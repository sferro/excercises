/* Program 12.3 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <sys/wait.h>
#include "uici.h"
 
 
/*
 *                       UICI Server
 *  Open a UICI port specified as a command-line argument
 *  and listen for requests.  When a request
 *  arrives, fork a child to handle the communication and
 *  listen again.
 */
void main(int argc, char *argv[])
{
   u_port_t portnumber;
   int byteswritten;
   int listenfd;
   int communfd;
   char client[MAX_CANON];
   int bytes_copied,bytes_copiedtot;
   int child;
   char bufrecived[1024];
   char bufsend[1024];
 
   if (argc != 2) {
      fprintf(stderr, "Usage: %s port\n", argv[0]);
      exit(1);
   } 

   portnumber = (u_port_t) atoi(argv[1]);
   if ((listenfd = u_open(portnumber)) == -1) {
      u_error("Unable to establish a port connection");
      exit(1);
   }  
 
   while ((communfd = u_listen(listenfd, client)) != -1) {
      fprintf(stderr, "[%ld]: A connection has been made to %s\n",
              (long) getpid(), client);
      if ((child = fork()) == -1) {
         fprintf(stderr, "Could not fork a child\n");
         break;
      }  
 
      if (child == 0) {   
      	bytes_copiedtot=0;                         /* child code */
         close(listenfd);
         fprintf(stderr, "[%ld]: A connection has been made to %s\n",
                        (long) getpid(), client);
         bytes_copied =u_read3(communfd, bufrecived, 1024,10000);
         fprintf(stderr, "Cliente Envio: %s", bufrecived);
         fprintf(stderr, "Bytes recibidos por el cliente: %d\n", bytes_copied);
         bytes_copiedtot+=bytes_copied;
       	strcpy(bufsend,"El Mensaje 1 fue recivido con exito");
 			byteswritten = u_write3(communfd, bufsend, strlen(bufsend),10000);
         bytes_copied =u_read3(communfd, bufrecived, 1024,10000);
         fprintf(stderr, "Cliente Envio: %s", bufrecived);
         fprintf(stderr, "Bytes recibidos por el cliente: %d\n", bytes_copied);
         bytes_copiedtot+=bytes_copied;
       	strcpy(bufsend,"El Mensaje 2 fue recivido con exito");
 			byteswritten = u_write3(communfd, bufsend, strlen(bufsend),10000);
         close(communfd);
         fprintf(stderr, "[%ld]:Bytes transferred = %d\n",
                        (long) getpid(), bytes_copiedtot);
         exit(0);
 
   	}
    	else {                                    /* parent code */
         u_close(communfd);
         while (waitpid(-1, NULL, WNOHANG) > 0)
            ;
      }
   }   
   exit(0);
}
