/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author eric
 */
public class PaymentCard {
    private double balance;
    public PaymentCard(double openingBalance){
        if(openingBalance > 150){
            this.balance = 150;
        }
        this.balance = openingBalance;
    }
    
    public String toString(){
        return "The card has a balance of " + Double.toString(this.balance) + " euros";
    }
    
    public void eatAffordably(){
        if(this.balance - 2.60 < 0){
            return;
        }
        this.balance -= 2.60;
    }
    
    public void eatHeartily(){
        if(this.balance - 4.60 < 0){
            return;
        }
        this.balance -= 4.60;
    }
    
    public void addMoney(double amount){
        if(amount < 0){
            return;
        }
        if(this.balance + amount > 150){
            this.balance = 150;
            return;
        }
        this.balance += amount;
    }
}
