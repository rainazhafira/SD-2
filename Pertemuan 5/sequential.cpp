#include <iostream>
using namespace std;

int main() {
    int n, key, posisi = -1; // posisi = -1 untuk penanda kalau posisi nya ga ketemu

    cout << "Masukkan jumlah data: ";
    cin >> n; // masukin jumlah data

    int data[n];

    // elemen setiap data nya
    cout << "Masukkan elemen data: " << endl;
    for (int i = 0; i < n; i++) {
        cout << "Data ke-" << i << ": ";
        cin >> data[i];
    }

    cout << "\nMasukkan nilai yang ingin dicari: ";
    cin >> key; // key untuk target

    // TODO : Proses pencarian sequential/linear
    for(int i = 0; i < n; i++){
        if(data[i] == key){
            posisi = i; // simpan posisi ketika ketemu
            break; // kalau posisi nya ketemu
        }
    }

    // Output hasil
    if(posisi != -1)
        cout << "\nData ditemukan di indeks ke- " << posisi << endl;
    else
        cout << "\nData tidak ditemukan " << endl;
    return 0;
}