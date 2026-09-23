#include <iostream>
using namespace std;

#define MAX 5 // untuk buat array dengan kapasitas 5 
int stack[MAX]; 
int top = -1; // awalnya kosong 

// TODO : Operasi Push
void push (int value) {
    if(top == MAX -1) { // pengkondisian kalo udah penuh
        cout << "Stack penuh !!\n"; // kalo stack nya penuh gabisa nambah
    } else { // kalo belum penuh
        top++; // nambah 1
        stack[top] = value; //  value nya 50
        cout << value << " ditambahkan dalam stack\n";
    }
}

// TODO : Operasi Pop
void pop (){
// pop = hapus data dari atas

   if(top == -1) { // stack masih kosong
    cout << "stack kosong !!\n";
   } else {
    cout << "\n" << stack[top] << " dihapus dari stack\n";
    top--;
   }
}
// TODO : Nampilin Stack
void display() {
    if(top == -1) {
        cout << "stack kosong !!\n";
    } else {
        cout << "\n Isi stack : \n";
        for(int i = top; i >= 0; i--) {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
}

int main (){
    push(50);
    push(40);
    push(30);
    push(20);
    push(10);

    display();
    pop();
    display;

    return 0;
}