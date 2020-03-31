import java.util.*;

public class IMORanking
{

    public static void main(String[] args)
    {

        // Array of Array which stores marks for each team, with six subjects each.
        int[][] marks = { { 39, 40, 17, 35, 42, 6 }, { 40, 41, 27, 41, 42, 36 }, { 42, 40, 26, 42, 42, 35 } };

// Individual Subject Marks Calculations.

        TreeMap<Integer, Integer> marksFreq = new TreeMap<>(Collections.reverseOrder()); // stores marks Occurrences in
        // descending order

        HashMap<Integer, Integer> marksRank = new HashMap<>(); // stores rank of each subject

        calculateMarksFreq(marks, marksFreq);

        calculateRank(marksFreq, marksRank);

// Team Data Calculations
        int[] teamTotal = new int[marks.length]; // Array to store team Total Marks.

        TreeMap<Integer, Integer> teamTotalFreq = new TreeMap<>(Collections.reverseOrder()); // stores team total
        // Occurrences in
        // descending order

        HashMap<Integer, Integer> teamRank = new HashMap<>(); // stores rank of team totals

        calculateTeamTotal(marks, teamTotal);

        calculateTeamTotalFrequency(teamTotal, teamTotalFreq);

        calculateRank(teamTotalFreq, teamRank);

        printTeamRankData(marks, teamTotal, teamRank, marksRank);

    }

    private static void calculateMarksFreq(int[][] marks, TreeMap<Integer, Integer> marksFreq)
    {
        // function calculates marks frequency by storing data in TreeMap which will be
        // in sorted order
        // descending further useful to evaluate ranking as well.

        for (int i = 0; i < marks.length; i++)
        {
            for (int j = 0; j < marks[i].length; j++)
            {
                if (marksFreq.get(marks[i][j]) == null)
                {
                    marksFreq.put(marks[i][j], 1);
                }
                else
                {
                    marksFreq.put(marks[i][j], 1 + marksFreq.get(marks[i][j]));
                }
            }
        }
    }

    private static void calculateRank(TreeMap<Integer, Integer> teamTotalFreq, HashMap<Integer, Integer> teamRank)
    {
        // Rank is calculated by parsing Tree Map with occurrences count starting with 1

        int rank = 1;

        for (Map.Entry<Integer, Integer> entry : teamTotalFreq.entrySet())
        {
            teamRank.put(entry.getKey(), rank);
            rank += entry.getValue();
        }
    }

    private static void calculateTeamTotalFrequency(int[] teamTotal, TreeMap<Integer, Integer> teamTotalFreq)
    {
        // function calculates teamTotal frequency by storing data in TreeMap which will
        // be in sorted order
        // descending further useful to evaluate ranking as well.
        for (int i = 0; i < teamTotal.length; i++)
        {
            if (teamTotalFreq.get(teamTotal[i]) == null)
            {
                teamTotalFreq.put(teamTotal[i], 1);
            }
            else
            {
                teamTotalFreq.put(teamTotal[i], 1 + teamTotalFreq.get(teamTotal[i]));
            }
        }
    }

    private static void calculateTeamTotal(int[][] marks, int[] teamTotal)
    {
        // Calculate team total for all the subjects.
        for (int i = 0; i < marks.length; i++)
        {
            for (int j = 0; j < marks[i].length; j++)
            {
                teamTotal[i] += marks[i][j];
            }
        }
    }

    private static void printTeamRankData(int[][] marks, int[] teamTotal, HashMap<Integer, Integer> teamRank,
                                          HashMap<Integer, Integer> marksRank)
    {

        // Formatting data in the required format
        System.out.println("The Ranking List:");

        System.out.format("%15s%7s%7s%7s%7s%7s%7s%7s", "P1", "P2", "P3", "P4", "P5", "P6", "Total", "Rank");
        System.out.println();

        for (int i = 0; i < marks.length; i++)
        {
            System.out.format("%10s", "Team " + i + " ");
            for (int j = 0; j < marks[i].length; j++)
            {
                System.out.format("%7s", marks[i][j] + "(" + marksRank.get(marks[i][j]) + ") ");

            }
            System.out.format("%4s%7s", teamTotal[i], teamRank.get(teamTotal[i]));
            System.out.println();
        }
    }

}
