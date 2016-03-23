import java.util.*;

class Main{
	
	public static void main(String[] args)
	{
		Scanner scan = new Scanner(System.in);
		int tc = scan.nextInt();

		for(int i = 0; i < tc; ++i)
		{
			String s1 = scan.next();
			String s2 = scan.next();
			solve(s1, s2);
		}

	}

	private static void solve(String s1, String s2)
	{
		System.out.print("Distances: ");

		for(int i = 0; i < s1.length(); ++i)
		{
			System.out.print((s2.charAt(i) - s1.charAt(i) + 26) % 26 + " ");
		}
		System.out.println("");
	}
}
