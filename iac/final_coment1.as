;Grupo: 38               ;
;Turno: Quinta-Feira 8:00;
;                        ;
;Gonçalo Fialho nº79112  ;
;Gonçalo Mendes nº79222  ;
;Luís Borges    nº78349  ;

;____________,
;Temporizador;
;____________;
ATIVA_TEMP	EQU	FFF7h
DURACAO		EQU	FFF6h

;______;
; LEDS ;
;______;
LEDS		EQU	FFF8h

;_______;
;  LCD  ;
;_______;
LCD_CONTROLO	EQU	FFF4h
LCD_ESCRITA	EQU	FFF5h
LCD_MASK	EQU	1000000000000000b

;Mascaras;
SP_INICIAL	EQU	FDFFh
INT_MASK_ADDR   EQU     FFFAh    ;Mascara de interrupções, permite definir os vetores de interrupção habilitados, um por cada bit da mascara ;

INT_MASK_INICIAL	EQU	0000000000000010b
INT_MASK        EQU     1000110000000101b ;Interrupções activadas;


Mascara_Alea	EQU	1000000000010110b

;_________________________,
;Dispositivos Janela Texto;
;_________________________;
IO_READ		EQU	FFFFh
IO_WRITE	EQU	FFFEh
IO_CONTROL	EQU	FFFCh
POS_INI		EQU	0000h
FIM_TEXTO	EQU	'$'


;_________,
; Display ;
;_________;
IO_DISPLAY1      EQU     FFF0h 
IO_DISPLAY2      EQU     FFF1h 
IO_DISPLAY3      EQU     FFF2h 
IO_DISPLAY4      EQU     FFF3h 


BemVindoPos	EQU	0918h ;Posicao da mensagem Bem-Vindo
INICIO		EQU	001Ah ;Posicao da Primeira Barreira
NUM_LINHAS	EQU	0018h ;24 linhas



;MEMORIAS PARA INTERRUPCOES;
Comeca_Jogo	EQU	0001h


Random		EQU	0000h ;Constante Random


;Variaveis;
		ORIG	8000h
BemVindo	STR	'Bem-Vindo a Corrida de Bicicleta!',FIM_TEXTO
BemVindo1	STR	'Prima o interruptor I1 para comecar.',FIM_TEXTO
Apaga_Bem	STR	'                                               ',FIM_TEXTO   ;Este texto apaga as mensagens e a Janela de jogo
ASTERISCOS	STR	'***',FIM_TEXTO
Lim1		STR	'+|',FIM_TEXTO
Lim2		STR	'|+',FIM_TEXTO
Bicla		STR	'o|o',FIM_TEXTO
ESPACO		STR	'   ',FIM_TEXTO
FimdoJogo1	STR	'Fim do Jogo',FIM_TEXTO
FimdoJogo2	STR	'Prima o interruptor I1 para recomecar',FIM_TEXTO
LCD1		STR	'Distancia:0000m',FIM_TEXTO
LCD2		STR	'Maximo:       m',FIM_TEXTO

LCDPAUSA1	STR	'     PAUSA     ',FIM_TEXTO
LCDPAUSA2	STR	'               ',FIM_TEXTO

Apaga_FimJogo	WORD	001Ah  ;Posicao da primeira Barreira

Valor_ASCII_LCD_1	WORD	0030h	; Corresponde ao numero 0
Valor_ASCII_LCD_2	WORD	0030h
Valor_ASCII_LCD_3	WORD	0030h
Valor_ASCII_LCD_4	WORD	0030h

Ultima_Pontuacao_1	WORD	0030h
Ultima_Pontuacao_2	WORD	0030h
Ultima_Pontuacao_3	WORD	0030h
Ultima_Pontuacao_4	WORD	0030h

Distancia_Percorrida	WORD	0000h
Distancia_Percorrida_MAX 	WORD	0000h

;____________,
; Constantes ,
;____________;
Soma2Linhas	WORD	0200h
Numero1		WORD	0001h
Numero_0100h	WORD	0100h
Numero_002Fh	WORD	002Fh	
Numero_0019h	WORD	0019h
Numero_1527h	WORD	1527h
Numero_0018h	WORD	0018h
Numero_001Ch	WORD	001Ch
Numero_181Ch	WORD	181Ch
Numero_0300h	WORD	0300h
Numero_0004h	WORD	0004h
Numero_1833h	WORD	1833h
Numero_9000h	WORD	9000h
Numero_0030h	WORD	0030h
Numero_F000h	WORD	F000h
Numero_FF00h	WORD	FF00h
Numero_0008h	WORD	0008h
Numero_FFF0h	WORD	FFF0h
Numero_0006h	WORD	0006h
Numero_000Ch	WORD	000Ch
Numero_FFFFh	WORD	FFFFh
Numero_003Ah	WORD	003Ah
Numero_800Dh	WORD	800Dh
Numero_0002h	WORD	0002h
Numero_0003h	WORD	0003h
Numero_0010h	WORD	0010h
Numero_801Dh	WORD	801Dh
Numero_0014h	WORD	0014h
Numero_0012h	WORD	0012h
Numero_0924h	WORD	0924h
Numero_0016h	WORD	0016h
Numero_0005h	WORD	0005h

;______________________,
;Posicoes das Barreiras;
;______________________;

Inicia_Barreir	WORD	0012h ;Utilizado para verificar quantas barreiras existem na janela;
Primeira_Posic	WORD	0000h
Barreira_1	WORD	0000h
Barreira_2	WORD	0000h
Barreira_3	WORD	0000h
Barreira_4	WORD	0000h

;_____________________,
;Displays constantes  ;
;_____________________;
Barreiras_Ultr	WORD	0000h
Barreiras_90	WORD	0000h
Barreiras_900	WORD	0000h
Barreiras_9000	WORD	0000h


;_____________,
; Colisoes    ,
;_____________;

PosicColis	WORD	0000h
HouveColisao	WORD	0001h

;_____________,
;Nível de Jogo;
;_____________;

ValorNivel	WORD	0001h
ValorTemp	WORD	0005h
ValorLeds	WORD	0000h

;_________________________,
;Memorias para as interrup;
;_________________________;

Temporizador_Mem	WORD	0001h

Esquerda_Mem		WORD	0001h

Direita_Mem		WORD	0001h

Pausa_Mem		WORD	0001h

Turbo_Mem		WORD	0001h

