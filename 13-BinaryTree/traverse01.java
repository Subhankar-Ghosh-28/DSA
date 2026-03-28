class Node {
    public int data;
    Node left;
    Node right;

    public Node(int key) {
        data = key;
    }
}

class Recursive {
    public void PreOrder(Node root) {
        if (root == null)
            return;

        System.out.print(root.data + " ");
        PreOrder(root.left);
        PreOrder(root.right);
    }

    void Inorder(Node root) {
        if (root == null)
            return;

        Inorder(root.left);
        System.out.print(root.data + " ");
        Inorder(root.right);
    }

    void PostOrder(Node root) {
        if (root == null)
            return;

        PostOrder(root.left);
        PostOrder(root.right);
        System.out.print(root.data + " ");
    }
}

public class traverse01 {

    public static void main(String[] args) {
        Node root = new Node(1);

        root.left = new Node(2);
        root.right = new Node(3);

        root.left.left = new Node(4);
        root.left.right = new Node(5);

        root.right.left = new Node(8);

        Recursive sol = new Recursive();

        System.out.print("Pre-order traversal : ");
        sol.PreOrder(root);
        System.out.println();

        System.out.print("In-order traversal : ");
        sol.Inorder(root);
        System.out.println();

        System.out.print("Post-order traversal : ");
        sol.PostOrder(root);
        System.out.println();

    }
}