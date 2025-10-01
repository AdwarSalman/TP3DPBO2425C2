// TenagaKependidikan.java

public class TenagaKependidikan extends Pegawai implements IKehadiran {
    private String departemen;
    private String posisi;
    private int jamLembur;

    public TenagaKependidikan(String idPegawai, String nama, double gajiPokok, String alamatLengkap, String tanggalLahirString,
                              String departemen, String posisi, int jamLembur) {
        super(idPegawai, nama, gajiPokok, alamatLengkap, tanggalLahirString);
        this.departemen = departemen;
        this.posisi = posisi;
        this.jamLembur = jamLembur;
    }

    // --- GETTER/SETTER SPESIFIK ---
    public String getDepartemen() { return departemen; }
    public String getPosisi() { return posisi; }
    public int getJamLembur() { return jamLembur; }

    public void setJamLembur(int jamLembur) {
        if (jamLembur < 0) throw new IllegalArgumentException("Jam lembur tidak boleh negatif.");
        this.jamLembur = jamLembur;
    }

    // Implementasi Polimorfik wajib dari Pegawai
    @Override
    public double hitungTunjangan() {
        double tunjanganPosisi = 500000; 
        double tunjanganLembur = this.jamLembur * 50000; 
        return tunjanganPosisi + tunjanganLembur;
    }

    @Override
    public void tampilkanData() {
        super.tampilkanDasar();
        System.out.println("Jabatan: Tenaga Kependidikan");
        System.out.println("Departemen: " + this.departemen); 
        System.out.println("Posisi: " + this.posisi);
        System.out.println("Jam Lembur: " + this.jamLembur + " jam");
        
        System.out.printf("Total Gaji + Tunjangan: %,.2f\n", (this.getGajiPokok() + this.hitungTunjangan()));
        System.out.printf("Jam Kerja Bulan Ini: %.0f jam\n", this.hitungJamKerja());
    }

    // Implementasi wajib dari IKehadiran
    @Override
    public double hitungJamKerja() {
        return 160 + this.jamLembur;
    }

    @Override
    public String getBulanKehadiran() {
        return "Oktober";
    }
}