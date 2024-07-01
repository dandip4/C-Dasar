#include <iostream>
#include <cmath>

using namespace std;

// Struktur node untuk linked list
struct Node {
    int data;
    Node* next;
};

// Fungsi untuk mengecek apakah suatu bilangan prima
bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

// Fungsi untuk menambahkan node baru pada akhir linked list
void append(Node** head_ref, int new_data) {
    Node* new_node = new Node();
    Node* last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
}

// Fungsi untuk menampilkan linked list
void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;

    // Menambahkan bilangan prima dari 1 hingga 30 ke dalam linked list
    for (int i = 1; i <= 30; i++) {
        if (isPrime(i)) {
            // Jika bilangan memiliki angka 3, tambahkan NPM pribadi terlebih dahulu
            if (to_string(i).find('3') != string::npos) {
                append(&head, 18101162); // NPM pribadi saya
            }
            append(&head, i);
        }
    }

    // Menampilkan linked list
    display(head);

    return 0;
}
