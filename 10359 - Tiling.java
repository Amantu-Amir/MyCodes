import java.math.BigInteger;
import java.util.Scanner;

public class Main
{
    static BigInteger dp[] = new BigInteger[255];
    static BigInteger fun(int n)
    {
        if(n==0) return BigInteger.ONE;
        if(n==1) return BigInteger.ONE;
        if(dp[n].equals(new BigInteger("-1")))
            dp[n] = fun(n-1).add(fun(n-2)).add(fun(n-2));
        return dp[n];
    }
    public static void main (String[] args) throws java.lang.Exception
    {
        for(int i=0; i<=250; i++)
            dp[i] = new BigInteger("-1");
        Scanner sc = new Scanner(System.in);
        while(sc.hasNextInt())
            System.out.println(fun(sc.nextInt()));
    }
}