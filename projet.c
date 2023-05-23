//\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\//   
// ██████╗██╗   ██╗ ██████╗██████╗ ██╗   ██╗███████╗██╗  ██╗//
//██╔════╝╚██╗ ██╔╝██╔════╝██╔══██╗██║   ██║██╔════╝██║  ██║//
//██║      ╚████╔╝ ██║     ██████╔╝██║   ██║███████╗███████║//
//██║       ╚██╔╝  ██║     ██╔══██╗██║   ██║╚════██║██╔══██║//
//╚██████╗   ██║   ╚██████╗██║  ██║╚██████╔╝███████║██║  ██║//
// ╚═════╝   ╚═╝    ╚═════╝╚═╝  ╚═╝ ╚═════╝ ╚══════╝╚═╝  ╚═╝//
//\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\//
                                                    
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

typedef struct{
	int d1;
	int d2;
	int nb_s;
	int a;
	int b;
	int c;
	int d;
}choix;

void buffer(){
	while( getchar() != '\n');
}

int menu(){
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
}

void regle(){
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

choix option(choix dim){
	int check1, check2;
	dim.a = 0;
	menu();
     printf("                          1.Dimensions\n                          2.Nombre de symboles\n                          3.Retour\n");
	do{
     	scanf("%d", &dim.a);
     }while(dim.a<1 || dim.a>3);
     	switch(dim.a){
         		case 1 :
            		do{
        				printf("Quel nombre de ligne veux-tu ? (Minimum 3 sinon c'est pas drole ;-;)\n");
        				check1 = scanf( "%d" , &dim.d1);
        				buffer();
        				printf("Quel nombre de colone veux-tu ? (Minimum 3 aussi sinon c'est encore moins drôle ;-;)\n");
        				check2 = scanf( "%d" , &dim.d2);
        				buffer();
            			if(dim.d2<3 || dim.d1<3|| check1 != 1 || check2 !=1){
         					printf("Erreur de saisie. Veuillez  réessayer.\n");
        				}
    				}while(dim.d2<3 || dim.d1<3 || check1 != 1);
    				return dim;
    			break;
    			case 2 :
    				do{
    					printf("Combien de symboles veux-tu ? (Max 6)\n");
        				check1 = scanf( "%d" , &dim.nb_s);
        				buffer();
        				if(dim.d2<3 || dim.d1<3 || check1 != 1){
         					printf("Erreur de saisie. Veuillez  réessayer.\n");
        				}
        			}while(dim.nb_s<0 || dim.nb_s>7 || check1 != 1);
        			return dim;
        		break;
    			case 3 : 	
    				return dim;
            	break;
            }
}
	

void gravite(int **plat, choix dim){

}

int** construct_plat(choix dim){ //Construction du plateau de jeu
	int i, j;
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
	for(i=0; i<dim.d1; i++){
		for(j=0; j<dim.d2; j++){
			if(j<2 && i>2){
				do{
					plat[i][j]=rand()%dim.nb_s+1; 
				}while(plat[i][j]==plat[i-1][j] && plat[i-2][j]);
			}
			if(j>2 && i<2){
				do{
					plat[i][j]=rand()%dim.nb_s+1; 
				}while(plat[i][j]==plat[i][j-1] && plat[i][j-2]);
			}
			if(i>=2 && j>=2){
				do{
					plat[i][j]=rand()%dim.nb_s+1; 
				}while(plat[i][j]==plat[i-1][j] && plat[i-2][j] || plat[i][j]==plat[i][j-2] && plat[i][j]==plat[i][j-1] || plat[i][j]==plat[i-1][j-1] && plat[i-2][j-2] || plat[i][j]==plat[i-1][j+1] && plat[i-2][j+2]);
			}
		}
	}
	return plat;
}

void affichage(int **plat, choix dim){
	int i, j;
	printf("   ");
	for(i=0; i<dim.d2; i++){
		printf(" %c ",'A'+i);
	}
	printf("\n   ");
	for(i=0; i<dim.d2; i++){
		printf("-- ");
	}
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
					printf("  ");
					break;
				case 1 :
					printf("\U0001F351 ");
					break;
				case 2 :
					printf("\U0001F352 ");
					break;
				case 3 :
					printf("\U0001F346 ");
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

choix move(int **plat, choix case1){
	char a, c;
	int b, d, temp, check1, check2;
	do{
		printf("Quel case voulez vous déplacer ? \n Colone :");
		check1 = scanf("%c", &a);
		buffer();
		printf(" Ligne :");
		check2 = scanf("%d", &b);
		buffer();
		if(a<65 || a>=65+case1.d2 || b<1 || b>case1.d1 || check1 != 1 || check2 !=1){
			printf("Erreur de saisie. Veuillez  réessayer.\n");
		}
	}while(a<65 || a>=65+case1.d2 || b<1 || b>case1.d1 || check1 != 1 || check2 !=1);
	do{
		printf("Avec laquelle ? \n Colonne :");
		check1 = scanf("%c", &c);
		buffer();
		printf(" Ligne :");
		check2 = scanf("%d", &d);
		buffer();
		if(c<65 || c>=65+case1.d2 || d<1 || d>case1.d1 || check1 != 1 || check2 !=1){
			printf("Erreur de saisie. Veuillez  réessayer.\n");
		}
	}while(c<65 || c>=65+case1.d2 || d<1 || d>case1.d1 || check1 != 1 || check2 !=1);
	case1.a = a-65;
	case1.b = b-1;
	case1.c = c-65;
	case1.d = d-1;
	temp = plat[case1.b][case1.a];
	plat[case1.b][case1.a ] = plat[case1.d][case1.c];
	plat[case1.d][case1.c] = temp;
	return case1;
}

int CYcrush(choix a, choix b, int** c){
	int men;
	int check;
	menu();
	printf("                          1.Jouer\n                          2.Règles\n                          3.Options\n                          4.Quitter\n");
	do{
		check = scanf("%d", &men);
		buffer();
	}while(men < 1 || men > 4 || check !=1);
	printf("\n");
	switch(men){
		case 1:
			c = construct_plat(a);
			affichage(c,a);
			b= move(c, a);
			affichage(c,a);
			break;
		case 3 :
			do{
				a = option(a);
			}while(a.a !=3);
			CYcrush(a, b, c);
			break;
		case 2:
			regle();
			do{
				check = scanf("%d",&men);
				buffer();
				if(men != 1 || check !=1){
					printf("Erreur de saisie. Veuillez  réessayer.\n");
				}
			}while(men !=1 || check !=1);
			CYcrush(a, b, c);
			break;
		case 4:
			return 0;
			break;
	}
	return 0;
}

int main(){
	srand(time(NULL));
	choix a,b;
	a.d1=5;
	a.d2=5;
	a.nb_s=4;
	int **c;
	CYcrush(a, b, c);
	return 0;
}
