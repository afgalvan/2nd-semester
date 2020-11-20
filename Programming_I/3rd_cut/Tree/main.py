from src.menu import main
from os import system


def check_dependencies():
    try:
        import curses
    except:
        system("pip install -r requirements.txt")


if __name__ == "__main__":
    check_dependencies()
    main()
