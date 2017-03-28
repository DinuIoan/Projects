/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
//package tema2;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Ionut
 */
public class Evenimente implements Runnable{
    WorkPool workPool;
    String name ;
    
    Evenimente(WorkPool workPool, String name ){
        this.workPool = workPool;
        this.name = name;
    }
    
        @Override
	public void run() {
                BufferedReader br = null;
		FileReader fr = null;
		String[] liniiFisier = new String[Tema2.evenimenteFisier];
                String[] cuvinte = new String[30];
                 try{
                    String sCurrentLine;
                    fr = new FileReader(name);
                    br = new BufferedReader(fr);
                    int count = 0;
                    int count2 = 0;
                    while ((sCurrentLine = br.readLine()) != null) {
                        
                        String[] parts = sCurrentLine.split(",");
                        long time = Long.parseLong(parts[0]);
                        String eveniment = parts[1];
                        int numar = Integer.parseInt(parts[2]);
                        synchronized (WorkPool.tasks){
                        try {
                            WorkPool.tasks.wait(time);
                            while(WorkPool.tasks.size() == Tema2.N){
                               WorkPool.tasks.wait();
                            }
                            if(eveniment.equals("PRIME")){
                                PRIME prime = new PRIME(numar);
                                workPool.putWork(prime);
                                /*while(prime.numarPrim() == false){
                                    prime.n--;
                                }
                                Tema2.buffer.put(prime.n); */
                                
                            }
                            else if(eveniment.equals("SQUARE")){
                                SQUARE square = new SQUARE(numar);
                                workPool.putWork(square);
                                //Tema2.buffer.put(square.celMaiMicPatrat());
                            }       
                            else if(eveniment.equals("FIB")){
                                FIB fib = new FIB(numar);
                                workPool.putWork(fib);
                                //Tema2.buffer.put(fib.fibonacci());
                            }
                            else if(eveniment.equals("FACT")){
                                FACT fact = new FACT(numar);
                                workPool.putWork(fact);
                                //Tema2.buffer.put(fact.factorial());
                            }   

                            
                           
                        } catch (InterruptedException ex) {
                            Logger.getLogger(Evenimente.class.getName()).log(Level.SEVERE, null, ex);
                        }
                        }
                        
                        
                       // System.out.println();
                        count++;
                        count2 += 3;
                    }
                }catch(IOException e){
                    e.printStackTrace();
                }
        }

}
