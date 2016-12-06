public class TestMyString
{
    public static void main(String[] args)
    {
        char[] var1 = {'d', 'u', 'j', 'i', 'a', 'n', 'h', 'u', 'a'};
        char[] var2 = {'y', 'a', 'n', 'g', 'j', 'i', 'n', 'f', 'e', 'n', 'g'};
        int length1 = var1.length;

        MyString ms1 = new MyString(var1, 0, length1);  //用构造函数2
        MyString ms2 = new MyString(var2);              //用构造函数3
        MyString ms3 = new MyString("lihonglei");       //用构造函数4
        MyString ms4 = new MyString("zhangxuhui");      //用构造函数4

        MyString ms5 = ms1.concat(ms2);
        ms1.myPrint();
        ms5.myPrint();

        MyString ms6 = ms4.substring(0, 4);
        ms6.myPrint();

        MyString ms7 = ms4.insert(new MyString("123"), 4);
        ms7.myPrint();

        MyString ms8 = ms4.delete(3, 6);
        ms8.myPrint();

        int pos;
        System.out.println("11111111111111");
        pos = ms4.indexOf_BF(new MyString("gxu"), 4);
        System.out.println("pos= " + pos);
        pos = ms4.indexOf_KMPA(new MyString("gxu"), 4);
        System.out.println("pos= " + pos);
        pos = ms4.indexOf_KMPB(new MyString("gxu"), 4);
        System.out.println("pos= " + pos);

        //  String s = ("cddcdc"), t = ("abcde");       //测试例子1
        //  String s = ("aaaaaaaa"), t = ("aaaab");     //测试例子2
        MyString ms9 = new MyString("aaaaaaaa");
        pos = ms9.indexOf_BF_Count(new MyString("aaaab"), 0);
        System.out.println("pos= " + pos);
        MyString ms10 = new MyString("aaaaaaaa");
        pos = ms10.indexOf_KMPB_Count(new MyString("aaaab"), 0);
        System.out.println("pos= " + pos);


    }
}
