/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listes-01.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pventuri <pventuri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 16:50:49 by pventuri          #+#    #+#             */
/*   Updated: 2017/12/13 19:06:58 by pventuri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef H_LISTE_CHAINEE
#define H_LISTE_CHAINEE

typedef struct Element Element;
struct Element
{
    int nombre;
    Element *suivant;
};

typedef struct Liste Liste;
struct Liste
{
    Element *premier;
};

Liste *initialisation();
void insertion(Liste *liste, int nvNombre);
void suppression(Liste *liste);
void afficherListe(Liste *liste);
#include <stdio.h>
#include <stdlib.h>

#endif

Liste *initialisation()
{
    Liste *liste = malloc(sizeof(*liste));
    Element *element = malloc(sizeof(*element));

    if (liste == NULL || element == NULL)
    {
        exit(EXIT_FAILURE);
    }

    element->nombre = 0;
    element->suivant = NULL;
    liste->premier = element;

    return liste;
}

void insertion(Liste *liste, int nvNombre)
{
    /* Création du nouvel élément */
    Element *nouveau = malloc(sizeof(*nouveau));
    if (liste == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }
    nouveau->nombre = nvNombre;

    /* Insertion de l'élément au début de la liste */
    nouveau->suivant = liste->premier;
    liste->premier = nouveau;
}

void suppression(Liste *liste)
{
    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    if (liste->premier != NULL)
    {
      /* Suppression du premier élément */
        Element *aSupprimer = liste->premier;
        liste->premier = liste->premier->suivant;
        free(aSupprimer);
    }
}

void afficherListe(Liste *liste)
{
    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    Element *actuel = liste->premier;

    while (actuel != NULL)
    {
        printf("%d -> ", actuel->nombre);
        actuel = actuel->suivant;
    }
    printf("NULL\n");
}

void pv_delListe(Liste *liste)
{
  Element *actuel = liste->premier;
  while (actuel != NULL)
  {
    suppression(liste);
    actuel = actuel->suivant;
  }
}

int pv_lenListe(Liste *liste)
{
  int i;

  i = 0;
  Element *actuel = liste->premier;
  while (actuel != NULL)
  {
    actuel = actuel->suivant;
    i++;
  }
  return (i);
}

int main()
{
    Liste *maListe = initialisation();

    insertion(maListe, 1);
    insertion(maListe, 2);
    insertion(maListe, 3);
    //suppression(maListe);
    printf("Nombre d'éléments : %d\n", pv_lenListe(maListe));

    afficherListe(maListe);
    printf("\n");
    pv_delListe(maListe);
    afficherListe(maListe);

    return 0;
}
