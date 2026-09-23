#include <iostream>
using namespace std;

#define MAX 6 // bikin array di queue sampai 6
int queue[MAX]; // sama int queue 6
int front = -1, rear = -1; // awalnya kosong makanya -1

// TODO : Enqueue
void enqueue( int value ) {
    if (rear == MAX - 1){
        cout << "Queue sudah penuh !!\n"; // pengkondisian
    } else {
        if(front == -1) front = 0; // kalo frontnya masih -1 maka jadi 0
        rear++; // bertambah dengan sesuai jumlah slotnya, tapi front tetap 0
        queue[rear] = value;
        cout << value << " masuk kedalam queue\n";
    }
}

// TODO : Dequeue
void dequeue() {
    if(front == -1 || front > rear) {
        cout << " Queue kosong\n";
    } else {
        cout << queue[front] << " Keluar dari queue\n";
        front++; // frontnya nambah dan pindah ke indeks  lainnya
    }
}

// TODO : Nampilin isi queue
void display() {
    if(front == -1 || front > rear) {
        cout << " Queue kosong\n";
    } else {
        cout << "Isi dari queue : ";
        for(int i = front; i <= rear; i++){
            cout << queue[i] << " ";
        }
        cout << endl;
    }
}

int main () {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);

    display();

    enqueue(6);
    display();

    dequeue();
    display();

    return 0;
}