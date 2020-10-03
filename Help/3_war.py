#  3. Realizar un programa que lea una letra Romana y diga
#  que numero es. rango es( I, X, L, D,V, M, C ).
#  obs: Debe decir si la letra es valida, solo ac
from subprocess import call

valid = ["I", "X", "L", "D", "V", "M", "C"]
translate = [1, 10, 50, 500, 5, 1000, 100]
while True:
    call("clear")
    print("\t\tNUMEROS ROMANOS.")
    n = input("\nIngrese un número en romano: ")
    if n not in valid: 
        print("Valor inválido.")
        input()
        continue
    
    result = valid.index(n)
    print("El numero es ", translate[result])
    break

input("\nJavier Gayrra")
