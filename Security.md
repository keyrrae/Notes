IP header with no options, 20 bytes total
VER TOS Length in bytes
ID Field  Frag offset
TTL Protocol  Header checksum
Source IP address
Destination IP address

ARP is used to broadcast a request to all hosts on the local network asking
one to respond with a MAC address that matches the desired destination IP number.

#Cryptography

- Cryptography provides the building-blocks to achieve network security
- Privacy/Confidentiality
- Authentication
- Integrity
- Non repudiation

Cleartext -> Encryption -> Ciphertext -> Decryption


#Network Security Analysis

## The TCP/IP Protocol Suite

- Network protocols(OSI layer 3)
IP Internet Protocol
ICMP Internet Control Message Protocol
IGMP Internet Group Management Protocol

Transport protocols(OSI layer 4)
-TCP transfer control protocol
-UDP User Datagram Protocol

Application protocols(OSI layer 7)
SMTP HTTP SSH

Other Protocols
-ARP Address Resolution Protocol
-RARP Reverse Address Resolution Protocol

IP Addresses
-Each host has on or more IP addresses *for each network inferface*
