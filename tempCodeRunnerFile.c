#include <stdio.h>
#include <string.h>
#include <ctype.h>

void corregirTexto(const char* archivoEntrada, const char* archivoSalida) {
    /// Abrir el archivo de entrada en modo lectura
    FILE* archivoEntradaPtr = fopen(archivoEntrada, "r");
    if (archivoEntradaPtr == NULL) {
        printf("No se pudo abrir el archivo de entrada.\n");
        return;
    }

     /// Abrir el archivo de salida en modo escritura
    FILE* archivoSalidaPtr = fopen(archivoSalida, "w");
    if (archivoSalidaPtr == NULL) {
        printf("No se pudo abrir el archivo de salida.\n");
        fclose(archivoEntradaPtr);
        return;
    }

    char palabra[50]; //Aqui la variable palabra es un arreglo con una longitud de 50 elementos.

    /// Leer palabras del archivo de entrada
    while (fscanf(archivoEntradaPtr, "%s", palabra) == 1) {
        /// Comprobar si la palabra es "ecuador" 
        if (strcmp(palabra, "ecuador") == 0) {
            /// Comprobar si la primera letra es minúscula
            if (islower(palabra[0])) {
                /// Cambiar a mayúscula
                palabra[0] = toupper(palabra[0]);
            }
        }
        /// Comprobar si la palabra es "ecuador." (con punto)
        if (strcmp(palabra, "ecuador.") == 0) {
            if (islower(palabra[0])) {
                palabra[0] = toupper(palabra[0]);
       
            }
        }
        /// Comprobar si la palabra es "ecuador," (con coma)
        if (strcmp(palabra, "ecuador,") == 0) {
            if (islower(palabra[0])) {
                palabra[0] = toupper(palabra[0]);
      
            }
        }
         /// Para escribir la palabra ecuador ya corregida en el archivo de texto de salida
        fprintf(archivoSalidaPtr, "%s ", palabra);
    }

    /// Cerrar archivos
    fclose(archivoEntradaPtr);
    fclose(archivoSalidaPtr);

    printf("Ya se corregio el archivo.");
}

int main() {
    const char* archivoEntrada = "texto_entrada.txt";
    const char* archivoSalida = "texto_salida.txt";

    /// Llamar función corregirTexto con el archivo de texto de entrada y salida
    corregirTexto(archivoEntrada, archivoSalida);

    return 0;
}