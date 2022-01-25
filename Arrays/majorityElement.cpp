/*
Given an array A of N elements. Find the majority element in the array. A majority element in an array A of size N is an element that appears more than N/2 times in the array.
*/

int majorityElement(int a[], int size)
{
    sort(a, a+size);
    for (int i = 0; i <= size/2; i++) {
        if (a[i] == a[i+size/2])
            return a[i];
    }
    return -1;
}
