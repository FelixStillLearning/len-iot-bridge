#include <iostream>
#include <string>

class Pekerja {
protected:
  int id_pekerja;
  std::string nama_pekerja;

public:
  Pekerja(int id, std::string nama) {
    id_pekerja = id;
    nama_pekerja = nama;

    std::cout << "pekerja baru telah terdaftar dengan nama : " << nama_pekerja
              << std::endl;
  }

  void bekerja() {
    std::cout << "pekerja dengan nama : " << nama_pekerja << "sedang bekerja"
              << std::endl;
  }

  void ingfo_pekerja() {
    std::cout << " nama pekerja : " << nama_pekerja << std::endl;
    std::cout << "memiliki iD: " << id_pekerja << std::endl;
  }
};

class Pelajar {
protected:
  int nisn;
  std::string tingkat;

public:
  Pelajar(int nisn, std::string tingkat) {
    this->nisn = nisn;
    this->tingkat = tingkat;

    std::cout << "pelajar baru :" << this->nisn << "telah terdaftar"
              << std::endl;
  }
  void belajar() {
    std::cout << "pelajar dengan nisn : " << this->nisn << "sedang belajar"
              << std::endl;
  }

  void ingfo_pelajar() {
    std::cout << "nisn pelajar : " << this->nisn << std::endl;
    std::cout << "tingkat : " << this->tingkat << std::endl;
  }
};

class PekerjaPelajar : public Pelajar, public Pekerja {
private:
  std::string status_kerja;

public:
  PekerjaPelajar(int id_kantor, std::string nama_pekerja_input, int nisn_siswa,
                 std::string tingkat_input, std::string status_input)
      : Pelajar(nisn_siswa, tingkat_input),
        Pekerja(id_kantor, nama_pekerja_input) {
    this->status_kerja = status_input;
  }

  void tampilkan_profil_lengkap() {
    ingfo_pekerja();
    ingfo_pelajar();
    std::cout << "status kerja: " << this->status_kerja << std::endl;
    std::cout << "nisnnya: " << this->nisn << std::endl;
  }
};

int main() {
  PekerjaPelajar Pelakar1(10, "felix", 10020, "tiga", "aktif");
  Pelakar1.tampilkan_profil_lengkap();
}
