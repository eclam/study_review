
public class Money {

    private final int euros;
    private final int cents;

    public Money(int euros, int cents) {

        if (cents > 99) {
            euros = euros + cents / 100;
            cents = cents % 100;
        }

        this.euros = euros;
        this.cents = cents;
    }

    public int euros() {
        return this.euros;
    }

    public int cents() {
        return this.cents;
    }

    public String toString() {
        String zero = "";
        if (this.cents < 10) {
            zero = "0";
        }

        return this.euros + "." + zero + this.cents + "e";
    }

    public Money plus(Money addition){
        int euros = addition.euros() + this.euros, cents = addition.cents() + this.cents;
        while(cents > 99){
            euros++;
            cents -= 100;
        }
        Money newMoney = new Money(euros, cents);
        
        
        return newMoney;
    }
    
    public boolean lessThan(Money comparison){        
        if(this.euros == comparison.euros()){
            if(this.cents < comparison.cents()){
                return true;
            }
        } else if (this.euros < comparison.euros()){
            return true;
        }
        return false;
        
    }
    public Money minus(Money minus){
        int euros = 0, cents = 0;
  
        if(!(this.lessThan(minus))){
            euros = this.euros - minus.euros();
            
            if(this.cents < minus.cents()){
                euros--;
                cents = 100 + this.cents - minus.cents();
            } else {
                cents = this.cents - minus.cents();
            }
        } 
                
        Money newMoney = new Money(euros, cents);
        return newMoney;
    }
}
