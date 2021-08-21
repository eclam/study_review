
import java.util.Arrays;


public class MainProgram {
    public static int smallest(int[] arr){
        int smallest = Integer.MAX_VALUE;
        for(int i : arr){
            if(i < smallest){
                smallest = i;
            }
        }
        return smallest;
    }
    
    public static int indexOfSmallest(int[] arr){
        int smallest = Integer.MAX_VALUE;
        int index = arr.length;
        for (int i = 0; i < arr.length; i++) {
            if(arr[i] < smallest){
                smallest = arr[i];
                index = i;
            }
        }
        return index;
    }
    
    public static int indexOfSmallestFrom(int[] arr, int startIndex) {
        int smallest = Integer.MAX_VALUE;
        int index = arr.length;
        for (int i = startIndex; i < arr.length; i++) {
            if(arr[i] < smallest){
                smallest = arr[i];
                index = i;
            }
        }
        return index;
    }
    
    public static void swap(int[] arr, int index1, int index2) {
        int temp = arr[index1];
        arr[index1] = arr[index2];
        arr[index2] = temp;
    }
    
    public static void sort(int[] arr){
        for (int i = 0; i < arr.length; i++) {
            System.out.println(Arrays.toString(arr));
            int smallestIndex = MainProgram.indexOfSmallestFrom(arr, i);
            MainProgram.swap(arr, i, smallestIndex);
        }
    }
    
    public static void main(String[] args) {
        // write your test code here
        int[] numbers = {6, 5, 8, 7, 11};

        System.out.println("Smallest: " + MainProgram.smallest(numbers));
        System.out.println("Index of the smallest number: " + MainProgram.indexOfSmallest(numbers));
        
        int[] numbers1 = {-1, 6, 9, 8, 12};
        System.out.println(MainProgram.indexOfSmallestFrom(numbers1, 0));
        System.out.println(MainProgram.indexOfSmallestFrom(numbers1, 1));
        System.out.println(MainProgram.indexOfSmallestFrom(numbers1, 2));
        
        
        int[] numbers2 = {3, 2, 5, 4, 8};
        System.out.println(Arrays.toString(numbers2));

        MainProgram.swap(numbers2, 1, 0);
        System.out.println(Arrays.toString(numbers2));

        MainProgram.swap(numbers2, 0, 3);
        System.out.println(Arrays.toString(numbers2));
        
        int[] numbers3 = {8, 3, 7, 9, 1, 2, 4};
        MainProgram.sort(numbers3);
    }

}
