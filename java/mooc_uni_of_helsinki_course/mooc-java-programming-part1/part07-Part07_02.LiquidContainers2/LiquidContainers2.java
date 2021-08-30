
import java.util.Scanner;

public class LiquidContainers2 {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        
        Container firstContainer = new Container();
        Container secondContainer = new Container();
        
        while (true) {
            System.out.println("First: " + firstContainer);
            System.out.println("Second: " + secondContainer);

            String input = scan.nextLine();
            String[] parts = input.split(" ");
            if (parts[0].equals("quit")) {
                break;
            } else if (parts[0].equals("add")){
                int addVal = Integer.valueOf(parts[1]);
                firstContainer.add(addVal);
            } else if (parts[0].equals("move")){
                int moveVal = Integer.valueOf(parts[1]);                
                if (moveVal > 0){
                    if(firstContainer.contains() < moveVal){
                        moveVal = firstContainer.contains();   
                    }
                    firstContainer.remove(moveVal);
                    
                    secondContainer.add(moveVal);
                }
            } else if (parts[0].equals("remove")){
                int removeVal = Integer.valueOf(parts[1]);
                secondContainer.remove(removeVal);
            }
            System.out.println("");

        }
    }

}
