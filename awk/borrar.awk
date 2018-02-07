BEGIN {
  RS = "%"
  iContador = 0
  iCantidad = 2;  /* Este valor se tendria que pasar como parametro*/
}
{
  if(iContador == iCantidad) {
	print $0
	
  }
	iContador++
}
