public class Exam6_5
{
    public static void display(int n)
    {
        for (int i = 1; i <= n; i ++) {
            System.out.print("     " + n);
        }

        System.out.println();

        if (n > 0) {
            display(n - 1);
        }
    }

    public static void main(String[] args)
    {
        int n = 9;

        display(n);
    }
}
