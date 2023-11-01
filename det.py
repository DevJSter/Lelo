def hamming_code_error_detection(data):
    # Calculate the parity bits' positions: parity_positions = [1, 2, 4]
    # Initialize parity bits
    parity_bits = [0, 0, 0]
    # Convert the data to a list of integers
    data_bits = [int(bit) for bit in data]
    
    # Calculate the parity bits
    for i, position in enumerate([1, 2, 4]):
        parity_bits[i] = sum(data_bits[x - 1] for x in range(1, len(data_bits) + 1) if (x & position) != 0) % 2
    
    # Calculate the error position
    error_position = sum([(parity_bits[i] % 2) * (2 ** i) for i in range(3)])
    
    # Check for errors
    if error_position > 0:
        print(f"Error detected at position {error_position}.")
    else:
        print("No errors detected.")

# Input from the user
received_data = input("Enter the received Hamming code (7 bits): ")
hamming_code_error_detection(received_data)

