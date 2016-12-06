public class Node
{
    Object element;                     //数据元素
    Node next;                          //表示下一个结点的对象

    Node(Node nextval)                  //用于头结点的构造函数1
    {
        next = nextval;
    }

    Node(Object obj, Node nextval)      //用于其他结点的构造函数2
    {
        element = obj;
        next = nextval;
    }

    public Node getNext()
    {
        return next;
    }

    public void setNext(Node nextval)
    {
        next = nextval;
    }

    public Object getElement()
    {
        return element;
    }

    public void setElement(Object obj)
    {
        element = obj;
    }

    public String toString()
    {
        return element.toString();
    }
}
