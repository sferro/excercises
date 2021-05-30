/*	IMPLEMENTACION CON SOCKETS*/
/*	El programa B.2 es un programa cliente para probar UICI; acepta dos
*	argumentos de lina de comandos, una maquina destino y un numero de
*	puerto. Despues de establecer unba conexion, el cliente envia a la maquina
*	remota todo lo que llega por la entrada estandar. El cliente atrapa
*	las señales SIGUSR1 y SIGUSR2, demostrando que la transmicion funciona
*	correctamente incluso cuando hay señales presente. El programan utiliza
*	bloques de tamaño pequeños para que la transmision de un archivo requiera
*	un gran numero de transferencias incluso si el tamaño de archivo es moderado
*	El cliente termina cuando detecta un fin de archivo en la entrada estandar*/
/* Program B.2 */
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
/*
 *  This is a client test of UICI. It opens a connection
 *  to a machine specified by host and a port number.
 *  It reads a file from stdin in blocks of size BLKSIZE
 *  and outputs it to the connection.
 */
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
 	strcpy(bufsend,"Prueba 1\n");
 	byteswritten = u_write3(outfd, bufsend, strlen(bufsend),10000);
 	byteswrittentot+= byteswritten;
 	bytes_copied =u_read3(outfd, bufrecived, 1024,10000);
 	fprintf(stderr, "Server Envio: %s\n",bufrecived);
 	fprintf(stderr, "Bytes recibidos por el server: %d\n", bytes_copied);
 	strcpy(bufsend,"prueba 2\n");
 	byteswritten = u_write3(outfd, bufsend, strlen(bufsend),10000);
 	byteswrittentot+= byteswritten;
 	bytes_copied =u_read3(outfd, bufrecived, 1024,10000);
 	fprintf(stderr, "Server Envio: %s\n",bufrecived);
   fprintf(stderr, "Bytes recibidos por el server: %d\n", bytes_copied);
  u_close(outfd);
  exit(0);
}
