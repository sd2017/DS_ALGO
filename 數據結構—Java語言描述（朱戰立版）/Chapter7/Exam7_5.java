public class Exam7_5
{
    static final int maxValue = 10000;
    static final int maxN = 10;

    public static void haffman(int[] weight, int n, HaffNode[] haffTree)
    {
        int m1, m2, x1, x2;

        for (int i = 0; i < 2 * n - 1; i ++) {
            HaffNode temp = new HaffNode();

            if (i < n) {
                temp.weight = weight[i];
            } else {
                temp.weight = 0;
            }

            temp.parent = 0;
            temp.flag = 0;
            temp.leftChild = -1;
            temp.rightChild = -1;
            haffTree[i] = temp;
        }

        for (int i = 0; i < n - 1; i ++) {
            m1 = m2 = maxValue;
            x1 = x2 = 0;

            for (int j = 0; j < n + i; j ++) {
                if (haffTree[j].weight < m1 && haffTree[j].flag == 0) {
                    m2 = m1;
                    x2 = x1;
                    m1 = haffTree[j].weight;
                    x1 = j;
                } else if (haffTree[j].weight < m2 && haffTree[j].flag == 0) {
                    m2 = haffTree[j].weight;
                    x2 = j;
                }
            }

            haffTree[x1].parent  = n + i;
            haffTree[x2].parent  = n + i;
            haffTree[x1].flag    = 1;
            haffTree[x2].flag    = 1;
            haffTree[n + i].weight = haffTree[x1].weight + haffTree[x2].weight;
            haffTree[n + i].leftChild = x1;
            haffTree[n + i].rightChild = x2;
        }
    }
    public static void haffmanCode(HaffNode[] haffTree, int n, Code[] haffCode)
    {
        Code cd = new Code(maxN);
        int child, parent;

        for (int i = 0; i < n; i ++) {
            cd.start = n - 1;
            cd.weight = haffTree[i].weight;
            child = i;
            parent = haffTree[child].parent;

            while (parent != 0) {
                if (haffTree[parent].leftChild == child) {
                    cd.bit[cd.start] = 0;
                } else {
                    cd.bit[cd.start] = 1;
                }

                cd.start --;
                child = parent;
                parent = haffTree[child].parent;
            }

            Code temp = new Code(maxN);

            for (int j = cd.start + 1; j < n; j++) {
                temp.bit[j] = cd.bit[j];
            }

            temp.start  = cd.start;
            temp.weight = cd.weight;
            haffCode[i] = temp;
        }
    }

    public static void main(String[] args)
    {
        int n = 4;
        int[] weight = {1, 3, 5, 7};
        HaffNode[] myHaffTree = new HaffNode[2 * n + 1];
        Code[] myHaffCode = new Code[n];

        //if(n > maxN){
        //  System.out.println("定义的n越界，修改maxN!");
        //  return;
        //}
        haffman(weight, n, myHaffTree);
        haffmanCode(myHaffTree, n, myHaffCode);

        for (int i = 0; i < n; i ++) {
            System.out.print("Weight = " + myHaffCode[i].weight + " Code = ");

            for (int j = myHaffCode[i].start + 1; j < n; j ++) {
                System.out.print(myHaffCode[i].bit[j]);
            }

            System.out.println();
        }
    }
}
