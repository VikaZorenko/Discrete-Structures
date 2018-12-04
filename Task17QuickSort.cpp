#include <iostream>
#include <limits.h>
using namespace std;

void FillArray (int *arr, int size) {
    for (int i = 0; i < size; i++ ) {
        arr[i] = rand()%100;
    }
};

void ShowArray (int *arr,int size) {
    for ( int k = 0; k < size; k++ ) {
        cout << arr[k] << " " ;
    }
    cout << endl;
};

void InputElement (int *&arr, int size) {
    int *NewArray = new int [size];
    int min = INT_MAX;
    for(int j = 0; j < size; j++) {
        int minIndex = 0;
        for (int i = 0; i < size; i++) {
            if (arr[i] < min) {
                min = arr[i];
                minIndex = i;
            }
        }
        NewArray[j] = min;
        min = INT_MAX;
        arr[minIndex] = INT_MAX;
    }
    delete[] arr;
    arr = NewArray;
}

int main () {
    int size = 0; 
    cout << "Enter array size: "; 
    cin >> size;
    int *arr = new int [size];
    FillArray (arr, size);
    ShowArray (arr, size);
    cout << "--------------------------" << endl;
    InputElement (arr, size);
    ShowArray (arr, size);
    delete [] arr;
    return 0;
}