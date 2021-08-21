
import java.io.File;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.Scanner;

public class RecipeSearch {

    public static void start(Recipes recipes, Scanner scanner){
        while(true){
            System.out.print("Enter command: ");
            String cmd = scanner.nextLine();
            System.out.println("");
            
            if (cmd.equals("stop")){
                return;
            } else if (cmd.equals("list")) {
                recipes.list();
            } else if (cmd.equals("find name")){
                System.out.print("Searched word: ");
                String searchWord = scanner.nextLine();
                recipes.searchByName(searchWord);
            } else if (cmd.equals("find cooking time")){
                System.out.print("Max cooking time: ");
                int maxCookingTime = Integer.valueOf(scanner.nextLine());
                recipes.searchByCookingTime(maxCookingTime);
            } else if (cmd.equals("find ingredient")){
                System.out.print("Ingredient: ");
                String ingredient = scanner.nextLine();
                recipes.searchByIngredient(ingredient);
            }
            
        }
    }
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        Recipes recipes = new Recipes();
        
        System.out.print("File to read: ");
        String fileName = scanner.nextLine();
        
        
        recipes.processFile(fileName);

        System.out.println("Commands:");
        System.out.println("list - lists the recipes");
        System.out.println("stop - stops the program");
        System.out.println("find name - searches recipes by name");
        System.out.println("find cooking time - searches recipes by cooking time");
        System.out.println("find ingredient - searches recipes by ingredient");
        System.out.println("");
        
        RecipeSearch.start(recipes, scanner);

        
    }

}
