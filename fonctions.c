#include "fonctions.h"

void buffer() { // Videbuffer pour éviter le crash au scanf
  while (getchar() != '\n')
    ;
}

int menu() { // Affichage du menu CYcrush
  couleur(34) int a;
  char c[50];
  FILE *f = fopen("menu.txt", "r");
  if (f == NULL) {
    printf("Impossible");
    return 5;
  } else {
    while (fgets(c, sizeof c, f) != NULL) {
      printf("%s", c);
    }
    fclose(f);
    printf("\n");
  }
  couleur(0)
}

void regle() {// Explication des règles avec 3s de délais entre chaque phrases

  printf("CYcrush est un puzzle game se basant sur le même principe que "
         "CandyCrush comme son nom l'indique. Attention cependant, les règles "
         "diffèrent un peu !\n");
  sleep(3);
  printf("-Premièrement, vous pouvez échanger deux cases symboles entre elles peu "
         "importe leur emplacement l'une par rapport à l'autre\n");
  sleep(3);
  printf("-Deuxièmement, une fois qu'il y a un cassage, la grille ne se "
         "remplit pas\n");
  sleep(3);
  printf(
      "-Troisièmement, et le plus important ! Vous pouvez casser les bonbons "
      "par 3 ou plus, que ce soit en verticale, horizontale ou diagonale !\n");
  sleep(3);
  printf("1.Retour ?\n"); //Demande au joueur s'il veux revenir au menu de jeux 
}

Dimensions
option(Dimensions dim) { // Affichage du menu de sélection de la difficulté
  int check1, check2;
  dim.a = 0;
  menu();
  printf("                      1.Dimensions\n                      2.Nombre de symboles\n                      3.Scores\n                      4.Retour\n");
  do {
    scanf("%d", &dim.a);
  } while (dim.a < 1 || dim.a > 4);
  switch (dim.a) {
    case 1:
      //Choix de la dimension du plateau de jeu
      do {
        printf("Quel nombre de ligne veux-tu ? (Minimum 3 sinon c'est pas drole "
             ";-;)\n");
        check1 = scanf("%d", &dim.d1);
        buffer();
        printf("Quel nombre de colone veux-tu ? (Minimum 3 aussi sinon c'est "
              "encore moins drôle ;-;)\n");
        check2 = scanf("%d", &dim.d2);
        buffer();
        if (dim.d2 < 3 || dim.d1 < 3 || check1 != 1 || check2 != 1) {
          couleur(33) 
          printf("Erreur de saisie. Veuillez  réessayer.\n");
          couleur(0)
        }
      } while (dim.d2 < 3 || dim.d1 < 3 || check1 != 1 || check2 != 1);
      return dim;
      break;
    case 2:
      //Choix du nombre de symboles
      do {
        printf("Combien de symboles veux-tu ? (Minimum 4 et Max 6)\n");
        check1 = scanf("%d", &dim.nb_s);
        buffer();
        if (dim.nb_s < 4 || dim.nb_s > 7 || check1 != 1) {
          couleur(31) 
          printf("Erreur de saisie. Veuillez  réessayer.\n");
          couleur(0)
        }
      } while (dim.nb_s < 4 || dim.nb_s > 7 || check1 != 1);
      return dim;
      break;
    case 3 :
      //Affichage des scores
      lire_meilleurs_scores();
      sleep(5);
      return dim;
      break;
    case 4:
      //Retour au menu principal
      return dim;
      break;
  }
  return dim;
}

void sauvegarde(int **plat, Dimensions dim, int *score, int *tour){ //Enregistre la partie avec le plateau, les dimensions, le score, le nombre de tour dans un fichier.
  FILE *f = fopen("sauvegarde.txt", "w+"); //Créer et ouvre un fichier en mode ecriture 
  if (f == NULL) { // Affiche un message d'erreur lorsqu'il est vide 
    couleur(33) printf("Impossible");
    couleur(0) exit(1);
  }
  fprintf(f, "%d\n", *tour);
  fprintf(f, "%d\n", *score);
  fprintf(f, "%d\n", dim.d1);
  fprintf(f, "%d\n", dim.d2);
  for (int i = 0; i < dim.d1; i++) { //Ecrit la position des cases du tableau
    for (int j = 0; j < dim.d2; j++) {
      fprintf(f, "%d", plat[i][j]);
    }
  }
  fclose(f); // Ferme le fichier
}

