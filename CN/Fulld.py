#Server script
import socket
import select

server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_socket.bind(('0.0.0.0', 12345))
server_socket.listen(5)

sockets_list = [server_socket]
clients = {}

print("Server is listening for connections...")

while True:
    read_sockets, _, _ = select.select(sockets_list, [], [])
    for s in read_sockets:
        if s is server_socket:
            client_socket, client_address = server_socket.accept()
            sockets_list.append(client_socket)
            clients[client_socket] = client_address
            print("Client connected:", client_address)
        else:
            try:
                data = s.recv(1024)
                if not data:
                    print("Client disconnected:", clients[s])
                    s.close()
                    sockets_list.remove(s)
                    del clients[s]
                    continue
                message = data.decode()
                print(f"Received from {clients[s]}: {message}")
                response = input("Server: ")
                s.send(response.encode())
            except:
                continue
#client 1
import socket

client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_address = ('127.0.0.1', 12345)
client_socket.connect(server_address)

while True:
    message = input("Client: ")
    client_socket.send(message.encode())
    data = client_socket.recv(1024)
    if not data:
        break
    print("Server:", data.decode())

client_socket.close()

#client 2
import socket

client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_address = ('127.0.0.1', 12345)  # Corrected the server address here
client_socket.connect(server_address)

while True:
    message = input("Client: ")
    client_socket.send(message.encode())
    data = client_socket.recv(1024)
    if not data:
        break
    print("Server:", data.decode())

client_socket.close()
