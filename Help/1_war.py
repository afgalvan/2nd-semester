from subprocess import call
from getpass import getpass

call("cls", shell=True)
 
print("\tDIVISORES")

term = int(input("De que numero desea saber el divisor: "))
n = 1
while n < term:
    if term % n == 0:
        print(n)
    n += 1
    
getpass("\nHecho por Javier Guerra")