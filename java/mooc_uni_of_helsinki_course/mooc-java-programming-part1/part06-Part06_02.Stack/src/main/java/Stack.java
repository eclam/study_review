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

public class Stack {
    private ArrayList<String> stack;
    
    public Stack(){
        this.stack = new ArrayList<>();
    }
    
    public boolean isEmpty(){
        if(this.stack.isEmpty()){
            return true;
        }
        return false;
    }
    
    public ArrayList<String> values(){
        return this.stack;
    }
    
    public void add(String val){
        this.stack.add(val);
    }
    
    public String take(){
        if(this.stack.size()> 0){
            int lastIndex = this.stack.size()-1;
            String result = this.stack.get(lastIndex);
            this.stack.remove(lastIndex);
            return result;            
        }
        return null;
    }
    
}
