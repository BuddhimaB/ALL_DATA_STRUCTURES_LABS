#include <iostream>
#include <vector>
#include <chrono>


using namespace std;

size_t factorial(int n){
    if (n==0) return 1;
    else if(n==1) return 1;
    return n*factorial(n-1);
}


void mergeSortRecursion(vector<int>& arr){

    if (arr.size()==1) return;

    auto mid = arr.size()/2;

    // divide

    vector<int> left;
    for(int i=0;i<mid;i++)
        left.push_back(arr[i]);

    vector<int> right;
    for(int j=mid;j<arr.size();j++)
        right.push_back(arr[j]);

    mergeSortRecursion(left);
    mergeSortRecursion(right);

    // merge

    int i=0, j=0,k=0;

    while(i<left.size() && j<right.size()){
        if(left[i]>right[j])
            arr[k++]=right[j++];
        else
            arr[k++]=left[i++];
    }

    while(i<left.size())
        arr[k++]=left[i++];

    while(j<right.size())
        arr[k++]=right[j++];
}

void merge(vector<int>& arr, int l, int mid, int r) {

    int leftSize = mid - l + 1;
    int rightSize = r - mid;

    vector<int> left,right;

    for (int i = 0; i < leftSize; i++)
        left.push_back(arr[l + i]);
    for (int j = 0; j < rightSize; j++)
        right.push_back(arr[mid + 1 + j]);

    int i=0,j=0,k=l;

    // compare & merge

    while (i < leftSize && j < rightSize) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }

    // merge remaining elements

    while (i < leftSize)
        arr[k++] = left[i++];

    while (j < rightSize) {
        arr[k++] = right[j++];

    }
}

void mergeSortIterative(vector<int>& arr) {
    int n = arr.size();
    int curr_size;

    for (curr_size = 1; curr_size <= n - 1; curr_size = 2 * curr_size) {
        for (int left_start = 0; left_start < n - 1; left_start += 2 * curr_size) {

            int mid = min(left_start + curr_size - 1, n - 1);
            int right_end = min(left_start + 2 * curr_size - 1, n - 1);

            merge(arr, left_start, mid, right_end);
        }
    }
}


vector<int> createRandomArray(int size) {
    vector<int> randArray(size);
    srand(std::time(nullptr));
    for (int i = 0; i < size; i++)
        randArray[i] = rand() % 100;
    return randArray;
}

void executionTimeRe(vector<int>& arr){
    auto start_time = std::chrono::high_resolution_clock::now();

    mergeSortRecursion(arr);

    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);

    cout << "recursion : "<<arr.size()<<" : "<< duration.count() << " microseconds\n";
}

void executionTimeIt(vector<int>& arr){
    auto start_time = std::chrono::high_resolution_clock::now();

    mergeSortIterative(arr);

    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);

    cout << "Iteration : "<<arr.size()<<" : "<< duration.count() << " microseconds\n";
}

void executionTimeReport(vector<int>& arr){
    executionTimeRe(arr);
    executionTimeIt(arr);
}


int main() {

    auto arr = createRandomArray(20000);
    executionTimeReport(arr);

}