public class Position
{
    private int x;
    private int y;
    public Position()
    {
        x = y = 0;
    }

    public static void main(String args[])
    {
        Position pos[] = new Position[10];
        Position p = pos[1];
        Position pp = new Position();
        pos[2] = pp;
    }
}
