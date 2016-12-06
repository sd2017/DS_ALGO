public class TestDog
{
    public static void main(String[] args)
    {
        Dog d1 = new Dog("Mimi", 2, "Baby");
        System.out.print("name is " + d1.getName()
                         + "   age is " + d1.getAge());
        System.out.println("  nickName is " + d1.getNickName());
        d1.run();

        Animal a1 = new Animal("Mimi", 2);
        System.out.println("name is " + a1.getName()
                           + "    age is " + a1.getAge());
        a1.run();
    }
}

