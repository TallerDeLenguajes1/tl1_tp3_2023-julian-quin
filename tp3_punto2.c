#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void)
{
    int MTproduccion[5][12];
    int sumaPromedio=0, Vmax=0, Vmin=999999, anioMayor, mesMayor, anioMenor, mesMenor;
    float promedios [5];
    
    srand(time(NULL));

    // cargado

    for (int i = 0; i < 5; i++) //trata las filas
    {
        for (int k = 0; k < 12; k++) //trata las columnas
        {
            MTproduccion[i][k] = rand() % (50000 - 10000) + 1000;
            sumaPromedio += MTproduccion[i][k];
            
            //para el valor maximo
            if (MTproduccion[i][k]> Vmax)
            {
                Vmax=MTproduccion[i][k];
                anioMayor=i+1;
                mesMayor=k+1;
            }
             
            //para el valor minimo 
            if (MTproduccion[i][k]<Vmin)
            {
                Vmin=MTproduccion[i][k];
                anioMenor=i+1;
                mesMenor=k+1;
            }
            
        }
        promedios[i]=(sumaPromedio/12);
        sumaPromedio=0;
    }

    // mostrado

    printf("\t\t\t\t\t>>>>>>>>>>>>>  MESES  >>>>>>>>>>>>>>\n\n");
    for (int i = 0; i < 5; i++)
    {
        printf("anio(%d)->", i + 1);
        for (int k = 0; k < 12; k++)
        {

            printf("%8d", MTproduccion[i][k]);
        }

        printf("\n");
    }

    printf("\nPromedios de gananancia\n");
    for (int j = 0; j < 5; j++)
    {
       printf("promedio del anio (%d) = %.2f\n",j+1,promedios[j]);

    }
    

    printf("\nEl valor maximo de ganancias fue de $ %d en el mes % d del anio %d\n",Vmax,mesMayor,anioMayor);
    printf("El valor minimo de ganancias fue de $ %d en el mes % d del anio %d\n",Vmin,mesMenor,anioMenor);
    return 0;
}
