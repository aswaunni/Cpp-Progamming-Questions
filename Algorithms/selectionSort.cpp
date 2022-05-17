/*
------------------
SELECTION SORT
------------------
Time Complexity -> O(n^2)

This sorting algorithm is an in-place comparison-based algorithm in which the list is divided into two parts, 
the sorted part at the left end and the unsorted part at the right end. Initially, the sorted part is empty and the unsorted part is the entire list.

The smallest element is selected from the unsorted array and swapped with the leftmost element, and that element becomes a part of the sorted array.
This process continues moving unsorted array boundary by one element to the right.
*/

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n-1; i++) {
        int mn = i;
        for (int j = i+1; j < n; j++) {
            if (arr[mn] > arr[j])
                mn = j;
        }
        swap(&arr[i], &arr[mn]);
    }
}
