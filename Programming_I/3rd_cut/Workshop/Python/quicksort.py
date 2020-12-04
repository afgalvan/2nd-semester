from time import time
from random import randint
from controllers.controllers import *


def partition(array: list(), limit: int, init: int):
    i = init - 1
    pivot = array[limit]

    for j in range(init, limit):
        if array[j] <= pivot:
            i += 1
            array[i], array[j] = array[j], array[i]

    array[i+1], array[limit] = array[limit], array[i+1]
    return i + 1


def quick_sort(array: list(), limit: int, init=0):
    if init < limit:
        part_index = partition(array, limit, init)

        quick_sort(array, part_index - 1, init)
        quick_sort(array, limit, part_index + 1)


def main():
    clear()
    array = [randint(1, 1000) for n in range(1, 20)]
    size = len(array)
    
    # center_print("Unsorted array", 5)
    # array_table(array, 6) # <== Función array_table para
    #                           # imprimir cualquier arreglo

    center_print("Quicksorted array", 10)
    quick_sort(array, size - 1)
    array_table(array, 11) # <== Es la misma función
    print()

main()