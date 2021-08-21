
import java.util.ArrayList;
import java.util.Scanner;

public class PersonalDetails {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String longestName = "";
        int sum = 0;
        int count = 0;
        while(true){
            String input = scanner.nextLine();
            if(input.equals("")){
                break;
            }
            String[] parts = input.split(",");
            if(longestName.length() < parts[0].length()){
                longestName = parts[0];
            }
            sum += Integer.valueOf(parts[1]);
            count += 1;
        }
        System.out.println("Longest name: " + longestName);
        System.out.println("Average of birth years: " + ((float)sum)/count);
    }
}
