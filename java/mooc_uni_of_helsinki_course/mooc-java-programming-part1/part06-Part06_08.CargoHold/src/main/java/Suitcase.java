/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author eric
 */
import java.util.ArrayList;

public class Suitcase {
    private int maxWeight;
    private int totalWeight;
    private ArrayList<Item> items;
    
    public Suitcase(int maxWeight){
        this.maxWeight = maxWeight;
        this.items = new ArrayList<>();
        this.totalWeight = 0;
        
    }
    
    public void addItem(Item item){
        int itemWeight = item.getWeight();
        
        if(itemWeight + this.totalWeight > maxWeight){
           return; 
        }
        
        this.totalWeight += itemWeight;
        this.items.add(item);
    }
    
    public String toString(){
        int totalItems = this.items.size();
        if(totalItems == 0){
            return "no items (0 kg)";
        }
        String itemsString = "items";
        if(totalItems == 1){
            itemsString = "item";
        }
        return totalItems + " "+ itemsString + " (" + this.totalWeight + " kg)";
        
    }
    
    public void printItems(){
        for(Item item : this.items){
            System.out.println(item.getName() + "(" + item.getWeight() + " kg)");
        }
    }
    
    public int totalWeight(){
        return this.totalWeight;
    }
    
    public Item heaviestItem(){
        if(this.items.isEmpty()){
            return null;
        }
        int weight = 0;
        Item resultItem = null;
        for(Item item : this.items){
            int weightComparison = item.getWeight();
            if(weightComparison > weight){
                weight = weightComparison;
                resultItem = item;
            }
        }
        return resultItem;
    }
}
