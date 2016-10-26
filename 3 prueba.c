# include <stdio.h>
# include <time.h>
# include <gmp.h>   //Se incluye la libreria time.h para poder calcular el tiempo de ejecucion del programa.
# include <stdlib.h>
# include <math.h>

int main(){
    FILE *file;
    int j, vueltas, inicio, fin;    //Se inicializa la variable j, vueltas, inicio y fin.
    float tiempo = 0;
    inicio = clock();   //Variable que comienza a tomar el tiempo de ejecucion del programa.
    j = 2;  //El valor de j es 2.
    vueltas = 0;    //Variable vueltas de valor 0, que almacenara la cantidad de veces en que cambian los valores de a y b.
    mpz_t a, b, resto, d, i, aux_a, aux_b;    //Se designan las variables de tipo gmp, a, b y resto, donde a y b son los numeros a utilizar para calcular maximo comun divisor.
    mpz_init(a);    //Se inicializa la variable a.
    mpz_init(b);    //Se inicializa la variable b.
    mpz_init(resto);    //Se inicializa la variable resto.
    mpz_init(aux_a);
    mpz_init(aux_b);
    mpz_init_set_ui(d, 1);  //Se inicializa la variable d en 1.
    mpz_init_set_ui(i, 2);  //Se inicializa la variable i en 2.
    printf("\nIngrese el numero 'a': ");    //Se pide por consola que se ingrese el numero a.
    gmp_scanf("%Zd", a);    //Una vez ingresado, el programa lee el numero.
    printf("Ingrese el numero 'b': ");  //Se pide por consola que se ingrese el numero b.
    gmp_scanf("%Zd", b);    //Una vez ingresado, el programa lee el numero.
    mpz_set(aux_a, a);
    mpz_set(aux_b, b);
    if (mpz_sgn(a) == 0)    //Se verifica si a es igual a 0.
    {
        printf("\nError, el valor de a no puede ser igual a 0.\n\n");   //Se muestra por pantalla el error.
        exit(0);    //Fin del programa.
    }       
    if (mpz_cmp(a, b) < 0) //Se verifica si el valor de a es mayor al de b, de no ser asi, la comparacion retorna un valor negativo.
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
    while (mpz_tstbit(a, 0) == 0 && mpz_tstbit(b, 0) == 0) //Se verifica se tanto 'a' como 'b' son pares, se observa si el ultimo bit de los numeros es 0.
    {
        mpz_cdiv_q(a, a, i);    //La variable a es dividida por 2.
        vueltas = vueltas + 1;
        mpz_cdiv_q(b, b, i);    //La variable b es dividida por 2.
        vueltas = vueltas + 1;
        mpz_mul_ui(d, d, j);    //La variable d es multiplicada por 2.
    }
    while (mpz_tstbit(a, 0) == 0)   //Se verifica si 'a' es par, observando si su ultimo bit vale 0.
    {   
        mpz_cdiv_q(a, a, i);    //La variable a es dividida por 2.
        vueltas = vueltas + 1;
    }   
    while (mpz_tstbit(b, 0) == 0)   //Se verifica si b es par, observando si su ultimo bit vale 0.
    {   
        mpz_cdiv_q(b, b, i);    //La variable b es dividida por 2.
        vueltas = vueltas + 1;
    }   
    if (mpz_cmp(b, a) > 0)  //Se verifica si el valor de b es mayor que el de a, de ser asi, la comparacion retorna 1.
    {
        mpz_set(resto, b);  //Se asigna a resto el valor de b.
        vueltas = vueltas + 1;
        mpz_set(b, a);  //Se asigna a 'b' el valor de 'a'.
        vueltas = vueltas + 1;
        mpz_set(a, resto);  //Se asigna 'a' a el valor del resto.
        vueltas = vueltas + 1; //Cantidad de veces que se cambian los valores de a y b.
    }
    while (mpz_sgn(b) != 0) //Mientras el valor de 'b' sea distinto de 0, entra al ciclo while.
    {
        mpz_sub(resto, a, b);   //Se le asigna a resto, el valor de la resta entre a y b.
        while (mpz_tstbit(resto, 0) == 0 && mpz_sgn(resto) != 0)    //Se verifica si 'resto' es par, se observa si el ultimo bit del numero es 0 y tambien si es distinto de 0.
        {   
            mpz_cdiv_q(resto, resto, i);    //La variable 'resto' es dividida por 2.
        }
        if (mpz_cmp(resto, b) >= 0) //Se verifica si 'resto' es mayor o igual que b, si es mayor se retorna un 1 y si son iguales retorna un 0.
        {
            mpz_set(a, resto);  //Se le asigna a 'a' el valor de 'resto'.
            vueltas = vueltas + 1; //Cantidad de veces que se cambian los valores de a y b.
        }
        else //De no ser asi, se realiza lo siguiente.
        {
            mpz_set(a, b);  //Se asigna a 'a' el valor de 'b'
            vueltas = vueltas + 1;
            mpz_set(b, resto);  //Se asigna a 'b' el valor de 'resto'.
            vueltas = vueltas + 1; //Cantidad de veces que se cambian los valores de a y b.
        }
    }
    mpz_mul(d, d, a);   //Se multiplica la variable 'd' por 'a'.
    gmp_printf("\nEl gdc es: %Zd\n", d);    //Se imprime por pantalla el gcd entre ambos enteros.
    printf("\nEl numero de veces que 'a' y/o 'b' fueron cambiados es: %d\n\n", vueltas);    //Se muestra por consola la cantidad de veces en que a y/o b fueron cambiados.
    fin = clock();  ///Variable que almacena el tiempo final de ejecucion del programa.
    tiempo = (fin-inicio)/(double)CLOCKS_PER_SEC;
    printf("El tiempo de ejecución fue de: %F \n\n",tiempo);   //Se imprime el tiempo de ejecucion.
    file = fopen("algoritmo3.txt", "a");
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
    mpz_clear(resto);   //Se borra lo almacenado en la variable resto.
    mpz_clear(d);   //Se borra lo almacenado en la variable d.
    mpz_clear(i);   //Se borra lo almacenado en la variable i.
    mpz_clear(aux_a);
    mpz_clear(aux_b);
}