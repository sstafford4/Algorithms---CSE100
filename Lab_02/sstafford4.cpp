#include <iostream>

using namespace std; 

void merge(int arr[], int p, int q, int r){
    int n_1 = q - p + 1;
    int n_2 = r - q;
    // Let L and R be new arrays of size [n_1 + 1] and [n_2 + 1]

    int L[n_1];
    int R[n_2];
    // wondering if I'm suppsoed to make these dynamically allocated / sized.
    // allocating memory from the heap for these subarrays. Dont forget to delete[] them at the end to prevent an overflow.  

    for (int i = 0; i < n_1; i++){
        L[i] = arr[p + i];
    }
    for (int j = 0; j < n_2; j++){
        R[j] = arr[q + j + 1];
    }
    // in the psuedocode, at this point, L[n_1 + 1] and R[n_2 + 1] are supposed to equal to infinity. 
    // Im unsure what thats supposed to mean in terms of coding syntax, but i'll figure it out.
    int i_n1 = 0;
    int i_n2 = 0;
    int i_merged; 
    
    for (i_merged = p; i_n1 < n_1 && i_n2 < n_2; i_merged++){
        if (L[i_n1] < R[i_n2]){
            arr[i_merged] = L[i_n1];
            i_n1 += 1; 
        }
        else{
            arr[i_merged] = R[i_n2];
            i_n2 += 1; 
        }
    }
    // copy remaining elements of L
    while (i_n1 < n_1){
        arr[i_merged] = L[i_n1];
        i_n1 += 1;
        i_merged += 1; 
    }
    // copy remaining elements of R
    while (i_n2 < n_2){
        arr[i_merged] = R[i_n2];
        i_n2 += 1; 
        i_merged += 1; 
    }
}

void merge_sort(int arr[], int p, int q){
    if (p < q){
        int r = p + (q - p) / 2;
        merge_sort(arr, p, r);
        merge_sort(arr, r + 1, q);
        merge(arr, p, r, q);
    }
}


int main(){
    int arr_n; 
    cin >> arr_n;

    int arr[arr_n];

    for (int i = 0; i < arr_n; i++){
        cin >> arr[i]; 
    }
    merge_sort(arr, 0, arr_n - 1);

    for (int i = 0; i < arr_n; i++){
       cout << arr[i] << ";";
    }
    return 0;
}