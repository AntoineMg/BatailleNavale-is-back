#pragma once
#include "PrjInfo2022.h"



//fonction qui initialise toutes les cases de la mer a 0
void initCases(int f_int_mer) {
	//initialisation de toutes les cases a 0
	for (iBcl1 = 0; iBcl1 < LIGNES; iBcl1++) {
		for (iBcl2 = 0; iBcl2 < COLONNES; iBcl2++) {
			l_enrTab_Mer[f_int_mer][iBcl1][iBcl2].m_int_bateau = 0;
			l_enrTab_Mer[f_int_mer][iBcl1][iBcl2].m_bool_touche = 0;
		}
	}
}

// affichage du logo 
void logo(void) {
	Sleep(250);
	Color(3);
	printf("\t\t\t\t\toooooooooo.                .               o8o  oooo  oooo                 ooooo      ooo                                 oooo            \n");
	printf("\t\t\t\t\t`888'   `Y8b             .o8                    `888  `888                 `888b.     `8'                                 `888            \n");
	printf("\t\t\t\t\t 888     888  .oooo.   .o888oo  .oooo.    oooo   888   888   .ooooo.        8 `88b.    8   .oooo.   oooo   oooo  .oooo.    888   .ooooo.  \n");
	printf("\t\t\t\t\t 888oooo888' `P  )88b    888   `P  )88b    888   888   888  d88' `88b       8   `88b.  8  `P  )88b   `88.  .8'  `P  )88b   888  d88' `88b \n");
	printf("\t\t\t\t\t 888    `88b  .oP8888    888    .oP8888    888   888   888  8888888888      8     P888 8   .oP8888    `888        oP8888   888  888ooo888 \n");
	printf("\t\t\t\t\t 888    .88P d8(  888    888 . d8(  888    888   888   888  888    __       8       `888  d8(  888     `888'    d8(  888   888  888    .o \n");
	printf("\t\t\t\t\t o888bood8P'  `Y888888o   888    Y8888o   o888o o888o o888o `Y8bod8P'      o8o        `8  `Y8888888     `8'     `Y888888o o888o `Y8bod8P' \n");
	printf("\t\t\t\t\t\t                  __/___                                               __\___                                      \n");
	printf("\t\t\t\t\t\t           _____ /______|                                             |______\______                               \n");
	printf("\t\t\t\t\t\t  _______ / _____\_______\_____                                 _____/_______/_____ \ _______                      \n");
	printf("\t\t\t\t\t\t  \              < < <       |                                   |    > > >                 /                      \n");
	printf("\t\t\t\t\t\t  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~                         ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~                    \n\n\n");
	printf("\t\t\t\t\t\t		Created by :    Antoine Morier-Genoud      and       Thomas Guillerme\n\n\n\n");

	Sleep(1500);
}

//Ecrqn de chargement
void load(void) {
	printf("\t\t\t\t\t\tChargement [");
	for (iBcl = 0; iBcl < TAILLE_LOAD; iBcl++) {
		Sleep(TEMPS2);
		printf("|");
	}
	printf("]");
	Sleep(800);
	system("CLS");
}

//Mode Plein ecran
void Fscreen(void) {
	keybd_event(VK_MENU, 0x38, 0, 0); //Appuie sur ALT
	keybd_event(VK_RETURN, 0x1c, 0, 0); //Appuie ENTREE
	keybd_event(VK_RETURN, 0x1c, KEYEVENTF_KEYUP, 0); // Relache ENTREE
	keybd_event(VK_MENU, 0x38, KEYEVENTF_KEYUP, 0); //Relache ALT
}

//DEBUG
void afficheMerDebug(int f_int_player) {
	//affichage de la ligne d'en tete en couleur1
	Color(COLOR_1);
	printf("   1 2 3 4 5 6\n");
	Color(COLOR_2);

	//boucle for pour afficher les lignes en couleur 2 ainsi que l'en tete de chaque ligne en couleur 1
	for (iBcl1 = 0; iBcl1 < LIGNES; iBcl1++) {
		Color(COLOR_1);
		printf("%c  ", iBcl1 + 65);
		Color(COLOR_2);
		//boucle for pour afficher les colonnes
		for (iBcl2 = 0; iBcl2 < COLONNES; iBcl2++) {
			printf("%i ", l_enrTab_Mer[f_int_player][iBcl1][iBcl2].m_int_bateau);
		}
		//retour a la ligne pour rendre le resultat plus clean
		printf("\n");
		Color(COLOR_1);
	}
}

