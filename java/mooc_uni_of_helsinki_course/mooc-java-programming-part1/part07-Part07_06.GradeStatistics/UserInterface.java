
import java.util.Scanner;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author eric
 */
public class UserInterface {
    private Scanner scan;
    private Grades grades;
    
    public UserInterface(Grades grades, Scanner scan){
        this.scan = scan;
        this.grades = grades;
    }
    public UserInterface(Grades grades){
        this.scan = new Scanner(System.in);
        this.grades = grades;
    }
    
    public void start(){
        System.out.println("Enter point totals, -1 stops:");
        while(true){
            int input = Integer.valueOf(this.scan.nextLine());
            if(input == -1){
                System.out.println("Point average (all): " + this.grades.averageOfPoints());
                
                double passingPoints = this.grades.averageOfPassingPoints();
                System.out.print("Point average (passing): ");
                if(passingPoints == -1){
                    System.out.println("-");
                } else {
                    System.out.println(passingPoints);
                }
                
                System.out.println("Pass percentage: " +  this.grades.passPercentage());
                this.grades.gradesDistribution();
                return;
            } else {
                this.grades.addGradeBasedOnPoints(input);
            }
            
        }
    }
}