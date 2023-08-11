#include <stdio.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <net/ethernet.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <errno.h>
#include <string.h>
#include <unistd.h> 

#define GETSOCKETERRNO() (errno)

int main() {
   
    //This socket captures all network traffic that passes by this terminal.
    //A raw socket records binary data, the rest of the program is 
    //interpreting the data
    int raw_socket;
    raw_socket = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ALL));
    
    if (raw_socket < 0) {
        printf("[-]Error creating socket\n");
        printf("%s", strerror(errno));
        return -1;
    }
    printf("[+]Socket Created\n[*]Return Value: %d\n", raw_socket);
    printf("-----------------------------\n");

    while (1) {
        char buffer[65536];
        struct sockaddr saddr;
        int saddr_len = sizeof(saddr);
        int data_size = recvfrom(raw_socket, buffer, sizeof(buffer), 0, &saddr, &saddr_len);     
        
        if (data_size < 0){
            printf("[-]Failed to capture packet\n");
            printf("[*]%s\n", strerror(errno));
            return -1;
        }

       //https://dox.ipxe.org/if__ether_8h_source.html
       //Decode Ethernet Headdr
       struct ethhdr *eth = (struct ethhdr *)buffer;
       printf("Source MAC: %02X:%02X:%02X:%02X:%02X:%02X\n",
               eth->h_source[0],eth->h_source[1],eth->h_source[2],
               eth->h_source[3],eth->h_source[4],eth->h_source[5]);
    
       printf("Destination MAC: %02X:%02X:%02X:%02X:%02X:%02X\n",
               eth->h_dest[0],eth->h_dest[1],eth->h_dest[2],
               eth->h_dest[3],eth->h_dest[4],eth->h_dest[5]); 
       //ntohs - network to host short
       printf("Protocol ID: 0x%04X\n", ntohs(eth->h_proto));

       //Decode IP Header
       struct iphdr *ip = (struct iphdr *)(buffer + sizeof(struct ethhdr));
       //ntoa - network binary (big endian) to 4 octect IP address
       printf("Source IP: %s\n", inet_ntoa(*(struct in_addr *)&ip->saddr));
       printf("Destination IP: %s\n", inet_ntoa(*(struct in_addr*)&ip->daddr));

       //Decode TCP Header
       struct tcphdr *tcp = (struct tcphdr *)(buffer + 
               sizeof(struct iphdr) + 
               sizeof(struct ethhdr));

       printf("Source Port:%u\n", ntohs(tcp->source));
       printf("Desination Port:%u\n", ntohs(tcp->dest));
    
       //Decode Payload 
       int payload_size = data_size - 
               (sizeof(struct ethhdr) + 
               sizeof(struct iphdr) +
               sizeof(struct tcphdr));
       
       printf("Payload Data:\n");
       
       for (int i = 0; i < payload_size; i++) {
           
           unsigned char payload_byte = (unsigned char)buffer[
                 sizeof(struct ethhdr) +
                 sizeof(struct iphdr) +
                 sizeof(struct tcphdr) + i];

           if (i != 0 && i % 16 == 0) {
               printf("          ");
               for (int j = i - 16; j < i; j++) {
                   if (payload_byte >= 32 && payload_byte <= 128)
                        printf("%c", payload_byte);
                   printf(".");
                }
               printf("\n");
           }
           printf("%02X ", payload_byte);
            }
       printf("\n");
       printf("-----------------------------\n");
    
            
       }

    close(raw_socket);
    return 0;
}
