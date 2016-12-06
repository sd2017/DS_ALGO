public class Exam6_7
{
    public static int gcd(int n, int m)
    {
        if (n < 0 || m < 0) {
            System.exit(0);
        }

        if (m == 0) {
            return n;
        } else if (m > n) {
            return gcd(m, n);
        } else {
            return gcd(m, n % m);
        }
    }

    public static int gcd2(int n, int m)
    {
        int tn, tm, temp;

        if (n < 0 || m < 0) {
            System.exit(0);
        }

        if (m > n) {
            tn = m;
            tm = n;
        } else {
            tn = n;
            tm = m;
        }

        while (tm != 0) {
            temp = tn;
            tn = tm;
            tm = temp % tm;
        }

        return tn;
    }

    public static void main(String[] args)
    {
        int n = 30, m = 4, c;

        c = gcd2(n, m);
        System.out.println("c = " + c);
    }
}
