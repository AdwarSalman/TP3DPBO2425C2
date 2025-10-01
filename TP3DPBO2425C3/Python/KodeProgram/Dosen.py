# Dosen.py
from Pegawai import Pegawai
from IKepemimpinan import IKepemimpinan
from IKehadiran import IKehadiran

class Dosen(Pegawai, IKepemimpinan, IKehadiran):
    """Subkelas Dosen: Hybrid Inheritance (Pegawai + IKepemimpinan)."""
    def __init__(self, id_pegawai, nama, gaji_pokok, alamat, tgl_lahir, nidn, jab_akademik, jab_struktural, sks, unit_kerja):
        super().__init__(id_pegawai, nama, gaji_pokok, alamat, tgl_lahir)
        self._nidn = nidn
        self._jabatan_akademik = jab_akademik
        self._jabatan_struktural = jab_struktural
        self._jumlah_sks = sks
        self._unit_kerja = unit_kerja

    # --- GETTER SPESIFIK ---
    @property
    def nidn(self): return self._nidn
    @property
    def jabatan_akademik(self): return self._jabatan_akademik
    @property
    def jabatan_struktural(self): return self._jabatan_struktural
    @property
    def jumlah_sks(self): return self._jumlah_sks
    
    # --- SETTER SPESIFIK ---
    @jabatan_struktural.setter
    def jabatan_struktural(self, value):
        if value not in ["Kaprodi", "Dekan", None, ""]:
            raise ValueError("Jabatan struktural tidak valid.")
        self._jabatan_struktural = value
    
    @jumlah_sks.setter
    def jumlah_sks(self, value):
        if value < 0 or value > 24: raise ValueError("SKS harus antara 0-24.")
        self._jumlah_sks = value

    def hitung_tunjangan(self):
        tunjangan_sks = self.jumlah_sks * 100000 
        tunjangan_jabatan = 3000000 if self.jabatan_struktural else 0
        return tunjangan_sks + tunjangan_jabatan

    def tampilkan_data(self):
        self._tampilkan_dasar()
        print(f"Jabatan: Dosen")
        # Menampilkan semua atribut spesifik (Pertanggungjawaban Data)
        print(f"NIDN: {self.nidn}") 
        print(f"Jabatan Akademik: {self.jabatan_akademik}")
        print(f"Jumlah SKS Mengajar: {self.jumlah_sks}")
        print(f"Jabatan Struktural: {self.jabatan_struktural}") 
        print(f"Unit Kerja Struktural: {self.get_unit_kerja()}") 
        
        # Output Hybrid Inheritance
        print(f"Keterangan Struktural: {self.ambil_keputusan_strategis()}") 
        print(f"Total Gaji + Tunjangan: {(self.gaji_pokok + self.hitung_tunjangan()):,.2f}")
        print(f"Jam Kerja Bulan Ini: {self.hitung_jam_kerja()} jam")


    # Implementasi Wajib dari IKepemimpinan (Logic Hybrid Inheritance & Enkapsulasi)
    def ambil_keputusan_strategis(self):
        """Memastikan output kepemimpinan hanya muncul jika ada jabatan."""
        # Mengakses atribut melalui Getter
        if self.jabatan_struktural: 
            return f"Mengambil keputusan strategis untuk {self.get_unit_kerja()}"
        else:
            # Output jika jabatan kosong (Pertanggungjawaban data kosong)
            return "Tidak memiliki jabatan struktural aktif." 
            
    def get_unit_kerja(self):
        # Mengembalikan field private
        return self._unit_kerja 

    # Implementasi Wajib dari IKehadiran
    def hitung_jam_kerja(self):
        return self.jumlah_sks * 1.5 * 16

    def get_bulan_kehadiran(self):
        return "Oktober"