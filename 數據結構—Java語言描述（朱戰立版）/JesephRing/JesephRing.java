public class JesephRing
{
    Node head;                                      //头指针
    Node rear;                                      //尾指针
    Node current;                                   //当前指针
    int size;                                       //结点个数

    JesephRing()                                    //构造函数
    {
        head = current = rear = null;
    }

    public void index(int i) throws Exception{      //定位
        //定位当前指针current指向第i个结点
        if (i < -1 || i > size - 1)
        {
            throw new Exception("参数错误！");
        }

        if (i == -1)
        {
            return;
        }

        current = head;
        int j = 0;

        while ((current != null) && j < i)
        {
            current = current.next;
            j ++;
        }
    }

    public void insert(int i, Node obj) throws Exception{   //插入
        //在第i个结点前插入结点obj
        if (i < 0 || i > size)
        {
            throw new Exception("参数错误！");
        }

        index(i - 1);                           // current定位至i - 1

        if (size == 0)
        {
            head = current = rear = obj;        //置第一次插入的指针值
        }

        //新结点加入链表
        obj.next = current.next;
        current.next = obj;

        if (current.equlas(rear))
        {
            obj.next = head;                    //勾成循环链表
            rear = obj;                         //置尾指针
        } else { rear.next = head; }                //勾成循环链表

        size ++;
    }

    public void delete(int m) throws Exception{         //删除
        //以m为随机计数值，逐个删除全部结点
        int i;
        current = head;

        while (size > 0)
        {
            for (i = 1; i < m; i ++) {                  //寻找第m个
                current = current.next;
            }

            System.out.print(current.next.code + "   ");//输出被删结点编号

            current.next = current.next.next;           //被删结点脱链
            size --;
            current = current.next;         //从被删结点的下一个结点开始
        }

        head = current = rear = null;
    }

    public static void main(String[] args) throws Exception{
        int m = 2;
        JesephRing lin = new JesephRing();

        lin.insert(0, new Node(1, null));
        lin.insert(1, new Node(2, null));
        lin.insert(2, new Node(3, null));
        lin.insert(3, new Node(4, null));
        lin.insert(4, new Node(5, null));
        lin.insert(5, new Node(6, null));
        lin.insert(6, new Node(7, null));

        Node curr = lin.head;
        System.out.println("测试是否构成循环链表：");

        for (int i = 0; i < lin.size * 2; i ++)
        {
            System.out.print(curr.code +  "   ");
            curr = curr.next;
        }

        System.out.println();

        System.out.println("依次被删结点编号为：");
        lin.delete(m);
    }
}
