/**
 * @file server.cc
 * @brief Server application for socket programming.
 */

#include <cstring>
#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

using namespace std;

/**
 * @brief Main function for the server application.
 * 
 * This function creates a socket, binds it to an address, listens for connections,
 * accepts a connection, and sends and receives messages.
 * 
 * @return int Returns 0 on successful execution.
 */
int main()
{
    // creating socket
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    // specifying the address
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    // binding socket.
    bind(serverSocket, (struct sockaddr *)&serverAddress,
         sizeof(serverAddress));

    // listening to the assigned socket
    listen(serverSocket, 5);

    // accepting connection request
    int clientSocket = accept(serverSocket, nullptr, nullptr);

    // receiving data
    while (1)
    {
        char buffer[1024] = {0};
        recv(clientSocket, buffer, sizeof(buffer), 0);
        cout << "Message from client: " << buffer
             << endl;
        bzero(buffer, 1024);
        fgets(buffer, 255, stdin);
        send(clientSocket, buffer, strlen(buffer), 0);

        int i = strncmp("Bye", buffer, 3);
        if (i == 0)
            break;
    }

    // closing the socket.
    close(serverSocket);

    return 0;
}
