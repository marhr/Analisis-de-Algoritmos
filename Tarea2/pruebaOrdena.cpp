// C++ program to merge two sorted arrays/ 
#include <iostream> 
#include <chrono>
#include <vector>
using namespace std;
using namespace chrono; 
  
// Merge arr1[0..n1-1] and arr2[0..n2-1] into 
// arr3[0..n1+n2-1] 
void mergeArrays(int arr1[], int arr2[], int n1, 
                             int n2, int arr3[]) 
{ 
    //timer.reset();
    int i = 0, j = 0, k = 0; 
  
    // Traverse both array 
    while (i<n1 && j <n2) 
    { 
        // Check if current element of first 
        // array is smaller than current element 
        // of second array. If yes, store first 
        // array element and increment first array 
        // index. Otherwise do same with second array 
        if (arr1[i] < arr2[j]) 
            arr3[k++] = arr1[i++]; 
        else
            arr3[k++] = arr2[j++]; 
    } 
  
    // Store remaining elements of first array 
    while (i < n1) 
        arr3[k++] = arr1[i++]; 
  
    // Store remaining elements of second array 
    while (j < n2) 
        arr3[k++] = arr2[j++]; 

    //double tiempo = timer.measure();
    //cout << "tiempo de ejecucion: " << tiempo << endl; 
} 

vector<int> generaVector(){
    srand((int)time(0));
    int i = 0;
    vector<int> v;
    while(i++ < 1000000){
        int r = (rand()%1000000)+1;
        v.push_back(r);
    }
    return v;

}
  
// Driver code 
int main() 
{ 
    // tiempo antes de ejecucion
    auto inicio = high_resolution_clock::now();
    //cout << inicio << endl;
    int arr1[] = {1, 3, 5, 7}; 
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    cout << sizeof(arr1) << endl; 
  
    int arr2[] = {2, 4, 6, 8}; 
    int n2 = sizeof(arr2) / sizeof(arr2[0]); 
    cout << sizeof(arr2) << endl;
  
    int arr3[n1+n2]; 
    mergeArrays(arr1, arr2, n1, n2, arr3); 
    // tiempo despues de ejecucion
    auto fin = high_resolution_clock::now();  
    auto duracion = duration_cast<microseconds>(fin-inicio);
    cout << "Tiempo de ejecucion: " << duracion.count() << endl;
  
    cout << "Array after merging" <<endl; 
    for (int i=0; i < n1+n2; i++) 
        cout << arr3[i] << " ";

    cout << "GENERADOR ALEATORIO" << endl;
    vector<int> v = generaVector(); 
    for (int i=0; i < v.size(); i++) 
        cout << v[i] << " ";
  
    return 0; 
} 