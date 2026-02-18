#include <future>
#include <iostream>
#include <string>

class Produk {
private:
  std::string nama_produk;
  double harga_produk;
  int jumlah_produk;

public:
  Produk(std::string nama_produk, double harga_produk, int jumlah_produk) {
    this->nama_produk = nama_produk;
    this->harga_produk = harga_produk;
    this->jumlah_produk = jumlah_produk;
    std::cout << "produk baru berhasil ditambahkan : " << this->nama_produk
              << "dengan jumlah : " << this->jumlah_produk
              << "dan harga : " << this->harga_produk << std::endl;
  }
  Produk &atur_nama(std::string nama_produk) {
    this->nama_produk = nama_produk;
    std::cout << "nama produk telah diubah menjadi: " << this->nama_produk
              << std::endl;
    return *this;
  }
  void tampilkan_info_produk() {
    std::cout << "nama produk : " << this->nama_produk << std::endl;
    std::cout << "harga produk : " << this->harga_produk << std::endl;
    std::cout << "jumlah produk : " << this->jumlah_produk << std::endl;
    std::cout << "lokasi objek berada di : " << this << std::endl;
  }

  bool apakah_harga_sama(const Produk &produk_lain) {
    return this->harga_produk == produk_lain.harga_produk;
  }
};
int main() {
  Produk Laptop("Lenovo thinkpad", 15'000, 20);
  Laptop.tampilkan_info_produk();

  Produk SmartPhone("Samsung Galazy", 16'000, 10);
  SmartPhone.tampilkan_info_produk();

  if (Laptop.apakah_harga_sama(SmartPhone)) {
    std::cout << "harga laptop dan smartphone sama " << std::endl;

  } else {
    std::cout << "harga laptop dan smartphone tidak sama " << std::endl;
  }

  Laptop.atur_nama("Lenovo Ideapad Slim 5i");
  return 0;
}
