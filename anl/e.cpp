#include <cstdlib>
#include <time.h>
#include <iostream>
using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[high]; 
    
    int i = low - 1; 
  
    for (int j = low; j < high; j++)  {
        if (arr[j] <= pivot) {
            i++; 
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}
  
int partition_r(int arr[], int low, int high) {
    srand(time(NULL));
    int random = low + rand() % (high - low);
  
    swap(arr[random], arr[high]);
  
    return partition(arr, low, high);
}
  
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition_r(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
  
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout<<arr[i]<<" "; 
}
  
// Driver Code
int main()
{
    int arr[] = { 10, 7, 8, 9, 1, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);

    // int n;
    // cin>>n;

    // int arr[n];

    // for(int i=0;i<n;i++) cin>>arr[i];
      
    quickSort(arr, 0, n - 1);
    printf("Sorted array: \n");
    printArray(arr, n);
      
    return 0;
}

// Using random pivoting we improve the expected or average time complexity to O (N log N). The Worst-Case complexity is still O ( N^2 ).

// In this article, we will discuss how to implement QuickSort using random pivoting. In QuickSort we first partition the array in place such that all elements to the left of the pivot element are smaller, while all elements to the right of the pivot are greater than the pivot. Then we recursively call the same procedure for left and right subarrays. 
// Unlike merge sort, we don’t need to merge the two sorted arrays. Thus Quicksort requires lesser auxiliary space than Merge Sort, which is why it is often preferred to Merge Sort. Using a randomly generated pivot we can further improve the time complexity of QuickSort.

// We have discussed at two popular methods for partitioning the arrays-Hoare’s vs Lomuto partition scheme 
// It is advised that the reader has read that article or knows how to implement the QuickSort using either of the two partition schemes.