#include <iostream>
#include <fstream>
using namespace std;

const int    MAX_FILM  = 100;
const string NAMA_FILE = "data_film.txt"; // File utama

struct Film {
    int    id;
    string judul;
    string genre;
    string sutradara;
    int    tahun;
    float  rating;
};

Film daftarFilm[MAX_FILM];
int  jumlahFilm = 0;

//UI
void cetakGaris() {
    cout << "============================================================\n";
}

void cetakJudul(const string& teks) {
    cetakGaris();
    cout << "  " << teks << "\n";
    cetakGaris();
}

//  FILE I/O
void simpanKeFile() {
    ofstream file(NAMA_FILE);
    if (!file.is_open()) {
        cout << "[ERROR] Gagal membuka file untuk menulis!\n";
        return;
    }
    for (int i = 0; i < jumlahFilm; i++) {
        file << daftarFilm[i].id        << "\n"
             << daftarFilm[i].judul     << "\n"
             << daftarFilm[i].genre     << "\n"
             << daftarFilm[i].sutradara << "\n"
             << daftarFilm[i].tahun     << "\n"
             << daftarFilm[i].rating    << "\n"
             << "---\n";
    }
    file.close();
    cout << "[INFO] Data berhasil disimpan ke '" << NAMA_FILE
         << "'. Total: " << jumlahFilm << " film.\n";
}

void simpanKeFileCustom(const string& namaFileTujuan){
    ofstream file(namaFileTujuan);
    if (!file.is_open()){
        cout << "[ERROR] Gagal membuka file '" << namaFileTujuan << "' untuk menulis!\n";
        return; 
    }
    for(int i = 0; i < jumlahFilm; i++){
        file << daftarFilm[i].id        << "\n"
             << daftarFilm[i].judul     << "\n"
             << daftarFilm[i].genre     << "\n"
             << daftarFilm[i].sutradara << "\n"
             << daftarFilm[i].tahun     << "\n"
             << daftarFilm[i].rating    << "\n"
             << "---\n";
    }
    file.close();
    cout << "[INFO] Data terurut berhasil disimpan ke '"
         << namaFileTujuan << "'. Total: " << jumlahFilm << " film.\n"; 
    }

// Fungsi untuk meminta input nama file dari user setelah sorting
// Mengembalikan string nama file yang sudah pasti berekstensi .txt
string mintaNamaFileSorting(const string& kriteria) {
    string namaFile;
    cout << "\n============================================================\n";
    cout << "  SIMPAN HASIL SORTING\n";
    cout << "============================================================\n";
    cout << "  Data sudah diurutkan berdasarkan " << kriteria << ".\n";
    cout << "  File utama    : " << NAMA_FILE << " (data asli, tidak diubah)\n";
    cout << "\n  Masukkan nama file untuk menyimpan hasil sorting\n";
    cout << "  (contoh: sorted_judul.txt)\n";
    cout << "  Nama file: ";
    cin.ignore();
    getline(cin, namaFile);

    // Tambahkan ekstensi .txt otomatis jika user tidak mengetikkannya
    // Cek apakah 4 karakter terakhir sudah ".txt"
    if (namaFile.size() < 4 || namaFile.substr(namaFile.size() - 4) != ".txt"){
        namaFile += ".txt"; // otomatis tambahkan .txt
    }
    
    return namaFile;
}  

void muatDariFile() {
    ifstream file(NAMA_FILE);
    if (!file.is_open()) {
        cout << "[INFO] File '" << NAMA_FILE
             << "' belum ada. Memulai dengan data kosong.\n";
        return;
    }
    jumlahFilm = 0;
    string pemisah;
    while (jumlahFilm < MAX_FILM) {
        Film f;                                // variabel sementara
        string idStr, tahunStr, ratingStr;     // variabel sementara
        if (!getline(file, idStr))       break;
        if (!getline(file, f.judul))     break;
        if (!getline(file, f.genre))     break;
        if (!getline(file, f.sutradara)) break;
        if (!getline(file, tahunStr))    break;
        if (!getline(file, ratingStr))   break;
        getline(file, pemisah);          // baca "---"

        f.id     = stoi(idStr);         // string to int
        f.tahun  = stoi(tahunStr);      // string to int
        f.rating = stof(ratingStr);     // string to float
        daftarFilm[jumlahFilm++] = f;   // disimpan ke array
    }
    file.close();
    cout << "[INFO] " << jumlahFilm
         << " data film berhasil dimuat dari '" << NAMA_FILE << "'.\n";
}