void charger_sauvegarde(int **plat, Dimensions dim, int *score, int *tour) { // Génére la partie qui à été sauvegarder
  FILE *f = fopen("sauvegarde.txt", "r+"); //Ouvre un fichier en mode lecture
  if (f == NULL) { // Affiche un message lorsqu'il est vide
    couleur(33) printf("Impossible");
    couleur(0) exit(1);
  }
  fscanf(f, "%d", tour);
  fscanf(f, "%d", score);
  fscanf(f, "%d", &dim.d1);
  fscanf(f, "%d", &dim.d2);
  plat = (int **)malloc(dim.d1 * sizeof(int *)); //Fait de la place en mémoire pour créer un tableau 2D
  for (int i = 0; i < dim.d1; i++) {
    plat[i] = (int *)malloc(dim.d2 * sizeof(int));
  }

  for (int i = 0; i < dim.d1; i++) { //Recupère la position des cases du tableau dans le fichier 
    for (int j = 0; j < dim.d2; j++) {
      fscanf(f, "%d", &plat[i][j]);
    }
  }
  free(plat); //Libère la mémoire créer pour le tableau 2D
  fclose(f);
}

void sauvegarde_victoire(char pseudo[], int *tour) {//Ecrit le pseudo et le nombre de tour dans un fichier
  FILE *f = fopen("sauvegarde_victoire.txt", "w+");//Créer et ouvre un fichier en mode écriture
  if (f == NULL) {// Affiche un message lorsqu'il est vide
    couleur(33);
    printf("Impossible");
    couleur(0); 
    exit(1);
  }
  fprintf(f, "%s\n", pseudo);
  fprintf(f, "%d", *tour);
  fclose(f);
}

void lire_meilleurs_scores() { //Lis le fichier des meilleurs scores
  int score;
  FILE *f = fopen("sauvegarde_meilleur_score.txt", "r+");//Ouvre un fichier en mode lecture
  if (f == NULL) {// Affiche un message lorsqu'il est vide
    couleur(33); 
    printf("Impossible");
    couleur(0); 
    exit(1);
  }
  while (fscanf(f, "%d", &score) == 1) {// Parcours tout le fichier d'entiers
    printf("         %d          ", score);// Affiche les scores dans le fichier
  }
  fclose(f);
}
  
void mise_a_jour_score(int *score) {
  FILE *f = fopen("sauvegarde_meilleur_score.txt", "a+");//Créer et ouvre un fichier en mode lecture
  if (f == NULL) {// Affiche un message lorsqu'il est vide
    couleur(33); 
    printf("Impossible");
    couleur(0); 
    exit(1);
  }
  fprintf(f,"%d\n",*score);
  fclose(f);
}

int **construct_plat(Dimensions dim, int *score) { // Construction du plateau de jeu
  int i, j;
  int verif;
  int **plat;
  plat = (int **)malloc(dim.d1 * sizeof(int *)); //Fait de la place pour créer un tableau 2D
  for (i = 0; i < dim.d1; i++) {
    plat[i] = (int *)malloc(dim.d2 * sizeof(int));
  }
  for (i = 0; i < dim.d1; i++) { //Parcours le tableau et lui donne des valeurs aléatoires en fonction du nombre de symboles
    for (j = 0; j < dim.d2; j++) {
      plat[i][j] = rand() % dim.nb_s + 1;
    }
  }
  do {
    verif = cassage(plat, dim, score); //Vérifie qu'il n'y ait pas 3 symboles identiques cote à cote
    for (i = 0; i < dim.d1; i++) {
      for (j = 0; j < dim.d2; j++) {
        if (plat[i][j] == 0) {
          plat[i][j] = rand() % dim.nb_s + 1;
        }
      }
    }
  } while (verif == 1);
  return plat;
}

void affichage(int **plat, Dimensions dim, int tour, int score) { // Affichage du plateau de jeu
  int i, j;
  printf("   ");
  for (i = 0; i < dim.d2; i++) { // Affichage des colones avec le nom des lettes
    printf(" %c ", 'A' + i);
  }
  printf("   Tour : %d", tour);
  printf("\n   ");
  for (i = 0; i < dim.d2; i++) {
    printf("-- ");
  }
  printf("   Score : %d ", score);
  printf("\n");
  for (i = 0; i < dim.d1; i++) { //Affichage des lignes avec les chiffres
    if (i > 8) { 
      printf("%d|", i + 1);
    } else {
      printf("%d |", i + 1);
    }
    for (j = 0; j < dim.d2; j++) {
      switch (plat[i][j]) { //Formation des emojis
      case 0:
        printf("   ");
        break;
      case 1:
        printf("\U0001F351 ");
        break;
      case 2:
        printf("\U0001F352 ");
        break;
      case 3:
        printf("\U0001F34F ");
        break;
      case 4:
        printf("\U0001F968 ");
        break;
      case 5:
        printf("\U0001F347 ");
        break;
      case 6:
        printf("\U0001F349 ");
        break;
      }
      if (j == dim.d2 - 1) {
        printf("\n");
      }
    }
  }
}

