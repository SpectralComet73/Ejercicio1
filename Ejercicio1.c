//Ejercicio1 - Subir a un repositorio en github
//Elaborar un programa en C que realice lo siguiente:
//1.Proporcione una funcion que genere un arreglo de numeros enteros aleatorios de tamano dado por el usuario.
//2.Proporcione una funcion que imprima el contenido de cualquier arreglo.
//3.Proporcione almenos una funcion de busqueda secuencial empleando el arreglo del punto 1.
//4.Ofrezca una funcion de ordenamiento, probar con el arreglo del punto 1.
//5.Estimar el tiempo de ejecucion total del programa.

//Nombre: Rendon Sierra Carlos Alexis    Grupo: 3BV2     Boleta: 2022630725


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generarArreglo(int arreglo[],int tam);
void imprimirArreglo(int arreglo[],int tam);
void busquedaSecuencial(int arreglo[],int tam,int elemento);
void ordenamientoInsercion(int arreglo[],int tam);

int main()
{
    clock_t inicio=clock();    
    // Se solicita al usuario el tamano del arreglo a generar
    int tam;
    printf("\nIngrese el tamano del arreglo: \n");
    scanf("%d",&tam);
    int arreglo[tam];
    // Se llama a la funcion generarArreglo para generar el arreglo
    generarArreglo(arreglo,tam);
    // Se llama a la funcion imprimirArreglo para mostrar el contenido del arreglo
    imprimirArreglo(arreglo,tam);
    int elemento;
    // Se solicita al usuario el elemento a buscar en el arreglo
    printf("\nIngrese el elemento a buscar: \n");
    scanf("%d",&elemento);
    //Se aplica la funcion busquedaSecuencial para buscar el elemento ingresado en el arreglo
    busquedaSecuencial(arreglo,tam,elemento);
    //Se aplica la funcion ordenamientoInsercion para ordenar el arreglo de menor a mayor
    ordenamientoInsercion(arreglo,tam);
    //Se llama a la funcion imprimirArreglo para mostrar el contenido del arreglo ya ordenado
    imprimirArreglo(arreglo,tam);
    clock_t fin=clock();
    double tiempo=(double)(fin-inicio)/CLOCKS_PER_SEC;
    printf("\n");
    //Se muestra el tiempo de ejecucion del programa
    printf("Tiempo de ejecucion: %f segundos ", tiempo);
    return 0;
}

//La funcion generarArreglo recibe un arreglo y un tamano, y llena el arreglo del tamano dado con numeros aleatorios entre 1 y 100
void generarArreglo(int arreglo[],int tam)
{
    srand(time(NULL));
    for(int i=0;i<tam;i++)
    {   
        //Asigna un numero aleatorio entre 1 y 100 a la posicion i del arreglo
        arreglo[i]= 1 + rand() % (100-1+1);
    }
}
//La funcion imprimirArreglo recibe un arreglo y un tamano, y muestra el contenido del arreglo
void imprimirArreglo(int arreglo[],int tam)
{
    for(int i=0;i<tam;i++)
    {
        //Devuelve el contenido del arreglo en la posicion i
        printf("\nEl valor %d del arreglo es: %d\n",i+1,arreglo[i]);
    }
}

//La funcion busquedaSecuencial recibe un arreglo, un tamano y un numero, y busca el numero en el arreglo,
// si lo encuentra devuelve 1, si no lo encuentra devuelve -1
void busquedaSecuencial(int arreglo[],int tam,int numero)
{
    for(int i=0;i<tam;i++)
    {
        if(numero==arreglo[i])
        {
            //Devuelve la posicion en la que se encuentra el numero
            printf("\nEl numero %d se encuentra en la posicion %d del arreglo\n",numero,i+1);
            
        }
    }
}

//La funcion ordenamientoInsercion recibe un arreglo y un tamano, y ordena el arreglo de menor a mayor por medio 
//del metodo de ordenamiento por insercion
void ordenamientoInsercion(int arreglo[],int tam)
{
    int anterior,pos;
    for(int i=1;i<tam;i++)
    {
        pos=arreglo[i];
        anterior=i-1;
        while(anterior>=0 && arreglo[anterior]>pos)
        {
            arreglo[anterior+1]=arreglo[anterior];
            anterior= anterior-1;
        }
        arreglo[anterior+1]=pos;
    }
    //Devuelve el arreglo ordenado
    printf("\nEl arreglo ordenado es: \n");
    
}



//reporte lleva el enunciado , el codigo y documentacion y explicacion del codigo 