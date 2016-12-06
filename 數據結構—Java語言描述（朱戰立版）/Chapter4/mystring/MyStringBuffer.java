public class MyStringBuffer
{
    private char[] value;
    private int count;


    public MyStringBuffer(String str)
    {
        char[] chararray = str.toCharArray();
        value = chararray;
        count = chararray.length;

    }

    private void expandCapacity(int minCapacity)
    {
        int newCapacity = value.length * 2;

        if (minCapacity > newCapacity) {
            newCapacity = minCapacity;
        }

        char newValue[] = new char[newCapacity];
        arrayCopy(value, 0, newValue, 0, count);
        value = newValue;    //
    }


    private static void arrayCopy(char[] src, int srcPos, char[] dst, int dstPos,
                                  int length)
    {
        if (src.length - srcPos < length || dst.length - dstPos < length) {
            throw new StringIndexOutOfBoundsException(length);
        }

        for (int i = 0; i < length; i++) {
            dst[dstPos++] = src[srcPos++];
        }
    }

    public static void stringCopy(MyStringBuffer src, int srcPos,
                                  MyStringBuffer dst, int dstPos, int length)
    {
        arrayCopy(src.toArray(), srcPos, dst.toArray(), dstPos, length);
    }

    public MyStringBuffer concat(MyStringBuffer str)
    {
        int otherLen = str.length();

        if (otherLen == 0) {
            return this;
        }

        expandCapacity(count + otherLen);
        stringCopy(str, 0, this, count, str.length());
        count = count + otherLen;
        return this;                //
    }
    public char[] toArray()
    {
        return value;
    }

    public int length()
    {
        return count;
    }

    public void myPrint()
    {
        for (int i = 0; i < count; i++) {
            System.out.print(value[i]);
        }

        System.out.println();
    }
}
