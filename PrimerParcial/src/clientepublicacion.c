#include "clientepublicacion.h"

void mostrarRubroMayorCantidad(eRubros listadoRubros[],int MAXPUBLICACIONES, ePublicacion listadoPublicaciones[] ){


	int i;
	int j;
	eRubros auxiliar;
	int maximo;

	for(i=0; i<MAXPUBLICACIONES; i++)
	{

		for(j=0; j<MAXPUBLICACIONES; j++)
		{
			if( listadoRubros[i].isEmpty == EMPTY && listadoPublicaciones[j].estadoPublicacion == 'ACTIVA' && listadoRubros[i].numeroRubro != listadoPublicaciones[j].numeroRubro){

			listadoRubros[i].numeroRubro = listadoPublicaciones[j].numeroRubro;
			listadoRubros[i].isEmpty = NOTEMPTY;
			listadoRubros[i].contador ++;
		}
		}
	}
    for (i=0; i<MAXPUBLICACIONES; i++)
    {
    	if(listadoRubros[i].contador > maximo)
    	{
    		maximo = listadoRubros[i].contador;
    	}
    }
    printf ("El/Los rubros con mas publicaciones activas (con %d publicaciones):\n", maximo);
    for (i=0; i<MAXPUBLICACIONES; i++)
        {

                if(listadoRubros[i].contador == maximo&& listadoPublicaciones[i].isEmpty == NOTEMPTY)
                {
                    printf ("- %d\n ", listadoRubros[i].numeroRubro);
                }

        }

}

int eliminarUnCliente (eCliente listadoClientes[], int MAXCLIENTES, ePublicacion listadoPublicaciones[], int MAXPUBLICACIONES)
{
    int indiceSeleccionado;
    char confirmacion;
    int i;
    int returnValue;
    
    imprimirClientesConSusPublicaciones(listadoClientes, MAXCLIENTES, listadoPublicaciones, MAXPUBLICACIONES);
    indiceSeleccionado = seleccionarClientePorId(listadoClientes, MAXCLIENTES); //DEVUELVE -1 si no coincide, o el indice si coincide
    
    if (indiceSeleccionado != -1)
    {
        printf("Usted selecciono al cliente %s %s, con ID %d.\n", listadoClientes[indiceSeleccionado].nombre, listadoClientes[indiceSeleccionado].apellido, listadoClientes[indiceSeleccionado].idCliente);
        confirmacion = getChar("Realmente desea eliminar al cliente con sus productos? [s/n]: ", "Opcion invalida, por favor ingrese nuevamente [s/n]: ");
        
        if (confirmacion == 's')
        {
            listadoClientes[indiceSeleccionado].isEmpty == EMPTY;
            for (i=0; i<MAXPUBLICACIONES; i++)
            {
                if(listadoPublicaciones[i].idCliente == listadoClientes[indiceSeleccionado].idCliente)
                {
                    listadoPublicaciones[i].isEmpty == EMPTY;
                }
            }
            returnValue = 1;
        }
        else
        {
            returnValue = 0;
        }
    }
    else
    {
        returnValue = -1;
    }
    
    return returnValue;
    
}

void imprimirClientesConSusPublicaciones (eCliente listadoClientes[], int MAXCLIENTES, ePublicacion listadoPublicaciones[], int MAXPUBLICACIONES)
{
    int i;
    int j;
    int flagPublicaciones; //Se inicializa en cero, y cambia su valor si el cliente tiene al menos una publicacion.
    
    flagPublicaciones = 0;
    
    for (i=0; i<MAXCLIENTES; i++)
    {
        if(listadoClientes[i].isEmpty == NOTEMPTY)
        {
            printf("ID: %4d -------- CLIENTE: %20s %s -------- CUIT: %12lld\n", listadoClientes[i].idCliente, listadoClientes[i].nombre, listadoClientes[i].apellido, listadoClientes[i].cuit);
            
            for (j=0; j<MAXPUBLICACIONES; j++)
            {
                if(listadoPublicaciones[j].idCliente == listadoClientes[i].idCliente && listadoPublicaciones[j].isEmpty == NOTEMPTY)
                {
                    printf("Rubro: %4d -------- ID del aviso: %4d -------- Aviso: %s -------- Estado: %10s\n", listadoPublicaciones[j].numeroRubro, listadoPublicaciones[j].idAviso, listadoPublicaciones[j].aviso, listadoPublicaciones[j].estadoPublicacion);
                    flagPublicaciones = 1;
                }
                
            }
            
            if(flagPublicaciones == 0)
            {
                printf("Este cliente no tiene publicaciones en este momento.\n");
            }
            
            flagPublicaciones = 0;
        }
    }
}

