#include <iostream>
using namespace std;

void FillArray (int *arr, int size) {
    for (int i = 0; i < size; i++ ) {
        arr[i] = rand()%100;
    }
};

void ShellSort(int *arr, int size){
    for (int part = size / 2; part >= 1; part /= 2){
        for (int i = part; i < size; i++){
            for (int j = i; j >= part && arr[j-part] > arr[j]; j -= part){
                swap(arr[j], arr[j-part]);
            }
        }
    }
};

void Inverse(int *arr, int size){
    int i = 0;
    while (i < (size/2)) {
        int el = arr[size - 1 - i];
        arr[size - 1 - i] = arr[i];
        arr[i] = el;
        i++;
    }
}

void ShowArray (int *arr,int size) {
    for ( int k = 0; k < size; k++ ) {
        cout << arr[k] << " " ;
    }
    cout << endl;
};

int main () {
    int size = 0; 
    cout << "Enter array size: "; 
    cin >> size;
    int *arr = new int [size];
    FillArray (arr, size);
    ShowArray (arr, size);
    ShellSort (arr,size);
    cout << "-----------------------" << endl;
    ShowArray (arr, size);
    cout << "-----------------------" << endl;
    Inverse (arr,size);
    ShowArray (arr, size);
    delete[] arr;
    return 0;
}