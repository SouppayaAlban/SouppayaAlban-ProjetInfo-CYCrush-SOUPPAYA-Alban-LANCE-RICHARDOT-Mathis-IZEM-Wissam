#include "fonctions.h"

void buffer(){ // Videbuffer pour éviter le crash au scanf
	while( getchar() != '\n');
}

int menu(){ //Affichage du menu CYcrush
  couleur(34)
	int a;
	char c[50];
	FILE*f = fopen("menu.txt", "r");
	if(f==NULL){
		printf("Impossible");
    	return 5;
	}
	else{
		while(fgets(c,sizeof c,f )!=NULL){
      		printf("%s", c);
		}
	fclose(f);
	printf("\n");
	}
  couleur(0)
}

void regle(){ //Explication des règles
  
	printf("CYcrush est un puzzle game se basant sur le même principe que CandyCrush comme son nom l'indique. Attention cependant, les règles diffèrent un peu !\n");
     sleep(3);
     printf("-Premièrement, vous pouvez échanger deux cases entre elles peu importe leur emplacement l'une par rapport à l'autre\n");
     sleep(3);
     printf("-Deuxièmement, une fois qu'il y a un cassage, la grille ne se remplit pas\n");
     sleep(3);
     printf("-Troisièmement, et le plus important ! Vous pouvez casser les bonbons par 3 ou plus, que ce soit en verticale, horizontale ou diagonale !\n");
     sleep(3);
     printf("1.Retour ?\n");
}

Dimensions option(Dimensions dim){ //Affichage du menu de sélection de la difficulté
	int check1, check2;
	dim.a = 0;
	menu();
    printf("                      1.Dimensions\n                      2.Nombre de symboles\n                      3.Retour\n");
	do{
      scanf("%d", &dim.a);
  }while(dim.a<1 || dim.a>3);
  switch(dim.a){
    case 1 :
      do{
      printf("Quel nombre de ligne veux-tu ? (Minimum 3 sinon c'est pas drole ;-;)\n");
      check1 = scanf( "%d" , &dim.d1);
      buffer();
      printf("Quel nombre de colone veux-tu ? (Minimum 3 aussi sinon c'est encore moins drôle       ;-;)\n");
      check2 = scanf( "%d" , &dim.d2);
      buffer();
      if(dim.d2<3 || dim.d1<3|| check1 != 1 || check2 !=1){
        couleur(33)
        printf("Erreur de saisie. Veuillez  réessayer.\n");
        couleur(0)
       }
      }while(dim.d2<3 || dim.d1<3 || check1 != 1 || check2 !=1);
      return dim;
      break;
    case 2 :
      do{
    	 printf("Combien de symboles veux-tu ? (Minimum 4 et Max 6)\n");
        check1 = scanf( "%d" , &dim.nb_s);
        buffer();
        if(dim.nb_s<4 || dim.nb_s>7 || check1 != 1){
          couleur(31)
          printf("Erreur de saisie. Veuillez  réessayer.\n");
          couleur(0)
        }
      }while(dim.nb_s<4 || dim.nb_s>7 || check1 != 1);
      return dim;
      break;
    case 3 : 	
      return dim;
      break;
  }
  return dim;
}

void sauvegarde(int **plat, Dimensions dim){
	FILE*f = fopen("sauvegarde.txt", "w+");
	if(f==NULL){
		printf("Impossible");
		exit(1);
	}
	fprintf(f,"%d\n", dim.d1);
	fprintf(f,"%d\n", dim.d2);
	for(int i=0 ; i<dim.d1 ; i++){
		for(int j=0 ; j<dim.d2 ; j++){
			fprintf(f,"%d",plat[i][j]);
		}
	}
	fclose(f);
}

void charger_sauvegarde(int **plat, Dimensions dim){
	FILE*f = fopen("sauvegarde.txt", "r+");
	if(f==NULL){
    couleur(33)
		printf("Impossible");
    couleur(0)
		exit(1);
	}
	fscanf(f,"%d", &dim.d1);
	fscanf(f,"%d", &dim.d2);
	for(int i=0 ; i<dim.d1 ; i++){
		for(int j=0 ; j<dim.d2 ; j++){
			fscanf(f,"%d",&plat[i][j]);
			if(plat[i][j]==-1){
				plat[i][j]=0;
			}
		}
	}
	fclose(f);
}

