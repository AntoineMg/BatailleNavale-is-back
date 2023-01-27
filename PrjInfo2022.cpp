#include "PrjInfo2022.h"
#include "main.cpp"


void Color(WORD x_word_attributes) {    // fonction d'affichage de couleurs
	HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(H, x_word_attributes);
}

void InitJeu32(TCarte x_enrTab_Carte32[], int m_int_taille) {
	int iBcl;
	for (iBcl = 0; iBcl<8; iBcl++) {
		x_enrTab_Carte32[iBcl].m_char_couleur = 'H';
		x_enrTab_Carte32[iBcl + 8].m_char_couleur = 'C';
		x_enrTab_Carte32[iBcl + 16].m_char_couleur = 'P';
		x_enrTab_Carte32[iBcl + 24].m_char_couleur = 'T';
		x_enrTab_Carte32[iBcl].m_int_valeur = iBcl + 7;
		x_enrTab_Carte32[iBcl + 8].m_int_valeur = iBcl + 7;
		x_enrTab_Carte32[iBcl + 16].m_int_valeur = iBcl + 7;
		x_enrTab_Carte32[iBcl + 24].m_int_valeur = iBcl + 7;
	}
	x_enrTab_Carte32[7].m_int_valeur = 1;
	x_enrTab_Carte32[15].m_int_valeur = 1;
	x_enrTab_Carte32[23].m_int_valeur = 1;
	x_enrTab_Carte32[31].m_int_valeur = 1;
}

void ChoisirInstrument(int x_int_channel, int x_int_numInstrument, HMIDIOUT x_hMidiOut_obj){
	midiOutShortMsg(x_hMidiOut_obj,x_int_channel | 0xC0 | (x_int_numInstrument << 8));
}

void JouerNote(int x_int_channel, int x_int_note, int x_int_force, HMIDIOUT x_hMidiOut_obj){
	midiOutShortMsg(x_hMidiOut_obj, x_int_channel | 0x90 | (x_int_note << 8) | (x_int_force << 16));
}

void ArreterNote(int x_int_Channel, int x_int_note, HMIDIOUT x_hMidiOut_obj) {
	midiOutShortMsg(x_hMidiOut_obj, x_int_Channel | 0x80 | (x_int_note << 8));
}

void JouerSonBaR(int x_int_code, HMIDIOUT x_hMidiOut_obj, int x_int_volume) {
	ChoisirInstrument(1, x_int_code,x_hMidiOut_obj);
	JouerNote(1, 53, x_int_volume, x_hMidiOut_obj);
}

void JouerSonJeu(int x_int_note, HMIDIOUT x_hMidiOut_obj, int x_int_volume) {
	ChoisirInstrument(1, 1, x_hMidiOut_obj);
	JouerNote(1, x_int_note, x_int_volume, x_hMidiOut_obj);
}