void imprimirClientesConSusPublicacionesActivas (eCliente listadoClientes[], int MAXCLIENTES, ePublicacion listadoPublicaciones[], int MAXPUBLICACIONES)
{
    int i;
    int j;
    int contadorPublicaciones; //Se inicializa en cero, y cambia su valor si el cliente tiene al menos una publicacion.
    
    contadorPublicaciones = 0;
    
    for (i=0; i<MAXCLIENTES; i++)
    {
        if(listadoClientes[i].isEmpty == NOTEMPTY)
        {
            printf("ID: %4d -------- CLIENTE: %20s %s -------- CUIT: %11lld\n", listadoClientes[i].idCliente, listadoClientes[i].nombre, listadoClientes[i].apellido, listadoClientes[i].cuit);
            
            for (j=0; j<MAXPUBLICACIONES; j++)
            {
                if(listadoPublicaciones[j].idCliente == listadoClientes[i].idCliente && listadoPublicaciones[j].isEmpty == NOTEMPTY)
                {
                    printf("Rubro: %4d -------- ID del aviso: %4d -------- Aviso: %20s -------- Estado: %10s\n", listadoPublicaciones[j].numeroRubro, listadoPublicaciones[j].idAviso, listadoPublicaciones[j].aviso, listadoPublicaciones[j].estadoPublicacion);
                    contadorPublicaciones++;
                }
                
            }
            
            if(contadorPublicaciones == 0)
            {
                printf("Este cliente no tiene publicaciones en este momento.\n");
            }
            else
            {
                printf("Este cliente tiene en total: %d publicaciones\n", contadorPublicaciones);
            }
            
            contadorPublicaciones = 0;
        }
    }
}


ePublicacion crearNuevaPublicacion (eCliente listadoClientes[], int MAXCLIENTES)
{
    ePublicacion nuevaPublicacion;
    int indiceSeleccionado;
    char confirmacion;
    
    imprimirClientesConSusId(listadoClientes, MAXCLIENTES);
    indiceSeleccionado = seleccionarClientePorId(listadoClientes,MAXCLIENTES);
    
    if (indiceSeleccionado == -1)
    {
        confirmacion = getChar("El ID seleccionado no pertenece a ningun cliente. Desea continuar de todas maneras? [s/n]: ", "Error, caracter ingresado invalido, reingrese [s/n]: ");
        if (confirmacion == 's')
        {
            nuevaPublicacion.idCliente = listadoClientes[indiceSeleccionado].idCliente;
        }
        else
        {
            imprimirClientesConSusId(listadoClientes, MAXCLIENTES);
            indiceSeleccionado = seleccionarClientePorId (listadoClientes, MAXCLIENTES);
        }
    }
    else
    {
        nuevaPublicacion.idCliente = listadoClientes[indiceSeleccionado].idCliente;
    }
    
    nuevaPublicacion.numeroRubro = getInt("Ingrese el numero de rubro de la publicacion: ");
    getString("Ingrese el aviso de la publicacion (maximo 64 caracteres): ", nuevaPublicacion.aviso, 65);
    nuevaPublicacion.idAviso = generateIdPublicacion();
    nuevaPublicacion.isEmpty = NOTEMPTY;
    strcpy(nuevaPublicacion.estadoPublicacion, PUBLICACIONACTIVA);
    
    return nuevaPublicacion;
}


