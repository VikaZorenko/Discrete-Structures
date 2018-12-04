// 20. Имеется n слов различной  длины, все они занесены в массив А.
// Составить программу упорядочения слов по возрастанию их длин.
// Зоренко Вікторія ІП-74
#include <iostream>
#include "string.h"
using namespace std;

void FillArray (int *arr, int size) {
    for (int i = 0; i < size; i++ ) {
        arr[i] = rand()%100;
    }
};

void ShowArray (char** arr,int size) {
    for ( int k = 0; k < size; k++ ) {
        cout << arr[k] << " " ;
    }
    cout << endl;
};

void QuickSort (char** arr, int left, int right) {
    int i = left, j = right;
    char* pivot = arr[(left + right)/ 2]; 
    while (i <= j) {
        while (strlen(arr[i]) < strlen(pivot)) {
            i++;
        }
        while (strlen(arr[j]) > strlen(pivot)) {
            j--;
        }
        if ( i <= j) {
            char* tmp;
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
        QuickSort(arr, i, right);
    }
};

int main () {
    int size = 12;
    char *arr[size] = {
        "Piper",
        "Saucerfull",
        "More",
        "Ummagumma",
        "Mother",
        "Heart",
        "Clouds",
        "Moon",
        "Animals",
        "Cut",
        "Division",
        "Endless"
    };
    ShowArray(arr, size);
    QuickSort (arr,0,size-1);
    cout << "-----------------------" << endl;
    ShowArray (arr, size);
    return 0;
}