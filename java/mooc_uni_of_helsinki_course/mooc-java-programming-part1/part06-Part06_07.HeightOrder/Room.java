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

public class Room {
    private ArrayList<Person> people;
    
    public Room(){
        this.people = new ArrayList<>();
    }
    
    public void add(Person person){
        this.people.add(person);
    }
    
    public boolean isEmpty(){
        return this.people.isEmpty();
    }
    
    public ArrayList<Person> getPersons(){
        return this.people;
    }
    
    public Person shortest(){
        if(this.people.isEmpty()){
            return null;
        }
        int height = Integer.MAX_VALUE;
        Person shortestPerson = null;
        for(Person person : this.people){
            int comparisonHeight = person.getHeight();
            if(comparisonHeight <= height){
                height = comparisonHeight;
                shortestPerson = person;
            }
        }
        return shortestPerson;
    }

    public Person take(){
        if(this.people.isEmpty()){
            return null;
        }
        
        Person shortestPerson = this.shortest();
        this.people.remove(shortestPerson);
        
        return shortestPerson;
    }
    
}
