/*Imprime el texto que se le pasa en el primer parametro. En el segundo parametro
 * se le debe pasar la cantidad de opciones numericas
 */
int printMenu(char opcionesMenu[], int cantidadOpciones);

/*Imprime el texto del primer parametro, pidiendole el string al usuario. Lo al-
 *-macena en el segundo parametro. En el tercero se declara el largo del string
 */
void getString (char mensaje[], char texto[], int largo);

/*Le pide al usuario por el primer parametro un valor numerico y lo devuelve
 *validado para su uso.
 */
long long int getLongLongInt (char mensaje[], char error[]);

char getChar (char mensaje[], char error[]);

int getInt (char mensaje[]);
