import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;
import java.util.Arrays;

public class Solution
{

    // Complete the maxMin function below.
    static int maxMin(int k, int[] arr)
    {
        int [] sortedArr= arr.clone();
        Arrays.sort(sortedArr); // Sort the Array
        int minMax = Integer.MAX_VALUE;

        for(int i=0; i<=sortedArr.length-k; i++) // Loop through sorted array to find the minMax of
        {
            if((sortedArr[i+k-1] - sortedArr[i])< minMax) //subarray last kth element diff with first element
            {
                minMax = (sortedArr[k+i-1]-sortedArr[i]);
            }
            System.out.println(sortedArr[i] + " " + sortedArr[i+k-1] + " "+minMax);
        }
        return minMax;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException
    {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int n = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        int k = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        int[] arr = new int[n];

        for (int i = 0; i < n; i++)
        {
            int arrItem = scanner.nextInt();
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");
            arr[i] = arrItem;
        }

        int result = maxMin(k, arr);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
