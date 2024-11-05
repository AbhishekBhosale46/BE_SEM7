#include<bits/stdc++.h>
using namespace std;

void printArray(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int deterministicPartition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low-1;
    for(int j=low; j<high; j++){
        if(arr[j]<=pivot){
            i++;
            swap(arr[j], arr[i]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i+1;
}

void deterministicQuickSort(int arr[], int low, int high){
    if(low<high){
        int pivotIndex = deterministicPartition(arr, low, high);
        deterministicQuickSort(arr, low, pivotIndex-1);
        deterministicQuickSort(arr, pivotIndex+1, high);
    }
}


int randomizePartition(int arr[], int low, int high){
    int randomPivot = low + rand() % (high-low+1);
    swap(arr[high], arr[randomPivot]);
    return deterministicPartition(arr, low, high);
}

void randomizeQuickSort(int arr[], int low, int high){
    if(low<high){
        int pivotIndex = randomizePartition(arr, low, high);
        randomizeQuickSort(arr, low, pivotIndex-1);
        randomizeQuickSort(arr, pivotIndex+1, high);
    }
}


int main(){

    int arr[] = {8, 7, 6, 1, 0, 9, 2};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<"Original array: ";
    printArray(arr, n);

    int arr1[] = {8, 7, 6, 1, 0, 9, 2};
    deterministicQuickSort(arr1, 0, n-1);
    cout<<"Sorted array with Deterministic Quick Sort: ";
    printArray(arr1, n);

    int arr2[] = {8, 7, 6, 1, 0, 9, 2};
    randomizeQuickSort(arr2, 0, n-1);
    cout<<"Sorted array with Randomize Quick Sort: ";
    printArray(arr2, n);

    return 0;
}