/**
 * @file p1_e1.c
 * @author Alejandro y Sergio
 * @date February 2026
 * @version 1.0
 * @brief Crear e inicializar dos canciones
 *
 * @details 
 * 
 * @see
 */

 #include <stdio.h>
 #include "music.h"
 #include <stdlib.h>
 #include <string.h>

 int main()
 {
    Music *m1 = NULL, *m2 = NULL, *m3 = NULL;
    /*Inicializamos dos canciones*/
    m1 = music_init();
    m2 = music_init();

    if (!m1 || !m2)
    {
        music_free(m1);
        music_free(m2);
        return ERROR;
    }

    /*Configuramos la primera cancion*/
    music_setId(m1, 10);
    music_setTitle(m1, "Blinding Lights");
    music_setArtist(m1, "The Weeknd");
    music_setDuration(m1, 200);

    /*Configuramos segunda cancion*/
    music_setId(m2, 20);
    music_setTitle(m2, "Bohemian Rhapsody");
    music_setArtist(m2, "Queen");
    music_setDuration(m2, 355);

    /*Resproducir e imprimir ambas canciones*/
    music_formatted_print(stdout, m1);
    music_formatted_print(stdout, m2);
    printf("\n");
    
    /*Comparar canciones*/
    if (music_cmp(m1, m2) == 0)
    {
        printf("Equals? Yes\n");
    }
    else
    {
        printf("Equals? No\n");
    }

    /*Imprimimos el titulo de la segunda cancion*/
    printf("Music 2 title: %s\n", music_getTitle(m2));

    /*Copiamos la primera cancion en una tercera*/
    m3 = music_copy(m1);

    /*Imprimir el id de la tercera canción*/
    printf("Music 3 Id: %ld\n", music_getId(m3));

    /*Reproducir (imprimir) la primera y la tercera canción*/
    music_formatted_print(stdout, m1);
    music_formatted_print(stdout, m3);
    printf("\n");

    /*Comparar la primera y la tercera canción*/
    if (music_cmp(m1, m3) == 0)
    {
        printf("Equals? Yes\n");
    }
    else
    {
        printf("Equals? No\n");
    }

    /*Liberar memoria*/
    music_free(m1);
    music_free(m2);
    music_free(m3);

    return OK;

 }

 