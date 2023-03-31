#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"}; // cada componente es un puntero con cajas cargadas?

struct {
    int ProductoID; //Numerado en ciclo iterativo
    int Cantidad; // entre 1 y 10
    char *TipoProducto; // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
} typedef Producto;

struct {
    int ClienteID; // Numerado en el ciclo iterativo
    char *NombreCliente; // Ingresado por usuario
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
    Producto *Productos; //El tamaño de este arreglo depende de la variable
                       // “CantidadProductosAPedir”
} typedef Clientes;

void cargarClientela( Clientes * clientela, int cantClientes);
void cargarProductos(Producto * Producto, int cantProducto );
void mostrado(Clientes *arreglo, int cant);
void fri (Clientes *clientela, int cantClientes);

//<<<<<<<<<<<<<<<<<<<<<<<<<<<< ACÁ MAIN >>>>>>>>>>>>>>>>>>>>>>>>>>>>>

int main (void)
{
    int cantClientes;
    char *buff;
    buff = (char *) malloc (sizeof(char) *100);
    Clientes *clientela;
    srand(time(NULL));
    puts("Ingresa la cantidad de clientes");
    scanf("%d",&cantClientes);
    clientela= (Clientes *) malloc(sizeof(Clientes)*cantClientes);
    cargarClientela(clientela,cantClientes);
    mostrado(clientela,cantClientes);
    fri(clientela,cantClientes);
    return 0;
}





void cargarClientela( Clientes * clientela, int cantClientes)
{

    for (int i = 0; i < cantClientes; i++)
    {
        char nombre[20];
        printf("CLIENTE N %d\n",i+1);
        clientela[i].ClienteID=i;
        printf("nombre: ");
        fflush(stdin);
        gets(nombre);
        clientela[i].NombreCliente = (char *) malloc((strlen(nombre)+1) * sizeof(char));
        strcpy((clientela[i].NombreCliente),nombre);   // sin los parentesis no funciona
        clientela[i].CantidadProductosAPedir = rand () % (5-1)+1;
        clientela[i].Productos= (Producto *)malloc(sizeof(Producto)*clientela[i].CantidadProductosAPedir);
        cargarProductos((clientela[i].Productos),(clientela[i].CantidadProductosAPedir));
        puts("-----------------------");

    }
    
}

void cargarProductos( Producto * Producto, int cantProducto )
{
    for (int i = 0; i < cantProducto; i++)
    {
        Producto[i].ProductoID=i;
        Producto[i].Cantidad= rand () % (10-1)+1;
        Producto[i].TipoProducto = TiposProductos[rand ()% 4]; //es como que le estoy dando una direccion de
                                                               // memoria a tipo producto con las cajas ya cargadas ?
        Producto[i].PrecioUnitario=rand () % (100-10)+10;
    }
    
}

void mostrado( Clientes *arreglo, int cant)
{
    printf("\n\n");
    puts("(((((>>>>>>>>>>>>>>> MOSTRADO >>>>>>>>>>>>>>>)))))");
    printf("\n");
    for (int k = 0; k < cant; k++)
    {
        printf("CLIENTE N: (%d)\n\n", k + 1);
        printf("NOMBRES: %s\n", arreglo[k].NombreCliente);
        printf("CANTIDAD DE PRODUCTOS: %d\n",arreglo[k].CantidadProductosAPedir);
        printf("\n");
        for (int i = 0; i < arreglo[k].CantidadProductosAPedir; i++)
        {
            printf("\tProducto N %d\n", i + 1);
            printf("ID producto: %d\n", arreglo[k].Productos[i].ProductoID);
            printf("Cantidad: %d\n", arreglo[k].Productos[i].Cantidad);
            printf("Tipo de producto: %s\n", arreglo[k].Productos[i].TipoProducto);
            printf("precio unitario: %.2f\n", arreglo[k].Productos[i].PrecioUnitario);
            printf("\n");
        }
        printf("\n");
        puts("===================================");
        printf("\n");
    }
    puts("-----------------------------------");

}
void fri (Clientes *clientela, int cantClientes)
{
    for (int i = 0; i < cantClientes; i++)
    {
       free(clientela[i].Productos);
    }
    free(clientela);
}