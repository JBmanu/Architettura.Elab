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
	//char s1[] = "Sette scettici sceicchi sciocchi con la sciatica a Shanghai";
	char s1[] = "Ciao Cia Cio Ociao ciao Ocio CiCiao CieCiaCiu CiAo eeCCia";
	//char s1[] = "ciao ciao ciak";

	unsigned int lungS1 = sizeof(s1) - 1;
	//char s2[] = "icchi";
	char s2[] = "Cia";

	unsigned int lungS2 = sizeof(s2) - 1;
	// Output
	unsigned int posizioni[MAX_LEN];
	unsigned int posizioniLen;

	// Blocco assembler
	__asm
	{
		MOV posizioniLen, 0  //Azzero posizione dell'indice
		XOR EAX, EAX   // Indice Parola
		XOR ESI, ESI   // Indice del Testo
		XOR EDX, EDX   // Lunghezza della Parola
		XOR ECX, ECX   // Lunghezza del Testo
		XOR EBX, EBX   // Contenitore dei caratteri BL-Testo e BH-Parola
		XOR EDI, EDI   // Indice vettore
		///////// assegnamento
		MOV ECX, lungS1   // lunghezza testo
		MOV EDX, lungS2   // lunghezza parola


// Ciclo per ogni carattere del testo dato
CicloTesto:	CMP ESI, ECX
			JE Fine           // controllo se ho letto tutti i caratteri del testo e fine algoritmo

			MOV BH, s1[ESI]   // carattere del testo  
			MOV BL, s2[EAX]	  // carattere della parola

			CMP BH, BL        // Controllo se i caratteri sono uguali
			JE Uguali
			CMP BH, BL        // Controllo se i caratteri sono diversi
			JNE Diversi

	Controllo:	CMP EAX, EDX   // Controllo se ho trovato tutte le parola nel testo
				JE Azzera

	Continua:	INC ESI
JMP CicloTesto

// Caratteri uguali incremento l'indice della parola per il nuovo carattere
Uguali:	INC EAX
JMP Controllo
// Caratteri diversi pulisco l'area di memoria dell'indice 
Diversi:	CMP BH, s2[0]
			JE Indietro
	Aggiornato:	CALL PulisciEAX
JMP Controllo

// Pulisco l'area di memoria e salvo l'indice della parola completa trovata nel testo
Azzera:	CALL Indice
		MOV posizioni[4 * EDI], EAX
		INC EDI
		INC posizioniLen
		XOR EAX, EAX
JMP Continua

// Ricerca dell'indice della parola trovata tramite sottrazione
Indice:	CALL PulisciEAX
		MOV EAX, ESI
		INC EAX
		SUB EAX, EDX
RET

// Azzera l'area di memoria EAX
Indietro:	DEC ESI
JMP Aggiornato

// Azzera l'area di memoria EAX
PulisciEAX:	XOR EAX, EAX
RET

// Fine algoritmo
Fine:
	}

	// Stampa su video
	{
		unsigned int i;
		for (i = 0; i < posizioniLen; i++)
			printf("Sottostringa in posizione=%d\n", posizioni[i]);
	}
}
