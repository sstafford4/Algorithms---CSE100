#include <iostream>

using namespace std;

// Based on Divide and Conquer psudeocode.
// Will try to translate the psuedo from page 72 of the textbook.
// O(nlogn) running time algorithm from Max Subarray problem. 
// Apparently, we also did this in lecture. Probably will remember it when I see the psuedo.


// Lets see if this works. I didnt translate the psuedocode exactly. 
int find_crossing(int a[], int low, int mid, int high){
    
    int left_sum = 0; // left_sum is supposed to be equal to neg infinity
    int max_left;
    int right_sum = 0; // right_sum is suppoed to be equal to neg infinity
    int max_right; 

    // to make this even able to compile, Ive set left and right sum equal to 0 as a placeholder.
    // this works fne, did not have to use sentinels. 

    int sum = 0; 
    for (int i = mid; i >= low; i--){
        sum += a[i];
        if (sum > left_sum){
            left_sum = sum;
            max_left = i;
        }
    }

    // issue found! Did not reset sum to be 0 after dealing with left side. 
    // this caused an error in the calculations. 
    sum = 0;
    for (int j = mid + 1; j <= high; j++){
        sum += a[j]; 
        if (sum > right_sum){
            right_sum = sum;
            max_right = j; 
        }
    }
    return (max_left, max_right, (left_sum + right_sum));

}

int find_max(int a[], int low, int high){
    int left_low, left_high, left_sum, right_low, right_high, right_sum, cross_low, cross_high, cross_sum; 
    // if the value if already equal, just return it. 
    if (high == low){
        return (low, high, a[low]);
    }
    // This was actually so straightforward i didnt know that you could assign variables this way lol
    // pretty much exactly like the psuedocode was. 
    else{
        int mid = ((low + high) / 2); 
        (left_low, left_high, left_sum) = find_max(a, low, mid);
        (right_low, right_high, right_sum) = find_max(a, mid + 1, high); 
        (cross_low, cross_high, cross_sum) = find_crossing(a, low, mid, high);

        if (left_sum >= right_sum && left_sum >= cross_sum){
            return (left_low, left_high, left_sum);
        }
        else if (right_sum >= left_sum && right_sum >= cross_sum){
                return (right_low, right_high, right_sum);
            }
        else{
            return  (cross_low, cross_high, cross_sum);
        }

    }

}

int main(){

    int n;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    int max = find_max(a, 0, n - 1);
    cout << max; 


    return 0; 
}