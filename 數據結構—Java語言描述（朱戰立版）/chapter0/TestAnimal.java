public class TestAnimal
{
    public static void main(String[] args)
    {
        Animal a1 = new Animal("Mimi", 2);
        Animal a2 = new Animal("Tom");           //用不同的构造方法创建对象
        System.out.println("name is " + a1.getName()
                           + "    age is " + a1.getAge());
        a1.run();
        System.out.println("name is " + a2.getName() + "    age is "
                           + a2.getAge());
        a2.run();
    }
}


