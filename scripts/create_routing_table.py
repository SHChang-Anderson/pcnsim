import os
import shutil

from collections import deque


def delete_directory(directory):

  try:
    shutil.rmtree(directory)
 
  except OSError as e:
    print(f"Dir does not exist: {e}")



def bfs(graph, residual_graph, vs, vd):
    # Performs a Breadth-First Search
    queue = deque([vs])
    parent = {vs: None}
    while queue:
        node = queue.popleft()
        for neighbor, capacity in residual_graph[node].items():
            if neighbor not in parent and capacity > 0:
                parent[neighbor] = node
                if neighbor == vd:
                    return parent
                queue.append(neighbor)
    return None

def candidate_path_computation(graph, capacity, base_fee, vs):
    # Initialization
    candidate_paths = {}

    # Iterate over all destination nodes
    for vd in graph:
        residual_graph = {node: {neighbor: capacity.get((node, neighbor), 0) for neighbor in graph[node]} for node in graph}
        if vd == vs:
            continue
        candidate_paths[vd] = []

        # BFS to find paths
        while True:
            parent = bfs(graph, residual_graph, vs, vd)
            if not parent:
                break

            # Reconstruct the path
            path = []
            node = vd
            while node != vs:
                path.append(node)
                node = parent[node]
            path.append(vs)
            path.reverse()

            # Calculate the maximum payment Y(p)
            Y_p = min(residual_graph[path[i]][path[i + 1]] for i in range(len(path) - 1))
            base_fee_sum = sum(base_fee.get((path[i], path[i + 1]), 0) for i in range(len(path) - 1))
            if Y_p > 0:
                # Add the path to the candidate paths set
                candidate_paths[vd].append((path, Y_p, base_fee_sum))

                # Update the residual network edge weights
                for i in range(len(path) - 1):
                    u, v = path[i], path[i + 1]
                    # Ensure the edge from v to u exists, initialize to 0 if not
                    if v not in residual_graph:
                        residual_graph[v] = {}
                    if u not in residual_graph[v]:
                        residual_graph[v][u] = 0
                    
                    # Update capacity
                    residual_graph[u][v] -= Y_p
                    residual_graph[v][u] += Y_p
            else:
                # If the payment is 0, find the minimum supported payment
                min_payment = float('inf')
                min_k = -1
                for i in range(len(path) - 1):
                    u, v = path[i], path[i + 1]
                    min_payment = min(min_payment, residual_graph[u][v])

                # Find the hop k with the minimum payment
                for i in range(len(path) - 1):
                    u, v = path[i], path[i + 1]
                    if residual_graph[u][v] == min_payment:
                        min_k = i
                        break

                # Update the residual network edge weights
                u, v = path[min_k], path[min_k + 1]
                residual_graph[u][v] = 0
                residual_graph[v][u] = capacity[(u, v)]
                break

        # Remove edges with weight 0
        for u in list(residual_graph):
            for v in list(residual_graph[u]):
                if residual_graph[u][v] <= 0:
                    del residual_graph[u][v]
    
    return candidate_paths





# clear routing table
directory_to_delete = "../routing_table"
delete_directory(directory_to_delete)

# Initialize structures
graph = {}
capacity = {}
base_fee = {}

# Read data
with open("../topologies/topology", "r") as file:
    for line in file:
        # Skip empty lines or comment lines
        if not line.strip() or line.startswith("#"):
            continue
        
        # Split data
        data = line.split()
        node1, node2 = data[0], data[1]
        cap = float(data[2])
        fee = float(data[4])  # Base fee

        # Construct graph
        if node1 not in graph:
            graph[node1] = []
        if node2 not in graph[node1]:  # Ensure no duplicates
            graph[node1].append(node2)
        if node2 not in graph:
            graph[node2] = []
        if node1 not in graph[node2]:
            graph[node2].append(node1)

        # Set capacity
        capacity[(node1, node2)] = cap
        capacity[(node2, node1)] = cap  # Assume undirected edges

        # Set base fee
        base_fee[(node1, node2)] = fee
        base_fee[(node2, node1)] = fee  # Assume undirected edges



for i in range(len(graph)):
    vs = str(i)
    all_paths = candidate_path_computation(graph, capacity, base_fee,  vs)



    # Create folder
    folder_name = "../routing_table"
    if not os.path.exists(folder_name):
        os.mkdir(folder_name)

    # Write routing table
    with open(folder_name + "/node" + vs, "w") as file:  
        for vd, paths in all_paths.items():
            file.write(f"Paths from node{vs} to node{vd}:\n")
            for path, flow, fee in paths:
                path_str = ' '.join(f"node{node}" for node in path)  
                file.write(f"  Path: {path_str}, Flow: {flow}, Fee: {fee}\n")