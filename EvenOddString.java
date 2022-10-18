import java.util.Scanner;

public class EvenOddString {
    //  take a string
    //  concatenate the even index chars to the front, and the odd ones to the back
    //  repeat step 2
    //  what is the minimum number of rounds needed for string to return to original?
    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);
        String str = scanner.nextLine();
        String original = str;
        int round = 0;

        do{
            String odd = "";
            String even = "";
            for (int i = 0; i < str.length();i++){
                if (i%2==0){
                    even += str.charAt(i);
                }
                else{
                    odd += str.charAt(i);
                }
            }
            str = even + odd;
            round++;
            System.out.println(str);
        }
        while (!str.equals(original));
        System.out.println(round);
    }
}
