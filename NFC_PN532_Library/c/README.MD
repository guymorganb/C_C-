### I have provided examples. This READM can be helpful if you performing a custom install. Otherwise musch of these setting are automaticlly handled. 

## libgpiod

# List Dynamic Dependencies: Use tools like ldd to list the dynamic dependencies of your compiled binaries. 

This will show you which shared libraries your binaries depend on.
```bash
ldd /path/to/compiled/binary
```
-- Example of When compiling & linking against /include for header-link against the library itself --
```bash
gcc"main.c",
"-o", "/home/guymorganb/RaspberryPi/c/src/output/main", // Output path, and name of file
"-I/home/guymorganb/RaspberryPi/c/builds/libgpiod/include",  // Include path for gpiod.h
"-L/home/guymorganb/RaspberryPi/c/builds/libgpiod/lib",      // Library path for libgpiod
"-l:libgpiod.a", // static linking to libgpiod
"-I/home/guymorganb/RaspberryPi/c/builds/libusb/include/libusb-1.0",
"-L/home/guymorganb/RaspberryPi/c/builds/libusb/lib",  
"-l:libusb-1.0.a",             
"-I/home/guymorganb/RaspberryPi/c/builds/libnfc/include",
"-L/home/guymorganb/RaspberryPi/c/builds/libnfc/lib",  // Lib for libnfc.h"
"-l:libnfc.a", // static linking to libnfc"
"-lnfc",
"-I/home/guymorganb/RaspberryPi/c/builds/libusb-compat-0.1-0.1.8/include",
"-L/home/guymorganb/RaspberryPi/c/builds/libusb-compat-0.1-0.1.8/lib",
"-lusb",
"-I/home/guymorganb/RaspberryPi/c/src"
```

# Moving onto the instalation of ligpiod for the manipulation of GPIO(General purpose I/O pins on microcontroler devices)
1)Download the source code from linux for ubuntu git clone git://git.kernel.org/pub/scm/libs/libgpiod/libgpiod.git

2)ensure you have all the dependencies and your $PATH is properly set:

```bash
sudo apt-get install pkg-config
** there are several more
autoupdate
autoreconf -fvi
export ACLOCAL_PATH=/usr/share/aclocal
```

3) prepare the environment for compilation, setup commanline tools & ensure proper directory for the library to be installed when using make to build and make install:

```bash
./autogen.sh --enable-tools=yes --prefix=/home/guymorganb/RaspberryPi/c/builds/libgpiod
```

3a) If you have to uninstall use 'sudo make uninstall' then 'make clean' in the root directory of the original library, then reconfigure the build, run:

```bash
./autogen.sh --enable-tools=yes --prefix=/home/guymorganb/RaspberryPi/c/builds/libgpiod
```
4) make & make install

5) set path variable so you can run comand line comands: export the path to run the commands from terminal:

```bash
export LD_LIBRARY_PATH=/home/guymorganb/RaspberryPi/c/builds/libgpiodlib:$LD_LIBRARY_PATH
```

6) compile and link the dependencies when youve finished your program using command:
```bash
gcc -I/home/guymorganb/RaspberryPi/c/builds/libgpiod/include -L/home/guymorganb/RaspberryPi/c/lib/libgpiod/lib -o my_program main.c -lgpiod

sudo /home/guymorganb/Pn532-nfc-hat-code/raspberrypi/test-Pn532-nfc-code/raspberrypi/c/libs/gpiod/bin/gpiodetect
```
# Moving onto the instalation of NFC feild control using Libnfc
## Libnfc
1) install dependencies: 
```bash
sudo apt-get install libusb-dev libpcsclite-dev libtool
sudo apt-get install automake autocon
```
### You need mfoc for the pn532
2)Download the source code from linux for ubuntu git clone https://github.com/nfc-tools/libnfc.git
git clone https://github.com/nfc-tools/mfoc.git

3) Config/Compile/Install libnfc
```bash
cd libnfc
autoreconf –vis
./configure --prefix=/usr --sysconfdir=/etc
make
sudo make install
```

4) Config/Compile/Install mfoc
```bash
cd mfoc
autoreconf -vis
./configure --prefix=/usr --sysconfdir=/etc
make
sudo make install
```

-- You should see a message like this:
```bash
lib_nfc Selected Drivers:
Selected drivers:
   pcsc............. no
   acr122_pcsc...... no
   acr122_usb....... yes
   acr122s.......... yes
   arygon........... yes
   pn53x_usb........ yes
   pn532_uart....... yes
   pn532_spi.......  yes
   pn532_i2c........ yes
   pn71xx........... no

```
   ## useful commands to help get things setup:

   # Set PKG_CONFIG_PATH Environment Variable: when installing to non default location
   - PKG_CONFIG_PATH is an environment variable that specifies additional paths for pkg-config to search for its .pc files. These files contain metadata about the libraries.
   nan0 ~/.bashrc
```bash
export PKG_CONFIG_PATH=/home/guymorganb/Pn532-nfc-hat-code/raspberrypi/test-Pn532-nfc-code/raspberrypi/c/libs/lib_nfc/lib/pkgconfig:$PKG_CONFIG_PATH
```
kill the terminal and start a new one.
```bash
pkg-config --modversion <library-name>

```

# Setting linux to use SPI 
```bash
sudo nano /boot/firmware/config.tx
```
- look for:
```bash
sudo nano /boot/firmware/config.txt

dtparam=spi=on
```
# check SPI status:
```bash
lsmod | grep spi
```
## List SPI devices:
```bash
ls /dev/spidev*
```
## GitHub Account Swapping notes:
to swap between your 2 accounts you need to run this command to change the remote origin
```bash
git remote set-url origin git@github.com-account2:<username>/<repo>.git

git remote set-url origin git@github.com-account1:<username>/<repo>.git
```
