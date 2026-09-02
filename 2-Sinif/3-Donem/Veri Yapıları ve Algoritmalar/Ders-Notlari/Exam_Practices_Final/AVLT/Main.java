package AVLT;


import javax.swing.*;

public class Main {
    public static void main(String[] args) {

        AVLTree tree = new AVLTree();

        tree.insert(23);
        tree.insert(33);
        tree.insert(71);
        tree.insert(100);
        tree.insert(256);
        /*tree.insert(25);
        tree.insert(88);
        tree.insert(333);
        tree.insert(444);
        tree.insert(555);
        tree.insert(666);
        tree.insert(257);
        tree.insert(777);
        tree.insert(888);
        tree.insert(999);
        tree.insert(1000);
        tree.insert(1001);
        tree.insert(1002);
        tree.insert(1003);
        tree.insert(1004);
        tree.insert(1005);*/

        visualize(tree);


    }

    public static void visualize(AVLTree tree) {
        JFrame frame = new JFrame("Tree Visualization");
        TreeVisualizer panel = new TreeVisualizer(tree);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.getContentPane().add(panel);
        frame.pack();
        frame.setVisible(true);
    }
}
