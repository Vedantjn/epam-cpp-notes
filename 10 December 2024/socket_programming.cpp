// Socket programming in C++ refers to the process of using sockets to enable communication between different programs, 
// devices, or processes over a network. It is a fundamental aspect of network programming and can be used for building 
// client-server architectures where programs exchange data over the Internet or other networks.

// What is a Socket?
// A socket is an endpoint for communication. It is a programming construct that allows sending and receiving data between devices or processes. Each socket is identified by:

// An IP address (for the device).
// A port number (for the specific application/service on that device).

// Types of Sockets
// Stream Sockets (TCP):

// Provide reliable, connection-oriented communication.
// Use the Transmission Control Protocol (TCP).
// Example: HTTP, FTP, SSH.
// Datagram Sockets (UDP):

// Provide connectionless, unreliable communication.
// Use the User Datagram Protocol (UDP).
// Example: DNS, video streaming.

// Basic Steps for Socket Programming
// Socket programming typically involves the following steps for a client and server:

// Server Side
// Create a socket using socket().
// Bind the socket to an IP address and port using bind().
// Listen for incoming connections using listen().
// Accept a connection using accept().
// Receive or send data using recv() and send() (or read() and write()).
// Close the socket using close().

// Client Side
// Create a socket using socket().
// Connect to the server using connect().
// Send or receive data using send() and recv() (or write() and read()).
// Close the socket using close().


// Server code

#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>

#define PORT 8080

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    const char* hello = "Hello from server";

    // Create socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // Bind to address and port
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    // Accept a connection
    if ((new_socket = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen)) < 0) {
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }

    // Receive data
    read(new_socket, buffer, 1024);
    std::cout << "Message from client: " << buffer << std::endl;

    // Send data
    send(new_socket, hello, strlen(hello), 0);
    std::cout << "Hello message sent\n";

    close(new_socket);
    close(server_fd);
    return 0;
}

// Client code:

#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>

#define PORT 8080

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    const char* message = "Hello from client";
    char buffer[1024] = {0};

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        std::cerr << "Socket creation error\n";
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 address from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        std::cerr << "Invalid address/ Address not supported\n";
        return -1;
    }

    // Connect to the server
    if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        std::cerr << "Connection Failed\n";
        return -1;
    }

    // Send data
    send(sock, message, strlen(message), 0);
    std::cout << "Message sent\n";

    // Receive data
    read(sock, buffer, 1024);
    std::cout << "Message from server: " << buffer << std::endl;

    close(sock);
    return 0;
}
