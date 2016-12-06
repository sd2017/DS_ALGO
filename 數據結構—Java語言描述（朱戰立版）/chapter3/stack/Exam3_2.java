public class Exam3_2
{

    public static void expIsCorrect(String[] exp, int n) throws Exception{
        SeqStack myStack = new SeqStack();

        for (int i = 0; i < n; i ++)
        {
            if ((exp[i].equals(new String("("))) || (exp[i].equals(new String("["))) ||
            (exp[i].equals(new String("{")))) {
                myStack.push(exp[i]);
            } else if ((exp[i].equals(new String(")"))) && myStack.notEmpty() &&
            myStack.getTop().equals(new String("("))) {
                myStack.pop();
            } else if ((exp[i].equals(new String(")"))) && myStack.notEmpty() &&
                       !myStack.getTop().equals(new String("("))) {
                System.out.println("左、右括号匹配次序不正确！");
                return;
            } else if ((exp[i].equals(new String("]"))) && myStack.notEmpty() &&
                       myStack.getTop().equals(new String("["))) {
                myStack.pop();
            } else if ((exp[i].equals(new String("]"))) && myStack.notEmpty() &&
                       !myStack.getTop().equals(new String("["))) {
                System.out.println("左、右括号匹配次序不正确！");
                return;
            } else if ((exp[i].equals(new String("}"))) && myStack.notEmpty() &&
                       myStack.getTop().equals(new String("{"))) {
                myStack.pop();
            } else if ((exp[i].equals(new String("}"))) && myStack.notEmpty() &&
                       !myStack.getTop().equals(new String("{"))) {
                System.out.println("左、右括号匹配次序不正确！");
                return;
            } else if ((exp[i].equals(new String(")"))) ||
                       (exp[i].equals(new String("]"))) || (exp[i].equals(new String("}"))) &&
                       !myStack.notEmpty()) {
                System.out.println("右括号多于左括号！");
                return;
            }
        }

        if (myStack.notEmpty())
        {
            System.out.println("左括号多于右括号！");
        } else
        { System.out.println("左、右括号匹配次序正确！"); }
    }

    private static String[] strToString(String str)
    {
        int n = str.length();
        String[] a;
        a = new String[n];

        for (int i = 0; i < n; i ++) {
            a[i] = str.substring(i, i + 1);
        }

        return a;
    }

    public static void main(String[] args)
    {

        String str;
        int n;

        try {
            str = "(())abc{[)(]}";
            n = str.length();
            String[] a;
            a = strToString(str);
            expIsCorrect(a, n);

            str = "(()))abc{[]}";
            n = str.length();
            String[] b;
            b = strToString(str);
            expIsCorrect(b, n);

            str = "(()()abc{[]}";
            n = str.length();
            String[] c;
            c = strToString(str);
            expIsCorrect(c, n);

            str = "(())abc{[]}";
            n = str.length();
            String[] d;
            d = strToString(str);
            expIsCorrect(d, n);
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }
}
