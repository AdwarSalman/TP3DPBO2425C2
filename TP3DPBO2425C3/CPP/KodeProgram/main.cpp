#include <iostream>
#include <vector>
#include <string>
#include <memory> 
#include <iomanip>
#include <limits> 
#include <stdexcept>
#include <algorithm> // Untuk std::max

// PENTING: Include semua file .cpp secara berurutan
#include "RiwayatGaji.cpp"      
#include "IKepemimpinan.cpp"
#include "IKehadiran.cpp"
#include "Pegawai.cpp"
#include "PramuBakti.cpp"
#include "TenagaKependidikan.cpp"
#include "Dosen.cpp"

using namespace std;

// Fungsi Global untuk Pemusatan Teks (Menggantikan .center())
// Fungsi ini harus didefinisikan agar program bisa dikompilasi.
string centerString(const string& s, int width, char fill = ' ') {
    if ((int)s.length() >= width) {
        return s;
    }
    int padding = width - s.length();
    int padLeft = padding / 2;
    int padRight = padding - padLeft;
    return string(padLeft, fill) + s + string(padRight, fill);
}

// =================================================================
// KELAS PENGELOLA (ManajemenData) & FUNGSI UTAMA
// =================================================================

class ManajemenData {
private:
    vector<unique_ptr<Pegawai>> daftarPegawai; 

public:
    void tambahPegawai(unique_ptr<Pegawai> pegawai);
    void tampilkanSemuaData() const;
    void muatDataDefault(); 
    void tambahDataBaru();
};

void ManajemenData::tambahPegawai(unique_ptr<Pegawai> pegawai) {
    if (pegawai) {
        cout << "\n[INFO]: Data pegawai '" << pegawai->getNama() << "' berhasil ditambahkan.\n";
        daftarPegawai.push_back(std::move(pegawai));
    }
}

void ManajemenData::tampilkanSemuaData() const {
    if (daftarPegawai.empty()) {
        cout << "\n--- Data pegawai masih kosong. ---\n";
        return;
    }

    cout << "\n" << string(70, '#') << endl;
    // Menggunakan fungsi centerString
    cout << centerString(" LAPORAN DATA PEGAWAI INSTITUSI (ARRAY OF OBJECTS & POLIMORFISME) ", 70, ' ') << endl;
    cout << string(70, '#') << endl;

    for (size_t i = 0; i < daftarPegawai.size(); ++i) {
        cout << "\n<<< " << i + 1 << ". DATA OBJEK - " << daftarPegawai[i]->getNama() << " >>>" << endl;
        daftarPegawai[i]->tampilkanData(); 
        cout << string(40, '=') << endl;
    }
}

void ManajemenData::muatDataDefault() {
    cout << string(50, '=') << endl;
    // Menggunakan fungsi centerString
    cout << centerString("INJEKSI 6 DATA DEFAULT (Fungsi Add Data)", 50, ' ') << endl;
    cout << string(50, '=') << endl;
    
    // (Kode injeksi data sama)
    unique_ptr<Dosen> dosen1 = make_unique<Dosen>("D001", "Dr. Bima Sakti", 9500000, "Jl. Ilmu No. 1", "1980-08-10", 
        "12345678", "Lektor Kepala", "Dekan", 14, "Fakultas Sains");
    dosen1->tambahRiwayatGaji(RiwayatGaji(2024, 15000000, 6.0));
    tambahPegawai(std::move(dosen1)); 

    unique_ptr<Dosen> dosen2 = make_unique<Dosen>("D002", "Siti Nurjanah", 7500000, "Jl. Riset No. 5", "1990-01-20", 
        "87654321", "Asisten Ahli", "", 12, "Fakultas Teknik"); 
    dosen2->tambahRiwayatGaji(RiwayatGaji(2024, 10000000, 5.0));
    tambahPegawai(std::move(dosen2)); 
    
    unique_ptr<TenagaKependidikan> tendik1 = make_unique<TenagaKependidikan>("T001", "Budi Santoso", 6000000, "Jl. Mawar No. 5", "1990-11-15", 
        "Keuangan", "Staf Senior", 10);
    tendik1->tambahRiwayatGaji(RiwayatGaji(2024, 7500000, 4.0));
    tambahPegawai(std::move(tendik1));

    unique_ptr<TenagaKependidikan> tendik2 = make_unique<TenagaKependidikan>("T002", "Rina Marlina", 4800000, "Jl. Admin No. 2", "1992-07-25", 
        "Akademik", "Staf Junior", 0);
    tendik2->tambahRiwayatGaji(RiwayatGaji(2024, 6000000, 3.5));
    tambahPegawai(std::move(tendik2));

    unique_ptr<PramuBakti> pramu1 = make_unique<PramuBakti>("P001", "Siti Aisyah", 3800000, "Jl. Kebersihan No. 2", "1995-02-05", 
        "Area Perpustakaan", 600000, "Pagi");
    pramu1->tambahRiwayatGaji(RiwayatGaji(2024, 4500000, 3.0));
    tambahPegawai(std::move(pramu1));
    
    unique_ptr<PramuBakti> pramu2 = make_unique<PramuBakti>("P002", "Joko Susilo", 3500000, "Jl. Pelayanan No. 8", "1988-06-12", 
        "Area Toilet Utama", 700000, "Siang");
    pramu2->tambahRiwayatGaji(RiwayatGaji(2024, 4200000, 2.5));
    tambahPegawai(std::move(pramu2));
}

