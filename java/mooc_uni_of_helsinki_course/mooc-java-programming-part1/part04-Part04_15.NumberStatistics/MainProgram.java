
import java.util.Scanner;

public class MainProgram {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        // you can write test code here
        // however, remove all unnecessary code when doing the final parts of the exercise

        // In order for the tests to work, the objects must be created in the
        // correct order in the main program. First the object that tracks the total
        // sum, secondly the object that tracks the sum of even numbers, 
        // and lastly the one that tracks the sum of odd numbers!
        System.out.println("Enter numbers:");
        Statistics sumStats = new Statistics();
        Statistics evenSumStats = new Statistics();
        Statistics oddSumStats = new Statistics();
        
        int input = Integer.valueOf(scanner.nextLine());
        if(input != -1){
            sumStats.addNumber(input);
            if(input%2 == 0){
                evenSumStats.addNumber(input);
            } else {
                oddSumStats.addNumber(input);
            }
            while(true){
                input = Integer.valueOf(scanner.nextLine());
                if(input == -1){
                    break;
                }
                sumStats.addNumber(input);
                if(input%2 == 0){
                    evenSumStats.addNumber(input);
                } else {
                    oddSumStats.addNumber(input);
                }
            }
            System.out.println("Sum: " + sumStats.sum());
            System.out.println("Sum of even numbers: " + evenSumStats.sum());
            System.out.println("Sum of odd numbers: " + oddSumStats.sum());
        }

        
    }
}
