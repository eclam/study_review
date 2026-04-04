
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
public class MessagingService {
    private ArrayList<Message> msgs;
    
    public MessagingService(){
        this.msgs = new ArrayList<>();
    }
    
    public ArrayList<Message> getMessages(){
        return this.msgs;
    }
    
    public void add(Message message){
        if(message.getContent().length() > 280){
            return;
        }
        this.msgs.add(message);
    }
        
}
