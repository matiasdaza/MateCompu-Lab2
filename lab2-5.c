# include <stdio.h>
# include <time.h>
# include <gmp.h>   //Se incluye la libreria time.h para poder calcular el tiempo de ejecucion del programa.
# include <stdlib.h>
# include <math.h>

main() 
{
    FILE *file;
    int j, inicio, fin; //Se inicializa variable j, inicio y fin.
    float tiempo = 0;
    inicio = clock();   //Variable que comienza a tomar el tiempo de ejecucion del programa.
    j = 2;  //El valor de j es 2.
    mpz_t i, a, b, r, u, v, d, A, B, s, t, s1, s2, t1, t2, suma_s1, suma_s2, resta_t2, resta_t1, suma_u, resta_v, aux_a, aux_b;   //Se designan las variables de tipo gmp.
    mpz_init(a);    //Se inicializa la variable a.
    mpz_init(b);    //Se inicializa la variable b.
    mpz_init(r);    //Se inicializa la variable r.
    mpz_init(u);    //Se inicializa la variable u.
    mpz_init(v);    //Se inicializa la variable v.
    mpz_init(A);    //Se inicializa la variable A.
    mpz_init(B);    //Se inicializa la variable B.
    mpz_init(s);    //Se inicializa la variable s.
    mpz_init(t);    //Se inicializa la variable t.
    mpz_init(suma_u);   //Se inicializa la variable suma_u.
    mpz_init(resta_v);  //Se inicializa la variable resta_v.
    mpz_init(suma_s1);  //Se inicializa la variable que almacenara s1 + B.
    mpz_init(resta_t1); //Se inicializa la variable que almacenara t1 - A.
    mpz_init(suma_s2);  //Se inicializa la variable que almacenara s2 + B.
    mpz_init(resta_t2); //Se inicializa la variable que almacenara t2 - A.
    mpz_init(aux_a);
    mpz_init(aux_b);
    mpz_init_set_ui(d, 1);  //Se inicializa la variable d en 1.
    mpz_init_set_ui(s1, 1); //Se inicializa la variable s1 en 1.
    mpz_init_set_ui(t1, 0); //Se inicializa la variable t1 en 0.
    mpz_init_set_ui(s2, 0); //Se inicializa la variable s2 en 0.
    mpz_init_set_ui(t2, 1); //Se inicializa la variable t2 en 1.
    mpz_init_set_ui(i, 2);  //Se inicializa la variable i en 2.
    mpz_init_set_ui(d, 1);  //Se inicializa la variable d en 1.
    mpz_init_set_ui(s1, 1); //Se inicializa la variable s1 en 1.
    mpz_init_set_ui(t1, 0); //Se inicializa la variable t1 en 0.
    mpz_init_set_ui(s2, 0); //Se inicializa la variable s2 en 0.
    mpz_init_set_ui(t2, 1); //Se inicializa la variable t2 en 1.
    mpz_init_set_ui(i, 2);  //Se inicializa la variable i en 2.
    printf("\nIngrese el numero 'a': ");    //Se pide por consola que se ingrese el numero a.
    gmp_scanf("%Zd", a);    //Una vez ingresado, el programa lee el numero.
    printf("Ingrese el numero 'b': ");  //Se pide por consola que se ingrese el numero b.
    gmp_scanf("%Zd", b);    //Una vez ingresado, el programa lee el numero.
    mpz_set(aux_a, a);
    mpz_set(aux_b, b);

    //Condiciones inciales

    if (mpz_sgn(a) == 0)    //Se verifica si a es igual a 0.
    {
        printf("\nError, el valor de a no puede ser igual a 0.\n\n");   //Se muestra por pantalla el error.
        return 0;   //Fin del programa.
    }       
    if (mpz_cmp(a, b) < 0)  //Se verifica si el valor de a es mayor al de b, de no ser asi, la comparacion retorna un valor negativo.
    {
        printf("\nError, el valor de a debe ser mayor al de b, se procederá a intercambiarlos...\n\n");   //Se muestra por pantalla el error.
        mpz_swap(a,b);
        gmp_printf("Nuevo 'a': %Zd \n", a);
        gmp_printf("Nuevo 'b': %Zd \n", b);
        getchar();
        printf("Presione la tecla Enter para continuar...\n");
        getchar();
    }
    if (mpz_sgn(b) < 0) //Se verifica si b es mayor a 0.
    {
        printf("\nError, el valor de b debe ser mayor o igual a 0.\n\n"); //Se muestra por pantalla el error.
        exit(0);    //Fin del programa.
    }
    while (mpz_tstbit(a, 0) == 0 && mpz_tstbit(b, 0) == 0 && mpz_cmp_ui(a, 0) != 0 && mpz_cmp_ui(b, 0) != 0 ) //Se verifica se tanto 'a' como 'b' son pares, se observa si el ultimo bit de los numeros es 0.
    {
        mpz_cdiv_q(a, a, i);    //La variable 'a' es dividida por 2.
        mpz_cdiv_q(b, b, i);    //La variable 'b' es dividida por 2.
        mpz_mul_ui(d, d, j);    //La variable d es multiplicada por 2.

    }
    mpz_set(A, a);  //Se asigna a 'A' el valor de la variable 'a'.
    mpz_set(B, b);  //Se asigna a 'B' el valor de la variable 'b'.
    while (mpz_tstbit(a, 0) == 0 && mpz_cmp_ui(a, 0) != 0 ) //Se verifica si 'a' es par, observando si su ultimo bit es 0.
    {
        mpz_cdiv_q(a, a, i);    //La variable 'a' es dividida por 2.
        if (mpz_tstbit(s1, 0) == 0 && mpz_tstbit(t1, 0) == 0 && mpz_cmp_ui(s1, 0) != 0 && mpz_cmp_ui(t1, 0) != 0)   //Se verifica si s1 y t1 son pares, observando si sus ultimos bits son 0.
        {
            mpz_cdiv_q(s1, s1, i);  //La variable s1 es dividida por 2.
            mpz_cdiv_q(t1, t1, i);  //La variable t1 es dividida por 2.
        }
        else    //De no ser asi, se realiza lo siguiente.
        {
            mpz_add(suma_s1, s1, B);    //Se asigna a suma_s1 el valor de s1 + B.
            mpz_cdiv_q(s1, suma_s1, i); //Se asigna a s1 el valor de (s1 + B)/2.
            mpz_sub(resta_t1, t1, A);   //Se asigna a resta_t1 el valor de t1 - A.
            mpz_cdiv_q(t1, resta_t1, i);    //Se asigna a t1 el valor de (t1 - A)/2.
        }
    }
    while (mpz_tstbit(b, 0) == 0 && mpz_cmp_ui(b, 0) != 0)  //Se verifica si b es par, observando si su ultimo bit es 0.
    {
        mpz_cdiv_q(b, b, i);    //La variable b es dividida por 2.
        if (mpz_tstbit(s2, 0) == 0 && mpz_tstbit(t2, 0) == 0 && mpz_cmp_ui(s2, 0) != 0 && mpz_cmp_ui(t2, 0) != 0) //Se verifica si tanto 's2' como 't2' son pares, se observa si el ultimo bit de los numeros es 0.
        {
            mpz_cdiv_q(s2, s2, i);  //La variable s2 es dividida por 2.
            mpz_cdiv_q(t2, t2, i);  //La variable t2 es dividida por 2.
        }
        else    //De no ser asi, se realiza lo siguiente.
        {
            mpz_add(suma_s2, s2, B);    //Se asigna a suma_s2 el valor de s2 + B.
            mpz_cdiv_q(s2, suma_s2, i); //Se asigna a s2 el valor de (s2 + B)/2.
            mpz_sub(resta_t2, t2, A);   //Se asigna a resta_t2 el valor de t2 - A.
            mpz_cdiv_q(t2, resta_t2, i);    //Se asigna a t2 el valor de (t2 - A)/2.
        }   
    }
    if (mpz_cmp(b, a) > 0)  //Se verifica si el valor de b es mayor al de a, de no ser asi, la comparacion retorna un valor negativo.
    {
        mpz_set(r, b);  //Se asigna a 'r' el valor de b.
        mpz_set(b, a);  //Se asigna a 'b' el valor de a.
        mpz_set(a, r);  //Se asigna a 'a' el valor de r.
        mpz_set(u, s2); //Se asigna a 'u' el valor de s2.
        mpz_set(s2, s1);    //Se asigna a 's2' el valor de s1.
        mpz_set(s1, u); //Se asigna a 's1' el valor de u.
        mpz_set(v, t2); //Se asigna a v el valor de t2.
        mpz_set(t2, t1);    //Se asigna a t2 el valor de t1.
        mpz_set(t1, v); //Se asigna a 't1' el valor de v.
    }
    while (mpz_sgn(b) != 0) //Mientras 'b' sea distinto de 0, se entra al ciclo while.
    {
        mpz_sub(r, a, b);   //Se asigna a 'r' el valor de la resta entre a y b.
        mpz_sub(u, s1, s2); //Se asigna a 'u' el valor de la resta entre s1 y s2.
        mpz_sub(v, t1, t2); //Se asigna a 'v' e valor de la resta entre t1 y t2.
        while (mpz_tstbit(r, 0) == 0 && mpz_sgn(r) != 0)
        {
            mpz_cdiv_q(r, r, i);    //La variable r es dividida por 2.
            if (mpz_tstbit(u, 0) == 0 && mpz_tstbit(v, 0) == 0 && mpz_cmp_ui(u, 0) != 0 && mpz_cmp_ui(v, 0) != 0) //Se verifica si tanto 'u' como 'v' son pares, se observa si el ultimo bit de los numeros es 0.
            {
                mpz_cdiv_q(u, u, i);    //La variable u es dividida por 2.
                mpz_cdiv_q(v, v, i);    //La variable v es dividida por 2.
            }
            else    //De no ser asi, se realiza lo siguiente.
            {
                mpz_add(suma_u, u, B);  //Se asigna a suma_u el valor de u + B.
                mpz_cdiv_q(u, suma_u, i);   //Se asigna a 'u' el valor de (u + B)/2.
                mpz_sub(resta_v, v, A); //Se asigna a resta_v el valor de v - A.
                mpz_cdiv_q(v, resta_v, i);  //Se asigna a 'v' el valor de (v - A)/2.
            }   
        }
        if (mpz_cmp(r, b) >= 0) //Se verifica si el valor de r es mayor al de b, de no ser asi, la comparacion retorna un valor negativo.
        {
            mpz_set(a, r);  //Se asigna a 'a' el valor de r.
            mpz_set(s1, u); //Se asigna a 's1' el valor de u.
            mpz_set(t1, v); //Se asigna a 't1' el valor de v.
        }
        else
        {
            mpz_set(a, b);  //Se asigna a 'a' el valor de b.
            mpz_set(b, r);  //Se asigna a 'b' el valor de r.
            mpz_set(s1, s2);    //Se asigna a 's1' el valor de s2.
            mpz_set(s2, u); //Se asigna a 's2' el valor de u.
            mpz_set(t1, t2);    //Se asigna a 't1' el valor de t2.
            mpz_set(t2, v); //Se asigna a 't2' el valor de v.
        }       
    }
    mpz_mul(d, d, a);   //Se asigna a 'd' el valor de d*a.
    mpz_set(s, s1); //Se asigna a 's' el valor de s1.
    mpz_set(t, t1); //Se asigna a 't' el valor de t1.
    gmp_printf("\nEl gdc es: %Zd\n\n", d);  //Se imprime por pantalla el gcd entre ambos enteros.
    gmp_printf("Los enteros que satisfacen la condicion s*a + t*b = d son: s = %Zd; t = %Zd \n", s, t); //Se imprime por pantalla el valor de s y t.
    fin = clock();  ///Variable que almacena el tiempo final de ejecucion del programa.
    tiempo = (fin-inicio)/(double)CLOCKS_PER_SEC;
    printf("El tiempo de ejecución fue de: %F \n\n",tiempo);   //Se imprime el tiempo de ejecucion.
    file = fopen("algoritmo5.txt", "a");
    if(file == NULL)
    {
        printf("Error al abrir archivo");
    }
    mpz_out_str(file, 10, aux_a);
    fprintf(file,"\t");
    mpz_out_str(file, 10, aux_b);
    fprintf(file,"\t %F \n",tiempo);
    fclose(file);
    mpz_clear(a);   //Se borra lo almacenado en la variable a.
    mpz_clear(b);   //Se borra lo almacenado en la variable b.
    mpz_clear(r);   //Se borra lo almacenado en la variable r.
    mpz_clear(u);   //Se borra lo almacenado en la variable u.
    mpz_clear(v);   //Se borra lo almacenado en la variable v.
    mpz_clear(A);   //Se borra lo almacenado en la variable A.
    mpz_clear(B);   //Se borra lo almacenado en la variable B.
    mpz_clear(s);   //Se borra lo almacenado en la variable s.
    mpz_clear(t);   //Se borra lo almacenado en la variable t.
    mpz_clear(suma_u);  //Se borra lo almacenado en la variable suma_u.
    mpz_clear(resta_v); //Se borra lo almacenado en la variable resta_v.
    mpz_clear(suma_s1); //Se borra lo almacenado en la variable suma_s1.
    mpz_clear(resta_t1);    //Se borra lo almacenado en la variable resta_t1.
    mpz_clear(suma_s2); //Se borra lo almacenado en la variable suma_s2.
    mpz_clear(resta_t2);    //Se borra lo almacenado en la variable resta_t2.
    mpz_clear(d);   //Se borra lo almacenado en la variable d.
    mpz_clear(s1);  //Se borra lo almacenado en la variable s1.
    mpz_clear(t1);  //Se borra lo almacenado en la variable t1.
    mpz_clear(s2);  //Se borra lo almacenado en la variable s2.
    mpz_clear(t2);  //Se borra lo almacenado en la variable t2.
    mpz_clear(i);   //Se borra lo almacenado en la variable i.
    mpz_clear(aux_a);
    mpz_clear(aux_b);
}