void echangeCase(int **plat, int a, int b, int c, int d) { // Echange deux cases entre elles
  int temp;
  temp = plat[b][a];
  plat[b][a] = plat[d][c];
  plat[d][c] = temp;
}

Deplacements choixCase(int **plat, Dimensions dim) { // Déplacement du joueur
  char a, c;
  int b, d, temp, check1, check2;
  Deplacements echange;
  //Choix de la première case à déplacer
  do {
    couleur(34) printf("Quel case voulez vous déplacer ? \n ");
    couleur(0) printf("Colone :");
    check1 = scanf("%c", &a);
    buffer();
    printf(" Ligne :");
    check2 = scanf("%d", &b);
    buffer();
    if (a < 65 || (a >= 65 + dim.d2 && a < 97) || a >= 97 + dim.d2 || b < 1 || b > dim.d1 || check1 != 1 || check2 != 1) {
      couleur(33) printf("Erreur de saisie. Veuillez  réessayer.\n");
      couleur(0)
    }
  } while (a < 65 || (a >= 65 + dim.d2 && a < 97) || a >= 97 + dim.d2 ||
           b < 1 || b > dim.d1 || check1 != 1 || check2 != 1);
  //Choix de la deuxième case à déplacer
  do {
    couleur(34) printf("Avec laquelle ? \n");
    couleur(0) printf("Colone :");
    check1 = scanf("%c", &c);
    buffer();
    printf(" Ligne :");
    check2 = scanf("%d", &d);
    buffer();
    if (c < 65 || (c >= 65 + dim.d2 && c < 97) || c >= 97 + dim.d2 || d < 1 ||
        d > dim.d1 || check1 != 1 || check2 != 1) {
      couleur(33) printf("Erreur de saisie. Veuillez  réessayer.\n");
      couleur(0)
    }
  } while (c < 65 || (c >= 65 + dim.d2 && c < 97) || c >= 97 + dim.d2 || d < 1 || d > dim.d1 || check1 != 1 || check2 != 1);
  if (a >= 97 && a < 97 + dim.d2) {
    a = a - 32;
  }
  if (c >= 97 && c < 97 + dim.d2) {
    c = c - 32;
  }
  echange.a = a - 65;
  echange.b = b - 1;
  echange.c = c - 65;
  echange.d = d - 1;
  if (plat[echange.b][echange.a] == 0 || plat[echange.d][echange.c] == 0) {
    printf("Erreur de saisie veuillez rentrer d'autre case");
  } else {
    echangeCase(plat, echange.a, echange.b, echange.c, echange.d);
  }
  return echange;
}

int cassage(int **plat, Dimensions dim, int *score) { // Fonction de cassage des symboles
  int compteur;
  int a, b;
  a = 0;
  for (int i = 0; i < dim.d1; i++) {
    compteur = 1;
    for (int j = 0; j < dim.d2; j++) {
      // Vérification des lignes
      while (j + compteur < dim.d2 && plat[i][j] == plat[i][j + compteur]) {
        compteur += 1;
      }
      if (compteur > 2 && plat[i][j] != 0) {
        //Transformation des lignes en case vide 
        for (int k = 0; k < compteur; k++) {
          if (compteur - 1 + j - k >= 0) {
            plat[i][compteur - 1 + j - k] = 0;
          }
        }
        a = 1;
        *score = *score + (compteur * 100);
      }
      compteur = 1;
      // Vérification des colones
      while (i + compteur < dim.d1 && plat[i][j] == plat[i + compteur][j]) {
        compteur += 1;
      }
      if (compteur > 2 && plat[i][j] != 0) {
        //Transformation des colones en case vide 
        for (int k = 0; k < compteur; k++) {
          if (compteur - 1 + i - k >= 0) {
            plat[compteur - 1 + i - k][j] = 0;
          }
        }
        a = 1;
        *score = *score + (compteur * 100);
      }
      compteur = 1;
      // Vérification des diagonales haut-bas
      while (i + compteur < dim.d1 && j + compteur < dim.d2 &&
             plat[i][j] == plat[i + compteur][j + compteur]) {
        compteur += 1;
      }
      if (compteur > 2 && plat[i][j] != 0) {
        //Transformation des diagonales haut-bas en case vide 
        for (int k = 0; k < compteur; k++) {
          if (compteur - 1 + i - k >= 0 && compteur - 1 + j - k >= 0) {
            plat[compteur - 1 + i - k][compteur - 1 + j - k] = 0;
          }
        }
        a = 1;
        *score = *score + (compteur * 100);
      }
      compteur = 1;
      // Vérification des diagonales bas-haut
      while (i + compteur < dim.d1 && j - compteur >= 0 &&
             plat[i][j] == plat[i + compteur][j - compteur]) {
        compteur += 1;
      }
      if (compteur > 2 && plat[i][j] != 0) {
        //Transformation des diagonales bas-haut en case vide 
        for (int k = 0; k < compteur; k++) {
          if (compteur - 1 + i - k >= 0 && compteur + 1 - j + k >= 0) {
            plat[compteur - 1 + i - k][j + 1 - compteur + k] = 0;
          }
        }
        a = 1;
        *score = *score + (compteur * 100);
      }
      compteur = 1;
    }
  }
  return a;
}

