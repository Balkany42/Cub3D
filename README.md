====================================PARSING=====================================

I/	Read la map

1/ 	Ouvrir le fichier CUB3D avec read
2/ 	Lire chaque ligne (simple avec GNL)
3/ 	Stocker la map
4/ 	Ignorer les lignes vides avant la map
5/ 	Interdire les lignes vides / caractères non valides dans la map
6/ 	Fichier introuvable : erreur, mauvaise extension : erreur.
	Attention piège gichier cachés, on a voulu me KO solong pour ça
	espaces / tabulations considérés comme empty

II/	Vérifier que la map est valide
1/	Vérifier qu'on a bien dans l'ordre les textures et chemins correspondants :
		-	NO
		-	SO
		-	WE
		-	EA
		-	Pas plus de directions
		-	Peut être qu'il faut vérifier les chemins de texture ici ?
		-	Doit être séparé de la partie suivante par une ou plusieurs
			lignes vides
2/	Vérifier qu'on a bien dans l'ordre les couleurs et identifiants
	correspondants :
		-	F (range imposée 0, 255, 255) //
		-	C (range imposée 0, 255, 255) //
		-	Pas plus de 2 couleurs
		-	Doit être séparé de la partie suivante par une ou plusieurs
			lignes vides
3/	Vérifier la map (liste non exhaustive)
		-	Vérifier que la map est bien fermée
			(skipspaces and tabs)
		-	Vérifier qu'il y a bien un seul joueur
		-	Flood fill pour vérifier qu'on peut bien aller partout (même que
			so_long a priori) // A priori non en fait
		-	Vérifier les caractère invalides (autres que 0, 1, N, S, E, W)
		-	Sécurité pour les dossiers infinis... On m'a cassé so_long comme ça

		ATTENTION, LA MAP N'EST PAS FORCEMENT UN CARRE OU UN RECTANGLE

		Sujet à interprétation "Except for the map, each type of information
		from an element can be separated by one or more spaces.

=====================================INIT=======================================

1/	Initialisation de la mlx
2/	Chargement des textures (message d'erreur en cas d'erreur)
3/	Création des structures (préparation moteru / raycast)
		-	Joueur (pos, angle)
		-	Carte
		-	Textures
		-	Paramètres de rendu
	// Pour l'instant cette étape je comprend pas grand chose

====================================RAYCASTING==================================

1/	Calcul des rayons
2/	Détection des intersections
3/	Correction du fish eye
4/	Calcul de la distance projetée
5/	Calcul de l'angle du rayon pour chaque colonne
6/	DDA (C'est quoi ?)
7/	Calcul de la distance réelle
8/	Détermination de la hauteur du mur
9/	Détermination de la structure à utiliser

=====================================RENDER=====================================

1/	Grosso modo un render similaire à solong, mais avec prise en compte du
	raycasting de ce que j'ai compris

====================================MOVEMENT====================================

1/	Gestion des touches
2/	Gestion des collisions (BONUS)
3/	Rotation du joueur (on doit être capables de la faire se retourner)
		De ce que j'ai compris, le mandatory c'est seulement avec les touches
		du clavier, et le bonus avec la souris

=====================================BONUS======================================

1/	Des sprites animés (pas plus difficile que solong)
2/	Une minimap (a priori très difficile)
3/	Des collisions avec les murs (semble facile mais si c'est bonus il doit y
	avoir un piège
4/	Des portes qui s'ouvrent et se ferment
5/	Faire la rotation du joueur avec la souris
