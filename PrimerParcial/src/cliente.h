typedef struct{
    
    char nombre[51];
    char apellido[51];
    long long int cuit;
    int idCliente;
    int isEmpty;
    
}eCliente;

void altaForzadaCliente(eCliente listadoClientes[], char nombre[], char apellido[], long long int cuit, int idCliente, int isEmpty, int indice);

/*Incializa el isEmpty de todos los clientes en EMPTY*/
void inicializarClientes (eCliente listaClientes[], int MAXCLIENTES);

/*Crea un nuevo dato del tipo eCliente*/
eCliente crearNuevoCliente (void);

/*Carga un dato del tipo eCliente en un array*/
int cargarClienteEnLista (eCliente listaClientes[], int MAXCLIENTES);

/*Permite al usuario modificar un cliente. Puede cancelar la modificacion.
 *Devuelve (-1) si no existe cliente, (0) si cancela modificaciones o no guarda,
 *y (1) si guarda las moficiaciones*/
int modificarUnCliente (eCliente listaClientes[], int MAXCLIENTES);

/*Imprime una lista de todos los clientes, con sus ID al lado*/
void imprimirClientesConSusId (eCliente listaClientes[], int MAXCLIENTES);

/*Le da a seleccionar al usuario un cliente por su numero de ID. Devuelve el indice 
 *de ese ID si lo encuentra, o -1 si no encuentra a un cliente con ese ID.
 */
int seleccionarClientePorId(eCliente listaClientes[], int MAXCLIENTES);

/* Busca un espacio libre en el array otorgado (field isEmpty == EMPTY). Si encuentra
 * un espacio, devuelve el indice donde se encuentra; si no, devuelve (-1)
 */
int buscarLibre (eCliente listaClientes[], int MAXCLIENTES);

/*Genera IDs incrementales empezando desde 1, y sumando 1 mas cada vez que se 
 * llama a esta funcion.
 */
int generateIdCliente (void);
