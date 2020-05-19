#include <string.h>
#include <stdio.h>
#include <stdio_ext.h>
#include <ctype.h>

int printMenu(char opcionesMenu[], int cantidadOpciones)
{
    int opcionElegida;
    
    printf("%s\n", opcionesMenu);
    printf("Ingrese la opcion que desea: ");
    __fpurge(stdin);
    scanf("%d", &opcionElegida);
    
    while (opcionElegida > cantidadOpciones || opcionElegida < 1)
    {
        printf("Error, opcion invalida. Por favor, reingrese la opcion que desea: ");
        __fpurge(stdin);
        scanf("%d", &opcionElegida);
    }
    
    return opcionElegida;
}

void getString (char mensaje[], char texto[], int largo)
{
    printf("%s", mensaje);
    __fpurge(stdin);
    fgets(texto, largo, stdin);
    texto[strlen(texto)-1]='\0';
}

long long int getLongLongInt (char mensaje[], char error[])
{
    long long int returnValue;
    
    printf("%s", mensaje);
    __fpurge(stdin);
    scanf("%lld", &returnValue);
    
    return returnValue;
}

char getChar (char mensaje[], char error[])
{
    char opcionSeleccionada;
    int returnValue;
    
    printf("%s", mensaje);
    __fpurge(stdin);
    scanf("%c", &opcionSeleccionada);
    returnValue = tolower(opcionSeleccionada);
    
    while(returnValue != 115 && returnValue != 110)
    {
        printf("%s", error);
        __fpurge(stdin);
        scanf("%c", &opcionSeleccionada);
        returnValue = tolower(opcionSeleccionada);
    }
    
    return returnValue;
}

int getInt (char mensaje[], char error[])
{
    int returnValue;
    
    printf("%s", mensaje);
    __fpurge(stdin);
    scanf("%d", &returnValue);
    
    return returnValue;
}
