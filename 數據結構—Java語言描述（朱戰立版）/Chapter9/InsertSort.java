public class InsertSort
{
    public static void insertSort(int[] a)
    {
        int i, j, temp;
        int n = a.length;

        for (i = 0; i < n - 1; i ++) {
            temp = a[i + 1];
            j = i;

            while (j > -1 && temp <= a[j]) {
                a[j + 1] = a[j];
                j --;
            }

            a[j + 1] = temp;
        }
    }

    public static void main(String[] args)
    {
        int[] test = {64, 5, 7, 89, 6, 24};
        int n = test.length;

        insertSort(test);

        for (int i = 0; i < n; i ++) {
            System.out.print(test[i] + "  ");
        }
    }
}
