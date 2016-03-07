;Temporizador;

ATIVA_TEMP	EQU	FFF7h
DURACAO		EQU	FFF6h


;   ;
ESPACO_LINHA	EQU	0Ah
Random		EQU	0000h

;Mascaras;
SP_INICIAL	EQU	FDFFh
INT_MASK_ADDR   EQU     FFFAh    ;Mascara de interrupções, permite definir os vetores de interrupção habilitados, um por cada bit da mascara ;

INT_MASK_INICIAL	EQU	0000000000000010b
INT_MASK        EQU     1000100000000111b ;Interrupções activadas;

Mascara_Alea	EQU	1000000000010110b

;Dispositivos Janela Texto;
IO_READ		EQU	FFFFh
IO_WRITE	EQU	FFFEh
IO_CONTROL	EQU	FFFCh
POS_INI		EQU	0000h
FIM_TEXTO	EQU	'$'


BemVindoPos	EQU	0918h
INICIO		EQU	001Ah
NUM_LINHAS	EQU	0018h   ;24 linhas
INICIO_BICLA	EQU	1827h

Comecou_Jogo	EQU	0000h


;MEMORIAS PARA INTERRUPCOES;
Comeca_Jogo	EQU	0001h
Dir		EQU	0001h






		ORIG	8000h
BemVindo	STR	'Bem-Vindo a Corrida de Bicicleta!',FIM_TEXTO
BemVindo1	STR	'Prima o interruptor I1 para comecar.',FIM_TEXTO
Apaga_Bem	STR	'                                     ',FIM_TEXTO
ASTERISCOS	STR	'***',FIM_TEXTO
Lim1		STR	'+|',FIM_TEXTO
Lim2		STR	'|+',FIM_TEXTO
Bicla		STR	'o|o',FIM_TEXTO
ESPACO		STR	'   ',FIM_TEXTO

;Posicoes das Barreiras;
Inicia_Barreir	WORD	0015h
Primeira_Posic	WORD	0000h
Barreira_1	WORD	0000h
Barreira_2	WORD	0000h
Barreira_3	WORD	0000h
Barreira_4	WORD	0000h
AguardaBarreira	WORD	0005h

; Tabela de interrupcoes
                ORIG    FE00h
INT0            WORD    Esquerda  

                ORIG    FE0Bh
INTB            WORD    Direita 

                ORIG    FE01h
INT1            WORD    Comeca_Jogo_INT  

		ORIG	FE0Fh
INT3		WORD	Temporizador


	ORIG	0000h

	JMP	Inicio


Comeca_Jogo_INT:MOV	M[Comeca_Jogo],R0
		RTI


;VER ISTO!;
Dir_INT:	MOV	M[Dir],R0
		RTI
;VER ISTO!;




BemVind:	PUSH	R1
		PUSH	R2
		MOV	R1,BemVindo
BemVind1:	MOV	R2,M[R1]		
		CMP	R2,FIM_TEXTO
		BR.Z	MudaLinha
		MOV	M[IO_WRITE],R2
		INC	R6
		MOV	M[IO_CONTROL],R6
		INC	R1
		BR	BemVind1	
		
MudaLinha:	MOV	R6,BemVindoPos
		ADD	R6,0200h
		SUB	R6,0001h
		MOV	M[IO_CONTROL],R6
		MOV	R1,BemVindo1
BemVind2:	MOV	R2,M[R1]
		CMP	R2,FIM_TEXTO
		BR.Z	AcabaBemVindo
		MOV	M[IO_WRITE],R2
		INC	R6
		MOV	M[IO_CONTROL],R6
		INC	R1
		BR	BemVind2	

AcabaBemVindo:	POP	R2		
		POP	R1	
		RET






Escreve_Campo:	DSI
		PUSH	R1
		PUSH	R2
		PUSH	R3
		MOV	R2,NUM_LINHAS

Escreve_Linha:	CALL	Escr_Limites
		DEC	R2
		BR.NZ	Escreve_Linha
		BR	Acaba

Acaba:		POP	R3
		POP	R2
		POP	R1
		CALL	EscreveBicla		
		ENI
		RET

EscreveBicla:	MOV	R6,1527h
		MOV	M[IO_CONTROL],R6

		PUSH	R1
		PUSH	R2
		MOV	R1,Bicla
EscreveBicla1:	MOV	R2,M[R1]
		CMP	R2,FIM_TEXTO
		BR.Z	EscreveuBicla
		MOV	M[IO_WRITE],R2
		ADD	R6,0100h
		MOV	M[IO_CONTROL],R6
		INC	R1
		BR	EscreveBicla1

EscreveuBicla:	POP	R2
		POP	R1
		RET



