// Dosen.java

public class Dosen extends Pegawai implements IKepemimpinan, IKehadiran {
    // Atribut private spesifik
    private String nidn;
    private String jabatanAkademik;
    private String jabatanStruktural;
    private int jumlahSKS;
    private String unitKerja;

    public Dosen(String idPegawai, String nama, double gajiPokok, String alamatLengkap, String tanggalLahirString,
                 String nidn, String jabatanAkademik, String jabatanStruktural, int jumlahSKS, String unitKerja) {
        super(idPegawai, nama, gajiPokok, alamatLengkap, tanggalLahirString);
        this.nidn = nidn;
        this.jabatanAkademik = jabatanAkademik;
        this.jabatanStruktural = jabatanStruktural;
        this.jumlahSKS = jumlahSKS;
        this.unitKerja = unitKerja;
    }

    // --- GETTER/SETTER SPESIFIK ---
    public String getNidn() { return nidn; }
    public String getJabatanAkademik() { return jabatanAkademik; }
    public String getJabatanStruktural() { return jabatanStruktural; }
    public int getJumlahSKS() { return jumlahSKS; }

    public void setJabatanStruktural(String jabatanStruktural) {
        if (!jabatanStruktural.equals("Kaprodi") && !jabatanStruktural.equals("Dekan") && !jabatanStruktural.isEmpty()) {
            throw new IllegalArgumentException("Jabatan struktural tidak valid.");
        }
        this.jabatanStruktural = jabatanStruktural;
    }

    // Implementasi Polimorfik wajib dari Pegawai
    @Override
    public double hitungTunjangan() {
        double tunjanganSKS = this.jumlahSKS * 100000;
        // Logic Hybrid Inheritance
        double tunjanganJabatan = this.jabatanStruktural != null && !this.jabatanStruktural.isEmpty() ? 3000000 : 0;
        return tunjanganSKS + tunjanganJabatan;
    }

    @Override
    public void tampilkanData() {
        super.tampilkanDasar();
        System.out.println("Jabatan: Dosen");
        System.out.println("NIDN: " + this.nidn); 
        System.out.println("Jabatan Akademik: " + this.jabatanAkademik);
        System.out.println("Jumlah SKS Mengajar: " + this.jumlahSKS);
        System.out.println("Jabatan Struktural: " + this.jabatanStruktural); 
        System.out.println("Unit Kerja Struktural: " + this.getUnitKerja()); 
        
        System.out.println("Keterangan Struktural: " + this.ambilKeputusanStrategis()); 
        System.out.printf("Total Gaji + Tunjangan: %,.2f\n", (this.getGajiPokok() + this.hitungTunjangan()));
        System.out.printf("Jam Kerja Bulan Ini: %.2f jam\n", this.hitungJamKerja());
    }
    
    // Implementasi wajib dari IKepemimpinan (Hybrid Inheritance)
    @Override
    public String ambilKeputusanStrategis() {
        if (this.jabatanStruktural != null && !this.jabatanStruktural.isEmpty()) {
            return "Mengambil keputusan strategis untuk " + this.getUnitKerja();
        } else {
            return "Tidak memiliki jabatan struktural aktif.";
        }
    }
    
    @Override
    public String getUnitKerja() {
        return this.unitKerja;
    }

    // Implementasi wajib dari IKehadiran
    @Override
    public double hitungJamKerja() {
        return this.jumlahSKS * 1.5 * 16;
    }

    @Override
    public String getBulanKehadiran() {
        return "Oktober";
    }
}