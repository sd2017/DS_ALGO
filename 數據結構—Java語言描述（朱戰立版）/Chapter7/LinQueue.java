public class LinQueue
{
    Link front;
    Link rear;
    int count;

    public void LinQueue()
    {
        initiate();
    }

    public void LinQueue(int sz)
    {
        initiate();
    }

    public void initiate()
    {
        front = rear = null;
        count = 0;
    }

    public void append(Object obj)
    {
        Link newNode = new Link(obj, null);

        if (rear != null) {
            rear.next = newNode;
        }

        rear = newNode;

        if (front == null) {
            front = newNode;
        }

        count ++;
    }

    public Object delete() throws Exception{
        if (count == 0)
        {
            throw new Exception("队列已空！");
        }

        Link temp = front;
        front = front.next;
        count --;
        return temp.getElement();
    }

    public Object getFront() throws Exception{
        if (count == 0)
        {
            throw new Exception("队列已空！");
        }

        return front.getElement();
    }

    public boolean isEmpty()
    {
        return count == 0;
    }
}
