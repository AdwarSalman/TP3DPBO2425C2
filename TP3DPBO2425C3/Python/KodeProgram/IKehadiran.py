# IKehadiran.py
from abc import ABC, abstractmethod

class IKehadiran(ABC):
    """Interface untuk Polimorfisme."""
    @abstractmethod
    def hitung_jam_kerja(self):
        pass

    @abstractmethod
    def get_bulan_kehadiran(self):
        pass