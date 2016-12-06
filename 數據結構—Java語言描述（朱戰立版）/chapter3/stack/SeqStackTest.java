public class SeqStackTest
{
    public static void main(String[] args)
    {

        SeqStack myStack = new SeqStack();

        int test[] = {1, 3, 5, 7, 9};
        int n = 5;

        try {
            for (int i = 0; i < n; i ++) {
                myStack.push(new Integer(test[i]));
            }

            System.out.println("当前栈顶元素为：" + myStack.getTop());

            System.out.print("出栈元素序列为：");

            while (myStack.notEmpty()) {
                System.out.print(myStack.pop() + "  ");
            }
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }
}
