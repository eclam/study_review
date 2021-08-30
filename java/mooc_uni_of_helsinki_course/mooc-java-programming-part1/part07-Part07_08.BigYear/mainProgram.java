
import java.util.Scanner;

public class mainProgram {

    public static void main(String[] args) {
        // NB! Do not create other scanner objects than the one below
        // if and when you create other classes, pass the scanner to them
        // as a parameter
        Birds birds = new Birds();
        Scanner scan = new Scanner(System.in);
        while(true){
            System.out.print("? ");
            String cmd = scan.nextLine();
            
            if(cmd.equals("Quit")){
                break;
            } else if(cmd.equals("Add")){
                System.out.print("Name: ");
                String name = scan.nextLine();
                System.out.println("");
                
                System.out.print("Name in Latin: ");
                String latinName = scan.nextLine();
                System.out.println("");
                
                birds.add(name, latinName);
            } else if (cmd.equals("Observation")){
                String name = scan.nextLine();
                if(!birds.observation(name)){
                    System.out.println("Not a bird!");
                }
            } else if (cmd.equals("All")) {
                birds.all();
            } else if (cmd.equals("One")) {
                System.out.print("Bird? ");
                String name = scan.nextLine();
                System.out.println("");
                birds.one(name);
                
            }
        }
        
        
    }

}