int** construct_plat(Dimensions dim, int *score){ //Construction du plateau de jeu
	int i, j;
	int verif;
	int **plat;
	plat =(int**)malloc(dim.d1*sizeof(int*));
	for(i=0; i<dim.d1; i++){
		plat[i]=(int*)malloc(dim.d2*sizeof(int));
	}
	for(i=0; i<dim.d1; i++){
		for(j=0; j<dim.d2; j++){
			plat[i][j]=rand()%dim.nb_s+1; 
		}
	}
	do{
		verif = cassage(plat, dim, score);
		for(i=0; i<dim.d1; i++){
			for(j=0; j<dim.d2; j++){
				if(plat[i][j]==0){
					plat[i][j]=rand()%dim.nb_s+1;
				}
			}
		}	
	}while(verif == 1);
	return plat;
}

void affichage(int **plat, Dimensions dim, int tour, int score){ //Affichage du plateau de jeu
	int i, j;
	printf("   ");
	for(i=0; i<dim.d2; i++){
		printf(" %c ",'A'+i);
	}
  printf("   Tour : %d", tour);
	printf("\n   ");
	for(i=0; i<dim.d2; i++){
		printf("-- ");
	}
  printf("   Score : %d ", score);
	printf("\n");
	for(i=0; i<dim.d1; i++){
		if(i>8){
			printf("%d|",i+1);
		}
		else{
			printf("%d |",i+1);
		}
		for(j=0; j<dim.d2; j++){
			switch(plat[i][j]){
 				case 0 :
					printf("   ");
					break;
				case 1 :
					printf("\U0001F351 ");
					break;
				case 2 :
					printf("\U0001F352 ");
					break;
				case 3 :
					printf("\U0001F34F ");
					break;
				case 4 :
					printf("\U0001F968 ");
					break;
				case 5 :
					printf("\U0001F347 ");
					break;
				case 6 :
					printf("\U0001F349 ");
					break;
			}
			if(j==dim.d2-1){
				printf("\n");
			}
		}
	}
}	

void echangeCase(int** plat, int a, int b, int c, int d){ //Inversion des déplacement si mauvais mouvement
  int temp;
  temp = plat[b][a];
	plat[b][a] = plat[d][c];
	plat[d][c] = temp;
}

 Deplacements choixCase(int **plat, Dimensions dim){ //Déplacement du joueur
	char a, c;
	int b, d, temp, check1, check2;
  Deplacements echange;
	do{
    couleur(34)
		printf("Quel case voulez vous déplacer ? \n ");
    couleur(0)
    printf("Colone :");
		check1 = scanf("%c", &a);
		buffer();
		printf(" Ligne :");
		check2 = scanf("%d", &b);
		buffer();
		if(a<65 || (a>=65+dim.d2 && a<97) || a>=97+dim.d2 || b<1 || b>dim.d1 || check1 != 1 || check2 !=1){
      couleur(33)
			printf("Erreur de saisie. Veuillez  réessayer.\n");
      couleur(0)
		}
	}while(a<65 || (a>=65+dim.d2 && a<97) || a>=97+dim.d2 || b<1 || b>dim.d1 || check1 != 1 || check2 !=1);
	do{
    couleur(34)
		printf("Avec laquelle ? \n");
    couleur(0)
    printf("Colone :");
		check1 = scanf("%c", &c);
		buffer();
		printf(" Ligne :");
		check2 = scanf("%d", &d);
		buffer();
		if(c<65 || (c>=65+dim.d2 && c<97) || c>=97+dim.d2 || d<1 || d>dim.d1 || check1 != 1 || check2 !=1){
      couleur(33)
			printf("Erreur de saisie. Veuillez  réessayer.\n");
      couleur(0)
		}
	}while(c<65 || (c>=65+dim.d2 && c<97) || c>=97+dim.d2 || d<1 || d>dim.d1 || check1 != 1 || check2 !=1);
	if(a>=97 && a<97+dim.d2){
		a = a-32;
	}
	if(c>=97 && c<97+dim.d2){
		c = c-32;
	}
	echange.a = a-65;
	echange.b = b-1;
	echange.c = c-65;
	echange.d = d-1;
  echangeCase(plat,echange.a, echange.b, echange.c, echange.d);
	return echange;
}

