/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author eric
 */
public class Debt {
    private double balance;
    private double mortgageRate;
    public Debt(double balance, double mortgageRate){
        this.balance = balance;
        this.mortgageRate = mortgageRate;
    }
    
    public void printBalance(){
        System.out.println(this.balance);
    }
    public void waitOneYear(){
        this.balance = this.balance * mortgageRate;
    }
    
}
