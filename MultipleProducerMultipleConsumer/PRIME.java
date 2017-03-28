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
public class PRIME {
    int n;
    
    PRIME(int n){
        this.n = n;
    }
    
    public boolean numarPrim(){
        for (int i = 2; i <= n /2; i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
    
}
