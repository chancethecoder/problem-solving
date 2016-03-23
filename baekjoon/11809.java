import java.util.*;

class Main{

    public static void main(String[] args)
    {
        Scanner scan = new Scanner(System.in);
        String A = scan.next();
        String B = scan.next();
        solve(A, B);
    }

    private static void solve(String A, String B)
    {
        int a_idx = A.length() - 1;
        int b_idx = B.length() - 1;
        String AA = A;
        String BB = B;

        while(a_idx >= 0 && b_idx >= 0)
        {
            if(A.charAt(a_idx) < B.charAt(b_idx))
            {
                AA = erase(AA, a_idx);
            }
            else if(A.charAt(a_idx) > B.charAt(b_idx))
            {
                BB = erase(BB, b_idx);
            }

            --a_idx;
            --b_idx;
        }

        print_to_number(AA);
        print_to_number(BB);
    }

    private static String erase(String S, int idx)
    {
        String A = S.substring(0, idx);
        String B = S.substring(idx + 1, S.length());
        return A + B;
    }

    private static void print_to_number(String S)
    {
        int num = 0, idx = S.length() - 1;
        int radix = 1;

        while(idx >= 0)
        {
            num += (S.charAt(idx) - '0') * radix;
            radix *= 10;
            --idx;
        }

        System.out.println(S.length() == 0 ? "YODA" : num);
    }
}