void InitTabMusic(TExtraitSonore x_enrTab_songInit[], int x_int_taille) {
	x_enrTab_songInit[0].m_string_nomFichier = ("Song0.wav");
	x_enrTab_songInit[1].m_string_nomFichier = ("Song1.wav");
	x_enrTab_songInit[2].m_string_nomFichier = ("Song2.wav");
	x_enrTab_songInit[3].m_string_nomFichier = ("Song3.wav");
	x_enrTab_songInit[4].m_string_nomFichier = ("Song4.wav");
	x_enrTab_songInit[5].m_string_nomFichier = ("Song5.wav");
	x_enrTab_songInit[6].m_string_nomFichier = ("Song6.wav");
	x_enrTab_songInit[7].m_string_nomFichier = ("Song7.wav");
	x_enrTab_songInit[8].m_string_nomFichier = ("Song8.wav");
	x_enrTab_songInit[9].m_string_nomFichier = ("Song9.wav");
	x_enrTab_songInit[10].m_string_nomFichier = ("Song10.wav");
	x_enrTab_songInit[11].m_string_nomFichier = ("Song11.wav");
	x_enrTab_songInit[12].m_string_nomFichier = ("Song12.wav");
	x_enrTab_songInit[13].m_string_nomFichier = ("Song13.wav");
	x_enrTab_songInit[14].m_string_nomFichier = ("Song14.wav");
	x_enrTab_songInit[15].m_string_nomFichier = ("Song15.wav");
	x_enrTab_songInit[16].m_string_nomFichier = ("Song16.wav");
	x_enrTab_songInit[17].m_string_nomFichier = ("Song17.wav");
	x_enrTab_songInit[18].m_string_nomFichier = ("Song18.wav");
	x_enrTab_songInit[19].m_string_nomFichier = ("Song19.wav");
	x_enrTab_songInit[20].m_string_nomFichier = ("Song20.wav");
	
	x_enrTab_songInit[0].m_string_nomChanson = "2Unlimited";
	x_enrTab_songInit[1].m_string_nomChanson= "AlainBashung";
	x_enrTab_songInit[2].m_string_nomChanson= "AndreaBocelli";
	x_enrTab_songInit[3].m_string_nomChanson= "BritneySpears";
	x_enrTab_songInit[4].m_string_nomChanson= "CelineDion";
	x_enrTab_songInit[5].m_string_nomChanson= "Coolio";
	x_enrTab_songInit[6].m_string_nomChanson= "Corona";
	x_enrTab_songInit[7].m_string_nomChanson= "Haddaway";
	x_enrTab_songInit[8].m_string_nomChanson= "LosDelRio";
	x_enrTab_songInit[9].m_string_nomChanson= "LouBega";
	x_enrTab_songInit[10].m_string_nomChanson= "LouiseAttaque";
	x_enrTab_songInit[11].m_string_nomChanson= "Muse";
	x_enrTab_songInit[12].m_string_nomChanson ="MyleneFarmer";
	x_enrTab_songInit[13].m_string_nomChanson= "Paradisio";
	x_enrTab_songInit[14].m_string_nomChanson= "PatrickBruel";
	x_enrTab_songInit[15].m_string_nomChanson= "Reel2Real";
	x_enrTab_songInit[16].m_string_nomChanson= "RickyMartin";
	x_enrTab_songInit[17].m_string_nomChanson= "RobertMiles";
	x_enrTab_songInit[18].m_string_nomChanson ="Zebda";
	x_enrTab_songInit[19].m_string_nomChanson= "ZoukMachine";
	x_enrTab_songInit[20].m_string_nomChanson = "Gala";
	
}

void InitTabSport(TExtraitSonore x_enrTab_sportInit[], int x_int_taille) {
	x_enrTab_sportInit[0].m_string_nomFichier = ("Sport0.wav");
	x_enrTab_sportInit[1].m_string_nomFichier = ("Sport1.wav");
	x_enrTab_sportInit[2].m_string_nomFichier = ("Sport2.wav");
	x_enrTab_sportInit[3].m_string_nomFichier = ("Sport3.wav");
	x_enrTab_sportInit[4].m_string_nomFichier = ("Sport4.wav");
	x_enrTab_sportInit[5].m_string_nomFichier = ("Sport5.wav");
	x_enrTab_sportInit[6].m_string_nomFichier = ("Sport6.wav");
	x_enrTab_sportInit[7].m_string_nomFichier = ("Sport7.wav");
	x_enrTab_sportInit[8].m_string_nomFichier = ("Sport8.wav");
	x_enrTab_sportInit[9].m_string_nomFichier = ("Sport9.wav");
	x_enrTab_sportInit[10].m_string_nomFichier = ("Sport10.wav");
	x_enrTab_sportInit[0].m_string_nomChanson= "JoDeneriaz";
	x_enrTab_sportInit[1].m_string_nomChanson= "CdmHand";
	x_enrTab_sportInit[2].m_string_nomChanson= "CdeSainte";
	x_enrTab_sportInit[3].m_string_nomChanson= "RdmLavillenie";
	x_enrTab_sportInit[4].m_string_nomChanson= "CdeLemaitre";
	x_enrTab_sportInit[5].m_string_nomChanson= "LdcOm";
	x_enrTab_sportInit[6].m_string_nomChanson= "CdmPavard";
	x_enrTab_sportInit[7].m_string_nomChanson= "JoPerec";
	x_enrTab_sportInit[8].m_string_nomChanson= "CdmPetit";
	x_enrTab_sportInit[9].m_string_nomChanson= "CdmRugby";
	x_enrTab_sportInit[10].m_string_nomChanson= "TdFrance";
	x_enrTab_sportInit[0].m_int_date = 2006;
	x_enrTab_sportInit[1].m_int_date = 1995;
	x_enrTab_sportInit[2].m_int_date = 1976;
	x_enrTab_sportInit[3].m_int_date = 2014;
	x_enrTab_sportInit[4].m_int_date = 2010;
	x_enrTab_sportInit[5].m_int_date = 1993;
	x_enrTab_sportInit[6].m_int_date = 2018;
	x_enrTab_sportInit[7].m_int_date = 1996;
	x_enrTab_sportInit[8].m_int_date = 1998;
	x_enrTab_sportInit[9].m_int_date = 1999;
	x_enrTab_sportInit[10].m_int_date = 1989;
}


