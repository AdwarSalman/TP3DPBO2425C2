# IKepemimpinan.py
from abc import ABC, abstractmethod

class IKepemimpinan(ABC):
    """Interface untuk Hybrid/Multiple Inheritance."""
    @abstractmethod
    def ambil_keputusan_strategis(self):
        pass

    @abstractmethod
    def get_unit_kerja(self):
        pass