Escr_Limites:	MOV	R1,Lim1
Escr_Limites1:	MOV	R3,M[R1]
		CMP	R3,FIM_TEXTO
		BR.Z	Escr_Lim2
		MOV	M[IO_WRITE],R3
		INC	R6
		MOV	M[IO_CONTROL],R6
		INC	R1
		BR	Escr_Limites1

Escr_Lim2:	ADD	R6,0018h
		MOV	M[IO_CONTROL],R6
		MOV	R1,Lim2
Escr_Limites2:	MOV	R3,M[R1]
		CMP	R3,FIM_TEXTO
		BR.Z	Retorna
		MOV	M[IO_WRITE],R3
		INC	R6
		MOV	M[IO_CONTROL],R6
		INC	R1
		BR	Escr_Limites2


Retorna:	SUB	R6,001Ch
		ADD	R6,0100h
		MOV	M[IO_CONTROL],R6
		RET

Esquerda:	PUSH	R1
		PUSH	R2


		CMP	R6,181Ch
		JMP.Z	EscreveuEsquer


		SUB	R6,0300h
		MOV	M[IO_CONTROL],R6
		MOV	R1,ESPACO
ApagaEsquerda:	MOV	R2,M[R1]
		CMP	R2,FIM_TEXTO
		BR.Z	ApagouEsquerda
		MOV	M[IO_WRITE],R2
		ADD	R6,0100h
		MOV	M[IO_CONTROL],R6
		INC	R1
		BR	ApagaEsquerda



ApagouEsquerda:	SUB	R6,0300h
		SUB	R6,1
		MOV	M[IO_CONTROL],R6
		MOV	R1,Bicla
Esquerda1:	MOV	R2,M[R1]
		CMP	R2,FIM_TEXTO
		BR.Z	EscreveuEsquer
		MOV	M[IO_WRITE],R2
		ADD	R6,0100h
		MOV	M[IO_CONTROL],R6
		INC	R1
		BR	Esquerda1

EscreveuEsquer:	POP	R2
		POP	R1
		RTI





Direita:	PUSH	R1
		PUSH	R2


		CMP	R6,1833h
		JMP.Z	EscreveuDir


		SUB	R6,0300h
		MOV	M[IO_CONTROL],R6
		MOV	R1,ESPACO
ApagaDir:	MOV	R2,M[R1]
		CMP	R2,FIM_TEXTO
		BR.Z	ApagouDir
		MOV	M[IO_WRITE],R2
		ADD	R6,0100h
		MOV	M[IO_CONTROL],R6
		INC	R1
		BR	ApagaDir



ApagouDir:	SUB	R6,0300h
		ADD	R6,1
		MOV	M[IO_CONTROL],R6
		MOV	R1,Bicla
Direita1:	MOV	R2,M[R1]
		CMP	R2,FIM_TEXTO
		BR.Z	EscreveuDir
		MOV	M[IO_WRITE],R2
		ADD	R6,0100h
		MOV	M[IO_CONTROL],R6
		INC	R1
		BR	Direita1

EscreveuDir:	POP	R2
		POP	R1
		RTI


Apaga_Mensagem:	PUSH	R1
		PUSH	R2
		PUSH	R3
		MOV	R3,0001h
		MOV	R6,BemVindoPos
		MOV	M[IO_CONTROL],R6
		MOV	R1,Apaga_Bem

Apaga_BemVind:	MOV	R2,M[R1]		
		CMP	R2,FIM_TEXTO
		BR.Z	Apaga_MudaLinha
		MOV	M[IO_WRITE],R2
		INC	R6
		MOV	M[IO_CONTROL],R6
		INC	R1
		BR	Apaga_BemVind	
		
Apaga_MudaLinha:MOV	R6,BemVindoPos
		ADD	R6,0200h
		SUB	R6,0001h
		MOV	M[IO_CONTROL],R6
		MOV	R1,Apaga_Bem
		CMP	R3,R0

Apaga_BemVind1:	MOV	R2,M[R1]
		CMP	R2,FIM_TEXTO
		BR.Z	ApagaBemVindo
		MOV	M[IO_WRITE],R2
		INC	R6
		MOV	M[IO_CONTROL],R6
		INC	R1
		BR	Apaga_BemVind1

ApagaBemVindo:	POP	R3
		POP	R2		
		POP	R1	
		RET





Temporizador:	PUSH	R1
		PUSH	R2
		PUSH	R5
		
		
		
;1 barreira;
		MOV	R5,M[Barreira_1]
		MOV	M[Primeira_Posic],R5
		SHR	R5,8
		CMP	R5,R0
		CALL.Z	EscBarreira1
		CALL	ApagaEscreve
		MOV	R5,M[Primeira_Posic]
		MOV	M[Barreira_1],R5

