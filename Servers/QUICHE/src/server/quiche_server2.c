// Implementations of TCP servers in C. 
// The core logic of server applications that accept TCP socket connections.
// Your C TCP Server: Your server listens for TCP connections and can send/receive data to/from clients.
 
 #include <stdio.h>; // C standard library for input/output
 #include <stdlib.h>; // C standard library for memory allocation
 #include <string.h>; // C standard library for string manipulation

 #include <unistd.h> // C standard library for POSIX API, like read and close
 #include <sys/socket.h> // C standard library for socket API
 #include <sys/types.h> // C standard library for system data types
 #include <netinet/in.h> // C standard library for internet protocol family/ Contains constants and structures needed for internet domain addresses.

// error handling function
void error(const char *msg){    // char *msg declares msg as a pointer to the string being passed into the function, a pointer just points to the memory location of the variable being passed
    perror(msg);                // perror expects to recieve a pointer, and will print the items at the memory location msg is pointing at
    exit(1);
}

// client_handler: A function that handles communication with the client. It reads data from the client into buffer and prints the received message. It then closes the client's socket and exits the thread.
void *client_handler(void *sockfd){ // void pointers can accept any data type, this allows it to hold the hold the integer file-descriptor/process-index of the socket connection.
    int newsockfd = *(int *)sockfd; // Cast to an int and dereference the void sockfd, this is necessary because the socket-file descriptor is an integer.
    char buffer[256];               // buffer to store messages read from the client
    int n;                          // n will count and store the number of bytes read from the client
    // If the buffer wasn't cleared first, it could contain random leftover data from previous uses of that memory area.
    bzero(buffer, 256);             // always zero out the buffer, this is necessary because the buffer will be filled with the data read from the client
    n = read(newsockfd, buffer, 255); // read data from the client
    if(n < 0){
        error("Error reading from socket");
        /*
        when reading from a socket, can return -1 on error. Some common errors that would result in a negative return value include:
        The socket is not connected.
        The socket has been shut down.
        The time limit expired before data arrived.
        An error occurred while reading data.
        */
    }

    printf("Clent data: %s", buffer); // print the clients data

    close(newsockfd);
    return NULL;
}

int main(int argc, char *argv[]){

    // Socket file descriptors and port number
    int sockfd;
    int newsockfd;
    int portno;

    socklen_t clilen; //The socklen_t clilen declaration defines a variable to hold the size of the client's address structure. This is needed by functions like accept() to pass the address size.

    //This not only declares the sockaddr_in struct type, but also defines two variables of that type - serv_addr and cli_addr.
    struct sockaddr_in serv_addr;
    struct sockaddr_in cli_addr;

    // pthread_t thread declares a variable of type pthread_t, 
    // which is used to represent thread identifiers in POSIX threads (pthreads). This variable will be used to store the ID of the thread created to handle incoming client connections.
    pthread_t thread; // Thread handling
    // Create a new TCP socket

    sockfd = (socket(AF_INET, SOCK_STREAM, 0));
    /**
    socket() is a system call that creates a socket of a specified type. In this case:
    socket() returns a file descriptor that can be used to identify this socket in subsequent system calls like bind(), listen(), accept() etc.
    AF_INET specifies that this will be an Internet domain socket, using IPv4.
    SOCK_STREAM specifies this will be a stream socket (TCP).
    The last 0 parameter indicates no protocols should be used.
    -This file descriptor is stored in the sockfd variable. 
    -It represents the socket that will listen for incoming client connection requests.
    -So in summary, it is declaring a thread identifier and creating a TCP listening socket (file descriptor stored in sockfd). 
    -This socket will be used to accept new client connections and spawn a thread to handle communication with each client on its own socket.
    */
    if(sockfd < 0){
        error("ERROR opening socket");
    }
/**
bzero sets bytes in a memory buffer to zero (null byte). This has two key effects:
Any string data in the buffer will be null terminated, since strings in C are terminated by a null byte.
Numeric or other data types stored in the buffer will be initialized to zero.
*/
    // Clear the server address structure
    bzero((char *)&serv_addr, sizeof(serv_addr));

    portno = 4040;

    // serv_addr.sin_family sets the address family to AF_INET for IPv4
    serv_addr.sin_family = AF_INET; // Address family (IPv4)

    // serv_addr.sin_addr.s_addr = INADDR_ANY binds the socket to all interfaces, so both local and public IPs can connect
    serv_addr.sin_addr.s_addr = INADDR_ANY; // Bind to all interfaces
    /**
     htons stands for "host to network short", and converts the port number from host byte order to network byte order. 
     This ensures the port number is standardized when sending/receiving across different systems.
    */
    serv_addr.sin_port = htons(portno); // Convert port number to network byte order

    if(bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0){
        error("ERROR on binding");
    }

    listen(sockfd, 5); // Listen for incoming connections with a backlog of 5
}





1. Define the Components of Your System
First, identify all the components that will be part of your network. In your case, these would include:

Mobile devices (iPhones and Android phones)
Distributed servers or cloud infrastructure for task allocation and data aggregation
Secure communication channels
Data storage and processing nodes (for model partitioning and layer-wise distribution)
2. Determine the Data Flow
Map out how data will flow between these components. This includes:

How tasks are distributed and received
The flow of processed data back to the servers
Data aggregation points
Secure transmission of data
3. Incorporate Model Partitioning and Layer-wise Distribution
Show how the model is divided and distributed:

Indicate how the model shards or layers are distributed across mobile devices
Include synchronization mechanisms to ensure consistency and accuracy
4. Show Load Balancing and Task Allocation
Illustrate the dynamic allocation of tasks:

Represent how tasks are assigned based on device capability and load
Show fallback mechanisms for task redistribution in case of device failures
5. Detail Communication Optimization
This involves data compression, batch processing, and efficient encoding:

Highlight data compression techniques
Show batched communication to reduce network load
Illustrate efficient data encoding strategies
6. Display Security Measures
Include aspects like data encryption and secure channels:

Mark encrypted data paths
Show secure API endpoints or communication channels
7. Indicate User Participation and Incentivization
Represent user opt-in and incentive mechanisms:

Show user interaction points
Illustrate how incentives are managed or distributed
8. Energy Efficiency and Software Optimization
Reflect energy-efficient operations and software optimization:

Indicate low-energy modes or smart scheduling strategies
Show software optimization tailored for mobile processors
9. Monitoring and Maintenance Infrastructure
Include real-time monitoring and maintenance tools:

Show monitoring centers or dashboards
Represent automated update systems
10. Address Legal and Ethical Considerations
While these might not be directly represented in a network diagram, ensure that user consent and transparency are integral to your system’s design philosophy.

Tools for Creating the Diagram
Use diagramming tools like Lucidchart, Microsoft Visio, or even simpler tools like draw.io.
Utilize different shapes and colors to distinguish between different types of nodes and data flows.
Add legends and descriptions to explain complex parts of the diagram.
Finalizing the Diagram
Ensure the diagram is clear and not overly complicated. It should give an overall picture at a glance, with the ability to delve into details.
Validate the diagram with stakeholders or team members to ensure it accurately represents the system and is understandable.
