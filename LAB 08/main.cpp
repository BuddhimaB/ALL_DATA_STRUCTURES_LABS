#include <iostream>
#include <vector>
using namespace std;

// function to heapify the tree
void heapify(int arr[], int n, int root)
{
    int largestValue = root; // Initialize largestValue as the root
    int leftChild = 2 * root + 1; // get leftChild child index
    int rightChild = 2 * root + 2; // get rightChild child index

    // If leftChild  is larger than root
    if (leftChild < n && arr[leftChild] > arr[largestValue])
        largestValue = leftChild;

    // If rightChild is larger than largestValue
    if (rightChild < n && arr[rightChild] > arr[largestValue])
        largestValue = rightChild;

    // If largestValue is not root
    if (largestValue != root) {
        swap(arr[root], arr[largestValue]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largestValue);
    }
}

// implementing heap sort
void heapSort(int arr[], int n)
{
   // build max heap
   for (int i = n / 2 - 1; i >= 0; i--)
       heapify(arr, n, i);

   // extracting elements from heap one by one
   for (int i=n-1; i>=0; i--)
   {
       // Move current root to end
       swap(arr[0], arr[i]);

       // call max heapify on the reduced heap
       heapify(arr, i, 0);
   }
}

/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}

// main program
int main()
{   //vector<int> input{};
    int noOfUserInput;
    int element;

    cout<<"Enter the number of elements to be sorted: "<<endl;
    cin>> noOfUserInput;            // get the number of inputs from the user
    int heap_arr[noOfUserInput];    //initialize the heap Array according to the input from the user
    cout<<"Enter the values with space seperated"<<endl;
    for(int i=0;i<noOfUserInput;i++){
        cin>>heap_arr[i];
    }


   int n = sizeof(heap_arr)/sizeof(heap_arr[0]); // calculating the size of the array
   cout<<"Input array"<<endl;
   displayArray(heap_arr,n); //display the array given by user

   heapSort(heap_arr, n);   // Sorting the array using heapsort function

   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n); //display the array given after sorting
}
