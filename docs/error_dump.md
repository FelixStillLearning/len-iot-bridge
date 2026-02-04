## Error dan Solusi C++ Project Setup

### Error 1: CMake Tidak Mendeteksi GCC di WSL
VS Code CMake Tools hanya menampilkan Visual Studio compilers (Windows), tidak ada pilihan GCC 11.

Penyebab: Project dibuka dari Windows path bukan WSL path, VS Code belum terhubung ke WSL environment, CMake Tools belum scan ulang kompiler di WSL.

Fix:
1. Cek GCC: `gcc --version`
2. Buka project dari WSL: `cd folder && code .`
3. Scan ulang: Ctrl+Shift+P > CMake: Scan for Kits
4. Atau buat `.vscode/cmake-kits.json` dengan GCC 11 path `/usr/bin/gcc-11` dan `/usr/bin/g++-11`

### Error 2: Permission Denied saat Conan Generate
PermissionError: [Errno 13] Permission denied: 'cmakedeps_macros.cmake'

Penyebab: File di folder build dibuat dengan permission root, user biasa tidak bisa overwrite.

Fix:
```bash
sudo rm -rf build
conan install . --output-folder=build --build=missing
```

### Error 3: CMake Cannot Find CMakeLists.txt
CMake Error: The source directory does not appear to contain CMakeLists.txt

Penyebab: CMakeLists.txt tidak ada di folder yang dijalankan, atau kosong (0 bytes), atau menjalankan cmake di folder salah.

Fix:
1. Pastikan CMakeLists.txt ada di root folder project
2. Cek ukuran: `ls -lh CMakeLists.txt` (harus > 0 bytes)
3. Jika ada di subfolder (docker/), copy ke root: `cp docker/CMakeLists.txt ./`
4. Jalankan cmake dari folder yang benar

### Error 4: File .env Not Found
grep: .env: No such file or directory

Penyebab: File .env tidak ada di project (opsional).

Fix: Skip jika tidak ada, atau buat kosong dengan `touch .env`

### Workflow Benar untuk Setup C++ Project
```bash
cd ~/workspace/project-name
conan profile detect --force
conan install . --output-folder=build --build=missing
export $(grep -v '^#' .env | xargs) 2>/dev/null || true
cmake --preset conan-release
cmake --build build --config Release
./build/<executable-name>
```

---

## Error dan Solusi Environment Setup

### Error 5: WSL Tidak Bisa Dijalankan
WSL terbuka sebentar lalu tertutup otomatis.

Penyebab: WSL bukan aplikasi GUI, distro belum dijalankan dengan benar.

Fix: Install Ubuntu via Microsoft Store, jalankan lewat terminal `Ubuntu` atau `wsl`.

### Error 6: Cannot Stat cmake-3.31.3-linux-x86_64
mv: cannot stat 'cmake-3.31.3-linux-x86_64'

Penyebab: File .tar.gz belum diekstrak, typo path atau versi, path Windows dengan spasi sulit dibaca WSL.

Fix:
```bash
cd ~
wget https://github.com/Kitware/CMake/releases/download/v3.31.0/cmake-3.31.0-linux-x86_64.tar.gz
tar -xzvf cmake-3.31.0-linux-x86_64.tar.gz
sudo mv cmake-3.31.0-linux-x86_64 /usr/local/cmake
sudo ln -sf /usr/local/cmake/bin/* /usr/local/bin
hash -r
cmake --version
```

### Error 7: Externally-Managed-Environment
error: externally-managed-environment

Penyebab: Ubuntu 22.04+ melindungi Python sistem dari modifikasi langsung (PEP 668).

Fix:
```bash
sudo pip install conan --break-system-packages
```

### Error 8: Install Python dengan pip
Command salah: `sudo pip install python3`

Penyebab: Python adalah runtime OS-level, bukan package pip.

Fix:
```bash
sudo apt install python3
python3 --version
```

### Error 9: Conan Profile Already Exists
Profile already exists

Penyebab: Profile default sudah dibuat sebelumnya.

Fix:
```bash
conan profile detect --force
```

### Error 10: Conan Command Tidak Dikenali
conan profile show default
ERROR: Unrecognized arguments

Penyebab: Perbedaan CLI Conan 1.x vs 2.x.

Fix:
```bash
conan profile show --profile default
# atau
conan profile show
```

### Error 11: spawn cmake ENOENT
spawn /usr/local/bin/cmake ENOENT

Penyebab: VS Code dibuka dari Windows, CMake ada di WSL environment.

Fix:
```bash
cd ~/workspace/len-iot-bridge
code .
```

### Error 12: Terminal VS Code Menggunakan CMD
Prompt menunjukkan `C:\Windows>`, command `which` tidak dikenali.

Penyebab: Default terminal diset ke Command Prompt.

