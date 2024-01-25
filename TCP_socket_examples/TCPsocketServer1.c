#include <stdio.h>       // Standard I/O functions
#include <stdlib.h>      // Standard library for memory allocation, process control, etc.
#include <string.h>      // String handling functions
#include <unistd.h>      // Provides access to the POSIX operating system API
#include <sys/types.h>   // Definitions of data types used in system calls
#include <sys/socket.h>  // Definitions needed for sockets
#include <netinet/in.h>  // Constants and structures for internet domain addresses
#include <pthread.h>     // POSIX threading library

void error(const char *msg) {
    perror(msg);     // Print a system error message
    exit(1);         // Exit the program with a status code of 1 (error)
}

// Function to handle communication with the client
void *client_handler(void *sockfd) {
    int newsockfd = *(int*)sockfd;  // Cast and dereference sockfd to use it
    char buffer[256];               // Buffer to store messages from the client
    int n;                          // Number of characters read or written

    bzero(buffer, 256);             // Zero out the buffer
    n = read(newsockfd, buffer, 255);  // Read data from the client
    if (n < 0) error("ERROR reading from socket");

    printf("Client: %s\n", buffer);  // Print the client's message

    close(newsockfd);               // Close the client's socket
    return NULL;                    // Exit the thread
}

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno;  // Socket file descriptors and port number
    socklen_t clilen;               // Size of the address of the client
    struct sockaddr_in serv_addr, cli_addr;  // Structures for internet addresses
    pthread_t thread;               // Thread for handling client connections

    sockfd = socket(AF_INET, SOCK_STREAM, 0);  // Create a new TCP socket
    if (sockfd < 0) error("ERROR opening socket");

    bzero((char *)&serv_addr, sizeof(serv_addr));  // Clear the server address structure
    portno = 12345;                               // Port number
    serv_addr.sin_family = AF_INET;               // Address family (IPv4)
    serv_addr.sin_addr.s_addr = INADDR_ANY;       // Bind to all interfaces
    serv_addr.sin_port = htons(portno);           // Convert port number to network byte order

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        error("ERROR on binding");

    listen(sockfd, 5);   // Listen for connections, with a backlog of 5

    while (1) {  // Main loop to accept connections
        clilen = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
        if (newsockfd < 0) error("ERROR on accept");

        // Create a new thread for each client
        if (pthread_create(&thread, NULL, client_handler, (void *)&newsockfd) < 0)
            error("ERROR creating thread");

        // Detach the thread - when it's done, its resources will be released
        pthread_detach(thread);
    }

    close(sockfd);  // Close the server socket (this line may never be reached in this setup)
    return 0;
}
