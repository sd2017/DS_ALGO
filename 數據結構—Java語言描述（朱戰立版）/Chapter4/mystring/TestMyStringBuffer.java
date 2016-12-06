public class TestMyStringBuffer
{
    public static void main(String[] args)
    {
        MyStringBuffer msb1 = new MyStringBuffer("lihonglei");
        MyStringBuffer msb2 = new MyStringBuffer("zhangxuhui");

        msb1.myPrint();
        MyStringBuffer msb3 = msb1.concat(msb2);
        msb1.myPrint();
        msb3.myPrint();
    }
}
