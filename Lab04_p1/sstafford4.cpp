#include <iostream>

using namespace std;


// So we need 2 functions. One to build a max heap of elements found in an array, and another to sort them. 

// Function 1:
void max_heapify(int arr[], int size, int x){
    int maximum = x; 
    int left = (2 * x) + 1;
    int right = (2 * x) + 2; 

    if ((left < size) && (arr[x] < arr[left])){
        maximum = left;
    }
    else{
        maximum = x; 
    }
    if ((right < size) && (arr[maximum] < arr[right])){
        maximum = right;
    }
    // my issues came from using swap instead of using temporary variables and switching that way. 
    if (maximum != x){
        int temp = arr[x];
        arr[x] = arr[maximum];
        arr[maximum] = temp;
        max_heapify(arr, size, maximum); 
    }
}

// Function 2: 
void heap_sort(int arr[], int n){
    // this first loop is going to rearrange the array. 
    for (int i = (n/2) - 1; i >= 0; i--){
        max_heapify(arr, n, i);
    }
    for (int i = n - 1; i >= 0; i--){
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp; 
        max_heapify(arr, i, 0); 
    }
}

int main(){

    int size;
    cin >> size;
    int arr[size];

    for (int i = 0; i < size; i++){
        cin >> arr[i];
    }

    heap_sort(arr, size);

    for (int i = 0; i < size; i++){
        cout << arr[i] << ";";
    }
    
    return 0; 
}