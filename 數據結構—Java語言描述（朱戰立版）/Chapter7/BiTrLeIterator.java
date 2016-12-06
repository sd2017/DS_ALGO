public class BiTrLeIterator extends BiTreeInterator
{
    LinQueue q = new LinQueue();

    BiTrLeIterator(BiTreeNode t)
    {
        super(t);
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

        current = root;

        try {
            if (root.getLeft() != null) {
                q.append(root.getLeft());
            }

            if (root.getRight() != null) {
                q.append(root.getRight());
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public void next()
    {
        if (iteComplete == 1) {
            System.out.println("已到二叉树尾！");
            return;
        }

        if (!q.isEmpty()) {
            try {
                current = (BiTreeNode)q.delete();

                if (current.getLeft() != null) {
                    q.append(current.getLeft());
                }

                if (current.getRight() != null) {
                    q.append(current.getRight());
                }
            } catch (Exception e) {
                e.printStackTrace();
            }
        } else {
            iteComplete = 1;
        }
    }
}