//fonction qui initialise toutes les cases de la mer a 0
void initCases(int f_int_mer) {

	int iBcl1; // compteur de boucle n1
	int iBcl2; // compteur de boucle n2

	//initialisation de toutes les cases a 0
	for (iBcl1 = 0; iBcl1 < LIGNES; iBcl1++) {
		for (iBcl2 = 0; iBcl2 < COLONNES; iBcl2++) {
			g_enrTab_Mer[f_int_mer][iBcl1][iBcl2].m_int_bateau = 0;
			g_enrTab_Mer[f_int_mer][iBcl1][iBcl2].m_bool_touche = 0;
		}
	}
}

// affichage du logo 
void logo(void) {
	Sleep(250);
	Color(3);

	printf("\t\t\t\t\toooooooooo.                .               o8o  oooo  oooo                 ooooo      ooo                                 oooo            \n");
	Sleep(250);
	printf("\t\t\t\t\t`888'   `Y8b             .o8                    `888  `888                 `888b.     `8'                                 `888            \n");
	Sleep(250);
	printf("\t\t\t\t\t 888     888  .oooo.   .o888oo  .oooo.    oooo   888   888   .ooooo.        8 `88b.    8   .oooo.   oooo   oooo  .oooo.    888   .ooooo.  \n");
	Sleep(250);
	printf("\t\t\t\t\t 888oooo888' `P  )88b    888   `P  )88b    888   888   888  d88' `88b       8   `88b.  8  `P  )88b   `88.  .8'  `P  )88b   888  d88' `88b \n");
	Sleep(250);
	printf("\t\t\t\t\t 888    `88b  .oP8888    888    .oP8888    888   888   888  8888888888      8     P888 8   .oP8888    `888        oP8888   888  888ooo888 \n");
	Sleep(250);
	printf("\t\t\t\t\t 888    .88P d8(  888    888 . d8(  888    888   888   888  888    __       8       `888  d8(  888     `888'    d8(  888   888  888    .o \n");
	Sleep(250);
	printf("\t\t\t\t\t o888bood8P'  `Y888888o   888    Y8888o   o888o o888o o888o `Y8bod8P'      o8o        `8  `Y8888888     `8'     `Y888888o o888o `Y8bod8P' \n");
	Sleep(250);
	printf("\t\t\t\t\t\t                  __/___                                               __\___                                      \n");
	Sleep(250);
	printf("\t\t\t\t\t\t           _____ /______|                                             |______\______                               \n");
	Sleep(250);
	printf("\t\t\t\t\t\t  _______ / _____\_______\_____                                 _____/_______/_____ \ _______                      \n");
	Sleep(250);
	printf("\t\t\t\t\t\t  \              < < <       |                                   |    > > >                 /                      \n");
	Sleep(250);
	printf("\t\t\t\t\t\t  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~                         ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~                    \n\n\n");
	Sleep(250);
	printf("\t\t\t\t\t\t		Created by :    Antoine Morier-Genoud      and       Thomas Guillerme\n\n\n\n");

	Sleep(1500);
}

