import os
import socket

host = os.environ.get("HOST")
port = int(os.environ.get("PORT"))

# Create a TCP socket
sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
ip = socket.gethostbyname(host)
print(ip)


# Connect to the server with the socket via our ngrok tunnel
server_address = (host, port)
sock.connect(server_address)
print("Connected to {}:{}".format(host, port))

# Send the message
message = "ping"
print("Sending: {}".format(message))
sock.sendall(message.encode("utf-8"))

# Await a response
data_received = 0
data_expected = len(message)

while data_received < data_expected:
    data = sock.recv(1024)
    data_received += len(data)
    print("Received: {}".format(data.decode("utf-8")))

sock.close()
