
import java.util.Scanner;

public class LiquidContainers {
    
    
    
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int firstContainer = 0;
        int secondContainer = 0;
        while (true) {
            System.out.println("First: " + firstContainer + "/100");
            System.out.println("Second: " + secondContainer + "/100");

            String input = scan.nextLine();
            String[] parts = input.split(" ");
            if (parts[0].equals("quit")) {
                break;
            } else if (parts[0].equals("add")){
                int addVal = Integer.valueOf(parts[1]);
                if (addVal >= 0){
                    if(firstContainer + addVal <= 100){
                        firstContainer += addVal;
                    } else{
                        firstContainer = 100;
                    }                    
                }                
            } else if (parts[0].equals("move")){
                int moveVal = Integer.valueOf(parts[1]);
                if (moveVal > 0){
                    if(firstContainer < moveVal){
                        moveVal = firstContainer;
                        firstContainer = 0;
                    } else if (firstContainer > moveVal){
                        firstContainer -= moveVal;
                    }
                    if(secondContainer + moveVal > 100){
                        secondContainer = 100;
                    } else {
                        secondContainer += moveVal;
                    }
                }
            } else if (parts[0].equals("remove")){
                int removeVal = Integer.valueOf(parts[1]);
                if(removeVal > 0){
                    if(removeVal <= secondContainer){
                        secondContainer -= removeVal;
                    } else {
                        secondContainer = 0;
                    }
                }
            }

        }
    }

}
