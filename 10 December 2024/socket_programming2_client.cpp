#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <cstring>

// Link with ws2_32.lib
#pragma comment(lib, "ws2_32.lib")

#define PORT 8080

int main() {
    WSADATA wsaData;
    SOCKET sock = INVALID_SOCKET;
    struct sockaddr_in serv_addr;
    const char* message = "Hello from client";
    char buffer[1024] = {0};

    // Initialize Winsock
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr << "WSAStartup failed with error: " << WSAGetLastError() << "\n";
        return -1;
    }

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
        std::cerr << "Socket creation error: " << WSAGetLastError() << "\n";
        WSACleanup();
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 address from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        std::cerr << "Invalid address/Address not supported\n";
        closesocket(sock);
        WSACleanup();
        return -1;
    }

    // Connect to the server
    if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == SOCKET_ERROR) {
        std::cerr << "Connection failed with error: " << WSAGetLastError() << "\n";
        closesocket(sock);
        WSACleanup();
        return -1;
    }

    // Send data
    send(sock, message, strlen(message), 0);
    std::cout << "Message sent\n";

    // Receive data
    int bytesReceived = recv(sock, buffer, sizeof(buffer) - 1, 0);
    if (bytesReceived > 0) {
        buffer[bytesReceived] = '\0'; // Null-terminate the received data
        std::cout << "Message from server: " << buffer << std::endl;
    } else {
        std::cerr << "Receiving failed with error: " << WSAGetLastError() << "\n";
    }

    // Cleanup
    closesocket(sock);
    WSACleanup();
    return 0;
}
