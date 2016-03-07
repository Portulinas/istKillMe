package ttt;

import java.rmi.registry.Registry;
import java.rmi.registry.LocateRegistry;

public class TTTServer{
	public static void main(String args[]){
		int registryPort = 8008;
		System.out.println("Main ok");
		try{
			TTT g = new TTT();
			System.out.println("Game instance created!");
			Registry reg = LocateRegistry.createRegistry(registryPort);
			reg.rebind("TTTServer", g);
			
			System.out.println("TTT Server is ready!");
		}catch(Exception e){
			System.out.println("TTT Server main: " + e.getMessage());
		}
	}
}