# Ubah ownership folder ke user 
sudo chown -R felixrdev:felixrdev ~/workspace/len-iot-bridge/

# Atau dari dalam folder
cd ~/workspace/len-iot-bridge/CPP_OOP
sudo chown -R felixrdev:felixrdev .

# Compile
g++ -o classnobject Classnobject.cpp

# Run
./classnobject