int cargarPublicacionEnLista (eCliente listadoClientes[], int MAXCLIENTES, ePublicacion listadoPublicaciones[], int MAXPUBLICACIONES)
{
    int indiceEncontrado;
    ePublicacion publicacionParaCargar;
    int returnValue;
    
    indiceEncontrado = buscarLibrePublicacion(listadoPublicaciones, MAXPUBLICACIONES);
    
    if (indiceEncontrado != -1)
    {
        publicacionParaCargar = crearNuevaPublicacion(listadoClientes, MAXCLIENTES);
        listadoPublicaciones[indiceEncontrado] = publicacionParaCargar;
        returnValue = 0;
    }
    else
    {
        returnValue = -1;
    }
    
    return returnValue;
}


int pausarPublicacion(eCliente listadoClientes[], int MAXCLIENTES, ePublicacion listadoPublicaciones[], int MAXPUBLICACIONES)
{
    int indiceSeleccionado;
    int i;
    char confirmacion;
    int returnValue;
    
    imprimirPublicacionesActivasConSusId(listadoPublicaciones, MAXPUBLICACIONES);
    indiceSeleccionado = seleccionarPublicacionPorId (listadoPublicaciones, MAXPUBLICACIONES);
    
    if(indiceSeleccionado != -1)
    {
        printf("La publicacion pertenece al siguiente cliente: \n");
        
        for(i=0; i<MAXCLIENTES; i++)
        {
            if(listadoPublicaciones[indiceSeleccionado].idCliente == listadoClientes[i].idCliente)
            {
                printf("Nombre y Apellido: %20s %s - ID: %4d\n", listadoClientes[i].nombre, listadoClientes[i].apellido, listadoClientes[i].idCliente);
                break;
            }
        }
        
        confirmacion = getChar("Esta seguro de que desea pausar la publicacion? [s/n]: ", "Error, caracter invalido. Por favor, reingrese [s/n]: ");
        
        if (confirmacion == 's')
        {
            strcpy(listadoPublicaciones[indiceSeleccionado].estadoPublicacion, PUBLICACIONPAUSADA);
            returnValue = 1;
        }
        else
        {
            returnValue = 0;
        }
    }
    else
    {
        returnValue = -1;
    }
    
    return returnValue;
}


int reanudarPublicacion(eCliente listadoClientes[], int MAXCLIENTES, ePublicacion listadoPublicaciones[], int MAXPUBLICACIONES)
{
    int indiceSeleccionado;
    int i;
    char confirmacion;
    int returnValue;
    
    imprimirPublicacionesPausadasConSusId(listadoPublicaciones, MAXPUBLICACIONES);
    indiceSeleccionado = seleccionarPublicacionPorId(listadoPublicaciones, MAXPUBLICACIONES);
    
    if(indiceSeleccionado != -1)
    {
        printf("La publicacion pertenece al siguiente cliente: \n");
        
        for(i=0; i<MAXCLIENTES; i++)
        {
            if(listadoPublicaciones[indiceSeleccionado].idCliente == listadoClientes[i].idCliente)
            {
                printf("Nombre y Apellido: %20s %s - ID: %4d\n", listadoClientes[i].nombre, listadoClientes[i].apellido, listadoClientes[i].idCliente);
                break;
            }
        }
        
        confirmacion = getChar("Esta seguro de que desea pausar la publicacion? [s/n]: ", "Error, caracter invalido. Por favor, reingrese [s/n]: ");
        
        if (confirmacion == 's')
        {
            strcpy(listadoPublicaciones[indiceSeleccionado].estadoPublicacion, PUBLICACIONACTIVA);
            returnValue = 1;
        }
        else
        {
            returnValue = 0;
        }
    }
    else
    {
        returnValue = -1;
    }
    
    return returnValue;
}

