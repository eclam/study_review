/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author eric
 */
public class Timer {
    private ClockHand hundredsOfASecond;
    private ClockHand seconds;
    
    public Timer(){
        this.hundredsOfASecond = new ClockHand(100);
        this.seconds = new ClockHand(60);
    }
    
    public String toString(){
        return this.seconds + ":" + this.hundredsOfASecond;
    }
    
    public void advance(){
        if(this.hundredsOfASecond.value() == 99){
            this.seconds.advance();
        }
        this.hundredsOfASecond.advance();
    }
}
