import java.io.*;

public class Reverse
{

    public static void main(String args[])
    {

        int n = 10;
        int[] a = new int[n];
        int[] b = new int[n];

        for (int i = 0; i < n; i++) {
            a[i] = i + 1;
        }

        Reverse2(a);

        for (int i = 0; i < n; i++) {
            System.out.print(a[i] + "  ");
        }
    }

    static void Reverse1(int[] a, int[] b)
    {
        int n = a.length;

        for (int i = 0; i < n; i++) {
            b[i] = a[n - 1 - i];
        }
    }

    static void Reverse2(int[] a)
    {
        int n = a.length;
        int m = n / 2;
        int temp;

        for (int i = 0; i < m; i++) {
            temp = a[i];
            a[i] = a[n - 1 - i];
            a[n - 1 - i] = temp;
        }
    }
}
