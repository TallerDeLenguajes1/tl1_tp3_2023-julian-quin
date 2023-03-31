#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(void)
{
    char **V;
    char *buff = (char *)malloc(sizeof(char) * 100); //var aux
    int cantPersonas;

    puts("ingrese la cantidad de personas");
    scanf("%d", &cantPersonas);

    // reservo la cantidad de elementos (punteros) que tendrá el Vector v ( o sea filas puntero)
    // v[n]={puntero1,puntero2,..., puntero n}

    V = (char **) malloc(sizeof(char *) * cantPersonas);

    for (int i = 0; i < cantPersonas; i++)
    {
        printf("ingrese un nombre: ");
        fflush(stdin);
        gets(buff);
        V[i]= (char*)malloc(sizeof(char) * strlen(buff +1)); // reservo la cantidad exacta de columnas, un puntero n
                                                             //apuntará a la direccion de memoria de la primera columna
        strcpy(V[i], buff);
    }

    printf("\n\n");

    for (int i = 0; i < cantPersonas; i++)
    {
        printf("nombre (%d) %s\n", i + 1, V[i]);
        free(V[i]);
    }
    free(V);
    free(buff);

    return 0;
}