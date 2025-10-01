#include "Pegawai.cpp" 

#ifndef PRAMUBAKTI_CPP
#define PRAMUBAKTI_CPP

class PramuBakti : public Pegawai, public IKehadiran {
private:
    std::string areaTugas;
    double tunjanganRisiko;
    std::string jamKerjaShift;

public:
    PramuBakti(const std::string& id, const std::string& nama, double gaji, const std::string& alamat, const std::string& tglLahir,
               const std::string& area, double tunjangan, const std::string& shift)
        : Pegawai(id, nama, gaji, alamat, tglLahir), areaTugas(area), tunjanganRisiko(tunjangan), jamKerjaShift(shift) {}

    // GETTER/SETTER Spesifik
    double getTunjanganRisiko() const { return tunjanganRisiko; }

    // Implementasi Polimorfik wajib
    void tampilkanData() const override {
        tampilkanDasar();
        std::cout << "Jabatan: Pramu Bakti\n";
        std::cout << "Area Tugas: " << areaTugas << std::endl;
        std::cout << "Tunjangan Risiko Dasar: " << tunjanganRisiko << std::endl;
        std::cout << "Jam Shift: " << jamKerjaShift << std::endl;
        
        std::cout << "Total Gaji + Tunjangan: " << (gajiPokok + hitungTunjangan()) << std::endl;
        std::cout << "Jam Kerja Bulan Ini: " << hitungJamKerja() << " jam\n";
    }

    double hitungTunjangan() const override {
        return tunjanganRisiko * 1.5;
    }

    // Implementasi wajib dari IKehadiran
    double hitungJamKerja() const override { return 20 * 8; }
    std::string getBulanKehadiran() const override { return "Oktober"; }
};

#endif // PRAMUBAKTI_CPP