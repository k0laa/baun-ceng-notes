package AVLT;

public class Node {
    int data;
    int height;
    Node left;
    Node right;

    public Node(int data) {
        this.data = data;
        this.height = 1;
        this.left = null;
        this.right = null;
    }
}
