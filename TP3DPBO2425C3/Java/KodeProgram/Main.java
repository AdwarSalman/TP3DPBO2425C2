// Main.java
import java.util.ArrayList;
import java.util.InputMismatchException;
import java.util.Scanner;

public class Main {
    private ArrayList<Pegawai> daftarPegawai; // Array of Objects
    private Scanner scanner;

    public Main() {
        this.daftarPegawai = new ArrayList<>();
        this.scanner = new Scanner(System.in);
    }

    public void tambahPegawai(Pegawai pegawai) {
        // Fungsi ADD DATA
        daftarPegawai.add(pegawai);
        System.out.println("\n[INFO]: Data pegawai '" + pegawai.getNama() + "' berhasil ditambahkan!");
    }

    public void tampilkanSemuaData() {
        // Fungsi DISPLAY ALL DATA (Polimorfisme)
        if (daftarPegawai.isEmpty()) {
            System.out.println("\n--- Data pegawai masih kosong. ---");
            return;
        }

        System.out.println("\n" + "#".repeat(70));
        System.out.println(" LAPORAN DATA PEGAWAI INSTITUSI (ARRAY OF OBJECTS & POLIMORFISME) ".indent(2));
        System.out.println("#".repeat(70));

        // Iterasi Array of Objects dan menjalankan Polimorfisme dengan PENOMORAN
        for (int i = 0; i < daftarPegawai.size(); i++) {
            Pegawai pegawai = daftarPegawai.get(i);
            System.out.printf("\n<<< %d. DATA OBJEK - %s (%s) >>>\n", 
                                i + 1, pegawai.getNama().toUpperCase(), pegawai.getClass().getSimpleName().toUpperCase());
            pegawai.tampilkanData(); // Polimorfisme dipanggil
            System.out.println("========================================");
            System.out.println();
        }
    }

    private void inputRiwayatGaji(Pegawai pegawai) {
        // Fungsi bantu untuk input riwayat gaji (Composition)
        System.out.println("\n--- Input Riwayat Gaji (Composition) ---");
        try {
            System.out.print("Masukkan Tahun Riwayat Gaji: ");
            int tahun = scanner.nextInt();
            System.out.print("Masukkan Nominal Gaji Bulanan: ");
            double gaji = scanner.nextDouble();
            System.out.print("Masukkan Persentase Kenaikan (%): ");
            double kenaikan = scanner.nextDouble();
            scanner.nextLine(); // Membersihkan buffer

            RiwayatGaji riwayat = new RiwayatGaji(tahun, gaji, kenaikan);
            pegawai.tambahRiwayatGaji(riwayat);
            System.out.println("[INFO] Riwayat Gaji berhasil ditambahkan.");
        } catch (InputMismatchException e) {
            System.out.println("[ERROR] Input tidak valid. Mohon masukkan angka.");
            scanner.nextLine(); // Membersihkan buffer setelah error
        }
    }

    private void tambahDataBaru() {
        // Fitur ADD data Interaktif
        System.out.println("\n--- PILIH TIPE PEGAWAI BARU ---");
        System.out.println("1. Dosen");
        System.out.println("2. Tenaga Kependidikan");
        System.out.println("3. Pramu Bakti");
        
        System.out.print("Pilih tipe (1/2/3): ");
        String pilihan = scanner.nextLine();
        
        Pegawai pegawaiBaru = null;

        try {
            // Input Dasar (Semua Pegawai)
            System.out.print("ID Pegawai: ");
            String idPegawai = scanner.nextLine();
            System.out.print("Nama Lengkap: ");
            String nama = scanner.nextLine();
            System.out.print("Gaji Pokok: ");
            double gajiPokok = Double.parseDouble(scanner.nextLine());
            System.out.print("Alamat: ");
            String alamat = scanner.nextLine();
            System.out.print("Tanggal Lahir (YYYY-MM-DD): ");
            String tglLahir = scanner.nextLine();

            if (pilihan.equals("1")) {
                System.out.print("NIDN: "); String nidn = scanner.nextLine();
                System.out.print("Jabatan Akademik: "); String jabAkademik = scanner.nextLine();
                System.out.print("Jabatan Struktural (Dekan/Kaprodi/Kosong): "); String jabStruktural = scanner.nextLine();
                System.out.print("Jumlah SKS Mengajar: "); int sks = Integer.parseInt(scanner.nextLine());
                System.out.print("Unit Kerja/Fakultas: "); String unitKerja = scanner.nextLine();
                pegawaiBaru = new Dosen(idPegawai, nama, gajiPokok, alamat, tglLahir, nidn, jabAkademik, jabStruktural, sks, unitKerja);
                
            } else if (pilihan.equals("2")) {
                System.out.print("Departemen: "); String departemen = scanner.nextLine();
                System.out.print("Posisi: "); String posisi = scanner.nextLine();
                System.out.print("Jam Lembur: "); int jamLembur = Integer.parseInt(scanner.nextLine());
                pegawaiBaru = new TenagaKependidikan(idPegawai, nama, gajiPokok, alamat, tglLahir, departemen, posisi, jamLembur);
                
            } else if (pilihan.equals("3")) {
                System.out.print("Area Tugas: "); String areaTugas = scanner.nextLine();
                System.out.print("Tunjangan Risiko: "); double tunjanganRisiko = Double.parseDouble(scanner.nextLine());
                System.out.print("Jam Shift (Pagi/Siang): "); String jamShift = scanner.nextLine();
                pegawaiBaru = new PramuBakti(idPegawai, nama, gajiPokok, alamat, tglLahir, areaTugas, tunjanganRisiko, jamShift);
                
            } else {
                System.out.println("[ERROR] Pilihan tidak valid.");
                return;
            }

            // Menambahkan data baru
            if (pegawaiBaru != null) {
                inputRiwayatGaji(pegawaiBaru);
                tambahPegawai(pegawaiBaru);
            }
        } catch (NumberFormatException e) {
            System.out.println("[ERROR] Input Gaji/SKS/Jam Lembur/Tunjangan harus berupa angka.");
        } catch (Exception e) {
            System.out.println("[FATAL ERROR] Terjadi kesalahan: " + e.getMessage());
        }
    }

