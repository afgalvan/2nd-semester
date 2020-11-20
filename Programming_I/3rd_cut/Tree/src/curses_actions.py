import curses

if __name__ == "__main__":
    print("Ejecutar el archivo main.py")

height, width = 1, 1


def set_size(stdscr):
    global height, width
    height, width = stdscr.getmaxyx()


def center_print(stdscr, text, y):
    global height, width
    t_len = len(text)

    x = width // 2 - t_len // 2
    stdscr.addstr(y, x, text)
    stdscr.refresh()


def arrow_moves(stdscr, current_row, options, decrement, increment):
    key = stdscr.getch()
    if key == decrement and current_row > 0:
        current_row -= 1
    elif key == increment and current_row < len(options)-1:
        current_row += 1
    elif key == curses.KEY_ENTER or key in [10, 13]:
        return True, current_row
    return False, current_row