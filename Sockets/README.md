# Network Packet Sniffer

This is a simple network packet sniffer implemented in C using raw sockets. It captures and interprets network traffic passing through the terminal, providing information about Ethernet headers, IP headers, TCP headers, and payload data.

## Prerequisites

- You need a Linux environment to run this code as it uses raw sockets, which are not supported on all operating systems.

## How to Use

1. Clone the repository:
   ```bash
   git clone https://github.com/Doodiman1/C.git
   ```
2. Compile the code:
   ```bash
   cd Sockets
   gcc sniffer.c -o sniffer
   ```
3. Run the program:
   ```bash
   sudo ./sniffer
   ```
*Note: The use of sudo is required to create and use raw sockets.*

4.The sniffer will start capturing network packets and display information about each packet's Ethernet headers, IP headers, TCP headers, and payload data.

5.Press Ctrl+C to stop the sniffer.

# Explanation

The code uses the AF_PACKET socket family to create a raw socket that captures all network traffic. It then interprets the captured packets to extract various header information and payload data.

    Ethernet Header: Source MAC address, Destination MAC address, Protocol ID
    IP Header: Source IP address, Destination IP address
    TCP Header: Source port, Destination port
    Payload Data: Hexadecimal and ASCII representation

# Disclaimer

This code is intended for educational purposes only. 
It is a basic example of network packet capturing and should not be used for malicious activities or on unauthorised networks.
