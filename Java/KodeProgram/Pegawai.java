// Pegawai.java
import java.util.ArrayList;

public abstract class Pegawai {
    // Atribut private (Enkapsulasi)
    private String idPegawai;
    private String nama;
    private double gajiPokok;
    private String alamatLengkap;
    private String tanggalLahirString;

    // Composition: Array of Objects (menggunakan ArrayList)
    private ArrayList<RiwayatGaji> riwayatGaji;

    public Pegawai(String idPegawai, String nama, double gajiPokok, String alamatLengkap, String tanggalLahirString) {
        this.idPegawai = idPegawai;
        this.nama = nama;
        this.gajiPokok = gajiPokok;
        this.alamatLengkap = alamatLengkap;
        this.tanggalLahirString = tanggalLahirString;
        this.riwayatGaji = new ArrayList<>();
    }

    // --- GETTER (Wajib) ---
    public String getIdPegawai() { return idPegawai; }
    public String getNama() { return nama; }
    public double getGajiPokok() { return gajiPokok; }
    public String getAlamatLengkap() { return alamatLengkap; }
    public String getTanggalLahirString() { return tanggalLahirString; }
    public ArrayList<RiwayatGaji> getRiwayatGaji() { return riwayatGaji; }

    // --- SETTER (Wajib) ---
    public void setNama(String nama) { 
        if (nama.isEmpty()) throw new IllegalArgumentException("Nama tidak boleh kosong.");
        this.nama = nama; 
    }
    public void setGajiPokok(double gajiPokok) { 
        if (gajiPokok < 3000000) throw new IllegalArgumentException("Gaji pokok minimal 3 juta.");
        this.gajiPokok = gajiPokok; 
    }
    public void setAlamatLengkap(String alamatLengkap) { this.alamatLengkap = alamatLengkap; }

    // Method Composition
    public void tambahRiwayatGaji(RiwayatGaji riwayat) {
        riwayatGaji.add(riwayat);
    }

    // Metode Abstrak (Polimorfisme)
    public abstract void tampilkanData();
    public abstract double hitungTunjangan();

    protected void tampilkanDasar() {
        System.out.println("========================================");
        System.out.println("ID Pegawai: " + idPegawai + " | Nama: " + nama);
        System.out.printf("Gaji Pokok: %,.2f\n", gajiPokok);
        System.out.println("Alamat Lengkap: " + alamatLengkap);
        System.out.println("Tanggal Lahir: " + tanggalLahirString);

        System.out.println("--- Riwayat Gaji (Composition) ---");
        for (RiwayatGaji riwayat : riwayatGaji) {
            riwayat.tampilkanData();
        }
        System.out.println("----------------------------------------");
    }
}