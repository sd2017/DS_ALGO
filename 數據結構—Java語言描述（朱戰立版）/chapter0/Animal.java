public class Animal
{
    protected String name;                  //成员变量
    protected int age;                      //成员变量

    public Animal(String n, int a)          //构造函数1
    {
        name = n;
        age = a;
    }

    public Animal(String n)                 //构造函数2
    {
        name = n;
        age = 1;
    }

    public void setName(String n)       //无返回值有形参的成员函数
    {
        name = n;
    }

    public String getName()             //有返回值无形参的成员函数
    {
        return name;
    }

    public void setAge(int a)
    {
        age = a;
    }

    public int getAge()
    {
        return age;
    }

    public void run()
    {
        System.out.println(name + " can run");
    }

}
