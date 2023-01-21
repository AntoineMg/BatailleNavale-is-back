#pragma once

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <mmsystem.h> 
#include <tchar.h>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <math.h>
#include "Fonctions.cpp"

#pragma comment(lib,"Winmm.lib")
#pragma comment(lib,"winmm")

//PARAMETRES

//Taille de la grille
#define LIGNES 6
#define COLONNES 6
//Nombre de bateaux
#define N_BATEAUX 2
//Choix de couleurs
#define COLOR_1 15
#define COLOR_2 15
//Durees
#define TEMPS 50
#define TEMPS2 200
//Autres parametres
#define TAILLE_LOAD 80

//Declarations prototypes
void playSolo(void);
void initCases(int f_int_mer);
void logo(void);
void load(void);
void Fscreen(void);
void afficheMerDebug(int f_int_player);
void afficheMer(int f_int_mer);
void placeBateau(int f_int_mer);
void placeBateauJoueur(int f_int_mer);
void checkCoule(int f_int_mer);
TCoord demandeJoueur(void);
bool checkCase(TCoord l_enr_essai, int f_int_mer);
void regles(void);
int nombreJoueurs(void);
void playSolo(void);
void playDuo(void);

typedef struct {
	int m_int_ligne;
	int m_int_colonne;
}TCoord;

typedef struct {
	TCoord m_TCoord_Case1;
	TCoord m_TCoord_Case2;
	TCoord m_TCoord_Case3;
}TBateau;

typedef struct {
	LPCSTR  m_string_nomFichier;
	LPCSTR  m_string_nomChanson;
	int m_int_date;
}TExtraitSonore;

typedef struct {
	int m_int_points;
	int m_intTab_jetDes[3];
}TJoueur421;

typedef struct {
	int m_int_bateau;
	bool m_bool_touche;
}TCase;

typedef struct {
	char m_char_couleur;
	int m_int_valeur;
}TCarte;

typedef struct {
	int miMn;
	int miSec;
}THeure;

typedef struct {
	int m_int_note;
	int m_int_duree;
}TNote;

void Color(WORD x_word_attributes);
void InitTabMusic(TExtraitSonore x_enrTab_songInit[], int x_int_taille);
void InitTabSport(TExtraitSonore x_enrTab_sportInit[], int x_int_taille);

void ChoisirInstrument(int x_int_channel, int x_int_numInstrument, HMIDIOUT x_hMidiOut_obj);
void JouerNote(int x_int_channel, int x_int_note, int x_int_force, HMIDIOUT x_hMidiOut_obj);
void ArreterNote(int x_int_Channel, int x_int_note, HMIDIOUT x_hMidiOut_obj);

void JouerSonBaR(int x_int_code, HMIDIOUT x_hMidiOut_obj, int x_int_volume);
void JouerSonJeu(int x_int_note, HMIDIOUT x_hMidiOut_obj, int x_int_volume);

void InitJeu32(TCarte x_enrTab_Carte32[], int m_int_taille);