;2 barreira;
		MOV	R5,M[Barreira_2]
		MOV	M[Primeira_Posic],R5
		SHR	R5,8
		CMP	R5,R0
		CALL.Z	EscBarreira1
		CALL	ApagaEscreve
		MOV	R5,M[Primeira_Posic]
		MOV	M[Barreira_2],R5





		JMP	AcabaTemp

ApagaEscreve:	PUSH	R1
		PUSH	R2
		PUSH	R5
		MOV	R5,M[Primeira_Posic]
		SUB	R5,0100h
		MOV	M[IO_CONTROL],R5
		MOV	R1,ESPACO
		
ApagaBarr:	MOV	R2,M[R1]
		CMP	R2,FIM_TEXTO
		BR.Z	ApagouBarr
		MOV	M[IO_WRITE],R2
		INC	R5
		MOV	M[IO_CONTROL],R5
		INC	R1
		BR	ApagaBarr

ApagouBarr:	ADD	R5,0100h
		SUB	R5,3
		MOV	M[Primeira_Posic],R5
		CALL	EscBarreira1
		POP	R5
		POP	R2
		POP	R1
		RET







EscBarreira1:	PUSH	R1
		PUSH	R2
		PUSH	R5
		MOV	R5,M[Primeira_Posic]
		MOV	M[IO_CONTROL],R5
		MOV	R1,ASTERISCOS

Barreira1:	MOV	R2,M[R1]
		CMP	R2,FIM_TEXTO
		BR.Z	AcabouBarr1
		MOV	M[IO_WRITE],R2
		INC	R5
		MOV	M[IO_CONTROL],R5
		INC	R1		
		BR	Barreira1
		

AcabouBarr1:	ADD	R5,0100h
		SUB	R5,3
		MOV	M[Primeira_Posic],R5
		POP	R5
		POP	R2
		POP	R1	
		RET
		

AcabaTemp:	MOV	R1,0005h		
		MOV	M[DURACAO],R1
		MOV	R1,0001h
		MOV	M[ATIVA_TEMP],R1
		POP	R5
		POP	R2
		POP	R1

		RTI				


	








Inicio:		MOV	R7,SP_INICIAL
		MOV	SP,R7

	
        	MOV     R7, INT_MASK_INICIAL
        	MOV     M[INT_MASK_ADDR], R7

		MOV	R6,IO_READ
		MOV	M[IO_CONTROL],R6
		MOV	R6,BemVindoPos
		MOV	M[IO_CONTROL],R6

		CALL	BemVind
		ENI
		
		JMP	Infinito


IniciaJogo:	CALL	Apaga_Mensagem
		MOV	R6,IO_READ
		MOV	M[IO_CONTROL],R6
		MOV	R6,INICIO
		MOV	M[IO_CONTROL],R6

		CALL	Escreve_Campo

        	MOV     R7, INT_MASK
        	MOV     M[INT_MASK_ADDR], R7

		PUSH	R1
		MOV	R1,0001h
		MOV	M[Comeca_Jogo],R1
		POP	R1	
		
		
		CALL	Aleatorio1st
		PUSH	R5
		MOV	R5,M[Primeira_Posic]	
		ADD	R5,001Ch
		MOV	M[Barreira_1],R5
		MOV	M[IO_CONTROL],R5

		ADD	R5,4
		MOV	M[Barreira_2],R5

		ADD	R5,4
		MOV	M[Barreira_3],R5


		POP	R5


		MOV	R1,0005h		
		MOV	M[DURACAO],R1
		MOV	R1,0001h
		MOV	M[ATIVA_TEMP],R1

		RET


Aleatorio1st:	PUSH	R5
		MOV	R5,M[Random]
Aleatorio:	PUSH	R1
		PUSH	R2
		PUSH	R6
		CMP	R5,R0
		BR.NZ	Alea1
		ROR	R5,0001h
	
		
		MOV	R1,0015h
		MOV	R2,R5
		DIV	R2,R1

		MOV	R5,R1
		MOV	M[Barreira_1],R5
	
	
		POP	R6
		POP	R2
		POP	R1
		POP	R5
		RET

;DIVIDIR POR 0015;
Alea1:		XOR	R5,M[Mascara_Alea]
		ROR	R5,0001h
		MOV	R6,R5
		SHL	R6,8
		SHR	R6,8
		MOV	R6,R5
	
		MOV	R1,0015h
		MOV	R2,R5
		DIV	R2,R1
		MOV	R5,R1
		MOV	M[Primeira_Posic],R5
		
		POP	R6
		POP	R2
		POP	R1
		POP	R5

		RET


Infinito:	CMP	M[Comeca_Jogo],R0
		CALL.Z	IniciaJogo
		INC	M[Random]
		BR	Infinito
