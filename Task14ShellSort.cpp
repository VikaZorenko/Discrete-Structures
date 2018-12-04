#include <iostream>
using namespace std;

void FillArray (int *arr, int size) {
    for (int i = 0; i < size; i++ ) {
        arr[i] = rand()%1000;
    }
};

void ShellSort(int *arr, int size){
  for (int part = size / 2; part > 0; part /= 2){
    for (int i = part; i <= size; i++){
      int temp = arr[k];
      int j;
      for (j = i; j >= part && arr[j-part] > temp; j = j - part){
        arr[j] = arr[j - part];
      }
      arr[j] = temp;
    }
  }
}

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

void ShowArray (int *arr,int size) {
    for ( int k = 0; k < size; k++ ) {
        cout << arr[k] << " " ;
    }
    cout << endl;
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
    ShellSort (arr,size-1);
    cout << "-----------------------" << endl;
    ShowArray (arr, size);
    InputElement (arr, size, el);
    cout << "-----------------------" << endl;
    ShowArray (arr, size);
    delete [] arr;
    return 0;
}