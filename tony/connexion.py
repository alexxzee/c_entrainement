import socket

target_host = "10.20.144.151"
target_port = 21
# create a socket object

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
# connect the client

client.connect((target_host, target_port))
# send some data

client.send("test")
# receive some data

response = client.recv(4096)
print (response)
