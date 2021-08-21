import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

public class Main {
    public static void sort(int[] arr){
        Arrays.sort(arr);
    }
    
    public static void sort(String[] arr){
        Arrays.sort(arr);
    }
    
    public static void sortIntegers(ArrayList<Integer> integers){
        Collections.sort(integers);
    }
    
    public static void sortStrings(ArrayList<String> strings){
        Collections.sort(strings);
    }
    
    public static void main(String[] args) {
        // insert test code here
        int[] array = {3, 1, 5, 99, 3, 12};
        Main.sort(array);
        System.out.println(Arrays.toString(array));
        
        String[] stringArr = {"fdsfxc", "z", "cvoiu", "coi", "vicu", "oasieruguio"};
        Main.sort(stringArr);
        System.out.println(Arrays.toString(stringArr));
        
        ArrayList<Integer> nums = new ArrayList<>();
        nums.add(3);
        nums.add(1);
        nums.add(5);
        nums.add(99);
        nums.add(3);
        nums.add(12);
        Main.sortIntegers(nums);
        System.out.println(nums);
        
        ArrayList<String> words = new ArrayList<>();
        words.add("fdsfxc");
        words.add("z");
        words.add("cvoiu");
        words.add("vicu");
        words.add("oasieruguio");
        words.add("coi");
        Main.sortStrings(words);
        System.out.println(words);
        
        
    }

}
