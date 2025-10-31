#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct param
{
char *mensaje;
pthread_t hilo;
} param_t;
void * imprimir_mensaje( void *puntero )
{
param_t *datos;
datos = (param_t *) puntero;
if (datos->hilo != 0)
pthread_join( datos->hilo, NULL );
printf("%s ", datos->mensaje);
pthread_exit( 0 );
}
int main()
{
pthread_t hilo1, hilo2;
param_t mensaje1 = {"Hola", 0};
param_t mensaje2 = {"Mundo", 0};
pthread_create(&hilo1,NULL,imprimir_mensaje,(void*)&mensaje1);
mensaje2.hilo = hilo1;
pthread_create(&hilo2,NULL,imprimir_mensaje,(void*)&mensaje2);
pthread_join( hilo2, NULL );
system("PAUSE");
exit(0);
return 1;
}