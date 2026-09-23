#include <iostream>
#include <string>

using namespace std;

#define MAX 100

char stack[MAX];
int top = -1;

// TODO : Menambahkan karakter ke stack
void push(char value) {
    if(top == MAX-1){
        cout << " stack penuh!! \n";
    } else {
        top++; 
        stack[top] = value;
        cout << value << " ditambahkan dalam stack\n";
    }
}
// TODO : Mengambil karakter paling atas
char pop() {
        if (top == -1){
         cout << " stack kosong!! \n";
    } else {
        char temp = stack[top];
        cout << "\n" << stack[top] << " dihapus dari Stack\n"; 
        top--;
        return temp;
    }

}

int main() {

    string kata, hasil;

    cout << "Masukkan sebuah kata: ";
    cin >> kata;

    // TODO : Memasukkan setiap karakter ke stack
      for (int i = 0; i < kata.length(); i++) {
        push(kata[i]);
    }

    // TODO Mengeluarkan karakter dari stack
      while (top != -1) {
        hasil += pop();
    }

    cout << " kata : " << kata << endl;
    cout << " hasil : " << hasil << endl;
    
    cout << endl;

    return 0;
}