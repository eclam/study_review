
import java.nio.file.Paths;
import java.util.Scanner;

public class RecordsFromAFile {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Name of the file:");
        String fileName = scanner.nextLine();
        try(Scanner fileScan = new Scanner(Paths.get(fileName))){
            while(fileScan.hasNextLine()){
                String line = fileScan.nextLine();
                String[] parts = line.split(",");
                int age = Integer.valueOf(parts[1]);
                if(age == 1){
                    System.out.println("");
                    System.out.println( parts[0] + ", age: " + age + " year");
                } else {
                    System.out.println( parts[0] + ", age: " + age + " years");
                }
            }
        } catch(Exception e){
            System.out.println("Error : " + e.getMessage());
        }
    }
}
