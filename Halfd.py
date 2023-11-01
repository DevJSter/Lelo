#Server Script
import socket

# Create a socket object
server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Bind the server to a specific IP address and port
server_address = ('0.0.0.0', 12345)
server_socket.bind(server_address)

# Listen for incoming connections
server_socket.listen(1)
print("Server is listening for connections...")

# Accept a client connection
client_socket, client_address = server_socket.accept()
print("Connected to:", client_address)

while True:
    # Receive data from the client
    data = client_socket.recv(1024)
    if not data:
        break
    print("Client:", data.decode())

    # Send a response to the client
    message = input("Server: ")
    client_socket.send(message.encode())

client_socket.close()
server_socket.close()

#Client Script
import socket

# Create a socket object
client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Connect to the server
server_address = ('127.0.0.1', 12345)
client_socket.connect(server_address)

while True:
    message = input("Client: ")
    client_socket.send(message.encode())

    # Receive the server's response
    data = client_socket.recv(1024)
    if not data:
        break
    print("Server:", data.decode())

client_socket.close()
