from time import time
from subprocess import call
from msvcrt import getche


def main():
    call("cls", shell=True)
    print("Ingrese un nombre: ")
    # first = getche().decode("utf-8")
    start = time()
    # name = first
    name = input("")
    end = time()
    print(name)
    eplapsed = round(end-start, 2)
    print(eplapsed)


if __name__ == "__main__":
    main()