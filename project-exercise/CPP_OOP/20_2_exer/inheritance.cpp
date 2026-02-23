#include <iostream>
#include <string>

class Manusia {
protected:
  std::string nama_manusia;
  int umur_manusia;

public:
  Manusia(std::string nama, int umur) {
    nama_manusia = nama;
    umur_manusia = umur;

    std::cout << "Manusia baru telah lahir dengan nama: " << nama_manusia
              << "dengan umur: " << umur_manusia << std::endl;
  }
  void Makan() {
    std::cout << "manusia bernama " << nama_manusia << "sedang makan"
              << std::endl;
  }

  void ingpo_manusia() {
    std::cout << "nama : " << nama_manusia << " usianya : " << umur_manusia
              << "tahun " << std::endl;
  }
};

class Orangtua : public Manusia {
private:
  std::string warna_rambut;

public:
  Orangtua(std::string nama, int umur, std::string warna)
      : Manusia(nama, umur) {
    warna_rambut = warna;
  }

  void pikun() {
    std::cout << "manusia yang bernama: " << nama_manusia << "kembali pikun"
              << std::endl;
  }

  void tampilkan_ingfo_orangtua() {
    ingpo_manusia();
    std::cout << "warna rambut nya adalah " << warna_rambut << std::endl;
  }
};

int main() {
  Orangtua manusia_pertama("felix", 15, "putih");
  manusia_pertama.ingpo_manusia();
  manusia_pertama.tampilkan_ingfo_orangtua();
  manusia_pertama.pikun();
}
