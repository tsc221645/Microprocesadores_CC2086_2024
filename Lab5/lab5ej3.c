/*
    Universidad del Valle de Guatemala
    Facultad de Ingenieria
    Programacion de Microprocesadores
    Seccion 10
    Ana Laura Tschen 221645
    Laboratorio 5 - Ejercicio 3
    Tres funciones en paralelo
*/

//Librerias
#include <omp.h>
#include <stdio.h>

// Función para calcular el factorial
void factorial(int n) {
    long long fact = 1;
    for (int i = 1; i <= n; i++) {
        //multiplicacion de cada numero de 1 a n para calcular el factorial
        fact *= i;
    }
    //impresion del resultado
    printf("Factorial de %d es %lld\n", n, fact);
}

// Función para generar la serie de Fibonacci
void fibonacci(int n) {
    long long a = 0, b = 1, temp;
    //impresion de los primeros 2 numeros
    printf("Serie de Fibonacci: %lld %lld ", a, b);
    for (int i = 2; i < n; i++) {
        temp = a + b;
        //impresion del siguiente numero de la serie
        printf("%lld ", temp); 
        a = b;
        b = temp;
    }
    printf("\n");
}

// Función para encontrar el máximo en un arreglo
void find_max(int arr[], int n) {
    //inicializaacion del primer elemento del arreglo
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        //comparacion entre el elemento actual y el siguiente elemento
        if (arr[i] > max) {
            //actualizacion del valor maximo si se encuentra un numero mayor
            max = arr[i];
        }
    }
    //print del resultado al encontrar el maximo en el arreglo
    printf("El máximo en el arreglo es %d\n", max);
}

int main() {
    int n = 10;
    int arr[] = {1, 2, 3, 10, 4, 5, 6, 7, 8, 9};

    //ejecucion de tres secciones en paralelo
    #pragma omp parallel sections
    {
        //definicion de seccion para ejecutar la funcion factorial
        #pragma omp section
        {
            factorial(n);
        }
        //definicion de seccion para ejecutar la funcion factorial
        #pragma omp section
        {
            fibonacci(n);
        }
        //definicion de seccion para ejecutar la funcion factorial
        #pragma omp section
        {
            find_max(arr, n);
        }
    }

    return 0;
}
