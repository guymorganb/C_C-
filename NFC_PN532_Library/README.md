
# NFC Communication Hub

## Overview

This project is designed to facilitate Near Field Communication (NFC) interactions between the PN532 NFC HAT attached to a Raspberry Pi 5 and various NFC-enabled devices, including iPhones, Android devices, and other compatible gadgets. By leveraging the capabilities of the C programming language in conjunction with the `libnfc`, `libgpiod`, and `libusb` libraries, this hub aims to establish a communication channel for a multitude of NFC-based applications. One of the exciting potential expansions of this project is the integration of a payment system for commercial NFC transactions.

## Features

- NFC communication with a wide range of modulation types, Baud Rates and devices, 
- Support for various NFC data exchange formats
- Extensible architecture for future features, such as payment processing

## Prerequisites

- Hardware: Raspberry Pi 5 with a PN532 NFC HAT
- Operating System: Linux for arm64 architecture (Ubuntu 22.+)
- Libraries:
  - `libnfc`: for NFC protocols
  - `libgpiod`: for GPIO manipulation on the Raspberry Pi
  - `libusb`: for USB communication
- Compiler: GCC (GNU Compiler Collection)

## Getting Started

### Dependencies Installation

Before building and running the project, make sure to install the required libraries:

More info on dependencies can be found on the project file readme.md

```bash
sudo apt-get update
sudo apt-get install libnfc-dev libgpiod-dev libusb-dev
```

### Compilation

To compile the project, navigate to the project directory and use GCC:

More comprehensive compilation examples can be found on the project file readme.md

```bash
gcc -o nfc_communication_hub main.c -lnfc -lgpiod -lusb
```

Replace `main.c` with the actual file name containing your `main` function. The `-l` flags link the corresponding libraries to your project during the build.

### Running the Application

After successful compilation, you can run the program by executing:
this will instigate the device search process wnd the pn_532 will find nearby deices (range 10cm)

```bash
./nfc_communication_hub
```

### Configuration

Ensure that the PN532 NFC HAT is correctly configured and connected to the Raspberry Pi GPIO pins. Any specific configurations or environment setups should be addressed in a configuration file or script if required.

## Further Development

The groundwork laid by this project could lead to several enhancements, most notably the addition of a payment system. Other possible improvements include:

- Integration with existing point-of-sale (POS) systems
- Enhanced security features for secure data transfers
- User-friendly interfaces for both consumers and businesses
- MFA (Multi factor Authentication)

## Contributing

Contributions to the NFC Communication Hub are welcome! Whether it's feature suggestions, bug reports, or pull requests, your input is invaluable in making this project a central part of NFC communication solutions on the Raspberry Pi platform.

## License

This project is licensed under the [MIT License](LICENSE) - see the LICENSE file for details.

## Disclaimer

This project is in no way affiliated with the official NFC Forum or Raspberry Pi Foundation. It is an independent project aimed at providing NFC communication solutions in C.

## Feedback and Contact

If you have any feedback, questions, or would like to get in touch, you can reach me at:

Email: [guymorganb@gmail.com]

LinkedIn: [https://www.linkedin.com/in/guymorganb/]

Instagram: [https://www.instagram.com/guyycodes/]

if you found this useful, consider staring my repo, contributing to the project or following me on instagram.