//fonction pour afficher une mer
void afficheMer(int f_int_mer) {
	//affichage de la ligne d'en tete en couleur1
	Color(BACKGROUND_RED | COLOR_1);
	printf("=== JOUEUR %i ===\n", f_int_mer);
	Color(COLOR_1);
	printf("    1 2 3 4 5 6\n");
	Color(COLOR_2);

	//boucle for pour afficher les lignes en couleur 2 ainsi que l'en tete de chaque ligne en couleur 1
	for (iBcl1 = 0; iBcl1 < LIGNES; iBcl1++) {
		Color(COLOR_1);
		printf(" %c  ", iBcl1 + 65);
		Color(COLOR_2 | BACKGROUND_BLUE);
		//boucle for pour afficher les colonnes
		for (iBcl2 = 0; iBcl2 < COLONNES; iBcl2++) {
			if (l_enrTab_Mer[f_int_mer][iBcl1][iBcl2].m_bool_touche == 1) {
				printf("X ");
			}
			else {
				printf("~ ");
			}
		}
		//retour a la ligne pour rendre le resultat plus clean
		printf("\n");
		Color(COLOR_1);
	}
}

//fonction pour placer les bateaux automatiquement
void placeBateau(int f_int_mer) {

	//init aleatoire
	srand(time(NULL));

	//boucle pour generer un certain nombre de bateau
	for (iBcl1 = 0; iBcl1 < N_BATEAUX; iBcl1++) {

		//determination aleatoire de la direction du bateau
		l_bool_direction = rand() % 2;
		l_bool_bateauxPlaces = 0;

		//execution fonction placement si bateau vertical
		if (l_bool_direction == 0) {

			//replace le bateau tant que celui-ci n'est pas dans une case libre
			do {

				//determination aleatoire de la premiere case du bateau
				l_int_ligne = rand() % 4;
				l_int_colonne = rand() % 6;

				//Si la case choisie aleatoirement et les 2 suivantes verticales sont libres, alors on place le bateau
				if ((l_enrTab_Mer[f_int_mer][l_int_ligne][l_int_colonne].m_int_bateau == 0) && (l_enrTab_Mer[f_int_mer][l_int_ligne + 1][l_int_colonne].m_int_bateau == 0) && (l_enrTab_Mer[f_int_mer][l_int_ligne + 2][l_int_colonne].m_int_bateau == 0)) {
					//ajout du bateau dans la mer
					l_enrTab_Mer[f_int_mer][l_int_ligne][l_int_colonne].m_int_bateau = 1;
					l_enrTab_Mer[f_int_mer][l_int_ligne + 1][l_int_colonne].m_int_bateau = 1;
					l_enrTab_Mer[f_int_mer][l_int_ligne + 2][l_int_colonne].m_int_bateau = 1;
					//stockage du bateau
					l_enr_Bateaux[iBcl1].m_TCoord_Case1.m_int_colonne = l_int_colonne;
					l_enr_Bateaux[iBcl1].m_TCoord_Case1.m_int_ligne = l_int_ligne;
					l_enr_Bateaux[iBcl1].m_TCoord_Case2.m_int_colonne = l_int_colonne;
					l_enr_Bateaux[iBcl1].m_TCoord_Case2.m_int_ligne = l_int_ligne+1;
					l_enr_Bateaux[iBcl1].m_TCoord_Case3.m_int_colonne = l_int_colonne;
					l_enr_Bateaux[iBcl1].m_TCoord_Case3.m_int_ligne = l_int_ligne+2;
					//confirmation que le bateau est place
					l_bool_bateauxPlaces = 1;
				}
			} while (l_bool_bateauxPlaces == 0);

		}

		//execution fonction placement si bateau horizontal
		else {

			do {
				//determination aleatoire de la premiere case du bateau
				l_int_ligne = rand() % 6;
				l_int_colonne = rand() % 4;

				//Si la case choisie aleatoirement et les 2 suivantes horizontales sont libres, alors on place le bateau
				if ((l_enrTab_Mer[f_int_mer][l_int_ligne][l_int_colonne].m_int_bateau == 0) && (l_enrTab_Mer[f_int_mer][l_int_ligne][l_int_colonne + 1].m_int_bateau == 0) && (l_enrTab_Mer[f_int_mer][l_int_ligne][l_int_colonne + 2].m_int_bateau == 0)) {
					//ajout du bateau dans la mer
					l_enrTab_Mer[f_int_mer][l_int_ligne][l_int_colonne].m_int_bateau = 1;
					l_enrTab_Mer[f_int_mer][l_int_ligne][l_int_colonne + 1].m_int_bateau = 1;
					l_enrTab_Mer[f_int_mer][l_int_ligne][l_int_colonne + 2].m_int_bateau = 1;
					//Stockage du bateau
					l_enr_Bateaux[iBcl1].m_TCoord_Case1.m_int_colonne = l_int_colonne;
					l_enr_Bateaux[iBcl1].m_TCoord_Case1.m_int_ligne = l_int_ligne;
					l_enr_Bateaux[iBcl1].m_TCoord_Case2.m_int_colonne = l_int_colonne+1;
					l_enr_Bateaux[iBcl1].m_TCoord_Case2.m_int_ligne = l_int_ligne;
					l_enr_Bateaux[iBcl1].m_TCoord_Case3.m_int_colonne = l_int_colonne+2;
					l_enr_Bateaux[iBcl1].m_TCoord_Case3.m_int_ligne = l_int_ligne;
					//confirmation que le bateau est place
					l_bool_bateauxPlaces = 1;
				}
			} while (l_bool_bateauxPlaces == 0);
		}
	}
}

