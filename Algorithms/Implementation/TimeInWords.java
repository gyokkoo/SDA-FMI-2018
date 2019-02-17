import java.io.*;
import java.util.*;

/*
    https://www.hackerrank.com/challenges/the-time-in-words/problem
 */

public class TimeInWords {

    private static final String TIME_WORDS[] = {
            "",
            "one",
            "two",
            "three",
            "four",
            "five",
            "six",
            "seven",
            "eight",
            "nine",
            "ten",
            "eleven",
            "twelve",
            "thirteen",
            "fourteen",
            "fifteen",
            "sixteen",
            "seventeen",
            "eighteen",
            "nineteen",
            "twenty",
            "twenty one",
            "twenty two",
            "twenty three",
            "twenty four",
            "twenty five",
            "twenty six",
            "twenty seven",
            "twenty eight",
            "twenty nine"
    };

    // Complete the timeInWords function below.
    private static String timeInWords(int hours, int minutes) {
        if (minutes == 0) {
            return TIME_WORDS[hours] + " o' clock";
        } else if (minutes == 15) {
            return "quarter past " + TIME_WORDS[hours];
        } else if (minutes == 30) {
            return "half past " + TIME_WORDS[hours];
        } else if (minutes == 45) {
            return "quarter to " + TIME_WORDS[hours + 1];
        } else if (minutes == 1) {
            return TIME_WORDS[minutes] + " minutes past " + TIME_WORDS[hours];
        } else if (minutes < 30) {
            return TIME_WORDS[minutes] + " minutes past " + TIME_WORDS[hours];
        } else {
            return TIME_WORDS[60 - minutes] + " minutes to " + TIME_WORDS[hours + 1];
        }
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {

        int h = scanner.nextInt();

        int m = scanner.nextInt();

        String result = timeInWords(h, m);

        System.out.println(result);

        scanner.close();
    }
}
