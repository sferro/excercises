#Primer programa en AWK
#Programa de prueba

BEGIN {
	print "Hola Mundo";
	print "esto es una prueba";
	print ARGC;
	for (i=0;i<ARGC;i++) {
		print ARGV[i];
	}
}
