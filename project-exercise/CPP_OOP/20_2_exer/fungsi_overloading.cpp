#include <iostream>
#include <string>

class Kalkulator {
public:
  Kalkulator() { nilai_default = 0; }

  int tambah(int angka1, int angka2) {
    int hasil = angka1 + angka2;
    return hasil;
  }

  int tambah(int angka1, int angka2, int angka3) {
    int hasil = angka1 + angka2 + angka3;
    return hasil;
  }

  double tambah(double angka1, double angka2) {
    double hasil = angka1 + angka2;
    return hasil;
  }

  int tambah(int angka) {
    int hasil = angka + nilai_default;
    return hasil;
  }

  double tambah(double angka) {
    double hasil = angka + double(nilai_default);
    return hasil;
  }

  void info_kalkulator(std::string pesan) {
    std::cout << "pesan dari kalulator: " << pesan << std::endl;
  }

  void atur_nilai_default(int nilai) { nilai_default = nilai; }

private:
  int nilai_default;
};

int main() {

  Kalkulator kalkulator_kita;
  kalkulator_kita.atur_nilai_default(5);

  std::cout << "5 + 3 adalah: " << kalkulator_kita.tambah(5, 3) << std::endl;
  std::cout << "hasil dengan nilai default: " << kalkulator_kita.tambah(10)
            << std::endl;
  std::cout << "4.3 + 3.2 adalah: " << kalkulator_kita.tambah(4.3, 3.2)
            << std::endl;
  std::cout << "4 + 5 + 3 adalah: " << kalkulator_kita.tambah(4, 5, 3)
            << std::endl;

  return 0;
}
