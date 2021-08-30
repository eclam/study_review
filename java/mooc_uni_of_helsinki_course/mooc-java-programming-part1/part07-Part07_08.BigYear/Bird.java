/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author eric
 */
public class Bird {
    private String name;
    private String latinName;
    private int observations;
    
    public Bird(String name, String latinName){
        this.name = name;
        this.latinName = latinName;
        this.observations = 0;
    }
    
    public String getName(){
        return this.name;
    }
    
    public String getLatinName(){
        return this.latinName;
    }
    
    public void addObservations(){
        this.observations++;
    }
    
    public int getObservationsCount(){
        return this.observations;
    }
    
    public String toString(){
        return this.name + " (" + this.latinName + "): " + this.observations + " observations";
    }
}
