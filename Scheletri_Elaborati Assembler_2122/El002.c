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
	//unsigned int Numero = 12612600;
	unsigned int Numero = 999;
	unsigned int Divisori[100];	// 100 è una dimensione più che sufficiente per il vettore
	int NumDiv;	// Numero dei fattori trovati

// Blocco assembler
	__asm
	{
		MOV NumDiv, 0
		MOV Divisori, 0
		XOR EAX, EAX	// contenitore del numero da dividere
		XOR EBX, EBX	// Divisore
		XOR ECX, ECX	// numero che viene diviso e aggiornato
		XOR EDX, EDX	// resto
		XOR EDI, EDI	// indice array
		XOR ESI, ESI	// 

		// EAX/EBX=EAX   EDX=resto

		MOV ECX, Numero
		MOV EAX, Numero  
		MOV EBX, 2

// Ciclo per trovare il prodotto dei fattori dei numeri primi
CicloNum:	CMP ECX, 2
			JB FineLoop

		XOR EDX, EDX      // pulisco il resto
		DIV EBX			  // divido
		CMP EDX, 0        // controllo se la divisione ha il resto diverso da zero
		JNE DivisoreInc   // se diverso da zero incremento il divisore

		CALL SePrimo      // controllo se il divisore e un numero primo

	Primo:	MOV ECX, EAX   // aggiorno il numero da dividere
			MOV Divisori[4 * EDI], EBX  // salvo il divisore
			INC EDI   
			MOV EBX, 2    // ricomincio dal primo numero primo
JMP CicloNum


DivisoreInc:	INC EBX		   // incremento il divisore 
				MOV EAX, ECX   // ripristino l ultimo dividendo 
JMP CicloNum

// controllo se il numero e' primo o meno
SePrimo:	CMP EBX, 2		
			JE Primo

			PUSH EAX    // salvo EAX
			PUSH EBX	// salvo EBX	
			PUSH ECX	// salvo ECX

			MOV ESI, EBX
			MOV ECX, EBX
			SHR ECX, 1		// radice quadrata
			MOV EBX, 2		// divisore

		ClicloSe:	XOR EDX, EDX	// pulisco resto
					MOV EAX, ESI	// salvo valore da dividere
					DIV EBX			
					TEST EDX, EDX	// controllo il resto
					JZ NonPrimo			
					INC EBX			
					CMP EBX, ECX	// controllo se ho finito
		JLE ClicloSe
			
			POP ECX		// ripristino i valori
			POP EBX
			POP EAX
			JMP Primo

			NonPrimo:	POP ECX		// ripristino i valori
						POP EBX
						POP EAX
			JMP	DivisoreInc
RET


FineLoop:	MOV NumDiv, EDI	// inserisco indice dei numeri primi

	}

	// Stampa su video
	{
		int i;
		printf("Numero di fattori primi=%d\n", NumDiv);
		for (i = 0; i < NumDiv; i++)
			printf("%d\n", Divisori[i]);
	}
}
