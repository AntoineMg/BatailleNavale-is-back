#include "PrjInfo2022.h"


//VARIABLES

//pour les variables globales, les renommer en g_int_xx
/*
//Variables utilisees pour le positionnement
//locales


//Verifieurs
int l_int_choix[2]; //choix
int l_int_tour; //Numero du Tour
int l_int_player; //Numero du joueur dont c'est le tour
*/

//globales

int g_int_coules[] = { 0,0 }; // compteur de bateaux coul�s dans chaque mer
int g_int_coulesAns[] = { 0,0 }; //compteur de bateaux coul�s dans chaque mer au tour pr�c�dent
//Compteurs
int g_int_points[] = { 0,0 }; //Compteur de points par joueur
int g_int_tentatives; //compteur de tentatives
//Mers et Bateaux
TCase g_enrTab_Mer[2][LIGNES][COLONNES]; //Declarations des mers (Tableau 3D, voir readme.md pour details)
TBateau g_enr_Bateaux[N_BATEAUX]; //Declarations des bateaux 

void main(void) {

	int l_char_lancement;
	int l_int_nbJoueurs; //nombre de joueurs de la partie
	int l_int_timeDebut;//timecode du debut de la partie
	int l_int_timeFin;//timecode de la fin de la partie
	int l_int_time;//duree de la partie
	int l_int_minutes;//nombre des minutes du temps
	int l_int_secondes;//nombre des secondes du temps

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
	Zoom();
	if (l_int_nbJoueurs == 1) {
		PlaySoundA("Theme.wav", NULL, SND_ASYNC | SND_LOOP);
		l_int_timeDebut = playSolo();
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
	printf("Vous avez effectue %i tentatives en une duree de %i minutes et %i secondes", g_int_tentatives, l_int_minutes, l_int_secondes);

	//ui
}
