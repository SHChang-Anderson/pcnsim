def process_barab():
    """
    Reads a file, parses its content, and processes the data by creating bidirectional edges.
    The processed data is written back to the same file.
    """
    input_file = "../topologies/topology"  # Input file path
    output_file = "../topologies/topology"  # Output file path

    # Read the original file content
    with open(input_file, "r") as file:
        lines = file.readlines()

    # Initialize lists to store original and reversed data
    original_data = []
    reversed_data = []

    # Process each line of the file
    for line in lines:
        parts = line.split()
        if len(parts) < 2:
            continue  # Skip lines with insufficient data
        # Append the original data
        original_data.append(line.strip())
        # Create a reversed version of the line with swapped first and second columns
        reversed_line = [parts[1], parts[0]] + parts[2:]
        reversed_data.append(" ".join(reversed_line))

    # Combine original and reversed data into one dataset
    combined_data = "\n".join(original_data + reversed_data)

    # Write the combined data to the output file
    with open(output_file, "w") as file:
        file.write(combined_data)

    print(f"Processing completed. The results have been written to {output_file}")