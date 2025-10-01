# Pegawai.py
from abc import ABC, abstractmethod
from RiwayatGaji import RiwayatGaji

class Pegawai(ABC):
    """
    Kelas Abstrak/Parent: Pegawai. 
    Induk utama untuk Hierarchical Inheritance dan Composition.
    """
    def __init__(self, id_pegawai, nama, gaji_pokok, alamat, tgl_lahir):
        # Atribut Private
        self._id_pegawai = id_pegawai
        self._nama = nama
        self._gaji_pokok = gaji_pokok
        self._alamat_lengkap = alamat
        self._tanggal_lahir_string = tgl_lahir
        
        # Composition: Pegawai HAS-A RiwayatGaji[] (Array of Objects)
        self._riwayat_gaji = [] 

    # --- GETTER ---
    @property
    def id_pegawai(self): return self._id_pegawai
    @property
    def nama(self): return self._nama
    @property
    def gaji_pokok(self): return self._gaji_pokok
    @property
    def alamat_lengkap(self): return self._alamat_lengkap
    @property
    def riwayat_gaji(self): return self._riwayat_gaji 
    @property
    def tanggal_lahir_string(self): return self._tanggal_lahir_string 

    # --- SETTER ---
    @nama.setter
    def nama(self, value):
        if not value: raise ValueError("Nama tidak boleh kosong.")
        self._nama = value
    
    @gaji_pokok.setter
    def gaji_pokok(self, value):
        if value < 3000000: raise ValueError("Gaji pokok minimal 3 juta.")
        self._gaji_pokok = value

    @alamat_lengkap.setter
    def alamat_lengkap(self, value):
        self._alamat_lengkap = value

    def tambah_riwayat_gaji(self, riwayat: RiwayatGaji):
        """Method untuk ADD DATA"""
        self._riwayat_gaji.append(riwayat)

    @abstractmethod
    def tampilkan_data(self):
        self._tampilkan_dasar() 

    @abstractmethod
    def hitung_tunjangan(self):
        pass

    def _tampilkan_dasar(self):
        # OUTPUT BERSIH: Memastikan semua atribut dasar tampil
        print("="*40)
        print(f"ID Pegawai: {self.id_pegawai} | Nama: {self.nama}")
        print(f"Gaji Pokok: {self.gaji_pokok:,.2f}")
        print(f"Alamat Lengkap: {self.alamat_lengkap}")
        print(f"Tanggal Lahir: {self.tanggal_lahir_string}")
        
        # Tampilkan Riwayat Gaji (Composition)
        print("--- Riwayat Gaji (Composition) ---")
        for riwayat in self.riwayat_gaji:
            riwayat.tampilkan_data()
        print("-" * 40)