import java.util.*;
import java.math.BigInteger;

class Main{
	public static void main(String[] args)
	{
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		System.out.println(solve(n));
	}

	private static BigInteger solve(int n)
	{
		BigInteger ret = new BigInteger("0");

		BigInteger N = BigInteger.valueOf(n);

		BigInteger A = N.multiply(N.multiply(BigInteger.valueOf(3)));

		BigInteger B = N.multiply(BigInteger.valueOf(5));

		ret = ret.add(A);
		ret = ret.add(B);
		ret = ret.add(BigInteger.valueOf(2));
		ret = ret.divide(BigInteger.valueOf(2));

		ret = ret.remainder(BigInteger.valueOf(45678));

		return ret;
	}
}
