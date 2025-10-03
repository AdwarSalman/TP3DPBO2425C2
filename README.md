Sistem Manajemen Pegawai Institusi (DPBO)
1. Janji

2. Desain Diagram Program 

<img width="972" height="903" alt="TP3DPBOC22025 drawio (2)" src="https://github.com/user-attachments/assets/8887ccc1-afc6-4663-9b9b-35302d779c10" />


3. Penjelasan Atribut dan Methods Setiap Kelas

1. Pegawai (Kelas Abstrak)
Atribut Unik:

_id_pegawai, _nama, _gaji_pokok (Data dasar pegawai).

_alamat_lengkap, _tanggal_lahir_string (Data identitas).

_riwayat_gaji (Composition: Koleksi objek RiwayatGaji).

Metode Kunci:

getNama(), setGajiPokok() (Enkapsulasi).

tambahRiwayatGaji() (Menambahkan objek Composition).

tampilkanData() (Abstrak: Polimorfisme Tampilan).

hitungTunjangan() (Abstrak: Polimorfisme Perhitungan).

2. RiwayatGaji (Kelas Komposisi)
Atribut Unik:

_tahun, _gaji_bulan, _kenaikan (Detail riwayat).

Metode Kunci:

getTahun(), setGajiBulanan() (Enkapsulasi).

tampilkanData() (Menampilkan detail riwayat gaji).

3. Dosen (Kelas Hybrid Inheritance)
Atribut Unik:

_nidn, _jabatan_akademik, _jumlah_sks (Akademik).

_jabatan_struktural, _unit_kerja (Peran dari IKepemimpinan).

Metode Kunci:

setJabatanStruktural() (Enkapsulasi & Validasi Hybrid).

ambilKeputusanStrategis() (Implementasi IKepemimpinan).

hitungTunjangan() (Override: Logika gaji Dosen).

hitungJamKerja() (Implementasi IKehadiran).

4. TenagaKependidikan (Kelas Hierarchical Inheritance)
Atribut Unik:

_departemen, _posisi (Administrasi).

_jam_lembur (Perhitungan kehadiran).

Metode Kunci:

getJamLembur() (Enkapsulasi).

hitungTunjangan() (Override: Logika gaji Tendik).

hitungJamKerja() (Implementasi IKehadiran).

5. PramuBakti (Kelas Hierarchical Inheritance)
Atribut Unik:

_area_tugas, _tunjangan_risiko, _jam_kerja_shift.

Metode Kunci:

setTunjanganRisiko() (Enkapsulasi).

hitungTunjangan() (Override: Logika gaji Pramu Bakti).

hitungJamKerja() (Implementasi IKehadiran).

6. IKepemimpinan (Interface)
Metode Kunci (Tidak punya atribut):

ambilKeputusanStrategis() (Perilaku Hybrid).

getUnitKerja() (Akses data struktural).

getTunjanganJabatan() (Akses nilai tunjangan jabatan).

7. IKehadiran (Interface)
Metode Kunci (Tidak punya atribut):

hitungJamKerja() (Perilaku Polimorfisme).

getBulanKehadiran() (Akses periode waktu).

isHadirPenuh() (Cek status kehadiran).

8. ManajemenData (Kelas Pengelola)
Atribut Unik:

_daftar_pegawai (Koleksi objek Pegawai - Array of Objects).

Metode Kunci:

tambahPegawai() (Fungsi ADD DATA).

tampilkanSemuaData() (Fungsi DISPLAY ALL DATA & Polimorfisme).

muatDataDefault() (Inisialisasi data awal).

4. Penjelasan Desain Program (Inheritance & Composition)
Desain program ini menggunakan model 3-Cabang Hierarchical Inheritance dan Hybrid Inheritance untuk memisahkan tanggung jawab pegawai secara rasional.

A. Hierarchical Inheritance
Kelas Pegawai berfungsi sebagai kelas dasar (Kelas Abstrak) yang diwarisi oleh tiga subkelas konkret: Dosen, TenagaKependidikan, dan PramuBakti.

Penerapan: Semua subkelas berbagi data dasar (mis. nama, idPegawai) dan diwajibkan meng-override perilaku spesifik seperti hitungTunjangan().

B. Hybrid Inheritance (Multiple Inheritance)
Konsep ini diterapkan pada kelas Dosen untuk memodelkan peran ganda:

Vertikal (Kelas): Dosen mewarisi (extends) sifat dasar dari Pegawai.

Horizontal (Interface): Dosen mengimplementasikan (implements) IKepemimpinan.

Tujuan: Memungkinkan objek Dosen mendapatkan data dari Pegawai sekaligus memperoleh kemampuan perilaku struktural (misalnya, ambilKeputusanStrategis) yang tidak dimiliki oleh Pegawai biasa.

C. Composition (Kepemilikan Wajib)
Hubungan Composition diimplementasikan antara Pegawai dan RiwayatGaji.

Penerapan: Kelas Pegawai memiliki (has-a) koleksi (Array/List/Vector) dari objek RiwayatGaji.

Rasionalitas: Data Riwayat Gaji tidak relevan tanpa eksistensi objek Pegawai. Ini juga sekaligus memenuhi syarat Array of Objects di dalam objek.

D. Polimorfisme & Array of Objects
Polimorfisme: Kelas Pegawai mendefinisikan metode abstrak (tampilkanData()). Kelas ManajemenData kemudian dapat memanggil pegawai.tampilkanData() pada Array of Objects-nya, dan runtime akan memilih implementasi yang benar (Dosen, Tendik, atau PramuBakti).

