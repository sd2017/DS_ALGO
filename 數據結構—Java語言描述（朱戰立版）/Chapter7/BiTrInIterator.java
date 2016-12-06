public class BiTrInIterator extends BiTreeInterator
{
    private LinStack s = new LinStack();

    BiTrInIterator(BiTreeNode t)
    {
        super(t);
    }

    private BiTreeNode goFarLeft(BiTreeNode t)
    {
        if (t == null) {
            return null;
        }

        while (t.getLeft() != null) {
            s.push(t);
            t = t.getLeft();
        }

        return t;
    }

    public void reset()
    {
        if (root == null) {
            iteComplete = 1;
        } else {
            iteComplete = 0;
        }

        if (root == null) {
            return;
        }

        current = goFarLeft(root);
    }

    public void next()
    {
        if (iteComplete == 1) {
            System.out.println("已到二叉树尾！");
            return;
        }

        if (current.getRight() != null) {
            current = goFarLeft(current.getRight());
        } else if (! s.isEmpty()) {
            try {
                current = (BiTreeNode)s.pop();
            } catch (Exception e) {
                e.printStackTrace();
            }
        } else {
            iteComplete = 1;
        }
    }
}
