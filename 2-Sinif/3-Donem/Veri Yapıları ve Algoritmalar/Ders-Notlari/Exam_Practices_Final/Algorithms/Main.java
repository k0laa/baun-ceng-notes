package Algorithms;

public class Main {

    public static void main(String[] args) {
        int[] arr = {5,3,0,6,1};
        SortAlgorithms sortAlgorithms = new SortAlgorithms();
        int[] sortedArr = sortAlgorithms.QuickSort(arr);
        for (int i : sortedArr) {
            System.out.println(i);
        }
    }
}
