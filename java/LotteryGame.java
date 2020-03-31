import java.util.HashSet;

public class LotteryGame
{

    public static void main(String[] args)
    {
        float[] pickNumbers1 = { 4, 8, 2 };
        float[] pickNumbers2 = { 4, 8, 8 };
        float[] pickNumbers3 = { 8, 8, 8 };
        float[] pickNumbers4 = { 1, 3, 5 };
        float[] winNumbers = { 8, 2, 4 };

        System.out.println("Lottery Win Amount for pickNumbers1 : " + lottery3(pickNumbers1, winNumbers));
        System.out.println("Lottery Win Amount for pickNumbers2 : " + lottery3(pickNumbers2, winNumbers));
        System.out.println("Lottery Win Amount for pickNumbers3 : " + lottery3(pickNumbers3, winNumbers));
        System.out.println("Lottery Win Amount for pickNumbers4 : " + lottery3(pickNumbers4, winNumbers));
    }

    static int lottery3(float[] pickNumbers, float[] winNumbers)
    {
        if (pickNumbers.length != 3 && winNumbers.length != 3)
            return 0;

        int winMatchCount = 0;
        int winAmount = 0;

        // HashSet is chosen as we need to count repetetions as only one
        // like if in {8,8,8} only once it is counted for win amount with {8} set
        // {4,8,8} here 8 counted only once and win amount calculated with {8,4} set
        HashSet<Float> pickNumbersSet = new HashSet<>();

        for (int i = 0; i < pickNumbers.length; i++)
        {
            pickNumbersSet.add(pickNumbers[i]);
        }

        // From hashset the unique values are calculated for win amount matching with winNumbers array.
        for (Float num : pickNumbersSet)
        {
            for (int i = 0; i < winNumbers.length; i++)
            {
                if (num == winNumbers[i])
                    winMatchCount++;
            }
        }

        // Switch case to calculate the win amount.
        switch (winMatchCount)
        {
        case 3:
            winAmount = 1000;
            break;
        case 2:
            winAmount = 10;
            break;
        case 1:
            winAmount = 1;
            break;
        case 0:
        default:
            winAmount = 0;
        }

        return winAmount;
    }

}
