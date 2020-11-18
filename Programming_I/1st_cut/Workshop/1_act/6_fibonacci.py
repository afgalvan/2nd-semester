from subprocess import call
from platform import system

def clear_console():
    OS = system()
    if OS == "Windows": call("cls", shell=True)
    else: call("clear")

def fibonacci_gen(limit):
    PHI = (1 + 5 ** 0.5) / 2
    fibonacci = lambda x: round((PHI ** x - (1 - PHI) ** x) / 5 ** 0.5)
    [print(fibonacci(x)) for x in range(limit)]


def main():
    clear_console()
    print("FIBONACCI\n")
    while True:
        maximum = input("Cuantos numeros fibonacci desea mostrar: ")
        try: maximum = int(maximum)
        except: continue
        if maximum < 1: continue
        break
    fibonacci_gen(maximum)


main()
