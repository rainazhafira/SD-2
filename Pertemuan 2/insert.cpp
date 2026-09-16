#include <iostream>
using namespace std;

// Deklarasi sebuah struktur node
struct Node { // bagian dari membuat node 
    int value;
    Node *next;
};

Node *head = NULL; // null karena belum ada linked list 
Node *tail = NULL;

// TODO : Insert di Depan
void insertFirst(int n) {
    Node *newNode = new Node;
    newNode -> value = n;
    newNode -> next =  NULL; // null karena dianggap belum ada

    if(head == NULL){ 
         head = newNode;
         tail = head;
    } else {
        newNode -> next = head;
        head = newNode;
    }
}

// TODO : Insert di belakang
void insertLast(int n) {
    Node *newNode = new Node;
    newNode -> value = n; // menunjukkan seberapa besar value
    newNode -> next = NULL;

    if(head == 0){
        head = newNode; // head tidak menunjuk apa-apa
        tail = head;
    } else {
        tail -> next = newNode;
        tail = newNode;
    }
}

// TODO : Insert setelah nilai tertentu
void insertAfter(int n, int check) {

    if(head == NULL){
        cout  << "List kosong, insert didepan dulu \n";
        return;
    }

    Node *newNode = new Node;
    newNode -> value = n; 
    newNode -> next =  NULL;

    Node *p = head;
    while(p != NULL && p -> value != check ){
         p = p -> next;

    }
    if(p == NULL){
        cout << "Node dengan nilai " << check << "tidak ada\n";
        delete newNode; // kalau ga ketemu node baru, hapus aja
    } else{
        newNode -> next = p -> next;
        p -> next = newNode;

        if ( p == tail){
            tail = newNode;
        }
    }

}
  

// Cetak linked list
void printList() {
    Node *temp = head;
    cout << "Isi dari linked list : ";
    while(temp != NULL) {

        cout << temp -> value << " -> ";
        temp = temp -> next;
    }
    cout << "NULL\n";
}

int main () {
    insertFirst(10); // dari depan 
    insertLast(20); // dari belakang 
    insertLast(30);
    insertAfter(25, 20); // menambahkan value 25 setelah 20 
    insertFirst(5);

    printList();
    return 0;
}