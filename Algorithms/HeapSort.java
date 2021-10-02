public class HeapSort {
    public void sort(int arr[])
    {
        int n = arr.length;
 
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(arr, n, i);
 
        // One by one extract an element from heap
        for (int i = n - 1; i > 0; i--) {
            // Move current root to end
            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;

            heapify(arr, i, 0);
        }
    }

    void heapify(int arr[], int n, int i)
    {
        int large = i;
        int l = 2 * i + 1; // left = 2*i + 1
        int r = 2 * i + 2; // right = 2*i + 2
        if (l < n && arr[l] > arr[large])
            large = l;
        if (r < n && arr[r] > arr[large])
            large = r;
 
        if (large != i) {
            int swap = arr[i];
            arr[i] = arr[large];
            arr[large] = swap;
            heapify(arr, n, large);
        }
    }
    static void printArrayList(int arr[])
    {
        int n = arr.length;
        for (int i = 0; i < n; ++i)
            System.out.print(arr[i] + "  ");
        System.out.println();
    }
 
    // Driver code
    public static void main(String args[])
    {
        int arr[] = { 12, 11, 13, 5, 6, 7 };
        int n = arr.length;
 
        HeapSort ob = new HeapSort();
        ob.sort(arr);
 
        System.out.println("Sorted array by heap sort is");
        printArrayList(arr);
    }
}
