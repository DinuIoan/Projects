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
public class SQUARE {
    int n;

    public SQUARE(int n) {
        this.n = n;
    }
    
    public int celMaiMicPatrat(){
        int number = this.n;
        for(int i = 0; i <= number / 2; i++){
            if(i*i > number){
                return i-1;
            }
        }
        return 0;
    }
    
    
    
}
