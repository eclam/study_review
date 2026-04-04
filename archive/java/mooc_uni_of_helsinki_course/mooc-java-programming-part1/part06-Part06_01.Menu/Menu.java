
import java.util.ArrayList;

public class Menu {

    private ArrayList<String> meals;

    public Menu() {
        this.meals = new ArrayList<>();
    }

    public void addMeal(String foodName){
        if(!this.meals.contains(foodName)){
            this.meals.add(foodName);
        }
    }
    
    public void printMeals(){
        for(String meal : this.meals){
            System.out.println(meal);
        }
    }
    
    public void clearMenu(){
        this.meals.clear();
    }
    
    // implement the required methods here
}
