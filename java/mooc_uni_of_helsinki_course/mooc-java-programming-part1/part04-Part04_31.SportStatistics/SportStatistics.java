
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.Scanner;

public class SportStatistics {

    
    
    
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.println("File:");
        String fileName = scan.nextLine();
        System.out.println("Team:");
        String teamName = scan.nextLine();
        
        int games = 0, losses = 0, wins = 0;
        try(Scanner fileScan = new Scanner(Paths.get(fileName))){
            while(fileScan.hasNextLine()){
                String line = fileScan.nextLine();
                String[] parts = line.split(",");

                int homeScore = Integer.valueOf(parts[2]);
                int visitorScore = Integer.valueOf(parts[3]);
  
                if(parts[0].equals(teamName)){
                    games++;
                    if(homeScore > visitorScore){
                        wins++;
                    } else {
                        losses++;
                    }
                } else if(parts[1].equals(teamName)){
                    games++;
                    if(visitorScore > homeScore){
                        wins++;
                    } else {
                        losses++;
                    }
                }
            }
            System.out.println("Games: " + games);
            System.out.println("Wins: " + wins);
            System.out.println("Losses: " + losses);
        } catch(Exception e){
            System.out.println("Error: " + e.getMessage());
        }
    }

}
