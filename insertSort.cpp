#include <iostream>
using namespace std;

int main () {
    int arr[6] = {21,-84, 47,-95,72,89};
    for ( int j = 1; j < 6; j++) {
        int key, i;
        key = arr[j];
        i = j-1;
        while ( i >= 0 && arr[i] > key) {
            arr[i+1] = arr[i];
            i = i-1;
        }
        arr[i+1] = key;
    }
    for ( int k = 0; k < 6; k++ ) {
        cout << arr[k] << " " ;
    }
    cout << endl;
}