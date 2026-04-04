
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
public class Birds {
    private ArrayList<Bird> birds;
    
    public Birds(){
        this.birds = new ArrayList<Bird>();
    }
    
    public void add(String name, String latinName){
        this.birds.add(new Bird(name, latinName));
    }
    
    public boolean observation(String birdName){
        for (Bird bird : this.birds){
            if(bird.getName().equals(birdName)){
                bird.addObservations();
                return true;
            }
        }
        return false;
    }
    

    public void all(){
        for(Bird bird : this.birds){
            System.out.println(bird);
        }
    }
    
    public void one(String name){
        Bird bird = this.findBird(name);
        System.out.println(bird);
    }
    
    public Bird findBird(String name){
        for(Bird bird : this.birds){
            if(bird.getName().equals(name)){
                return bird;
            }
        }
        return null;
    }
    
}
