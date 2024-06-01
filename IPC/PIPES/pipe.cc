#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <cstring>

int main() {
    int pipefd[2];
    pid_t pid;
    const char* message = "Hello from parent process!";
    char buffer[100];

    // Create a pipe
    if (pipe(pipefd) == -1) {
        perror("pipe");
        return 1;
    }

    // Fork a child process
    pid = fork();
    std::cout << "Child received message: " << pid << std::endl;
    if (pid == -1) {
        perror("fork");
        return 1;
    }

    if (pid > 0) {
        // Parent process
        close(pipefd[0]); // Close unused read end

        // Write message to the pipe
        write(pipefd[1], message, strlen(message) + 1);
        close(pipefd[1]); // Close write end after writing

        // Wait for child to finish
        wait(NULL);
    } else {
        // Child process
        close(pipefd[1]); // Close unused write end

        // Read message from the pipe
        read(pipefd[0], buffer, sizeof(buffer));
        close(pipefd[0]); // Close read end after reading

        // Print the message received from the parent
        std::cout << "Child received message: " << buffer << std::endl;
    }

    return 0;
}
