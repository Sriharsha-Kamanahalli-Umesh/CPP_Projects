// C++ program to illustrate the client application in the
// socket programming
#include <cstring>
#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

using namespace std;

int main()
{
    // creating socket
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);

    // specifying address
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    // sending connection request
    connect(clientSocket, (struct sockaddr *)&serverAddress,
            sizeof(serverAddress));

    // sending data
    while (1)
    {
        char buffer[1024] = {0};
        fgets(buffer, 255, stdin);
        send(clientSocket, buffer, strlen(buffer), 0);
        bzero(buffer, 1024);
        recv(clientSocket, buffer, 255, 0);
        cout << "Message from server: " << buffer
             << endl;
        int i = strncmp("Bye", buffer, 3);
        if (i == 0)
            break;
    }

    // closing socket
    close(clientSocket);

    return 0;
}