;______________________,
;Tabela Interrupções   ;
;______________________;
                ORIG    FE00h
INT0            WORD    Esquerda_INT 

                ORIG    FE0Bh
INTB            WORD    Direita_INT 

                ORIG    FE01h
INT1            WORD    Comeca_Jogo_INT  

		ORIG	FE0Fh
INT3		WORD	Temporizador_INT

                ORIG    FE0Ah
INTA            WORD    Pausa_INT 

		ORIG	FE02h
INT2		WORD	Turbo_INT


	ORIG	0000h

	JMP	Inicio



ApagaJanela:	PUSH	R1   ;apaga o campo de jogo
		PUSH	R2
		PUSH	R3


		MOV	R3,M[Apaga_FimJogo]	
Salto:		MOV	M[IO_CONTROL],R3
		

		MOV	R1,Apaga_Bem
ApagaJanela1:	MOV	R2,M[R1]		
		CMP	R2,FIM_TEXTO
		BR.Z	AcabouApagar
		MOV	M[IO_WRITE],R2
		INC	R3
		MOV	M[IO_CONTROL],R3
		INC	R1
		BR	ApagaJanela1	

AcabouApagar:	ADD	R3,M[Numero_0100h]
		SUB	R3,M[Numero_002Fh]
		MOV	R1,R3
		SHR	R1,8
		CMP	R1,M[Numero_0019h]
		BR.Z	TerminouApag

		JMP	Salto


TerminouApag:	POP	R3
		POP	R2
		POP	R1
		RET



Turbo_INT:	CMP	M[Turbo_Mem],R0  ;Ativa Turbo
		BR.NZ	AtivaTurbo
		PUSH	R1
		MOV	R1,M[Numero1]
		MOV	M[Turbo_Mem],R1
		POP	R1
		RTI

AtivaTurbo:	MOV	M[Turbo_Mem],R0
		RTI



Pausa_INT:	CMP	M[Pausa_Mem],R0 ; Ativa/Desativa Pausa
		BR.Z	Pausa_a_1

		MOV	M[Pausa_Mem],R0
		BR	TerminaPausa

Pausa_a_1:	INC	M[Pausa_Mem]

TerminaPausa:	RTI	


Comeca_Jogo_INT:MOV	M[Comeca_Jogo],R0 ;Começa jogo
		RTI


Temporizador_INT:	MOV	M[Temporizador_Mem],R0 ;Temporizador Ativo
			RTI	

Esquerda_INT:	MOV	M[Esquerda_Mem],R0 ; I0 Ativo
		RTI


Direita_INT:	MOV	M[Direita_Mem],R0 ; IB Ativo
		RTI






BemVind:	PUSH	R1
		PUSH	R2
		MOV	R1,BemVindo
BemVind1:	MOV	R2,M[R1]		;Escreve 1º Mensagem-Bemvindo
		CMP	R2,FIM_TEXTO
		BR.Z	MudaLinha
		MOV	M[IO_WRITE],R2
		INC	R6
		MOV	M[IO_CONTROL],R6
		INC	R1
		BR	BemVind1	
		
MudaLinha:	MOV	R6,BemVindoPos		;Espaçamento de 1 linha
		ADD	R6,M[Soma2Linhas]
		SUB	R6,M[Numero1]
		MOV	M[IO_CONTROL],R6
		MOV	R1,BemVindo1
BemVind2:	MOV	R2,M[R1]		;Escreve 2º Mensagem-Bemvindo
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






Escreve_Campo:	DSI		;Escreve o Campo de Jogo
		PUSH	R1
		PUSH	R2
		PUSH	R3
		MOV	R2,NUM_LINHAS

Escreve_Linha:	CALL	Escr_Limites	;Escreve uma linha de jogo
		DEC	R2
		BR.NZ	Escreve_Linha ;Enquanto o campo nao estiver concluido continua a escrever
		BR	Acaba

Acaba:		POP	R3
		POP	R2
		POP	R1
		CALL	EscreveBicla		   ;Escreve Bicicleta
		ENI
		RET

EscreveBicla:	MOV	R6,M[Numero_1527h]	;Posiçao central da bicicleta
		MOV	M[IO_CONTROL],R6

		PUSH	R1
		PUSH	R2
		MOV	R1,Bicla
EscreveBicla1:	MOV	R2,M[R1]
		CMP	R2,FIM_TEXTO
		BR.Z	EscreveuBicla
		MOV	M[IO_WRITE],R2
		ADD	R6,M[Numero_0100h]	;Proxima Linha
		MOV	M[IO_CONTROL],R6
		INC	R1
		BR	EscreveBicla1

EscreveuBicla:	POP	R2
		POP	R1
		RET



Escr_Limites:	MOV	R1,Lim1		;Esta rotina so uma linha os Limites
Escr_Limites1:	MOV	R3,M[R1]	;Escreve Limite Esquerdo
		CMP	R3,FIM_TEXTO
		BR.Z	Escr_Lim2
		MOV	M[IO_WRITE],R3
		INC	R6
		MOV	M[IO_CONTROL],R6
		INC	R1
		BR	Escr_Limites1

Escr_Lim2:	ADD	R6,M[Numero_0018h]	;Tamanho do campo (colunas)
		MOV	M[IO_CONTROL],R6
		MOV	R1,Lim2
Escr_Limites2:	MOV	R3,M[R1]	;Escreve Limite Esquerdo
		CMP	R3,FIM_TEXTO
		BR.Z	Retorna
		MOV	M[IO_WRITE],R3
		INC	R6
		MOV	M[IO_CONTROL],R6
		INC	R1
		BR	Escr_Limites2


Retorna:	SUB	R6,M[Numero_001Ch]	;Coloca em R6 a proxima linha que deve ser escrita
		ADD	R6,M[Numero_0100h]
		MOV	M[IO_CONTROL],R6
		RET

Esquerda:	PUSH	R1       ;Escreve a bicicleta uma posicao para a esquerda
		PUSH	R2

		MOV	R1,M[Numero1]
		MOV	M[Esquerda_Mem],R1

		CMP	R6,M[Numero_181Ch]
		JMP.Z	EscreveuEsquer


		SUB	R6,M[Numero_0300h]
		MOV	M[IO_CONTROL],R6
		MOV	R1,ESPACO
