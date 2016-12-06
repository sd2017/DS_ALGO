import java.io.*;
import java.util.*;

public class Maze
{
    int mazeSize;
    InterSection[] intSec;
    int exit;

    Maze(String fileName)
    {
        String line;
        Integer temp;

        try {
            BufferedReader in = new BufferedReader(new FileReader(fileName));
            line = in.readLine();
            mazeSize = Integer.parseInt(line.trim());

            intSec = new InterSection[mazeSize + 1];

            for (int i = 1; i <= mazeSize; i ++) {
                line = in.readLine();
                StringTokenizer tokenizer = new StringTokenizer(line);
                InterSection curr = new InterSection();
                curr.left = Integer.parseInt(tokenizer.nextToken());
                curr.forward = Integer.parseInt(tokenizer.nextToken());
                curr.right = Integer.parseInt(tokenizer.nextToken());
                intSec[i] = curr;
            }

            exit = Integer.parseInt(in.readLine());
            in.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public boolean travMaze(int intSecValue)
    {
        if (intSecValue > 0) {
            if (intSecValue == exit) {
                System.out.print(intSecValue + "<==");
                return true;
            } else if (travMaze(intSec[intSecValue].left)) {
                System.out.print(intSecValue + "<==");
                return true;
            } else if (travMaze(intSec[intSecValue].forward)) {
                System.out.print(intSecValue + "<==");
                return true;
            } else if (travMaze(intSec[intSecValue].right)) {
                System.out.print(intSecValue + "<==");
                return true;
            }
        }

        return false;
    }
}
class InterSection
{
    int left;
    int forward;
    int right;
}
