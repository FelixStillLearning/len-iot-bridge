# Cara Setup & Run Project simple-grpc-cpp

1. **Copy file .env**  
   Pastikan `.env` berisi variabel seperti `GRPC_PORT`, `GRPC_HOST`, dll.

2. **Pastikan CMakeLists.txt di root project**  
   Copy dari subfolder jika perlu.

3. **Install dependency dengan Conan**
   ```bash
   conan install . --output-folder=build --build=missing
   ```

4. **Konfigurasi project dengan CMake**
   ```bash
   cmake -S . -B build
   ```

5. **Build project**
   ```bash
   cmake --build build --config Release
   ```

6. **Export environment variable**
   ```bash
   export $(grep -v '^#' .env | xargs)
   ```

7. **Jalankan executable**
   ```bash
   ./build/<executable-name>
   ```

Selesai! Project gRPC siap dijalankan.