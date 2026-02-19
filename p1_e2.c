/**
 * @file p1_e1.c
 * @author Alejandro Dominguez y Sergio Romera
 * @date February 2026
 * @version 1.0
 * @brief Crear e inicializar una radio
 *
 * @details 
 * 
 * @see
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include "radio.h"

 int main()
 {
    Radio *r = NULL;
    char *desc1 = "id:111 title:'Paint It, Black' artist:'The Rolling Stones' duration:202";
    char *desc2 = "id:222 title:'Every Breath You Take' artist:'The Police' duration:253";
    /*Inicializar la radio*/
    r = radio_init();
    /*incluir nueva musica y comprobar si se puede meter en la radio*/
    printf("Inserting Paint it, Black... ");
    if (radio_newMusic(r, desc1) == ERROR)
    {
        printf("result...: 0\n");
        return -1;
    }

    printf("result...: 1\n");

    printf("Inserting Every Brith You Take... ");
    if (radio_newMusic(r, desc2) == ERROR)
    {
        printf("result...: 0\n");
        return -1;
    }

    printf("result...: 1\n");

    /*Crear una relacion entre la primera cancion y la segunda*/
    printf("Inserting radio recommendation: 222 --> 111\n");
    if (radio_newRelation(r, 222, 111) == ERROR)
    {
        printf("No se ha podido crear la relacion.");
        return -1;
    }
    else
    {
        printf("Recommendation inserted...\n");
    }

    /*Comprobamos si la cancion 111 tiene relacion con la cancion 222*/
    printf("111 --> 222? ");
    if (radio_relationExists(r, 111, 222) == FALSE)
    {
        printf("No\n");
    }
    else
    {
        printf("Si\n");
    }
    

    /*Comprobar si la canción con id 222 está relacionada con la canción con id 111*/
    printf("222 --> 111? ");
    if (radio_relationExists(r, 222, 111) == FALSE)
    {
        printf("No\n");
    }
    else
    {
        printf("Si\n");
    }

    /* Obtener e imprimir el número de recomendaciones desde la canción con id 111*/
    printf("Radio recommendations from Paint It, Black: %ln\n", radio_getRelationsFromId(r, 111));

    /*Imprimir la radio al completo (todas las recomendaciones para cada canción)*/
    printf("All radio recommendations:\n");
    radio_print(stdout, r);

    /* Liberar todos los recursos y salir*/
    radio_free(r);
    
    return 0;
 }