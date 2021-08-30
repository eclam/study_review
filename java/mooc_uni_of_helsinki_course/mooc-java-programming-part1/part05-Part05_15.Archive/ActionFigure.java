/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author eric
 */
public class ActionFigure {
    private String name;
    private String identifier;
    
    public ActionFigure(String name, String identifier){
        this.name = name;
        this.identifier = identifier;
    }
    
    public boolean equals(Object compare){
        if(this == compare){
            return true;
        }
        if(!(compare instanceof ActionFigure)){
            return false;
        }
        ActionFigure figure = (ActionFigure) compare;
        if(this.identifier.equals(figure.identifier)){
            return true;
        }
        return false;
    }
    public String toString(){
        return this.identifier + ": " + this.name;
    }
}
