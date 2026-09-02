package CT;

public class CustomTree {
    /*Node root;

    public CustomTree() {
        root = null;
    }

    public void insert(int data) {
        if (root == null) {
            root = new Node(data);
            return;
        }
        insertRec(root, data);
    }

    private void insertRec(Node current, int data) {
        if (current.left == null) {
            current.left = new Node(data);
            current.left.parent = current;
            bubbleUp(current.left);
        } else if (current.right == null) {
            current.right = new Node(data);
            current.right.parent = current;
            bubbleUp(current.right);
        } else {
            if (subtreeSize(current.left) <= subtreeSize(current.right)) {
                insertRec(current.left, data);
            } else {
                insertRec(current.right, data);
            }
        }
    }

    public void bubbleUp(Node node) {
        if (node.parent != null && node.parent.data < node.data) {
            int temp = node.parent.data;
            node.parent.data = node.data;
            node.data = temp;
            bubbleUp(node.parent);
        }
    }

    public int subtreeSize(Node node) {
        if (node == null)
            return 0;
        return 1 + subtreeSize(node.left) + subtreeSize(node.right);
    }*/

    Node root;

    public CustomTree() {
        root = null;
    }

    public void insert(int data) {
        root = insert(root, data);
    }
    public Node insert(Node root, int data) {
        if (root == null) {
            root = new Node(data);
            return root;
        }
        if (root.left == null) {
            root.left = new Node(data);
            root.left.parent = root;
            bubbleUp(root.left);
        } else if (root.right == null) {
            root.right = new Node(data);
            root.right.parent = root;
            bubbleUp(root.right);
        } else {
            if (treeSize(root.left) <= treeSize(root.right)) {
                insert(root.left, data);
            } else {
                insert(root.right, data);
            }

        }
        return root;
    }

    public void bubbleUp(Node node) {
        if (node.parent != null && node.parent.data < node.data) {
            int temp = node.parent.data;
            node.parent.data = node.data;
            node.data = temp;
            bubbleUp(node.parent);
        }
    }

    public int treeSize(Node node) {
        if (node == null) {
            return 0;
        }
        return treeSize(node.left) + treeSize(node.right) + 1;
    }
}
