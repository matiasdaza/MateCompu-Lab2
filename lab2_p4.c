#include <gmp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <math.h>
#include <inttypes.h>


int main(int argc, char *argv[]){
	
	mpz_t a;
	mpz_t b;

	mpz_init_set_str(a, argv[1],10);
	mpz_init_set_str(b, argv[2],10);


	mpz_t s;
	mpz_t t;
	mpz_t s_1;
	mpz_t t_1;
	mpz_t s_2;
	mpz_t t_2;
	mpz_t d;
	mpz_t q;
	mpz_t resultado;
	mpz_t auxiliar;
	mpz_t auxiliar_2;
	mpz_t auxiliar_3;
	mpz_inits(a);
	mpz_inits(b);
	mpz_inits(s);
	mpz_inits(t);
	mpz_inits(s_1);
	mpz_inits(t_1);
	mpz_inits(s_2);
	mpz_inits(t_2);
	mpz_inits(d);
	mpz_inits(q);
	mpz_inits(resultado);
	mpz_inits(auxiliar);
	mpz_inits(auxiliar_2);
	mpz_inits(auxiliar_3);
	
	clock_t inicio, fin; //Variables para medir el tiempo
	
	inicio=clock();
	
	if (mpz_cmp_ui(b,0) < 0){
		
		printf("\nERROR b no puede ser negativo\n");
	}
	if (mpz_cmp_ui(a,0) == 0){
		
		printf("\nERROR a no puede ser cero\n");
	}
	if (mpz_cmp(a,b) < 0){
		gmp_printf("polo");
		if (mpz_cmp_ui(a,0)==0){
			mpz_set(d,b);
			mpz_set_ui(t,1);
			mpz_set_ui(s,0);
			printf("El gcd de a y b es :");
			gmp_printf("%Zd",d);	
			printf("Los enteros que satisfacen sa + tb = d  son :");
			printf("Entero s");
			gmp_printf("%Zd",t);
			printf("Entero t");
			gmp_printf("%Zd",s);	
	}
	else {
		mpz_set_ui(t_2,1);
		mpz_set_ui(t_1,0);
		mpz_set_ui(s_2,0);
		mpz_set_ui(s_1,1);
		while (mpz_cmp_ui(a,0) > 0){
			mpz_div(q,b,a);
			mpz_mul(auxiliar,q,a);
			mpz_mul(auxiliar_2,q,t_1);
			mpz_mul(auxiliar_3,q,s_1);
			mpz_sub(resultado,b,auxiliar);
			mpz_sub(t,t_2,auxiliar_2);
			mpz_sub(s,s_2,auxiliar_3);
			mpz_set(b,a);
			mpz_set(a,resultado);
			mpz_set(t_2,t_1);
			mpz_set(t_1,t);
			mpz_set(s_2,s_1);
			mpz_set(s_1,s);				
		}
		mpz_set(d,b);
		mpz_set(t,t_2);
		mpz_set(s,s_2);	
		printf("El gcd de a y b es :");
		gmp_printf("%Zd",d);
		printf("\n");	
		printf("Los enteros que satisfacen sa + tb = gcd(a,b)  son :");
		printf("\n");
		printf("Entero s = ");
		gmp_printf("%Zd",s);
		printf("\n");
		printf("Entero t = ");
		gmp_printf("%Zd",t);	
		}
	}
	if (mpz_cmp(b,a) < 0){
		if (mpz_cmp_ui(b,0)==0){
			mpz_set(d,a);
			mpz_set_ui(s,1);
			mpz_set_ui(t,0);
			printf("El gcd de a y b es :");
			gmp_printf("%Zd",d);	
			printf("Los enteros que satisfacen sa + tb = d  son :");
			printf("Entero s");
			gmp_printf("%Zd",s);
			printf("Entero t");
			gmp_printf("%Zd",t);	
	}
	else {
		mpz_set_ui(s_2,1);
		mpz_set_ui(s_1,0);
		mpz_set_ui(t_2,0);
		mpz_set_ui(t_1,1);
		while (mpz_cmp_ui(b,0) > 0){
			mpz_div(q,a,b);
			mpz_mul(auxiliar,q,b);
			mpz_mul(auxiliar_2,q,s_1);
			mpz_mul(auxiliar_3,q,t_1);
			mpz_sub(resultado,a,auxiliar);
			mpz_sub(s,s_2,auxiliar_2);
			mpz_sub(t,t_2,auxiliar_3);
			mpz_set(a,b);
			mpz_set(b,resultado);
			mpz_set(s_2,s_1);
			mpz_set(s_1,s);
			mpz_set(t_2,t_1);
			mpz_set(t_1,t);				
		}
		mpz_set(d,a);
		mpz_set(s,s_2);
		mpz_set(t,t_2);	
		printf("El gcd de a y b es :");
		gmp_printf("%Zd",d);
		printf("\n");	
		printf("Los enteros que satisfacen sa + tb = gcd(a,b)  son :");
		printf("\n");
		printf("Entero s = ");
		gmp_printf("%Zd",s);
		printf("\n");
		printf("Entero t = ");
		gmp_printf("%Zd",t);	
	}
}
	
	fin=clock();
	printf("El tiempo de ejecución fue de: %f \n",(fin-inicio)/(double)CLOCKS_PER_SEC);
	
	
	
	mpz_clears(a);
	mpz_clears(b);
	mpz_clears(s);
	mpz_clears(t);
	mpz_clears(s_1);
	mpz_clears(t_1);
	mpz_clears(s_2);
	mpz_clears(t_2);
	mpz_clears(d);
	mpz_clears(q);
	mpz_clears(resultado);
	mpz_clears(auxiliar);
	mpz_clears(auxiliar_2);
	mpz_clears(auxiliar_3);
	
	return 0;
	
}

