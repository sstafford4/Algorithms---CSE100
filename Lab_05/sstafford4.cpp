#include <iostream>
#include <vector>

using namespace std;

// Psuedocode on page 198, short but not too useless
// It says we want to use a stable sorting method. Stable sorting methods include Insertion, Merge, and Counting.
// Counting sort is in the book right before Radix. 

// Radix Sorting iterates d-digit times and sorts the least significant figure first before the most significant. 
// meaning: 0bin -> 1bin -> 2bin and so on. 
// then it sorts the deck based on the 2nd least significant digit and recombines the deck in that manner.

// ok, so another explanation is that in the number 329, 9 would be done first, then 2, then 3.



// Counting sort, psuedocode on page 195. 
// Counting sort sorts based on how many elements are smaller than element x.
// ex. if there are 17 elements smaller than x, then x belongs in position 18. 

// 2 vectors, columns k, and size n
// they cant just be arrays, they must be vectors. 
void counting_sort(vector<int> arr[], vector<int> arr2[], int k, int n){

    // You start by initializing C[10]. 10 is literally just the amount of numbers thy want the vectors to be filled with. 
    int C[10];
    // instead of i < k here, it would be i < 10
    // other than that, you still want every element of C to be 0
    for (int i = 0; i < 10; i++){
        C[i] = 0; 
    }
    for (int j = 0; j < n; j++){
        // bc theyre vectors, they need the [][]. rows/ columns.
        C[arr[j][k]] = C[arr[j][k]] + 1;
    }
    // pretty much any instance where I used k as a size, I have to change to 10.
    // this is determining how many elements are leq i. 
    for (int i = 1; i < 10; i++){
        // accidentally made this c[i] - c[i-1]. Was causing a seg fault. 
        C[i] = C[i] + C[i - 1];
    }
    // this places the elements from arr[j] into their spots in the output array, arr2. 
    for (int j = n - 1; j >= 0; j--){
        arr2[C[arr[j][k]] - 1] = arr[j];
        C[arr[j][k]] = C[arr[j][k]] - 1; 
    } 
}

// two arrays and the size n
// they must be vectors. 
void radix_sort(vector<int> arr[], vector<int> arr2[], int n){
    for (int i = 9; i >= 0; i--){
        counting_sort(arr, arr2, i, n);
        for (int i = 0; i < n; i++){
            arr[i] = arr2[i];
        }
    }
}


int main(){
    int n; // the user inputted size of the vectors. rows. 
    int c; // columns. 
    cin >> n; 
    vector<int>arr[n];
    vector<int>arr2[n];

    for (int i = 0; i < n; i++){
        for (int j = 0; j < 10; j++){
            cin >> c;
            arr[i].push_back(c);
        }
    }
    radix_sort(arr, arr2, n);

    for (int i = 0; i < n; i++){
        for (int j = 0; j < 10; j++){
            cout << arr2[i][j] << ";"; 
        }
        cout << "\n";
    }
    return 0; 
}