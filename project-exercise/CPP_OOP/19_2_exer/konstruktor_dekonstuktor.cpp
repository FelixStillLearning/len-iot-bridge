#include <iostream>
#include <string>

class Buku {
private:
  std::string judul_buku;
  std::string penulis_buku;
  int tahun_terbit;
  static int jumlah_total_buku;

public:
  // constraktor default
  Buku() {
    judul_buku = "kosong";
    penulis_buku = "kosong";
    tahun_terbit = 0;
    jumlah_total_buku++;

    std::cout << "buku default sudah ditambahkan ke dalam sistem" << std::endl;
    std::cout << "total buku: " << jumlah_total_buku << std::endl;
  }
  // constructor untuk mengubah data
  Buku(std::string judul, std::string penulis, int tahun) {
    judul_buku = judul;
    penulis_buku = penulis;
    tahun_terbit = tahun;
    jumlah_total_buku++;

    std::cout << "Buku " << judul_buku << " oleh " << penulis_buku
              << " pada tahun terbit: " << tahun_terbit
              << " sudah didafatar kan" << std::endl;
    std::cout << "jumlah total buku sekrang adalah : " << jumlah_total_buku
              << std::endl;
  }

  // deskruktor atau penghancur class nya ketika sudah tidak lagi digunakan
  ~Buku() {
    std::cout << "buku" << judul_buku << "dihancurkan oleh memori" << std::endl;
    jumlah_total_buku--;
    std::cout << " total buku sekarang adalah ; " << jumlah_total_buku
              << std::endl;
  }
}
