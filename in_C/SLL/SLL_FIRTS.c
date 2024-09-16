// This is an extensive C program to demonstrate the usage of singly linked lists,
// along with an in-depth explanation of the Big O complexity of each operation.
// The program will be well-commented for clarity and educational purposes.

// --- Includes Section ---
#include <stdio.h>
#include <stdlib.h>

// Singly linked list is a data structure where each element (node) points to the next node in the list.
// The last node points to NULL, indicating the end of the list.

// --- Struct Definitions ---
typedef struct Node {
    int data;              // Data stored in the node
    struct Node *next;     // Pointer to the next node in the list
} Node;

// --- Function Declarations ---
Node* create_node(int data);
void append(Node **head, int data);
void insert_at(Node **head, int index, int data);
void delete_at(Node **head, int index);
Node* find(Node *head, int data);
void update_at(Node *head, int index, int new_data);
void print_list(Node *head);
void exercise_solution();
void free_list(Node **head);

// --- Main Function ---
// The main function will demonstrate the singly linked list operations.
int main() {
    // Linked List Initialization: O(1)
    // We'll start with an empty list.
    Node *head = NULL;  // Initialize an empty list

    // 1. Append Operation: O(n)
    // We'll append elements to the list.
    append(&head, 10);  // Append 10 to the list
    append(&head, 20);  // Append 20
    append(&head, 30);  // Append 30
    append(&head, 40);  // Append 40
    append(&head, 50);  // Append 50

    // Print the initial list
    printf("Initial Linked List:\n");
    print_list(head);

    // 2. Insert Operation: O(n)
    // We'll insert a new element at index 2.
    printf("\nInserting 25 at index 2:\n");
    insert_at(&head, 2, 25);  // Insert 25 at index 2
    print_list(head);  // Print after insertion

    // 3. Delete Operation: O(n)
    // We'll delete the element at index 4.
    printf("\nDeleting element at index 4:\n");
    delete_at(&head, 4);  // Delete element at index 4
    print_list(head);  // Print after deletion

    // 4. Find Operation: O(n)
    // Find if element 40 exists in the list.
    printf("\nFinding element 40 in the list:\n");
    Node *found_node = find(head, 40);  // Find element 40
    if (found_node != NULL) {
        printf("Element 40 found in the list.\n");
    } else {
        printf("Element 40 not found.\n");
    }

    // 5. Update Operation: O(n)
    // Update the element at index 3 to 99.
    printf("\nUpdating element at index 3 to 99:\n");
    update_at(head, 3, 99);  // Update index 3 to 99
    print_list(head);  // Print after update

    // --- Demonstrating Exercise ---
    // Calling the solution function to an exercise.
    printf("\n--- Exercise Solution ---\n");
    exercise_solution();

    // Free the memory used by the list
    free_list(&head);

    return 0;
}

// --- Linked List Operations ---

// 1. Create Node: O(1)
// This function creates a new node with the given data.
// Time complexity: O(1) as creating a node takes constant time.
Node* create_node(int data) {
    Node *new_node = (Node*)malloc(sizeof(Node));  // Allocate memory for a new node
    if (!new_node) {
        printf("Memory allocation error!\n");
        exit(1);  // Exit if memory allocation fails
    }
    new_node->data = data;  // Assign data
    new_node->next = NULL;  // Initialize the next pointer to NULL
    return new_node;  // Return the new node
}

// 2. Append Operation: O(n)
// Appending an element to the end of the linked list requires traversing the list to find the last node.
// Time complexity: O(n), where n is the number of nodes in the list.
void append(Node **head, int data) {
    Node *new_node = create_node(data);  // Create a new node

    // If the list is empty, make the new node the head
    if (*head == NULL) {
        *head = new_node;
        return;
    }

    // Traverse the list to find the last node
    Node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Append the new node at the end
    temp->next = new_node;
}

