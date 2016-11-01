#include <gmp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Entradas: Dos enteros a y b con b ≥ 0, a ≥ b y a = 0.
// Salidas: d = gcd(a, b) y enteros s e t que satisfacen sa + tb = d.
// Modo de compilación: gcc -o lab2_p4 lab2_p4.c -lgmp
// Modo de ejecución: ./lab2_p4 a b 

int main(int argc, char *argv[]){
	
	FILE *file;
	mpz_t a;
	mpz_t b;
	float tiempo=0;

	mpz_init_set_str(a, argv[1],10);
	mpz_init_set_str(b, argv[2],10);

	
	mpz_t s, t, s_1, t_1, s_2, t_2, d, q, resultado, auxiliar, u, v, aux_a, aux_b; //Valores definidos
	
	//Iniciar las variables en 0

	mpz_init(s);
	mpz_init(t);
	mpz_init(s_1);
	mpz_init(t_1);
	mpz_init(s_2);
	mpz_init(t_2);
	mpz_init(d);
	mpz_init(q);
	mpz_init(resultado);
	mpz_init(auxiliar);
	mpz_init(u);
	mpz_init(v);
	mpz_init(aux_a);
    mpz_init(aux_b);
    mpz_set(aux_a, a);
    mpz_set(aux_b, b);
	
	clock_t inicio, fin; //Variables para medir el tiempo
	
	inicio=clock();
	
	if (mpz_cmp_ui(a,0) == 0){
		
		printf("\nError --> a tiene que ser distinto de cero\n");
	}
	if (mpz_cmp_ui(b,0) < 0){
		
		printf("\nError --> b tiene que ser positivo\n");
	}
	
	if (mpz_cmp(a,b) < 0){ // Verifica que a sea mayor que b
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
		mpz_set_ui(s_1,1); //s_1 = 1
		mpz_set_ui(t_1,0); //t_1 = 0
		mpz_set_ui(s_2,0); //s_2 = 0
		mpz_set_ui(t_2,1); //t_2 = 1
		
		
		while (mpz_cmp_ui(a,0) > 0){
			mpz_div(q,b,a);
			mpz_mul(auxiliar,q,a);
			mpz_mul(u,q,t_1);
			mpz_mul(v,q,s_1);
			mpz_sub(resultado,b,auxiliar);
			mpz_sub(t,t_2,u);
			mpz_sub(s,s_2,v);
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
		printf("El gcd (a,b) es = ");
		gmp_printf("%Zd",d);
		printf("\n");	
		printf("Los enteros que cumplen sa + tb = gcd(a,b)  son :");
		printf("\n");
		printf("Para s = ");
		gmp_printf("%Zd",s);
		printf("\n");
		printf("Para t = ");
		gmp_printf("%Zd",t);	
		}
	}

	if (mpz_cmp(b,a) < 0){
		if (mpz_cmp_ui(b,0)==0){
			mpz_set(d,a);
			mpz_set_ui(s,1);
			mpz_set_ui(t,0);
			printf("El gcd (a,b) es = ");
			gmp_printf("%Zd",d);	
			printf("Los enteros que cumplen sa + tb = d  son :");
			printf("EPara s");
			gmp_printf("%Zd",s);
			printf("Para t");
			gmp_printf("%Zd",t);	
	}
	else {
		mpz_set_ui(s_1,0);
		mpz_set_ui(t_1,1);
		mpz_set_ui(s_2,1);
		mpz_set_ui(t_2,0);
		
		while (mpz_cmp_ui(b,0) > 0){
			mpz_div(q,a,b);
			mpz_mul(auxiliar,q,b);
			mpz_mul(u,q,s_1);
			mpz_mul(v,q,t_1);
			mpz_sub(resultado,a,auxiliar);
			mpz_sub(s,s_2,u);
			mpz_sub(t,t_2,v);
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
		printf("El gcd (a,b) es = ");
		gmp_printf("%Zd",d);
		printf("\n");	
		printf("Los enteros que cumplen sa + tb = gcd(a,b)  son :");
		printf("\n");
		printf("Para s = ");
		gmp_printf("%Zd",s);
		printf("\n");
		printf("Para t = ");
		gmp_printf("%Zd",t);	
	}
}
	
	fin=clock();
	tiempo=(fin-inicio)/(double)CLOCKS_PER_SEC;
	printf("\n El tiempo de ejecución en segundos fue de: %f \n",tiempo);
	file = fopen("algoritmo4.txt", "a");
    if(file == NULL)
    {
        printf("Error al abrir archivo");
    }
    mpz_out_str(file, 10, aux_a);
    fprintf(file,"\t");
    mpz_out_str(file, 10, aux_b);
    fprintf(file,"\t %F \n",tiempo);
    fclose(file);
	
	
	
	mpz_clears(a);
	mpz_clears(b);
	mpz_clears(aux_a);
	mpz_clears(aux_b);
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
	mpz_clears(u);
	mpz_clears(v);
	
	return 0;
	
}