//fonction pour que les joueurs placent les bateaux
//FONCTIONNE PAS = TROP DE BUGS
void placeBateauJoueur(int f_int_mer) {

	//init aleatoire
	srand(time(NULL));

	//boucle pour generer un certain nombre de bateau
	for (iBcl1 = 0; iBcl1 < N_BATEAUX; iBcl1++) {

		//demande user de la direction du bateau
		do {
			printf("\nJoueur %i Saisir la direction (v ou h) : ",f_int_mer);
			l_int_direction = _getch();
			printf("%i", l_int_direction);
		} while ((l_int_direction != 118) && (l_int_direction != 112));

		//transformation en bool
		if (l_int_direction == 118) {
			l_bool_direction = 0;
		}
		if (l_int_direction == 112) {
			l_bool_direction = 1;
		}

		//reset var
		l_bool_bateauxPlaces = 0;

		//execution fonction placement si bateau vertical
		if (l_bool_direction == 0) {

			//replace le bateau tant que celui-ci n'est pas dans une case libre
			do {
				//determination aleatoire de la premiere case du bateau
				printf("\nJoueur %i, Saisir la ligne : ", f_int_mer);
				l_int_coordY = _getch();
				printf("\nJoueur %i Saisir la colonne : ", f_int_mer);
				scanf_s("%i", &l_int_coordX);

				//Si la case choisie aleatoirement et les 2 suivantes verticales sont libres, alors on place le bateau
				if ((l_enrTab_Mer[f_int_mer][l_int_ligne][l_int_colonne].m_int_bateau == 0) && (l_enrTab_Mer[f_int_mer][l_int_ligne + 1][l_int_colonne].m_int_bateau == 0) && (l_enrTab_Mer[f_int_mer][l_int_ligne + 2][l_int_colonne].m_int_bateau == 0)) {
					//ajout du bateau dans la mer
					l_enrTab_Mer[f_int_mer][l_int_ligne][l_int_colonne].m_int_bateau = 1;
					l_enrTab_Mer[f_int_mer][l_int_ligne + 1][l_int_colonne].m_int_bateau = 1;
					l_enrTab_Mer[f_int_mer][l_int_ligne + 2][l_int_colonne].m_int_bateau = 1;
					//stockage du bateau
					l_enr_Bateaux[iBcl1].m_TCoord_Case1.m_int_colonne = l_int_colonne;
					l_enr_Bateaux[iBcl1].m_TCoord_Case1.m_int_ligne = l_int_ligne;
					l_enr_Bateaux[iBcl1].m_TCoord_Case2.m_int_colonne = l_int_colonne;
					l_enr_Bateaux[iBcl1].m_TCoord_Case2.m_int_ligne = l_int_ligne + 1;
					l_enr_Bateaux[iBcl1].m_TCoord_Case3.m_int_colonne = l_int_colonne;
					l_enr_Bateaux[iBcl1].m_TCoord_Case3.m_int_ligne = l_int_ligne + 2;
					//confirmation que le bateau est place
					l_bool_bateauxPlaces = 1;
				}
			} while (l_bool_bateauxPlaces == 0);

		}

		//execution fonction placement si bateau horizontal
		else {

			do {
				//determination aleatoire de la premiere case du bateau
				l_int_ligne = rand() % 6;
				l_int_colonne = rand() % 4;

				//Si la case choisie aleatoirement et les 2 suivantes horizontales sont libres, alors on place le bateau
				if ((l_enrTab_Mer[f_int_mer][l_int_ligne][l_int_colonne].m_int_bateau == 0) && (l_enrTab_Mer[f_int_mer][l_int_ligne][l_int_colonne + 1].m_int_bateau == 0) && (l_enrTab_Mer[f_int_mer][l_int_ligne][l_int_colonne + 2].m_int_bateau == 0)) {
					//ajout du bateau dans la mer
					l_enrTab_Mer[f_int_mer][l_int_ligne][l_int_colonne].m_int_bateau = 1;
					l_enrTab_Mer[f_int_mer][l_int_ligne][l_int_colonne + 1].m_int_bateau = 1;
					l_enrTab_Mer[f_int_mer][l_int_ligne][l_int_colonne + 2].m_int_bateau = 1;
					//Stockage du bateau
					l_enr_Bateaux[iBcl1].m_TCoord_Case1.m_int_colonne = l_int_colonne;
					l_enr_Bateaux[iBcl1].m_TCoord_Case1.m_int_ligne = l_int_ligne;
					l_enr_Bateaux[iBcl1].m_TCoord_Case2.m_int_colonne = l_int_colonne + 1;
					l_enr_Bateaux[iBcl1].m_TCoord_Case2.m_int_ligne = l_int_ligne;
					l_enr_Bateaux[iBcl1].m_TCoord_Case3.m_int_colonne = l_int_colonne + 2;
					l_enr_Bateaux[iBcl1].m_TCoord_Case3.m_int_ligne = l_int_ligne;
					//confirmation que le bateau est place
					l_bool_bateauxPlaces = 1;
				}
			} while (l_bool_bateauxPlaces == 0);
		}
	}
}

