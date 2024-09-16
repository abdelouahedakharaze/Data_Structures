// This C program demonstrates the usage of a binary tree, explaining each operation
// in detail along with its Big O complexity. Each operation is well-commented for educational
// purposes.

// --- Includes Section ---
#include <stdio.h>
#include <stdlib.h>

// --- Struct Definitions ---
// Binary Tree: Each node contains data, a pointer to the left child, and a pointer
// to the right child, allowing hierarchical relationships.

typedef struct TreeNode {
    int data;                  // Data stored in the node
    struct TreeNode *left;     // Pointer to the left child
    struct TreeNode *right;    // Pointer to the right child
} TreeNode;

// --- Function Declarations ---
TreeNode* create_node(int data);
TreeNode* insert(TreeNode *root, int data);
TreeNode* find(TreeNode *root, int data);
TreeNode* delete(TreeNode *root, int data);
TreeNode* find_min(TreeNode *root);
void inorder_traversal(TreeNode *root);
void preorder_traversal(TreeNode *root);
void postorder_traversal(TreeNode *root);
void exercise_solution();
void free_tree(TreeNode *root);

// --- Main Function ---
int main() {
    // Binary Tree Initialization: O(1)
    TreeNode *root = NULL;  // Start with an empty tree

    // 1. Insert Operation: O(log n) on average, O(n) in the worst case (unbalanced)
    // Insert elements into the tree
    root = insert(root, 50);  // Insert 50
    root = insert(root, 30);  // Insert 30
    root = insert(root, 70);  // Insert 70
    root = insert(root, 20);  // Insert 20
    root = insert(root, 40);  // Insert 40
    root = insert(root, 60);  // Insert 60
    root = insert(root, 80);  // Insert 80

    // 2. Traversal Operations: O(n)
    // Inorder Traversal: Left -> Root -> Right
    printf("Inorder Traversal:\n");
    inorder_traversal(root);

    // Preorder Traversal: Root -> Left -> Right
    printf("\nPreorder Traversal:\n");
    preorder_traversal(root);

    // Postorder Traversal: Left -> Right -> Root
    printf("\nPostorder Traversal:\n");
    postorder_traversal(root);

    // 3. Find Operation: O(log n) on average, O(n) in the worst case (unbalanced)
    // Find element 40 in the tree
    printf("\nFinding element 40 in the tree:\n");
    TreeNode *found_node = find(root, 40);
    if (found_node != NULL) {
        printf("Element 40 found in the tree.\n");
    } else {
        printf("Element 40 not found in the tree.\n");
    }

    // 4. Delete Operation: O(log n) on average, O(n) in the worst case (unbalanced)
    // Delete the element 70 from the tree
    printf("\nDeleting element 70 from the tree:\n");
    root = delete(root, 70);
    inorder_traversal(root);  // Inorder traversal after deletion

    // --- Exercise Demonstration ---
    printf("\n--- Exercise Solution ---\n");
    exercise_solution();

    // Free the tree memory
    free_tree(root);

    return 0;
}

// --- Binary Tree Operations ---

// 1. Create Node: O(1)
// This function creates a new node with the given data.
// Time complexity: O(1), since creating a node takes constant time.
TreeNode* create_node(int data) {
    TreeNode *new_node = (TreeNode*)malloc(sizeof(TreeNode));  // Allocate memory for the new node
    if (!new_node) {
        printf("Memory allocation error!\n");
        exit(1);  // Exit if memory allocation fails
    }
    new_node->data = data;    // Assign data
    new_node->left = NULL;    // Initialize the left child to NULL
    new_node->right = NULL;   // Initialize the right child to NULL
    return new_node;          // Return the new node
}

// 2. Insert Operation: O(log n) on average, O(n) in the worst case (unbalanced)
// This function inserts a new element into the binary search tree.
// Time complexity: O(log n) on average for balanced trees, O(n) for unbalanced trees.
TreeNode* insert(TreeNode *root, int data) {
    // If the tree is empty, create a new node
    if (root == NULL) {
        return create_node(data);
    }

    // Otherwise, insert the data into the correct position in the subtree
    if (data < root->data) {
        root->left = insert(root->left, data);  // Insert into the left subtree
    } else if (data > root->data) {
        root->right = insert(root->right, data);  // Insert into the right subtree
    }

    return root;  // Return the root of the subtree
}

// 3. Find Operation: O(log n) on average, O(n) in the worst case (unbalanced)
// This function finds an element in the binary search tree.
// Time complexity: O(log n) on average for balanced trees, O(n) for unbalanced trees.
TreeNode* find(TreeNode *root, int data) {
    // If the tree is empty or the data is found
    if (root == NULL || root->data == data) {
        return root;
    }

    // Search in the left or right subtree
    if (data < root->data) {
        return find(root->left, data);  // Search in the left subtree
    } else {
        return find(root->right, data);  // Search in the right subtree
    }
}

