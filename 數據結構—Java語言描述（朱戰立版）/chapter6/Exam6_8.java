public class Exam6_8
{
    public static void main(String[] args)
    {
        String fileName = "Maze1.dat";
        Maze m = new Maze(fileName);
        int start = 1;

        if (m.travMaze(start)) {
            System.out.println();
            System.out.println("此迷宫的一条通路如上所示");
        } else {
            System.out.println("此迷宫无通路出来！");
        }
    }
}
