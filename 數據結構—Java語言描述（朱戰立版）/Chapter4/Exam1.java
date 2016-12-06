public class Exam1
{
    public static void reverseName(String name, String newName)
    {
        newName = name.replace(' ', ',');
        System.out.println("Name: " + name + "  " + "ReverseName: " + newName);
    }

    public static void main(String[] args)
    {
        String name = "William Topp";
        String newName = new String();

        reverseName(name, newName);
        System.out.println("Name: " + name + "  " + "ReverseName: " + newName);
    }
}
