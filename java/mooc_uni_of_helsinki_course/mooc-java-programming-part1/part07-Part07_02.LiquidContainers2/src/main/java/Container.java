/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author eric
 */
public class Container {
    private int val;
    
    public Container(){
        this.val = 0;
    }
    
    public int contains(){
        return this.val;
    }
    
    public void add(int amt){
        if (amt > 0){
            if(this.val + amt <= 100){
                this.val += amt;
            } else{
                this.val = 100;
            }                    
        }   
    }
    
    public void remove(int amt){
        if(amt > 0){
            if(amt <= this.val){
                this.val -= amt;
            } else {
                this.val = 0;
            }
        } 
    }
    
    public String toString(){
        return this.val + "/100";
    }
    
}
