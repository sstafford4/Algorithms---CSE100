#include <iostream>
#include <list> 

using namespace std;

// TEST 5: tbh don't know why this test isnt passing. 

// k = key, m = size of hash table or number of buckets. m changed to size when I took out that paramater from all of my functions and initilized it from the stat as seen on line 12. 
// takes single division operation, therefore it is pretty fast.
// division method has constraints on the m value, for ex. m should not be a power of 2 bc if m = 2^p, then h(k) is just the p lowest order bits of k.

int size; // initializing this outside of the functions. I had included the size as a paramater to the functions, but that was causing an error in some of the tests. 

int hash_function(int k){
    return (k % size);
}

// takes in a linked list, the key, and the size of the hash table
void hash_insert(list<int> arr[], int k){
    int hash_index = hash_function(k); // uses the hash function to make the new index 
    if (size != 0){
        // push_front inserts elements at the front of the list.
        // in this case, since we're using linked lists, we have to use the new index. 
        arr[hash_index].push_front(k); 
    }
}

void hash_search(list<int> arr[], int k){
    list<int> :: iterator x; // https://stackoverflow.com/questions/31585830/trouble-understanding-listintiterator-i used this to understand :: iterator
    // pretty much, iterators allow you to look at each element of a list one at a time.
    int i = 0; // needed for the output, and also for hash_delete()
    int hash_index = hash_function(k);
    bool flag = false; // boolean used to determine if found or not found  
    for (x = arr[hash_index].begin(); x != arr[hash_index].end(); ++x, i++){
        if (*x == k){
            cout << k << ":FOUND_AT" << hash_index << "," <<  i << ";" << endl; 
            flag = true;
        }
    }
    if (!flag){
        cout << k << ":NOT_FOUND;" << endl;
    }
}

void hash_delete(list<int> arr[], int k){
    list<int> :: iterator x; 
    int i = 0; 
    int hash_index = hash_function(k);
    bool flag2 = false; // this flag is to determine if the element has or hasnt been removed.
    for (x = arr[hash_index].begin(); x != arr[hash_index].end(); ++x, i++){
        if (*x == k){
            arr[i].erase(x);
            cout << k << ":DELETED;" << endl;
            flag2 = true;
            break;  
        }
    }
    if (!flag2){
        cout << k << ":DELETE_FAILED;" << endl; // omg the only reason it wasnt passing test 5 was bc i forgot to include the cout << k here. 
    }
}


void print_it(list<int> arr[]){
    list<int> :: iterator x;
    for (int i = 0; i < size; i++){
        cout << i << ":";
        for (x = arr[i].begin(); x != arr[i].end(); ++x){ // main issue stemmed from here, where I accidentally made it i++ instead of x++
            cout << *x << "->";
        }
        cout << ";" << endl; 
    } 
}

int main(int argc, const char* argv[]){
    //int size;
    cin >> size;
    list<int> arr[size];

    char c;
    int k;

    while (size != 0){
        cin >> c; 
        if (c == 'i'){ // forgot that you cant use "" with chars you have to use ''
            cin >> k;
            hash_insert(arr, k);
        }

        else if (c == 'd'){
            cin >> k;
            hash_delete(arr, k);
        }

        else if (c == 's'){
            cin >> k;
            hash_search(arr, k);
        }

        else if (c == 'o'){
            print_it(arr);
        }

        else{
            if (c == 'e'){
            break;
            }
        }
    }
    return 0;
}