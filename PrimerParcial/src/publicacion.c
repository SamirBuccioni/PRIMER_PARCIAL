#include "clientepublicacion.h"

void hardcodeo (ePublicacion listadoPublicaciones[], int MAXPUBLICACIONES)
{
    int numeroRubro[10] = {1,1,1,2,3,3,4,5,5,5};
    char aviso[10][64] = {"Aviso numero 1","Aviso numero 2","Aviso numero 3","Aviso numero 4","Aviso numero 5","Aviso numero 6","Aviso numero 7","Aviso numero 8","Aviso numero 9","Aviso numero 10"};
    int idAviso[10] = {100,101,102,103,104,105,106,107,108,109};
    int isEmpty[10] = {NOTEMPTY,NOTEMPTY,NOTEMPTY,NOTEMPTY,NOTEMPTY,NOTEMPTY,NOTEMPTY,NOTEMPTY,NOTEMPTY,NOTEMPTY};
    char estadoPublicacion[10][20] = {"ACTIVA","PAUSADA","ACTIVA","PAUSADA","ACTIVA","PAUSADA","ACTIVA","PAUSADA","ACTIVA","PAUSADA"};
    
    int idCliente[10] = {1,1,1,1,2,2,2,2,2,2};
    
    int i;
    
    for (i=0; i<10; i++)
    {
        listadoPublicaciones[i].numeroRubro = numeroRubro[i];
        strcpy(listadoPublicaciones[i].aviso, aviso[i]);
        listadoPublicaciones[i].idAviso = idAviso[i];
        listadoPublicaciones[i].isEmpty = isEmpty[i];
        strcpy(listadoPublicaciones[i].estadoPublicacion, estadoPublicacion[i]);
        listadoPublicaciones[i].idCliente = idCliente[i];
    }

}

void inicializarPublicaciones(ePublicacion listadoPublicaciones[], int MAXPUBLICACIONES)
{
    int i;
    
    for (i=0; i<MAXPUBLICACIONES; i++)
    {
        listadoPublicaciones[i].isEmpty = EMPTY;
    }
}

void inicializarRubros(eRubros listadoRubros[], int MAXPUBLICACIONES)
{
    int i;
    for (i=0; i<MAXPUBLICACIONES; i++)
    {
        listadoRubros[i].numeroRubro = -1001;
        listadoRubros[i].contador = 0;
    	listadoRubros[i].isEmpty = EMPTY;
    }
}

void imprimirPublicacionesActivasConSusId(ePublicacion listadoPublicaciones[], int MAXPUBLICACIONES)
{
    int i;
    
    for (i=0; i<MAXPUBLICACIONES; i++)
    {
        if(listadoPublicaciones[i].isEmpty == NOTEMPTY && strcmp(listadoPublicaciones[i].estadoPublicacion, PUBLICACIONACTIVA)==0)
        {
            printf("ID: %8d -------- AVISO: %20s\n", listadoPublicaciones[i].idAviso, listadoPublicaciones[i].aviso);
        }
    }
}

void imprimirPublicacionesPausadasConSusId(ePublicacion listadoPublicaciones[], int MAXPUBLICACIONES)
{
    int i;
    
    for (i=0; i<MAXPUBLICACIONES; i++)
    {
        if(listadoPublicaciones[i].isEmpty == NOTEMPTY && strcmp(listadoPublicaciones[i].estadoPublicacion, PUBLICACIONPAUSADA)==0)
        {
            printf("ID: %8d -------- AVISO: %20s\n", listadoPublicaciones[i].idAviso, listadoPublicaciones[i].aviso);
        }
    }
}

int seleccionarPublicacionPorId (ePublicacion listadoPublicaciones[], int MAXPUBLICACIONES)
{
    int idSeleccionado;
    int i;
    int returnValue;
    
    printf("Ingrese el ID que desea: ");
    __fpurge(stdin);
    scanf("%d", &idSeleccionado);
    
    for(i=0; i<MAXPUBLICACIONES; i++)
    {
        if(listadoPublicaciones[i].idAviso == idSeleccionado && listadoPublicaciones[i].isEmpty == NOTEMPTY)
        {
            returnValue = i;
            break;
        }
        else
        {
            returnValue = -1;
        }
    }
    
    return returnValue;
    
}

void mostrarCantidadDePublicacionesDeUnRubro (ePublicacion listadoPublicaciones[], int MAXPUBLICACIONES)
{
    int rubroSeleccionado;
    int i;
    int contadorPublicacionesActivas;
    
    contadorPublicacionesActivas = 0;
    
    rubroSeleccionado = getInt("Ingrese el numero de rubro que desee: ");
    
    for (i=0; i<MAXPUBLICACIONES; i++)
    {
        if(listadoPublicaciones[i].numeroRubro == rubroSeleccionado && listadoPublicaciones[i].isEmpty == NOTEMPTY && (strcmp(listadoPublicaciones[i].estadoPublicacion, PUBLICACIONACTIVA)==0))
        {
            printf("ID: %4d ---- Aviso: %30s\n", listadoPublicaciones[i].idAviso, listadoPublicaciones[i].aviso);
            contadorPublicacionesActivas++;
        }
    }
    
    if(contadorPublicacionesActivas == 0)
    {
        printf("No hay ninguna publicacion activa con ese numero de rubro.\n");
    }
    else
    {
        printf("La cantidad de publicaciones activas con ese numero de rubro es %d.\n", contadorPublicacionesActivas);
    }
}


int buscarLibrePublicacion (ePublicacion listadoPublicaciones[], int MAXPUBLICACIONES)
{
    int i;
    int returnValue= -1;
    
    for (i=0; i<MAXPUBLICACIONES; i++)
    {
        if(listadoPublicaciones[i].isEmpty == EMPTY)
        {
            returnValue = i;
            break;
        }
    }
    return returnValue;
}

int generateIdPublicacion (void)
{
    static int generatedId = 0;
    
    generatedId++;
    
    return generatedId;
}
