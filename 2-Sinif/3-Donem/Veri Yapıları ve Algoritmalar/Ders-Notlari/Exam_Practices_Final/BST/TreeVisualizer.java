package BST;

import javax.swing.*;
import java.awt.*;

public class TreeVisualizer extends JPanel {
    private BinarySearchTree tree;

    public TreeVisualizer(BinarySearchTree tree) {
        this.tree = tree;
        this.setPreferredSize(new Dimension(800, 600));
    }

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        if (tree != null) {
            drawTree(g, tree.root, 400, 50, 100);
        }
    }

    private void drawTree(Graphics g, Node node, int x, int y, int xOffset) {
        if (node == null) return;

        g.setColor(Color.BLACK);
        g.fillOval(x - 15, y - 15, 30, 30);
        g.setColor(Color.WHITE);
        g.drawString(String.valueOf(node.data), x - 5, y + 5);

        if (node.left != null) {
            g.drawLine(x, y, x - xOffset, y + 50);
            drawTree(g, node.left, x - xOffset, y + 50, xOffset / 2);
        }
        if (node.right != null) {
            g.drawLine(x, y, x + xOffset, y + 50);
            drawTree(g, node.right, x + xOffset, y + 50, xOffset / 2);
        }
    }

    public static void main(String[] args) {
        BinarySearchTree tree = new BinarySearchTree();
        tree.insert(10);
        tree.insert(5);
        tree.insert(15);
        tree.insert(3);
        tree.insert(7);
        tree.insert(13);
        tree.insert(18);

        JFrame frame = new JFrame("Binary Search Tree Visualization");
        TreeVisualizer panel = new TreeVisualizer(tree);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.getContentPane().add(panel);
        frame.pack();
        frame.setVisible(true);
    }
}
