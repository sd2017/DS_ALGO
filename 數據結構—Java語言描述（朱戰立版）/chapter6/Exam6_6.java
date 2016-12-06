public class Exam6_6
{
    public static int comm(int n, int k)
    {
        if (n < 1 || k > n) {
            return 0;
        }

        if (k == 0) {
            return 1;
        }

        if (n == k) {
            return 1;
        }

        return comm(n - 1, k - 1) + comm(n - 1, k);
    }

    public static void main(String[] args)
    {
        int n = 5, k = 2, c;

        c = comm(n, k);
        System.out.println("c = " + c);
    }
}