//fonction pour verifie si il y a un bateau coule dans une mer
//fonctionne parfsois ex pour E456 et pour CDE4 et pour A234
void checkCoule(int f_int_mer) {
	l_int_coules[f_int_mer] = 0;
	for (iBcl1 = 0; iBcl1 < N_BATEAUX; iBcl1++) {
		if ((l_enrTab_Mer[f_int_mer][l_enr_Bateaux[iBcl1].m_TCoord_Case1.m_int_ligne][l_enr_Bateaux[iBcl1].m_TCoord_Case1.m_int_colonne].m_bool_touche == 1) && (l_enrTab_Mer[f_int_mer][l_enr_Bateaux[iBcl1].m_TCoord_Case2.m_int_ligne][l_enr_Bateaux[iBcl1].m_TCoord_Case2.m_int_colonne].m_bool_touche == 1) && (l_enrTab_Mer[f_int_mer][l_enr_Bateaux[iBcl1].m_TCoord_Case3.m_int_ligne][l_enr_Bateaux[iBcl1].m_TCoord_Case3.m_int_colonne].m_bool_touche == 1)) {
			l_boolTab_Coules[f_int_mer][iBcl] = 1;
		}
	}
	for (iBcl2 = 0; iBcl2 < N_BATEAUX; iBcl2++) {
		if (l_boolTab_Coules[f_int_mer][iBcl2] == 1) {
			l_int_coules[f_int_mer]++;
		}
	}
}

//fonction qui demande une case au joueur et qui la retourne au format TCoord
TCoord demandeJoueur(void) {
	//declarations
	TCoord l_enr_case;

	//demande de saisie utilisateur tant que il n a pas saisi de valeur correcte (ex : A5 / D2 / C4 / ... )
	do {
		printf("Saisir la ligne : \n");
		l_int_coordY = _getch();
		//scanf_s("%c", &l_int_coordY);
	} while (int((l_int_coordY) < 97) || (int(l_int_coordY) > 102));

	do {
		printf("\nSaisir la colonne : ");
		scanf_s("%i", &l_int_coordX);
	} while ((l_int_coordX < 1) || (l_int_coordX > 6));

	//assignation des valeurs saisies a l_enr case
	//-1 car decalage index
	l_enr_case.m_int_ligne = l_int_coordY - 97;
	l_enr_case.m_int_colonne = l_int_coordX - 1;

	//retourne l_enr_case sous forme de Tcoord
	return(l_enr_case);
}

