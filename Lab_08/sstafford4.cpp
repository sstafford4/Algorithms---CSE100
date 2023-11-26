#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

// taken from textbook chapter 15.2, page 375
void matrix_chain_order(int p[], vector<vector<int>> &m, vector<vector<int>> &s, int n){

    // psuedo: n = p.length() - 1 n in this case is going to be user input. 
    // let m[] and s[] be new tables
    // for i = 1 to n{ m[i,i] = 0} this is setting every element of the 2d array to 0
    // l is the chain length
    // for l = 0 to n{ for i = 1 to n - l + 1{ j = i + l + 1, m[i,j] = +inf
    // for k = i to j - 1{ q = m[i,k] + m[k+1, j] + p_(i - 1)(p_k)(p_j)
    // if q < m[i,j]{ m[i,j] = q, s[i,j] = k}}}}
    // return m and s

    for (int i = 1; i < n; i++){
        m[i][i] = 0; 
    }
    // l is the chaining order
    for (int l = 2; l < n; l++){
        for (int i = 1; i < n - l + 1; i++){
            int j = i + l - 1;
            m[i][j] = INT_MAX;
            // k is supposed to be <= j, thats what was causing the seg faults. 
            for (int k = i; k <= j - 1; k++){
                int q = m[i][k] + m[k + 1][j] + (p[i-1] * p[k] * p[j]);
                if (q < m[i][j]){
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
}

void print(vector<vector<int>> s, int x, int y){

    if (x == y){
        cout << "A" << (x - 1);
    }
    else{
        cout << "(";
        print(s, x, s[x][y]);
        print(s, s[x][y] + 1, y);
        cout << ")";
    }
}



int main(){
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i <= n; i++){
        cin >> arr[i];
    }
    vector<vector<int>> m;
    vector<vector<int>> s;
    
    // .resize() changes the size of a vector
    // learned from https://www.tutorialspoint.com/cpp_standard_library/cpp_vector_resize.htm#:~:text=The%20C%2B%2B%20function%20std%3A%3A,elements%20are%20initialed%20with%20val.
    m.resize(n + 1, vector<int>(n+1, 0));
    s.resize(n + 1, vector<int>(n+1, 0));

    matrix_chain_order(arr, m, s, n+1);
    
    cout << m[1][n] << "\n";
    print(s, 1, n);
    cout << "\n";
    return 0; 
}