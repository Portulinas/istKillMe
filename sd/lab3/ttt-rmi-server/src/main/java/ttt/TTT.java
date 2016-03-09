package ttt;

import java.rmi.*;
import java.rmi.server.UnicastRemoteObject;

public class TTT extends UnicastRemoteObject implements TTTService {
	
	
	private static final long serialVersionUID = 1L;
	char board[][] = {
		  {'1','2','3'},          /* Initial values are reference numbers */
		  {'4','5','6'},          /* used to select a vacant square for   */
		  {'7','8','9'}           /* a turn.                              */
		};
	char defaultBoard[][] = {
			  {'1','2','3'},          /* Initial values are reference numbers */
			  {'4','5','6'},          /* used to select a vacant square for   */
			  {'7','8','9'}           /* a turn.                              */
			};
	int nextPlayer = 0;
	int numPlays = 0;
	
	int[][] lastPlayOne = {{-1,-1},{-1,-1}};
	int[][] lastPlayTwo = {{-1,-1},{-1,-1}};
	
	public TTT() throws RemoteException {
		super();
	}

    public String currentBoard() {
    	String s = "\n\n " + 
    				board[0][0]+" | " +
    				board[0][1]+" | " +
    				board[0][2]+" " +
    				"\n---+---+---\n " +
    				board[1][0]+" | " +
    				board[1][1]+" | " +
    				board[1][2]+" " +
    				"\n---+---+---\n " +
    				board[2][0]+" | " +
    				board[2][1]+" | " +
    				board[2][2] + " \n";
    	return s;
    }

    public boolean play(int row, int column, int player) {
		if (!(row >=0 && row <3 && column >= 0 && column < 3))
			return false;
		if (board[row][column] > '9')
			return false;
		if (player != nextPlayer) 
			return false;

		if (numPlays == 9) 
			return false;

		board[row][column] = (player == 1) ? 'X' : 'O';        /* Insert player symbol   */
		
		if (player == 0) {
			if (lastPlayOne[1][0] == -1 && lastPlayOne[1][1] == -1) {
				lastPlayOne[1][0] = row;
				lastPlayOne[1][1] = column;
			}
			else if (lastPlayOne[0][0] == -1 && lastPlayOne[0][1] == -1) {
				lastPlayOne[0][0] = row;
				lastPlayOne[0][1] = column;
			}
			else {
				lastPlayOne[0][0] = lastPlayOne[1][0];
				lastPlayOne[0][1] = lastPlayOne[1][1];
				
				lastPlayOne[1][0] = row;
				lastPlayOne[1][1] = column;
			}
			
		}
		else {
			if (lastPlayTwo[1][0] == -1 && lastPlayTwo[1][1] == -1) {
				lastPlayTwo[1][0] = row;
				lastPlayTwo[1][1] = column;
			}
			else if (lastPlayTwo[0][0] == -1 && lastPlayTwo[0][1] == -1) {
				lastPlayTwo[0][0] = row;
				lastPlayTwo[0][1] = column;
			}
			else {
				lastPlayTwo[0][0] = lastPlayTwo[1][0];
				lastPlayTwo[0][1] = lastPlayTwo[1][1];
				
				lastPlayTwo[1][0] = row;
				lastPlayTwo[1][1] = column;
			}
		}
		
		nextPlayer = (nextPlayer + 1) % 2;
		numPlays ++;
		return true;	
    }

    public int checkWinner() {
    	  int i;
    	  /* Check for a winning line - diagonals first */     
    	  if((board[0][0] == board[1][1] && board[0][0] == board[2][2]) ||
    	     (board[0][2] == board[1][1] && board[0][2] == board[2][0])) {
    		  if (board[1][1]=='X')
    			  return 1;
    		  else 
    			  return 0;
    	  }
    	  else
    	    /* Check rows and columns for a winning line */
    	    for(i = 0; i <= 2; i ++) {
    	      if((board[i][0] == board[i][1] && board[i][0] == board[i][2])) {
    	    	  if (board[i][0]=='X')
    	    		  return 1;
    	    	  else 
    	    		  return 0;
    	      }

    	     if ((board[0][i] == board[1][i] && board[0][i] == board[2][i])) {
    	    	 if (board[0][i]=='X') 
    	    		 return 1;
    	    	 else 
    	    		 return 0;
    	     }
    	    }
    	  	if (numPlays == 9)
    	  		return 2; /* A draw! */
    	  	else
    	  		return -1; /* Game is not over yet */
	}
    
	public void anularDuas() throws RemoteException {
		int row;
		int column; 
	
		if (nextPlayer == 0) {
			
			if(lastPlayOne[0][0] != -1 || lastPlayOne[0][1] != -1) {
				
				row = lastPlayOne[1][0];
				column = lastPlayOne[1][1];
				board[row][column] = defaultBoard[row][column];
				
				row = lastPlayOne[0][0];
				column = lastPlayOne[0][1];
				board[row][column] = defaultBoard[row][column];
			
			}
		}
		else {
			
			if(lastPlayTwo[0][0] != -1 || lastPlayTwo[0][1] != -1) {
				
				row = lastPlayTwo[1][0];
				column = lastPlayTwo[1][1];
				board[row][column] = defaultBoard[row][column];
				
				row = lastPlayTwo[0][0];
				column = lastPlayTwo[0][1];
				board[row][column] = defaultBoard[row][column];
				
			}
		}
	}


}
