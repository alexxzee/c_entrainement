import hashlib

chaine = '96719db60d8e3f498c98d94155e1296aac105ck4923290c89eeeb3ba26d3eef92'

hashage = ""
for i in range(40):
  hashage += chaine[i]

hashage = str.encode(hashage)

hashage = hashlib.sha1(hashage).hexdigest()

print(hashage)
