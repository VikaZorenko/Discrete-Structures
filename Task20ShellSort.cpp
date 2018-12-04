#include <iostream>
#include <string>
using namespace std;

void ShowArray (string *arr,int size) {
    for ( int k = 0; k < size; k++ ) {
        cout << arr[k] << " " ;
    }
    cout << endl;
};

void ShellSort(string *arr, int size){
  for (int part = size / 2; part > 0; part /= 2){
    for (int i = part; i <= size; i++){
      int temp = arr[i].length();
      int j;
      for (j = i; j >= part && arr[j-part].length() < temp; j = j - part){
        arr[j] = arr[j - part];
      }
      // arr[j].length() = temp;
    }
  }
}

int main () {
    int size = 5;
    string *arr = new string[size]{"functor", "function", "adidas", "more", "impossible"};
    ShowArray (arr, size);
    cout << "-----------------------" << endl;
    ShellSort (arr, size);
    ShowArray (arr, size);
    delete [] arr;
    return 0;
}