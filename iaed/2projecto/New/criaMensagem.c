#include "final.h"

Item criaMensagem(int sender, int receiver, char *texto){
	/*Cria o item com a mensagem texto do utilizador sender para o receiver*/
	Item msg;
	msg = malloc(sizeof(struct mensagem));
	msg -> e = sender;
	msg -> r = receiver;
	msg -> text = (char*) malloc( (strlen(texto)+1) * sizeof(char) );
	strcpy(msg->text,texto);
	return msg;
}
