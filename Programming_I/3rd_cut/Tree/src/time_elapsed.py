from time import time
from msvcrt import getche


def main():
    print("Ingrese un nombre: ")
    first = getche().decode("utf-8")
    start = time()
    name = first
    name += input("")
    end = time()
    print(name)
    eplapsed = round(end-start, 2)
    print(eplapsed)


main()