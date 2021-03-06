package filetree;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.tree.*;
import java.io.*;
import javax.swing.event.*;
import java.util.*;

public class TreeFrame extends JFrame
{
    private JPanel contentPane;
    private BorderLayout borderLayout1 = new BorderLayout();
    private JScrollPane jScrollPane1 = new JScrollPane();
    private JButton jButton2 = new JButton();
    private JTree jTree1 ;

    //Construct the frame
    public TreeFrame()
    {
        enableEvents(AWTEvent.WINDOW_EVENT_MASK);

        try {
            jbInit();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    //Component initialization
    private void jbInit() throws Exception  {
        //setIconImage(Toolkit.getDefaultToolkit().createImage(TreeFrame.class.getResource("[Your Icon]")));
        contentPane = (JPanel) this.getContentPane();
        jButton2.setText("jButton2");
        contentPane.setLayout(borderLayout1);
        this.setSize(new Dimension(525, 469));
        this.setTitle("Frame Title");
        initTree("C:\\");
        contentPane.add(jScrollPane1, BorderLayout.CENTER);
        jScrollPane1.getViewport().add(jTree1, null);
        this.setVisible(true) ;
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
    //Overridden so we can exit when window is closed
    protected void processWindowEvent(WindowEvent e)
    {
        super.processWindowEvent(e);

        if (e.getID() == WindowEvent.WINDOW_CLOSING) {
            System.exit(0);
        }
    }
    void initTree(String dir)
    {
        FileTreeNode root = (FileTreeNode)buildTree(dir);
        DefaultTreeModel treemodel = new DefaultTreeModel(root);
        jTree1 = new JTree(treemodel);
        MyTreeExpansionListener listener = new MyTreeExpansionListener(jTree1, root,
                treemodel, this);
        jTree1.addTreeExpansionListener(listener);
    }
    public TreeNode buildTree(String dir)
    {
        FileTreeNode root = new FileTreeNode(new File(dir));
        root.readTree(false);
        return (TreeNode)root;
    }
    class FileTreeNode extends DefaultMutableTreeNode
    {
        boolean isAdded;
        public  FileTreeNode(File file)
        {
            super(file);
            isAdded = false;
        }
        public boolean readTree()
        {
            return readTree(false);
        }
        public boolean readTree(boolean b)
        {
            if (isAdded) {
                return false;
            }

            String list[] = getFileObject().list();

            if (list != null) {
                for (int i = 0; i < list.length; i++) {
                    FileTreeNode subnode = new FileTreeNode(new File(getFileObject(), list[i]));
                    add(subnode);

                    if (b) {
                        subnode.readTree(b);

                    }
                }
            }

            isAdded = true;
            return true;
        }
        public File getFileObject()
        {
            return (File)getUserObject();
        }
        public String toString()
        {
            File file = getFileObject();
            return file.getName().length() > 0 ? file.getName() : file.getPath();
        }
        public boolean isLeaf()
        {
            return ((File)userObject).isFile();
        }

    }
    class MyTreeExpansionListener implements TreeExpansionListener
    {
        FileTreeNode root;
        JTree jtree;
        DefaultTreeModel treemodel;
        JFrame frame;
        public MyTreeExpansionListener(JTree tree, FileTreeNode node,
                                       DefaultTreeModel tmodel, JFrame theFrame)
        {
            root = node;
            jtree = tree;
            treemodel = tmodel;
            frame = theFrame;
        }
        //Called whenever an item in the tree has been expanded
        public void treeExpanded(TreeExpansionEvent event)
        {
            TreePath path = event.getPath();
            FileTreeNode node = (FileTreeNode)path.getLastPathComponent();
            frame.setCursor(Cursor.getPredefinedCursor(Cursor.WAIT_CURSOR));
            frame.setEnabled(false);

            if (node.readTree(false)) {
                int childrenIdx[] = new int[node.getChildCount()];
                int i = 0;

                for (Enumeration e = node.children(); e.hasMoreElements();) {
                    Object obj = e.nextElement();
                    childrenIdx[i] = node.getIndex((TreeNode)obj) ;
                    i++;
                }

                treemodel.nodesWereInserted(node, childrenIdx);

            }

            frame.setEnabled(true);
            frame.setCursor(Cursor.getDefaultCursor());
        }
        //Called whenever ab item in the tree has been collapsed
        public void treeCollapsed(TreeExpansionEvent event)
        {
        }
    }
}

