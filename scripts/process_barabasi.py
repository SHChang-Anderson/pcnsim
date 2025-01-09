def process_barab():
    # 讀取檔案，解析並處理數據
    input_file = "../topologies/topology"
    output_file = "../topologies/topology"

    # 讀取原始檔案內容
    with open(input_file, "r") as file:
        lines = file.readlines()

    # 初始化列表
    original_data = []
    reversed_data = []

    # 處理每一行數據
    for line in lines:
        parts = line.split()
        if len(parts) < 2:
            continue
        # 保留原始數據
        original_data.append(line.strip())
        # 調換第一和第二欄，保留其餘數據
        reversed_line = [parts[1], parts[0]] + parts[2:]
        reversed_data.append(" ".join(reversed_line))

    # 合併數據
    combined_data = "\n".join(original_data + reversed_data)

    # 寫入處理後的結果到新檔案
    with open(output_file, "w") as file:
        file.write(combined_data)

    print(f"處理完成，結果已寫入 {output_file}")