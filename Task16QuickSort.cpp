#include <iostream>
using namespace std;

void FillArray (int *arr, int size) {
    for (int i = 0; i < size; i++ ) {
        arr[i] = rand()%100 - 80;
    }
};

void ShowArray (int *arr,int size) {
    for ( int k = 0; k < size; k++ ) {
        cout << arr[k] << " " ;
    }
    cout << endl;
};

void DeleteEl (int *&arr, int &size) {
    int i = 0;
    int *NewArray = new int [size];
    int *Trash = new int [size];
    while (i < size) {
        if (arr[i] < 0) {
            Trash[i] = arr[i];
        }
        NewArray[i] = arr[i];
        i++;
    }
    delete[] arr;
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
    cout << "-----------------------" << endl;
    ShowArray (arr, size);
    DeleteEl (arr, size);
    cout << "-----------------------" << endl;
    ShowArray (arr, size);
    delete [] arr;
    return 0;
}