//Binary Search Code in JAVA
class binarySearch {
    // Returns index of element
    int bSearch(int arr[], int l, int r, int x) {
        if (r >= l) {
            int mid = l + (r - l) / 2;
            // If the element is at middle
            if (arr[mid] == x)
                return mid;
            // if the element is greater than mid
            if (x > arr[mid])
                return bSearch(arr, mid + 1, r, x);
            // Else
            return bSearch(arr, l, mid - 1, x);
        }
        return -1;
    }

    public static void main(String args[]) {
        binarySearch b = new binarySearch();
        int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        int n = arr.length;
        int x = 3;
        int ans = b.bSearch(arr, 0, n - 1, x);
        if (ans == -1)
            System.out.println("Element Not in Array");
        else
            System.out.println("Element is Present at " + ans);
    }
}
