// Server side

#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>
#pragma comment(lib, "ws2_32.lib") // Link with Winsock library

#define PORT 8080

int main() {
    WSADATA wsaData;
    SOCKET server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    const char* hello = "Hello from server";

    // Initialize Winsock
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr << "WSAStartup failed\n";
        return 1;
    }

    // Create socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
        std::cerr << "Socket creation failed: " << WSAGetLastError() << "\n";
        WSACleanup();
        return 1;
    }

    // Bind to address and port
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) == SOCKET_ERROR) {
        std::cerr << "Bind failed: " << WSAGetLastError() << "\n";
        closesocket(server_fd);
        WSACleanup();
        return 1;
    }

    // Listen for incoming connections
    if (listen(server_fd, 3) == SOCKET_ERROR) {
        std::cerr << "Listen failed: " << WSAGetLastError() << "\n";
        closesocket(server_fd);
        WSACleanup();
        return 1;
    }

    std::cout << "Waiting for connections...\n";

    // Accept a connection
    if ((new_socket = accept(server_fd, (struct sockaddr*)&address, &addrlen)) == INVALID_SOCKET) {
        std::cerr << "Accept failed: " << WSAGetLastError() << "\n";
        closesocket(server_fd);
        WSACleanup();
        return 1;
    }

    // Receive data
    int valread = recv(new_socket, buffer, sizeof(buffer), 0);
    if (valread > 0) {
        std::cout << "Message from client: " << buffer << std::endl;
    } else {
        std::cerr << "Recv failed: " << WSAGetLastError() << "\n";
    }

    // Send data
    send(new_socket, hello, strlen(hello), 0);
    std::cout << "Hello message sent\n";

    closesocket(new_socket);
    closesocket(server_fd);
    WSACleanup();
    return 0;
}
