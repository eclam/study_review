
import java.util.ArrayList;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        ArrayList<ActionFigure> actionFigures = new ArrayList<>();
        
        while(true){
            System.out.println("Identifier? (empty will stop)");
            String identifier = scanner.nextLine();
            if(identifier.isEmpty()){
                break;
            }
            System.out.println("Name? (empty will stop)");
            String objName = scanner.nextLine();
            if(objName.isEmpty()){
                break;
            }
            ActionFigure figure = new ActionFigure(objName, identifier);
            if(actionFigures.contains(figure)){
                continue;
            } else{
                actionFigures.add(figure);
            }
        }
        for(ActionFigure fig : actionFigures){
            System.out.println(fig);
        }
    }
}
