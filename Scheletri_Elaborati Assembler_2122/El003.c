/********************************************************************************
 *                                                                              *
 *                   Architetture dei sistemi di Elaborazione                   *
 *                                                                              *
 ********************************************************************************

 Elaborato 3
 Descrizione:	Data una DWORD, trovare le sequenze contigue più lunghe
				di bit a 0 e a 1 e restituirne le rispettive lunghezze.

 ********************************************************************************/

#include <stdio.h>

void main()
{
	// Variabili
	unsigned int w = 0x00000000;	// la DWORD
	int numSequenzaZero;	// Lunghezza della sequenza più lunga di bit a 0 contigui
	int numSequenzaUno;     // Lunghezza della sequenza più lunga di bit a 1 contigui

	__asm
	{

	}

	// Stampa su video
	printf("La sequenza piu' lunga di bit contigui a 0 e' pari a %d\n", numSequenzaZero);
	printf("La sequenza piu' lunga di bit contigui a 1 e' pari a %d\n", numSequenzaUno);
}
