#include <iostream>
using namespace std;

struct Node {
    int value;
    Node *next;
};

Node *head = NULL;
Node *tail = NULL;

void insertFirst(int n) {
    Node *newNode = new Node;
    newNode->value = n;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        tail = head;
    } else {
        newNode->next = head;
        head = newNode;
    }
}

void insertLast(int n) {
    Node *newNode = new Node;
    newNode->value = n;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        tail = head;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

void insertAfter(int n, int check) {
    if (head == NULL) {
        cout << "listnya kosong, tambah di belakang atau didepan dulu\n";
        return;
    }

    Node *p = head;
    while (p != NULL && p->value != check) {
        p = p->next;
    }

    if (p == NULL) {
        cout << "node dengan nilai " << check << " tidak ada\n";
        return;
    }

    Node *newNode = new Node;
    newNode->value = n;
    newNode->next = p->next;
    p->next = newNode;

    if (p == tail) {
        tail = newNode;
    }
}

void deleteFirst() {
    if (head == NULL) {
        cout << "listnya kosong\n";
        return;
    }
    Node *temp = head;
    head = head->next;
    if (head == NULL) tail = NULL;
    delete temp;
}

void deleteLast() {
    if (head == NULL) {
        cout << "listnya kosong\n";
        return;
    }
    if (head == tail) {
        delete head;
        head = tail = NULL;
        return;
    }
    Node *p = head;
    while (p->next != tail) {
        p = p->next;
    }
    delete tail;
    tail = p;
    tail->next = NULL;
}

void deleteByValue(int value) {
    if (head == NULL) {
        cout << "listnya kosong\n";
        return;
    }

    if (head->value == value) {
        deleteFirst();
        return;
    }

    if (tail->value == value) {
        deleteLast();
        return;
    }

    Node *p = head;
    while (p->next != NULL && p->next->value != value) {
        p = p->next;
    }

    if (p->next == NULL) {
        cout << "node dengan nilai " << value << " tidak ada\n";
    } else {
        Node *temp = p->next;
        p->next = temp->next;
        delete temp;
    }
}

void printList() {
    Node *temp = head;
    cout << "isi Linked List: ";
    while (temp != NULL) {
        cout << temp->value << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

void tampilkanMenu() {
    cout << "Menu Single Linked List\n";
    cout << "1. tambah di depan\n";
    cout << "2. tambah di belakang\n";
    cout << "3. tambah setelah nilai tertentu\n";
    cout << "4. hapus berdasarkan nilai\n";
    cout << "5. tampilkan linked list\n";
    cout << "0. keluar\n";
    cout << "pilihan: ";
}

int main() {
    int pilihan = -1; 

    while (pilihan != 0) {
        tampilkanMenu();
        cin >> pilihan;

        if (pilihan == 1) {
            int nilai;
            cout << "masukkan nilai: ";
            cin >> nilai;
            insertFirst(nilai);
            printList();

        } else if (pilihan == 2) {
            int nilai;
            cout << "masukkan nilai: ";
            cin >> nilai;
            insertLast(nilai);
            printList();

        } else if (pilihan == 3) {
            int nilaiBaru, nilaiCari;
            cout << "masukkan nilai baru: ";
            cin >> nilaiBaru;
            cout << "masukkan nilai yang mau dicari: ";
            cin >> nilaiCari;
            insertAfter(nilaiBaru, nilaiCari);
            printList();

        } else if (pilihan == 4) {
            int nilaiHapus;
            cout << "masukkan nilai yang mau dihapus: ";
            cin >> nilaiHapus;
            deleteByValue(nilaiHapus);
            printList();

        } else if (pilihan == 5) {
            printList();

        } else if (pilihan == 0) {
            cout << "program selesai\n";

        } else {
            cout << "pilihannya tidak ada\n";
        }

        cout << "\n";
    }

    return 0;
}
