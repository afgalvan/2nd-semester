if __name__ == "__main__":
    print("Ejecutar el archivo main.py")
else:
    from src.curses_actions import *


def show_exit(stdscr, selected_op_idx, options):
    h, w = stdscr.getmaxyx()
    spaces = 5
    between = (0, 7)
    for i in options:
        spaces += len(i)

    for idx, each in enumerate(options):
        x = w//2 - spaces//2 + between[idx]
        y = h//2
        if idx == selected_op_idx:
            stdscr.attron(curses.color_pair(1))
            stdscr.addstr(y, x, each)
            stdscr.attroff(curses.color_pair(1))
        else:
            stdscr.addstr(y, x, each)

    stdscr.refresh()


def exit_menu(stdscr, current_option=0):
    h, w = stdscr.getmaxyx()
    stdscr.clear()
    center_print(stdscr, "¿Seguro que desea salir?", h//2 - 1)
    options = ("Si", "No")

    show_exit(stdscr, current_option, options)

    while True:
        select, current_option = arrow_moves(stdscr, current_option, options,
                                     curses.KEY_LEFT, curses.KEY_RIGHT)
        show_exit(stdscr, current_option, options)
        if select:
            if current_option == 0:
                exit(0)
            stdscr.clear()
            break