Interface: Implementasi IKehadiran oleh ketiga subkelas memastikan Polimorfisme diterapkan pada fungsi hitungJamKerja() dengan logika yang unik di setiap jenis pegawai.

5. Penjelasan Alur Program (Universal)
Alur program ini didorong oleh interaksi antara kelas pengelola (ManajemenData) dengan model data (Pegawai dan turunannya), serta penggunaan fitur ADD dan DISPLAY sebagai inti.

1. Inisialisasi dan Pembuatan Objek
Start & Initialization: Program dimulai dengan fungsi main(), yang menciptakan satu instance dari kelas ManajemenData.

Muat Data Default: Method muatDataDefault() dipanggil. Di sini, 6 objek konkret (2 Dosen, 2 TenagaKependidikan, 2 PramuBakti) diciptakan.

Composition Inisiasi: Selama pembuatan setiap objek pegawai, method tambahRiwayatGaji() dipanggil. Method ini menciptakan instance dari kelas RiwayatGaji dan menyimpannya ke dalam _riwayat_gaji (Array of Objects) di dalam objek Pegawai. Ini memastikan relasi Composition terpenuhi.

Array of Objects: Setiap objek pegawai yang baru dibuat kemudian diserahkan ke method tambahPegawai() milik ManajemenData, di mana objek tersebut disimpan dalam koleksi _daftar_pegawai (Array of Objects).

2. Alur Fungsi ADD DATA (Menu Opsi 2)
Fungsi ini menguji kemampuan program untuk menciptakan dan memvalidasi objek baru secara interaktif (Enkapsulasi).

Pilihan Tipe: Pengguna memilih tipe pegawai yang akan ditambahkan (Dosen, TenagaKependidikan, atau PramuBakti).

Input & Setter: Program meminta input data. Setiap input dicek kevalidannya. Jika data diubah setelah objek dibuat (misalnya, dosen.setGajiPokok(value)), mekanisme Setter akan mengaktifkan validasi Enkapsulasi.

Penciptaan Objek: Objek baru (misalnya Dosen) diciptakan, secara otomatis menjalankan Hierarchical Inheritance (mendapat atribut dasar dari Pegawai) dan menyiapkan kontrak Hybrid Inheritance (IKepemimpinan, IKehadiran).

Composition Interaktif: Pengguna kemudian diminta untuk menginput detail RiwayatGaji. Objek RiwayatGaji yang baru dibuat dihubungkan ke objek pegawai, memastikan integritas Composition.

Penyimpanan Polimorfik: Objek pegawai baru dimasukkan ke dalam koleksi _daftar_pegawai (Array of Objects) milik ManajemenData.

3. Alur Fungsi DISPLAY ALL DATA (Menu Opsi 1)
Fungsi ini adalah puncak demonstrasi Polimorfisme dan Array of Objects.

Iterasi Koleksi: Program memulai loop melalui _daftar_pegawai. Penting untuk dicatat bahwa loop ini hanya melihat tipe dasar Pegawai.

Polimorfisme Runtime (Tampilan): Pada setiap objek, method tampilkanData() dipanggil.

Karena tampilkanData() adalah method Polimorfik (dideklarasikan abstrak di Pegawai), JVM/Kompiler C++ akan secara otomatis menentukan tipe objek sebenarnya (Dosen, Tendik, atau PramuBakti) pada saat runtime.

Method tampilkanData() yang spesifik dijalankan, mencetak atribut unik (NIDN untuk Dosen, jamLembur untuk Tendik, dll.).

Polimorfisme Fungsional (Perhitungan): Selama tampilan data, method perhitungan dipanggil secara internal:

hitungTunjangan() dijalankan: Dosen, Tendik, dan PramuBakti masing-masing menggunakan logika perhitungan yang berbeda-beda.

hitungJamKerja() (dari Interface IKehadiran) dijalankan: Masing-masing kelas menghitung jam kerja dengan aturan unik mereka.

Program berakhir ketika pengguna memilih opsi 'Keluar Program'.
6. Dokumentasi
1. CPP
<img width="1107" height="748" alt="DokumentasiCPP(add)" src="https://github.com/user-attachments/assets/232645f7-ebcc-4f8c-b462-da803265f442" />
<img width="472" height="841" alt="DokumentasiCPP(display1)" src="https://github.com/user-attachments/assets/24a66c65-9a7a-4782-9720-b948b49b05b6" />
<img width="445" height="958" alt="DokumentasiCPP(display2)" src="https://github.com/user-attachments/assets/b39ef8fe-43bf-444d-8656-6dd00b873af4" />

2. Python
<img width="1184" height="695" alt="DokumentasiPython(add)" src="https://github.com/user-attachments/assets/7a84d2d0-3449-47de-a6e9-40f40c5080a9" />
<img width="680" height="926" alt="DokumentasiPython(Display)" src="https://github.com/user-attachments/assets/0c16834e-f356-4890-9c5e-a53604979868" />

3. Java
<img width="1121" height="834" alt="DokumentasiJava(add)" src="https://github.com/user-attachments/assets/0d3a869c-65d2-4099-a6b0-71383f2cbfcc" />
<img width="704" height="951" alt="DokumentasiJava(Display)" src="https://github.com/user-attachments/assets/caaad1d8-7b46-4a93-ba77-dc153ac0834c" />
