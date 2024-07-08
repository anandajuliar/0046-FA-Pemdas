#include <iostream> 
using namespace std;

// Kelas Abstrak MasukUniversitas
class MasukUniversitas {
protected: // isi access modifier disini
    int uangPendaftaran;
    int uangSemesterPertama;
    int uangBangunan;
    int totalBiaya;

public:
    MasukUniversitas() {
    uangPendaftaran = 0; 
    uangSemesterPertama = 0;
    uangBangunan = 0;
    totalBiaya = 0;
    }

    // isi disini dengan fungsi virtual yang dibutuhkan
    virtual void namaJalurMasuk() { return; }
    virtual void hitungTotalBiaya() { return; }
    virtual void tampilkanTotalBiaya() { return; }
    virtual void input() { return; }
    
    // Getter dan Setter
    void setUangPendaftaran(int nilai) { 
        this->uangPendaftaran = nilai;
    }
    float getUangPendaftaran() { 
        return uangPendaftaran;
    }

    void setUangSemesterPertama(int nilai) { 
        this->uangSemesterPertama = nilai;
    }
    float getUangSemesterPertama() { 
        return uangSemesterPertama;
    }

    void setUangBangunan(int nilai) { 
        this->uangBangunan = nilai;
    }
    float getUangBangunan() { 
        return uangBangunan;
    }  
      
    void setTotalBiaya(int nilai) { 
        this->totalBiaya = nilai;
    }
    float getTotalBiaya() { 
        return totalBiaya;
    }
};

class SNBT : public MasukUniversitas {
public:
    void namaJalurMasuk() {
        cout << "SNBT" << endl; // Implementasi fungsi namajalurmasuk() di kelas snbt
    }
 
    void input() {
        cout << "Masukkan uang pendaftaran: ";
        cin >> uangPendaftaran;
        cout << "Masukkan uang semester pertama: ";
        cin >> uangSemesterPertama;
        cout << "Masukkan uang bangunan: ";
        cin >> uangBangunan;
    }

    void hitungTotalBiaya() {
        totalBiaya = uangPendaftaran + uangSemesterPertama + uangBangunan;
    }

    void tampilkanTotalBiaya() {
        cout << "Total Biaya (SNBT): " << totalBiaya << endl;
        if (totalBiaya > 10000000) {
            cout << "Kategori: Mahal" << endl;
        }
        else if (totalBiaya > 5000000) {
            cout << "Kategori: Sedang" << endl;
        }
        else {
            cout << "Kategori: Murah" << endl;
        }
    }
};

class SNBP : public MasukUniversitas {
public:
    void namaJalurMasuk() { // Implementasi fungsi namajalurmasuk() di kelas snbp
        cout << "SNBP" << endl; 
    }

    void input() override {
        cout << "Masukkan uang pendaftaran: ";
        cin >> uangPendaftaran;
        cout << "Masukkan uang semester pertama: ";
        cin >> uangSemesterPertama;
    }

    void hitungTotalBiaya() override {
        totalBiaya = uangPendaftaran + uangSemesterPertama;
    }

    void tampilkanTotalBiaya() override {
        cout << "Total Biaya (SNBP): " << totalBiaya << endl;
        if (totalBiaya > 10000000) {
            cout << "Kategori: Mahal" << endl;
        }
        else if (totalBiaya > 5000000) {
            cout << "Kategori: Sedang" << endl;
        }
        else {
            cout << "Kategori: Murah" << endl;
        }
    }
};

int main() {
    cout << "Selamat datang di sistem perhitungan biaya masuk universitas" << endl;
    cout << "Jalur masuk:" << endl;
    cout << "1. SNBT" << endl;
    cout << "2. SNBP" << endl;
    int pilihan;
    cout << "masukkan pilihan: ";
    cin >> pilihan;

    MasukUniversitas* jalurMasuk = nullptr;

    if (pilihan == 1) {
        jalurMasuk = new SNBT();
    }
    else if (pilihan == 2) {
        jalurMasuk = new SNBP();
    }
    else {
        cout << "pilihan gak ada" << endl;
        return 1;
    }

    jalurMasuk->input(); // Memanggil fungsi input() melalui pointer jalurmasuk
    jalurMasuk->hitungTotalBiaya(); // Memanggil fungsi hitungtotalbiaya() melalui pointer jalurmasuk
    jalurMasuk->tampilkanTotalBiaya(); // Memanggil fungsi tampilkantotalbiaya() melalui pointer jalurmasuk1
    return 0;
}

