#Desarrollado por Merlus - i
BEGIN { dia_anterior = 0 }
{
  if ( $3 != dia_anterior )
  {
	print renglon_dia;
	renglon_dia = sprintf("%s %s\t", $2, $3);
	dia_anterior = $3;
  }
  renglon_dia = sprintf( "%s\t%s", renglon_dia, $4) ;
}					   
END { print renglon_dia }