//  GENERATE ID OTOMATIS
int generateId() {
    int maxId = 0;
    for (int i = 0; i < jumlahFilm; i++)
        if (daftarFilm[i].id > maxId) maxId = daftarFilm[i].id;
    return maxId + 1;
}

//  TAMBAH FILM
void tambahFilm() {
    cetakJudul("TAMBAH FILM BARU");
    if (jumlahFilm >= MAX_FILM) {
        cout << "[ERROR] Database penuh! Maksimal " << MAX_FILM << " film.\n";
        return;
    }
    Film f;                     // variabel sementara untuk kerapihan code.
    f.id = generateId();
    cout << "  ID Film (otomatis) : " << f.id << "\n\n";

    cout << "  Judul Film         : "; 
    cin.ignore(); getline(cin, f.judul);
    cout << "  Genre              : "; 
    getline(cin, f.genre);
    cout << "  Sutradara          : "; 
    getline(cin, f.sutradara);
    cout << "  Tahun Rilis        : "; cin >> f.tahun;
    cout << "  Rating (0.0-10.0)  : "; cin >> f.rating;

    if (f.rating < 0.0f)  f.rating = 0.0f;      // batasan nilai rating
    if (f.rating > 10.0f) f.rating = 10.0f;

    daftarFilm[jumlahFilm++] = f;
    cout << "\n[SUKSES] Film '" << f.judul << "' berhasil ditambahkan!\n";
    simpanKeFile();
}

//  LIHAT DAFTAR & DETAIL
void lihatDaftarFilm() {
    cetakJudul("DAFTAR FILM");
    if (jumlahFilm == 0) {
        cout << "  [INFO] Belum ada data film.\n";
        cetakGaris();
        return;
    }
    for (int i = 0; i < jumlahFilm; i++) {
        cout << "  " << (i + 1)
             << ". [ID:" << daftarFilm[i].id << "] "
             << daftarFilm[i].judul
             << " (" << daftarFilm[i].tahun << ")"
             << " - " << daftarFilm[i].genre
             << " | Rating: " << daftarFilm[i].rating << "/10."
             << " | Sutradara: " << daftarFilm[i].sutradara << endl;
    }
    cout << "\n  Total film: " << jumlahFilm << "\n";
    cetakGaris();
}

void detailFilm(const Film& f) {
    cetakGaris();
    cout << "  ID        : " << f.id        << "\n";
    cout << "  Judul     : " << f.judul     << "\n";
    cout << "  Genre     : " << f.genre     << "\n";
    cout << "  Sutradara : " << f.sutradara << "\n";
    cout << "  Tahun     : " << f.tahun     << "\n";
    cout << "  Rating    : " << f.rating    << " / 10\n";
    cetakGaris();
}

// Selection Sort – Judul A-Z
// Cara kerja: Setiap iterasi, cari elemen dengan judul terkecil
// dari posisi i hingga akhir, lalu tukar dengan posisi i.
void selectionSortJudul() {
    int n = jumlahFilm;
    for (int i = 0; i < n - 1; i++) {
        // elemen ke-i adalah yang terkecil
        int minIdx = i;
        // mencari elemen dengan judul terkecil di sisa array
        for (int j = i + 1; j < n; j++) {
            if (daftarFilm[j].judul < daftarFilm[minIdx].judul)
                minIdx = j;
        }
        // menukar elemen terkecil yang ditemukan ke posisi i
        if (minIdx != i) {
            Film temp          = daftarFilm[i];
            daftarFilm[i]      = daftarFilm[minIdx];
            daftarFilm[minIdx] = temp;
        }
    }
}