//Ecrqn de chargement
void load(void) {

	int iBcl; // compteur de boucle

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

void Zoom(void) {
	keybd_event(VK_LCONTROL, 0xA2, 0, 0); //Appuie sur Ctrl
	mouse_event(MOUSEEVENTF_WHEEL, 0, 0, -75*120, 0);
	keybd_event(VK_LCONTROL, 0x1c, KEYEVENTF_KEYUP, 0); // Relache ENTREE
}
//DEBUG
void afficheMerDebug(int f_int_player) {

	int iBcl1; // compteur de boucle n1
	int iBcl2; // compteur de boucle n2

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
			printf("%i ", g_enrTab_Mer[f_int_player][iBcl1][iBcl2].m_int_bateau);
		}
		//retour a la ligne pour rendre le resultat plus clean
		printf("\n");
		Color(COLOR_1);
	}
}

//fonction pour afficher une mer
void afficheMer(int f_int_mer) {

	int iBcl1; // compteur de boucle n1
	int iBcl2; // compteur de boucle n2
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
		if (f_int_mer == 1) {
			Color(COLOR_2 | BACKGROUND_BLUE);
		}
		else {
			Color(COLOR_2 | 35);
		}
	
		//boucle for pour afficher les colonnes
		for (iBcl2 = 0; iBcl2 < COLONNES; iBcl2++) {
			if (g_enrTab_Mer[f_int_mer][iBcl1][iBcl2].m_bool_touche == 1) {
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

	int iBcl1; // compteur de boucle n1
	int iBcl2; // compteur de boucle n2

	bool l_bool_bateauxPlaces = 0; //Les bateaux ont ete correctement places
	bool l_bool_direction; //l_bool_direction 0 pour vertical et 1 pour horizontal

	int l_int_ligne = 0; //
	int l_int_colonne = 0; //

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
				if ((g_enrTab_Mer[f_int_mer][l_int_ligne][l_int_colonne].m_int_bateau == 0) && (g_enrTab_Mer[f_int_mer][l_int_ligne + 1][l_int_colonne].m_int_bateau == 0) && (g_enrTab_Mer[f_int_mer][l_int_ligne + 2][l_int_colonne].m_int_bateau == 0)) {
					//ajout du bateau dans la mer
					g_enrTab_Mer[f_int_mer][l_int_ligne][l_int_colonne].m_int_bateau = 1;
					g_enrTab_Mer[f_int_mer][l_int_ligne + 1][l_int_colonne].m_int_bateau = 1;
					g_enrTab_Mer[f_int_mer][l_int_ligne + 2][l_int_colonne].m_int_bateau = 1;
					//stockage du bateau
					g_enr_Bateaux[iBcl1].m_TCoord_Case1.m_int_colonne = l_int_colonne;
					g_enr_Bateaux[iBcl1].m_TCoord_Case1.m_int_ligne = l_int_ligne;
					g_enr_Bateaux[iBcl1].m_TCoord_Case2.m_int_colonne = l_int_colonne;
					g_enr_Bateaux[iBcl1].m_TCoord_Case2.m_int_ligne = l_int_ligne + 1;
					g_enr_Bateaux[iBcl1].m_TCoord_Case3.m_int_colonne = l_int_colonne;
					g_enr_Bateaux[iBcl1].m_TCoord_Case3.m_int_ligne = l_int_ligne + 2;
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
				if ((g_enrTab_Mer[f_int_mer][l_int_ligne][l_int_colonne].m_int_bateau == 0) && (g_enrTab_Mer[f_int_mer][l_int_ligne][l_int_colonne + 1].m_int_bateau == 0) && (g_enrTab_Mer[f_int_mer][l_int_ligne][l_int_colonne + 2].m_int_bateau == 0)) {
					//ajout du bateau dans la mer
					g_enrTab_Mer[f_int_mer][l_int_ligne][l_int_colonne].m_int_bateau = 1;
					g_enrTab_Mer[f_int_mer][l_int_ligne][l_int_colonne + 1].m_int_bateau = 1;
					g_enrTab_Mer[f_int_mer][l_int_ligne][l_int_colonne + 2].m_int_bateau = 1;
					//Stockage du bateau
					g_enr_Bateaux[iBcl1].m_TCoord_Case1.m_int_colonne = l_int_colonne;
					g_enr_Bateaux[iBcl1].m_TCoord_Case1.m_int_ligne = l_int_ligne;
					g_enr_Bateaux[iBcl1].m_TCoord_Case2.m_int_colonne = l_int_colonne + 1;
					g_enr_Bateaux[iBcl1].m_TCoord_Case2.m_int_ligne = l_int_ligne;
					g_enr_Bateaux[iBcl1].m_TCoord_Case3.m_int_colonne = l_int_colonne + 2;
					g_enr_Bateaux[iBcl1].m_TCoord_Case3.m_int_ligne = l_int_ligne;
					//confirmation que le bateau est place
					l_bool_bateauxPlaces = 1;
				}
			} while (l_bool_bateauxPlaces == 0);
		}
	}
}

