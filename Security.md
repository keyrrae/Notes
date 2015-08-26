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
- ARP Address Resolution Protocol
- RARP Reverse Address Resolution Protocol

IP Addresses
- Each host has on or more IP addresses *for each network inferface*
- IPv4 addresses are composed of 32 bit class+netid+hostid
- Represented in dotted-decimal notation: 128.111.48.69
- classes
class A netid=7bit()
- Class A (0): netid=7 bit (128 networks, actually 1-126), hostid=24 bit
(16777216 hosts)
- Class B (10): netid=14 bit (16384 networks), hostid=16 bit (65536 hosts)
- Class C (110): netid=21 bit (2097152 networks), hostid=8 bit (256 hosts)
- Class D - Multicast (1110): multicast addresses
- Class E (1111): reserved or future use

## Special Addresses
As source and destination address
- Loopback interface: 127.X.X.X
(usually 127.0.0.1)
- As source address
- netid=0, hostid=0 or hostid=XXX: this host on this net (used in special
cases, such as booting procedures)
- As destination address
- All bits set to 1: local broadcast
- netid + hostid with all bits set to 1: net-directed broadcast to netid

- Reserved addresses (RFC 1597):
10.0.0.0 - 10.255.255.255
172.16.0.0 - 172.31.255.255
192.168.0.0 - 192.168.255.255

##Classless Inter-Domain Routing(CIDR)
- Allocation of large chunks of IP addresses wasted an enormous
number of IP addresses
- Number of hosts is increasing
- IPv6 provides a larger address space but it is not ubiquitously
implemented
- CIDR is a new addressing scheme for the Internet which allows
for more efficient allocation of IP addresses than the old “Class
A, B, and C” address scheme
- The netid/hostid boundary can be placed on any bit between 13
and 27
- 32 hosts minimum
- 524,288 hosts maximum

## Internet Protocol
- The IP protocol represents the “glue” of the Internet
- The IP protocol provides a connectionless, unreliable, best-effort
datagram delivery service (delivery, integrity, ordering, non-
duplication, and bandwidth is not guaranteed)
- IP datagrams can be exchanged between any two nodes
(provided they both have an IP address)
- For direct communication IP relies on a number of different
lower-level protocols, e.g., Ethernet, Token Ring, FDDI, RS-232

## IP Header

- Normal size: 20 bytes
- Version (4 bits): current value=4 (IPv4)
- Header length (4 bits): number of 32-bit words in the header,
including options (max header size is 60 bytes)
- Type of service (8 bits): priority (3 bits), quality of service (4 bits),
and an unused bit
- Total length (16 bits): datagram length in bytes (max size is
65535 bytes)
- Id (16 bits): unique identifier for the datagram (usually
incremented by one)

- Flags (3 bits) and offset (13 bits): used for fragmentation
- Time To Live (8 bits): specifies the max number of hops in the
delivery process
- Protocol (8 bits): specifies the protocol encapsulated in the
datagram data (e.g., TCP)
- Header checksum (16 bits): checksum calculated over the IP
header
- Addresses (32+32 bits): IP addresses of the source and
destination of the datagram

## IP Options
- Variable length
- Identified by first byte
- Security and handling restrictions: used in military applications
- Record route : each router records its IP address
- Time stamp : each router records its IP address and time
- Source route : specifies a list of IP addresses that must be traversed by
the datagram
 Loose : some

 Strict : all of them

- Many others...

## IP Encapsulation

              IP header IP data
Frame header  Frame data

## IP: Direct Delivery

If two hosts are in the same physical network the IP datagram is
encapsulated in a lower level protocol and delivered directly

## Ethernet
- Widely-used link-layer protocol
- uses CSMA/CD (Carrier Sense, Multiple Access with Collision Detection)
- Destination Address: 48 bits (e.g., 09:45:FA:07:22:23)
- Source Address: 48 bits
- Type: 2 bytes (IP, ARP, RARP)
- Data: Min 46 bytes (padding may be needed)  Max 1500 bytes
- CRC: Cyclic Redundancy Check, 4 bytes

