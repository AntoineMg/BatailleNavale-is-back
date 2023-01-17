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




