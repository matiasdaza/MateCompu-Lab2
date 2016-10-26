//1.- Algoritmo Euclidiano binario

#include <stdio.h>
#include <time.h> //Librería para medir el tiempo
#include <gmp.h> //Librería para trabajo matemático

void gcd(mpz_t a, mpz_t b);

//arcg: cantidad de parámetros contando el nombre del ejecutable que es el primer parámetro.
//argv[]: Un arreglo que contiene todos los parámetros recibidos.
//Lo hago para recibir los valores desde la consola!!!


main(int argc, char *argv[])
{
	mpz_t a, b;
	clock_t inicio, fin; // Se crea variable 'clock_t' para calcular el tiempo de ejecúción del programa.
	inicio=clock();
	mpz_init_set_str(a,argv[1],10);
	mpz_init_set_str(b,argv[2],10);
	if(mpz_sgn(a)<=0 || mpz_sgn(b)<=0)//Condición para que los valores de n y k sean positivos!
	{	
		printf("Los valores de a y de b deben ser positivos. y el valor debe ser distinto de 0\n");
		return 0;
	}
	if (mpz_cmp(a,b)<0) // Como es un arreglo uno se guarda en la posición 1 y el otro en la 2.Si se ingresan mal los datos, el programa lo acusará y se cerrará.
	{
		printf("El valor de a tiene que ser mayor o igual que b.\n"); // Si se ingresan mal los datos, el programa lo acusará y se cerrará.
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

void gcd(mpz_t a, mpz_t b)
{
	int vueltas=0;
	mpz_t r, d, parA, parB, parR;
	mpz_init_set_ui(d,1);
	mpz_init_set_ui(r,1);
	mpz_init_set_ui(parR,1);
	mpz_init_set_ui(parA,1);
	mpz_init_set_ui(parB,1);
	mpz_mod_ui(parA, a, 2);
	mpz_mod_ui(parB, b, 2);
	while(mpz_sgn(parA)== 0 && mpz_sgn(parB) == 0)// mientras a y b sean pares.
    {
    	mpz_cdiv_q_ui (a,a,2);
    	mpz_cdiv_q_ui (b,b,2);
    	mpz_mul_ui(d,d,2);
    	mpz_mod_ui(parA, a, 2);
		mpz_mod_ui(parB, b, 2);
    }
    while(mpz_sgn(parA)== 0)
    {
    	mpz_cdiv_q_ui (a,a,2);
    	printf("hola1\n");
    	mpz_mod_ui(parA, a, 2);
    }
    while(mpz_sgn(parB)== 0)
    {
    	mpz_cdiv_q_ui (a,a,2);
    	printf("hola2\n");
    	mpz_mod_ui(parB, a, 2);
    }
    if(mpz_cmp(a,b)<0)
    {
    	printf("hola3\n");
    	mpz_set(r,b);
    	mpz_set(b,a);
    	mpz_set(a,r);
    }
    while(mpz_sgn(b)!=0)
    {
    	printf("hola4\n");
    	//Hasta aquí llega.
    	mpz_sub(r,a,b);
    	mpz_mod_ui(parR, r, 2);
    	while(mpz_sgn(r)>0 && mpz_sgn(parR)==0)
    	{
    		mpz_cdiv_q_ui (r,r,2);
    		printf("hola5\n");
    	}
    	if(mpz_cmp(r,b)>=0)
    	{
    		mpz_set(a,r);
    	}else
    	{
    		mpz_set(a,b);
    		mpz_set(b,r);	
    	}
    }

    mpz_mul(d,d,a);
    gmp_printf("\nEl gcd es: %Zd \n", d);   //Se muestra por consola el valor del maximo comun divisor entre a y b.
  	mpz_clear(a);   //Se borra lo almacenado en la variable a.
    mpz_clear(b);   //Se borra lo almacenado en la variable b.
    mpz_clear(d);
    mpz_clear(r);
    mpz_clear(parA);	
    mpz_clear(parB);
    mpz_clear(parR);
}