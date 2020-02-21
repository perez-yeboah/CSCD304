#include <iostream>
using namespace std;

void merge(int array, int first, int last, int array2) {
    int size = (last - first) + 1;
    int array2 = new int array2[];
    //int merge:: array2;

    int i = first;
    int mid = (first + last) / 2;
    int k = 0;
    int j = mid + 1;

    while (k < size) {
        if ((i <= mid) && (array[i] < array[j])) {
            array2[k++] = array[i++];
        }
        else
        {
            array2[k++] = array[j++];
        }
    }
    for (k = 0; k < size; k++) {
        array[first + k] = array2[k];
    }

    delete array2;
}

void mergeSort(int *array, int first, int last) {
    int mid;
    if (first < last) {
        mid = (first + last) / 2; //divide in half
        mergeSort(array,first, mid); //first recursive call
        mergeSort(array,mid + 1, last); //second recursive call
        merge(array,first, last);
    }
}




int main() {
    int N = 8;
    int left, right;

    left = 0;
    right = 7;

    int c[] = { 10, 5, 33, 16, 14, 56, 50, 7 }; //unsorted
    cout << "Before merge sort : " << endl;

    for (int i = 0; i < N; i++) {
        cout << c[i] << endl;
    }

    cout << "check if sorted before merge sort. " << endl;
    cout << isSorted(c, N) << endl;

    mergeSort(c, left, right);

    //values after sorting
    for (int i = 0; i < N; i++) {
        cout << c[i] << endl;
    }
}
