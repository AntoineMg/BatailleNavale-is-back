# projetBatailleNavale
!!! ATTENTION IMPORTANT !!!
Afin de lancer le programme correctement, déplacez le contenu du dossier assets, dans le dossier parent.

==========FONCTIONS DOC==================

	void initCases(void)
		initialise toutes les cases de la mer a 0


	void afficheMer(void)
		affiche la mer en couleur1 sous forme d'une grille de 6*6
		affiche les legendes au dessus et a gauche en couleur2

	void placeBateau(void)
		Place N_BATEAUX fois un bateau
			determine un nbre aleatoire entre 0 et 1
				si 0 alors bateau vertical		
				si 1 alors bateau horizontal
			determine les coordonnees de la premiere case du bateau
			verifie si il ne chevauche pas dautre bateau, sinon il recommence
			place le bateau dans le tableau
		
	TCoord demandeJoueur(void)
		Demande une saisie au joueur
		Renvoie sous forme de Tcoord

	
