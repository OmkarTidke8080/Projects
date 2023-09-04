/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner sc = new Scanner(System.in);
		
				int T=sc.nextInt();
		while(T-->0){
		    int N=sc.nextInt();
		    int X=sc.nextInt();
		    int K=sc.nextInt();
		    int P=sc.nextInt();
		    
            int sum=0;
            if(K>X)
            sum=P+(K-X)*5+(X*10);
            else
            sum=P+K*10;
            if(K==N)
            System.out.println(sum+20);
            else
            System.out.println(sum);
		}
	}
}
