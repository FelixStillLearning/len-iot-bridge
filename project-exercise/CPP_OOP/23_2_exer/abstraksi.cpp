#include <iostream>
#include <string>

class ALatPembayaran {
public:
  virtual void bayar(double jumlah_uang) = 0;

  virtual void tampilkan_info() {
    std::cout << "menampilkan informasi pembayaran " << std::endl;
  }

  virtual ~ALatPembayaran() {
    std::cout << "Alat Pembayaran Selaesai digunakan" << std::endl;
  }
};

class Kartu_kredit : public ALatPembayaran {
private:
  std::string nama_bank;
  std::string nomor_kartu;
  double limit_kartu;
  double tagihan_kartu;

public:
  Kartu_kredit(std::string bank, std::string nomor, double limit) {
    nama_bank = bank;
    nomor_kartu = nomor;
    limit_kartu = limit;
    tagihan_kartu = 0;
  }

  void tampilkan_info() override {
    std::cout << "nama bank: " << nama_bank << std::endl;
    std::cout << "kartu: " << nomor_kartu << std::endl;
  }

  void bayar(double jumlah_uang) override {
    if (jumlah_uang + tagihan_kartu <= limit_kartu) {
      tagihan_kartu += jumlah_uang;
      std::cout << "pembayaran sukses via bank " << nama_bank
                << "jumlah_uang: Rp." << jumlah_uang << "ditagihkan ke: Rp."
                << tagihan_kartu << std::endl;

    } else {
      std::cout << "gagal, melebihi kapasitas limit kartu " << std::endl;
    }
  }
};

int main() {
  ALatPembayaran *kartu_kredit =
      new Kartu_kredit("FelixJuraganUdang", "1273457", 20'000);

  kartu_kredit->bayar(500000);
  kartu_kredit->tampilkan_info();

  delete kartu_kredit;

  return 0;
}