// 4. Delete Operation: O(log n) on average, O(n) in the worst case (unbalanced)
// This function deletes an element from the binary search tree.
// Time complexity: O(log n) on average for balanced trees, O(n) for unbalanced trees.
TreeNode* delete(TreeNode *root, int data) {
    // If the tree is empty, return NULL
    if (root == NULL) {
        return root;
    }

    // Search for the node to delete
    if (data < root->data) {
        root->left = delete(root->left, data);  // Search in the left subtree
    } else if (data > root->data) {
        root->right = delete(root->right, data);  // Search in the right subtree
    } else {
        // If the node is found
        if (root->left == NULL) {
            TreeNode *temp = root->right;
            free(root);  // Free the current node
            return temp;  // Return the right child
        } else if (root->right == NULL) {
            TreeNode *temp = root->left;
            free(root);  // Free the current node
            return temp;  // Return the left child
        }

        // If the node has two children, find the in-order successor (smallest in the right subtree)
        TreeNode *temp = find_min(root->right);
        root->data = temp->data;  // Replace the current node's data with the in-order successor's data
        root->right = delete(root->right, temp->data);  // Delete the in-order successor
    }

    return root;  // Return the root of the subtree
}

// 5. Find Minimum: O(log n) on average, O(n) in the worst case (unbalanced)
// This function finds the minimum value in a binary search tree.
// Time complexity: O(log n) on average for balanced trees, O(n) for unbalanced trees.
TreeNode* find_min(TreeNode *root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// 6. Inorder Traversal: O(n)
// This function performs an in-order traversal of the tree.
// Time complexity: O(n), where n is the number of nodes in the tree.
void inorder_traversal(TreeNode *root) {
    if (root != NULL) {
        inorder_traversal(root->left);    // Visit the left subtree
        printf("%d -> ", root->data);     // Visit the root
        inorder_traversal(root->right);   // Visit the right subtree
    }
}

// 7. Preorder Traversal: O(n)
// This function performs a pre-order traversal of the tree.
// Time complexity: O(n), where n is the number of nodes in the tree.
void preorder_traversal(TreeNode *root) {
    if (root != NULL) {
        printf("%d -> ", root->data);     // Visit the root
        preorder_traversal(root->left);   // Visit the left subtree
        preorder_traversal(root->right);  // Visit the right subtree
    }
}

// 8. Postorder Traversal: O(n)
// This function performs a post-order traversal of the tree.
// Time complexity: O(n), where n is the number of nodes in the tree.
void postorder_traversal(TreeNode *root) {
    if (root != NULL) {
        postorder_traversal(root->left);  // Visit the left subtree
        postorder_traversal(root->right); // Visit the right subtree
        printf("%d -> ", root->data);     // Visit the root
    }
}

// 9. Free Tree: O(n)
// This function frees all the memory allocated for the binary tree.
// Time complexity: O(n), where n is the number of nodes in the tree.
void free_tree(TreeNode *root) {
    if (root != NULL) {
        free_tree(root->left);    // Free the left subtree
        free_tree(root->right);   // Free the right subtree
        free(root);               // Free the root
    }
}

// --- Exercise ---
// Problem: Given a binary tree, find the maximum element.
// For simplicity, assume the tree is a binary search tree.
void exercise_solution() {
    // Create a sample tree
    TreeNode *root = NULL;
    root = insert(root, 15);
    root = insert(root, 10);
    root = insert(root, 25);
    root = insert(root, 8);
    root = insert(root, 12);
    root = insert(root, 20);
    root = insert(root, 30);

    // Find the maximum element in the tree
    TreeNode *max_node = root;
    while (max_node->right != NULL) {
        max_node = max_node->right;
    }

    // Output the result
    printf("The maximum element in the binary tree is: %d\n", max_node->data);

    // Free the tree memory
    free_tree(root);
}

// --- Big O Summary ---
// 1. Create Node: O(1) - Creating a node takes constant time.
// 2. Insert Operation: O(log n) on average, O(n) in the worst case (unbalanced).
// 3. Find Operation: O(log n) on average, O(n) in the worst case (unbalanced).
// 4. Delete Operation: O(log n) on average, O(n) in the worst case (unbalanced).
// 5. Find Minimum: O(log n) on average, O(n) in the worst case (unbalanced).
// 6. Inorder Traversal: O(n) - Traversing the tree takes linear time.
// 7. Preorder Traversal: O(n) - Traversing the tree takes linear time.
// 8. Postorder Traversal: O(n) - Traversing the tree takes linear time.
// 9. Free Tree: O(n) - Freeing each node takes linear time.
