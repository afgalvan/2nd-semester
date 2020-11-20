from subprocess import call
from platform import system


def gotoxy(x, y):
    print("%c[%d;%df" % (0x1B, y, x), end='')


def clear():
    OS = system()
    if OS == "Windows":
        call("cls", shell=True)
    else:
        call("clear")
