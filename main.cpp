#include "PrjInfo2022.h"

//VARIABLES GLOBALES
int g_int_coules[] = { 0,0 }; // compteur de bateaux coul�s dans chaque mer
int g_int_coulesAns[] = { 0,0 }; //compteur de bateaux coul�s dans chaque mer au tour pr�c�dent
int g_int_tentatives; //compteur de tentatives
TCase g_enrTab_Mer[2][LIGNES][COLONNES]; //Declarations des mers (Tableau 3D, voir readme.md pour details)
TBateau g_enr_Bateaux[N_BATEAUX]; //Declarations des bateaux 

void main(void) {
	int l_int_nbJoueurs; //nombre de joueurs de la partie
	int l_int_timeDebut;//timecode du debut de la partie

	Debut();

	l_int_nbJoueurs = nombreJoueurs();
	Zoom();
	if (l_int_nbJoueurs == 1) {
		l_int_timeDebut = playSolo();
	}
	else if (l_int_nbJoueurs == 2) {
		l_int_timeDebut = playDuo();
	}
	else{
		printf("Tant pis, au revoir !!!");
		system("pause");
	}
	//Obtention de la duree de la partie
	Final(l_int_timeDebut,g_int_tentatives);
}