ApagaEsquerda:	MOV	R2,M[R1]	;Apaga posiçao anterior da bicicleta
		CMP	R2,FIM_TEXTO
		BR.Z	ApagouEsquerda
		MOV	M[IO_WRITE],R2
		ADD	R6,M[Numero_0100h]
		MOV	M[IO_CONTROL],R6
		INC	R1
		BR	ApagaEsquerda



ApagouEsquerda:	SUB	R6,M[Numero_0300h]	; Escreve a nova posição da bicicleta
		SUB	R6,1
		MOV	M[IO_CONTROL],R6
		MOV	R1,Bicla
Esquerda1:	MOV	R2,M[R1]
		CMP	R2,FIM_TEXTO
		BR.Z	EscreveuEsquer

		CALL	MovBiclaColis
	
		MOV	M[IO_WRITE],R2
		ADD	R6,M[Numero_0100h]
		CALL	MovBiclaColis		;verifica se existe colisao
		MOV	M[IO_CONTROL],R6
		INC	R1
		BR	Esquerda1

EscreveuEsquer:	POP	R2
		POP	R1
		RET





Direita:	PUSH	R1		;Escreve a bicicleta uma posicao para a direita
		PUSH	R2

		MOV	R1,M[Numero1]
		MOV	M[Direita_Mem],R1


		CMP	R6,M[Numero_1833h]
		JMP.Z	EscreveuDir


		SUB	R6,M[Numero_0300h]
		MOV	M[IO_CONTROL],R6
		MOV	R1,ESPACO
ApagaDir:	MOV	R2,M[R1]	;Apaga posiçao anterior da bicicleta
		CMP	R2,FIM_TEXTO
		BR.Z	ApagouDir
		MOV	M[IO_WRITE],R2
		ADD	R6,M[Numero_0100h]
		MOV	M[IO_CONTROL],R6
		INC	R1
		BR	ApagaDir



ApagouDir:	SUB	R6,M[Numero_0300h]
		ADD	R6,1
		MOV	M[IO_CONTROL],R6
		MOV	R1,Bicla
Direita1:	MOV	R2,M[R1]	; Escreve a nova posição da bicicleta
		CMP	R2,FIM_TEXTO
		BR.Z	EscreveuDir
		MOV	M[IO_WRITE],R2
		ADD	R6,M[Numero_0100h]
		CALL	MovBiclaColis	;verifica se existe colisao
		MOV	M[IO_CONTROL],R6
		INC	R1
		BR	Direita1



EscreveuDir:	POP	R2
		POP	R1
		RET





MovBiclaColis:	PUSH	R1		;Verifica todos os locais possíveis de ocorrer colisão
		PUSH	R2
		PUSH	R3
		
;1;
		MOV	R3,M[Barreira_1]
	
		CMP	R3,R6
		CALL.Z	GAMEOVER
		
		ADD	R3,2
		CMP	R3,R2
		CALL.Z	GAMEOVER


;2;
		MOV	R3,M[Barreira_2]
	
		CMP	R3,R6
		CALL.Z	GAMEOVER
		
		ADD	R3,2
		CMP	R3,R6
		CALL.Z	GAMEOVER

;4;
		MOV	R3,M[Barreira_3]
	
		CMP	R3,R6
		CALL.Z	GAMEOVER
		
		ADD	R3,2
		CMP	R3,R6
		CALL.Z	GAMEOVER
		

;4;
		MOV	R3,M[Barreira_3]
	
		CMP	R3,R6
		CALL.Z	GAMEOVER
		
		ADD	R3,2
		CMP	R3,R6
		CALL.Z	GAMEOVER

		POP	R3
		POP	R2
		POP	R1
		RET
		





Apaga_Mensagem:	PUSH	R1		;Apaga as mensagens de BemVindo e Termina Jogo.
		PUSH	R2
		PUSH	R3
		MOV	R3,M[Numero1]
		MOV	R6,BemVindoPos 
		MOV	M[IO_CONTROL],R6
		MOV	R1,Apaga_Bem

Apaga_BemVind:	MOV	R2,M[R1]		;Escreve espaços por cima da 1ºmensagem
		CMP	R2,FIM_TEXTO
		BR.Z	Apaga_MudaLinha
		MOV	M[IO_WRITE],R2
		INC	R6
		MOV	M[IO_CONTROL],R6
		INC	R1
		BR	Apaga_BemVind	
		
Apaga_MudaLinha:MOV	R6,BemVindoPos		;Soma +1 linha
		ADD	R6,M[Soma2Linhas]
		SUB	R6,M[Numero1]
		MOV	M[IO_CONTROL],R6
		MOV	R1,Apaga_Bem
		CMP	R3,R0

Apaga_BemVind1:	MOV	R2,M[R1]		;Escreve espaços por cima da 2ºmensagem
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






Soma_Display:	PUSH	R1	; Incrementa o Display de 7 segmentos
		PUSH	R2
		MOV	R2,M[Barreiras_Ultr]

		INC	R2	
		CMP	M[Barreiras_90],R0	;verifica se chegou a 9
		BR.NZ	Naoaumentalvl
		CMP	R2,M[Numero_0004h]	;Se passou 4 obs. muda para nivel2
		CALL.Z	Nivel2

		
		CMP	R2,M[Numero_0008h]		;Se passou 8 obs. muda para nivel3
		CALL.Z	Nivel3


Naoaumentalvl:	MOV	R2,M[Barreiras_Ultr]
		SHL	R2,12
		CMP	R2,M[Numero_9000h]	;Verifica se chegou a 9
		BR.Z	Soma_Display1		
	

		MOV	R1,IO_DISPLAY1		; Incrementa Display1
		MOV	R2,M[Barreiras_Ultr]
		INC	R2
		MOV	M[Barreiras_Ultr],R2
		MOV	M[R1],R2

		JMP	Termina_Display

Soma_Display1:	MOV	R2,M[Barreiras_90]
		SHL	R2,12
		CMP	R2,M[Numero_9000h]
		BR.Z	Soma_Display2

		MOV	R1,IO_DISPLAY2
		MOV	R2,M[Barreiras_90]
		INC	R2
		MOV	M[Barreiras_90],R2	;Incrementa Display2
		MOV	M[R1],R2
		MOV	R1,IO_DISPLAY1
		MOV	M[Barreiras_Ultr],R0	;Coloca Display1 a 0
		MOV	M[R1],R0
		JMP	Termina_Display

