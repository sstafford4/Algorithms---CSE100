#include <iostream>
#include <limits.h>
// including limit.h so that i can have access to INT_MIN and INT_MAX for sentinels. 

using namespace std;

// n = size
// arr_p = array of prices of metal rod.
// arr_r = array of revenue, given as r sub n in the book.


// memoized means that it stores every subproblem its already done in a new array or hash table.
// in the non efficient cut-rod shown in the book, it had to do the same subproblem many times with arger inputs, and that caused it to take much more time
// this one takes q, which is represents the subproblems the program has already done and checks every time to see if its done it. 
// memoized --> "remembers"

// switching to do the extended bottom up cut from the book bc the psuedo for printing the output is confusing me when I try to apply it to the memoized version. 

void extended_bottom_up_cut(int arr_p[], int n){
    int arr_r[n];
    int arr_s[n];

    arr_r[0] = 0;
    int q = INT_MIN; 
    for (int j = 1; j < n; j++){
        for (int i = 1; i <= j; i++){
            if (q < (arr_p[i] + arr_r[j - i])){
                q = arr_p[i] + arr_r[j - i];
                arr_s[j] = i;
            }
        }
        arr_r[j] = q;
    }
    n -= 1;
    cout << arr_r[n] << endl;

    while (n > 0){
        cout << arr_s[n] << " ";
        n = n - arr_s[n];
    }
    cout << "-1" << endl;

}


// ripped directly from verifier.cpp, whiich was included in the zip file. 
int main(int argc,char **argv) {

  // Get the size of the sequence
  int n = 1;
  int* p; 

  cin >> n;

  p = new int[n+1];
  //read p; 
  p[0] = 0; 
  for(int i=1; i<=n; i++)
  {
    cin >> p[i];  
  }
  // only had to add in this part. n + 1 bc p is a new int pointer / array of size n + 1
  extended_bottom_up_cut(p, n + 1);

}