"""
This is for python module to improve your presentation and your
data in basic python terminal programs.

This simple module is for basic side functions, that allow the
developer to focus on the main process and show a good looking
program without much effort.
"""


from subprocess import call
from platform import system
from shutil import get_terminal_size


class ColorsPalette:
    """A color pallete for a colourful program without
    worrying about ansi escape codes.

    * Usage:
      With an already created object named "color", you
      can change the fore color of your text just adding
      the color in the list printing it.

    * Example:
      print(color.RED + "Lorem ipsum")
      This will print Lorem ipsum with red fore color.

    You can also combine styles such as BOLD and UNDERLINE
    text.

    * Example:
      print(color.RED + color.BOLD + "Lorem ipsum")

    Finally to return the default values of your prompt,
    you should print the color.DEFAULT attribute.
    """

    YELLOW = '\033[93m'
    BLUE = '\033[94m'
    RED = '\033[91m'
    PURPLE = '\033[95m'
    CYAN = '\033[96m'
    GREEN = '\033[92m'
    DEFAULT = '\033[0m'
    BOLD = '\033[1m'
    UNDERLINE = '\033[4m'


width, height = get_terminal_size()
color = ColorsPalette()
OS = system()


def clear():
    """Clear console deppending of the O.S terminal command,
    using the system function from the platform module that
    returns a string of the OS name.
    """
    if OS == "Windows":
        call("cls", shell=True)
    else:
        call("clear")


def center_this(text: str):
    """Given a string line return the most centered position
    to prompt in the terminal. With the get_terminal_size()
    function previously used to get the window dimensions and
    having the string lenght, just apply basic math to return
    that value.

    ├── 10 ──┤
    Lorem ipsum

                     Window width
    ├───────────────── 40 ─────────────────┤

    (40 - 10) // 2 = 15

                      Lorem ipsum
    ├──────────────┼───────────────────────┤
                     15
                        
    """
    center_position = (width - len(text))//2
    return center_position


def gotoxy(x, y):
    """"""
    print("%c[%d;%df" % (0x1B, y, x), end='')


def center_print(text: str, *args):
    """"""
    y = args[0]
    width_alter = 0
    if len(args) == 2:
        width_alter = args[1]

    x = center_this(text)
    gotoxy(x+width_alter, y)
    print(text, end="")


def error_print(error_msg: str, position="m", *args):
    """"""
    width_alter = 0
    y = 0

    try:
        y = args[0]
        width_alter = args[1]
    except:
        pass

    print(color.RED, end="")
    if position == "m":
        print(error_msg, end="")
    elif position == "c":
        center_print(error_msg, y, width_alter)
    print(color.DEFAULT)


def scan(question="", var_type=str):
    """"""
    data = input(question)
    try:
        data = var_type(data)
        return data
    except:
        return None


def better_input(question="", var_type=str, error_msg=""):
    """"""
    while True:
        data = scan(question, var_type)
        if data is None:
            error_print("Error. " + error_msg)
            continue
        break
    return data
