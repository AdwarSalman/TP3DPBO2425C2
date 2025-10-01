// PramuBakti.java

public class PramuBakti extends Pegawai implements IKehadiran {
    private String areaTugas;
    private double tunjanganRisiko;
    private String jamKerjaShift;

    public PramuBakti(String idPegawai, String nama, double gajiPokok, String alamatLengkap, String tanggalLahirString,
                      String areaTugas, double tunjanganRisiko, String jamKerjaShift) {
        super(idPegawai, nama, gajiPokok, alamatLengkap, tanggalLahirString);
        this.areaTugas = areaTugas;
        this.tunjanganRisiko = tunjanganRisiko;
        this.jamKerjaShift = jamKerjaShift;
    }

    // --- GETTER/SETTER SPESIFIK ---
    public String getAreaTugas() { return areaTugas; }
    public double getTunjanganRisiko() { return tunjanganRisiko; }
    public String getJamKerjaShift() { return jamKerjaShift; }

    public void setTunjanganRisiko(double tunjanganRisiko) {
        if (tunjanganRisiko < 0) throw new IllegalArgumentException("Tunjangan risiko tidak boleh negatif.");
        this.tunjanganRisiko = tunjanganRisiko;
    }

    // Implementasi Polimorfik wajib dari Pegawai
    @Override
    public double hitungTunjangan() {
        return this.tunjanganRisiko * 1.5;
    }

    @Override
    public void tampilkanData() {
        super.tampilkanDasar();
        System.out.println("Jabatan: Pramu Bakti");
        System.out.println("Area Tugas: " + this.areaTugas); 
        System.out.printf("Tunjangan Risiko Dasar: %,.2f\n", this.tunjanganRisiko);
        System.out.println("Jam Shift: " + this.jamKerjaShift);
        
        System.out.printf("Total Gaji + Tunjangan: %,.2f\n", (this.getGajiPokok() + this.hitungTunjangan()));
        System.out.printf("Jam Kerja Bulan Ini: %.0f jam\n", this.hitungJamKerja());
    }

    // Implementasi wajib dari IKehadiran
    @Override
    public double hitungJamKerja() {
        return 20 * 8; // Asumsi 20 hari kerja x 8 jam
    }

    @Override
    public String getBulanKehadiran() {
        return "Oktober";
    }
}