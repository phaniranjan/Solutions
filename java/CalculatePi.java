/*
Write a program that calculates an approximation for pi.

An approximate value for pi can be used by this series: pi = 4 ( 1 - (1/3) + (1/5) - (1/7) + (1/9) - (1/11) +....). Write a program that asks a user to enter the number of times to loop through this formula.

Display ALL results for the first 50 iterations. After the first 50 iterations of the loop, display the output less frequently: only on multiples of 100 and the iteration after (ex: 100, 101, 200, 201...). Always display the final iteration

*/
#============== CalculatePi ,java ================

import java.util.Scanner;

public class CalculatePi
{

    public static void main(String[] args)
    {

        Scanner inScanner = new Scanner(System.in);

        System.out.print("Enter the number iterations for precise calcaulation of PI value : ");
        long noIterations = inScanner.nextLong(); // long to accept huge values for iteration.

        double piValue = calculatePi(noIterations);
        System.out.println("Pi Value :=" + piValue);
    }

    static double calculatePi(long iterCount)
    {
        double piFraction = 0.0;

        for (long i = 1; i <= iterCount; i++)
        {
            if ((i % 2) == 0)
            {
                piFraction += -1.0 / (2 * i - 1); // Calculates floating division for -1/3 -1/7 -1/11 and so on.
            }
            else
            {
                piFraction += 1.0 / (2 * i - 1); // Calculates floating division for 1 -1/5 -1/9 and so on
            }
            if ((i <= 50) || (i % 100 == 0) || ((i - 1) % 100 == 0)) // intermediate pi value from 1 to 50 and then 100
                // multiples and next iteration after 100 multiple
            {
                System.out.println("Iteration : " + i + " Pi Value : " + 4 * piFraction);
            }
        }

        return 4 * piFraction;

    }

}
