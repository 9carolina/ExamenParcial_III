//Obtener la suma de las veces que aparece cada palabra, a partir de los datos del CVS.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define C_MAX 3200 
#define FILAS_N 50 
#define LINEA_LONG 10240 
int main(){
    FILE *file=fopen("emails.csv", "r");
    if (!file){
        perror("Error al abrir el archivo CSV");
        return 1;
    }

    char mat[LINEA_LONG];
    char *nom[C_MAX]; 
    int cont[C_MAX]={0}; 
    int id=350; 
    
    if (fgets(mat, sizeof(mat), file)){
        char *token=strtok(mat, ",");
        int columna=0;
        while (token && columna <= C_MAX){
            nom[columna]=strdup(token); 
            token=strtok(NULL, ",");
            columna++;
        }
    }

	int cFila;
    for (cFila=0; cFila <= id && fgets(mat, sizeof(mat), file); ++cFila);
    
    for (cFila=0; cFila<FILAS_N && fgets(mat, sizeof(mat), file); ++cFila){
        char *token=strtok(mat, ",");
        int columna=0;
        while (token && columna<C_MAX){
            cont[columna] += atoi(token);  
            token=strtok(NULL, ",");
            columna++;
        }
    }
    fclose(file);
    
	int i;
    FILE *archivoFinal=fopen("179350.txt", "w");
    if (!archivoFinal){
        perror("Error al abrir el archivo de salida");
        for ( i=0; i<C_MAX; i++){
            free(nom[i]);
        }
        return 1;
    }

    for (i=0; i<C_MAX && nom[i] != NULL; i++){
        fprintf(archivoFinal, "%s, %d\n", nom[i], cont[i]);
        free(nom[i]); 
    }

    fclose(archivoFinal);
    printf("El archivo con los valores totales del 350 al 400 esta escrito en 179350.txt\n");

    return 0;
}
