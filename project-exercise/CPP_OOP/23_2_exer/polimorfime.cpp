#include <iostream>
#include <string>

class Kendaraan {
public:
  virtual void nyalakan() {
    std::cout << "Kendaran umum berhasil dinyalakan " << std::endl;
  }

  virtual ~Kendaraan() {
    std::cout << "Kendaraan umum berhasil dimatikan " << std::endl;
  }
};

class Mobil : public Kendaraan {
private:
  std::string Merek_mobil;
  int jumlah_tempat_duduk;

public:
  Mobil(std::string merek, int jumlah) {
    Merek_mobil = merek;
    jumlah_tempat_duduk = jumlah;
    std::cout << "Mobil dengan merek: " << Merek_mobil
              << "dengan tempat jumlah duduk " << jumlah_tempat_duduk
              << std::endl;
  }

  void nyalakan() override {
    std::cout << "Mobil dengan merek: " << Merek_mobil << "berhasil dinyalakan "
              << std::endl;
  }
};

int main() {

  Mobil *Kendaraan_pertama = new Mobil("subaru", 2);
  Mobil Kendaraan_kedua("avanza", 10);

  Kendaraan_pertama->nyalakan();
}
