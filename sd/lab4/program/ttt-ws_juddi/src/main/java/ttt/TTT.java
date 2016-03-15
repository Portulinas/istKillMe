package ttt;

import javax.jws.WebService;

@WebService
public interface TTT {
	String currentBoard();

	void tituloJogo(String new_titulo);
	
	boolean play(int row, int column, int player);

	int checkWinner();
}
