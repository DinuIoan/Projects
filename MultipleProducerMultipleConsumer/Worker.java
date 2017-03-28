//package tema2;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;
//import tema2.WorkPool;



class Worker extends Thread {
	WorkPool wp;

	public Worker(WorkPool workpool) {
		this.wp = workpool;
	}

	
	void processPartialSolution(Object ps) {
            
            
                
                Object typeOfEvent = ps;
                if(typeOfEvent instanceof PRIME){
                    while(((PRIME) typeOfEvent).numarPrim() == false){
                                    ((PRIME) typeOfEvent).n--;
                         }
                    Tema2.primeV.add(((PRIME) typeOfEvent).n);
                   /* prime.write("" + ((PRIME) typeOfEvent).n);
                    prime.newLine();*/
                }
                else if(typeOfEvent instanceof SQUARE){
                    Tema2.squareV.add(((SQUARE) typeOfEvent).celMaiMicPatrat());
                    /*square.write("" + ((SQUARE) typeOfEvent).celMaiMicPatrat());
                    square.newLine();*/
                }
                else if(typeOfEvent instanceof FIB){
                    Tema2.fibV.add(((FIB) typeOfEvent).fibonacci());
                    /*fib.write("" + ((FIB) typeOfEvent).fibonacci());
                    fib.newLine();     */             
                }
                else if(typeOfEvent instanceof FACT){
                    Tema2.factV.add(((FACT) typeOfEvent).factorial());
                    /*fact.write("" + ((FACT) typeOfEvent).factorial());
                    fact.newLine();*/
                }
            
            
	}
	
	public void run() {
                 
		while (true) {
                    
			Object ps = wp.getWork();
			if (ps == null)
				break;
			                
			processPartialSolution(ps);
		}
	}

	
}




