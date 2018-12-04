#include <iostream>
using namespace std;

void FillArray (int *arr, int size) {
    for (int i = 0; i < size; i++ ) {
        arr[i] = rand()%5;
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
        while (arr[i] > pivot) {
        i++;
        }
        while (arr[j] < pivot) {
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

void MidlEl (int *&arr, int &size) { 
    int k = size;
    size = (size * 2) - 1;
    int *NewArray = new int [size];
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
    int *arr = new int [size];
    FillArray (arr, size);
    ShowArray (arr, size);
    QuickSort (arr,0,size);
    cout << "-----------------------" << endl;
    ShowArray (arr, size);
    cout << "-----------------------" << endl;
    MidlEl (arr, size);
    ShowArray (arr, size);
    
    delete[] arr;
    return 0;
}