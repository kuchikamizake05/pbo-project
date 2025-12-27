# Hotel Reservation System (PBO Project)

Sistem Reservasi Hotel sederhana yang dibangun menggunakan bahasa pemrograman C++ dengan menerapkan prinsip Pemrograman Berorientasi Objek (PBO).

## Fitur Utama
- **Manajemen Kamar**: Mendukung berbagai tipe kamar (Deluxe, Superior, Suite) menggunakan *Factory Pattern*.
- **Manajemen Customer**: Pendaftaran dan pengelolaan data tamu hotel.
- **Sistem Reservasi**: Proses pemesanan kamar, pembatalan reservasi, dan pengecekan status ketersediaan.
- **Summary Hotel**: Menampilkan ringkasan status operasional hotel.

## Struktur Proyek
- `Hotel.h/cpp`: Inti logika manajemen hotel.
- `Room.h/cpp`: Representasi kamar dan *factory* untuk pembuatan tipe kamar.
- `Customer.h/cpp`: Manajemen data pelanggan.
- `Reservation.h/cpp`: Logika transaksi reservasi.
- `Payment.h/cpp`: Penanganan proses pembayaran.
- `Utils.h/cpp`: Fungsi pembantu/utilitas.
- `main.cpp`: Antarmuka CLI (Command Line Interface).

## Cara Menjalankan
1. Pastikan Anda memiliki compiler C++ (seperti `g++`).
2. Clone repositori ini:
   ```bash
   git clone https://github.com/kuchikamizake05/pbo-project.git
   ```
3. Compile kode:
   ```bash
   g++ -o hotel main.cpp Hotel.cpp Room.cpp Customer.cpp Reservation.cpp Payment.cpp Utils.cpp
   ```
4. Jalankan aplikasi:
   ```bash
   ./hotel
   ```

## Prinsip PBO yang Diterapkan
- **Encapsulation**: Menyembunyikan detail implementasi data pada setiap class.
- **Inheritance & Polymorphism**: Digunakan pada struktur tipe kamar.
- **Abstraction**: Menyederhanakan kompleksitas sistem reservasi menjadi antarmuka yang mudah digunakan.
- **Factory Pattern**: Digunakan dalam pembuatan objek kamar.
