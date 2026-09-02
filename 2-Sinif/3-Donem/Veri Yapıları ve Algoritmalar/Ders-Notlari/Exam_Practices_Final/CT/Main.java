package CT;


import javax.swing.*;
import java.util.ArrayList;

public class Main {

    public static void main(String[] args) {
        CustomTree tree = new CustomTree();

        tree.insert(23);
        tree.insert(10);
        tree.insert(71);
        tree.insert(4);
        tree.insert(15);
        tree.insert(49);
        tree.insert(80);

        visualize(tree);
    }

    public static void visualize(CustomTree tree) {
        JFrame frame = new JFrame("Tree Visualization");
        TreeVisualizer panel = new TreeVisualizer(tree);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.getContentPane().add(panel);
        frame.pack();
        frame.setVisible(true);
    }
}