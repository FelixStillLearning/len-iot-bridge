#include <iostream>
#include <ostream>
#include <string>

class KueUlangTahun {
private:
  std::string rasa_kue, ukuran_kue, tulisan_di_kue;
  int jumlah_lilin;

public:
  KueUlangTahun() {
    rasa_kue = "vanilla";
    ukuran_kue = "sedang";
    tulisan_di_kue = "selamat ulang tahun";

    std::cout << "kue default dibuat dengan rasa: " << rasa_kue
              << " ukuran: " << ukuran_kue << std::endl;
  }
  KueUlangTahun(std::string rasa) {
    rasa_kue = rasa;
    ukuran_kue = "sedang";
    tulisan_di_kue = "selamat ulang tahun";
    jumlah_lilin = 1;

    std::cout << "kue dengan rasa: " << rasa_kue
              << " ukuran standart sudah dibuat " << std::endl;
  }
  KueUlangTahun(std::string rasa, std::string ukuran, std::string tulisan,
                int lilin) {
    rasa_kue = rasa;
    ukuran_kue = ukuran;
    tulisan_di_kue = tulisan;
    jumlah_lilin = lilin;

    std::cout << "rasa: " << rasa_kue << "ukuran_kue : " << ukuran_kue
              << "tulisan : " << tulisan_di_kue
              << "dan jumlah lilin : " << jumlah_lilin << "sudah dibuat"
              << std::endl;
  }

  void tampilkan_info_kue() const {
    std::cout << "rasa: " << rasa_kue << "ukuran_kue : " << ukuran_kue
              << "tulisan : " << tulisan_di_kue
              << "dan jumlah lilin : " << jumlah_lilin << std::endl;
  }
};

int main() {
  KueUlangTahun kue_pertama;
  kue_pertama.tampilkan_info_kue();

  KueUlangTahun kue_kedua("Strawberry");
  kue_kedua.tampilkan_info_kue();

  KueUlangTahun kue_ketiga("Coklat", "besar", "Smeoga panjang umur", 10);
  kue_ketiga.tampilkan_info_kue();

  return 0;
}
