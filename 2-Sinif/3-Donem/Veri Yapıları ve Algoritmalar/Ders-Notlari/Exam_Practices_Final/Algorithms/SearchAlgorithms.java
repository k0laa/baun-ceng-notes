package Algorithms;

public class SearchAlgorithms {

    //Binary Search -- Recursive
    public int BinarySearch(int[] arr, int target) {
        return BinarySearch(arr, 0, arr.length, target);
    }

    private int BinarySearch(int[] arr, int from, int to, int target) {
        if (from > to) return -1;

        int mid = (from + to) / 2;

        if (arr[mid] == target) return mid;

        if (arr[mid] < target) return BinarySearch(arr, from, mid - 1, target);

        return BinarySearch(arr, mid + 1, to, target);
    }


    //Jump Search
    public int JumpSearch(int[] arr, int target) {
        int n = arr.length;
        int step = (int) Math.floor(Math.sqrt(n));
        int temp = 0;
        while (arr[temp] < target) {
            if (temp + step < n) temp += step;
            else break;

            if (arr[temp] == target) return temp;
        }
        for (int i = temp - step; i < temp; i++) {
            if (arr[i] == target) {
                return i;
            }
        }
        return -1;
    }
}
