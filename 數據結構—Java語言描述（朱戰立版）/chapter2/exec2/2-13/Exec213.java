public class Exec213
{

    int listFind(SeqList s, int x)
    {
        for (int i = 0; i < s.size; i++) {
            if (s.list[i] == x) {
                return i;
            }
        }

        return -1;
    }

    public static void main(String[] args)
    {
        Exec213 e = new Exec213();
        SeqList s = new SeqList();
        int x = 20;

        int result = e.listFind(s, x);
        System.out.println();
        System.out.println(x + " position is " + result);
    }
}

class SeqList
{
    public int[] list = new int[50];
    public int size;
    public SeqList()
    {
        size = 0;

        for (int i = 0; i < list.length - 1; i++) {
            int m = (int)(Math.random() * 100);

            if (m > 100) {
                break;
            }

            list[i] = m;
            size++;
            System.out.print(m + " ");
        }
    }
}
