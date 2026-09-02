package AVLT;


import javax.swing.*;
import java.awt.*;

public class TreeVisualizer extends JPanel {
    private AVLTree tree;

    public TreeVisualizer(AVLTree tree) {
        this.tree = tree;
        this.setPreferredSize(new Dimension(800, 600));
    }

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        g.setColor(Color.GRAY);
        g.fillRect(0,0,800,600);
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
}
