public class WWP
{
    private static final int INF = Integer.MAX_VALUE;
 
    void solve(int l[], int n, int M)
    {
        int extras[][] = new int[n + 1][n + 1];
        int lineCost[][] = new int[n + 1][n + 1];
        int cost[] = new int[n + 1];
        int printSol[] = new int[n + 1];
        int i, j;
 
        for (i = 1; i <= n; i++)
        {
            extras[i][i] = M - l[i - 1];
            for (j = i + 1; j <= n; j++)
            {
                extras[i][j] = extras[i][j - 1] - l[j - 1] - 1;
            }
        }
 
        for (i = 1; i <= n; i++)
        {
            for (j = i; j <= n; j++)
            {
                if (extras[i][j] < 0)
                {
                    lineCost[i][j] = INF;
                } 
                else if (j == n && extras[i][j] >= 0)
                {
                    lineCost[i][j] = 0;
                } 
                else
                    lineCost[i][j] = extras[i][j] * extras[i][j];
            }
        }
        cost[0] = 0;
        for (j = 1; j <= n; j++)
        {
            cost[j] = INF;
            for (i = 1; i <= j; i++)
            {
                if (cost[i - 1] != INF && lineCost[i][j] != INF
                    && (cost[i - 1] + lineCost[i][j] < cost[j]))
                {
                    cost[j] = cost[i - 1] + lineCost[i][j];
                    printSol[j] = i;
                }
            }
        }
        printS(printSol, n);
    }
 
    private int printS(int p[], int n)
    {
        int k;
        if (p[n] == 1)
            k = 1; 
        else
            k = printS(p, p[n] - 1) + 1;
        System.out.println("Line number " + k + " From word no " + p[n] + " to " + n);
        return k;
    }
 
    public static void main(String...arg)
    {
        int l[]  = {3,2,2,5};
        int n = 4;
        int M = 6;
        WWP wWP = new WWP();
        wWP.solve(l, n, M);
    }	
}