// Insertion Sort – Tahun terbaru ke terlama
// Cara kerja: Ambil elemen ke-i, geser semua elemen sebelumnya
// yang lebih kecil ke kanan, lalu sisipkan elemen ke posisi yang tepat.
void insertionSortTahun() {
    int n = jumlahFilm;
    for (int i = 1; i < n; i++) {
        Film key = daftarFilm[i]; // menymimpan elemen yang akan disisipkan
        int  j   = i - 1;
        // geser elemen yang tahunnya lebih kecil (lebih lama) ke kanan
        while (j >= 0 && daftarFilm[j].tahun < key.tahun) {
            daftarFilm[j + 1] = daftarFilm[j];
            j--;
        }
        // sisipkan elemen ke posisi yang tepat
        daftarFilm[j + 1] = key;
    }
}

// Bubble Sort – Rating tertinggi ke terendah
// Cara kerja: Bandingkan dua elemen berdampingan, tukar jika
// urutan salah. Ulangi hingga tidak ada pertukaran (array terurut).
void bubbleSortRating() {
    int  n        = jumlahFilm;
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        // Setiap pass, elemen terkecil "gelembung" ke akhir
        for (int j = 0; j < n - 1 - i; j++) {
            // Tukar jika rating kiri lebih kecil dari kanan
            if (daftarFilm[j].rating < daftarFilm[j + 1].rating) {
                Film temp        = daftarFilm[j];
                daftarFilm[j]    = daftarFilm[j + 1];
                daftarFilm[j + 1] = temp;
                swapped = true;
            }
        }
        // Optimasi: hentikan jika tidak ada pertukaran di pass ini
        if (!swapped) break;
    }
}

// Shell Sort – Sutradara A-Z
// Cara kerja: Versi penyempurnaan Insertion Sort dengan gap awal n/2,
// lalu gap diperkecil setengahnya setiap iterasi hingga gap = 1.
// Elemen yang jauh bisa berpindah lebih cepat dibanding Insertion Sort biasa.
void shellSortSutradara() {
    int n = jumlahFilm;
    // Mulai dengan gap besar, kecilkan hingga gap = 1
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // Lakukan insertion sort untuk elemen berjarak 'gap'
        for (int i = gap; i < n; i++) {
            Film temp = daftarFilm[i]; // Elemen yang akan disisipkan
            int  j    = i;
            // Geser elemen ke kanan selama sutradara elemen di kiri
            // lebih besar dari temp.sutradara
            while (j >= gap && daftarFilm[j - gap].sutradara > temp.sutradara) {
                daftarFilm[j] = daftarFilm[j - gap];
                j -= gap;
            }
            daftarFilm[j] = temp;
        }
    }
}

