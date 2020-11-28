import * as beauty from "./Controllers";

function main(): number {
  let array = [4, 2, 6, 0, 12, 42, 8];
  let arraySize = array.length;

  console.clear();
  beauty.centerPrint("Unsorted array", 5);
  beauty.arrayTable(array, 6);

  beauty.centerPrint("Quicksorted array", 10);
  quicksort(array, 0, arraySize - 1);
  beauty.arrayTable(array, 11);

  return 0;
}

function arrayPartition(
  array: Array<number>,
  init: number,
  limit: number
): number {
  let j: number,
    swap: number,
    i = init - 1;
  let pivot = array[limit];

  for (j = init; j < limit; j++) {
    if (array[j] <= pivot) {
      i++;
      swap = array[i];
      array[i] = array[j];
      array[j] = swap;
    }
  }

  swap = array[i];
  array[i] = array[j];
  array[j] = swap;
  return i + 1;
}

function quicksort(array: Array<number>, init: number, limit: number): void {
  let partition_index: number;

  if (init < limit) {
    partition_index = arrayPartition(array, init, limit);

    quicksort(array, init, partition_index - 1);
    quicksort(array, partition_index + 1, limit);
  }
}

main();
