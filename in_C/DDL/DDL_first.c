// This C program demonstrates the usage of a doubly linked list, explaining each operation
// in detail along with its Big O complexity. Each operation is well-commented for educational
// purposes.

// --- Includes Section ---
#include <stdio.h>
#include <stdlib.h>

// Doubly Linked List: Each node contains data, a pointer to the next node, and a pointer
// to the previous node, allowing bidirectional traversal.

// --- Struct Definitions ---
typedef struct Node {
    int data;               // Data stored in the node
    struct Node *next;      // Pointer to the next node
    struct Node *prev;      // Pointer to the previous node
} Node;

// --- Function Declarations ---
Node* create_node(int data);
void append(Node **head, int data);
void insert_at(Node **head, int index, int data);
void delete_at(Node **head, int index);
Node* find(Node *head, int data);
void update_at(Node *head, int index, int new_data);
void print_list_forward(Node *head);
void print_list_backward(Node *head);
void exercise_solution();
void free_list(Node **head);

// --- Main Function ---
int main() {
    // Doubly Linked List Initialization: O(1)
    // We'll start with an empty list.
    Node *head = NULL;  // Initialize an empty list

    // 1. Append Operation: O(n)
    // Append elements to the list
    append(&head, 10);  // Append 10 to the list
    append(&head, 20);  // Append 20
    append(&head, 30);  // Append 30
    append(&head, 40);  // Append 40
    append(&head, 50);  // Append 50

    // Print the initial list in forward and backward direction
    printf("Initial Doubly Linked List (Forward):\n");
    print_list_forward(head);

    printf("Initial Doubly Linked List (Backward):\n");
    print_list_backward(head);

    // 2. Insert Operation: O(n)
    // Insert a new element at index 2
    printf("\nInserting 25 at index 2:\n");
    insert_at(&head, 2, 25);  // Insert 25 at index 2
    print_list_forward(head);  // Print after insertion

    // 3. Delete Operation: O(n)
    // Delete the element at index 4
    printf("\nDeleting element at index 4:\n");
    delete_at(&head, 4);  // Delete element at index 4
    print_list_forward(head);  // Print after deletion

    // 4. Find Operation: O(n)
    // Find if element 40 exists in the list
    printf("\nFinding element 40 in the list:\n");
    Node *found_node = find(head, 40);  // Find element 40
    if (found_node != NULL) {
        printf("Element 40 found in the list.\n");
    } else {
        printf("Element 40 not found.\n");
    }

    // 5. Update Operation: O(n)
    // Update the element at index 3 to 99
    printf("\nUpdating element at index 3 to 99:\n");
    update_at(head, 3, 99);  // Update index 3 to 99
    print_list_forward(head);  // Print after update

    // --- Exercise Demonstration ---
    printf("\n--- Exercise Solution ---\n");
    exercise_solution();

    // Free the list memory
    free_list(&head);

    return 0;
}

// --- Doubly Linked List Operations ---

// 1. Create Node: O(1)
// This function creates a new node with the given data.
// Time complexity: O(1), since creating a node takes constant time.
Node* create_node(int data) {
    Node *new_node = (Node*)malloc(sizeof(Node));  // Allocate memory for a new node
    if (!new_node) {
        printf("Memory allocation error!\n");
        exit(1);  // Exit if memory allocation fails
    }
    new_node->data = data;  // Assign data
    new_node->next = NULL;  // Initialize the next pointer to NULL
    new_node->prev = NULL;  // Initialize the previous pointer to NULL
    return new_node;  // Return the new node
}

// 2. Append Operation: O(n)
// Appending an element to the end of the list requires traversing to the end.
// Time complexity: O(n), where n is the number of nodes in the list.
void append(Node **head, int data) {
    Node *new_node = create_node(data);  // Create a new node

    // If the list is empty, make the new node the head
    if (*head == NULL) {
        *head = new_node;
        return;
    }

    // Traverse to the end of the list
    Node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Append the new node at the end
    temp->next = new_node;
    new_node->prev = temp;
}

// 3. Insert at Index: O(n)
// Inserting an element at a specific index requires traversing to that index.
// Time complexity: O(n), where n is the number of nodes in the list.
void insert_at(Node **head, int index, int data) {
    Node *new_node = create_node(data);

    // If inserting at the head (index 0)
    if (index == 0) {
        new_node->next = *head;
        if (*head != NULL) {
            (*head)->prev = new_node;
        }
        *head = new_node;
        return;
    }

    // Traverse to the node before the insertion point
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
    new_node->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = new_node;
    }
    temp->next = new_node;
}

// 4. Delete at Index: O(n)
// Deleting an element from a specific index requires traversing to that index.
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
        *head = temp->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
        free(temp);  // Free the old head node
        return;
    }

    // Traverse to the node at the given index
    for (int i = 0; i < index && temp != NULL; i++) {
        temp = temp->next;
    }

    // If index is out of bounds
    if (temp == NULL) {
        printf("Error: Index out of bounds.\n");
        return;
    }

    // Update the pointers to remove the node
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }

    // Free the memory of the deleted node
    free(temp);
}

// 5. Find Element: O(n)
// Finding an element in a doubly linked list requires traversing the list.
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
// Updating an element at a specific index requires traversing to that index.
// Time complexity: O(n), where n is the number of nodes in the list.
void update_at(Node *head, int index, int new_data) {
    Node *temp = head;

    // Traverse to the node at the index
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

// 7. Print List Forward: O(n)
// This function prints the contents of the list in forward direction.
// Time complexity: O(n), where n is the number of nodes in the list.
void print_list_forward(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);  // Print the data
        temp = temp->next;
    }
    printf("NULL\n");
}

// 8. Print List Backward: O(n)
// This function prints the contents of the list in backward direction.
// Time complexity: O(n), where n is the number of nodes in the list.
void print_list_backward(Node *head) {
    if (head == NULL) return;

    // Traverse to the end of the list
    Node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Print in reverse
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

// 9. Free List: O(n)
// This function frees all the memory allocated for the linked list.
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
// Problem: Given a doubly linked list, find the minimum element.
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

    // Initialize min with the first element
    int min = head->data;

    // Traverse the list to find the minimum
    Node *temp = head;
    while (temp != NULL) {
        if (temp->data < min) {
            min = temp->data;  // Update min if a smaller element is found
        }
        temp = temp->next;
    }

    // Output the result
    printf("The minimum element in the linked list is: %d\n", min);

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
// 7. Print List Forward: O(n) - Printing the list in forward direction takes linear time.
// 8. Print List Backward: O(n) - Printing the list in reverse direction takes linear time.
// 9. Free List: O(n) - Freeing each node takes linear time.
