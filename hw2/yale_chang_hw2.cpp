// Author: Yale CHANG
// Complier: g++ (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3
// Platform: Ubuntu Release 12.04 (precise) 32-bit
//           Kernel Linux 3.2.0-53-generic-pae

#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;

void insertionSort(vector<int> &A );
void populateVector(vector<int> &A, double m);
void printVector(vector<int> A);

int main()
{
    // Initialize test vector 
    int test_vector[] = {3,7,2,9,5,4};
    vector<int> myvector(test_vector,test_vector+sizeof(test_vector)/sizeof(int));
    
    // Test insertionSort
    insertionSort(myvector);
    printVector(myvector);

    // Test populateVector
    vector<int> vector_1(6,0);
    double m = 100;
    populateVector(vector_1,m);
    printVector(vector_1);
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
