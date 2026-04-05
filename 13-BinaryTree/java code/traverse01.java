class TreeNode {
    public int data;
    TreeNode left;
    TreeNode right;

    public TreeNode(int key) {
        data = key;
    }
}

class Recursive {
    public void PreOrder(TreeNode root) {
        if (root == null)
            return;

        System.out.print(root.data + " ");
        PreOrder(root.left);
        PreOrder(root.right);
    }

    void Inorder(TreeNode root) {
        if (root == null)
            return;

        Inorder(root.left);
        System.out.print(root.data + " ");
        Inorder(root.right);
    }

    void PostOrder(TreeNode root) {
        if (root == null)
            return;

        PostOrder(root.left);
        PostOrder(root.right);
        System.out.print(root.data + " ");
    }
}

public class traverse01 {

    public static void main(String[] args) {
        TreeNode root = new TreeNode(1);

        root.left = new TreeNode(2);
        root.right = new TreeNode(3);

        root.left.left = new TreeNode(4);
        root.left.right = new TreeNode(5);

        root.right.left = new TreeNode(8);

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