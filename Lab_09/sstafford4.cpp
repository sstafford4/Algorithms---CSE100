#include <iostream>
#include <queue> // going to use priority queues
#include <string>
#include <vector>

// entire code is based on: https://www.geeksforgeeks.org/huffman-coding-using-priority-queue/

// Huffman coding is a lossless data compression algorithm.
// The idea is to assign variable-length codes to input characters, lengths of the assigned codes are based on the frequencies of corresponding characters


// the more characters, the smaller the frequency, and vice versa. 

using namespace std;

string max_huffman[0];

class HuffmanNode{
public:
    string data; // stores the character
    int frequency; // stores the requency of the character
    int unique; // the unique character for huffman encoding. 

    HuffmanNode* left; // left child of current node
    HuffmanNode* right; // right child of current node
    
    // This is going to initialize the current node
    HuffmanNode(string input_char, int input_freq){
        left, right = NULL; 
        this->data = input_char;
        this->frequency = input_freq;
        this->unique = 0; 
    }

    HuffmanNode(string input_char, int input_freq, int input_unique){
        left, right = NULL; 
        this->data = input_char;
        this->frequency = input_freq;
        this->unique = input_unique; 
    }
};

class Compare{
public:
    // Overloading operator() to give it user defined meaning
    // Notes on overloading operators: https://www.geeksforgeeks.org/operator-overloading-cpp/
    bool operator()(HuffmanNode* a, HuffmanNode* b){// returns true or false if there is a unique character detected.
        // these are going to define the priority based on the frequency of the character. 
        // first of all based on whether or not the frequency of left and right are the same. 
        // if it is, define the priority based on the unique character instead of the frequency. 
        if (a->frequency == b->frequency){
            return (a->unique > b->unique);
        }
        else{
            return (a->frequency > b->frequency); // frequency is a member of HuffmanNode
        }
    }

};
// These are the only classes/structures that I need. 
// Now going to make some functions to actually do the Huffman coding.

// Basing on the G4G huffman coding using STL: https://www.geeksforgeeks.org/huffman-coding-greedy-algo-3/
// function to print the huffman codes for each character. 
// printCodes uses an array to store the huffman codes
void printCodes(HuffmanNode* root, string character, string options[], int n){

    if (root == NULL){
        return;
    }
    else{
        // different than the compare class, this is a built in function that compares the string to the sequence of characters specified by the argument.
        // Notes on compare(): https://www.digitalocean.com/community/tutorials/compare-strings-in-c-plus-plus
        if (root->data.compare("!") != 0){
            for (int i = 0; i < n; i++){
                if (root->data.compare(options[i]) == 0){
                    max_huffman[i] = character; 
                }
            }
        }
        if (root->data.compare("!") == 0){ // if it is a parent node
            printCodes(root->left, character + "0", options, n);
            printCodes(root->right, character + "1", options, n);
        }
        // this is a translation of this. 
        // if (root->left) {
        //     arr[top] = 0;
        //     printCodes(root->left,
        //         arr, top + 1);
        //     }
        // if (root->right) {
        //     arr[top] = 1;
        //     printCodes(root->right, arr, top + 1);
        // }
    }
}

void Huffman(string data[], vector<int>& freq, int n){ // building the Huffman tree

    priority_queue<HuffmanNode*, vector<HuffmanNode*>, Compare> pq;//creating the priority queue using a custom comparator
    HuffmanNode* root;
    HuffmanNode* left; 
    HuffmanNode* right;
    root, left, right = NULL;  

    for (int i = 0; i < n; i++){
        HuffmanNode* newNode = new HuffmanNode(data[i], freq[i], i+1); // sets an array of type HuffmanNode that holds data, freq, and the unique character
        pq.push(newNode);
    }

    while (pq.size() > 1){
        left = pq.top(); // getting the min number
        pq.pop();
        right = pq.top(); // getting the second min number;
        pq.pop();

        HuffmanNode* parent = new HuffmanNode("!", (left->frequency + right->frequency)); // creating a new parent node 
        root = parent; // making the new parent node the root
        if (left->frequency == right->frequency && left->unique > right->unique){ // swapping child nodes if left is greater than right. 
            root->left = right;
            root->right = left;
            root->unique = left->unique; 
        }
        else{ // otherwise leave it alone. 
            root->left = left;
            root->right = right;
            root->unique = left->unique; 
        }
        pq.push(root); // pushing in the finalized parent node. 
    }
    
    printCodes(pq.top(), "", data, n); 
    
    char j = 'A';
    for (int i = 0; j <= 'F'; i++, j++){
        cout << j << ":" << max_huffman[i] << endl; 
    }
}

int main(int argc, char** argv){
    int n = 6;
    int value = 0; 

    vector<int> freq; 
    string A[n];

    for (int i = 0; i < n; i++){
        cin >> value;
        freq.push_back(value);
        A[i] = "K" + to_string(i);  
    }

    Huffman(A, freq, n);
    
    return 0;
}