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
		MOV numSequenzaZero, 0
		MOV numSequenzaUno, 0
		XOR EAX, EAX	// numero da analizzare 
		XOR ECX, ECX	// Contatore dei bit da leggere da una DWORD 32 bit

		XOR EBX, EBX	// salvo gli zeri
		XOR EDX, EDX	// salovo gli uni

		MOV EAX, w

	// Ciclo per leggere i Bit del numero dato DWORD 32
	CicloBit:	SHR EAX, 1	// shift logic bit a bit a destra
				
				JNC BitZero	// Controllo se il bit e' zero
				JC BitUno	// Controllo se il bit e' uno

	Continua:	INC ECX
				CMP ECX, 32
				JE FineBit
	JMP CicloBit

	// Se il Bit e' zero
	BitZero:	INC EBX
				CALL AggiornaUni
	JMP Continua

	// Se il Bit e' zero
	BitUno:	INC EDX
			CALL AggiornaZeri
	JMP Continua

	// Aggiorna la nuova sequenza di ZERI piu lungha
	AggiornaZeri:	CMP EBX, numSequenzaZero
					JA MaxZeri
			AzzeraZeri:	XOR EBX, EBX
	RET
	// Aggiorna il numero massimo di zeri
	MaxZeri:	MOV numSequenzaZero, EBX
	JMP AzzeraZeri

	// Aggiorna la nuva sequenza di UNI piu lunga
	AggiornaUni:	CMP EDX, numSequenzaUno
					JA MaxUni
			AzzeraUni:	XOR EDX, EDX
	RET
	//Aggiorna il numero massimo di uni
	MaxUni:	MOV numSequenzaUno, EDX
	JMP AzzeraUni

	// Fine e aggiornamento dei massimi zeri e uni
	FineBit:	CALL AggiornaZeri
				CALL AggiornaUni
	}

	// Stampa su video
	printf("La sequenza piu' lunga di bit contigui a 0 e' pari a %d\n", numSequenzaZero);
	printf("La sequenza piu' lunga di bit contigui a 1 e' pari a %d\n", numSequenzaUno);
}
