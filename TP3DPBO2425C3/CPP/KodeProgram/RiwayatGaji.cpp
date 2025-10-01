#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <string>

#ifndef RIWAYATGAJI_CPP 
#define RIWAYATGAJI_CPP

class RiwayatGaji {
private:
    int tahun;
    double gajiBulan;
    double kenaikan;

public:
    RiwayatGaji(int tahun, double gajiBulan, double kenaikan) : 
        tahun(tahun), gajiBulan(gajiBulan), kenaikan(kenaikan) {}

    // GETTER
    int getTahun() const { return tahun; }
    double getGajiBulan() const { return gajiBulan; }
    double getKenaikan() const { return kenaikan; }

    // SETTER (Enkapsulasi & Validasi)
    void setGajiBulan(double gajiBulan) {
        if (gajiBulan < 0) throw std::invalid_argument("Gaji tidak boleh negatif.");
        this->gajiBulan = gajiBulan;
    }
    
    void tampilkanData() const {
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "    - Tahun: " << tahun 
                  << ", Gaji: " << gajiBulan 
                  << ", Kenaikan: " << kenaikan << "%\n";
    }
};

#endif // RIWAYATGAJI_CPP