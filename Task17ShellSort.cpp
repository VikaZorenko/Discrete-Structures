#include <iostream>
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

void ShellSort(int *arr, int size){
  for (int part = size / 2; part > 0; part /= 2){
    for (int i = part; i <= size; i++){
      int temp = arr[i];
      int j;
      for (j = i; j >= part && arr[j-part] > temp; j = j - part){
        arr[j] = arr[j - part];
      }
      arr[j] = temp;
    }
  }
}

int InputElement (int *&arr, int size) {
    int *NewArray = new int [size];
    for (int i = 0; i < size; i++) {
        NewArray[i] = arr[i];
        ShellSort (NewArray, i);
    }
    delete[] arr;
    arr = NewArray;
};

int main () {
    int size = 0; 
    cout << "Enter array size: "; 
    cin >> size;
    int *arr = new int [size];
    FillArray (arr, size);
    ShowArray (arr, size);
    cout << "-----------------------" << endl;
    InputElement (arr, size);
    ShowArray (arr, size);
    delete [] arr;
    return 0;
}