//fonction pour que les joueurs placent les bateaux
void placeBateauJoueur(int f_int_mer) {
	int iBcl1,iBcl2;
	int l_int_direction; //direction demandee au joueur
	bool l_bool_direction; //l_bool_direction 0 pour vertical et 1 pour horizontal
	bool l_bool_bateauxPlaces;
	int l_int_ligne = 0; //
	int l_int_colonne = 0; //
	int l_int_coordX; //coordonn�es X utilis�e dans certains calculs
	int l_int_coordY; //coordonn�es Y utilis�e dans certains calculs

	//init aleatoire
	srand(time(NULL));

	//boucle pour generer un certain nombre de bateau
	for (iBcl1 = 0; iBcl1 < N_BATEAUX; iBcl1++) {

		//demande user de la direction du bateau
		do {
			printf("\nJoueur %i Saisir la direction (v ou h) : ", f_int_mer);
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
				if ((g_enrTab_Mer[f_int_mer][l_int_ligne][l_int_colonne].m_int_bateau == 0) && (g_enrTab_Mer[f_int_mer][l_int_ligne + 1][l_int_colonne].m_int_bateau == 0) && (g_enrTab_Mer[f_int_mer][l_int_ligne + 2][l_int_colonne].m_int_bateau == 0)) {
					//ajout du bateau dans la mer
					g_enrTab_Mer[f_int_mer][l_int_ligne][l_int_colonne].m_int_bateau = 1;
					g_enrTab_Mer[f_int_mer][l_int_ligne + 1][l_int_colonne].m_int_bateau = 1;
					g_enrTab_Mer[f_int_mer][l_int_ligne + 2][l_int_colonne].m_int_bateau = 1;
					//stockage du bateau
					g_enr_Bateaux[iBcl1].m_TCoord_Case1.m_int_colonne = l_int_colonne;
					g_enr_Bateaux[iBcl1].m_TCoord_Case1.m_int_ligne = l_int_ligne;
					g_enr_Bateaux[iBcl1].m_TCoord_Case2.m_int_colonne = l_int_colonne;
					g_enr_Bateaux[iBcl1].m_TCoord_Case2.m_int_ligne = l_int_ligne + 1;
					g_enr_Bateaux[iBcl1].m_TCoord_Case3.m_int_colonne = l_int_colonne;
					g_enr_Bateaux[iBcl1].m_TCoord_Case3.m_int_ligne = l_int_ligne + 2;
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
				if ((g_enrTab_Mer[f_int_mer][l_int_ligne][l_int_colonne].m_int_bateau == 0) && (g_enrTab_Mer[f_int_mer][l_int_ligne][l_int_colonne + 1].m_int_bateau == 0) && (g_enrTab_Mer[f_int_mer][l_int_ligne][l_int_colonne + 2].m_int_bateau == 0)) {
					//ajout du bateau dans la mer
					g_enrTab_Mer[f_int_mer][l_int_ligne][l_int_colonne].m_int_bateau = 1;
					g_enrTab_Mer[f_int_mer][l_int_ligne][l_int_colonne + 1].m_int_bateau = 1;
					g_enrTab_Mer[f_int_mer][l_int_ligne][l_int_colonne + 2].m_int_bateau = 1;
					//Stockage du bateau
					g_enr_Bateaux[iBcl1].m_TCoord_Case1.m_int_colonne = l_int_colonne;
					g_enr_Bateaux[iBcl1].m_TCoord_Case1.m_int_ligne = l_int_ligne;
					g_enr_Bateaux[iBcl1].m_TCoord_Case2.m_int_colonne = l_int_colonne + 1;
					g_enr_Bateaux[iBcl1].m_TCoord_Case2.m_int_ligne = l_int_ligne;
					g_enr_Bateaux[iBcl1].m_TCoord_Case3.m_int_colonne = l_int_colonne + 2;
					g_enr_Bateaux[iBcl1].m_TCoord_Case3.m_int_ligne = l_int_ligne;
					//confirmation que le bateau est place
					l_bool_bateauxPlaces = 1;
				}
			} while (l_bool_bateauxPlaces == 0);
		}
	}
}

