#include "controllers.hh"

int Partition(int array[], int init, int limit);
int QuickSort(int array[], int init, int limit);

int main()
{
    int array[] = {4, 2, 6, 0, 12, 42, 8};
    int array_size = sizeof(array) / sizeof(*array);

    SetWindow('n');
    system("cls");

    CenterPrint("Unsorted array", 5);
    ArrayTable(array, array_size, 6);

    CenterPrint("Quicksorted array", 10);
    QuickSort(array, 0, array_size - 1);
    ArrayTable(array, array_size, 11);
    std::cout << "\n";
    return 0;
}

int Partition(int array[], int init, int limit)
{
    int j, i = init - 1;
    int pivot = array[limit];
    int changer;

    for (j = init; j < limit; j++)
        if (array[j] <= pivot)
        {
            i++;
            changer = array[i];
            array[i] = array[j];
            array[j] = changer;
        }
    changer = array[i+1];
    array[i+1] = array[limit];
    array[limit] = changer;
    return i + 1;
}

int QuickSort(int array[], int init, int limit)
{
    int partition_index;

    if (init < limit)
    {
        partition_index = Partition(array, init, limit);

        QuickSort(array, init, partition_index-1);
        QuickSort(array, partition_index+1, limit);
    }
}