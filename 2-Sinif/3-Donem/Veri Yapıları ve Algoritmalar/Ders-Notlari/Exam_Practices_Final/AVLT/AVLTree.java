package AVLT;

public class AVLTree {
    Node root;

    private int getHeight(Node node) {
        return (node == null) ? 0 : node.height;
    }

    private int getBalance(Node node) {
        return (node == null) ? 0 : getHeight(node.left) - getHeight(node.right);
    }

    private Node rightRotate(Node z) {
        Node y = z.left;
        Node T3 = y.right;
        y.right = z;
        z.left = T3;
        z.height = Math.max(getHeight(z.left), getHeight(z.right)) + 1;
        y.height = Math.max(getHeight(y.left), getHeight(y.right)) + 1;
        return y;
    }

    private Node leftRotate(Node z) {
        Node y = z.right;
        Node T2 = y.left;
        y.left = z;
        z.right = T2;
        z.height = Math.max(getHeight(z.left), getHeight(z.right)) + 1;
        y.height = Math.max(getHeight(y.left), getHeight(y.right)) + 1;
        return y;
    }

    public void insert(int data) {
        root = insert(root, data);
    }

    private Node insert(Node root, int data) {
        if (root == null) {
            return new Node(data);
        }
        if (root.data > data) {
            root.left = insert(root.left, data);
        } else if (root.data < data) {
            root.right = insert(root.right, data);
        } else {
            return root;
        }
        root.height = Math.max(getHeight(root.left), getHeight(root.right)) + 1;
        int balance = getBalance(root);
        if (balance > 1 && data < root.left.data) {
            return rightRotate(root);
        }
        if (balance < -1 && data > root.right.data) {
            return leftRotate(root);
        }
        if (balance > 1 && data > root.left.data) {
            root.left = leftRotate(root.left);
            return rightRotate(root);
        }
        if (balance < -1 && data < root.right.data) {
            root.right = rightRotate(root.right);
            return leftRotate(root);
        }
        return root;
    }
}
