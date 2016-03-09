package ttt;


import java.rmi.*;
import java.util.Scanner;


public class Game {

	TTT ttt;
	Scanner keyboardSc;
	int winner = 0;
	int player = 1;
		
	public Game(){
		try {
			
			ttt = (TTT)Naming.lookup("//localhost:8686/TTTServer");
			System.out.println("Found server");
			
		} catch (RemoteException e) {
			System.out.println("Game() constructor remote error: " + e.getMessage());
		} catch (Exception e) {
			System.out.println("Lookup error: " + e.getMessage());
		} 
		
		keyboardSc = new Scanner(System.in);
	}
	
	public int readPlay() {
		int play;
		do {
			System.out.printf("\nPlayer %d, please enter the number of the square "
							+ "where you want to place your %c (or 0 to refresh the board).\n"
							+ "Alternatively, enter 10 to undo your last two plays: \n",
							player, (player == 1) ? 'X' : 'O');
			play = keyboardSc.nextInt();
		} while (play > 10 || play < 0);
		return play;
	}
	
	public void playGame() throws RemoteException {
		int play;
		boolean playAccepted;

		do {
			player = ++player % 2;
			do {
				System.out.println(ttt.currentBoard());
				play = readPlay();
				if (play == 10) {
					ttt.anularDuas();
					System.out.println(ttt.currentBoard());
				}
				if (play != 0 && play != 10) {
					playAccepted = ttt.play( --play / 3, play % 3, player);
					if (!playAccepted)
						System.out.println("Invalid play! Try again.");
				} 
				else
					playAccepted = false;
			} while (!playAccepted);
			winner = ttt.checkWinner();
		} while (winner == -1);
	}
	
	public void congratulate() {
		if (winner == 2)
			System.out.printf("\nHow boring, it is a draw\n");
		else
			System.out.printf(
					"\nCongratulations, player %d, YOU ARE THE WINNER!\n",
					winner);
	}
	
    public static void main(String[] args) {
    	  
    	Game g = new Game();
    	System.out.println("Cenas");
    	
    	try {
    		g.playGame();
    		g.congratulate();	
    	} catch (RemoteException e) {
    		System.out.println("TTT Error: " + e.getMessage());
    	}
		
    	
    	
    }

}
