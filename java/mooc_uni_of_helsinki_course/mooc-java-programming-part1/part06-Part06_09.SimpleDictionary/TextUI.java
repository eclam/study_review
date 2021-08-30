
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
public class TextUI {
    private Scanner scanner;
    private SimpleDictionary dictionary;
    
    public TextUI(Scanner scan, SimpleDictionary dict){
        this.scanner = scan;
        this.dictionary = dict;
    }
    
    
    public void start(){
        while(true){
            System.out.print("Command: ");
            String scanned = this.scanner.nextLine();
            if(scanned.equals("end")){
                System.out.println("Bye bye!");
                return;
            } else if (scanned.equals("add")) {
                System.out.print("Word: ");
                String word = this.scanner.nextLine();
                
                System.out.print("Translation: ");
                String translation = this.scanner.nextLine();
                this.dictionary.add(word, translation);
            } else if(scanned.equals("search")){
                System.out.print("To be translated: ");
                String toBeTranslated = this.scanner.nextLine();
                String result = this.dictionary.translate(toBeTranslated);
                if(result != null){
                    System.out.println("Translation: " + result);
                } else {
                    System.out.println("Word " + toBeTranslated + " was not found");
                }
                
                
            } else {
                System.out.println("Unknown command");
            }
        }
    }
}
