// Pegawai.cpp
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <stdexcept>

// Include dependensi dasar dan Interfaces
#include "RiwayatGaji.cpp" 
#include "IKepemimpinan.cpp"  
#include "IKehadiran.cpp" 

#ifndef PEGAWAI_CPP 
#define PEGAWAI_CPP

class Pegawai {
protected:
    std::string idPegawai;
    std::string nama;
    double gajiPokok;
    std::string alamatLengkap;
    std::string tanggalLahirString;

private:
    std::vector<RiwayatGaji> riwayatGaji; // Composition

public:
    // Konstruktor Dasar
    Pegawai(const std::string& id, const std::string& nama, double gaji, const std::string& alamat, const std::string& tglLahir);

    virtual ~Pegawai() = default; 

    // --- GETTER ---
    std::string getNama() const { return nama; }
    double getGajiPokok() const { return gajiPokok; }
    std::string getAlamatLengkap() const { return alamatLengkap; }
    std::string getTanggalLahirString() const { return tanggalLahirString; }
    const std::vector<RiwayatGaji>& getRiwayatGaji() const { return riwayatGaji; }

    // --- SETTER ---
    void setNama(const std::string& nama);
    void setGajiPokok(double gajiPokok);
    void setAlamatLengkap(const std::string& alamat);

    // Method Composition
    void tambahRiwayatGaji(const RiwayatGaji& riwayat);

    // Pure virtual functions (Polimorfisme)
    virtual void tampilkanData() const = 0;
    virtual double hitungTunjangan() const = 0;

protected:
    void tampilkanDasar() const;
};

// =================================================================
// IMPLEMENTASI METHOD DARI PEGAWAI
// =================================================================

// 1. Konstruktor
Pegawai::Pegawai(const std::string& id, const std::string& nama, double gaji, const std::string& alamat, const std::string& tglLahir)
    : idPegawai(id), nama(nama), gajiPokok(gaji), alamatLengkap(alamat), tanggalLahirString(tglLahir) {}

// 2. SETTER (Implementasi penuh Enkapsulasi)
void Pegawai::setNama(const std::string& nama) { 
    if (nama.empty()) throw std::invalid_argument("Nama tidak boleh kosong.");
    this->nama = nama; 
}
void Pegawai::setGajiPokok(double gajiPokok) { 
    if (gajiPokok < 3000000) throw std::invalid_argument("Gaji pokok minimal 3 juta.");
    this->gajiPokok = gajiPokok; 
}
void Pegawai::setAlamatLengkap(const std::string& alamat) { 
    this->alamatLengkap = alamat; 
}

// 3. Method Composition
void Pegawai::tambahRiwayatGaji(const RiwayatGaji& riwayat) {
    riwayatGaji.push_back(riwayat);
}

// 4. Method Tampil Dasar
void Pegawai::tampilkanDasar() const {
    std::cout << std::string(40, '=') << std::endl;
    std::cout << "ID Pegawai: " << idPegawai << " | Nama: " << nama << std::endl;
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Gaji Pokok: " << gajiPokok << std::endl;
    std::cout << "Alamat Lengkap: " << alamatLengkap << std::endl;
    std::cout << "Tanggal Lahir: " << tanggalLahirString << std::endl;

    std::cout << "--- Riwayat Gaji (Composition) ---\n";
    for (const auto& riwayat : riwayatGaji) {
        riwayat.tampilkanData();
    }
    std::cout << std::string(40, '-') << std::endl;
}

#endif // PEGAWAI_CPP