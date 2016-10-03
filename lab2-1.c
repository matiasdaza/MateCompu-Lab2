//1.- Algoritmo Euclidiano

#include <stdio.h>
#include <time.h> //Librería para medir el tiempo
#include <gmp.h> //Librería para trabajo matemático

void gcd(int a, int b);

//arcg: cantidad de parámetros contando el nombre del ejecutable que es el primer parámetro.
//argv[]: Un arreglo que contiene todos los parámetros recibidos.
//Lo hago para recibir los valores desde la consola!!!


main(int argc, char *argv[])
{
	int a, b;
	clock_t inicio, fin; // Se crea variable 'clock_t' para calcular el tiempo de ejecúción del programa.
	inicio=clock();
	a = atoi(argv[1]); // Se convierten los datos ingresados a variable tipo entero.
	b = atoi(argv[2]);
	if(a<0 || b<0) //Condición para que los valores de n y k sean positivos!
	{
		printf("Los valores de a y de b deben ser positivos\n");
		return 0;
	}
	if (a<b) // Como es un arreglo uno se guarda en la posición 1 y el otro en la 2.Si se ingresan mal los datos, el programa lo acusará y se cerrará.
	{
		printf("El valor de n tiene que ser mayor que el de k.\n"); // Si se ingresan mal los datos, el programa lo acusará y se cerrará.
		return 0;
	}
	if (argc != 3) //Como argc es la cantidad de parámetros, si lee más de 3 estará malo (porque solo necesitamos n y k)
	{
		printf("Para ejecutar use: ./Ejecutar [valor a] [valor b] \n"); // Si se ingresan más de dos argumentos en la terminal, el programa lo acusará y se cerrará.
		return 0;
	}
	else
	{
		
		gcd(a,b); //Se manda los datos ingresados.
	}
	
	fin=clock();
	printf("El tiempo de ejecución fue de: %f \n",(fin-inicio)/(double)CLOCKS_PER_SEC); // %f es porque es un flotante!!!

	return 0; 
}

void gcd(int a, int b)
{
	int r;

	while(b!=0)
	{
		r = a-b;
		if(r>=b)
		{	
			a=r;
		}
		else
		{
			a=b;
			b=r;
		}
	}
	printf("%iEl maximo comun divisor es: \n", a );
}