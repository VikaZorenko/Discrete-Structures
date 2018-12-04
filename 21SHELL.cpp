// 21. Составить программу для сортировки массива А по возрастанию и убыванию модулей его элементов.
// Зоренко Вікторія ІП-74
#include <iostream>
#include <time.h>
using namespace std;

int abs(int val) {
	return val > 0 ? val : -1*val;
}

void FillArray (int* arr, int size) {
    for (int i = 0; i < size; i++ ) {
        arr[i] = (rand() % 10) > 5 ? -1 * (rand() % 100) : rand() % 100;
    }
};

void ShowArray (int* arr,int size) {
    for ( int k = 0; k < size; k++ ) {
        cout << arr[k] << " " ;
    }
    cout << endl;
};

void ShellSortForward(int* arr, int size){
  for (int part = size / 2; part > 0; part /= 2){
    for (int i = part; i < size; i++){
      int temp = arr[i];
      int j;
      for (j = i; j >= part && abs(arr[j-part]) > abs(temp); j = j - part){
        arr[j] = arr[j - part];
      }
      arr[j] = temp;
    }
  }
}

void ShellSortBackward(int* arr, int size){
  for (int part = size / 2; part > 0; part /= 2){
    for (int i = part; i < size; i++){
      int temp = arr[i];
      int j;
      for (j = i; j >= part && abs(arr[j-part]) < abs(temp); j = j - part){
        arr[j] = arr[j - part];
      }
      arr[j] = temp;
    }
  }
}

int main() {
	srand(time(NULL));
    int size = 0; 
    cout << "Enter array size: "; 
    cin >> size;
    int* arr = new int[size];
    FillArray (arr, size);
    int sortingDecision = 0;
    cout << "Do you wish to sort it forward(0) or backward(1)? 0 or 1: ";
    cin >> sortingDecision;
    ShowArray(arr, size);
    cout << "--------------------------" << endl;
    sortingDecision ? ShellSortForward(arr, size) : ShellSortBackward(arr, size);
    ShowArray(arr, size);
    delete [] arr;
    return 0;
}