//Algoritmo Euclideano Binario

#include <gmp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void Alg_euc_bin (mpz_t a, mpz_t b);

int main(int argc, char *argv[]){

	mpz_t a, b;
	clock_t inicio, fin; // Se crea variable 'clock_t' para calcular el tiempo de ejecúción del programa.
	inicio=clock();
	mpz_init_set_str(a,argv[1],10);
	mpz_init_set_str(b,argv[2],10);



	inicio=clock();	
	
	if (mpz_cmp_ui(b,0) < 0){
		
		printf("\nERROR, b tiene que ser positivo\n");
	}

	if (mpz_cmp_ui(a,0) == 0){
		
		printf("\nERROR, a tiene que ser distinto de 0\n");
	}

	else{

		Alg_euc_bin(a,b);
	}

	fin=clock();
	printf("El tiempo de ejecución fue de: %f \n",(fin-inicio)/(double)CLOCKS_PER_SEC);
	
	mpz_clears(a);
	mpz_clears(b);
		
	return 0;		
}

void Alg_euc_bin (mpz_t a, mpz_t b){


	mpz_t r;
	mpz_t d; // d = gcd(a,b)
	mpz_t resta;

	//Inicia las variables en 0 
	mpz_init(r); 
	mpz_init(d);
	mpz_init(resta);
	if (mpz_cmp(a,b) > 0 || mpz_cmp(a,b) == 0){
		mpz_set_ui(d,1); // d=1
		while(mpz_tstbit(a,0) == 0 && mpz_tstbit(b,0) == 0 )
		{
			mpz_div_ui(a,a,2); // a=a/2
			mpz_div_ui(b,b,2); // b=b/2
			mpz_mul_ui(d,d,2); // d=2d
		}
		while(mpz_tstbit(a,0) == 0)
		{ // verifica si a es par
			mpz_div_ui(a,a,2);
		}
		while(mpz_tstbit(b,0) == 0 )
		{ // verifica si b es par
			mpz_div_ui(b,b,2);
		}
		if(mpz_cmp(b,a) > 0)
		{
			mpz_set(r,b);
			mpz_set(b,a);
			mpz_set(a,r);
		}
		while(mpz_cmp_ui(b,0) != 0)
		{
			mpz_sub(resta,a,b);
			mpz_set(r,resta);
			while(mpz_tstbit(r,0) == 0 && mpz_cmp_ui(r,0) != 0 )
			{
				mpz_cdiv_q_ui(r,r,2);
			}
			if(mpz_cmp(r,b) >= 0)
				mpz_set(a,r);
			else
			{
				mpz_set(a,b);
				mpz_set(b,r);
			}
		}
		mpz_mul(d,d,a);	
	}
	else{
		printf("Holi\n");
		mpz_set_ui(d,1);
		printf("Holi\n");
		while(mpz_tstbit(a,0) == 0 && mpz_tstbit(b,0) == 0 ){
			mpz_div_ui(a,a,2);
			mpz_div_ui(b,b,2);
			mpz_mul_ui(d,d,2);
		}

		while(mpz_tstbit(a,0) == 0){
			mpz_div_ui(a,a,2);
		}
				printf("Holi1\n");
		while(mpz_tstbit(b,0) == 0 ){
			mpz_div_ui(b,b,2);
		}
		if(mpz_cmp(a,b) > 0){
			mpz_set(r,a);
			mpz_set(a,b);
			mpz_set(b,r);
		}
				printf("Holi2\n");

		while(mpz_cmp_ui(a,0) != 0){
			mpz_sub(resta,b,a);
			mpz_set(r,resta);
			while(mpz_tstbit(r,0) == 0 && mpz_cmp_ui(r,0) != 0 ){
				mpz_cdiv_q_ui(r,r,2); //r=r/2
			}
			if(mpz_cmp(r,b) >= 0)
				mpz_set(a,r);
			else{
				mpz_set(b,a);
				mpz_set(b,r);
			}
		}
		mpz_mul(d,d,b);
		
	}
	printf("El gcd de a y b es :");
	gmp_printf("%Zd",d);
	
	mpz_clears(d);
	mpz_clears(r);
	mpz_clears(resta);
		
}






