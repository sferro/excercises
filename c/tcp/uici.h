/*Pagina 599*/
/* Program B.1 */
/*********************************** uici.h **************************/
/*   various definitions required for the UICI functions             */  
/*********************************************************************/
#ifndef UICI_H
#define UICI_H
typedef unsigned short u_port_t;
int u_open(u_port_t port);
int u_listen(int fd, char *hostn);
int u_connect(u_port_t port, char *inetp);
int u_close(int fd);
ssize_t u_read(int fd, void *buf, size_t nbyte);
ssize_t u_read2(int fd, void *buf, size_t size, int timeout);
ssize_t u_read3(int fd, void *buf, size_t size, int timeout);
ssize_t u_write(int fd, void *buf, size_t nbyte);
ssize_t u_write2(int fd, void *buf, size_t size, int timeout);
void u_error(char *s);
int u_sync(int fd);
int copy_from_network_to_file(int communfd, int filefd);

#endif /* UICI_H */