Soma_Display2:	MOV	R2,M[Barreiras_900]
		SHL	R2,12
		CMP	R2,M[Numero_9000h]
		BR.Z	Soma_Display3
  
		MOV	R1,IO_DISPLAY3
		MOV	R2,M[Barreiras_900]	;Incrementa Display3
		INC	R2
		MOV	M[Barreiras_900],R2	
		MOV	M[R1],R2
		MOV	R1,IO_DISPLAY2
		MOV	M[Barreiras_90],R0	;Coloca Display2 a 0
		MOV	M[R1],R0
		MOV	R1,IO_DISPLAY1
		MOV	M[Barreiras_Ultr],R0	;Coloca Display1 a 0
		MOV	M[R1],R0
		JMP	Termina_Display
		
Soma_Display3:	MOV	R1,IO_DISPLAY4
		MOV	R2,M[Barreiras_9000]	;Incrementa Display4
		INC	R2
		MOV	M[Barreiras_9000],R2
		MOV	M[R1],R2
		
		MOV	R1,IO_DISPLAY3
		MOV	M[Barreiras_900],R0	;Coloca Display3 a 0
		MOV	M[R1],R0
		
		MOV	R1,IO_DISPLAY2		
		MOV	M[Barreiras_90],R0	;Coloca Display2 a 0
		MOV	M[R1],R0
		MOV	R1,IO_DISPLAY1
		MOV	M[Barreiras_Ultr],R0	;Coloca Display1 a 0
		MOV	M[R1],R0
		


Termina_Display:POP	R2
		POP	R1
		RET

Nivel2:		PUSH	R1
		MOV	R1,M[Numero_FF00h]	;Coloca nos Leds FF00h correspondente ao lvl2
		MOV	M[LEDS],R1
		MOV	M[ValorLeds],R1
		INC	M[ValorNivel]	;Coloca numa Memoria o Valor do Nivel(2)
		POP	R1
		RET

Nivel3:		PUSH	R1
		MOV	R1,M[Numero_FFF0h];Coloca nos Leds FFF0h correspondente ao lvl3
		MOV	M[LEDS],R1
		MOV	M[ValorLeds],R1
		INC	M[ValorNivel];Coloca numa Memoria o Valor do Nivel(3)
		POP	R1
		RET



Alea_Barr1:	PUSH	R1			;Gera um valor aleatorio para a Barreira_1 e guarda o respetivo valor
		PUSH	R2
		
		MOV	R2,M[Barreira_1]
		MOV	R5,R2
		SUB	R5,M[Numero_0100h]
		MOV	M[IO_CONTROL],R5
		
		
		MOV	R1,ESPACO
Apaga_Alea1:	MOV	R2,M[R1]	;Apaga a Barreira que se encontra na última linha do campo
		CMP	R2,FIM_TEXTO
		BR.Z	Apagou_Alea1
		
		MOV	M[PosicColis],R5
		CALL	Ver_Colisao
		MOV	M[IO_WRITE],R2
		INC	R5
		MOV	M[IO_CONTROL],R5
		INC	R1
		BR	Apaga_Alea1
		
		
Apagou_Alea1:	CALL	Soma_Display	;Soma o Display de 7 segmentos
		CALL	Aleatorio1st	;Gera Aleatório para a Barreira_1
		MOV	R1,M[Random]	
		ADD	R1,M[Numero_001Ch]	;Para ficar na zona da pista soma-se 001Ch
		MOV	M[Barreira_1],R1
		
		POP	R2
		POP	R1
		RET

Alea_Barr2:	PUSH	R1     ;Gera um valor aleatorio para a Barreira_2 e guarda o respetivo valor
		PUSH	R2
		
		MOV	R2,M[Barreira_2]
		MOV	R5,R2
		SUB	R5,M[Numero_0100h]
		MOV	M[IO_CONTROL],R5
		
		
		MOV	R1,ESPACO
Apaga_Alea2:	MOV	R2,M[R1]	;Apaga a Barreira que se encontra na última linha do campo
		CMP	R2,FIM_TEXTO
		BR.Z	Apagou_Alea2
		
		MOV	M[PosicColis],R5
		CALL	Ver_Colisao
		MOV	M[IO_WRITE],R2
		INC	R5
		MOV	M[IO_CONTROL],R5
		INC	R1
		BR	Apaga_Alea2
		
		
Apagou_Alea2:	CALL	Soma_Display	;Soma o Display de 7 segmentos
		CALL	Aleatorio1st	;Gera Aleatório para a Barreira_2
		MOV	R1,M[Random]
		ADD	R1,M[Numero_001Ch]
		MOV	M[Barreira_2],R1
		POP	R2
		POP	R1
		RET

Alea_Barr3:	PUSH	R1         ;Gera um valor aleatorio para a Barreira_3 e guarda o respetivo valor
		PUSH	R2
		
		MOV	R2,M[Barreira_3]
		MOV	R5,R2
		SUB	R5,M[Numero_0100h]
		MOV	M[IO_CONTROL],R5
		
		
		MOV	R1,ESPACO
Apaga_Alea3:	MOV	R2,M[R1]	;Apaga a Barreira que se encontra na última linha do campo
		CMP	R2,FIM_TEXTO
		BR.Z	Apagou_Alea3
		
		MOV	M[PosicColis],R5
		CALL	Ver_Colisao	;Verifica Colisao
		MOV	M[IO_WRITE],R2
		INC	R5
		MOV	M[IO_CONTROL],R5
		INC	R1
		BR	Apaga_Alea3
		
		
Apagou_Alea3:	CALL	Soma_Display	;Soma o Display de 7 segmentos
		CALL	Aleatorio1st	;Gera Aleatório para a Barreira_3
		MOV	R1,M[Random]
		ADD	R1,M[Numero_001Ch] ;Para ficar na zona da pista soma-se 001Ch
		MOV	M[Barreira_3],R1
		POP	R2
		POP	R1
		RET

Alea_Barr4:	PUSH	R1     ;Gera um valor aleatorio para a Barreira_4 e guarda o respetivo valor
		PUSH	R2
		
		MOV	R2,M[Barreira_4]
		MOV	R5,R2
		SUB	R5,M[Numero_0100h]
		MOV	M[IO_CONTROL],R5
		
		
		MOV	R1,ESPACO
