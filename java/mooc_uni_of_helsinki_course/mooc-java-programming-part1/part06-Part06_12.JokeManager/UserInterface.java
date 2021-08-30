
import java.util.Scanner;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author eric
 */
public class UserInterface {
    private Scanner scanner;
    private JokeManager manager;
    
    public UserInterface(JokeManager manager, Scanner scanner){
        this.scanner = scanner;
        this.manager = manager;
    }
    
    public void start(){
        
        while(true){
            System.out.println("Commands:");
            System.out.println("1 - add a joke");
            System.out.println("2 - draw a joke");
            System.out.println("3 - list jokes");
            System.out.println("X - stop");
            String option = this.scanner.nextLine();
            
            if(option.equals("1")){
                System.out.println("Write the joke to be added:");
                String input = this.scanner.nextLine();
                this.manager.addJoke(input);
            } else if (option.equals("2")){
                System.out.println(this.manager.drawJoke());
            } else if (option.equals("3")){
                this.manager.printJokes();
            } else if (option.equals("X")){
                return;
            } else {
                System.out.println("Unknown COmmand");
            }
        }
    }
}
