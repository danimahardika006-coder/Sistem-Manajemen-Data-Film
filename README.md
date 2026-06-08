# 🎬 Sistem Manajemen Data Film

Program berbasis C++ untuk mengelola data film menggunakan konsep **Struct, Array, File Handling, Searching, dan Sorting**. Data film disimpan secara permanen pada file `.txt` sehingga tetap tersedia meskipun program ditutup.

## 👥 Anggota Kelompok

- Dani Ramadan Mahardika (123250038)
- Anisya Awalia Nur Ramadhani (123250024)

---

## 📌 Deskripsi Program

Sistem Manajemen Data Film merupakan aplikasi terminal yang memungkinkan pengguna untuk:

- Menambahkan data film baru
- Melihat daftar film
- Mencari film berdasarkan beberapa kriteria
- Menghapus film
- Mengurutkan data film menggunakan berbagai algoritma sorting
- Menyimpan dan memuat data dari file

Program dibuat sebagai implementasi konsep struktur data dan algoritma pada bahasa pemrograman C++.

---

## 🏗️ Struktur Data

Program menggunakan `struct Film` sebagai record utama.

```cpp
struct Film {
    int    id;
    string judul;
    string genre;
    string sutradara;
    int    tahun;
    float  rating;
};
```

### Atribut Film

| Field | Tipe Data | Keterangan |
|---------|---------|---------|
| id | int | ID unik film |
| judul | string | Judul film |
| genre | string | Genre film |
| sutradara | string | Nama sutradara |
| tahun | int | Tahun rilis |
| rating | float | Rating film (0–10) |

---

## ⚙️ Fitur Program

### 1. Tambah Film
Menambahkan data film baru dengan ID yang dibuat otomatis.

### 2. Lihat Daftar Film
Menampilkan seluruh data film yang tersimpan.

### 3. Cari Film (Sequential Search)
Pencarian dapat dilakukan berdasarkan:

- Judul
- Genre
- Sutradara
- Tahun Rilis

### 4. Hapus Film
Menghapus data film berdasarkan judul yang dimasukkan pengguna.

### 5. Simpan & Muat Data
Menggunakan file:

```txt
data_film.txt
```

Data akan otomatis:

- Disimpan setelah penambahan film
- Disimpan setelah penghapusan film
- Dimuat saat program dijalankan

---
