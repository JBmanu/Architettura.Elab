/********************************************************************************
 *                                                                              *
 *                   Architetture dei sistemi di Elaborazione                   *
 *                                                                              *
 ********************************************************************************

 Elaborato 2
 Descrizione: Scomporre in fattori primi un numero

 ********************************************************************************/

#include <stdio.h>

void main()
{
	// Variabili
	unsigned int Numero = 12612600;
	unsigned int Divisori[100];	// 100 è una dimensione più che sufficiente per il vettore
	int NumDiv;	// Numero dei fattori trovati

// Blocco assembler
	__asm
	{

	}

	// Stampa su video
	{
		int i;
		printf("Numero di fattori primi=%d\n", NumDiv);
		for (i = 0; i < NumDiv; i++)
			printf("%d\n", Divisori[i]);
	}
}
