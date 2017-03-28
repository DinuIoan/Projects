/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
//package tema2;

import static java.lang.Math.sqrt;

/**
 *
 * @author Ionut
 */
public class FIB {
    
    int n;

    public FIB(int n) {
        this.n = n;
    }
    
    public int fibonacci(){
        
        int fib0 = 1,fib1 = 1,fibonacci = 1;
        int count = 1;
        while(fibonacci < n)
        {
            fibonacci = fib0 + fib1;
            fib0 = fib1;
            fib1 = fibonacci;
            count++;   
        }
        return count;
    }
    
    
    
}
