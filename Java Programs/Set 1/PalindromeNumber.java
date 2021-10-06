import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        int num, i, sum = 0;
        num = n;
        while (n != 0) {
            i = n % 10;
            sum = sum * 10 + i;
            n = n / 10;
        }
        if (num == sum)
            System.out.println(num + " is palindrome number");
        else
            System.out.println(num + " is not palindrome number");
    }
}