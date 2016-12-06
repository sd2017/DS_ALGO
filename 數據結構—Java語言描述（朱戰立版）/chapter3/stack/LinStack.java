public class LinStack implements Stack
{

    Node head;
    int size;

    public void LinStack()
    {
        head = null;
        size = 0;
    }

    public void push(Object obj)
    {
        head = new Node(obj, head);
        size ++;
    }

    public Object pop() throws Exception{
        if (size == 0)
        {
            throw new Exception("堆栈已空！");
        }

        Object obj = head.element;
        head = head.next;
        size --;
        return obj;
    }

    public boolean notEmpty()
    {
        return head != null;
    }

    public Object getTop()
    {
        return head.element;
    }
}
