#include "Pegawai.cpp" 

#ifndef DOSEN_CPP
#define DOSEN_CPP

class Dosen : public Pegawai, public IKepemimpinan, public IKehadiran {
private:
    std::string nidn;
    std::string jabatanAkademik;
    std::string jabatanStruktural;
    int jumlahSKS;
    std::string unitKerja;

public:
    Dosen(const std::string& id, const std::string& nama, double gaji, const std::string& alamat, const std::string& tglLahir,
          const std::string& nidn, const std::string& jabAkademik, const std::string& jabStruktural, int sks, const std::string& unitKerja)
        : Pegawai(id, nama, gaji, alamat, tglLahir), nidn(nidn), jabatanAkademik(jabAkademik),
          jabatanStruktural(jabStruktural), jumlahSKS(sks), unitKerja(unitKerja) {}

    // GETTER/SETTER Spesifik
    std::string getJabatanStruktural() const { return jabatanStruktural; }
    void setJabatanStruktural(const std::string& jab) { this->jabatanStruktural = jab; }

    // Implementasi Polimorfik wajib
    void tampilkanData() const override {
        tampilkanDasar();
        std::cout << "Jabatan: Dosen\n";
        std::cout << "NIDN: " << nidn << std::endl;
        std::cout << "Jabatan Akademik: " << jabatanAkademik << std::endl;
        std::cout << "Jumlah SKS Mengajar: " << jumlahSKS << std::endl;
        std::cout << "Jabatan Struktural: " << jabatanStruktural << std::endl; 
        std::cout << "Unit Kerja Struktural: " << getUnitKerja() << std::endl; 
        
        std::cout << "Keterangan Struktural: " << ambilKeputusanStrategis() << std::endl;
        std::cout << "Total Gaji + Tunjangan: " << (gajiPokok + hitungTunjangan()) << std::endl;
        std::cout << "Jam Kerja Bulan Ini: " << hitungJamKerja() << " jam\n";
    }

    double hitungTunjangan() const override {
        double tunjanganSKS = jumlahSKS * 100000; 
        double tunjanganJabatan = jabatanStruktural.empty() ? 0 : 3000000;
        return tunjanganSKS + tunjanganJabatan;
    }

    // Implementasi wajib dari IKepemimpinan (Logic Hybrid Inheritance)
    std::string ambilKeputusanStrategis() const override {
        if (!jabatanStruktural.empty()) {
            return "Mengambil keputusan strategis untuk " + getUnitKerja();
        } else {
            return "Tidak memiliki jabatan struktural aktif.";
        }
    }
    std::string getUnitKerja() const override { return unitKerja; }

    // Implementasi wajib dari IKehadiran
    double hitungJamKerja() const override { return jumlahSKS * 1.5 * 16; }
    std::string getBulanKehadiran() const override { return "Oktober"; }
};

#endif // DOSEN_CPP