//  Menu Sorting
void urutkanFilm() {
    cetakJudul("URUTKAN FILM");
    if (jumlahFilm == 0){
        cout << "  [INFO] Belum ada data film.\n";
        return;
    }
    cout << "  Pilih kriteria pengurutan:\n";
    cout << "  [1] Judul (A-Z)                  -- Selection Sort\n";
    cout << "  [2] Tahun Rilis (terbaru-terlama) -- Insertion Sort\n";
    cout << "  [3] Rating (tertinggi-terendah)   -- Bubble Sort\n";
    cout << "  [4] Sutradara (A-Z)               -- Shell Sort\n";
    cout << "\n  Pilihan: ";

    int pilih;
    cin >> pilih;

    string kriteria; // label pada user
    

    switch (pilih) {
        case 1:
            selectionSortJudul();
            kriteria = "Judul A-Z (Selection Sort)";
            cout << "\n[SUKSES] Film diurutkan berdasarkan " << kriteria << ".\n";
            break;
        case 2:
            insertionSortTahun();
            kriteria = "Tahun terbaru (Insertion Sort)";
            cout << "\n[SUKSES] Film diurutkan berdasarkan " << kriteria << ".\n";
            break;
        case 3:
            bubbleSortRating();
            kriteria = "Rating tertinggi (Bubble Sort)";
            cout << "\n[SUKSES] Film diurutkan berdasarkan " << kriteria << ".\n";
            break;
        case 4:
            shellSortSutradara();
            kriteria = "Sutradara A-Z (Shell Sort)";
            cout << "\n[SUKSES] Film diurutkan berdasarkan " << kriteria << ".\n";
            break;
        default:
            cout << "\n[ERROR] Pilihan tidak valid.\n";
            return; // keluar tanpa menyimpan apapun
    }

    // Melihat daftah hasil sorting
    lihatDaftarFilm();

    // minta nama file custom, terus simpan ke file tsb
    string namaFileSorted = mintaNamaFileSorting(kriteria);
    simpanKeFileCustom(namaFileSorted); // simpan ke file kustom hasil sorting

    // Beri tahu user perbedaan kedua file
    cout << "\n  Ringkasan file:\n";
    cout << "  [ASLI]   " << NAMA_FILE    << "  data asli (urutan input)\n";
    cout << "  [SORTED] " << namaFileSorted << "  data terurut (" << kriteria << ")\n";
    cetakGaris();

}

// Sequential Search
void cariFilm() {
    cetakJudul("CARI FILM (Sequential Search)");
    if (jumlahFilm == 0) {
        cout << "  [INFO] Belum ada data film.\n";
        return;
    }
    cout << "  Cari berdasarkan:\n";
    cout << "  [1] Judul\n";
    cout << "  [2] Genre\n";
    cout << "  [3] Sutradara\n";
    cout << "  [4] Tahun\n";
    cout << "\n  Pilihan: ";

    int pilih;
    cin >> pilih;
    cin.ignore();

    string kataCari;
    int    tahunCari = 0;

    if (pilih == 4) {
        cout << "  Masukkan tahun: ";
        cin >> tahunCari;
    } else {
        cout << "  Masukkan kata kunci: ";
        getline(cin, kataCari);
    }

    int  ditemukan = 0;
    bool hasilIdx[MAX_FILM] = {};

    for (int i = 0; i < jumlahFilm; i++) {
        bool cocok = false;
        if      (pilih == 1 && daftarFilm[i].judul     == kataCari)  cocok = true;
        else if (pilih == 2 && daftarFilm[i].genre     == kataCari)  cocok = true;
        else if (pilih == 3 && daftarFilm[i].sutradara == kataCari)  cocok = true;
        else if (pilih == 4 && daftarFilm[i].tahun     == tahunCari) cocok = true;

        if (cocok){ 
            hasilIdx[i] = true; ditemukan++;
        }
    }

    cout << "\n";
    if (ditemukan == 0) {
        cout << "  [INFO] Film tidak ditemukan.\n";
    } else {
        cout << "  Ditemukan " << ditemukan << " film:\n\n";
        cetakGaris();
        for (int i = 0; i < jumlahFilm; i++) {
            if (hasilIdx[i]) {
                cout << "  [ID:" << daftarFilm[i].id << "] "
                     << daftarFilm[i].judul
                     << " (" << daftarFilm[i].tahun << ")"
                     << " - " << daftarFilm[i].genre
                     << " | Rating: " << daftarFilm[i].rating << "/10" << endl;
            }
        }
        cetakGaris();
        if (ditemukan == 1) {
            for (int i = 0; i < jumlahFilm; i++) {
                if (hasilIdx[i]) {
                    cout << "\n  Detail Film:\n";
                    detailFilm(daftarFilm[i]);
                }
            }
        }
    }
}

