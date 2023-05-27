#ifndef FONCTIONS
#define FONCTIONS

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

#define clear() printf("\033[H\033[J")
#define couleur(param)\
	printf("\033[%dm", param);

typedef struct{
	int d1;
	int d2;
	int nb_s;
  int a;
}Dimensions;

typedef struct{
  int a;
  int b;
  int c;
  int d;
}Deplacements;

void buffer();

int menu();

void regle();

Dimensions option(Dimensions dim);

void sauvegarde(int **plat, Dimensions dim, int *score, int *tour);

void charger_sauvegarde(int **plat, Dimensions dimn, int *score, int *tour);

void sauvegarde_victoire(char pseudo[], int *tour);

void lire_meilleurs_scores();

void mise_a_jour_score(int *score);

int** construct_plat(Dimensions dim, int* score);

void affichage(int **plat, Dimensions dim, int tour, int score);

void echangeCase(int **plat, int a, int b, int c, int d);

Deplacements choixCase(int **plat, Dimensions echange);

int cassage(int **plat, Dimensions dim, int* score);

int verifcassage(int** plat, Dimensions dim);

void gravite(int **plat, Dimensions dim);

int testVictoire(int **plat, Dimensions dim);

void compteur_symbole(int **plat, Dimensions dim, int score, char pseudo[], int *tour);

int CYcrush(int **plat, Dimensions dim);

#endif