from time import sleep
import curses
from src.public.curses_actions import *

options = ("Mostrar taller", "Ver más", "Salir")


def show_menu(stdscr, selected_row_idx):
    h, w = stdscr.getmaxyx()
    for idx, row in enumerate(options):
        x = w//2 - len(row)//2
        y = h//2 - len(options)//2 + idx
        if idx == selected_row_idx:
            stdscr.attron(curses.color_pair(1))
            stdscr.addstr(y, x, row)
            stdscr.attroff(curses.color_pair(1))
        else:
            stdscr.addstr(y, x, row)

    stdscr.refresh()


def main_menu(stdscr):
    curses.curs_set(0)
    curses.init_pair(1, curses.COLOR_BLACK, curses.COLOR_WHITE)

    current_row = 0
    show_menu(stdscr, current_row)

    while True:
        current_row = arrow_moves(stdscr, current_row, options)
        show_menu(stdscr, current_row)


def main():
    curses.wrapper(main_menu)