//fonction pour verifier si il y a un bateau coule dans une mer
//fonctionne parfsois ex pour E456 et pour CDE4 et pour A234
void checkCoule(int f_int_mer) {
	int iBcl1, iBcl2;
	bool l_boolTab_Coules[2][N_BATEAUX] = { 0,0 }; //Tableau 2D qui stocke l'etat (coule ou non) de 1 bateau de 1 joueur par case

	g_int_coules[f_int_mer] = 0;
	for (iBcl1 = 0; iBcl1 < N_BATEAUX; iBcl1++) {
		if ((g_enrTab_Mer[f_int_mer][g_enr_Bateaux[iBcl1].m_TCoord_Case1.m_int_ligne][g_enr_Bateaux[iBcl1].m_TCoord_Case1.m_int_colonne].m_bool_touche == 1) && (g_enrTab_Mer[f_int_mer][g_enr_Bateaux[iBcl1].m_TCoord_Case2.m_int_ligne][g_enr_Bateaux[iBcl1].m_TCoord_Case2.m_int_colonne].m_bool_touche == 1) && (g_enrTab_Mer[f_int_mer][g_enr_Bateaux[iBcl1].m_TCoord_Case3.m_int_ligne][g_enr_Bateaux[iBcl1].m_TCoord_Case3.m_int_colonne].m_bool_touche == 1)) {
			l_boolTab_Coules[f_int_mer][iBcl1] = 1;
		}
	}
	for (iBcl2 = 0; iBcl2 < N_BATEAUX; iBcl2++) {
		if (l_boolTab_Coules[f_int_mer][iBcl2] == 1) {
			g_int_coules[f_int_mer]++;
		}
	}

}

