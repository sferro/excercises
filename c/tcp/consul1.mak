USUARIO = pais/nueva@BNDESA

PROGNAME= consul1

PCINC= include=$(ORACLE_HOME)/precomp/public \
	include=$(ORACLE_HOME)/plsql/public

PCFLG= release_cursor=YES unsafe_null=YES dbms=V8 sqlcheck=full \
        maxopencursors=255 ireclen=300 oreclen=300 \
	userid=$(USUARIO)

CINC= -I$(ORACLE_HOME)/precomp/public \
	-I$(ORACLE_HOME)/plsql/public

CFLG= -c -D_POSIX_C_SOURCE

LFLG= -L/opt/SUNWspro/lib -L$(ORACLE_HOME)/network/lib/ -L$(ORACLE_HOME)/lib \
#        -lsql -lconnect -lnetdir -lnnccj 
#        -lsocket -lclntsh -lnsl -lm -L 


PROCLIBS = -lgeneric8 -lsunmath -lCstd -lsunmath_mt -lsqlplus -lclient8 -lserver8 -lsocket -lclntsh -lnsl -lm -lsql8 -lcore8 -lc

#LIBS= -L$(ORACLE_HOME)/usr/users/app/oracle/product/8.0.5/precomp/lib
LIBS =-L$(ORACLE_HOME)/lib \
    -L$/opt/SUNWspro/lib \
    -L$(ORACLE_HOME)/network/lib \
    -L$(ORACLE_HOME)/lib/osntab.o \
    $(PROCLIBS)

CFLAGS = $(CFLG)

PROC= proc

PCSRC= $(PROGNAME).pc

CSRC=

PCOBJ= $(PROGNAME).o

COBJ=

.SUFFIXES: .pc 

all : $(PROGNAME)

.c.o:
	@echo "Compiling $<"
	$(CC) $(CFLG) $(CINC) $<

.pc.o:
	@echo "$< -->"
	$(PROC) $(PCINC) $(PCFLG) iname=$*.pc oname=$*.c
	$(CC) $(CFLG) $(CINC) $*.c

.pc.c:
	@echo "Traduciendo...  $< -->"
	$(PROC) $(PCINC) $(PCFLG) iname=$*.pc oname=$*.c

$(PROGNAME) : $(PROGNAME).o 
	cc -o $@ $(LIBS) $(PROGNAME).o uici.o

#$(AR) -r $@ $(COBJ) $(PCOBJ)
#mv $@ ../../../slib

clean:
	rm -f *.o 