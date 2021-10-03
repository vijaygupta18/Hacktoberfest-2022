import java.util.*;

public class sortAnArrayWith012 {

    public static void sort012(int a[], int n) {
        int l = 0, h = n - 1;
        int mid = 0, temp = 0;
        while (mid <= h) {
            switch (a[mid]) {
                case 0: {
                    temp = a[l];
                    a[l] = a[mid];
                    a[mid] = temp;
                    l++;
                    mid++;
                    break;
                }
                case 1: {
                    mid++;
                    break;
                }
                case 2: {
                    temp = a[mid];
                    a[mid] = a[h];
                    a[h] = temp;
                    h--;
                    break;
                }
            }
        }
    }

    public static void print(int a[], int n) {

        for (int i = 0; i < n; i++)
            System.out.print(a[i] + " ");

    }

    public static void main(String[] args) {
        int n;
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        int a[] = new int[n];
        for (int i = 0; i < n; i++)
            a[i] = sc.nextInt();
        sort012(a, n);
        print(a, n);
    }
}