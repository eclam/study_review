
import java.util.ArrayList;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author eric
 */
public class Recipe {
    private String recipeName;
    private int cookingTime;
    private ArrayList<String> ingredients;
    
    public Recipe(String recipeName, int cookingTime){
        this.recipeName = recipeName;
        this.cookingTime = cookingTime;
        this.ingredients = new ArrayList<>();
    }
    
    public String getRecipeName(){
        return this.recipeName;
    }
    
    public int getCookingTime(){
        return this.cookingTime;
    }
    
    public void addIngredient(String ingredient){
        this.ingredients.add(ingredient);
    }
    
    public boolean hasIngredient(String ingredient){
        for(String recipeIngredient: this.ingredients){
            if(recipeIngredient.equals(ingredient)){
                return true;
            }
        }
        return false;
    }
    
}
