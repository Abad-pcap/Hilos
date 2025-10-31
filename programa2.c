#include <stdio.h>
#include <stdlib.h>
void imprimir_mensaje( void *puntero );
int main() {
char *mensaje1 = "Hola";
char *mensaje2 = "Mundo"; imprimir_mensaje((void *)mensaje1);
imprimir_mensaje((void *)mensaje2); printf("\n");
system("PAUSE");
exit(0);
return 1;
}
void imprimir_mensaje( void *puntero )
{
char *mensaje;
mensaje = (char *) puntero;
printf("%s ", mensaje);
}