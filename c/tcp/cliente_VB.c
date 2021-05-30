#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <sys/types.h>
#include "uici.h"

#define BLKSIZE  1024

void usr1handler(int s)
{
   fprintf(stderr, "SIGUSR1 signal caught\n");
}
 
void usr2handler(int s)
{
   fprintf(stderr, "SIGUSR2 signal caught\n");
}
 
 
void installusrhandlers()
{
    struct  sigaction  newact;
    newact.sa_handler = usr1handler;      /* set the new usr1 handler */
    sigemptyset(&newact.sa_mask);    /* no additional signals blocked */
    newact.sa_flags = 0;            /* nothing special on the options */
    if (sigaction(SIGUSR1, &newact, (struct sigaction *)NULL) == -1) {
       perror("Could not install SIGUSR1 signal handler");
       return;
    }
    newact.sa_handler = usr2handler;      /* set the new usr2 handler */
    if (sigaction(SIGUSR2, &newact, (struct sigaction *)NULL) == -1) {
       perror("Could not install SIGUSR2 signal handler");
       return;
    }
    fprintf(stderr,
       "Client process %ld set to use SIGUSR1 and SIGUSR2\n",
       (long)getpid());
}
 
void main(int argc, char *argv[])
{
    u_port_t portnumber;
    int outfd;
    int i;
    ssize_t byteswritten;
    ssize_t byteswrittentot;
    int bytes_copied;
    char bufrecived[1024];
    char bufsend[1024];
       
  if (argc != 3) {
  	fprintf(stderr, "Usage: %s host port\n", argv[0]);
    exit(1);
  }
  byteswrittentot=0;   
  installusrhandlers();
 
  portnumber = (u_port_t)atoi(argv[2]);
 
  if ((outfd = u_connect(portnumber, argv[1])) < 0) {
  	u_error("Unable to establish an Internet connection");
    exit(1);
  }
       
  fprintf(stderr, "Connection has been made to %s\n", argv[1]);
 	strcpy(bufsend,"Prueba 1");
 	byteswritten = u_write(outfd, bufsend, strlen(bufsend));
 	byteswrittentot+= byteswritten;

 	strcpy(bufsend,"prueba 2");
 	byteswritten = u_write(outfd, bufsend, strlen(bufsend));
 	byteswrittentot+= byteswritten;

  u_close(outfd);
  exit(0);
}
