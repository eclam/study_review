
import java.util.Objects;

public class Person {

    private String name;
    private SimpleDate birthday;
    private int height;
    private int weight;

    public Person(String name, SimpleDate birthday, int height, int weight) {
        this.name = name;
        this.birthday = birthday;
        this.height = height;
        this.weight = weight;
    }

    // implement an equals method here for checking the equality of objects
    public boolean equals(Object compare){
        if(this == compare){
            return true;
        }
        if(!(compare instanceof Person)){
           return false; 
        }
        Person person = (Person)compare;
        
        if(this.name.equals(person.name) &&
           this.birthday.equals(person.birthday) &&
           this.height == person.height &&
           this.weight == person.weight){
            return true;
        }
        return false;
    }
}