Apaga_Alea4:	MOV	R2,M[R1]	;Apaga a Barreira que se encontra na última linha do campo
		CMP	R2,FIM_TEXTO
		BR.Z	Apagou_Alea4
		
		MOV	M[PosicColis],R5
		CALL	Ver_Colisao
		MOV	M[IO_WRITE],R2
		INC	R5
		MOV	M[IO_CONTROL],R5
		INC	R1
		BR	Apaga_Alea4
		
		
Apagou_Alea4:	CALL	Soma_Display	;Soma o Display de 7 segmentos
		CALL	Aleatorio1st	;Gera Aleatório para a Barreira_4
		MOV	R1,M[Random]
		ADD	R1,M[Numero_001Ch]
		MOV	M[Barreira_4],R1
		POP	R2
		POP	R1
		RET

Temporizador:	PUSH	R1
		PUSH	R2
		PUSH	R5

		CMP	M[Inicia_Barreir],R0	;Verifica se pode criar 4º Barreira
		BR.Z	Barreira4
		
		
		MOV	R1,M[Numero_0006h]		;Verifica se pode criar 3º Barreira
		CMP	M[Inicia_Barreir],R1
		BR.Z	Barreira3
		
		MOV	R1,M[Numero_000Ch]		;Verifica se pode criar 2º Barreira
		CMP	M[Inicia_Barreir],R1
		BR.Z	Barreira2
		JMP	EscritBarreira1	

Barreira4:	CALL	Aleatorio1st		;Só é realizada 1vez 
		MOV	R1,M[Random]
		ADD	R1,M[Numero_001Ch]
		MOV	M[Barreira_4],R1
		BR	EscritBarreira1


Barreira3:	CALL	Aleatorio1st		;Só é realizada 1vez
		MOV	R1,M[Random]
		ADD	R1,M[Numero_001Ch]
		MOV	M[Barreira_3],R1
		BR	EscritBarreira1


Barreira2:	CALL	Aleatorio1st		;Só é realizada 1vez
		MOV	R1,M[Random]
		ADD	R1,M[Numero_001Ch]
		MOV	M[Barreira_2],R1
		

		
;1 barreira;
EscritBarreira1:MOV	R5,M[Barreira_1]  ;Realiza testes em Barreira_1 e escreve a sua nova posição
		SHR	R5,8
		CMP	R5,M[Numero_0018h]	;Se a 1º barreira estiver na ultima linha cria novo valor para a mesma
		CALL.Z	Alea_Barr1
		MOV	R5,M[Barreira_1]				

		MOV	M[Primeira_Posic],R5
		SHR	R5,8
		CMP	R5,R0
		CALL.Z	EscBarreira1		;Se for 1º posição só escreve e não apaga pos. anterior

		MOV	R1,M[Numero1]
		MOV	M[ATIVA_TEMP],R1
		CALL	ApagaEscreve
		MOV	R5,M[Primeira_Posic]
		MOV	M[Barreira_1],R5


		CMP	M[Barreira_2],R0
		JMP.Z	TerminaTemp
		


;2 barreira;
		MOV	R5,M[Barreira_2]	;Realiza testes em Barreira_2 e escreve a sua nova posição
		SHR	R5,8
		CMP	R5,M[Numero_0018h]	;Se a 2º barreira estiver na ultima linha cria novo valor para a mesma
		CALL.Z	Alea_Barr2
		MOV	R5,M[Barreira_2]

		MOV	M[Primeira_Posic],R5
		SHR	R5,8
		CMP	R5,R0
		CALL.Z	EscBarreira1		;Se for 1º posição só escreve e não apaga pos. anterior
		CALL	ApagaEscreve
		MOV	R5,M[Primeira_Posic]
		MOV	M[Barreira_2],R5
		
		CMP	M[Barreira_3],R0
		JMP.Z	TerminaTemp

;3 barreira;
		MOV	R5,M[Barreira_3] 	;Realiza testes em Barreira_3 e escreve a sua nova posição
		SHR	R5,8
		CMP	R5,M[Numero_0018h]	;Se a 3º barreira estiver na ultima linha cria novo valor para a mesma
		CALL.Z	Alea_Barr3
		MOV	R5,M[Barreira_3]

		MOV	M[Primeira_Posic],R5
		SHR	R5,8
		CMP	R5,R0
		CALL.Z	EscBarreira1		;Se for 1º posição só escreve e não apaga pos. anterior
		CALL	ApagaEscreve
		MOV	R5,M[Primeira_Posic]
		MOV	M[Barreira_3],R5
		
		CMP	M[Barreira_4],R0
		JMP.Z	TerminaTemp


;4 barreira;
		MOV	R5,M[Barreira_4]  ;Realiza testes em Barreira_4 e escreve a sua nova posição
		SHR	R5,8
		CMP	R5,M[Numero_0018h]	;Se a 4º barreira estiver na ultima linha cria novo valor para a mesma
		CALL.Z	Alea_Barr4
		MOV	R5,M[Barreira_4]

		MOV	M[Primeira_Posic],R5
		SHR	R5,8
		CMP	R5,R0
		CALL.Z	EscBarreira1		;Se for 1º posição só escreve e não apaga pos. anterior
		CALL	ApagaEscreve
		MOV	R5,M[Primeira_Posic]
		MOV	M[Barreira_4],R5
		
		

TerminaTemp:	JMP	AcabaTemp

ApagaEscreve:	PUSH	R1			;Esta rotina Apaga a pos. Anterior da Bicicleta e escreve a nova
		PUSH	R2
		PUSH	R5
		MOV	R5,M[Primeira_Posic]
		SUB	R5,M[Numero_0100h]
		MOV	M[IO_CONTROL],R5
		MOV	R1,ESPACO
		
ApagaBarr:	MOV	R2,M[R1]		;Apaga a Barreira
		CMP	R2,FIM_TEXTO
		BR.Z	ApagouBarr
		
		MOV	M[PosicColis],R5
		CALL	Ver_Colisao	

		MOV	M[IO_WRITE],R2
		INC	R5
		MOV	M[IO_CONTROL],R5
		INC	R1
		BR	ApagaBarr

ApagouBarr:	ADD	R5,M[Numero_0100h]
		SUB	R5,3
		MOV	M[Primeira_Posic],R5
		
		SHR	R5,8
		CMP	R5,M[Numero_0019h]
		CALL.NZ	EscBarreira1	;Escreve a nova Barreira

		POP	R5
		POP	R2
		POP	R1
		RET



