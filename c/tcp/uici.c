/* Implementacion completa de UICI en terminos de sockets*/
/* Program B.4 */
/* uici.c  sockets implementation */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <errno.h>
#include "uici.h"

#include  <sys/times.h>
#include  <sys/select.h>
  
#define MAXBACKLOG 5

#define BLKSIZE 1024

int copy_from_network_to_file(int communfd, int filefd)
{
   int bytes_read;
   int bytes_written;
   int bytes_to_write;
   int total_bytes = 0;
   char buf[BLKSIZE];
   char *bufp;

   for ( ; ; ) {
      if ((bytes_read = u_read(communfd, buf, BLKSIZE)) < 0) {
         u_error("Server read error");
         break;
    	} 
    	else if (bytes_read == 0) {
         fprintf(stderr, "Network end-of-file\n");
         break;
    	}
   	 	else {    /* allow for interruption of write by signal */
         for (bufp = buf, bytes_to_write = bytes_read;
            bytes_to_write > 0;
            bufp += bytes_written, bytes_to_write -= bytes_written){
            bytes_written = write(filefd, bufp, bytes_to_write);
            if ((bytes_written) == -1 && (errno != EINTR)){
               perror("Server write error");
               break;
            } 
            else if (bytes_written == -1)
               bytes_written = 0;
            total_bytes += bytes_written;
         }
         if (bytes_written == -1)
            break;
      }
   }   
   return total_bytes;
}

int copy_from_network_to_file2(int communfd, int filefd)
{
   int bytes_read;
   int bytes_written;
   int bytes_to_write;
   int total_bytes = 0;
   char buf[BLKSIZE];
   char *bufp;

/*  for ( ; ; ) {*/
      if ((bytes_read = u_read(communfd, buf, BLKSIZE)) < 0) {
         u_error("Server read error");
/*         break;*/
    	} 
    	else if (bytes_read == 0) {
         fprintf(stderr, "Network end-of-file\n");
/*         break;*/
    	}
   	 	else {    /* allow for interruption of write by signal */
         for (bufp = buf, bytes_to_write = bytes_read;
            bytes_to_write > 0;
            bufp += bytes_written, bytes_to_write -= bytes_written){
            bytes_written = write(filefd, bufp, bytes_to_write);
            if ((bytes_written) == -1 && (errno != EINTR)){
               perror("Server write error");
               break;
            } 
            else if (bytes_written == -1)
               bytes_written = 0;
            total_bytes += bytes_written;
         }
 /*        if (bytes_written == -1)*/
 /*           break;*/
      }
 /*  }   */
   return total_bytes;
}

/* return 1 if error, 0 if OK */
int u_ignore_sigpipe()
{
   struct sigaction act;

   if (sigaction(SIGPIPE, (struct sigaction *)NULL, &act) < 0)
      return 1;
   if (act.sa_handler == SIG_DFL) {
      act.sa_handler = SIG_IGN;
      if (sigaction(SIGPIPE, &act, (struct sigaction *)NULL) < 0)
         return 1;
   }   
   return 0;
}

/*
 *                           u_open
 * Return a file descriptor which is bound to the given port.
 *
 * parameter:
 *        s = number of port to bind to
 * returns:  file descriptor if successful and -1 on error
 */
int u_open(u_port_t port)
{
   int sock;
   struct sockaddr_in server;
 
   if ( (u_ignore_sigpipe() != 0) ||
        ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) )
      return -1;
       
   server.sin_family = AF_INET;
   server.sin_addr.s_addr = INADDR_ANY;
   server.sin_port = htons((short)port);
 
   if ( (bind(sock, (struct sockaddr *)&server, sizeof(server)) < 0) ||
        (listen(sock, MAXBACKLOG) < 0) )
      return -1;
   return sock;
}

/*
 *                           u_listen
 * Listen for a request from a particular host on a specified port.
 *
 * parameters:
 *      fd = file descriptor previously bound to listening port
 *      hostn = name of host to listen for
 * returns:  communication file descriptor or -1 on error
 *
 * comments: This function is used by the server to listen for
 * communication.  It blocks until a remote request is received
 * from the port bound to the given file descriptor.
 * hostn is filled with an ASCII string containing the remote
 * host name.  It must point to s string which is large enough to
 * hold this name.
 */
