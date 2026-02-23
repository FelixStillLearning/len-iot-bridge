#include <iostream>
#include <string>

class RekeningBank {
public:
  RekeningBank(std::string nomor, std::string nama, double saldo_awal,
               int pin) {
    nomor_rekening = nomor;
    nama_pemilik = nama;
    saldo_rekening = saldo_awal;
    pin_keamanan = pin;
  }

  void tukar_pin(int pin_lama, int pin_baru) {
    if (pin_lama == pin_keamanan) {
      pin_keamanan = pin_baru;
      std::cout << "pin berhasil diganti" << std::endl;
    } else {
      std::cout << "pin salah, gagal untuk tukar pin" << std::endl;
    }
  }

  void setor_uang(double jumlah) {
    if (jumlah > 0) {
      saldo_rekening += jumlah;
      std::cout << "setor tunai Rp." << jumlah << " berhasil" << std::endl;
    } else {
      std::cout << "jumlah setor uang tidak valid" << std::endl;
    }
  }

  void tarik_uang(double jumlah, int pin) {
    if (pin != pin_keamanan) {
      std::cout << "pin salah, transaksi tari uang gagal" << std::endl;
      return;
    }

    if (jumlah <= 0) {
      std::cout << "jumlah tarik uang tidak valid" << std::endl;
      return;
    }

    if (jumlah > saldo_rekening) {
      std::cout << "saldo tidak mencukupi, karena saldo anda adalah: "
                << saldo_rekening << std::endl;
      return;
    }

    saldo_rekening -= jumlah;
    std::cout << "penarikan tunai seharga: Rp." << jumlah << " berhasil"
              << std::endl;
  }

  void tampilin_info() const {
    std::cout << "pemilik: " << nama_pemilik << std::endl;
    std::cout << "saldo: Rp." << saldo_rekening << std::endl;
  }

  double ambil_saldo_rekening() const { return saldo_rekening; }

private:
  std::string nomor_rekening, nama_pemilik;
  double saldo_rekening;
  int pin_keamanan;
};

int main() {
  RekeningBank rekening_arfy("788-333-000", "arfy slowy", 500'000, 1234);

  rekening_arfy.tampilin_info();
  rekening_arfy.setor_uang(45'000);
  std::cout << "saldo rekening sekaran adalah: "
            << rekening_arfy.ambil_saldo_rekening() << std::endl;
  rekening_arfy.tarik_uang(350'000, 1234);
  std::cout << "saldo sekarang adalah: " << rekening_arfy.ambil_saldo_rekening()
            << std::endl;

  return 0;
}
