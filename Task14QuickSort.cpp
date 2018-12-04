#include <iostream>
#include <stdlib.h>
#include <cstdio>
using namespace std;

void FillArray (int *arr, int size) {
    for (int i = 0; i < size; i++ ) {
        arr[i] = rand()%1000;
    }
};

void ShowArray (int *arr,int size) {
    for ( int k = 0; k < size; k++ ) {
        cout << arr[k] << " " ;
    }
    cout << endl;
};

void QuickSort (int *arr, int left, int right) {
    int i = left, j = right;
    int pivot = arr[(left + right)/ 2]; 
    while (i <= j) {
        while (arr[i] < pivot) {
        i++;
        }
        while (arr[j] > pivot) {
        j--;
        }
            if ( i <= j) {
                int tmp;
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
                i++;
                j--;
            }
        }
    if ( left < j) {
        QuickSort(arr, left, j);
    }
    if (i < right) {
        QuickSort(arr,i,right);
    }
};

void InputElement (int *&arr,int &size, int el) {
    int *NewArray = new int [++size];
    int i = 0;
    while (arr[i] < el && i < size - 1) {
        NewArray[i] = arr[i];
        i++;
    }
    NewArray[i] = el;
    i++;
    while (i < size) {
        NewArray[i] = arr[i-1];
        i++;
    }
    delete[] arr;
    arr = NewArray;
};

int main () {
    int size = 0; 
    int el = 0;
    cout << "Enter array size: "; 
    cin >> size;
    cout << "Enter new element: "; 
    cin >> el;
    int *arr = new int [size];
    FillArray (arr, size);
    ShowArray (arr, size);
    QuickSort (arr,0,size-1);
    cout << "-----------------------" << endl;
    ShowArray (arr, size);
    InputElement (arr, size, el);
    cout << "-----------------------" << endl;
    ShowArray (arr, size);
    delete [] arr;
    return 0;
}