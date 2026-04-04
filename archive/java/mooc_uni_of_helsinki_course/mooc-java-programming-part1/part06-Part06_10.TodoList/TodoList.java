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
public class TodoList {
    private ArrayList<String> todoList;
    
    public TodoList(){
        this.todoList = new ArrayList<>();
    }
    
    public void add(String task){
        this.todoList.add(task);
    }
    
    public void print(){
        int index = 0;
        for(String task : this.todoList){
            index++;
            System.out.println(index + ": " + task);
            
        }
    }
    public void remove(int index){
        this.todoList.remove(index-1);
    }
}
