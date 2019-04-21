/* A simple server in the internet domain using TCP
   The port number is passed as an argument */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#define LISTENQ 5
void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
     pid_t pid;
     int listenfd,connfd,portno;
     socklen_t clilen;
     char buffer[256];
	 struct sockaddr_in serv_addr,cli_addr;
     int n;
     
     if (argc < 2) 
	 {
         fprintf(stderr,"ERROR, no port provided\n");
         exit(1);
     }
	
	 listenfd = socket(AF_INET,SOCK_STREAM,0);
     if(listenfd < 0)
     	error("ERROR opening socket");
     
	 bzero((char *) &serv_addr, sizeof(serv_addr));	
     portno = atoi(argv[1]);
     serv_addr.sin_family = AF_INET;
     serv_addr.sin_addr.s_addr = INADDR_ANY;
     serv_addr.sin_port = htons(portno);
     
     if(bind(listenfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0)
     	error("ERROR on binding");
     
	 listen(listenfd,LISTENQ);
	 clilen = sizeof(cli_addr);
	 
	 for(;;)
	 {
	    connfd = accept(listenfd,(struct sockaddr *) &cli_addr, &clilen);	
	    
	    if((pid = fork()) == 0)
	    {
	    	close(listenfd);
	    	if(connfd < 0)
	    		error("ERROR on accept");
	    	
			bzero(buffer,256);
    	 	n = read(connfd,buffer,255);
    	 	if (n < 0) error("ERROR reading from socket");
    	 	printf("Here is the message: %s\n",buffer);
    		n = write(connfd,"I got your message",18);
    		if (n < 0) error("ERROR writing to socket");
    		
			close(connfd);
    		exit(0);
		}
		close(connfd);
	 }	
	 return 0;
}