int verifcassage(int **plat, Dimensions dim) {
  int i, j;
  for (i = 0; i < dim.d1; i++) {
    for (j = 0; j < dim.d2; j++) {
      if (plat[i][j] != 0) {
        //Vérification si 3 symboles en ligne
        if (i + 2 < dim.d1 && plat[i][j]) { 
          if (plat[i][j] == plat[i + 1][j] && plat[i][j] == plat[i + 2][j]) {
            return 1;
          }
        }
        //Vérification si 3 symboles en colone
        if (j + 2 < dim.d2) {
          if (plat[i][j] == plat[i][j + 1] && plat[i][j] == plat[i][j + 2]) {
            return 1;
          }
        }
        //Vérification si 3 symboles en diagonale haut-bas
        if (i + 2 < dim.d1 && j - 2 >= 0) {
          if (plat[i][j] == plat[i + 1][j - 1] && plat[i][j] == plat[i + 2][j - 2]) {
            return 1;
          }
        }
        //Vérification si 3 symboles en diagonale bas-haut
        if (i + 2 < dim.d1 && j + 2 < dim.d2) {
          if (plat[i][j] == plat[i + 1][j + 1] && plat[i][j] == plat[i + 2][j + 2]) {
            return 1;
          }
        }
      }
    }
  }
  return 0;
}

void gravite(int **plat, Dimensions dim) { // Gravité vers le bas
  int temp;
  for (int i = 0; i < dim.d1; i++) {
    for (int j = 0; j < dim.d2; j++) {
      if (plat[i][j] == 0) {
        for (int k = i; k >= 1; k--) {
          temp = plat[k][j];
          plat[k][j] = plat[k - 1][j];
          plat[k - 1][j] = temp;
        }
      }
    }
  }
}

int testVictoire(int **plat, Dimensions dim) {
  int temp, compteur_symbole, a; 
  a = 0;
  int i, j, k, l;
  //Parcours tout le tableau 
  for (k = 0; k < dim.d1; k++) {
    for (l = 0; l < dim.d2; l++) {
      //Vérifie cassage pour chaque mouvement de chaque case du tableau
      for (i = 0; i < dim.d1; i++) {
        for (j = 0; j < dim.d2; j++) {
          if (plat[k][l] != 0) {
            echangeCase(plat, l, k, j, i);
            if (verifcassage(plat, dim) == 1) {
              a = 1;
            }
            echangeCase(plat, l, k, j, i);
          }
        }
      }
    }
  }
  return a;
}

void compteur_symbole(int **plat, Dimensions dim, int score, char pseudo[], int *tour) { //Compte le nombre de symbole total
  int compteur_symbole = 0;
  for (int i = 0; i < dim.d1; i++) {
    for (int j = 0; j < dim.d2; j++) {
      if (plat[i][j] > 0 && plat[i][j] < 7) {
        compteur_symbole += 1;
      }
    }
  }
  if (compteur_symbole < 3) {
    printf("Vous avez gagné avec un score de %d points\n", score);
    sauvegarde_victoire(pseudo, tour);
    mise_a_jour_score(&score);
  }
  else {
    printf("Vous avez perdu avec un score de %d points\n", score);
  }
}
