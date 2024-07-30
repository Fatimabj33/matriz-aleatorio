#include <iostream>
#include <cstdlib> // Para generar números aleatorios
#include <ctime>   // Para inicializar la semilla aleatoria

using namespace std;

const int filas = 5;
const int columnas = 6;

// Función para generar un número aleatorio entre 0 y 9
int generarNumeroAleatorio() {
   return rand() % 10;
}

// Función para calcular la suma parcial de una fila
int calcularSumaFila(int fila, int matriz[][columnas]) {
   int sumaFila = 0;
   for (int j = 0; j < columnas; j++) {
      sumaFila += matriz[fila][j];
   }
   return sumaFila;
}

// Función para calcular la suma parcial de una columna
int calcularSumaColumna(int columna, int matriz[][columnas]) {
   int sumaColumna = 0;
   for (int i = 0; i < filas; i++) {
      sumaColumna += matriz[i][columna];
   }
   return sumaColumna;
}

// Procedimiento para mostrar la matriz
void mostrarMatriz(int matriz[][columnas]) {
   for (int i = 0; i < filas; i++) {
      for (int j = 0; j < columnas; j++) {
         cout << matriz[i][j] << "\t";
      }
      cout << endl;
    }
}

void inicializarMatriz(int matriz[][columnas]) {
   for (int i = 0; i < filas; i++) {
      for (int j = 0; j < columnas; j++) {
         matriz[i][j] = 0;
      }
   }
}

void llenarMatriz(int matriz[][columnas]) {
   for (int i = 0; i < filas-1; i++) {
      for (int j = 0; j < columnas-1; j++) {
         matriz[i][j] = generarNumeroAleatorio();
      }
   }
}

int main() {
   // Inicializar la semilla aleatoria
   srand(time(nullptr));
   int suma = 0;
   // Declarar e inicializar la matriz
   int matriz[filas][columnas];
   inicializarMatriz(matriz);
   // Llenar la matriz
   llenarMatriz(matriz);     
   // Calcular y guardar suma parcial de columna
   for (int j = 0; j < columnas; j++){
      matriz[filas-1][j] = calcularSumaColumna(j, matriz);
    } 

   //Calcular y guardar suma parcial de fila
   for (int i = 0; i < filas; i++){
      matriz[i][columnas-1] = calcularSumaFila(i, matriz);
   } 
    
    
    // Calcular suma total
    //matriz[filas][columnas] = sumaTotal;

    // Mostrar la matriz
    mostrarMatriz(matriz);

 

    return 0;
}