int u_listen(int fd, char *hostn)
{
   struct sockaddr_in net_client;
   int len = sizeof(struct sockaddr);
   int retval;
   struct hostent *hostptr;
 
   while ( ((retval =
           accept(fd, (struct sockaddr *)(&net_client), &len)) == -1) &&
          (errno == EINTR) )
      ;
   if (retval == -1)
      return retval;
   hostptr =
      gethostbyaddr((char *)&(net_client.sin_addr.s_addr), 4, AF_INET);
   if (hostptr == NULL)
      strcpy(hostn, "unknown");
   else
      strcpy(hostn, (*hostptr).h_name);
   return retval;
}

/*
 *                           u_connect
 * Initiate communication with a remote server.
 *
 * parameters:
 *     port  = well-known port on remote server
 *     inept = character string giving the Internet name of the
 *             remote machine
 * returns: the file descriptor used for communication or -1 if error
 */
int u_connect(u_port_t port, char *hostn)
{
   struct sockaddr_in server;
   struct hostent *hp;
   int sock;
   int retval;
 
   if ( (u_ignore_sigpipe() != 0) ||
        !(hp = gethostbyname(hostn)) ||
        ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) )
      return -1;
       
   memcpy((char *)&server.sin_addr, hp->h_addr_list[0], hp->h_length);
 
   server.sin_port = htons((short)port);
   server.sin_family = AF_INET;
 
   while ( ((retval =
       connect(sock, (struct sockaddr *)&server, sizeof(server))) == -1)
        && (errno == EINTR) )
      ;
   if (retval == -1) {
        close(sock);
        return -1;
   }
   return sock;
}
 
/*
 *                           u_close
 * Close communication for the given file descriptor.
 * parameter:
 *       fd = file descriptor of socket connection to be closed
 * returns:
 *       a negative value indicates an error occurred
 */
 
int u_close(int fd)
{
   return close(fd);
}

/*
 *                           u_read
 *
 * Retrieve information from a file descriptor opened by u_open.
 *
 * parameters:
 *       fd = file descriptor
 *       buf = buffer to be output
 *       nbyte = number of bytes to retrieve
 * returns:
 *      a negative value indicates an error occurred
 *      otherwise the number of bytes read is returned
 */
 
ssize_t u_read(int fd, void *buf, size_t size)
{
   ssize_t retval;
 
   while (retval = read(fd, buf, size), retval == -1 && errno == EINTR)
     ;
   return retval;
}    


/*
 *                           u_read2
 *	Modificado
 *	para que funcione con la funcion SELECT
 * Retrieve information from a file descriptor opened by u_open.
 *
 * parameters:
 *       fd = file descriptor
 *       buf = buffer to be output
 *       nbyte = number of bytes to retrieve
 * returns:
 *      a negative value indicates an error occurred
 *      otherwise the number of bytes read is returned
 */
ssize_t u_read2(int fd, void *buf, size_t size, int timeout)
{
   ssize_t retval;
   struct timeval to;
   int vr;
   fd_set readset;
   FD_ZERO(&readset);
   FD_SET(fd, &readset);
   to.tv_sec = timeout / 1000;
   to.tv_usec = (timeout % 1000) * 1000;
   vr = select(1, &readset, NULL, NULL, &to);
   if (vr == -1) {
   	printf("select ret -1\n");
   	perror("uici u_read2\n");
   	return -1;
   }
   if (!vr) {
   	printf("Resultado de select es: %d\n", vr);
   	printf("uici u_read2: timeout cumplido\n");
   	retval = read(fd, buf, size);   
  		printf("read retorno %d\n", retval);
   	return retval;
   }

}

/*
 *                           u_read3
 *	Modificado
 *	para que funcione con la funcion SELECT
 * Retrieve information from a file descriptor opened by u_open.
 *
 * parameters:
 *       fd = file descriptor
 *       buf = buffer to be output
 *       nbyte = number of bytes to retrieve
 * returns:
 *      a negative value indicates an error occurred
 *      otherwise the number of bytes read is returned
 */
