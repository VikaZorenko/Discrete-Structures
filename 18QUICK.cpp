// 18. Дан список авторов в форме массива А. Составить программу формирования 
// указателя авторов в алфавитном порядке и вывести его на экран.
// Зоренко Віеторії ІП-74
#include <iostream>
#include "string.h"
using namespace std;

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
        while (strcmp(arr[i], pivot) < 0) {
            i++;
        }
        while (strcmp(arr[j], pivot) > 0) {
            j--;
        }
        if ( i <= j ) {
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
    int size = 10;
    char *arr[size] = {
        "Orwell",
        "Herbert",
        "Lovecraft",
        "Dick",
        "Wells",
        "Vonnegut",
        "Bradbury",
        "Asimov",
        "Verne",
        "Klarke"
    };
    ShowArray(arr, size);
    QuickSort (arr,0,size-1);
    cout << "-----------------------" << endl;
    ShowArray (arr, size);
    return 0;
}