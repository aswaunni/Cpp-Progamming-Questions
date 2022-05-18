/*
------------------
INSERTION SORT
------------------
Time Complexity -> O(n^2)

Insertion sort is a sorting algorithm that places an unsorted element at its suitable place in each iteration.
Insertion sort works similarly as we sort cards in our hand in a card game.
*/

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i-1;
        while (j >= 0 && key < arr[j]) {
            arr[j+1] = arr[j];
            --j;
        }
        arr[j+1] = key;
    }
}
