#include "fonctions.h"

int CYcrush(int** plat, Dimensions dim){ //Fonction principale de jeu
  	//Initialisation de toutes les variables 
	int var = 0;
	int *score;
  	int points = 0;
  	score = &points;
  	int tour = 0;
  	char pseudo[100];
  	int taille=0, i=0;
	int men;
	int check;
  	Deplacements echange;
  	char choix;
  	//Affichage du menu de jeu
  	clear();
	menu();
	printf("                          1.Jouer\n                          2.Règles\n                          3.Options\n                          4.Quitter\n");
  	couleur(0)
	do{
		check = scanf("%d", &men);
		buffer();
	}while(men < 1 || men > 4 || check !=1);
	printf("\n");
	switch(men){
		case 1:
    			clear();
			menu();
			printf("                     1.Nouvelle partie\n                    2.Charger Sauvegarde\n");
			do{
				check = scanf("%d", &men);
				buffer();
			}while(men < 1 || men > 2 || check !=1);
			if(men==1){
        			clear();
        			menu();
				printf("                     Pseudo:\n");
         		 	//Demande du Pseudo joueur
        			do{
				    	check = scanf("%s", pseudo);
				    	buffer();
            				while (pseudo[i] != '\0') {
              				taille+=1;
              				i++;
            				}
			    	}while(check !=1);
        			tour+=1;
				clear();
				plat = construct_plat(dim, score);
        			*score = 0;
				affichage(plat, dim, tour, points);
			}
			else{
				clear();
				charger_sauvegarde(plat,dim, &points,&tour);
				affichage(plat,dim, tour, points);				
			}
		  	do{
        			//Choix de mouvement du joueur
        			do{
          				echange = choixCase(plat, dim);
          				if(verifcassage(plat, dim) == 0){
            					echangeCase(plat,echange.a, echange.b, echange.c, echange.d);
            					couleur(31)
            					printf("Mouvement Incorect, réessayez\n");
            					couleur(0)
          				}
          				clear();
          				affichage(plat,dim, tour, points);				
          				sleep(1);
          				clear();
          				affichage(plat,dim, tour, points);
        			}while(verifcassage(plat, dim) == 0);
        			//Cassage de 3 (ou plus) symboles avec gravité
		    		do{
          				clear();
				  	cassage(plat,dim,score);
          				affichage(plat,dim, tour, points);
          				sleep(1);
          				clear();
				  	gravite(plat,dim);
          				affichage(plat,dim, tour, points);
			  	}while(verifcassage(plat, dim) == 1 ); //Réaction en chaine si 3 (ou plus) symboles sont alignés
        			tour +=1;
        			printf("Sauvegarder ?(O/N)\n");
        			do{
					check = scanf("%c", &choix);
					buffer(); 
				}while(choix !=79 && choix !=111 && choix !=110 && choix !=78 || check != 1);
				if(choix ==79 || choix ==111){
					sauvegarde(plat,dim, &points, &tour);
					clear();
					CYcrush(plat, dim);
				}
				else{
				clear();
				affichage(plat,dim, tour, points);
				}
		  	}while(testVictoire(plat, dim) == 1); //Vérification de tout le plateau de jeu si des cassages sont possibles
      			compteur_symbole(plat, dim, points, pseudo+taille, &tour);
      			mise_a_jour_score(&points);
      			CYcrush(plat, dim);
			break;
		case 3 :
      			//Affichage du menu d'options
			do{
        			clear();
				dim = option(dim);
			}while(dim.a !=4);
			CYcrush(plat, dim);
			break;
		case 2:
      			//Affichage des règles
      			clear();
			menu();
			regle();
			do{
				check = scanf("%d",&men);
				buffer();
				if(men != 1 || check !=1){
					printf("Erreur de saisie. Veuillez  réessayer.\n");
				}
			}while(men !=1 || check !=1);
			CYcrush(plat, dim);
			break;
		case 4:
      			//Quitte le jeu
			return 0;
			break;
	}
	return 0;
}
