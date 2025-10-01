# RiwayatGaji.py

class RiwayatGaji:
    """Kelas Komposisi yang bersarang di dalam Pegawai."""
    def __init__(self, tahun, gaji_bulan, kenaikan):
        self._tahun = tahun
        self._gaji_bulan = gaji_bulan
        self._kenaikan = kenaikan

    # GETTER
    @property
    def tahun(self):
        return self._tahun

    @property
    def gaji_bulan(self):
        return self._gaji_bulan

    @property
    def kenaikan(self):
        return self._kenaikan

    # SETTER (Enkapsulasi)
    @tahun.setter
    def tahun(self, value):
        if value < 2000:
            raise ValueError("Tahun harus setelah 2000.")
        self._tahun = value

    @gaji_bulan.setter
    def gaji_bulan(self, value):
        if value < 0:
            raise ValueError("Gaji tidak boleh negatif.")
        self._gaji_bulan = value

    def tampilkan_data(self):
        print(f"    - Tahun: {self.tahun}, Gaji: {self.gaji_bulan:,.2f}, Kenaikan: {self.kenaikan}%")