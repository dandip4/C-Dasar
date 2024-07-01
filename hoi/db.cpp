#include <iostream>
#include <string>
using namespace std;
class Node {
public:
    string data;
    Node* next;

    Node(string data) {
        this->data = data;
        this->next = nullptr;
    }
};
class LinkedList {
private:
    Node* kepala;
public:
    LinkedList() {
        kepala = nullptr;
    }
    bool apakah_prima(int n) {
        if (n <= 1) return false;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) return false;
        }
        return true;
    }
    void tambahNode(string data) {
        Node* newNode = new Node(data);
        newNode->next = kepala;
        kepala = newNode;
    }
    void buatLinkedList(string npm) {
        for (int num = 30; num >= 1; num--) {
            if (to_string(num).find('3') != string::npos) tambahNode(npm);
            else if (apakah_prima(num)) tambahNode(to_string(num));
        }
    }
    void tampilkan() {
        Node* sekarang = kepala;
        while (sekarang != nullptr) {
            cout << sekarang->data << " -> ";
            sekarang = sekarang->next;
        }
        cout << "nullptr" << endl;
    }
};
int main() {
    string npm = "065123199";
    LinkedList linkedList;
    linkedList.buatLinkedList(npm);
    cout << "Linked List:" << endl;
    linkedList.tampilkan();
    return 0;
}
