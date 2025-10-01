#include "Pegawai.cpp" 

#ifndef TENAGAKEPENDIDIKAN_CPP
#define TENAGAKEPENDIDIKAN_CPP

class TenagaKependidikan : public Pegawai, public IKehadiran {
private:
    std::string departemen;
    std::string posisi;
    int jamLembur;

public:
    TenagaKependidikan(const std::string& id, const std::string& nama, double gaji, const std::string& alamat, const std::string& tglLahir,
                       const std::string& dept, const std::string& posisi, int jamLembur)
        : Pegawai(id, nama, gaji, alamat, tglLahir), departemen(dept), posisi(posisi), jamLembur(jamLembur) {}

    // GETTER/SETTER Spesifik
    int getJamLembur() const { return jamLembur; }

    // Implementasi Polimorfik wajib
    void tampilkanData() const override {
        tampilkanDasar();
        std::cout << "Jabatan: Tenaga Kependidikan\n";
        std::cout << "Departemen: " << departemen << std::endl;
        std::cout << "Posisi: " << posisi << std::endl;
        std::cout << "Jam Lembur: " << jamLembur << " jam\n";

        std::cout << "Total Gaji + Tunjangan: " << (gajiPokok + hitungTunjangan()) << std::endl;
        std::cout << "Jam Kerja Bulan Ini: " << hitungJamKerja() << " jam\n";
    }

    double hitungTunjangan() const override {
        double tunjanganPosisi = 500000; 
        double tunjanganLembur = jamLembur * 50000; 
        return tunjanganPosisi + tunjanganLembur;
    }

    // Implementasi wajib dari IKehadiran
    double hitungJamKerja() const override { return 160 + jamLembur; }
    std::string getBulanKehadiran() const override { return "Oktober"; }
};

#endif // TENAGAKEPENDIDIKAN_CPP