from time import time
from random import randint

array = [randint(1, 1000) for i in range(1, 1000)]

def partition(array: list(), limit: int, init: int):
    i = init - 1
    pivot = array[limit]

    for j in range(init, limit):
        if array[j] <= pivot:
            i += 1
            array[i], array[j] = array[j], array[i]

    array[i+1], array[limit] = array[limit], array[i+1]
    return i + 1


def quickSort(array: list(), limit: int, init=0):
    if init < limit:
        part_index = partition(array, limit, init)

        quickSort(array, part_index - 1, init)
        quickSort(array, limit, part_index + 1)

def count_elapsed_time(f):
    """
    Decorator.
    Execute the function and calculate the elapsed time.
    Print the result to the standard output.
    """
    def wrapper():
        # Start counting.
        start_time = time()
        # Take the original function's return value.
        ret = f()
        # Calculate the elapsed time.
        elapsed_time = time() - start_time
        print("Elapsed time: %0.10f seconds." % elapsed_time)
        return ret
    
    return wrapper


@count_elapsed_time
def prompt():
    global array
    n = len(array)
    quickSort(array, n - 1)
    print(array)
    
prompt()