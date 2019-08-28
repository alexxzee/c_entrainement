
import socket

class SimpleSocket:

  def __init__( self, target, target_port ):
    self.target = target
    self.target_port = target_port
    self.buffer_size = 4096

    self.create_socket()
  
  def sanitize_to_send( self, data ):
    return data.encode('utf-8')

  def create_socket(self):
    self.client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    self.client.connect((self.target, self.target_port))
    data = self.client.recv(self.buffer_size)
    print(data)


connect_tony = SimpleSocket( 'tybbow.com', 21 )