## Ethernet Frame
dest (6) src (6) type (2) data (46-1500) CRC (4)
0800 IP datagram
0806 ARP (28) PAD (18)
0808 RARP (28) PAD (18)

## Address Resolution Protocol
- The address resolution protocol allows a host to map IP
addresses to the link-level addresses associated with the peer’s
hardware interface (e.g., Ethernet) to be used in direct delivery
- ARP messages are encapsulated in the underlying link level
protocol

Host A wants to know the hardware address associated with IP
address I b of host B
•  A broadcasts a special message to all the hosts on the same
physical link
•  Host B answers with a message containing its own link-level
address
•  A keeps the answer in its cache (20 minutes)
•  To optimize traffic, when A sends its request, A includes its own
IP address
•  The receiver of the ARP request will cache the requester
mapping

ARP Messages
Hw type Prot type
•
•
•
•
•
Hw size
Prot size Op Sender Ether Sender IP
Target Ether
Target IP
Hardware (2 bytes), protocol (2 bytes), hardware size (1 byte),
and protocol size (1 byte) specify the link and network
addresses to be mapped (usually Ethernet and IP, respectively)
[0x0001, 0x0800, 6, 4]
OP field specifies if this is an ARP request or an ARP reply (1=
ARP req, 2=ARP reply)
Sender Ethernet/IP: data of the requester
Target Ethernet: empty in a request
Target IP: requested IP address




## Local Area Network Attacks
- Sniffing
- Spoofing
- Hijacking
- ARP attacks
- Goals
Impersonation of a host

Denial of service

Access to information

Tampering with delivery mechanisms

## Network Sniffing
•  Technique at the basis of many attacks
•  The attacker sets his/her network interface in promiscuous
mode
•  Can access all the traffic on the segment

## Why Sniffing?
•  Many protocols (FTP, POP, HTTP, IMAP) transfer authentication
information in the clear
•  By sniffing the traffic it is possible to collect usernames/
passwords, files, mail, etc.
•  Many tools available

## Dsniff
•  Collection of tools for network auditing and penetration testing
•  dsniff, filesnarf, mailsnarf, msgsnarf, urlsnarf, and webspy
passively monitor a network for interesting data (passwords, e-
mail, files, etc.)
•  arpspoof, dnsspoof, and macof facilitate the interception of
network traffic normally unavailable to an attacker (e.g., due to
layer-2 switching)
•  sshmitm and webmitm implement active man-in-the-middle
attacks against redirected SSH and HTTPS


##ICMP Redirect
•  A host that receives an ICMP redirect message performs the
following checks:

The new router must be on a directly connected network

The redirect must be from the current router for that destination

The redirect cannot tell the host to use itself as the router

The route that is being modified must be an indirect route



## ICMP Redirect Attacks
```bash
# arp -n
Address
HWtype HWaddress
192.168.1.1
ether
00:20:78:CA:7E:AE
192.168.1.10
ether
00:01:03:1D:98:B8
192.168.1.100
ether
08:00:46:07:04:A3
C:\WINDOWS>route PRINT
Active Routes:
Network Address
Netmask Gateway Address
Interface
0.0.0.0
0.0.0.0
192.168.1.1
192.168.1.10
127.0.0.0
255.0.0.0
127.0.0.1
127.0.0.1
192.168.1.0
255.255.255.0
192.168.1.10
192.168.1.10
192.168.1.10 255.255.255.255
127.0.0.1
127.0.0.1
192.168.1.255 255.255.255.255
192.168.1.10
192.168.1.10
# tcpdump -n
8:0:46:7:4:a3 0:1:3:1d:98:b8 0800 70: 192.168.1.1 > 192.168.1.10:
icmp: redirect 128.111.48.69 to host 192.168.1.100

```



ICMP Destination Unreachable
•  ICMP message used by gateways to state that the datagram
cannot be delivered
•  Many subtypes

Network unreachable

Host unreachable

Protocol unreachable

Port unreachable

Fragmentation needed but don’t fragment bit set

Destination host unknown

Destination network unknown