void ManajemenData::tambahDataBaru() {
    // (Isi method tambahDataBaru sama)
    cout << "\n--- PILIH TIPE PEGAWAI BARU ---\n";
    cout << "1. Dosen\n2. Tenaga Kependidikan\n3. Pramu Bakti\n";
    
    string inputStr;
    int pilihan;
    
    cout << "Pilih tipe (1/2/3): ";
    getline(cin, inputStr);
    try {
        pilihan = stoi(inputStr);
    } catch (...) {
        cout << "[ERROR] Input tidak valid.\n";
        return;
    }

    // Input Dasar
    string id, nama, alamat, tglLahir;
    double gaji;
    
    cout << "ID Pegawai: "; getline(cin, id);
    cout << "Nama Lengkap: "; getline(cin, nama);
    cout << "Alamat: "; getline(cin, alamat);
    cout << "Tanggal Lahir (YYYY-MM-DD): "; getline(cin, tglLahir);
    cout << "Gaji Pokok: "; 
    if (!(cin >> gaji)) { cout << "[ERROR] Input gaji tidak valid.\n"; cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); return; }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    unique_ptr<Pegawai> pegawaiBaru = nullptr;

    try {
        if (pilihan == 1) {
            string nidn, jabAkademik, jabStruktural, unitKerja;
            int sks;
            cout << "NIDN: "; getline(cin, nidn);
            cout << "Jabatan Akademik: "; getline(cin, jabAkademik);
            cout << "Jabatan Struktural: "; getline(cin, jabStruktural);
            cout << "Jumlah SKS Mengajar: "; 
            if (!(cin >> sks)) throw runtime_error("Input SKS invalid.");
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Unit Kerja/Fakultas: "; getline(cin, unitKerja);
            
            pegawaiBaru = make_unique<Dosen>(id, nama, gaji, alamat, tglLahir, nidn, jabAkademik, jabStruktural, sks, unitKerja);

        } else if (pilihan == 2) {
            string dept, posisi;
            int jamLembur;
            cout << "Departemen: "; getline(cin, dept);
            cout << "Posisi: "; getline(cin, posisi);
            cout << "Jam Lembur: "; 
            if (!(cin >> jamLembur)) throw runtime_error("Input jam lembur invalid.");
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            
            pegawaiBaru = make_unique<TenagaKependidikan>(id, nama, gaji, alamat, tglLahir, dept, posisi, jamLembur);

        } else if (pilihan == 3) {
            string area, shift;
            double tunjangan;
            cout << "Area Tugas: "; getline(cin, area);
            cout << "Tunjangan Risiko: "; 
            if (!(cin >> tunjangan)) throw runtime_error("Input tunjangan invalid.");
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Jam Shift: "; getline(cin, shift);
            
            pegawaiBaru = make_unique<PramuBakti>(id, nama, gaji, alamat, tglLahir, area, tunjangan, shift);
            
        } else {
            cout << "[ERROR] Pilihan tipe pegawai tidak valid.\n";
            return;
        }

        // Input Riwayat Gaji (Composition)
        int tahun; double gajiRiwayat, kenaikan;
        cout << "\n--- Input Riwayat Gaji (Composition) ---\n";
        cout << "Tahun Riwayat: "; 
        if (!(cin >> tahun)) throw runtime_error("Input tahun invalid.");
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Gaji Riwayat: "; 
        if (!(cin >> gajiRiwayat)) throw runtime_error("Input gaji riwayat invalid.");
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Kenaikan (%): "; 
        if (!(cin >> kenaikan)) throw runtime_error("Input kenaikan invalid.");
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        pegawaiBaru->tambahRiwayatGaji(RiwayatGaji(tahun, gajiRiwayat, kenaikan));
        
        tambahPegawai(std::move(pegawaiBaru));

    } catch (const exception& e) {
        cout << "[ERROR] Gagal menambahkan data: " << e.what() << endl;
    }
}


void mainMenu() {
    ManajemenData manajemen;
    manajemen.muatDataDefault();

    string inputStr;
    int pilihan;

    do {
        cout << "\n\n" << string(50, '=') << endl;
        // Menggunakan fungsi centerString
        cout << centerString(" SISTEM MANAJEMEN PEGAWAI (C++) ", 50, '-') << endl;
        cout << string(50, '=') << endl;
        cout << "1. Tampilkan Semua Data Pegawai\n";
        cout << "2. Tambah Data Pegawai Baru (Interaktif)\n";
        cout << "3. Keluar Program\n";
        cout << string(50, '=') << endl;
        
        cout << "Masukkan pilihan (1-3): ";
        getline(cin, inputStr);
        try {
            pilihan = stoi(inputStr);
        } catch (...) {
            pilihan = 0;
        }

        switch (pilihan) {
            case 1:
                manajemen.tampilkanSemuaData();
                break;
            case 2:
                manajemen.tambahDataBaru();
                break;
            case 3:
                cout << "\nTerima kasih, program berakhir. Sampai jumpa!\n";
                break;
            default:
                cout << "\nPilihan tidak valid. Silakan coba lagi.\n";
                break;
        }
    } while (pilihan != 3);
}

int main() {
    mainMenu();
    return 0;
}