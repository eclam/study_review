
import java.util.Scanner;

public class DifferentTypesOfInput {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        // Write your program here
        System.out.println("Give a string:");
        String msg = scan.nextLine();
        
        System.out.println("Give an integer:");
        int int_val = Integer.valueOf(scan.nextLine());
        
        System.out.println("Give a double:");
        double double_val = Double.valueOf(scan.nextLine());
        
        System.out.println("Give a boolean:");
        boolean bool_val = Boolean.valueOf(scan.nextLine());
        
        System.out.println("You gave the string " + msg);
        System.out.println("You gave the integer " + int_val);
        System.out.println("You gave the double " + double_val);
        System.out.println("You gave the boolean " + bool_val);
        
    }
}