int cassage(int** plat, Dimensions dim, int *score) { //Fonction de cassage des symboles
  int compteur;
  int a, b;
  a = 0;
  for (int i = 0; i < dim.d1; i++) {
    compteur = 1;
    for (int j = 0; j < dim.d2; j++) {
      // Vérification des horizontales
      while(j + compteur < dim.d2 && plat[i][j] == plat[i][j + compteur]) {
        compteur += 1;
      }
      if(compteur > 2 && plat[i][j] !=0) {
        for (int k = 0; k < compteur; k++) {
          if (compteur-1+j - k >= 0) {
            plat[i][compteur-1+j - k] = 0;
          }
        }
        a=1;
        *score = *score+(compteur*100);
      }
      compteur = 1;
      // Vérification des verticales
      while(i + compteur < dim.d1 && plat[i][j] == plat[i + compteur][j]) {
        compteur += 1;
      }
      if (compteur > 2 && plat[i][j] !=0) {
        for (int k = 0; k < compteur; k++) {
          if (compteur-1+i - k >= 0) {
              plat[compteur-1+i - k][j] = 0; 
          }
        }
        a=1;
        *score = *score+(compteur*100);
      }
      compteur = 1;
      // Vérification des diagonales haut-bas
      while(i + compteur < dim.d1 && j + compteur < dim.d2 && plat[i][j] == plat[i + compteur][j + compteur]) {
        compteur += 1;
      }
      if (compteur > 2 && plat[i][j] !=0) {
        for (int k = 0; k < compteur; k++) {
          if (compteur-1+i - k >= 0 && compteur-1+j - k >= 0) {
              plat[compteur-1+i - k][compteur-1+j - k] = 0; 
          }
        }
        a=1;
        *score = *score+(compteur*100);
      }
      compteur = 1;
      // Vérification des diagonales bas-haut
        while(i + compteur < dim.d1 && j - compteur >= 0 && plat[i][j] == plat[i + compteur][j - compteur]){
        compteur += 1;
        }
        if (compteur > 2 && plat[i][j] !=0) {
          for (int k = 0; k < compteur; k++) {
            if (compteur-1+i - k >= 0 && compteur+1-j + k >= 0) {
              plat[compteur-1+i - k][j+1-compteur + k] = 0; 
            }  
          }
          a=1;
          *score = *score+(compteur*100);
       }
        compteur = 1;
    }
  }
  return a;
}

int verifcassage(int** plat, Dimensions dim){
	int i, j;
	for(i=0; i<dim.d1; i++){
		for(j=0; j<dim.d2; j++){
			if(plat[i][j] != 0){
				if(i+2 < dim.d1 && plat[i][j]){
					if(plat[i][j] == plat[i+1][j] && plat[i][j] == plat[i+2][j]){
						return 1;
					}
				}
				if(j+2 < dim.d2){
					if(plat[i][j] == plat[i][j+1] && plat[i][j] == plat[i][j+2]){
						return 1;
					}
				}
				if(i+2 < dim.d1 && j-2 >=0){
					if(plat[i][j] == plat[i+1][j-1] && plat[i][j] == plat[i+2][j-2]){
						return 1;
					}
				}
				if(i+2 < dim.d1 && j+2 < dim.d2){
					if(plat[i][j] == plat[i+1][j+1] && plat[i][j] == plat[i+2][j+2]){
						return 1;
					}
				}
			}	
		}
	}
	return 0;
}
	

void gravite(int **plat, Dimensions dim){ //Gravité vers le bas
	int temp;
	for(int i=0; i<dim.d1; i++){
		for(int j=0; j<dim.d2; j++){
			if(plat[i][j] == 0){
				for(int k=i; k>=1; k--){
					temp = plat[k][j];
					plat[k][j] = plat[k-1][j];
					plat[k-1][j] = temp;
				}
			}
		}
	}
}

int testVictoire(int **plat, Dimensions dim){
	int temp;
	int i, j , k, l;
	for(k = 0;k<dim.d1; k++){
		for(l = 0; l<dim.d2; l++){
			for(i = 0; i<dim.d1; i++){
				for(j = 0 ; j<dim.d2; j++){
					if(i+k < dim.d1 && j+l < dim.d2 && plat[i+k][j+l] != 0){
						echangeCase(plat, j+l, i+k, j+l+1, i+k);
						if(verifcassage(plat, dim)==1){
							return 1;
						}
						else{
							echangeCase(plat, j+l, i+k, j+l+1, i+k);
						}
					}
				}
			}
		}
	}
	return 0;
}

