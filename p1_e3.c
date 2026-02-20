/**
 * @file p1_e3.c
 * @author Alejandro Dominguez y Sergio Romera
 * @date Febrero 2026
 * @brief Programa para probar la lectura de Radio desde fichero (Ejercicio 3)
 */

#include <stdio.h>
#include <stdlib.h>
#include "radio.h"

int main(int argc, char *argv[]) {
    Radio *r = NULL;
    FILE *f = NULL;

    if (argc < 2) {
        fprintf(stderr, "Uso: %s <fichero_radio>\n", argv[0]);
        return EXIT_FAILURE;
    }

    /* 1. Inicializar Radio */
    r = radio_init();
    if (!r) {
        fprintf(stderr, "Error inicializando la radio.\n");
        return EXIT_FAILURE;
    }

    /* 2. Abrir el fichero */
    f = fopen(argv[1], "r");
    if (!f) {
        perror("Error al abrir el fichero");
        radio_free(r);
        return EXIT_FAILURE;
    }

    /* 3. Leer la radio desde el fichero */
    if (radio_readFromFile(f, r) == ERROR) {
        fprintf(stderr, "Error leyendo los datos del fichero.\n");
        fclose(f);
        radio_free(r);
        return EXIT_FAILURE;
    }

    /* 4. Imprimir la radio (Salida esperada) */
    printf("Radio recommendations:\n");
    radio_print(stdout, r);

    /* 5. Limpieza y salida */
    fclose(f);
    radio_free(r);

    return EXIT_SUCCESS;
}