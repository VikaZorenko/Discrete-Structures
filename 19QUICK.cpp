// 19. Имеется n абонентов телефонной станции. 
// Составить программу, в которой формируется  список по форме: номер телефона, фамилия 
// (номера идут в порядке возрастания). 
// Зоренко Вікторія ІП-74
#include <iostream>
#include "string.h"
using namespace std;

void ShowArrays (char** names, long long* numbers, int size) {
    for ( int k = 0; k < size; k++ ) {
        cout << numbers[k] << " " << names[k] << endl;
    }
};

void QuickSort (char** names, long long* numbers, int left, int right) {
    int i = left, j = right;
    long long pivot = numbers[(left + right)/ 2]; 
    while (i <= j) {
        while (numbers[i] < pivot) {
            i++;
        }
        while (numbers[j] > pivot) {
            j--;
        }
        if ( i <= j ) {
            long long tmpNum;
            tmpNum = numbers[i];
            numbers[i] = numbers[j];
            numbers[j] = tmpNum;

            char* tmpName;
            tmpName = names[i];
            names[i] = names[j];
            names[j] = tmpName;

            i++;
            j--;
        }
    }
    if (left < j) {
        QuickSort(names, numbers, left, j);
    }
    if (i < right) {
        QuickSort(names, numbers, i, right);
    }
};

int main () {
    int size = 10;
    char *names[size] = {
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
    long long numbers[size] = {
        380951112233,
        380951114433,
        380951116633,
        380951112255,
        380951111133,
        380953332233,
        380952221188,
        380956662266,
        380951112211,
        380951112299,
    };
    ShowArrays(names, numbers, size);
    QuickSort (names, numbers,0,size-1);
    cout << "-----------------------" << endl;
    ShowArrays (names, numbers, size);
    return 0;
}