// Including necessary header files for input/output, strings, vectors, and conversions
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <sstream>

using namespace std;

// Function to perform the merge sort algorithm
vector<int> mergeSorting(vector<int> vect, int n);

// Function to merge two sorted sub-vectors
vector<int> merge(vector<int> vect, int start, int mid, int end);

// Function to merge two sorted sub-vectors
vector<int> merge(vector<int> vect, int start, int mid, int end) {
    // Calculating sizes of the two sub-vectors 
    int n1 = mid - start + 1;
    int n2 = end - mid;

    // Creating temporary vectors to store the elements of the sub array left and right
    vector<int> leftVect(n1);
    vector<int> rightVect(n2);

    // Copying elements into the temporary left vector
    for (int i = 0; i < n1; i++) {
        leftVect[i] = vect[start + i];
    }

    // Copying elements into the temporary right vector
    for (int j = 0; j < n2; j++) {
        rightVect[j] = vect[mid + 1 + j];
    }

    // Initalize new ariables to iterate through the sub vectors and main vector
    int leftFlag = 0;
    int rightFlag = 0;
    int key = start;

    // Iterating through the sub-vectors and merging them
    while ((leftFlag < n1) && (rightFlag < n2)) {
        //check what is the smallest element amog the current possitions of the left and right array 
        if (leftVect[leftFlag] >= rightVect[rightFlag]) {
            //update main vector with the correct possition of the current element
            vect[key] = rightVect[rightFlag];
            //increment the current possition of the right vector
            rightFlag++;
        } else {
            //update main vector with the correct possition of the current element
            vect[key] = leftVect[leftFlag];
            //increment the current possition of the left vector
            leftFlag++;
        }
        // Increment the current iteration index of the main array
        key++;
    }

    // Copying remaining elements from the left sub vector
    while (leftFlag < n1) {
        vect[key] = leftVect[leftFlag];
        leftFlag++;
        key++;
    }
    
    // Copying remaining elements from the right sub vector
    while (rightFlag < n2) {
        vect[key] = rightVect[rightFlag];
        rightFlag++;
        key++;
    }
    
    // Returning the merged vector
    return vect;
}

// Recursive function to perform merge sort
vector<int> mergeSorting(vector<int> vect, int start, int end) {
   
}

// Main function
int main() {
    // Vector to store input numbers
    vector<int> numberVector;
    int k = 0;
    
    // Getting input from the user
    string input;
    getline(cin, input);
    
    // Parsing input string to extract numbers
    istringstream stream(input);
    int number;
    // Store inputed numbers in the number vector
    while (stream >> number) {
        numberVector.push_back(number);
        k++;
    }
    
    // Sorting the vector using merge sort algorithm
    numberVector = mergeSorting(numberVector, 0, k - 1);

    // Printing the sorted vector
    for (int a = 0; a < k; a++) {
        cout << numberVector[a] << " "; 
    }
    cout << endl;
    
    // Return statement indicating successful execution
    return 0;
}
