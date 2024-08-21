/*
    Universidad del Valle de Guatemala
    Facultad de Ingenieria
    Programacion de Microprocesadores
    Seccion 10
    Ana Laura Tschen 221645
    Laboratorio 5 - Ejercicio 5
    Version paralela del ejercicio5A
*/

//librerias
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#define N 131072
#define THRESHOLD 1024  

// Función recursiva para contar apariciones de 'key' 
long parallel_count_key(long Nlen, long *a, long key) {
    if (Nlen <= THRESHOLD) {
        //cuenta secuencial si es pequeno
        long count = 0;
        for (int i = 0; i < Nlen; i++)
            if (a[i] == key) count++;
        return count;
    } else {
        //cuenta secuencial si es grande
        long mid = Nlen / 2;
        long count1 = 0, count2 = 0;

        #pragma omp task shared(count1)
        count1 = parallel_count_key(mid, a, key);

        #pragma omp task shared(count2)
        count2 = parallel_count_key(Nlen - mid, a + mid, key);

        // Espera a que ambas tareas terminen
        #pragma omp taskwait  

        //retorna la suma de los contadores
        return count1 + count2;
    }
}

//funcion nmain
int main() {
    long a[N], key = 42, nkey = 0;

    // Inicializa el arreglo con valores aleatorios
    for (long i = 0; i < N; i++) a[i] = rand() % N;

    // Inserta manualmente el valor 'key' 
    a[N % 43] = key; 
    a[N % 73] = key; 
    a[N % 3] = key;

    // Paralelizacion 
    #pragma omp parallel
    {
        //inicio de la tarea por un solo hilo
        #pragma omp single
        nkey = parallel_count_key(N, a, key);  
    }

    //impresion de las veces que aparece key en paralelo
    printf("Numero de veces que 'key' aparece en paralelo: %ld\n", nkey);

    return 0;
}
