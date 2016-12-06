
public class LinStack
{

    Link top;
    int size;

    public void LinStack()
    {
        initiate();
    }

    public void LinStack(int sz)
    {
        initiate();
    }

    private void initiate()
    {
        top = null;
        size = 0;
    }

    public void push(Object obj)
    {
        top = new Link(obj, top);
        size ++;
    }

    public Object pop() throws Exception{
        if (size == 0)
        {
            throw new Exception("堆栈已空！");
        }

        Object obj = top.element;
        top = top.next;
        size --;
        return obj;
    }

    public boolean isEmpty()
    {
        return top == null;
    }

    public Object getTop()
    {
        return top.next.element;
    }
}
