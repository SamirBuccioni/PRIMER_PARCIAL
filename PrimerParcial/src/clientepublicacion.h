#include "cliente.h"
#include "publicacion.h"
#include "userinteractions.h"
#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>

#define EMPTY -1
#define NOTEMPTY 0
#define PUBLICACIONACTIVA "ACTIVA"
#define PUBLICACIONPAUSADA "PAUSADA"

typedef struct
{
    int idCliente;
    int cantidadPublicaciones;
}eAuxiliar;


int eliminarUnCliente (eCliente listadoClientes[], int MAXCLIENTES, ePublicacion listadoPublicaciones[], int MAXPUBLICACIONES);

void imprimirClientesConSusPublicaciones(eCliente listadoClientes[], int MAXCLIENTES, ePublicacion listadoPublicaciones[], int MAXPUBLICACIONES);

/*Crea un nuevo dato del tipo ePublicacion*/
ePublicacion crearNuevaPublicacion (eCliente listadoClientes[], int MAXCLIENTES);

/*Carga un dato del tipo ePublicacion en un array*/
int cargarPublicacionEnLista (eCliente listadoClientes[], int MAXCLIENTES, ePublicacion listadoPublicaciones[], int MAXPUBLICACIONES);

int pausarPublicacion(eCliente listadoClientes[], int MAXCLIENTES, ePublicacion listadoPublicaciones[], int MAXPUBLICACIONES);

int reanudarPublicacion(eCliente listadoClientes[], int MAXCLIENTES, ePublicacion listadoPublicaciones[], int MAXPUBLICACIONES);

void imprimirClientesConSusPublicacionesActivas(eCliente listadoClientes[], int MAXCLIENTES, ePublicacion listadoPublicaciones[], int MAXPUBLICACIONES);

void imprimirPublicacionesConCuitCliente(eCliente listadoClientes[], int MAXCLIENTES, ePublicacion listadoPublicaciones[], int MAXPUBLICACIONES);

void mostrarClienteConMasPublicaciones(eCliente listadoClientes[], int MAXCLIENTES, ePublicacion listadoPublicaciones[], int MAXPUBLICACIONES);

void mostrarClienteConMasPublicacionesActivas(eCliente listadoClientes[], int MAXCLIENTES, ePublicacion listadoPublicaciones[], int MAXPUBLICACIONES);

void mostrarClienteConMasPublicacionesPausadas(eCliente listadoClientes[], int MAXCLIENTES, ePublicacion listadoPublicaciones[], int MAXPUBLICACIONES);

/*Inicializa la cantidad de publicaciones en 0, y asigna un idCliente a cada posicion del array*/
void inicializarAuxiliar (eAuxiliar auxiliarCliente_Publicacion[], eCliente listadoClientes[], int MAXCLIENTES);

/*Recibe la posicion en el array a calcular, y le asigna la cantidad de publicaciones que tiene acorde a su ID*/
int calcularCantidadDePublicaciones(eAuxiliar auxiliarCliente_Publicacion[], int posicionAsignada, ePublicacion listadoPublicaciones[],eCliente listadoClientes[], int MAXPUBLICACIONES);

/*Recibe la posicion en el array a calcular, y le asigna la cantidad de publicaciones ACTIVAS que tiene acorde a su ID*/
int calcularCantidadDePublicacionesActivas(eAuxiliar auxiliarCliente_Publicacion[], int posicionAsignada, ePublicacion listadoPublicaciones[],eCliente listadoClientes[], int MAXPUBLICACIONES);

/*Recibe la posicion en el array a calcular, y le asigna la cantidad de publicaciones PAUSADAS que tiene acorde a su ID*/
int calcularCantidadDePublicacionesPausadas(eAuxiliar auxiliarCliente_Publicacion[], int posicionAsignada, ePublicacion listadoPublicaciones[],eCliente listadoClientes[], int MAXPUBLICACIONES);

/*Calcula la mayor cantidad de publicaciones almacenada en alguna posicion del array auxiliar*/
int calcularMaximoPublicaciones(eAuxiliar auxiliarCliente_Publicacion[], int MAXCLIENTES);

/*Imprime el/los clientes que tengan una cantidad de publicaciones igual al maximo*/
void imprimirClientesConMayorCantidadDePublicaciones(eAuxiliar auxiliarCliente_Publicacion[], eCliente listadoClientes[],int MAXCLIENTES, int maximo);

