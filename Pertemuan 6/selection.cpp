#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Masukkan jumlah elemen data: ";
    cin >> n;

    int data[n];
    cout << "Masukkan elemen-elemen data: ";
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }

    // TODO : Selection Sort dari terbesar hingga terkecil
    for(int i = 0; i < n; i++){ // mengatur seberapa banyak penyimpanan
        int maxIndex = i; // tempat penyimpanan sementara
        for(int j = i + 1; j < n; j++){
            if(data[j] > data[maxIndex]){
                maxIndex = j;
            }
        }
       
        int temp = data[i]; // tempat sementara untuk pindah
        data[i] = data[maxIndex];
        data[maxIndex] = temp;
    }
   

    cout << "Data setelah diurutkan dari terbesar hingga terkecil:\n";
    for (int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }
    cout << endl;

    return 0;
}