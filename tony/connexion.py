# import socket

# HOST = '51.38.187.123'
# PORT = 21

# client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
# client.connect((HOST, PORT))
# print('Connexion vers ' + HOST + ':' + str(PORT) + ' reussie.')

# message = 'Hello, world'
# print('Envoi de :' + message)
# n = client.send(message)
# if (n != len(message)):
#         print('Erreur envoi.')
# else:
#         print('Envoi ok.')

# print('Reception...')
# donnees = client.recv(1024)
# print('Recu :', donnees)

# print('Deconnexion.')
# client.close()



# Marche
# import socket

# hote = '51.38.187.123'
# port = 21

# socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
# socket.connect((hote, port))
# print("Connection on {}".format(port))

# socket.send(b"Hey my name is Olivier!")

# print("Close")
# socket.close()




# import socket


# def client_program():
#     host = '51.38.187.123'  # as both code is running on same pc
#     port = 21  # socket server port number

#     client_socket = socket.socket()  # instantiate
#     client_socket.connect((host, port))  # connect to the server

#     message = input(" -> ")  # take input

#     while message.lower().strip() != 'bye':
#         client_socket.send(message.encode())  # send message
#         data = client_socket.recv(1024).decode()  # receive response

#         print('Received from server: ' + data)  # show in terminal

#         message = input(" -> ")  # again take input

#     client_socket.close()  # close the connection

# client_program()


# import socket

# HOST = 'www.tybbow.com/codes.php?lid=4'  # as both code is running on same pc
# PORT = 80  # socket server port number

# client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
# client.connect((HOST, PORT))
# print ('Connexion vers ' + HOST + ':' + str(PORT) + ' reussie.')

# message = b'Hello, world'
# print ('Envoi de :' + str(message))
# n = client.send(message)
# if (n != len(message)):
#         print ('Erreur envoi.')
# else:
#         print ('Envoi ok.')

# print ('Reception...')
# donnees = client.recv(1024)
# print ('Recu :', donnees)

# print ('Deconnexion.')
# client.close()



import sys
import telnetlib

HOST = "www.tybbow.com"
PORT = "80"

telnetObj=telnetlib.Telnet(HOST,PORT)
message = ("GET http://www.tybbow.com/codes.php?lid=4 HTTP/1.1\nHost:"+HOST+"\n\n").encode('ascii')
telnetObj.write(message)
output=telnetObj.read_all()
print(output)
telnetObj.close()
