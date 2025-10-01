# main.py

# Import semua kelas dari direktori yang sama
from Pegawai import Pegawai
from RiwayatGaji import RiwayatGaji
from Dosen import Dosen
from TenagaKependidikan import TenagaKependidikan
from PramuBakti import PramuBakti
import time 

class ManajemenData:
    """
    Kelas Pengelola data utama.
    Mengimplementasikan Array of Objects.
    """
    def __init__(self):
        self._daftar_pegawai = []

    @property
    def daftar_pegawai(self):
        return self._daftar_pegawai

    def tambah_pegawai(self, pegawai: Pegawai):
        """Fungsi ADD DATA"""
        self._daftar_pegawai.append(pegawai)
        print(f"[INFO]: Data pegawai '{pegawai.nama}' ({pegawai.id_pegawai}) berhasil ditambahkan.")

    def tampilkan_semua_data(self):
        """Fungsi DISPLAY ALL DATA """
        if not self.daftar_pegawai:
            print("\n--- Data pegawai masih kosong. ---")
            return

        print("\n" + "#"*70)
        print(" LAPORAN DATA PEGAWAI INSTITUSI ".center(70, '#'))
        print("#"*70)
        
        # Iterasi Array of Objects dan menjalankan Polimorfisme dengan PENOMORAN
        for i, pegawai in enumerate(self.daftar_pegawai):
            # Penomoran dan pembeda objek
            print(f"\n<<< {i+1}. DATA OBJEK - {pegawai.nama.upper()} ({type(pegawai).__name__.upper()}) >>>")
            pegawai.tampilkan_data()
            print("="*40)
            print()

# =================================================================
# FUNGSI INTERAKTIF DAN DRIVER PROGRAM
# =================================================================

def input_riwayat_gaji(pegawai):
    """Fungsi bantu untuk input riwayat gaji (Composition)"""
    print("\n--- Input Riwayat Gaji ---")
    try:
        tahun = int(input("Masukkan Tahun Riwayat Gaji: "))
        gaji = float(input("Masukkan Nominal Gaji Bulanan: "))
        kenaikan = float(input("Masukkan Persentase Kenaikan (%): "))
        riwayat = RiwayatGaji(tahun, gaji, kenaikan)
        pegawai.tambah_riwayat_gaji(riwayat)
        print("[INFO] Riwayat Gaji berhasil ditambahkan.")
    except ValueError as e:
        print(f"[ERROR] Input tidak valid: {e}")

def tambah_data_baru(manajemen: ManajemenData):
    """
    Fitur ADD data Interaktif.
    """
    print("\n--- PILIH TIPE PEGAWAI BARU ---")
    print("1. Dosen")
    print("2. Tenaga Kependidikan")
    print("3. Pramu Bakti")
    
    pilihan = input("Pilih tipe (1/2/3): ")
    
    # Input Dasar (Semua Pegawai)
    try:
        id_pegawai = input("ID Pegawai: ")
        nama = input("Nama Lengkap: ")
        gaji_pokok = float(input("Gaji Pokok: "))
        alamat = input("Alamat: ")
        tgl_lahir = input("Tanggal Lahir (YYYY-MM-DD): ")
    except ValueError:
        print("[ERROR] Input gaji tidak valid.")
        return

    pegawai_baru = None

    if pilihan == '1':
        nidn = input("NIDN: ")
        jab_akademik = input("Jabatan Akademik: ")
        jab_struktural = input("Jabatan Struktural (Contoh: Dekan/Kaprodi/Kosong): ")
        sks = int(input("Jumlah SKS Mengajar: "))
        unit_kerja = input("Unit Kerja/Fakultas: ")
        pegawai_baru = Dosen(id_pegawai, nama, gaji_pokok, alamat, tgl_lahir, nidn, jab_akademik, jab_struktural, sks, unit_kerja)
        
    elif pilihan == '2':
        departemen = input("Departemen: ")
        posisi = input("Posisi: ")
        jam_lembur = int(input("Jam Lembur: "))
        pegawai_baru = TenagaKependidikan(id_pegawai, nama, gaji_pokok, alamat, tgl_lahir, departemen, posisi, jam_lembur)
        
    elif pilihan == '3':
        area_tugas = input("Area Tugas: ")
        tunjangan_risiko = float(input("Tunjangan Risiko: "))
        jam_shift = input("Jam Shift (Pagi/Siang): ")
        pegawai_baru = PramuBakti(id_pegawai, nama, gaji_pokok, alamat, tgl_lahir, area_tugas, tunjangan_risiko, jam_shift)
        
    else:
        print("[ERROR] Pilihan tidak valid.")
        return

    # Menambahkan data baru (jika berhasil dibuat)
    if pegawai_baru:
        # Panggil fungsi composition
        input_riwayat_gaji(pegawai_baru)
        manajemen.tambah_pegawai(pegawai_baru)