EscBarreira1:	PUSH	R1 ; Escreve Barreira;
		PUSH	R2
		PUSH	R5
		MOV	R5,M[Primeira_Posic]
		MOV	M[IO_CONTROL],R5
		MOV	R1,ASTERISCOS

Barreira1:	MOV	R2,M[R1]	;Escreve Barreira
		CMP	R2,FIM_TEXTO		
		BR.Z	AcabouBarr1

		MOV	M[PosicColis],R5
		CALL	Ver_Colisao_Esc


		MOV	M[IO_WRITE],R2
		INC	R5
		MOV	M[IO_CONTROL],R5
		INC	R1		
		BR	Barreira1
		

AcabouBarr1:	ADD	R5,M[Numero_0100h] ;Terminou de Escrever a Barreira
		SUB	R5,3
		MOV	M[Primeira_Posic],R5
		POP	R5
		POP	R2
		POP	R1	
		RET


Ver_Colisao_Esc:PUSH	R1  ;Realiza CMP's para verificar se existiram colisões
		PUSH	R2

		MOV	R1,M[PosicColis]	
		MOV	R2,R6

		SUB	R2,M[Numero_0300h]
		CMP	R1,R2
		CALL.Z	GAMEOVER

		ADD	R2,M[Numero_0100h]	
		CMP	R1,R2
		CALL.Z	GAMEOVER
		
		ADD	R2,M[Numero_0100h]
		CMP	R1,R2
		CALL.Z	GAMEOVER
	
		POP	R2
		POP	R1
		RET

	
AcabaTemp:	CALL	VerificaNivel	;Atualiza o nivel de jogo
		MOV	R1,M[ValorTemp]

		MOV	M[DURACAO],R1
		MOV	R1,M[Numero1]
		MOV	M[ATIVA_TEMP],R1		
		
		CALL	IncrementaLCD1	;Incrementa a Distancia Percorrida


		MOV	R1,M[Numero1]	;Este processo verifica quantas barreiras foram inicializadas
		SUB	M[Inicia_Barreir],R1
		MOV	M[Temporizador_Mem],R1


		POP	R5
		POP	R2
		POP	R1

		RET				


IncrementaLCD1:	PUSH	R1	;Incrementa LCD
		PUSH	R2
		PUSH	R3
		
		INC	M[Distancia_Percorrida]	;Incrementa a distancia percorrida
		MOV	R3,M[Numero_0030h]

		INC	M[Valor_ASCII_LCD_1]
		MOV	R1,M[Valor_ASCII_LCD_1]
		CMP	R1,M[Numero_003Ah]	;Se valor não for um numero (:) coloca ascii a 0030 = 0
		BR.Z	ColocaAscii0
		JMP	ContinuaASCII_1

	


ColocaAscii0:	MOV	M[Valor_ASCII_LCD_1],R3	
		INC	M[Valor_ASCII_LCD_2]

		MOV	R2,M[Valor_ASCII_LCD_2]
		CMP	R2,M[Numero_003Ah]
		BR.Z	ColocaAscii1
		
		JMP	ContinuaASCII_1


ColocaAscii1:	INC	M[Valor_ASCII_LCD_3]
		MOV	R2,M[Valor_ASCII_LCD_3]
		CMP	R2,M[Numero_003Ah]
		BR.Z	ColocaAscii2

		MOV	M[Valor_ASCII_LCD_1],R3
		MOV	M[Valor_ASCII_LCD_2],R3
		JMP	ContinuaASCII_1


ColocaAscii2:	MOV	R2,M[Valor_ASCII_LCD_4]
				
		
		MOV	M[Valor_ASCII_LCD_1],R3
		MOV	M[Valor_ASCII_LCD_2],R3
		MOV	M[Valor_ASCII_LCD_3],R3
		INC	M[Valor_ASCII_LCD_4]
		




ContinuaASCII_1:MOV	R2,M[Numero_800Dh]
		MOV	M[LCD_CONTROLO],R2
		MOV	R1,M[Valor_ASCII_LCD_1]
		MOV	M[LCD_ESCRITA],R1

		DEC	R2
		MOV	M[LCD_CONTROLO],R2
		MOV	R1,M[Valor_ASCII_LCD_2]
		MOV	M[LCD_ESCRITA],R1

		DEC	R2
		MOV	M[LCD_CONTROLO],R2
		MOV	R1,M[Valor_ASCII_LCD_3]
		MOV	M[LCD_ESCRITA],R1

		
		DEC	R2
		MOV	M[LCD_CONTROLO],R2
		MOV	R1,M[Valor_ASCII_LCD_4]
		MOV	M[LCD_ESCRITA],R1



		POP	R3
		POP	R2
		POP	R1
		RET


VerificaNivel:	PUSH	R1		;Verifica o Nível Atual e refresca a variavel da duraçao 
		PUSH	R2
		PUSH	R3

		CMP	M[Turbo_Mem],R0
		JMP.Z	MODOTURBO

		MOV	R3,M[ValorLeds]
		MOV	M[LEDS],R3

		MOV	R1,M[ValorNivel]
		MOV	R2,M[Numero1]
		CMP	R1,R2
		BR.Z	Nivel_1

		MOV	R2,M[Numero_0002h]
		CMP	R1,R2
		BR.Z	Nivel_2

		MOV	R2,M[Numero_0003h]
		CMP	R1,R2
		BR.Z	Nivel_3


Nivel_1:	CMP	R3,M[Numero_F000h]
		BR.Z	Nivel1TEMP	

Nivel_2:	CMP	R3,M[Numero_FF00h]
		BR.Z	Nivel2TEMP

Nivel_3:	CMP	R3,M[Numero_FFF0h]
		BR.Z	Nivel3TEMP



Nivel1TEMP:	MOV	R1,M[Numero_0005h] ; Coloca o nivel 1 na variavel da duracao
		MOV	M[ValorTemp],R1
		JMP	TerminaVerifica

Nivel2TEMP:	MOV	R1,M[Numero_0004h]; Coloca o nivel 2 na variavel da duracao
		MOV	M[ValorTemp],R1
		JMP	TerminaVerifica

Nivel3TEMP:	MOV	R1,M[Numero_0003h]; Coloca o nivel 3 na variavel da duracao
		MOV	M[ValorTemp],R1
		JMP	TerminaVerifica

MODOTURBO:	MOV	R1,M[Numero_FFFFh]; Coloca o turbo na variavel da duracao
		MOV	M[LEDS],R1
		MOV	R1,M[Numero_0002h]
		MOV	M[ValorTemp],R1



