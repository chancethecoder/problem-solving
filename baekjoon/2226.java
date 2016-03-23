import java.util.*;
import java.math.BigInteger;

class Main{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		BigInteger[] a = new BigInteger[1001];

		BigInteger mult = new BigInteger("2");
		a[1] = BigInteger.valueOf(0);
		for(int i = 2; i < 1001; i++)
		{
			a[i] = a[i-1].multiply(BigInteger.valueOf(2));
			if(i % 2 == 1) a[i] = a[i].subtract(BigInteger.valueOf(1));
			else a[i] = a[i].add(BigInteger.valueOf(1));
		}

		System.out.println(a[sc.nextInt()]);
	}
}
