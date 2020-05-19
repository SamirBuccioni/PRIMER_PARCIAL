#include <stdio.h>
#include "clientepublicacion.h"

#define MAXCLIENTES 100
#define MAXPUBLICACIONES 1000

int main()
{
    eCliente listadoClientes [MAXCLIENTES];
    ePublicacion listadoPublicaciones [MAXPUBLICACIONES];
    eRubros listadoRubros[MAXPUBLICACIONES];
    int opcionMenu;
    int retornoFuncion;
    
    int i;
    
    inicializarClientes(listadoClientes, MAXCLIENTES);
    inicializarPublicaciones(listadoPublicaciones, MAXPUBLICACIONES);
    inicializarRubros(listadoRubros, MAXPUBLICACIONES);

    altaForzadaCliente(listadoClientes, "samir", "buccioni", 20415849576, 1, 0, 0);
    altaForzadaCliente(listadoClientes, "juan", "carlos", 211111111, 2, 0, 1);
    altaForzadaCliente(listadoClientes, "luca", "prodan", 222222222, 3, 0, 2);

    hardcodeo(listadoPublicaciones, MAXPUBLICACIONES);

    
    do
    {
        opcionMenu = printMenu("1.Alta de cliente\n2.Modificar datos cliente\n3.Baja cliente\n4.Publicar\n5.Pausar publicacion\n6.Reanudar publicacion\n7.Imprimir clientes\n8.Imprimir publicaciones\n9.Informar clientes\n10.Informar publicaciones\n11.Salir", 11);
        
        switch (opcionMenu)
        {
            case 1:
            //dar de alta un cliente
            retornoFuncion = cargarClienteEnLista(listadoClientes, MAXCLIENTES);
            switch(retornoFuncion)
            {
                case 0:
                printf("Se ha cargado correctamente el cliente\n");
                break;
                case -1:
                printf("No hay espacio para cargar al cliente\n");
                break;
            }
            break;
            case 2:
            retornoFuncion = modificarUnCliente(listadoClientes, MAXCLIENTES);
            switch(retornoFuncion)
            {
                case 0:
                printf("Las modificaciones sin guardar no se han aplicado.\n");
                break;
                case 1:
                printf("Se ha modificado correctamente al cliente.\n");
                break;
                case -1:
                printf("No hay ningun cliente con ese numero de ID.\n");
                break;
            }
            break;
            case 3:
            retornoFuncion = eliminarUnCliente(listadoClientes, MAXCLIENTES, listadoPublicaciones, MAXPUBLICACIONES);
            switch(retornoFuncion)
            {
                case 0:
                printf("Usted ha cancelado la eliminacion del cliente.\n");
                break;
                case 1: 
                printf("Usted ha eliminado correctamente al cliente.\n");
                break;
                case -1:
                printf("No hay ningun cliente con ese numero de ID.\n");
                break;
            }
            break;
            case 4:
            retornoFuncion = cargarPublicacionEnLista(listadoClientes, MAXCLIENTES, listadoPublicaciones, MAXPUBLICACIONES);
            switch(retornoFuncion)
            {
                case 0:
                printf("Usted ha agregado la publicacion correctamente. \n");
                break;
                case -1:
                printf("No hay espacio para agregar esa publicacion. \n");
                break;
            }
            break;
            case 5:
            retornoFuncion = pausarPublicacion(listadoClientes, MAXCLIENTES, listadoPublicaciones, MAXPUBLICACIONES);
            switch(retornoFuncion)
            {
                case 0: 
                printf("Usted ha cancelado la modificacion de estado de la publicacion. \n");
                break;
                case 1: 
                printf("Usted ha dejado el estado de la publicacion seleccionada como PAUSADO. \n");
                break;
                case -1:
                printf("No hay ninguna publicacion con ese numero de ID. \n");
            }
            break;
            case 6:
            retornoFuncion = reanudarPublicacion(listadoClientes, MAXCLIENTES, listadoPublicaciones, MAXPUBLICACIONES);
            switch(retornoFuncion)
            {
                case 0: 
                printf("Usted ha cancelado la modificacion de estado de la publicacion. \n");
                break;
                case 1: 
                printf("Usted ha dejado el estado de la publicacion seleccionada como ACTIVA. \n");
                break;
                case -1:
                printf("No hay ninguna publicacion con ese numero de ID. \n");
            }
            break;
            case 7:
            imprimirClientesConSusPublicacionesActivas(listadoClientes, MAXCLIENTES, listadoPublicaciones, MAXPUBLICACIONES);
            break;
            case 8:
            imprimirPublicacionesConCuitCliente(listadoClientes, MAXCLIENTES, listadoPublicaciones, MAXPUBLICACIONES);
            break;
            case 9:
            retornoFuncion = printMenu("1.Imprimir cliente con mas avisos activos\n2.Imprimir cliente con mas avisos pausados\n3.Imprimir cliente con mas avisos en total", 3);
            switch(retornoFuncion)
            {
                case 1:
                mostrarClienteConMasPublicacionesActivas(listadoClientes, MAXCLIENTES, listadoPublicaciones, MAXPUBLICACIONES);
                break;
                case 2:
                mostrarClienteConMasPublicacionesPausadas(listadoClientes, MAXCLIENTES, listadoPublicaciones, MAXPUBLICACIONES);
                break;
                case 3:
                mostrarClienteConMasPublicaciones(listadoClientes, MAXCLIENTES, listadoPublicaciones, MAXPUBLICACIONES);
                break;
            }
            
            break;
            case 10:
            retornoFuncion = printMenu("1.Mostrar cantidad de publicaciones de un rubro\n2.Mostrar rubro con mas publicaciones activas\n3.Mostrar rubro con menos publicaciones activas", 3);
            switch(retornoFuncion)
            {
                case 1:
                mostrarCantidadDePublicacionesDeUnRubro(listadoPublicaciones, MAXPUBLICACIONES);
                break;
                case 2:
                mostrarRubroMayorCantidad(listadoRubros, MAXPUBLICACIONES, listadoPublicaciones);
                break;
                case 3:
                break;
            }
            break;
            case 11:
            break;
        }
        
    }while (opcionMenu != 11);

    return 0;
}
