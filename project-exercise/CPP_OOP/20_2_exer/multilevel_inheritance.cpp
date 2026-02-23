#include <iostream>
#include <string>
#include <system_error>

class MakhlukHidup {
protected:
  std::string nama_makhluk;
  int usia_makhluk;

public:
  MakhlukHidup(std::string nama, int usia) {
    nama_makhluk = nama;
    usia_makhluk = usia;
  }

  void Bernafas() {
    std::cout << "MakhlukHidup dengan nama " << nama_makhluk
              << "Sedang Bernafas" << std::endl;
  }
};

class Manusia : public MakhlukHidup {
protected:
  std::string pekerjaan_manusia;

public:
  Manusia(std::string nama, int usia, std::string pekerjaan)
      : MakhlukHidup(nama, usia) {
    pekerjaan_manusia = pekerjaan;
  }

  void bekerja() { std::cout << nama_makhluk << "sedang bekerja" << std::endl; }
};

class Programmer : public Manusia {
protected:
  std::string bahasa_pemrograman;

public:
  Programmer(std::string nama, int usia, std::string pekerjaan,
             std::string bahasa)
      : Manusia(nama, usia, pekerjaan) {
    bahasa_pemrograman = bahasa;
  }

  void Mengoding() {
    std::cout << nama_makhluk << "sedang mengoding" << std::endl;
  }
};

int main() {
  Programmer prog1("felix", 21, "programmer", "cpp");

  prog1.Bernafas();
  prog1.bekerja();
  prog1.Mengoding();
}
