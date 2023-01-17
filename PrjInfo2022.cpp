#include "PrjInfo2022.h"


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