void imprimirPublicacionesConCuitCliente(eCliente listadoClientes[], int MAXCLIENTES, ePublicacion listadoPublicaciones[], int MAXPUBLICACIONES)
{
    int i;
    int j;
    
    for(j=0; j<MAXCLIENTES; j++)
    {
        for (i=0; i<MAXPUBLICACIONES; i++)
        {
            if(listadoPublicaciones[i].isEmpty == NOTEMPTY && listadoPublicaciones[i].idCliente == listadoClientes[j].idCliente)
            {
                printf("ID Aviso: %4d ---- Nro de rubro: %4d ---- Aviso: %20s ---- ESTADO: %8s ---- CUIT Cliente: %lld\n", listadoPublicaciones[i].idAviso, listadoPublicaciones[i].numeroRubro, listadoPublicaciones[i].aviso, listadoPublicaciones[i].estadoPublicacion, listadoClientes[j].cuit);
            }
        }
    }
}

void mostrarClienteConMasPublicaciones(eCliente listadoClientes[], int MAXCLIENTES, ePublicacion listadoPublicaciones[], int MAXPUBLICACIONES)
{
    eAuxiliar auxiliarCliente_Publicacion[MAXCLIENTES];
    
    int i;
    int maximo;
    
    inicializarAuxiliar(auxiliarCliente_Publicacion, listadoClientes, MAXCLIENTES);
    
    for (i=0; i<MAXCLIENTES; i++)
    {
        auxiliarCliente_Publicacion[i].cantidadPublicaciones = calcularCantidadDePublicaciones(auxiliarCliente_Publicacion, i, listadoPublicaciones, listadoClientes, MAXPUBLICACIONES);
    }

    maximo = calcularMaximoPublicaciones(auxiliarCliente_Publicacion, MAXCLIENTES);

    printf("Cliente/s con mayor cantidad de publicaciones (mayor cantidad = %d): \n", maximo);
    
    imprimirClientesConMayorCantidadDePublicaciones(auxiliarCliente_Publicacion, listadoClientes, MAXCLIENTES, maximo);
}


void mostrarClienteConMasPublicacionesActivas(eCliente listadoClientes[], int MAXCLIENTES, ePublicacion listadoPublicaciones[], int MAXPUBLICACIONES)
{
    eAuxiliar auxiliarCliente_Publicacion[MAXCLIENTES];
    
    int i;
    int maximo;
    
    inicializarAuxiliar(auxiliarCliente_Publicacion, listadoClientes, MAXCLIENTES);
    
    for (i=0; i<MAXCLIENTES; i++)
    {
        auxiliarCliente_Publicacion[i].cantidadPublicaciones = calcularCantidadDePublicacionesActivas(auxiliarCliente_Publicacion, i, listadoPublicaciones, listadoClientes, MAXPUBLICACIONES);
    }

    maximo = calcularMaximoPublicaciones(auxiliarCliente_Publicacion, MAXCLIENTES);

    printf("Cliente/s con mayor cantidad de publicaciones ACTIVAS (mayor cantidad = %d): \n", maximo);
    
    imprimirClientesConMayorCantidadDePublicaciones(auxiliarCliente_Publicacion, listadoClientes, MAXCLIENTES, maximo);
}

void mostrarClienteConMasPublicacionesPausadas(eCliente listadoClientes[], int MAXCLIENTES, ePublicacion listadoPublicaciones[], int MAXPUBLICACIONES)
{
    eAuxiliar auxiliarCliente_Publicacion[MAXCLIENTES];
    
    int i;
    int maximo;
    
    inicializarAuxiliar(auxiliarCliente_Publicacion, listadoClientes, MAXCLIENTES);
    
    for (i=0; i<MAXCLIENTES; i++)
    {
        auxiliarCliente_Publicacion[i].cantidadPublicaciones = calcularCantidadDePublicacionesPausadas(auxiliarCliente_Publicacion, i, listadoPublicaciones, listadoClientes, MAXPUBLICACIONES);
    }

    maximo = calcularMaximoPublicaciones(auxiliarCliente_Publicacion, MAXCLIENTES);

    printf("Cliente/s con mayor cantidad de publicaciones PAUSADAS (mayor cantidad = %d): \n", maximo);
    
    imprimirClientesConMayorCantidadDePublicaciones(auxiliarCliente_Publicacion, listadoClientes, MAXCLIENTES, maximo);
}


