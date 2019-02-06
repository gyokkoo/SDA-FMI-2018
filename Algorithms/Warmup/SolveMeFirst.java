import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

/*
 * https://www.hackerrank.com/challenges/solve-me-first/problem
 */
public class Solution {

    static int solveMeFirst(int a, int b) {
      	return a + b;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int a = in.nextInt();
        int b = in.nextInt();
        int sum = solveMeFirst(a, b);
        System.out.println(sum);
   }
}
