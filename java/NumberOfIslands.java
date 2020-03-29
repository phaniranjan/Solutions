class Solution
{
    public int numIslands(char[][] grid)
    {

        if(grid==null || grid.length==0)
        {
            return 0;
        }

        int islandsCount = 0;
        for(int i =0; i<grid.length; i++)
        {
            for(int j=0; j<grid[i].length; j++)
            {
                if(grid[i][j]=='1')
                {
                    islandsCount += 1; // First time increment island count
                    MarkIslandAsVisitedDFS(grid,i,j); // mark the remaining connected island as visited and make zero.
                }
            }
        }

        return islandsCount;
    }

    void MarkIslandAsVisitedDFS(char [][] grid, int i, int j)
    {
        if(i<0 || j<0 || i >= grid.length|| j>=grid[i].length || grid[i][j]=='0')
            return; // checking boundary limts to stop iteration

        grid[i][j]='0'; // Marks as zero so wont be counted further.

        MarkIslandAsVisitedDFS(grid, i+1, j); // Right Element
        MarkIslandAsVisitedDFS(grid, i-1, j); // Left Element
        MarkIslandAsVisitedDFS(grid, i, j+1); // Top Element
        MarkIslandAsVisitedDFS(grid, i, j-1); // Down Element
    }
}
