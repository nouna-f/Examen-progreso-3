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