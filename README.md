# SouppayaAlban-ProjetInfo-CYCrush-SOUPPAYA-Alban-LANCE-RICHARDOT-Mathis-IZEM-Wissam
Projet CYcrush informatique 2

Pour lancer CYcrush :

Télécharger les fichiers : main.c, CYcrush.c, fonctions.c, fonctions.h, menu.txt, makefile

Les mettre dans un même dossier

Pour compiler, utiliser la commande "make" dans le terminal

ATTENTION ! Si les symboles ne marchent pas remplacer fonctions.c par fonctions1.c, puis renommer fonctions1.c en fonctions.c



Présentation:

Notre projet consiste à créer un candy crush avec certaines règles qui ont été choisies au hasard. Les règles étant :

-Cassage lorsque 3 cases ou plus de même symbole sont alignés, il fait en plus de l'horizontal et la vertical, les diagonales;

-Déplacement avec n'importe quel case du tableau;

-Gravité vers le bas;

-Tableau qui ne se remplit pas;

Il y a différentes phases lors du candy crush la premiere est la selection des choix du joueur dans les menus puis la seconde est le lancement du jeu et enfin la phase finale



Sélection :

Vous aurez le choix entre jouer, voir les règles, choisir les options de jeu ou encore de sortir du jeu. 
Si le choix est de voir les régles il va afficher une par une les règles et vous proposer de revenir au menu quand tout sera affiché.
Puis dans options vous aurez accès aux choix  de la dimension du tableau ( par défault 9*6) qui va redemander en boucle la saisie si elle est incorrecte, il y aura la même chose avec le nombre de symboles et le dernier choix est de voir les scores enregistés lors d'une victoire des joueurs précedent.
Lorsque vous séléctionez "jouez" vous aurez encore un choix, soit créer une nouvelle partie ou générer la partie qui a été sauvegardée préalablement, si vous séléctionnez une sauvegarde inexitante cela va quitter le jeu automatiquement (il n'y a qu'une sauvegarde disponible s'il y en a une).
Si la nouvelle partie est créée le jeu te demandera ton pseudo et démarrera la partie.




Phase de jeu:

Le tableau affiche des smileys ou des nombres en couleur, il affichera aussi le tour auquel l'utilisateur est et son score.
Après le jeu demandera à l'utilisateur les cases qu'il souhaite déplacer et si aucun cassage est réalisé, il lui redemandera la saisie.
Si la saisie est correcte il demandera si vous voulez sauvegarder la partie, si oui cela vous fera revenir à la phase de sélection et vous pourrez générer cette sauvegarde.
Mais si vous créez une nouvelle partie et la sauvegardez l'ancienne sera effacée.
Si vous choisissez non, la partie continuera avec la mise a jour du tableau après que le cassage et que la gravité soient effectués.
Cela se répéte jusqu'à ce que le joueur ne puisse plus faire de mouvement. 




Phase finale :

Quand plus aucun mouvement n'est possible le programme va afficher le score du joueur et dire s'il a gagné ou non en vérifiant le nombre de symbole dans le plateau, si le nombre de symbole est supérieur à 2 il aura perdu sinon, il aura gagné.
Il va sauvegarder automatiquement son nombre de tours et mettra son pseudo (mais ne le fait pas) lorsqu'il gagne et ajoutera son score au fichier des scores des précédent joueurs.



Bugs connu :

-Affichage des scores dans le menu score non fonctionnel

-Double affichage du score à la fin d'une partie si une partie est sauvegardé au préalable

-Pseudo non affiché dans le fichier de sauvegarde

-En cas d'échange de case, s'il y a un combo de 2 combinaisons ou plus sur une même case seulement un se lancera en fonction de cet ordre (Ligne, Colone, Diagonale haut-bas, Diagonale bas-haut)

-De manière aléatoire le plateau ne s'affiche pas parfois (Le plus souvent sur Replit)

-Si dans les scanfs deux caractères sont saisies le programme risque de mal fonctionner