ssize_t u_read3(int fd, void *buf, size_t size, int timeout)
{
   int maxfd;
   ssize_t retval;
   struct timeval to;
   int vr;
   fd_set readset;
   to.tv_sec = timeout / 1000; 
   to.tv_usec = (timeout % 1000) * 1000;
  	FD_ZERO(&readset);
  	FD_SET(fd, &readset);
  	maxfd=fd;
  	if((select(maxfd+1, &readset, NULL, NULL, &to)==-1) && (errno!=EINTR)) {
  		printf("select ret -1\n");
  		perror("uici u_read3\n");
  	}
  	else {
 		if(FD_ISSET(fd, &readset)) {
			printf("Resultado de FD_ISSET= %d\n", FD_ISSET(fd, &readset));
  			printf("uici u_read3: timeout cumplido\n");
  			retval = read(fd, buf, size);   
			printf("read retorno %d\n", retval);
			return retval;
  		}	
	}
}
	


/*
 *                           u_write
 *
 * Send information on a file descriptor opened by u_open.
 *
 * parameters:
 *       fd = file descriptor
 *       buf = buffer to be output
 *       nbyte = number of bytes to send
 * returns:
 *      a negative value indicates an error occurred
 *      otherwise the number of bytes written is returned
 */
 
ssize_t u_write(int fd, void *buf, size_t size)
{
   ssize_t retval;
 
   while (retval = write(fd, buf, size), retval == -1 && errno == EINTR)
      ;
   return retval;
}     

/*
 *                           u_write2
 *	Modificado
 *	para que funcione con la funcion SELECT
 * Send information on a file descriptor opened by u_open.
 *
 * parameters:
 *       fd = file descriptor
 *       buf = buffer to be output
 *       nbyte = number of bytes to send
 * returns:
 *      a negative value indicates an error occurred
 *      otherwise the number of bytes written is returned
 */
ssize_t u_write2(int fd, void *buf, size_t size, int timeout)
{
   ssize_t retval;
   struct timeval to;
   int vr;
   fd_set writeset;
   FD_ZERO(&writeset);
   FD_SET(fd, &writeset);
   to.tv_sec = timeout / 1000;
/*   to.tv_usec = 0;   */
   to.tv_usec = (timeout % 1000) * 1000;
   vr = select(1, NULL, &writeset, NULL, &to);
   if (vr == -1) {
   	printf("select ret -1\n");
   	perror("uici u_write2\n");
   	return -1;
   }
   if (!vr) {
   	printf("uici u_write2: timeout cumplido\n");
   	retval = write(fd, buf, size);   
  		printf("write retorno %d\n", retval);
   	return retval;
   }

}

/*
 *                           u_write3
 *	Modificado
 *	para que funcione con la funcion SELECT
 * Send information on a file descriptor opened by u_open.
 *
 * parameters:
 *       fd = file descriptor
 *       buf = buffer to be output
 *       nbyte = number of bytes to send
 * returns:
 *      a negative value indicates an error occurred
 *      otherwise the number of bytes written is returned
 */
ssize_t u_write3(int fd, void *buf, size_t size, int timeout)
{
   int maxfd;
   ssize_t retval;
   struct timeval to;
   int vr;
   fd_set writeset;
   to.tv_sec = timeout / 1000; 
   to.tv_usec = (timeout % 1000) * 1000;
  	FD_ZERO(&writeset);
  	FD_SET(fd, &writeset);
  	maxfd=fd;
  	if((select(maxfd+1, NULL, &writeset, NULL, &to)==-1) && (errno!=EINTR)) {
  		printf("select ret -1\n");
  		perror("uici u_write3\n");
  	}
  	else {
 		if(FD_ISSET(fd, &writeset)) {
			printf("Resultado de FD_ISSET= %d\n", FD_ISSET(fd, &writeset));
  			printf("uici u_write3: timeout cumplido\n");
  			retval = write(fd, buf, size);   
			printf("read retorno %d\n", retval);
			return retval;
  		}	
	}
}

/*
 *                           u_error
 *  Display an error message in the manner of perror or t_error.
 *
 *  parameter:
 *          s =  string to be prepended to system error message
 *  returns:    0
 *
 *  algorithm:  Since the only type of error comes from a system call,
 *              we only need to call perror.  This implementation should
 *              be as MT-safe as the underlying sockets.
 */

void u_error(char *s)
{
   perror(s);
}

/*
 *                           u_sync
 *
 * This function must be called after an exec or a dup to attach an
 * opened file descriptor in simple UICI implementations.  It is not
 * needed for sockets.
 *
*/
/*ARGSUSED*/
int u_sync(int fd)
{
/* Not needed for sockets, retained for compatibility */
   return 0;
}
