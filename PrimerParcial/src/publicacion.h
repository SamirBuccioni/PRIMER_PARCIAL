typedef struct
{
    
    int numeroRubro;
    char aviso[64];
    int idAviso;
    int isEmpty;
    char estadoPublicacion[20];
    
    int idCliente;
    
}ePublicacion;

typedef struct
{
	int numeroRubro;
	int isEmpty;
	int contador;

}eRubros;

void hardcodeo (ePublicacion listadoPublicaciones[], int MAXPUBLICACIONES);

void inicializarPublicaciones(ePublicacion listadoPublicaciones[], int MAXPUBLICACIONES);

void inicializarRubros(eRubros listadoRubros[], int MAXPUBLICACIONES);

int buscarLibrePublicacion (ePublicacion listadoPublicaciones[], int MAXPUBLICACIONES);



void imprimirPublicacionesActivasConSusId(ePublicacion listadoPublicaciones[], int MAXPUBLICACIONES);

void imprimirPublicacionesPausadasConSusId(ePublicacion listadoPublicaciones[], int MAXPUBLICACIONES);

int seleccionarPublicacionPorId (ePublicacion listadoPublicaciones[], int MAXPUBLICACIONES);

int buscarLibrePublicacion (ePublicacion listadoPublicaciones[], int MAXPUBLICACIONES);

int generateIdPublicacion (void);

void mostrarCantidadDePublicacionesDeUnRubro (ePublicacion listadoPublicaciones[], int MAXPUBLICACIONES);
