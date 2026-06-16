#include <iostream>      // For input and output

using namespace std;

int main() {

    int n;   // Variable to store size of array

    // Ask user for number of elements
    cout << "Enter number of elements: ";

    // Take input from user
    cin >> n;

    // Declare array of size n
    int arr[n];

    // Ask user to enter array elements
    cout << "Enter array elements:" << endl;

    // Loop to take array input
    for (int i = 0; i < n; i++) {

        // Input each element
        cin >> arr[i];
    }

    // Selection Sort starts here

    // Outer loop for each pass
    for (int i = 0; i < n - 1; i++) {

        // Assume current index has minimum value
        int minIndex = i;

        // Inner loop to find smallest element
        for (int j = i + 1; j < n; j++) {

            // Compare current minimum with next element
            if (arr[j] < arr[minIndex]) {

                // Update minimum index
                minIndex = j;
            }
        }

        // Swap smallest element with current element

        // Store current element temporarily
        int temp = arr[i];

        // Put minimum element at correct position
        arr[i] = arr[minIndex];

        // Put old element at minimum position
        arr[minIndex] = temp;
    }

    // Print sorted array
    cout << "\nSorted array using Selection Sort:" << endl;

    // Loop to print sorted array
    for (int i = 0; i < n; i++) {

        // Print each element
        cout << arr[i] << " ";
    }

    return 0;   // End program
}

/*
Example Input
Enter number of elements: 5
Enter array elements:
64 25 12 22 11
*/
/*
Example Output
Sorted array using Selection Sort:
11 12 22 25 64
*/
/*
Simple Explanation of Selection Sort

Selection Sort is a Greedy Algorithm because:

In every step, it selects the smallest element
Places it at the correct position immediately
Working

Suppose array is:

64 25 12 22 11
Pass 1

Smallest element = 11

Swap with 64

11 25 12 22 64
Pass 2

Smallest element = 12

Swap with 25

11 12 25 22 64
Pass 3

Smallest element = 22

Swap with 25

11 12 22 25 64

Array becomes sorted.

Time Complexity
Case	Complexity
Best Case	O(n²)
Average Case	O(n²)
Worst Case	O(n²)
Why it is called Greedy?

Because at every step it chooses the best immediate option (smallest element)
*/