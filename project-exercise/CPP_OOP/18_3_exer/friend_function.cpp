#include <iostream>
#include <ostream>
#include <string>

class Lingkaran {
private:
  double jari_jari;
  std::string warna_lingkaran;

public:
  Lingkaran(double jari, std::string warna) {
    jari_jari = jari;
    warna_lingkaran = warna;

    std::cout << "Lingkaran dengan warna: " << warna_lingkaran
              << "dengan jari - jari" << jari_jari << " telah di buat"
              << std::endl;
  }
  double info_jari_jari() const { return jari_jari; }

  std::string info_warna_lingkaran() const { return warna_lingkaran; }

  double hitung_luas() const { return 3.14159 * jari_jari * jari_jari; }

  friend void tampilkan_info_lengkap(const Lingkaran &lingkaran);
  friend double hitung_keliling(const Lingkaran &lingkaran);
  friend bool apakah_lebih_besar(const Lingkaran &lingkaran_satu,
                                 const Lingkaran &lingkaran_idua);
};

void tampilkan_info_lengkap(const Lingkaran &Lingkaran) {
  std::cout << "warna: " << Lingkaran.warna_lingkaran << std::endl;
  std::cout << "jari-jari: " << Lingkaran.jari_jari << " cm " << std::endl;
  std::cout << "luas: " << 3.14159 * Lingkaran.jari_jari * Lingkaran.jari_jari
            << " cm kuadrat " << std::endl;
}

double hitung_keliling(const Lingkaran &lingkaran) {
  return 2 * 3.14159 * lingkaran.jari_jari;
}

bool apakah_lebih_besar(const Lingkaran &lingkaran_satu,
                        const Lingkaran &lingkaran_dua) {
  return lingkaran_satu.info_jari_jari() > lingkaran_dua.info_jari_jari();
}

int main() {
  Lingkaran lingkaran_pertama(3.4, "biru");
  Lingkaran lingkaran_kedua(2.5, "hijau");

  tampilkan_info_lengkap(lingkaran_pertama);

  std::cout << "keliling nya adalah: " << hitung_keliling(lingkaran_pertama)
            << std::endl;

  if (apakah_lebih_besar(lingkaran_pertama, lingkaran_kedua)) {
    std::cout << "Lingkaran biru lebih besar daripada lingkaran hijau"
              << std::endl;
  } else {
    std::cout << "Lingkaran hijau lebih besar daripada lingkaran biru"
              << std::endl;
  }

  std::cout << "lingkaran biru > lingkaran kuning"
            << apakah_lebih_besar(lingkaran_pertama, lingkaran_kedua)
            << std::endl;
  return 0;
}
