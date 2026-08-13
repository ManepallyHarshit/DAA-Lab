#include <iostream>

using namespace std;

struct Node {
  int data;
  Node* left;
  Node* right;
};

Node* createNode(int val) {
  Node* newNode = new Node();
  newNode->data = val;
  newNode->left = nullptr;
  newNode->right = nullptr;
  return newNode;
}

Node* insert(Node* root, int key) {
  if (root == nullptr) return createNode(key);
  if (key < root->data)
    root->left = insert(root->left, key);
  else if (key > root->data)
    root->right = insert(root->right, key);
  return root;
}

Node* findMin(Node* root) {
  while (root && root->left != nullptr)
    root = root->left;
  return root;
}

Node* deleteNode(Node* root, int key) {
  if (root == nullptr) return root;

  if (key < root->data)
    root->left = deleteNode(root->left, key);
  else if (key > root->data)
    root->right = deleteNode(root->right, key);
  else {
    if (root->left == nullptr) {
      Node* temp = root->right;
      delete root;
      return temp;
    } else if (root->right == nullptr) {
      Node* temp = root->left;
      delete root;
      return temp;
    }

    Node* temp = findMin(root->right);
    root->data = temp->data;
    root->right = deleteNode(root->right, temp->data);
  }
  return root;
}

void inorder(Node* root) {
  if (root != nullptr) {
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
  }
}

void preorder(Node* root) {
  if (root != nullptr) {
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
  }
}

void postorder(Node* root) {
  if (root != nullptr) {
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
  }
}

int main() {
  Node* root = nullptr;
  int choice, val;

  do {
    cout << "\n--- Binary Search Tree Menu ---\n";
    cout << "1. Insert\n";
    cout << "2. Delete\n";
    cout << "3. Inorder Traversal\n";
    cout << "4. Preorder Traversal\n";
    cout << "5. Postorder Traversal\n";
    cout << "6. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
      case 1:
        cout << "Enter value to insert: ";
        cin >> val;
        root = insert(root, val);
        cout << val << " inserted successfully.\n";
        break;
      case 2:
        cout << "Enter value to delete: ";
        cin >> val;
        root = deleteNode(root, val);
        cout << "Deletion complete.\n";
        break;
      case 3:
        cout << "Inorder: ";
        inorder(root);
        cout << "\n";
        break;
      case 4:
        cout << "Preorder: ";
        preorder(root);
        cout << "\n";
        break;
      case 5:
        cout << "Postorder: ";
        postorder(root);
        cout << "\n";
        break;
      case 6:
        cout << "Exiting...\n";
        break;
      default:
        cout << "Invalid choice! Please try again.\n";
    }
  } while (choice != 6);

  return 0;
}