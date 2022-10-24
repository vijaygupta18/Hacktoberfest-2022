import java.util.Scanner;

class Main {

  /*
  s = aabbbcc
  out = a2b3c2
  
  s = aabbbcca
  out = a2b3c2a1
  */

  public static String format_string_with_char_count(String s) {
    int count = 1;
    char[] cArr = s.toCharArray();
    String out = "";
    int i;
    for (i = 0; i < s.length() - 1; i++) {
      if (cArr[i] == cArr[i + 1]) {
        count++;
      } else {
        out = out + cArr[i] + String.valueOf(count);
        count = 1;
      }
    }
    out = out + cArr[i] + String.valueOf(count);
    return out;
  }

  public static void main(String args[]) {

    Scanner in = new Scanner(System.in);
    System.out.print("Enter the string: ");
    String s = in .nextLine();

    System.out.println("Output: string with char count");
    System.out.println(format_string_with_char_count(s));
  }
}
