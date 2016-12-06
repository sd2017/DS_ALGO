

public class Exam2_6
{

    public static void main(String[] args)
    {
        LinList myList = new LinList();
        int s[] = {1, 3, 6, 8, 9, 10, 11, 15, 16, 22}, n = 10;

        try {
            for (int i = 0; i < n; i++) {
                myList.orderInsert(new Integer(s[i]));
            }

            for (int i = 0; i < myList.size; i++) {
                System.out.print(myList.getData(i) + "  ");
            }
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }
}
