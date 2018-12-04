#include <iostream>
using namespace std;

void FillArray (float *arr, int size) {
    for (int i = 0; i < size; i++ ) {
        arr[i] = rand()%5;
    }
};

void ShowArray (float *arr,int size) {
    for ( int k = 0; k < size; k++ ) {
        cout << arr[k] << " " ;
    }
    cout << endl;
};

void ShellSort(float *arr, int size){
    for (int part = size / 2; part >= 1; part /= 2){
        for (int i = part; i < size; i++){
            for (int j = i; j >= part && arr[j-part] > arr[j]; j -= part){
                swap(arr[j], arr[j-part]);
                }
            }
    }
};

void MidlEl (float *&arr, int &size) { 
    int k = size;
    size = (size * 2) - 1;
    float *NewArray = new float [size];
    int x = 0;
    int y = 0;
    while (y < size) {
        NewArray[y] = arr[x];
        NewArray[y+2] = arr[x+1];
        NewArray[y+1] = (arr[x] + arr[x+1]) / 2;
        x++;
        y +=2;
    }
    delete[] arr;
    arr = NewArray;
}
 
int main () {
    int size = 0; 
    cout << "Enter array size: "; 
    cin >> size;
    float *arr = new float [size];
    FillArray (arr, size);
    ShowArray (arr, size);
    ShellSort (arr,size);
    cout << "-----------------------" << endl;
    ShowArray (arr, size);
    cout << "-----------------------" << endl;
    MidlEl (arr, size);
    ShowArray (arr, size);
    delete[] arr;
    return 0;
}