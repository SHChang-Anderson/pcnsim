def process_barab():
    """
    Reads a file, parses its content, and processes the data by creating bidirectional edges.
    The processed data is sorted by the first number in each line and written back to the same file.
    """
    input_file = "../topologies/topology"  # Input file path
    output_file = "../topologies/topology"  # Output file path
    
    # Read the original file content
    with open(input_file, "r") as file:
        lines = file.readlines()
    
    # Initialize list to store all edge data (original and reversed)
    all_edges = []
    
    # Process each line of the file
    for line in lines:
        parts = line.strip().split()
        if len(parts) < 2:
            continue  # Skip lines with insufficient data
        
        # Append the original data
        all_edges.append(line.strip())
        
        # Create a reversed version of the line with swapped first and second columns
        reversed_line = [parts[1], parts[0]] + parts[2:]
        all_edges.append(" ".join(reversed_line))
    
    # Sort all edges by the first number in each line
    sorted_edges = sorted(all_edges, key=lambda x: int(x.split()[0]))
    
    # Combine sorted edges into one dataset
    combined_data = "\n".join(sorted_edges)
    
    # Write the combined data to the output file
    with open(output_file, "w") as file:
        file.write(combined_data)
    
    print(f"Processing completed. The results have been written to {output_file}")