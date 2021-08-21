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

public class Hold {
    private ArrayList<Suitcase> suitcases;
    private int maxWeight;
    private int totalWeight;
    
    public Hold(int maxWeight){
        this.suitcases = new ArrayList<>();
        this.maxWeight = maxWeight;
        this.totalWeight = 0;
    }
    
    public void addSuitcase(Suitcase suitcase){
        int suitcaseWeight = suitcase.totalWeight();
        if(totalWeight + suitcaseWeight > maxWeight){
            return;
        }
        
        this.suitcases.add(suitcase);
        this.totalWeight += suitcaseWeight;
    }
    
    public String toString(){
        return this.suitcases.size() + " suitcases (" + this.totalWeight + " kg)";
    }
    
    public void printItems(){
        for(Suitcase suitcase : this.suitcases){
            suitcase.printItems();
        }
    }
    
}