TerminaVerifica:POP	R3
		POP	R2
		POP	R1
		RET

Ver_Colisao:	PUSH	R2 ;Verifica as barreiras a descer e se houve colisão
		PUSH	R3

		MOV	R3,M[PosicColis]	
		ADD	R3,M[Numero_0100h]
		MOV	R2,R6
		
		SUB	R2,M[Soma2Linhas]
		CMP	R3,R2
		CALL.Z	GAMEOVER
		
		ADD	R2,M[Numero_0100h]
		CMP	R3,R2
		CALL.Z	GAMEOVER


		
		ADD	R2,M[Numero_0100h]
		CMP	R3,R2
		CALL.Z	GAMEOVER



		POP	R3
		POP	R2
		RET

GAMEOVER:	PUSH	R1		;Coloca Distancia a e se Distancia Perc > Distancia Max coloca Distancia Perc. em distancia Max.
		PUSH	R2
		PUSH	R3		
		MOV	M[HouveColisao],R0

		MOV	M[Barreiras_Ultr],R0
		MOV	M[Barreiras_90],R0
		MOV	M[Barreiras_900],R0
		


		MOV	R2,M[Distancia_Percorrida]
		MOV	R3,M[Distancia_Percorrida_MAX]

		CMP	R2,R3
		BR.NP	AcabaGameOver

		MOV	R1,M[Valor_ASCII_LCD_4]
		MOV	M[Ultima_Pontuacao_4],R1

		MOV	R1,M[Valor_ASCII_LCD_3]
		MOV	M[Ultima_Pontuacao_3],R1

		MOV	R1,M[Valor_ASCII_LCD_2]
		MOV	M[Ultima_Pontuacao_2],R1

		MOV	R1,M[Valor_ASCII_LCD_1]
		MOV	M[Ultima_Pontuacao_1],R1

		MOV	M[Distancia_Percorrida_MAX],R2


AcabaGameOver:	MOV	M[Distancia_Percorrida],R0
		POP	R3
		POP	R2
		POP	R1

		RET




Inicio:		MOV	R7,SP_INICIAL		;Inicializa a pilha
		MOV	SP,R7

	
        	MOV     R7, INT_MASK_INICIAL  	;Ativa Interrupcao I1
        	MOV     M[INT_MASK_ADDR], R7

		MOV	R6,IO_READ		;Porto de controlo da Janela de Texto
		MOV	M[IO_CONTROL],R6
		MOV	R6,BemVindoPos
		MOV	M[IO_CONTROL],R6

		CALL	BemVind
		ENI
		
		JMP	Infinito

Escreve_LCD:	PUSH	R1
		PUSH	R2
		PUSH	R3


		MOV	R1,LCD_MASK		
		MOV	M[LCD_CONTROLO],R1	; Porto de controlo do LCD
		MOV	R3,LCD1

OutraVez:	MOV	R2,M[R3]		;Escreve "Distancia:    m" no LCD
		CMP	R2,FIM_TEXTO	
		BR.Z	MudalinhaLCD
		
		MOV	M[LCD_ESCRITA],R2
		
		INC	R3		
	
		INC	R1
		MOV	M[LCD_CONTROLO],R1

		BR	OutraVez

MudalinhaLCD:	MOV	R1,LCD_MASK		;Atualiza Porto Controlo LCD
		ADD	R1,M[Numero_0010h]
		MOV	M[LCD_CONTROLO],R1
		MOV	R3,LCD2

OutraVez1:	MOV	R2,M[R3]		;Escreve "Maximo:    m" no LCD
		CMP	R2,FIM_TEXTO
		BR.Z	Ajuda
		MOV	M[LCD_ESCRITA],R2
		INC	R3
		INC	R1
		MOV	M[LCD_CONTROLO],R1
		BR	OutraVez1


Ajuda:		MOV	R2,M[Numero_801Dh]		;Coloca Pontuação Maxima no LCD
		MOV	M[LCD_CONTROLO],R2	;Baseia-se em Variaveis chamadas Ultima_Pontuacao_X
		MOV	R1,M[Ultima_Pontuacao_1]
		MOV	M[LCD_ESCRITA],R1

		DEC	R2
		MOV	M[LCD_CONTROLO],R2
		MOV	R1,M[Ultima_Pontuacao_2]
		MOV	M[LCD_ESCRITA],R1

		DEC	R2
		MOV	M[LCD_CONTROLO],R2
		MOV	R1,M[Ultima_Pontuacao_3]
		MOV	M[LCD_ESCRITA],R1

		DEC	R2
		MOV	M[LCD_CONTROLO],R2
		MOV	R1,M[Ultima_Pontuacao_4]
		MOV	M[LCD_ESCRITA],R1


AcabaLCD:	POP	R3
		POP	R2
		POP	R1
		RET


IniciaJogo:	CALL	Apaga_Mensagem   ;Inicializa o Jogo
		MOV	R6,IO_READ
		MOV	M[IO_CONTROL],R6
		MOV	R6,INICIO
		MOV	M[IO_CONTROL],R6

		CALL	Escreve_Campo
		CALL	Escreve_LCD

        	MOV     R7, INT_MASK		;Novas Interrupc. a serem ativadas
        	MOV     M[INT_MASK_ADDR], R7
		
		MOV	R1,M[Numero_F000h]		;Corresponde ao lvl1
		MOV	M[LEDS],R1
		MOV	M[ValorLeds],R1



		PUSH	R1			;Coloca nas variaveis de distancia perc. 0
		MOV	R1,M[Numero_0030h]
		MOV	M[Valor_ASCII_LCD_4],R1
		MOV	M[Valor_ASCII_LCD_3],R1
		MOV	M[Valor_ASCII_LCD_2],R1
		MOV	M[Valor_ASCII_LCD_1],R1


		MOV	R1,M[Numero1]
		MOV	M[Comeca_Jogo],R1	;Para no ciclo Infinito o Inicia_jogo nao ser chamado
						;vai manter-se inalterado até existir o Fim do Jogo
					
		MOV	R1,R0		;Coloca Display de 7 seg. a 0
		MOV	M[IO_DISPLAY1],R1
		MOV	M[IO_DISPLAY2],R1
		MOV	M[IO_DISPLAY3],R1
		MOV	M[IO_DISPLAY4],R1
		
		CALL	Aleatorio1st		;Gera a posição da Primeira Barreira
		PUSH	R5
		MOV	R5,M[Primeira_Posic]	
		ADD	R5,M[Numero_001Ch]
		MOV	M[Barreira_1],R5
		MOV	M[IO_CONTROL],R5

		MOV	R1,M[Numero_0014h]		;Ativa Temporizador
		MOV	M[DURACAO],R1
		MOV	R1,M[Numero1]
		MOV	M[ATIVA_TEMP],R1
		
		POP	R5
		POP	R1

		RET






