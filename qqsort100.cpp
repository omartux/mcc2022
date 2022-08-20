#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

int n=0;

// Swap two elements - Utility function  
void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 
   
// partition the array using last element as pivot
int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high/2];    // pivot mitad
    //int pivot = arr[high]; pivot mayor
    //int pivot = arr[low]; pivot menor, falta random
    int i = (low - 1);   
   
    for (int j = low; j <= high- 1; j++) 
    { 
        //if current element is smaller than pivot, increment the low element
        //swap elements at i and j
        if (arr[j] <= pivot) 
        { 
            i++;    // increment index of smaller element 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 
   
//quicksort 
void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        //partir el array
        int pivot = partition(arr, low, high); 
   
        //ordenar los subarrays
        quickSort(arr, low, pivot - 1); 
        quickSort(arr, pivot + 1, high); 
    } 
} 
   
void displayArray(int arr[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        cout<<arr[i]<<"\t"; 
      
} 
   
int main() 
{ 
    auto start = high_resolution_clock::now();

    
    int arr[] = {-608, 449, 333, 861, -627, -398, -714, 977, 562, -684, 490, -945, 460, -773, -448, -344, -706, 272, -842, -832, -359, -96, -943, 328, -498, 790, -737, 896, 843, -887, 844, 282, 152, -235, 663, 585, 610, 752, -285, 686, -784, 604, 709, 559, 803, -674, -245, -29, 101, 964, 315, -280, 213, 909, -16, -598, 207, -276, -858, 522, -605, 878, -764, 903, -88, -540, -768, -473, -715, 572, -650, -707, -262, -23, -166, 425, 121, -409, -415, -441, -256, 22, 688, 720, 697, -400, -627, 755, 596, 229, -186, -744, 236, 132, -445, 181, 555, 11, 701, 165}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    //cout<<"Input array"<<endl;
    //displayArray(arr,n);
    cout<<endl;
    quickSort(arr, 0, n-1); 
    
    auto stop = high_resolution_clock::now();

    
    
    displayArray(arr,n); 
      cout<<endl;
    cout<<"Array sorted with quick sort"<<endl; 
    
    auto duration = duration_cast<microseconds>(stop - start);
 
// To get the value of duration use the count()
// member function on the duration object
 //   cout << duration.count() << " microseconds "<< endl;
    int duracion = duration.count();
    int duracion_mili = duracion /1000;
    
    cout << duracion << " microsegundos "<< endl;
    cout << duracion_mili << " milisegundos "<< endl;
    cout << "elementos = " << n <<endl;
    
    
    
    return 0; 
}
