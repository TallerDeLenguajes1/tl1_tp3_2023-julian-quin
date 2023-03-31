#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main (void)
{
    char *V[5]; // esto es un vector de punteros estatico de 5 elementos
                // por ello no hace falta hacer la reserva dinamica con malloc
                // dentro de este vector en las posiciones no voy a guardar numeros 
                //sino direcciones de memoria (o sea cada elemento de V es un puntero que apunta a algo)
                //matriz semi dinamica (filas estaticas)(columnas dinamicas)
   
    char *buff = (char *)malloc (sizeof(char)*100);

    for (int i = 0; i < 5; i++)
    {
        printf("ingrese un nombre: ");
        gets(buff);
        V[i]= (char *) malloc((strlen(buff)+1) * sizeof(char));
        strcpy(V[i],buff);
    }
    printf("\n\n");
    
    for (int i = 0; i < 5; i++)
    {
        printf("nombre (%d) %s\n",i+1,V[i]);
        free(V[i]);

    }
    free(buff);
    
    
    
    return 0;
}