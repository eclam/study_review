
import java.nio.file.Paths;
import java.util.ArrayList;
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
public class Recipes {
    private ArrayList<Recipe> recipes;
    
    public Recipes(){
        this.recipes = new ArrayList<Recipe>();
    }
    
    public void processFile(String fileName){
        ArrayList<String> fileContent = new ArrayList<>();
        try (Scanner fileScanner = new Scanner(Paths.get(fileName))) {
            while (fileScanner.hasNextLine()) {
                fileContent.add(fileScanner.nextLine());
            }
        } catch (Exception e) {
            System.out.println("Error");
        }
        fileContent.add(" ");//necessary for consistency of file input
        
        String tempRecipe = "";
        for (int i = 0; i < fileContent.size(); i++) {
            String temp = fileContent.get(i).trim();
            if(temp.isEmpty()){
                String[] parts = tempRecipe.split(", ");
                Recipe recipe = new Recipe(parts[0], Integer.valueOf(parts[1]));
                
                for (int j = 2; j < parts.length; j++) {
                    recipe.addIngredient(parts[j]);
                }
                
                this.recipes.add(recipe);
                tempRecipe = "";
            } else {
                tempRecipe += temp + ", ";
            }
        }
    }
    
    public void list(){
        for(Recipe recipe : this.recipes){
//            System.out.println(line);
            System.out.println(listRecipe(recipe));
        }
    }
    
    public String listRecipe(Recipe recipe){
        return recipe.getRecipeName() + ", cooking time: " + recipe.getCookingTime();
    }
    
    public void searchByName(String searchWord){
        System.out.println("Recipes:");
        for(Recipe recipe : this.recipes){
            String recipeName = recipe.getRecipeName();
            if(recipeName.toLowerCase().contains(searchWord.toLowerCase())){
                System.out.println(this.listRecipe(recipe));;
            }
        }
        System.out.println("");
    }
    
    public void searchByCookingTime(int maxCookingTime){
        System.out.println("Recipes:");
        for(Recipe recipe : this.recipes){
            if(recipe.getCookingTime() <= maxCookingTime){
                System.out.println(this.listRecipe(recipe));;
            }
        }
        System.out.println("");
    }
    
    public void searchByIngredient(String ingredient){
        for(Recipe recipe : this.recipes){
            if(recipe.hasIngredient(ingredient)){
                System.out.println(this.listRecipe(recipe));
            }
        }
    }
}
