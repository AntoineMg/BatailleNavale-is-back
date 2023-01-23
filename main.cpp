#include "PrjInfo2022.h"


//VARIABLES

//Compteurs de Boucles
int iBcl; // compteur de boucle
int iBcl1; // compteur de boucle n2
int iBcl2; // compteur de boucle n3
int iBcl3; // compteur de boucle n4

//Variables utilisees pour le positionnement
int l_int_ligne = 0; //
int l_int_colonne = 0; //
int l_int_coordX; //coordonn�es X utilis�e dans certains calculs 
int l_int_coordY; //coordonn�es Y utilis�e dans certains calculs
int l_int_direction; //direction demandee au joueur
bool l_bool_direction; //l_bool_direction 0 pour vertical et 1 pour horizontal

//Compteurs
int l_int_points[] = { 0,0 }; //Compteur de points par joueur
int l_int_tentatives; //compteur de tentatives

//Verifieurs
bool l_bool_bateauxPlaces = 0; //Les bateaux ont ete correctement places
bool l_bool_win = 0; //Etat de la partie (Gagnee 1 | Pas encore gagnee 0)

int l_char_lancement;
int l_int_choix[2]; //choix

//Saisies par l'Utilisateur
int l_int_nbJoueurs; //nombre de joueurs de la partie
int l_char_regles; //connaissance des regles


//Variables Temps POSSIBILITE D'AMELIORER EN UTILISANT UN TYPEDEF
int l_int_timeDebut;//timecode du debut de la partie
int l_int_timeFin;//timecode de la fin de la partie
int l_int_time;//duree de la partie
int l_int_minutes;//nombre des minutes du temps
int l_int_secondes;//nombre des secondes du temps

//Gestion des tours
int l_int_tour; //Numero du Tour
int l_int_player; //Numero du joueur dont c'est le tour

//Gestion des bateaux coul�s
int l_int_coules[] = { 0,0 }; // compteur de bateaux coul�s dans chaque mer
int l_int_coulesAns[] = { 0,0 }; //compteur de bateaux coul�s dans chaque mer au tour pr�c�dent
bool l_boolTab_Coules[2][N_BATEAUX] = { 0,0 }; //Tableau 2D qui stocke l'etat (coule ou non) de 1 bateau de 1 joueur par case

//Mers et Bateaux
TCase l_enrTab_Mer[2][LIGNES][COLONNES]; //Declarations des mers (Tableau 3D, voir readme.md pour details)
TBateau l_enr_Bateaux[N_BATEAUX]; //Declarations des bateaux 

void main(void) {

	//Mets la fenetre en fullscreen
	Fscreen();

	//Lance la musique d'intro
	PlaySoundA("Intro2.wav", NULL, SND_ASYNC);
	Sleep(2000);

	//Affiche le logo et l'ecran de chargement
	logo();
	load();

	//Lance l'audio du menu (explications en anglais)
	PlaySoundA("Menu.wav", NULL, SND_ASYNC);
	printf("Recommencer le message (Y ou y) ou lancer le programme (autre touche)\n");
	l_char_lancement = _getch();
	if ((l_char_lancement == 'Y') || (l_char_lancement == 'y')) {
		PlaySoundA("Menu.wav", NULL, SND_ASYNC);
	}
	
	//Acceuil et regles
	//Color(FOREGROUND_INTENSITY | BACKGROUND_BLUE);
	regles();
	l_int_nbJoueurs = nombreJoueurs();
	if (l_int_nbJoueurs == 1) {
		PlaySoundA("Theme.wav", NULL, SND_ASYNC | SND_LOOP);
		playSolo();
	}
	else if (l_int_nbJoueurs == 2) {
		PlaySoundA("Theme.wav", NULL, SND_ASYNC | SND_LOOP);
		playDuo();
	}
	else{
		printf("Tant pis, au revoir !!!");
		system("pause");
	}
	
	//Obtention de la duree de la partie
	l_int_timeFin = GetTickCount();
	l_int_time = l_int_timeFin - l_int_timeDebut;
	l_int_minutes = l_int_time / 60000; //60*1000
	l_int_secondes = (l_int_time - (60000 * l_int_minutes)) / 1000;

	//affichage ecran victoire
	printf("Gagne\n");
	//nb tentatives
	printf("Vous avez effectue %i tentatives en une duree de %i minutes et %i secondes", l_int_tentatives, l_int_minutes, l_int_secondes);

	//ui
}
