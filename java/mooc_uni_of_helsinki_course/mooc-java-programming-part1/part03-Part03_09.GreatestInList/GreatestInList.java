
import java.util.ArrayList;
import java.util.Scanner;

public class GreatestInList {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        ArrayList<Integer> list = new ArrayList<>();
        int largestNum = -1;
        while (true) {
            int input = Integer.valueOf(scanner.nextLine());
            if (input == -1) {
                break;
            }

            list.add(input);
            if(largestNum < input){
                largestNum = input;
            }
        }
        
        System.out.println("");

        // implement finding the greatest number in the list here
        System.out.println("The greatest number: "+largestNum);
    }
}
