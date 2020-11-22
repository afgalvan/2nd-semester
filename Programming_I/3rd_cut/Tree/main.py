from src.menu import main
from os import system
from src.controllers.controllers import clear, OS


def check_dependencies():
    if OS == "Windows":
        try:
            import curses
        except:
            system("pip install -r requirements.txt")
    else:
        try:
            from getch import getch
        except:
            system("make build")


if __name__ == "__main__":
    clear()
    check_dependencies()
    main()
