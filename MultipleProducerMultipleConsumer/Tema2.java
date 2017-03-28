/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
//package tema2;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Vector;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Ionut
 */
public class Tema2 {

    static int N;
    static int evenimenteFisier;
    //static Buffer buffer;
    static Vector fibV;
    static Vector factV;
    static Vector squareV;
    static Vector primeV;
    
    public static void main(String[] args) {
        int numarParametrii = 0;
        if(args.length > 3){
            N = Integer.parseInt(args[0]);
            evenimenteFisier = Integer.parseInt(args[1]);
        }
        else{
            System.out.println("No Arguments Found");
        }
       // buffer = new Buffer();
        fibV = new Vector();
        factV = new Vector();
        squareV = new Vector();
        primeV = new Vector();
         
        numarParametrii = args.length - 2;
        
       // Buffer buffer = new Buffer();
        Thread threads[] = new Thread[numarParametrii];
        Vector<String> numeFisier;
        numeFisier = new Vector<String>();
        
        WorkPool workPool = new WorkPool(5);
        Thread workers[] = new Thread[5];
        
        for(int i = 0 ; i < numarParametrii ; i++){
            numeFisier.add(args[i + 2]);
        }
        
	for(int i = 0; i < 5; i++){
            workers[i] = new Thread(new Worker(workPool));
        }
       
        
	for(int i = 0; i < 5; i++){
            workers[i].start();
        }
	for (int i = 0; i < 5; i++) {
            try {
                    workers[i].join();
            } catch (InterruptedException e) {
                    e.printStackTrace();
            }
        }
	for(int i = 0 ; i < numarParametrii; i++){
            threads[i] = new Thread(new Evenimente(workPool, numeFisier.get(i)));
            
        }
	for(int i = 0 ; i < numarParametrii; i++){
            threads[i].start();
        }
         
        for (int i = 0; i < numarParametrii; i++) {
            try {
                    threads[i].join();
            } catch (InterruptedException e) {
                    e.printStackTrace();
            }
        }
        
        
        
        
        BufferedWriter fib = null;
        BufferedWriter square = null;
        BufferedWriter prime = null;
        BufferedWriter fact = null;
        Collections.sort(fibV);
        Collections.sort(factV);
        Collections.sort(squareV);
        Collections.sort(primeV);
        
        
        
        try  
            {
                FileWriter fibStream = new FileWriter("FIB.out", true); //true tells to append data.
                fib = new BufferedWriter(fibStream);
                FileWriter squareStream = new FileWriter("SQUARE.out", true); //true tells to append data.
                square = new BufferedWriter(squareStream);
                FileWriter primeStream = new FileWriter("PRIME.out", true); //true tells to append data.
                prime = new BufferedWriter(primeStream);
                FileWriter factStream = new FileWriter("FACT.out", true); //true tells to append data.
                fact = new BufferedWriter(factStream);
                
                for(int i = 0; i < fibV.size();i++){
                    fib.write("" + fibV.elementAt(i));
                    fib.newLine();
                }
                for(int i = 0; i < factV.size();i++){
                    fact.write("" + factV.elementAt(i));
                    fact.newLine();
                }
                for(int i = 0; i <squareV.size();i++){
                    square.write("" + squareV.elementAt(i));
                    square.newLine();
                }
                for(int i = 0; i < primeV.size();i++){
                    prime.write("" + primeV.elementAt(i));
                    prime.newLine();
                }
                
        
        }
            catch (IOException e)
            {
                System.err.println("Error: " + e.getMessage());
            }
            finally
            {
                if(fib != null) {
                    try {
                        fib.close();
                    } catch (IOException ex) {
                        Logger.getLogger(Worker.class.getName()).log(Level.SEVERE, null, ex);
                    }
                }
                if(square != null) {
                    try {
                        square.close();
                    } catch (IOException ex) {
                        Logger.getLogger(Worker.class.getName()).log(Level.SEVERE, null, ex);
                    }
                }
                if(prime != null) {
                    try {
                        prime.close();
                    } catch (IOException ex) {
                        Logger.getLogger(Worker.class.getName()).log(Level.SEVERE, null, ex);
                    }
                }
                if(fact != null) {
                    try {
                        fact.close();
                    } catch (IOException ex) {
                        Logger.getLogger(Worker.class.getName()).log(Level.SEVERE, null, ex);
                    }
                }
            }
        

        
        
        
        
    }
    
}