//fonction qui demande une case au joueur et qui la retourne au format TCoord
TCoord demandeJoueur(void) {
	//declarations
	TCoord l_enr_case;
	int l_int_coordX; //coordonn�es X utilis�e dans certains calculs 
	int l_int_coordY; //coordonn�es Y utilis�e dans certains calculs

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
bool checkCase(TCoord l_enr_essai, int f_int_mer) {
	
	if (g_enrTab_Mer[f_int_mer][l_enr_essai.m_int_ligne][l_enr_essai.m_int_colonne].m_int_bateau == 1) {
		//printf("Touche\n");
		g_enrTab_Mer[f_int_mer][l_enr_essai.m_int_ligne][l_enr_essai.m_int_colonne].m_bool_touche = 1;
		g_int_tentatives += 1;
		return(1);
	}

	else {
		//printf("Loupe\n");
		g_int_tentatives++;
		return(0);
	}
}

int points(int x_int_mer) {
	int iBcl1, iBcl2;
	int l_int_points = 0;

	for (iBcl1 = 0; iBcl1 < 6; iBcl1++) {
		for (iBcl2 = 0; iBcl2 < 6; iBcl2++) {
			if (g_enrTab_Mer[x_int_mer][iBcl1][iBcl2].m_bool_touche == 1) {
				l_int_points++;
			}
		}
	}
	return(l_int_points);
}

//Affiche les règles
void regles(void) {
	int l_char_regles; //connaissance des regles

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

	int l_int_nbJoueurs; //nombre de joueurs de la partie

	printf("Combien de joueurs ? \n");
	scanf_s("%i", &l_int_nbJoueurs);
	system("CLS");
	return(l_int_nbJoueurs);
}

//Fonction qui demarre une partie en mode solo
int playSolo(void) {
	system("CLS");

	int l_int_timeDebut;//timecode du debut de la partie
	int l_int_timeFin;//timecode de la fin de la partie
	int l_int_player = 0;
	//placement des bateaux
	placeBateau(l_int_player);
	afficheMer(l_int_player);

	//Debut du chrono
	l_int_timeDebut = GetTickCount();

	//Tant que le joueur n'a pas gagne le jeu continue
	do{
		TCoord l_enr_saisie = demandeJoueur();
		//Si le bateau est touche on affiche touche ou coule
		if (checkCase(l_enr_saisie, l_int_player)) {
			//si le bateau est coule on affiche coule
			checkCoule(0);
			int l_int_points = points(0);
			if (g_int_coules[l_int_player] > g_int_coulesAns[l_int_player]) {
				g_int_coulesAns[l_int_player] = g_int_coules[l_int_player];
				system("CLS");
				afficheMer(l_int_player);
				printf("Coule !\n");
			}

			//Si non on affiche seulement touche
			else {
				system("CLS");
				afficheMer(l_int_player);
				printf("Touche !\n");
			}
		}

		//Si non on affiche Rate
		else {
			int l_int_points = points(0);
			system("CLS");
			afficheMer(l_int_player);
			printf("Rate !\n");
		}


	}while (points(0) < N_BATEAUX * 3);
	return(l_int_timeDebut);
}

//Fonction qui demarre une partie en mode 2 joueurs
int playDuo(void) {

	bool l_bool_win = 0; //Etat de la partie (Gagnee 1 | Pas encore gagnee 0)
	int l_int_tour = 1; //Numero du Tour
	int l_int_player; //Numero du joueur dont c'est le tour
	int l_intTab_points[] = { 0,0,0 };


	//placement des bateaux des deux joueurs
	//placeBateauJoueur(1);
	//placeBateauJoueur(2);
	placeBateau(1);
	placeBateau(2);

	//Debut du chrono
	int l_int_timeDebut = GetTickCount();

	do{
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
		printf("C'est au joueur %i de jouer\n", l_int_player);
		//Demande de saisie
		TCoord l_enr_saisie = demandeJoueur();

		if (checkCase(l_enr_saisie, l_int_player)) {
			//si le bateau est coule on affiche coule
			int l_int_points = points(0);
			checkCoule(l_int_player);
			if (g_int_coules > g_int_coulesAns) {
				g_int_coulesAns[l_int_player] = g_int_coules[l_int_player];
				system("CLS");
				afficheMer(l_int_player);
				printf("Coule !\n");
			}

			//Si non on affiche seulement touche
			else {
				system("CLS");
				afficheMer(l_int_player);
				printf("Touche !\n");
			}
		}

		//Si non on affiche Rate
		else {
			system("CLS");
			afficheMer(l_int_player);
			printf("Rate !\n");
		}
		l_intTab_points[l_int_player] = points(l_int_player);

		l_int_tour++;
	} while (l_intTab_points[0] < 6 || l_intTab_points[1] < 6);
	return(l_int_timeDebut);
}