Fix: Klik dropdown terminal di VS Code > Select Default Profile > Ubuntu (WSL)

### Error 13: VS Code Security Prompt wsl.localhost
Popup "Allow host wsl.localhost?"

Penyebab: Akses pertama ke filesystem WSL dari VS Code.

Fix: Centang "Permanently allow" dan klik "Allow"

### Error 14: Program Does Not Exist saat Debug
program ... Classobject.exe does not exist

Penyebab: Debug dijalankan sebelum build, path menunjuk ke .exe (Windows) bukan Linux binary.

Fix: Build project terlebih dahulu, arahkan debug ke executable di folder `build/`

### Error 15: Folder build Tidak Ada
ls build → No such file or directory

Penyebab: CMake belum pernah dijalankan.

Fix: Jalankan workflow: Conan install → CMake configure → CMake build

### Error 16: Typo CmakeLists.txt
CMake tidak generate apa pun.

Penyebab: Linux case-sensitive, file harus bernama `CMakeLists.txt` bukan `CmakeLists.txt`.

Fix:
```bash
mv CmakeLists.txt CMakeLists.txt
```

### Error 17: Ketidaksesuaian Versi Compiler
Sistem menggunakan GCC 13 sedangkan project memerlukan GCC 11.

Penyebab: Ubuntu 24.04 default menggunakan GCC 13, library OpenDDS memerlukan GCC 11.

Fix:
```bash
sudo apt install gcc-11 g++-11
sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-11 110
sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-13 130
sudo update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-11 110
sudo update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-13 130
sudo update-alternatives --config gcc
sudo update-alternatives --config g++
gcc --version
```

### Error 18: Struktur Folder CMake Berlapis
Perintah `cmake --version` tetap command not found setelah dipindahkan.

Penyebab: File CMake berada di folder nested (folder di dalam folder).

Fix:
```bash
cd /usr/local/cmake/cmake-3.31.0-linux-x86_64
sudo mv * ../
cd ..
sudo rm -rf cmake-3.31.0-linux-x86_64
sudo ln -sf /usr/local/cmake/bin/cmake /usr/local/bin/cmake
hash -r
```

### Error 19: Permission Denied dan Wildcard Gagal
Permission denied, mv path/* failed

Penyebab: Akses ke folder sistem memerlukan sudo, wildcard tidak bisa dibaca shell sebelum sudo dijalankan.

Fix:
```bash
sudo mv /source/folder /tmp/temp_folder
sudo mv /tmp/temp_folder/* /destination/
sudo rm -rf /tmp/temp_folder
```

### Error 20: Command Tidak Terdeteksi setelah Install
Binary sudah ada di path tapi terminal tidak mengenali.

Penyebab: Terminal cache command location.

Fix:
```bash
hash -r
```

### Error 21: Permission Denied saat Compile
/usr/bin/ld: cannot open output file classnobject: Permission denied

Penyebab: Folder dimiliki oleh root, user biasa tidak bisa write file di folder tersebut.

Fix:
```bash
sudo chown -R felixrdev:felixrdev ~/workspace/len-iot-bridge/CPP_OOP

# Sekarang compile lagi
g++ -o classnobject Classnobject.cpp
./classnobject
```

### Error 22: Git Dubious Ownership
fatal: detected dubious ownership in repository at '/home/felixrdev/workspace/len-iot-bridge'

Penyebab: Folder dimiliki oleh root, tapi diakses sebagai user biasa.

Fix:
```bash
# Option 1: Ubah ownership
sudo chown -R felixrdev:felixrdev ~/workspace/len-iot-bridge

# Option 2: Atau allow folder di git config
git config --global --add safe.directory /home/felixrdev/workspace/len-iot-bridge

# Sekarang coba lagi
git status
git add .
git commit -m "docs: tambah error dan solusi"
```

---
### ERROR 23: Izin akses foldee di wsle dari vscode windows 
Failed to save 'error_dump.md': Unable to write file 'vscode-remote://wsl+ubuntu/home/felixrdev/workspace/len-iot-bridge/docs/error_dump.md' (NoPermissions (FileSystemError): Error: EACCES: permission denied, open '/home/felixrdev/workspace/len-iot-bridge/docs/error_dump.md')

Fix:
Install extension WSL dan ubah directory permisiion wsl nya menggunakan 
```bash 
# Ubah Ownership ke folder user 
sudo chown -R felixrdev:felixrdev /home/felixrdev/workspace/len-iot-bridge
# lalu ubah permission memastikan user tersebut memiliki izin
chmod -R u+rw /home/felixrdev/workspace/len-iot-bridge
```




Status Akhir Environment: GCC/G++ 11.5.0, CMake 3.31.0, Conan 2.25.1, Python 3.12, C++17, Ubuntu 24.04 (WSL)