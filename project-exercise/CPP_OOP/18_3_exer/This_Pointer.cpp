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
  void tampilkan_info_produk() {
    std::cout << "nama produk : " << this->nama_produk << std::endl;
    std::cout << "harga produk : " << this->harga_produk << std::endl;
    std::cout << "jumlah produk : " << this->jumlah_produk << std::endl;
    std::cout << "lokasi objek berada di : " << this << std::endl;
  }
};
int main() {
  Produk Laptop("Lenovo thinkpad", 15'000, 20);
  Laptop.tampilkan_info_produk();

  Produk SmartPhone("Samsung Galazy", 16'000, 10);
  SmartPhone.tampilkan_info_produk();

  return 0;
}
