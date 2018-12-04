#include <iostream> 
using namespace std; 

void QuickSort (int arr[], int left, int right) {
    int i = left, j = right;
    int pivot = arr[(left + right)/ 2]; 
    while (i <= j) {
        while (arr[i] < pivot) {
        i++;
        }
        while (arr[j] > pivot) {
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

int main () {
    int arr[15] = {3,67,12,0,98,47,2,11,19,48,-3,-34,4,6,82};
    int size = 15;
    for ( int k = 0; k < size; k++ ) {
        cout << arr[k] << " " ;
    }
    cout << endl;
    QuickSort(arr,0,size);
    for ( int k = 0; k < size; k++ ) {
        cout << arr[k] << " " ;
    }
    cout << endl;
}
