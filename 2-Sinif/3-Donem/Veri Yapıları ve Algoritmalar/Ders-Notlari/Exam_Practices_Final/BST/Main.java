package BST;


import javax.swing.*;
import java.util.ArrayList;

public class Main {

    public static void main(String[] args) {

        BinarySearchTree tree = new BinarySearchTree();

        tree.insert(23);
        tree.insert(10);
        tree.insert(71);
        tree.insert(4);
        tree.insert(15);
        tree.insert(49);
        tree.insert(80);
        tree.insert(1);
        tree.insert(7);
        tree.insert(12);
        tree.insert(18);
        tree.insert(31);
        tree.insert(54);
        tree.insert(73);
        tree.insert(90);



        visualize(tree);

        tree.inorder();
        System.out.println("**********");
        tree.preorder();
        System.out.println("**********");
        tree.postorder();


    }

    public static void visualize(BinarySearchTree tree) {
        JFrame frame = new JFrame("Tree Visualization");
        TreeVisualizer panel = new TreeVisualizer(tree);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.getContentPane().add(panel);
        frame.pack();
        frame.setVisible(true);
    }
}