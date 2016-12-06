public class Exec218
{
    public void converse(Node head)
    {
        Node p, q;
        p = head.next;
        head.next = null;

        while (p != null) {
            q = p;
            p = p.next;
            q.next = head.next;
            head.next = q;
        }
    }

    public static void main(String[] args)
    {
        Exec218 ex = new Exec218();
        Node head = new Node();
        Node p = head;

        for (int i = 0; i < 10; i++) {
            int m = (int)(Math.random() * 100);
            Node node = new Node();
            node.data = m % 10;
            System.out.print(m % 10 + " ");
            p.next = node;
            p = p.next;
        }

        ex.converse(head);

        p = head.next;
        System.out.println();
        System.out.println("after converse");

        while (p != null) {
            System.out.print(p.data + " ");
            p = p.next;
        }
    }
}

class Node
{
    public int data;
    public Node next;
}