// 3. Insert at Index: O(n)
// Inserting an element at a specific index requires traversing the list to that index.
// Time complexity: O(n), where n is the number of nodes in the list.
void insert_at(Node **head, int index, int data) {
    // Create a new node
    Node *new_node = create_node(data);

    // If inserting at the head (index 0), update the head pointer
    if (index == 0) {
        new_node->next = *head;
        *head = new_node;
        return;
    }

    // Traverse the list to find the node before the index
    Node *temp = *head;
    for (int i = 0; i < index - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    // If index is out of bounds
    if (temp == NULL) {
        printf("Error: Index out of bounds.\n");
        free(new_node);  // Free the allocated memory for the new node
        return;
    }

    // Insert the new node at the index
    new_node->next = temp->next;
    temp->next = new_node;
}

// 4. Delete at Index: O(n)
// Deleting an element from a specific index requires traversing the list to that index.
// Time complexity: O(n), where n is the number of nodes in the list.
void delete_at(Node **head, int index) {
    // If the list is empty
    if (*head == NULL) {
        printf("Error: List is empty.\n");
        return;
    }

    Node *temp = *head;

    // If deleting the head (index 0)
    if (index == 0) {
        *head = temp->next;  // Update head
        free(temp);  // Free the old head node
        return;
    }

    // Traverse the list to find the node before the index
    for (int i = 0; i < index - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    // If index is out of bounds or next is NULL
    if (temp == NULL || temp->next == NULL) {
        printf("Error: Index out of bounds.\n");
        return;
    }

    // Remove the node at the index
    Node *node_to_delete = temp->next;
    temp->next = node_to_delete->next;
    free(node_to_delete);  // Free the memory of the deleted node
}

// 5. Find Element: O(n)
// Finding an element in a singly linked list requires traversing the list.
// Time complexity: O(n), where n is the number of nodes in the list.
Node* find(Node *head, int data) {
    Node *temp = head;
    while (temp != NULL) {
        if (temp->data == data) {
            return temp;  // Return the node if found
        }
        temp = temp->next;
    }
    return NULL;  // Return NULL if the element is not found
}

// 6. Update Element at Index: O(n)
// Updating an element at a specific index requires traversing the list to that index.
// Time complexity: O(n), where n is the number of nodes in the list.
void update_at(Node *head, int index, int new_data) {
    Node *temp = head;

    // Traverse the list to find the node at the index
    for (int i = 0; i < index && temp != NULL; i++) {
        temp = temp->next;
    }

    // If index is out of bounds
    if (temp == NULL) {
        printf("Error: Index out of bounds.\n");
        return;
    }

    // Update the node's data
    temp->data = new_data;
}

// 7. Print List: O(n)
// This function prints the contents of the linked list.
// Time complexity: O(n), where n is the number of nodes in the list.
void print_list(Node *head) {
    Node *temp = head;
    printf("[");
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) {
            printf(" -> ");
        }
        temp = temp->next;
    }
    printf("]\n");
}

// 8. Free List: O(n)
// This function frees the memory allocated for the linked list.
// Time complexity: O(n), where n is the number of nodes in the list.
void free_list(Node **head) {
    Node *temp;
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

// --- Exercise ---
// Problem: Given a singly linked list, find the maximum element.
// For simplicity, we assume the list has at least one element.
void exercise_solution() {
    // Example list for the exercise
    Node *head = NULL;

    // Add some elements to the list
    append(&head, 5);
    append(&head, 10);
    append(&head, 3);
    append(&head, 99);
    append(&head, 65);
    append(&head, 2);
    append(&head, 43);
    append(&head, 76);

    // Initialize max with the first element
    int max = head->data;

    // Traverse the list to find the maximum
    Node *temp = head;
    while (temp != NULL) {
        if (temp->data > max) {
            max = temp->data;  // Update max if a larger element is found
        }
        temp = temp->next;
    }

    // Output the result
    printf("The maximum element in the linked list is: %d\n", max);

    // Free the list memory after use
    free_list(&head);
}

// --- Big O Summary ---
// 1. Create Node: O(1) - Creating a node takes constant time.
// 2. Append Operation: O(n) - Traversing to the end of the list takes linear time.
// 3. Insert at Index: O(n) - Traversing to the specific index takes linear time.
// 4. Delete at Index: O(n) - Traversing to the specific index takes linear time.
// 5. Find Element: O(n) - Searching for an element takes linear time.
// 6. Update Element: O(n) - Traversing to the index takes linear time.
// 7. Free List: O(n) - Freeing each node takes linear time.
