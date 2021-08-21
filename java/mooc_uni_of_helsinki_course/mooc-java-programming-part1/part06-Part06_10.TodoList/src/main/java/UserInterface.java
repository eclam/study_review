
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
    private TodoList list;
    private Scanner scanner;
    
    public UserInterface(TodoList list, Scanner scanner){
        this.list = list;
        this.scanner = scanner;
    }
    
    
    public void start(){
        while(true){
            System.out.print("Command: ");
            String scanned = this.scanner.nextLine();
            if(scanned.equals("stop")){
                return;
            } else if (scanned.equals("add")) {
                System.out.print("To add: ");
                String toAdd = this.scanner.nextLine();
                this.list.add(toAdd);
            } else if(scanned.equals("list")){
                this.list.print();                
            } else if (scanned.equals("remove")){
                System.out.print("Which one is removed? ");
                int index = Integer.valueOf(this.scanner.nextLine());
                this.list.remove(index);
            } else {
                System.out.println("Unknown command");
            }
        }
    }
}
