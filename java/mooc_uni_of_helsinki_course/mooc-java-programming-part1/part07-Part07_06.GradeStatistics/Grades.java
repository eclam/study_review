
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
import java.util.ArrayList;
public class Grades {
    
    private ArrayList<Integer> grades;
    private ArrayList<Integer> points;
    private ArrayList<Integer> passingPoints;
    
    public Grades() {
        this.grades = new ArrayList<>();
        this.points = new ArrayList<>();
        this.passingPoints = new ArrayList<>();
    }

    public void addGradeBasedOnPoints(int points) {
        if(points < 0 || points > 100){
            return;
        }
        this.points.add(points);
        if(points >= 50){
            this.passingPoints.add(points);
        }
        this.grades.add(pointsToGrade(points));
    }

    public int numberOfGrades(int grade) {
        int count = 0;
        for (int received : this.grades) {
            if (received == grade) {
                count++;
            }
        }

        return count;
    }

    public static int pointsToGrade(int points) {

        int grade = 0;
        if (points < 50) {
            grade = 0;
        } else if (points < 60) {
            grade = 1;
        } else if (points < 70) {
            grade = 2;
        } else if (points < 80) {
            grade = 3;
        } else if (points < 90) {
            grade = 4;
        } else {
            grade = 5;
        }

        return grade;
    }
    
    public double averageOfPoints(){
        if(this.points.isEmpty()){
            return -1;
        }
        int sum = 0;
        for(int point : this.points){
            sum += point;
        }
        return (double)sum/this.points.size();
    }
    
    public double averageOfPassingPoints(){
        if(this.passingPoints.isEmpty()){
            return -1;
        }
        int sum = 0;
        for(int point : this.passingPoints){
            sum += point;
        }
        return (double)sum/this.passingPoints.size();
    }
    
    public double passPercentage(){
        return ((double)this.passingPoints.size()/this.points.size())*100;
    }
    
    public void gradesDistribution(){
        System.out.println("Grade distribution:");
        int[] arr = {0, 0, 0, 0, 0, 0};
        for(int grade : this.grades){
            if (grade == 5){
                arr[5]++;
            } else if (grade == 4){
                arr[4]++;
            } else if (grade == 3){
                arr[3]++;
            } else if (grade == 2){
                arr[2]++;
            } else if (grade == 1){
                arr[1]++;
            } else if (grade == 0){
                arr[0]++;
            }
        }
        
        for (int i = arr.length-1; i >= 0; i--) {
            System.out.print( i +": ");
            
            for (int j = 0; j < arr[i]; j++) {
                System.out.print("*");
            }
            System.out.println("");
        }
    }
}
