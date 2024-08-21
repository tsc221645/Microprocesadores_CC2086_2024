/*
    Universidad del Valle de Guatemala
    Facultad de Ingenieria
    Programacion de Microprocesadores
    Seccion 10
    Ana Laura Tschen 221645
    Laboratorio 5 - Ejercicio 2
    Suma de los primeros N numeros naturales con un ciclo for paralelo
*/
//Librerias
#include <omp.h>
#include <stdio.h>

#define N 1000000

//funcion main
int main() {
    //variable que almacena la suma de los numeros
    int sum = 0;

    //definicion de variable start time para calcular el tiempo de ejecucion
    double start_time = omp_get_wtime();
    
    //inicio de un ciclo for paralelo con reduction
    #pragma omp parallel for reduction(+:sum)
    for (int i = 1; i <= N; i++) {
        sum += i;
    }
    //definicion de la variable end time para calcular el tiempo de ejecucion
    double end_time = omp_get_wtime();

    //impresion de la suma 
    printf("La suma de los primeros %d números naturales es: %d\n", N, sum);
    
    //impresion del tiempo de ejecucion
    printf("Tiempo de ejecución: %f segundos\n", end_time - start_time);

    return 0;
}
