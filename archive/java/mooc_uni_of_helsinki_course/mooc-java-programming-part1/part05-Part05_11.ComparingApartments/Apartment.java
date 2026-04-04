import java.lang.Math;
public class Apartment {

    private int rooms;
    private int squares;
    private int pricePerSquare;

    public Apartment(int rooms, int squares, int pricePerSquare) {
        this.rooms = rooms;
        this.squares = squares;
        this.pricePerSquare = pricePerSquare;
    }

    public boolean largerThan(Apartment apt){
        if(this.squares > apt.squares){
            return true;
        }
        return false;
    }
    
    public int priceDifference(Apartment compared){
        int price = this.squares * this.pricePerSquare;
        int comparedPrice = compared.squares * compared.pricePerSquare;
        return Math.abs(price - comparedPrice);
    }
    
    public boolean moreExpensiveThan(Apartment compared){
        if(this.squares * this.pricePerSquare > compared.squares * compared.pricePerSquare){
            return true;
        }
        return false;
    }
    
}
