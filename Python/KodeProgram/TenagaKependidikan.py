# TenagaKependidikan.py
from Pegawai import Pegawai
from IKehadiran import IKehadiran

class TenagaKependidikan(Pegawai, IKehadiran):
    """Subkelas TenagaKependidikan: Hierarchical Inheritance."""
    def __init__(self, id_pegawai, nama, gaji_pokok, alamat, tgl_lahir, departemen, posisi, jam_lembur):
        super().__init__(id_pegawai, nama, gaji_pokok, alamat, tgl_lahir)
        self._departemen = departemen
        self._posisi = posisi
        self._jam_lembur = jam_lembur

    # --- GETTER SPESIFIK ---
    @property
    def departemen(self): return self._departemen
    @property
    def posisi(self): return self._posisi
    @property
    def jam_lembur(self): return self._jam_lembur

    # --- SETTER SPESIFIK ---
    @jam_lembur.setter
    def jam_lembur(self, value):
        if value < 0: raise ValueError("Jam lembur tidak boleh negatif.")
        self._jam_lembur = value

    def hitung_tunjangan(self):
        tunjangan_posisi = 500000 
        tunjangan_lembur = self.jam_lembur * 50000
        return tunjangan_posisi + tunjangan_lembur

    def tampilkan_data(self):
        self._tampilkan_dasar()
        print(f"Jabatan: Tenaga Kependidikan")
        # Menampilkan semua atribut spesifik
        print(f"Departemen: {self.departemen}") 
        print(f"Posisi: {self.posisi}")
        print(f"Jam Lembur: {self.jam_lembur} jam")
        
        print(f"Total Gaji + Tunjangan: {(self.gaji_pokok + self.hitung_tunjangan()):,.2f}")
        print(f"Jam Kerja Bulan Ini: {self.hitung_jam_kerja()} jam")

    def hitung_jam_kerja(self):
        return 160 + self.jam_lembur

    def get_bulan_kehadiran(self):
        return "Oktober"