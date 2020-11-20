from time import sleep
import curses
from webbrowser import open as open_url
if __name__ == "__main__":
    print("Ejecutar el archivo main.py")
else:
    from src.curses_actions import *

credits_text = """Hecho por Andrés Galván

Con la colaboración de
Javier Guerra
Santiago Andrés

Copyright (c) 2020 by Andrés Galván 
"""


def more_info(stdscr, current_option=0):
    h, w = stdscr.getmaxyx()
    stdscr.clear()
    options = ("Créditos", "Repositorio", "Licencia", "Volver al menú")


    while True:
        center_print(stdscr, "MÁS INFORMACIÓN", h//2 - len(options))
        show_menu(stdscr, current_option, options)
        select, current_option = arrow_moves(stdscr, current_option, options,
                                             curses.KEY_UP, curses.KEY_DOWN)
        show_menu(stdscr, current_option, options)
        if select:
            if current_option == 0:
                show_credits(stdscr)
            if current_option == 1:
                open_url("https://github.com/JuniorWriter")
            if current_option == len(options)-1:
                stdscr.clear()
                break


def show_credits(stdscr):
    h, w = stdscr.getmaxyx()

    curses.curs_set(0)
    y = h-1
    credits_list = credits_text.split("\n")
    space_diff = 2
    while y >= -4:
        stdscr.clear()
        for line in credits_list:
            if y + 1 > h:
                break
            if y - 2 < 1:
                y += 1
                continue
            center_print(stdscr, line, y)
            y += 1
        sleep(0.4)
        y -= space_diff
        if space_diff < 9:
            space_diff += 1


# curses.wrapper(animation)