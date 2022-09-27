#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <pthread.h>

#define PORT 5050       // the port client will be connecting to
#define MAXDATASIZE 256 // max number of bytes we can get at once

char client_name[20];    //cpmmecn

void *read_function (void *socket_desc)
{
  char *str, buffer[MAXDATASIZE];
  int sock = *(int*)socket_desc,numbytes;

   while(1)
    {
        bzero(buffer,MAXDATASIZE);
        if ((numbytes=read(sock, buffer, MAXDATASIZE-1)) < 0)
        {
            perror("ERROR reading from socket");
            exit(0);
        }
        buffer[numbytes] = '\0';
        if(strcmp(buffer,"exit")==0)
        {
            printf("Close connection\n");
            exit(0);
        }

        printf("From: %s\n",buffer);
    }

}


int main(int argc, char *argv[])
{
    int sockfd, numbytes;
    char buf[MAXDATASIZE],temp[MAXDATASIZE];
    struct hostent *server;
    struct sockaddr_in server_addr;
    pthread_t thread_id;

    if (argc != 3) {
        printf("usage: client hostname and name\n");
        exit(1);
    }


    if ((server=gethostbyname(argv[1])) == NULL)
    {
        printf("ERROR, no such host\n");
        exit(0);
    }

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("ERROR opening socket");
        exit(0);
    }

    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr = *((struct in_addr *)server->h_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(struct sockaddr)) < 0)
    {
        perror("ERROR connecting");
        exit(0);
    }

    if (write(sockfd,argv[2],strlen(argv[2])) < 0)
    {
        perror("ERROR writing to socket");
        exit(0);
    }


   if( pthread_create( &thread_id , NULL ,  read_function , (void*) &sockfd) < 0)
    {
        perror("ERROR create thread");
        exit(1);
    }

    while(1){
        bzero(buf,MAXDATASIZE);
        fgets(buf,MAXDATASIZE-1,stdin);

        if (write(sockfd,buf,strlen(buf)) < 0)
        {
            perror("ERROR writing to socket");
            exit(0);
        }
    }

    close(sockfd);
    return 0;
}

