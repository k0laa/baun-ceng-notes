package Algorithms;

public class SortAlgorithms {
    //Bubble Sort
    public int[] BubbleSort(int[] arr) {
        int n = arr.length;
        for (int i = 0; i < n; i++) { // sırayla her elemanı kontrol etmek için
            for (int j = 0; j < n - i - 1; j++) {  // -i çünkü her seferinde en büyük eleman en sona gidecek
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
        return arr;
    }
        // Quick Sort
    public int[] QuickSort(int[] arr) {
        return QuickSort(arr, 0, arr.length - 1);
    }
    private int[] QuickSort(int[] arr, int low, int high) {
        if (low < high) {
            int pi = partition(arr, low, high);

            QuickSort(arr, low, pi - 1);
            QuickSort(arr, pi + 1, high);
        }
        return arr;
    }

    private int partition(int[] arr, int low, int high) {
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (arr[j] < arr[high]) {
                ++i;
                swap(arr, i, j);
            }
        }
        swap(arr, i + 1, high);
        return i + 1;
    }

    private void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }


}
