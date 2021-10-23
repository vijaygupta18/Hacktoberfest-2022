// Program to convert temprature from Celsius to Fahrenheit

import java.util.Scanner;

public class temprature_converter {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.println("Please enter temp in C:");
        float tempC = in.nextFloat();
        float tempF = (tempC * 9/5) + 32;
        System.out.println("Temp in F :"+tempF);
    }
}
