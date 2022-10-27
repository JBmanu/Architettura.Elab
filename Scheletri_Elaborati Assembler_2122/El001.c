/********************************************************************************
 *                                                                              *
 *                   Architetture dei sistemi di Elaborazione                   *
 *                                                                              *
 ********************************************************************************

 Elaborato 1
 Descrizione: Cercare tutte le occorrenze di una sottostringa all'interno
			  di una stringa

 ********************************************************************************/

#include <stdio.h>

void main()
{
#define MAX_LEN	100

	// Input
	char s1[] = "ciao ciao ciak";
	unsigned int lungS1 = sizeof(s1) - 1;
	char s2[] = "ciao";
	unsigned int lungS2 = sizeof(s2) - 1;
	// Output
	unsigned int posizioni[MAX_LEN];
	unsigned int posizioniLen;

	// Blocco assembler
	__asm
	{
		MOV posizioniLen, 0
		MOV posizioni, 0
		XOR EAX, EAX   // Indice del Testo
		XOR ECX, ECX   // Lunghezza del Testo
		XOR ESI, ESI   // Indice Parola
		XOR EDX, EDX   // Lunghezza della Parola
		XOR EBX, EBX   // Contenitore dei caratteri BL-Testo e BH-Parola
		XOR EDI, EDI
		/////////
		MOV ECX, lungS1   // lunghezza testo
		MOV EDX, lungS2   // lunghezza parola



CicloTesto:	CMP EAX, ECX 
			JE Fine

			MOV BL, s1[EAX]   // carattere testo
			MOV BH, s2[ESI]	  // carattere parola

			// Se sono uguali
			CMP BL, BH 
			JE Uguale
			// Se sono diversi
			CMP BL, BH
			JNE Diverso

			Controllo: INC ESI
			CMP ESI, EDX
			JE Azzera
			Continua: INC EAX
JMP CicloTesto
			
Azzera: CMP EDI, ESI
		JE Trovato
		CMP EDI, ESI
		JNE NTrovato
		Pulisci: XOR ESI, ESI
		JMP Continua

Uguale: ADD EDI, 1
		JMP Controllo
Diverso: ADD EDI, 0
		JMP Controllo

Trovato: // MOV posizioni[posizioniLen], 1
		  INC posizioniLen
		  JMP Pulisci
NTrovato: XOR EDI, EDI
		  JMP Pulisci

		Fine: //MOV posizioniLen, EDI
	}

	// Stampa su video
	{
		printf("Sottostringa in posizione=%d\n", posizioniLen);

		/*unsigned int i;
		for (i = 0; i < posizioniLen; i++)
			printf("Sottostringa in posizione=%d\n", posizioni[i]);*/
	}
}
