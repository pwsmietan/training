#include <iostream>

#define DEBUG true

using namespace std;

// Function to swap two elements in the array
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to print the array
void printArray(int arr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    cout << "; size: " << size << endl;
}

// Partition function to rearrange the array around a pivot element
int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // Select the last element as pivot
    int i = (low - 1);     // Index of smaller element

#ifdef DEBUG
    cout << "Pivot (high) value=" << pivot << "; (low value): " << low << "; Partition l=" << low << "; h=" << high << endl;
#endif

    for(int j = low; j <= high - 1; j++)
    {
        // Move elements smaller than pivot to the left side
#ifdef DEBUG
        cout << "Compare arr[j]: " << arr[j] << " to pivot (last element in array): " << pivot << endl;
#endif
        if(arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
#ifdef DEBUG
            cout << "values swapped: " << arr[i] << "->" << arr[j] << endl;
            printArray(arr, high+1);
#endif
        }
    }

    swap(&arr[i + 1], &arr[high]); // Put pivot at its correct position
#ifdef DEBUG
    cout << "next swap: " << arr[i+1] << " -> " << arr[high] << endl;
    printArray(arr, high+1);
    cout << "Returning partition: " << i + 1 << endl;
#endif

    return (i + 1);
}

// Recursive quicksort function
void quickSort(int arr[], int low, int high)
{
    cout << "In QS: low index=" << low << "; high index=" << high << endl;
    if(low < high)
    {
        int pi = partition(arr, low, high); // Partitioning index

        // Recursively sort elements before and after their respective partition:
#ifdef DEBUG
        cout << "Recursive call #1: l=" << low << "; h=" << high << "; partition: " << pi - 1 << endl;
#endif
        quickSort(arr, low, pi - 1);

#ifdef DEBUG
        cout << "Recursive call #2: l=" << pi + 1 << "; h=" << high << endl;
#endif
        quickSort(arr, pi + 1, high);
    }
    else
    {
#ifdef DEBUG
        cout << "low not less than high - fall through!\n";
#endif
    }
}


int main()
{
    int arr[] = { 10, 7, 8, 9, 1, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Unsorted array: ";
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}