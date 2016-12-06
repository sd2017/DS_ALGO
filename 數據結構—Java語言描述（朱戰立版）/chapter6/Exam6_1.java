public class Exam6_1
{
    public static long fact(int n) throws Exception{
        int x;
        long y;

        if (n < 0)
        {
            throw new Exception("参数错！");
        }

        if (n == 0)
        {
            return 1;
        } else{
            x = n - 1;
            y = fact(x);
            return n * y;
        }
    }

    public static void main(String[] args)
    {
        long fn;

        try {
            fn = fact(3);
            System.out.println("fn = " + fn);
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }
}
