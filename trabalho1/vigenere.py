from sys import argv
from os.path import exists

class Vigenere:
	"""docstring for VigenereCipher"""
	def __init__(self):
		pass

	def cipher(self,file,key):
		if	exists(file):
			it = 0
			n = len(key)
			output = open("vigenere_cipher.txt",'w+b')
			with open(file,'r+b') as f:
				while 1:
					read_data = f.read(1)
					
					if not read_data:
						break
					output.write( chr( ( ord(read_data) + ord(key[it]) ) % 256 ) )
					
					it += 1
					if (it == n):
						it = 0
			output.close
		else:
			print "File not exists"

	def decipher(self,file,key):
		if	exists(file):
			it = 0
			n = len(key)
			output = open("vigenere_decipher.txt",'w+b')
			with open(file,'r+b') as f:
				while 1:
					read_data = f.read(1)
					
					if not read_data:
						break
					output.write( chr( ( ord(read_data) - ord(key[it]) ) % 256 ) )
					
					it += 1
					if (it == n):
						it = 0
			output.close
		else:
			print "File not exists"

		return "vigenere_decipher.txt"