def muat_data_default(manajemen: ManajemenData):
    """Memuat 6 data default (2 Dosen, 2 Tendik, 2 Pramu)"""
    
    # 1. DOSEN
    dosen1 = Dosen("D001", "Dr. Bima Sakti", 9500000, "Jl. Ilmu No. 1", "1980-08-10", "12345678", "Lektor Kepala", "Dekan", 14, "Fakultas Sains")
    dosen1.tambah_riwayat_gaji(RiwayatGaji(2024, 15000000, 6.0))
    manajemen.tambah_pegawai(dosen1) 

    dosen2 = Dosen("D002", "Siti Nurjanah", 7500000, "Jl. Riset No. 5", "1990-01-20", "87654321", "Asisten Ahli", "Kepala Program Studi", 12, "Fakultas Teknik")
    dosen2.tambah_riwayat_gaji(RiwayatGaji(2024, 10000000, 5.0))
    manajemen.tambah_pegawai(dosen2) 
    
    # 2. TENAGA KEPENDIDIKAN
    tendik1 = TenagaKependidikan("T001", "Budi Santoso", 6000000, "Jl. Mawar No. 5", "1990-11-15", "Keuangan", "Staf Senior", 10)
    tendik1.tambah_riwayat_gaji(RiwayatGaji(2024, 7500000, 4.0))
    manajemen.tambah_pegawai(tendik1)

    tendik2 = TenagaKependidikan("T002", "Rina Marlina", 4800000, "Jl. Admin No. 2", "1992-07-25", "Akademik", "Staf Junior", 0)
    tendik2.tambah_riwayat_gaji(RiwayatGaji(2024, 6000000, 3.5))
    manajemen.tambah_pegawai(tendik2)

    # 3. PRAMU BAKTI
    pramu1 = PramuBakti("P001", "Siti Aisyah", 3800000, "Jl. Kebersihan No. 2", "1995-02-05", "Area Perpustakaan", 600000, "Pagi")
    pramu1.tambah_riwayat_gaji(RiwayatGaji(2024, 4500000, 3.0))
    manajemen.tambah_pegawai(pramu1)
    
    pramu2 = PramuBakti("P002", "Joko Susilo", 3500000, "Jl. Pelayanan No. 8", "1988-06-12", "Area Toilet Utama", 700000, "Siang")
    pramu2.tambah_riwayat_gaji(RiwayatGaji(2024, 4200000, 2.5))
    manajemen.tambah_pegawai(pramu2)

def main_menu():
    """Fungsi menu utama CLI"""
    manajemen = ManajemenData()
    # Muat data default (6 data) saat program dimulai
    muat_data_default(manajemen) 

    while True:
        print("\n\n" + "="*50)
        print(" SISTEM MANAJEMEN PEGAWAI (DPBO) ".center(50, '-'))
        print("="*50)
        print("1. Tampilkan Semua Data Pegawai")
        print("2. Tambah Data Pegawai Baru")
        print("3. Keluar Program")
        print("="*50)
        
        pilihan = input("Masukkan pilihan (1-3): ")

        if pilihan == '1':
            manajemen.tampilkan_semua_data()
        elif pilihan == '2':
            tambah_data_baru(manajemen)
        elif pilihan == '3':
            print("\nTerima kasih, program berakhir. Sampai jumpa!")
            time.sleep(1)
            break
        else:
            print("\nPilihan tidak valid. Silakan coba lagi.")
            time.sleep(0.5)

if __name__ == "__main__":
    main_menu()