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
## 🔍 Algoritma Searching

Program menggunakan:

### Sequential Search

Digunakan untuk mencari film berdasarkan:

- Judul
- Genre
- Sutradara
- Tahun

Kompleksitas:

```text
Best Case  : O(1)
Worst Case : O(n)
```

---

## 🔄 Algoritma Sorting

Program mengimplementasikan 4 algoritma sorting berbeda.

| Kriteria | Algoritma |
|-----------|-----------|
| Judul A-Z | Selection Sort |
| Tahun Terbaru → Terlama | Insertion Sort |
| Rating Tertinggi → Terendah | Bubble Sort |
| Sutradara A-Z | Shell Sort |

### Selection Sort
Mengurutkan film berdasarkan judul.

```text
Time Complexity: O(n²)
```

### Insertion Sort
Mengurutkan berdasarkan tahun rilis terbaru.

```text
Time Complexity:
Best Case  : O(n)
Worst Case : O(n²)
```

### Bubble Sort
Mengurutkan berdasarkan rating tertinggi.

```text
Time Complexity: O(n²)
```

### Shell Sort
Mengurutkan berdasarkan nama sutradara.

```text
Time Complexity: ± O(n log n)
```

---

## 💾 Format Penyimpanan File

Contoh isi file:

```txt
1
Interstellar
Sci-Fi
Christopher Nolan
2014
8.9
---
2
Inception
Sci-Fi
Christopher Nolan
2010
8.8
---
```

Tanda:

```txt
---
```

digunakan sebagai pemisah antar record film.

---

## 🖥️ Tampilan Menu

```text
============================================================
     SISTEM MANAJEMEN DATA FILM
============================================================
  [1] Tambah Film Baru
  [2] Lihat Daftar Film
  [3] Urutkan Film
  [4] Cari Film
  [5] Hapus Film
  [6] Keluar
============================================================
```

---

## 📂 Struktur Project

```text
📁 Sistem-Manajemen-Film
│
├── Proyek_123250038_123250024.cpp
├── data_film.txt
└── README.md
```

---

## 🚀 Cara Menjalankan Program

### Compile

```bash
g++ Proyek_123250038_123250024.cpp -o film
```

### Run

```bash
./film
```

Untuk Windows:

```bash
film.exe
```

---

## 📚 Konsep yang Diimplementasikan

- Struct
- Array
- Function
- File Handling (ifstream & ofstream)
- Sequential Search
- Selection Sort
- Insertion Sort
- Bubble Sort
- Shell Sort
- CRUD Sederhana
- Generate ID Otomatis

---

## 🎯 Tujuan Proyek

Membangun sistem pengelolaan data film sederhana sebagai implementasi materi:

- Struktur Data
- Algoritma Sorting
- Algoritma Searching
- Pengolahan File
- Pemrograman C++

---

⭐ Jika repository ini bermanfaat, jangan lupa berikan star pada GitHub repository ini.
