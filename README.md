# SouppayaAlban-ProjetInfo-CYCrush-SOUPPAYA-Alban-LANCE-RICHARDOT-Mathis-IZEM-Wissam
Projet CYcrush informatique 2

Pour lancer CYcrush :

Télécharger les fichiers : main.c, CYcrush.c, fonctions.c, fonctions.h, menu.txt, makefile

Les mettre dans un même dossier

Pour compiler, utiliser la commande : make

ATTENTION ! Si les symboles ne marchent pas remplacer fonctions.c par fonctions1.c, puis renommer fonctions1.c en fonctions.c

Présentation:

Notre projet consiste de créer un candy crush avec certaines règles qui ont été choisis au hasard.
-le cassage se fait lorsque 3 ou plus de même symbole sont alignés, il fait en plus de l'horizontal et la vertical, les diagonales;
-on peut déplacer n'importe quelle case du tableau;
-La gravité est vers le bas;
-Le tableau se remplit pas;
Il y a différentes phases lors du candy crush la premieres est la selection des choix du joueur dans les menus puis la seconde est le lancement du jeu et enfin la phase finale

Sélection :

Vous aurez le choix de jouer, de voir les règles, choisir les options de jeu ou encore de sortir du jeu. 
Si le choix est de voir les régles il va afficher une par une les règles et vous propose de revenir au menu quand tout est affiché.
Puis dans options vous aurez accès aux choix  de la dimension du tableau ( par défault est du 9*6) qui va redemander en boucle la saisie si elle est incorrect, il y aura la même chose avec le nombre de symbole et le dernier choix de voir les scores enregister lors d'une victoire des joueurs précedent.
Lorsque vous séléctionez jouez vous aurez encore un choix soit créer une nouvelle partie ou générer la partie qui aura été sauvegardée et si vous séléctionnez une sauvegarde inexitantes cela va quitter le jeu automatiquement (il y aura qu'une sauvegarde disponible s'il y en a une).
Si la nouvelle partie est créée il te demandera ton pseudo et démarre la partie.


Phase de jeu:

Le tableau s'affiche avec des smileys ou des nombres de couleur et qui affiche le tour auquel on est et le score du joueur.
Après il demande à l'utilisateur les cases qu'il souhaite déplacer et si aucun cassage est réalisez, il lui redemande la saisie.
Si la saisie est correct il demandera si vous voulais sauvegarder la partie, si oui ça vous fera revenir à la phase de sélection et vous pourrez générer cette sauvegarde.
Mais si vous créez une nouvelle partie et la sauvegardez l'ancienne sera effacé.
Si vous choissiez non la partie continue avec la mise a jour du tableau après que le cassage et que la gravité sois effectuer.
Cela se répéte jusqu'à ce que le joueur ne puisse faire aucun mouvement. 

Phase finale :

Quand plus aucun mouvement est possible le programme va afficher le score du joueur et dire s'il a gagné ou non en vérifiant le nombre de symbole sur le plateau s'il est nombre de symbole est supérieur à 2 il aura perdu sinon il gagne.
Il va sauvegarder automatiquement son nombre de tours et met son pseudo (mais ne le fait pas) lorsqu'il gagne et aujoute son score au fichier des scores des précédent joueurs.
Bug connu:

-Sur certains replit le programme ne se lance pas 
-Si tu sauvegarde et tu gagnes ou perds la partie ça affiche deux fois la phrase avec le score sauvegarder et une autre avec le score final
-Pseudo apparait pas dans le fichier de sauvegarde de victoire


Bugs connu :

-Affichage des scores dans le menu score

-Double affichage du score à la fin d'une partie si une partie est sauvegardé au préalable

-Pseudo non affiché dans le fichier de sauvegarde

-En cas d'échange de case, s'il y a un combo de 2 combinaisons ou plus sur une même case seulement un se lancera en fonction de cet ordre (Ligne, Colone, Diagonale haut-bas, Diagonale bas-haut)

-De manière aléatoire le plateau ne s'affiche pas parfois (Le plus souvent sur Replit)

