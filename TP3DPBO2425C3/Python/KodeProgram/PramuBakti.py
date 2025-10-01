# PramuBakti.py
from Pegawai import Pegawai
from IKehadiran import IKehadiran

class PramuBakti(Pegawai, IKehadiran):
    """Subkelas PramuBakti: Hierarchical Inheritance."""
    def __init__(self, id_pegawai, nama, gaji_pokok, alamat, tgl_lahir, area_tugas, tunjangan_risiko, jam_shift):
        super().__init__(id_pegawai, nama, gaji_pokok, alamat, tgl_lahir)
        self._area_tugas = area_tugas
        self._tunjangan_risiko = tunjangan_risiko
        self._jam_kerja_shift = jam_shift

    # --- GETTER SPESIFIK ---
    @property
    def area_tugas(self): return self._area_tugas
    @property
    def tunjangan_risiko(self): return self._tunjangan_risiko
    @property
    def jam_kerja_shift(self): return self._jam_kerja_shift
    
    # --- SETTER SPESIFIK ---
    @tunjangan_risiko.setter
    def tunjangan_risiko(self, value):
        if value < 0: raise ValueError("Tunjangan tidak boleh negatif.")
        self._tunjangan_risiko = value

    def hitung_tunjangan(self):
        tunjangan_risiko = self.tunjangan_risiko * 1.5
        return tunjangan_risiko

    def tampilkan_data(self):
        self._tampilkan_dasar()
        print(f"Jabatan: Pramu Bakti")
        # Menampilkan semua atribut spesifik
        print(f"Area Tugas: {self.area_tugas}") 
        print(f"Tunjangan Risiko Dasar: {self.tunjangan_risiko:,.2f}")
        print(f"Jam Shift: {self.jam_kerja_shift}")
        
        print(f"Total Gaji + Tunjangan: {(self.gaji_pokok + self.hitung_tunjangan()):,.2f}")
        print(f"Jam Kerja Bulan Ini: {self.hitung_jam_kerja()} jam")

    def hitung_jam_kerja(self):
        return 20 * 8 

    def get_bulan_kehadiran(self):
        return "Oktober"