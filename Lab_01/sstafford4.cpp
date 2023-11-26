#include <iostream>
#include <string>

using namespace std;



void insertion_sort(int arr[], int key){
    for (int i = 1; i < key; i++){
        int n = arr[i]; // this sets the current key
        int j = i - 1;
        // move elements of arr[i-1] that arr[i-1] > n to the right. 
        while ( j >= 0 && arr[j] > n){
            arr[j + 1] = arr[j];
            j--; 
        }
        arr[j + 1] = n; // this sets the new key

    // prints the array with every iteration. 
    for (int k = 0; k < i + 1; k++){
        cout << arr[k] << ";"; 
        }
    cout << endl; 
    }
    
}

int main(){

    int size;
    cin >> size; 
    int array[size]; 
    for (int i = 0; i < size; i++){
        cin >> array[i]; 
    }

    insertion_sort(array, size);
    return 0; 
}