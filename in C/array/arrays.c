// This is an extensive C program to demonstrate the usage of arrays,
// along with an in-depth explanation of the Big O complexity of each operation.
// The program will be well-commented for clarity and educational purposes.

// --- Includes Section ---
#include <stdio.h>
#include <stdlib.h>

// Arrays are fixed-size, sequential data structures that store elements of the same type.
// In C, an array's size must be declared at compile time or dynamically allocated at runtime.

// --- Function Declarations ---
void print_array(int *arr, int size);
void insert_element(int *arr, int size, int index, int value);
void delete_element(int *arr, int size, int index);
int find_element(int *arr, int size, int value);
void update_element(int *arr, int size, int index, int new_value);
void exercise_solution();

// --- Main Function ---
// The main function will demonstrate the array operations.
int main() {
    // Array Initialization: O(1)
    // We create an array of size 5.
    int arr[5] = {10, 20, 30, 40, 50};  // Array initialization
    int size = 5;                       // Size of the array

    // Print the initial array
    printf("Initial Array:\n");
    print_array(arr, size);

    // 1. Insert Operation: O(n)
    // We'll insert a new element at index 2.
    printf("\nInserting 25 at index 2:\n");
    insert_element(arr, size, 2, 25); // Insert 25 at index 2
    print_array(arr, size);  // Print after insertion

    // 2. Delete Operation: O(n)
    // We'll delete the element at index 4.
    printf("\nDeleting element at index 4:\n");
    delete_element(arr, size, 4);  // Delete element at index 4
    print_array(arr, size);  // Print after deletion

    // 3. Find Operation: O(n)
    // Find if element 40 exists in the array.
    printf("\nFinding element 40 in the array:\n");
    int index = find_element(arr, size, 40);  // Find element 40
    if (index != -1) {
        printf("Element 40 found at index %d.\n", index);
    } else {
        printf("Element 40 not found.\n");
    }

    // 4. Update Operation: O(1)
    // Update the element at index 3 to 99.
    printf("\nUpdating element at index 3 to 99:\n");
    update_element(arr, size, 3, 99);  // Update index 3 to 99
    print_array(arr, size);  // Print after update

    // --- Demonstrating Exercise ---
    // Calling the solution function to an exercise.
    printf("\n--- Exercise Solution ---\n");
    exercise_solution();

    return 0;
}

// --- Array Operations ---

// 1. Print Array Function: O(n)
// This function prints the contents of the array.
// Time complexity: O(n) where n is the size of the array.
void print_array(int *arr, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

// 2. Insert Element Function: O(n)
// Inserting an element into an array can be expensive because the array is a contiguous block of memory.
// If we insert at the beginning or middle, we need to shift all elements after it.
// Time complexity: O(n) where n is the number of elements in the array.
void insert_element(int *arr, int size, int index, int value) {
    // Check if index is valid
    if (index < 0 || index >= size) {
        printf("Error: Index out of bounds.\n");
        return;
    }

    // Shift elements to the right
    for (int i = size - 1; i > index; i--) {
        arr[i] = arr[i - 1];  // Shifting elements to the right
    }
    // Insert new value
    arr[index] = value;
}

// 3. Delete Element Function: O(n)
// Deleting an element from an array also requires shifting all elements after it to the left.
// Time complexity: O(n) where n is the number of elements in the array.
void delete_element(int *arr, int size, int index) {
    // Check if index is valid
    if (index < 0 || index >= size) {
        printf("Error: Index out of bounds.\n");
        return;
    }

    // Shift elements to the left
    for (int i = index; i < size - 1; i++) {
        arr[i] = arr[i + 1];  // Shifting elements to the left
    }
    // For simplicity, we leave the last element as is.
}

// 4. Find Element Function: O(n)
// To find an element in an array, we might have to iterate through the entire array.
// This is known as a linear search.
// Time complexity: O(n) where n is the number of elements in the array.
int find_element(int *arr, int size, int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            return i;  // Return index if element is found
        }
    }
    return -1;  // Return -1 if element is not found
}

// 5. Update Element Function: O(1)
// Updating an element in an array is fast since we directly access the index.
// Time complexity: O(1) because it's a direct access operation.
void update_element(int *arr, int size, int index, int new_value) {
    // Check if index is valid
    if (index < 0 || index >= size) {
        printf("Error: Index out of bounds.\n");
        return;
    }
    arr[index] = new_value;  // Directly update the value
}

// --- Exercise ---
// Problem: Given an array of integers, find the maximum element.
// For simplicity, we assume the array has at least one element.
void exercise_solution() {
    // Example array for the exercise
    int example_arr[] = {5, 10, 3, 99, 65, 2, 43, 76};
    int size = 8;  // Size of the array

    // Initialize max with the first element
    int max = example_arr[0];

    // Traverse the array to find the maximum
    for (int i = 1; i < size; i++) {
        if (example_arr[i] > max) {
            max = example_arr[i];  // Update max if a larger element is found
        }
    }

    // Output the result
    printf("The maximum element in the array is: %d\n", max);
}

// --- Big O Summary ---
// 1. Array Initialization: O(1) - Initializing an array takes constant time.
// 2. Insertion at a specific index: O(n) - Because we might need to shift all elements after the insertion point.
// 3. Deletion at a specific index: O(n) - Similarly, we need to shift all elements after the deletion point.
// 4. Finding an element: O(n) - A linear search requires traversing the array.
// 5. Updating an element: O(1) - Direct access means it takes constant time to update an element.
