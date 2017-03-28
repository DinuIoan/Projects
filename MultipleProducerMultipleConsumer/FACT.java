/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
//package tema2;

/**
 *
 * @author Ionut
 */
public class FACT {
    int n;

    public FACT(int n) {
        this.n = n;
    }
    
    public int factorial(){
        int sum = 1;
        for(int i = 1; i <= n/2 ; i++){
            if(i*sum > n){
                return i-1;
            }else sum = sum * i;
        }
        return 0;
    }
    
    
    
}
