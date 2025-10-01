// RiwayatGaji.java

public class RiwayatGaji {
    // Atribut private untuk Enkapsulasi
    private int tahun;
    private double gajiBulanan;
    private double kenaikan;

    public RiwayatGaji(int tahun, double gajiBulanan, double kenaikan) {
        this.tahun = tahun;
        this.gajiBulanan = gajiBulanan;
        this.kenaikan = kenaikan;
    }

    // --- GETTER ---
    public int getTahun() { return tahun; }
    public double getGajiBulanan() { return gajiBulanan; }
    public double getKenaikan() { return kenaikan; }

    // --- SETTER ---
    public void setTahun(int tahun) {
        if (tahun < 2000) throw new IllegalArgumentException("Tahun harus setelah 2000.");
        this.tahun = tahun;
    }
    public void setGajiBulanan(double gajiBulanan) {
        if (gajiBulanan < 0) throw new IllegalArgumentException("Gaji tidak boleh negatif.");
        this.gajiBulanan = gajiBulanan;
    }
    
    public void tampilkanData() {
        System.out.printf("    - Tahun: %d, Gaji: %,.2f, Kenaikan: %.2f%%\n", this.tahun, this.gajiBulanan, this.kenaikan);
    }
}