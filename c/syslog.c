#include <stdio.h>
#include <syslog.h>


int main(int argc, char **argv) 
{
  
  openlog("/usr/users/ferros/pruebas/borrarlog.log",  LOG_PID, LOG_DAEMON);
  syslog(LOG_ALERT, "who: internal error 23");
  closelog();
     

  return 0;
}