    private void muatDataDefault() {
        // Muat 6 data default (2 Dosen, 2 Tendik, 2 Pramu)
        
        // 1. DOSEN
        Dosen dosen1 = new Dosen("D001", "Dr. Bima Sakti", 9500000, "Jl. Ilmu No. 1", "1980-08-10", "12345678", "Lektor Kepala", "Dekan", 14, "Fakultas Sains");
        dosen1.tambahRiwayatGaji(new RiwayatGaji(2024, 15000000, 6.0));
        tambahPegawai(dosen1); 

        Dosen dosen2 = new Dosen("D002", "Siti Nurjanah", 7500000, "Jl. Riset No. 5", "1990-01-20", "87654321", "Asisten Ahli", "Kepala Program Studi", 12, "Fakultas Teknik");
        dosen2.tambahRiwayatGaji(new RiwayatGaji(2024, 10000000, 5.0));
        tambahPegawai(dosen2); 
        
        // 2. TENAGA KEPENDIDIKAN
        TenagaKependidikan tendik1 = new TenagaKependidikan("T001", "Budi Santoso", 6000000, "Jl. Mawar No. 5", "1990-11-15", "Keuangan", "Staf Senior", 10);
        tendik1.tambahRiwayatGaji(new RiwayatGaji(2024, 7500000, 4.0));
        tambahPegawai(tendik1);

        TenagaKependidikan tendik2 = new TenagaKependidikan("T002", "Rina Marlina", 4800000, "Jl. Admin No. 2", "1992-07-25", "Akademik", "Staf Junior", 0);
        tendik2.tambahRiwayatGaji(new RiwayatGaji(2024, 6000000, 3.5));
        tambahPegawai(tendik2);

        // 3. PRAMU BAKTI
        PramuBakti pramu1 = new PramuBakti("P001", "Siti Aisyah", 3800000, "Jl. Kebersihan No. 2", "1995-02-05", "Area Perpustakaan", 600000, "Pagi");
        pramu1.tambahRiwayatGaji(new RiwayatGaji(2024, 4500000, 3.0));
        tambahPegawai(pramu1);
        
        PramuBakti pramu2 = new PramuBakti("P002", "Joko Susilo", 3500000, "Jl. Pelayanan No. 8", "1988-06-12", "Area Toilet Utama", 700000, "Siang");
        pramu2.tambahRiwayatGaji(new RiwayatGaji(2024, 4200000, 2.5));
        tambahPegawai(pramu2);
    }

    private void mainMenu() {
        muatDataDefault(); // Muat data default saat program dimulai

        int pilihan = 0;
        do {
            System.out.println("\n\n" + "=".repeat(50));
            System.out.println(" SISTEM MANAJEMEN PEGAWAI (DPBO) ".indent(2).repeat(1));
            System.out.println("=".repeat(50));
            System.out.println("1. Tampilkan Semua Data Pegawai (Polimorfisme)");
            System.out.println("2. Tambah Data Pegawai Baru (Interaktif)");
            System.out.println("3. Keluar Program");
            System.out.println("=".repeat(50));
            
            System.out.print("Masukkan pilihan (1-3): ");
            
            try {
                String input = scanner.nextLine();
                pilihan = Integer.parseInt(input);
            } catch (NumberFormatException e) {
                pilihan = 0;
            }

            switch (pilihan) {
                case 1:
                    tampilkanSemuaData();
                    break;
                case 2:
                    tambahDataBaru();
                    break;
                case 3:
                    System.out.println("\nTerima kasih, program berakhir. Sampai jumpa!");
                    break;
                default:
                    System.out.println("\nPilihan tidak valid. Silakan coba lagi.");
            }
        } while (pilihan != 3);
        scanner.close();
    }

    public static void main(String[] args) {
        Main app = new Main();
        app.mainMenu();
    }
}