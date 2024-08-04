#include <iostream>
using namespace std;

// Mendefinisikan Node untuk Binary Tree
struct Node {
    int data;
    Node* left;
    Node* right;

    // Konstruktor untuk mempermudah pembuatan node
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Fungsi untuk menambahkan node ke Binary Search Tree
Node* insert(Node* root, int value) {
    // Jika tree kosong, buat node baru
    if (root == nullptr) {
        return new Node(value);
    }

    // Jika nilai lebih kecil dari root, tambahkan ke subtree kiri
    if (value < root->data) {
        root->left = insert(root->left, value);
    }
    // Jika nilai lebih besar, tambahkan ke subtree kanan
    else {
        root->right = insert(root->right, value);
    }

    return root;
}

// Fungsi untuk mencetak inorder traversal dari Binary Tree
void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main() {
    Node* root = nullptr;

    // Menambahkan elemen ke Binary Search Tree
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // Mencetak elemen dalam urutan inorder
    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;

    return 0;
}