TerminaJogo:	PUSH	R1			;Termina o Jogo
		PUSH	R2
		
		MOV     R7, INT_MASK_INICIAL		; Desabilita todas as interrupçoes menos a int. I1
        	MOV     M[INT_MASK_ADDR], R7

		MOV	R1,R0
		MOV	M[ATIVA_TEMP],R1	;Desativa Temporizador
		

		MOV	R1,M[Numero_0012h]	;Coloca o valor inicial (0012h)
		MOV	M[Inicia_Barreir],R1

		MOV	M[Barreira_1],R0	;O valor da posicao das barreiras é colocado a 0
		MOV	M[Barreira_2],R0
		MOV	M[Barreira_3],R0
		MOV	M[Barreira_4],R0


		MOV	R1,M[Numero1]		
		MOV	M[HouveColisao],R1	;Reset nas memorias Colisao e Turbo
		MOV	M[Turbo_Mem],R1


		CALL	ApagaJanela

		CALL	TerminouFrase

		POP	R2
		POP	R1
		RET
		
		
TerminouFrase:	PUSH	R1  ; Escreve a Frase do GameOver


		MOV	R1,M[Numero_0924h]
		MOV	M[IO_CONTROL],R1

		MOV	R6,R0
		CALL	AcabouFrase		
		
		
		
		POP	R1	
		RET
		


AcabouFrase:	PUSH	R1
		PUSH	R2
		PUSH	R3
		MOV	R3,M[Numero_0924h]

		MOV	R1,FimdoJogo1
TerminaFrase:	MOV	R2,M[R1]		
		CMP	R2,FIM_TEXTO
		BR.Z	AcabaMudaLinha
		MOV	M[IO_WRITE],R2
		INC	R3
		MOV	M[IO_CONTROL],R3
		INC	R1
		BR	TerminaFrase	
		
AcabaMudaLinha:	ADD	R3,M[Soma2Linhas]
		SUB	R3,M[Numero_0018h]
		MOV	M[IO_CONTROL],R3
		MOV	R1,FimdoJogo2
TerminaFrase1:	MOV	R2,M[R1]
		CMP	R2,FIM_TEXTO
		BR.Z	AcabaTermina
		MOV	M[IO_WRITE],R2
		INC	R3
		MOV	M[IO_CONTROL],R3
		INC	R1
		BR	TerminaFrase1	

AcabaTermina:	POP	R3
		POP	R2		
		POP	R1	
		RET





Aleatorio1st:	PUSH	R5	;Gera Valores Aleatorios
		MOV	R5,M[Random]
Aleatorio:	PUSH	R1	
		PUSH	R2
		PUSH	R6
		CMP	R5,R0	
		BR.NZ	Alea1
		ROR	R5,1
	
		
		MOV	R1,M[Numero_0016h]
		MOV	R2,R5
		DIV	R2,R1

		MOV	R5,R1
		MOV	M[Random],R5
	
	
		POP	R6
		POP	R2
		POP	R1
		POP	R5
		RET

;DIVIDIR POR 0015;
Alea1:		XOR	R5,M[Mascara_Alea]
		ROR	R5,1
		MOV	R6,R5
		SHL	R6,8
		SHR	R6,8
		MOV	R6,R5
	
		MOV	R1,M[Numero_0016h]
		MOV	R2,R5
		DIV	R2,R1
		MOV	R5,R1
		MOV	M[Primeira_Posic],R5
		MOV	M[Random],R5
		
		POP	R6
		POP	R2
		POP	R1
		POP	R5

		RET



Pausa:		CALL	EscrevePausaLCD ;Se ativada a Pausa Faz um ciclo infinito em Pausa1 até I1 ser clicado novamente
Pausa1:		CMP	M[Pausa_Mem],R0
		BR.Z	Pausa1
		CALL	Escreve_LCD
		RET		

EscrevePausaLCD:PUSH	R1		;Escreve no LCD pausa
		PUSH	R2
		PUSH	R3
		MOV	R1,LCD_MASK
		MOV	M[LCD_CONTROLO],R1
		MOV	R3,LCDPAUSA1

EscPausa1:	MOV	R2,M[R3]
		CMP	R2,FIM_TEXTO	
		BR.Z	MudalinhaPausa
		
		MOV	M[LCD_ESCRITA],R2
		
		INC	R3		
	
		INC	R1
		MOV	M[LCD_CONTROLO],R1

		BR	EscPausa1

MudalinhaPausa:	MOV	R1,LCD_MASK
		ADD	R1,M[Numero_0010h]
		MOV	M[LCD_CONTROLO],R1
		MOV	R3,LCDPAUSA2

EscPausa2:	MOV	R2,M[R3]
		CMP	R2,FIM_TEXTO
		BR.Z	AcabaEscPausa
		MOV	M[LCD_ESCRITA],R2
		INC	R3
		INC	R1
		MOV	M[LCD_CONTROLO],R1
		BR	EscPausa2


AcabaEscPausa:	POP	R3
		POP	R2
		POP	R1
		RET




Infinito:	CMP	M[Comeca_Jogo],R0      	;Verifica se o jogo já começou
		CALL.Z	IniciaJogo
		INC	M[Random]

		CMP	M[Temporizador_Mem],R0	;Verifica se o Temporizador gerou interrupcao
		CALL.Z	Temporizador


		CMP	M[Esquerda_Mem],R0	;Verifica se I0 foi ativado
		CALL.Z	Esquerda

		CMP	M[Direita_Mem],R0	;Verifica se IB foi ativado
		CALL.Z	Direita

		CMP	M[HouveColisao],R0	;Verifica se ocorreu colisão
		CALL.Z	TerminaJogo

		CMP	M[Pausa_Mem],R0		;Verifica se ocorreu uma pausa
		CALL.Z 	Pausa


		MOV	R4,M[ValorNivel]


		BR	Infinito




