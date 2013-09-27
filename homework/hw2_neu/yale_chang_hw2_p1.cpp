// Author: Yale CHANG
// Complier: g++ (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3
// Platform: Ubuntu Release 12.04 (precise) 32-bit
//           Kernel Linux 3.2.0-53-generic-pae

#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;

// Declaration of functions to be implemented
void insertionSort(vector<int> &A );
void populateVector(vector<int> &A, double m);
void printVector(vector<int> A);

int main()
{
    // Initialize test vector using populateVector
    // Parameter for populateVector 
    double m = 100;
    
    // Specify the number of elements in the vector
    int len_myvector = 10;

    // Initialize the test vector 
    vector<int> myvector(len_myvector,0);

    // Populate the test vector
    populateVector(myvector,m);
    
    // Print out the original vector for comparision
    cout<<"========================================="<<endl;
    cout<<"Begin test of insertionSort:"<<endl;
    cout<<"Original Vector generated by populateVector:";
    printVector(myvector);

    // Test insertionSort
    insertionSort(myvector);
    cout<<"Original Vector after sorting:"; 
    printVector(myvector);
    cout<<"End test of insertionSort."<<endl;
    cout<<"========================================="<<endl;
}

// Implementation of Insertion Sort
void insertionSort(vector<int> &A)
{
    for(vector<int>::iterator j=A.begin()+1;j!=A.end();j++)
    {
        vector<int>::value_type key = *j;
        // Insert A[j] into the sorted sequence A[1..j-1].
        vector<int>::iterator i = j-1;
        while(i>=A.begin() && *i>key)
        {
            *(i+1) = *i;
            i--;
        }
        *(i+1) = key;
    }
}

// Implementation of populateVector
void populateVector(vector<int> &A, double m)
{
    // Obtain the size of the input vector
    vector<int>::size_type size_vec = A.size();
    
    // Note that in g++ 2011 version, the following line can be used directly
    // to generate random number 
    //default_random_engine generator;
    //uniform_int_distribution<int> distribution(-m/2,m/2);

    // Randomly and uniformly select integer numbers from [-m,m]
    for(vector<int>::iterator i=A.begin(); i!=A.end(); i++)
        *i = int(rand()%int(m+1)-m/2);
}

// Implementation of printVector
void printVector(vector<int> A)
{
    for(vector<int>::iterator i=A.begin(); i!=A.end(); i++)
        cout<<*i<<",";
    cout<<endl;
}