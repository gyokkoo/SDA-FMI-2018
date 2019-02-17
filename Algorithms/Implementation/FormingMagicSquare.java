import java.util.*;

public class FormingMagicSquare {

    private static final int N = 3;

    private static final int[][][] ALL_PERMUTATIONS = {
            {{8, 1, 6}, {3, 5, 7}, {4, 9, 2}},

            {{6, 1, 8}, {7, 5, 3}, {2, 9, 4}},

            {{4, 9, 2}, {3, 5, 7}, {8, 1, 6}},

            {{2, 9, 4}, {7, 5, 3}, {6, 1, 8}},

            {{8, 3, 4}, {1, 5, 9}, {6, 7, 2}},

            {{4, 3, 8}, {9, 5, 1}, {2, 7, 6}},

            {{6, 7, 2}, {1, 5, 9}, {8, 3, 4}},

            {{2, 7, 6}, {9, 5, 1}, {4, 3, 8}},
    };

    // Complete the formingMagicSquare function below.
    private static int formingMagicSquare(int[][] matrix) {
        int minimumCost = Integer.MAX_VALUE;

        for (int[][] permutation : ALL_PERMUTATIONS) {
            int permutationCost = 0;

            for (int row = 0; row < N; row++) {
                for (int col = 0; col < N; col++) {
                    permutationCost += Math.abs(matrix[row][col] - permutation[row][col]);
                }
            }

            if (permutationCost < minimumCost) {
                minimumCost = permutationCost;
            }
        }

        return minimumCost;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {

        int[][] s = new int[N][N];

        for (int i = 0; i < N; i++) {
            String[] sRowItems = scanner.nextLine().split(" ");

            for (int j = 0; j < N; j++) {
                int sItem = Integer.parseInt(sRowItems[j]);
                s[i][j] = sItem;
            }
        }

        int result = formingMagicSquare(s);

        System.out.println(result);

        scanner.close();
    }
}
