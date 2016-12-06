public class StringCompare
{
    public static int compare(String s, String t)
    {
        int n = s.length();
        int m = t.length();
        int i = 0, j = 0, tag;

        while (i < n && j < m) {
            if (s.charAt(i) == t.charAt(j)) {
                i++;
                j++;
            } else if (s.charAt(i) > t.charAt(j)) {
                tag = 1;
                return tag;
            } else {
                tag = -1;
                return tag;
            }
        }

        if (n == m) {
            tag = 0;
        } else if (n > m) {
            tag = 1;
        } else {
            tag = -1;
        }

        return tag;
    }

    public static void main(String[] args)
    {
        int result = compare(args[0], args[1]);

        if (result > 0) {
            System.out.println(args[0] + "  is larger than " + args[1]);
        } else if (result < 0) {
            System.out.println(args[0] + "  is less than " + args[1]);
        } else {
            System.out.println(args[0] + "  is eqaul  " + args[1]);
        }
    }
}
