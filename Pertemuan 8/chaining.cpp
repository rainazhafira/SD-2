#include <iostream>
#include <vector>
#include <list>
using namespace std;

class HashTableChaining {
private: // nandain variabel bawahnya itu cuma bisa di akses sama class nya
    int size; // simpan jumlah ukuran hash table
    vector<list<int>> table; // untuk bikin array dinamis nya

    // TODO 1: Buat hash function
    int hashFunction(int key) {
        // return rumus hashing
        return key % size; // guna return untuk ngebagi hasil nya biar selalu ada di rentang size nya
    }

public: // bisa di panggil secara global
    HashTableChaining(int s) { 
        size = s; // nentuin ukuran
        table.resize(size); // untuk ngatur jumlah slot kita oleh vector
    }

    // TODO 2: Buat fungsi insert untuk menyimpan key ke hash table
    void insert(int key) {
        // 1. Hitung index pakai hashFunction
        int index = hashFunction(key); // hashfunction untuk ngebantu nentuin nomor kursi nya
        // 2. Tambahkan angka ke list pada index tersebut
        table[index].push_back(key);
    }

    // TODO 3: Tampilkan isi hash table
    void display() { // cetak
        for (int i = 0; i < size; i++) {
            cout << i << ": ";
            // tampilkan semua elemen di slot ini
            for (int val : table[i]) {
                cout << val << " -> "; // untuk ngulang dari 0
            }
            cout << "NULL\n";
        }
    }
};

int main() {
    int size, n, value;

    cout << "Masukkan ukuran hash table: ";
    cin >> size;

    HashTableChaining ht(size);

    cout << "Berapa banyak angka yang ingin dimasukkan? ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Input angka ke-" << i + 1 << ": ";
        cin >> value;
        ht.insert(value);
    }

    cout << "\n=== HASH TABLE (CHAINING) ===\n";
    ht.display();

    return 0;
}