void inicializarAuxiliar (eAuxiliar auxiliarCliente_Publicacion[], eCliente listadoClientes[], int MAXCLIENTES)
{
    int i;
    
    for(i=0; i<MAXCLIENTES; i++)
    {
        auxiliarCliente_Publicacion[i].cantidadPublicaciones = 0;
        auxiliarCliente_Publicacion[i].idCliente = listadoClientes[i].idCliente;
    }
}

int calcularCantidadDePublicaciones(eAuxiliar auxiliarCliente_Publicacion[], int posicionAsignada, ePublicacion listadoPublicaciones[],eCliente listadoClientes[], int MAXPUBLICACIONES)
{
    int returnValue;
    int j;
    
    returnValue = 0;
    
    for(j=0;j<MAXPUBLICACIONES;j++)
    {
        if(listadoPublicaciones[j].idCliente == auxiliarCliente_Publicacion[posicionAsignada].idCliente && listadoPublicaciones[j].isEmpty == NOTEMPTY && listadoClientes[posicionAsignada].isEmpty == NOTEMPTY)
        {
            returnValue++;
        }
    }
    
    return returnValue;
}

int calcularCantidadDePublicacionesActivas(eAuxiliar auxiliarCliente_Publicacion[], int posicionAsignada, ePublicacion listadoPublicaciones[],eCliente listadoClientes[], int MAXPUBLICACIONES)
{
    int returnValue;
    int j;
    
    returnValue = 0;
    
    for(j=0;j<MAXPUBLICACIONES;j++)
    {
        if(listadoPublicaciones[j].idCliente == auxiliarCliente_Publicacion[posicionAsignada].idCliente && listadoPublicaciones[j].isEmpty == NOTEMPTY && listadoClientes[posicionAsignada].isEmpty == NOTEMPTY && (strcmp(listadoPublicaciones[j].estadoPublicacion,PUBLICACIONACTIVA)==0))
        {
            returnValue++;
        }
    }
    
    return returnValue;
}

int calcularCantidadDePublicacionesPausadas(eAuxiliar auxiliarCliente_Publicacion[], int posicionAsignada, ePublicacion listadoPublicaciones[],eCliente listadoClientes[], int MAXPUBLICACIONES)
{
    int returnValue;
    int j;
    
    returnValue = 0;
    
    for(j=0;j<MAXPUBLICACIONES;j++)
    {
        if(listadoPublicaciones[j].idCliente == auxiliarCliente_Publicacion[posicionAsignada].idCliente && listadoPublicaciones[j].isEmpty == NOTEMPTY && listadoClientes[posicionAsignada].isEmpty == NOTEMPTY && (strcmp(listadoPublicaciones[j].estadoPublicacion,PUBLICACIONPAUSADA)==0))
        {
            returnValue++;
        }
    }
    
    return returnValue;
}

int calcularMaximoPublicaciones(eAuxiliar auxiliarCliente_Publicacion[], int MAXCLIENTES)
{
    int i;
    int maximo;
    
    for (i=0; i<MAXCLIENTES; i++)
    {
        if (i==0 || auxiliarCliente_Publicacion[i].cantidadPublicaciones > maximo)
        {
            maximo = auxiliarCliente_Publicacion[i].cantidadPublicaciones;
        }
    }
    
    return maximo;
}

void imprimirClientesConMayorCantidadDePublicaciones(eAuxiliar auxiliarCliente_Publicacion[], eCliente listadoClientes[],int MAXCLIENTES, int maximo)
{
    int i;
    int j;
    
    for (i=0; i<MAXCLIENTES; i++)
    {
        for(j=0; j<MAXCLIENTES; j++)
        {
            if(listadoClientes[j].idCliente == auxiliarCliente_Publicacion[i].idCliente && auxiliarCliente_Publicacion[i].cantidadPublicaciones == maximo && listadoClientes[j].isEmpty == NOTEMPTY)
            {
                printf ("- %s %s\n", listadoClientes[j].nombre, listadoClientes[j].apellido);
            }
        }
    }
}