//  HAPUS FILM BERDASARKAN JUDUL (FITUR BARU)
// Cara kerja: Cari film yang judulnya sesuai input (sequential search),
// lalu geser semua elemen sesudahnya ke kiri untuk menutup "lubang",
// kemudian kurangi jumlahFilm sebanyak film yang dihapus.
void hapusFilm() {
    cetakJudul("HAPUS FILM");
    if (jumlahFilm == 0) {
        cout << "  [INFO] Belum ada data film.\n";
        return;
    }

    cout << "  Masukkan judul film yang ingin dihapus: ";
    cin.ignore();
    string judulCari;
    getline(cin, judulCari);

    // Tahap 1: Cari semua film yang judulnya cocok dan tampilkan
    int ditemukan = 0;
    for (int i = 0; i < jumlahFilm; i++) {
        if (daftarFilm[i].judul == judulCari) {
            if (ditemukan == 0) {
                cout << "\n  Film yang akan dihapus:\n";
                cetakGaris();
            }
            detailFilm(daftarFilm[i]);
            ditemukan++;
        }
    }

    // Jika tidak ditemukan, batalkan proses
    if (ditemukan == 0) {
        cout << "\n  [INFO] Film dengan judul '" << judulCari << "' tidak ditemukan.\n";
        return;
    }

    // Tahap 2: Konfirmasi penghapusan dari user
    cout << "\n  Ditemukan " << ditemukan << " film dengan judul tersebut.\n";
    cout << "  Yakin ingin menghapus? (y/n): ";
    char konfirmasi;
    cin >> konfirmasi;

    if (konfirmasi != 'y' && konfirmasi != 'Y') {
        cout << "\n  [INFO] Penghapusan dibatalkan.\n";
        return;
    }

    // Tahap 3: Hapus film dengan menggeser elemen array ke kiri
    int jumlahDihapus = 0;
    for (int i = 0; i < jumlahFilm; i++) {
        if (daftarFilm[i].judul == judulCari) {
            // Geser semua elemen sesudah indeks i ke kiri satu posisi
            for (int j = i; j < jumlahFilm - 1; j++) {
                daftarFilm[j] = daftarFilm[j + 1];
            }
            jumlahFilm--;   // Kurangi total film
            jumlahDihapus++;
            i--;            // Periksa ulang indeks i karena array sudah digeser
        }
    }

    cout << "\n[SUKSES] " << jumlahDihapus << " film berhasil dihapus.\n";
    simpanKeFile();
}

// Menu Utama
void tampilkanMenu() {
    cetakGaris();
    cout << "     SISTEM MANAJEMEN DATA FILM\n";
    cetakGaris();
    cout << "  [1] Tambah Film Baru\n";
    cout << "  [2] Lihat Daftar Film\n";
    cout << "  [3] Urutkan Film\n"; 
    cout << "  [4] Cari Film\n";
    cout << "  [5] Hapus Film\n";
    // cout << "  [6] Simpan ke File\n"; // Tambah: opsi simpan dipindah ke [6]
    cout << "  [6] Keluar\n";
    cetakGaris();
    cout << "  Pilihan: ";
}

int main() {
    cout << "\n";
    cetakGaris();
    cout << "  Selamat datang di Sistem Manajemen Data Film\n";
    cetakGaris();

    muatDariFile();

    int pilihan;
    do {
        cout << "\n";
        tampilkanMenu();
        cin >> pilihan;
        cout << "\n";
        switch (pilihan) {
            case 1: {
                tambahFilm();
                break;
            }
            case 2: {
                lihatDaftarFilm();
                break;
            }
            case 3: {
                urutkanFilm();
                break;
            }
            case 4: {
                cariFilm();
                break;
            }
            case 5: {
                hapusFilm();    // Ganti: semula simpanKeFile()
                break;
            }
            // case 6: {
            //     simpanKeFile(); // Tambah: case baru untuk simpan ke file
            //     break;
            // }
            case 6: {
                cetakGaris();
                cout << "  Terima kasih! Program selesai.\n";
                cetakGaris();
                break;
            }
            default:
                cout << "  [ERROR] Pilihan tidak valid. Coba lagi.\n";
        }
    } while (pilihan != 6);
    return 0;
}