//Verifie si un bateau etait present dans la case selectionne
bool checkCase(TCoord l_enr_essai,int f_int_mer) {
	if (l_enrTab_Mer[f_int_mer][l_enr_essai.m_int_ligne][l_enr_essai.m_int_colonne].m_int_bateau == 1) {
		//printf("Touche\n");
		l_enrTab_Mer[f_int_mer][l_enr_essai.m_int_ligne][l_enr_essai.m_int_colonne].m_bool_touche = 1;
		l_int_points[f_int_mer]+=1;
		l_int_tentatives+=1;
		return(1);
	}
	else {
		//printf("Loupe\n");
		l_int_tentatives++;
		return(0);
	}
}

//Affiche les règles
void regles(void) {
	printf("********* Bienvenue! *********\n");
	Sleep(500);
	printf("Connaissez vous les regles ? \n");
	Sleep(500);
	printf("Oui = o \nNon = n\n\n");
	l_char_regles = _getch();
	system("CLS");
	if (l_char_regles == 'n') {
		printf("Bah voir sur google\n");
	}
	else {
		printf("Super, alors allons-y !\n");
	}
	Sleep(1000);
	system("CLS");
}

//Fonction qui demande a l'utilisateur combien de joueurs veulent jouer et qui retourne le nombre de joueurs
int nombreJoueurs(void) {
	printf("Combien de joueurs ? \n");
	scanf_s("%i", &l_int_nbJoueurs);
	system("CLS");
	return(l_int_nbJoueurs);
}

//Fonction qui demarre une partie en mode solo
void playSolo(void) {
	system("CLS");
	l_int_player = 0;
	//placement des bateaux
	placeBateau(l_int_player);
	afficheMer(l_int_player);
	Sleep(3000);

	//Debut du chrono
	l_int_timeDebut = GetTickCount();

	//Tant que le joueur n'a pas gagne le jeu continue
	while (l_int_points[l_int_player] < N_BATEAUX * 3) {
		TCoord l_enr_saisie = demandeJoueur();
		//Si le bateau est touche on affiche touche ou coule
		if (checkCase(l_enr_saisie, l_int_player)) {
			//si le bateau est coule on affiche coule
			checkCoule(0);
			if (l_int_coules[l_int_player] > l_int_coulesAns[l_int_player]) {
				l_int_coulesAns[l_int_player] = l_int_coules[l_int_player];
				system("CLS");
				afficheMer(l_int_player);
				printf("Coule !\n");
				printf("%i points\n", l_int_points[l_int_player]);
			}

			//Si non on affiche seulement touche
			else {
				system("CLS");
				afficheMer(l_int_player);
				printf("Touche !\n");
				printf("%i points\n", l_int_points[l_int_player]);
			}
		}

		//Si non on affiche Rate
		else {
			system("CLS");
			afficheMer(l_int_player);
			printf("Rate !\n");
			printf("%i points\n", l_int_points[l_int_player]);
		}


	}
}

//Fonction qui demarre une partie en mode 2 joueurs
void playDuo(void) {
	//placement des bateaux des deux joueurs
	//placeBateauJoueur(1);
	//placeBateauJoueur(2);
	placeBateau(1);
	placeBateau(2);

	//Debut du chrono
	l_int_timeDebut = GetTickCount();

	//
	while (l_bool_win == 0) {
		//DETERMINATION DU JOUEUR A QUI CEST LE TOUR
		//si le tour est pair, c'est au joueur 1 de jouer 
		if (l_int_tour % 2 == 0) {
			l_int_player = 1;
		}
		//Si non c'est au tour du joueur 2
		else {
			l_int_player = 2;
		}

		//Annonce du joueur qui doit jouer
		printf("C'est au joueur %i de jouer\n",l_int_player);
		//Demande de saisie
		TCoord l_enr_saisie = demandeJoueur();

		if (checkCase(l_enr_saisie,l_int_player)) {
			//si le bateau est coule on affiche coule
			checkCoule(l_int_player);
			if (l_int_coules > l_int_coulesAns) {
				l_int_coulesAns[l_int_player] = l_int_coules[l_int_player];
				system("CLS");
				afficheMer(1);
				printf("Coule !\n");
				printf("%i points\n", l_int_points[l_int_player]);
			}

			//Si non on affiche seulement touche
			else {
				system("CLS");
				afficheMer(l_int_player);
				printf("Touche !\n");
				printf("%i points\n", l_int_points[l_int_player]);
			}
		}

		//Si non on affiche Rate
		else {
			system("CLS");
			afficheMer(l_int_player);
			printf("Rate !\n");
			printf("%i points\n", l_int_points[l_int_player]);
		}

		l_int_tour++;

		
	}

}








