/*
    Universidad del Valle de Guatemala
    Facultad de Ingenieria
    Programacion de Microprocesadores
    Seccion 10
    Ana Laura Tschen 221645
    Laboratorio 5 - Ejercicio 4
    Ciclo for con modificacion de variables de manera paralela
*/

//librerias
#include <omp.h>
#include <stdio.h>

//funcion main
int main() {
    //definicion de las 2 variables
    //variable1 - compartida
    int variable1 = 0;
    //variable2 - privada
    int variable2 = 0;

    //ejecucion de un ciclo en paralelo en base a las variables definidas anteriormente
    #pragma omp parallel for shared(variable1) private(variable2)
    for (int i = 0; i < 10; i++) {
        //incremento de variable1
        variable1 += i;
        //calculo del cuadrado de i y guardado en la variable2
        variable2 = i * i;
        //impresion de los valores de las variables en cada iteracion
        printf("Iteración %d: variable1 = %d, variable2 = %d\n", i, variable1, variable2);
    }
    //impresion final de variable1
    printf("Final variable1 = %d\n", variable1);
    
    return 0;
}
