#include "clientepublicacion.h"

void inicializarClientes (eCliente listaClientes[], int MAXCLIENTES)
{
    int i;
    
    for (i=0; i<MAXCLIENTES; i++)
    {
        listaClientes[i].isEmpty = EMPTY;
    }
}

void altaForzadaCliente(eCliente listadoClientes[], char nombre[], char apellido[], long long int cuit, int idCliente, int isEmpty, int indice)
{
	int respuesta = -1;
	eCliente buffer;

	strncpy(buffer.nombre,nombre,51);
	strncpy(buffer.apellido,apellido,51);
	buffer.cuit = cuit;
	buffer.idCliente = idCliente;
	buffer.isEmpty = isEmpty;
	listadoClientes[indice]=buffer;
}



eCliente crearNuevoCliente (void)
{
    eCliente nuevoCliente;
    
    getString("Ingrese el nombre del cliente: ", nuevoCliente.nombre, 51);
    getString("Ingrese el apellido del cliente: ", nuevoCliente.apellido, 51);
    nuevoCliente.cuit = getLongLongInt("Ingrese el CUIT del cliente (solo numeros): ", "Error, CUIT invalido");
    nuevoCliente.idCliente = generateIdCliente();
    nuevoCliente.isEmpty = NOTEMPTY;
    
    return nuevoCliente;
}

int cargarClienteEnLista (eCliente listaClientes[], int MAXCLIENTES)
{
    int indiceEncontrado;
    int returnValue;
    eCliente clienteParaCargar;
    
    indiceEncontrado = buscarLibre(listaClientes, MAXCLIENTES);
    
    if (indiceEncontrado != -1)
    {
        clienteParaCargar = crearNuevoCliente();
        listaClientes[indiceEncontrado] = clienteParaCargar;
        returnValue = 0;
    }
    else
    {
        returnValue = -1;
    }
    
    return returnValue;
}


int modificarUnCliente (eCliente listaClientes[], int MAXCLIENTES)
{
    int indiceSeleccionado;
    int returnValue;
    eCliente auxCliente;
    int opcionSeleccionada;
    char confirmacion;
    
    imprimirClientesConSusId(listaClientes, MAXCLIENTES);
    indiceSeleccionado = seleccionarClientePorId(listaClientes, MAXCLIENTES);
    auxCliente = listaClientes[indiceSeleccionado];
    returnValue = 0;
    
    if (indiceSeleccionado != -1) //da opciones para modificar
    {
        printf("Usted ha seleccionado al cliente %s %s, con ID %d\n", listaClientes[indiceSeleccionado].nombre, listaClientes[indiceSeleccionado].apellido, listaClientes[indiceSeleccionado].idCliente);
        
        do
        {
            opcionSeleccionada = printMenu("1.Modificar nombre\n2.Modificar apellido\n3.Modificar CUIT\n4.Previsualizar cambios\n5.Cancelar modificaciones\n6.Guardar modificaciones\n7.Salir", 7);
            
            switch(opcionSeleccionada)
            {
                case 1:
                getString("Ingrese el nuevo nombre: ", auxCliente.nombre, 51);
                break;
                case 2:
                getString("Ingrese el nuevo apellido: ", auxCliente.apellido, 51);
                break;
                case 3:
                auxCliente.cuit = getLongLongInt("Ingrese el nuevo CUIT del cliente: ", "Error, el CUIT no es valido, reingrse: ");
                break;
                case 4:
                printf("El cliente que selecciono era:\n-Nombre: %s // -Apellido: %s // -CUIT: %lld\n", listaClientes[indiceSeleccionado].nombre, listaClientes[indiceSeleccionado].apellido, listaClientes[indiceSeleccionado].cuit);
                printf("Con las modificaciones aplicadas, sera:\n-Nombre: %s // -Apellido: %s // -CUIT: %lld\n", auxCliente.nombre, auxCliente.apellido, auxCliente.cuit);
                break;
                case 5:
                confirmacion = getChar("Una vez cancelados los cambios, no podra recuperarlos. Esta seguro? [s/n]", "Error, respuesta invalida, reingrese [s/n]: ");
                if (confirmacion == 's')
                {
                    printf("Se han cancelado los cambios. Puede recomenzar las modificaciones o salir.\n");
                    auxCliente = listaClientes[indiceSeleccionado];
                    returnValue = 0;
                }
                else
                {
                    printf("Usted no ha cancelado los cambios.\n");
                    returnValue = 0;
                }
                break;
                case 6:
                confirmacion = getChar("Una vez guardados los cambios, no podra cancelarlos. Esta seguro? [s/n]: ", "Error, respuesta invalida, reingrese [s/n]: ");
                if (confirmacion == 's')
                {
                    printf("Se han guardado los cambios, ya puede salir.\n");
                    listaClientes[indiceSeleccionado] = auxCliente;
                    returnValue = 1; 
                }
                else
                {
                    printf("Los cambios aun no han sido guardados.\n");
                    returnValue = 0;
                }
                break;
            }
            
        }while(opcionSeleccionada!=7);
        
        
    }
    else
    {
        returnValue = -1; //no existe cliente activo con ese ID
    }
    
    return returnValue;
    
}

/*Imprime una lista de todos los clientes, con sus ID al lado*/
void imprimirClientesConSusId(eCliente listaClientes[], int MAXCLIENTES)
{
    int i;
    
    for (i=0; i<MAXCLIENTES; i++)
    {
        if(listaClientes[i].isEmpty == NOTEMPTY)
        {
            printf("ID: %8d -------- NOMBRE: %20s %s\n", listaClientes[i].idCliente, listaClientes[i].nombre, listaClientes[i].apellido);
        }
    }
}

/*Le da a seleccionar al usuario un cliente por su numero de ID. No sale de la
 *funcion hasta que no selecciona un ID correcto.
 */
int seleccionarClientePorId (eCliente listaClientes[], int MAXCLIENTES)
{
    int idSeleccionado;
    int i;
    int returnValue;
    
    printf("Ingrese el ID que desea: ");
    scanf("%d", &idSeleccionado);
    
    for(i=0; i<MAXCLIENTES; i++)
    {
        if(listaClientes[i].idCliente == idSeleccionado && listaClientes[i].isEmpty == NOTEMPTY)
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

int buscarLibre (eCliente listaClientes[], int MAXCLIENTES)
{
    int i;
    int returnValue;
    
    for (i=0; i<MAXCLIENTES; i++)
    {
        if(listaClientes[i].isEmpty == EMPTY)
        {
            returnValue = i;
            break;
        }
        else
        {
            returnValue = -1;
        }
    }
}

int generateIdCliente (void)
{
    static int generatedId = 0;
    
    generatedId++;
    
    return generatedId;
}
