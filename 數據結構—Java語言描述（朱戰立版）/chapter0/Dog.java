public class Dog extends Animal         //类Dog继承自父类Animal
{
    String nickName;                    //定义子类自己的成员变量

    Dog(String n, int a, String nn)     //构造函数1
    {
        super(n, a);                    //调用父类的构造函数
        nickName = nn;
    }

    Dog(String n)                       //构造函数2
    {
        super(n);
        nickName = "Tom";
    }

    public void setNickName(String nn)    //子类的成员函数
    {
        nickName = nn;
    }

    public String getNickName()                 //子类的成员函数
    {
        return nickName;
    }

    public void run()                       //覆盖父类的成员函数
    {
        System.out.println(nickName + " run by four feet");
    }
}
