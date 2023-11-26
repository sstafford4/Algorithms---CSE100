#include <iostream> 
#include <stdlib.h> // for inclusion of rand()


using namespace std;


// Whole Lab based on psuedo from page 179 in textbook.

// partition() based on psuedo from page 171 in textbook. 
int partition(int arr[], int p, int r){

    int x = arr[r];
    int i = p - 1;

    // changed from j < r - 1 to j <= r - 1
    for (int j = p; j <= r - 1; j++){
        if (arr[j] <= x){
            i += 1;
            // got my exchanging variables mixed up.
            // this was the root of my issues with the sorting. 
            int temp = arr[i];
            // here, had arr[j] = arr[i] and arr[i] = temp. Thats what was wrong. 
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp2 = arr[i + 1];
    arr[i + 1] = arr[r];
    arr[r] = temp2;

    return (i + 1); 
}

int random_partition(int arr[], int p, int r){
    // make x = a random element in between p and r
    int x = p + rand() % (r - p);
    // swapping elements
    int temp = arr[x]; 
    arr[x] = arr[r];
    arr[r] = temp; 

    // recurrance
    // do I need normal parttition for this? 
    // psuedo says to recurse normal partition.

    // alright. I made partition() and now the code works. Wrong output, probably from dumb mistake. 
    return partition(arr, p, r); 
}

// This is pretty much just the stndard quicksort algo, but using the random pivot instead of the normal one. 
void random_quicksort(int arr[], int p, int r){

    if (p < r){
        int q = random_partition(arr, p, r);
        random_quicksort(arr, p, q-1);
        random_quicksort(arr, q+1, r); 
    }
}

int main(){

    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    random_quicksort(arr, 0, n - 1);

    for (int i = 0; i < n; i++){
        cout << arr[i] << ";";
    }

    return 0; 
}