package ttt;

import java.rmi.registry.*;

public class TTTServer {

	public static void main(String[] args) {
		
		int registryPort = 8686;
		System.out.println("Main OK");
		
		try {
			TTT ttt = new TTT();
			System.out.println("After create");
			
			Registry reg = LocateRegistry.createRegistry(registryPort);
			reg.rebind("TTTServer", ttt);
			
			//Naming.rebind("TTTServer",ttt);
			System.out.println("TTTServer is ready");
		} 
		catch (Exception e) {
			System.err.println("Error in main(): " + e.getMessage());
		}

	}

}
