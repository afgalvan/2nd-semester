from time import sleep
import curses
# if __name__ == "__main__":
#     print("Ejecutar el archivo main.py")
# else:
#     from src.curses_actions import *

credits_text = """Hecho por Andrés Galván

Con la colaboración de
Javier Guerra
Santiago Andrés
"""

def center_print(stdscr, text, y):
    height, width = stdscr.getmaxyx()
    t_len = len(text)

    x = width // 2 - t_len // 2
    stdscr.addstr(y, x, text)
    stdscr.refresh()


def animation(stdscr):
    h, w = stdscr.getmaxyx()

    curses.curs_set(0)
    y = h-1
    credits_list = credits_text.split("\n")
    space_diff = 2
    while y >= 0:
        stdscr.clear()
        for line in credits_list:
            if y + 1 > h:
                break
            if y - 2 < 1:
                y += 1
                continue
            center_print(stdscr, line, y)
            y += 1
        sleep(0.3)
        y -= space_diff
        if space_diff < 7:
            space_diff += 1




curses.wrapper(animation)
