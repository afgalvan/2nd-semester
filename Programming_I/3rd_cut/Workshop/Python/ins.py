from random import randint
from os import system


print ("modulo de llenado random")
vector = [randint(1, 100) for n in range(10)]
#mostramos lo que la computadora genero 
print("contenido del vector:")
print(vector, sep= ", ")