## Traceroute
•  ICMP Time Exceeded messages are used by the traceroute
program to determine the path used to deliver a datagram
•  A series of IP datagrams are sent to the destination node
•  Each datagram has an increasing TTL field (starting at 1)
•  From the ICMP Time exceeded messages returned by the
intermediate gateways it is possible to reconstruct the route
from the source to the destination
•  Note: traceroute allows one to specify loose source routing (-g
option)
•  Useful for network analysis, topology mapping


## User Datagram Protocol (UDP)
•  The UDP protocol relies on IP to provide a connectionless ,
unreliable, best-effort datagram delivery service (delivery,
integrity, non-duplication, ordering, and bandwidth is not
guaranteed)
•  Introduces the port abstraction that allows one to address
different message destinations for the same IP address
•  Often used for multimedia (more efficient than TCP) and for
services based on request/reply schema (DNS, NIS, NFS, RPC)

## Network Information Service
•  Centralized database used to manage administrative files
(passwords, host tables) in a subnetwork
•  The NIS is composed of
–  Domains
–  Maps
–  Daemons
•  NIS was formerly known as Sun Yellow Pages (YP) but the name
Yellow Pages(tm) is a registered trademark in the United
Kingdom of British Telecom and may not be used without
permission

## NIS Server Hijacking
•  By racing against a legitimate NIS server it is possible to provide
a modified version of the password map during the login process
•  Attack described in “ A Unix Network Protocol Security Study:
Network Information Service” , David K. Hess, David R. Safford,
Udo W. Pooch
•  ypghost (http://www.unix.geek.org.uk/~arny/progs/ypghost/
ypghost.html) is a tool that listens for passwd map requests and
replies with the “ghost” version of the map


## UDP Portscan
•  Used to determine which UDP services are available
•  A zero-length UDP packet is sent to each port
•  If an ICMP error message “port unreachable” is received the
service is assumed to be unavailable
•  Many TCP/IP stack implementations (not Windows’!) implement
a limit on the error message rate, therefore this type of scan
can be slow (e.g., Linux limit is 80 messages every 4 seconds)

UDP Portscan
```
% nmap -sU 192.168.1.10
Starting nmap by fyodor@insecure.org ( www.insecure.org/nmap/ )
Interesting ports on (192.168.1.10):
(The 1445 ports scanned but not shown below are in state: closed)
Port
State
Service
137/udp
open
netbios-ns
138/udp
open
netbios-dgm
Nmap run completed -- 1 IP address (1 host up) scanned in 4 seconds
```



## Transmission Control Protocol (TCP)
•  The TCP protocol relies on IP to provide a connection-oriented,
reliable stream delivery service (no loss, no duplication, no
transmission errors, correct ordering)
•  TCP, as UDP, provides the port abstraction
•  TCP allows two nodes to establish a virtual circuit, identified by
source IP address, destination IP address, source TCP port,
destination TCP port
•  The virtual circuit is composed of two streams (full-duplex
connection)
•  The couple IP address/port number is sometimes called a
socket (and the two streams are called a socket pair )


## TCP Seq/Ack Numbers
•  The sequence number specifies the position of the segment
data in the communication stream
(SYN=13423 means: the payload of this segment contains the
data from byte 13423 to byte 13458 )
•  The acknowledgment number specifies the position of the next
byte expected from the communication partner
(ACK = 16754 means: I have received correctly up to byte
16753 in the stream, I expect the next byte to be 16754 )
•  These numbers are used to manage retransmission of lost
segments, duplication, flow control


## TCP Window
•  The TCP window is used to perform flow control
•  Segment will be accepted only if their sequence numbers are
inside the window that starts with the current acknowledgment
number:
ack number < sequence number < ack number + window
•  The window size can change dynamically to adjust the amount of
information sent by the sender

TCP Virtual Circuit: Setup
•  A server , listening to a specific port , receives a connection
request from a client: The segment containing the request is
marked with the SYN flag and contains a random initial
sequence number s c
•  The server answers with a segment marked with both the SYN
and ACK flags and containing
–  an initial random sequence number s s
–  s c + 1 as the acknowledgment number
•  The client sends a segment with the ACK flag set and with
sequence number s c + 1 and acknowledgment number s s + 1
