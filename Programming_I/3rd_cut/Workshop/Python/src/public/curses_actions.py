import curses
from time import sleep

height, width = 1, 1


def set_size(stdscr):
    global height, width
    height, width = stdscr.getmaxyx()


def center_print(stdscr, text):
    global height, width
    t_len = len(text)

    x = width // 2 - t_len // 2
    y = height // 2
    stdscr.addstr(y, x, text)
    stdscr.refresh()


def paint_section(stdscr):
    curses.init_pair(1, curses.COLOR_BLACK, curses.COLOR_WHITE)
    stdscr.attron(curses.color_pair(1))


def arrow_moves(stdscr, current_row, options):
    key = stdscr.getch()
    if key == curses.KEY_UP and current_row > 0:
        current_row -= 1
    elif key == curses.KEY_DOWN and current_row < len(options)-1:
        current_row += 1
    elif key == curses.KEY_ENTER or key in [10, 13]:
        exit(0)
    return current_row