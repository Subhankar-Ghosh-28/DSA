
import java.util.ArrayList;

class Node {
    public int data;
    Node left;
    Node right;

    Node(int key) {
        data = key;
    }
};

class Solution {
    boolean isLeaf(Node node) {
        if (node.left == null && node.right == null)
            return true;
        return false;
    }

    void addLeftBoundary(Node root, ArrayList<Integer> arr) {
        Node curr = root.left;

        while (curr != null) {
            if (!isLeaf(curr))
                arr.add(curr.data);
            if (curr.left != null)
                curr = curr.left;
            else
                curr = curr.right;
        }
    }

    void addLeaves(Node root, ArrayList<Integer> arr) {
        if (isLeaf(root)) {
            arr.add(root.data);
            return;
        }
        if (root.left != null)
            addLeaves(root.left, arr);
        if (root.right != null)
            addLeaves(root.right, arr);
    }

    void addRightboundaryReverse(Node root, ArrayList<Integer> arr) {
        Node curr = root.right;
        ArrayList<Integer> temp = new ArrayList<>();
        while (curr != null) {
            if (!isLeaf(curr))
                temp.add(curr.data);
            if (curr.left != null)
                curr = curr.right;
            else
                curr = curr.left;
        }

        for (int i = temp.size() - 1; i >= 0; i--) {
            arr.add(temp.get(i));
        }
    }

    public ArrayList<Integer> boudaryTraverse(Node root) {
        ArrayList<Integer> result = new ArrayList<>();
        if (root == null)
            return result;
        if (!isLeaf(root))
            result.add(root.data);
        addLeftBoundary(root, result);
        addLeaves(root, result);
        addRightboundaryReverse(root, result);
        return result;
    }

    void printResult(ArrayList<Integer> result) {
        for (int val : result) {
            System.out.print(val + " ");
        }
        System.out.println();
    } // TC.O(N) SC. O(N)
};

public class boundaryTraverse {

    public static void main(String[] args) {

        Node root = new Node(1);
        root.left = new Node(2);
        root.right = new Node(3);
        root.left.left = new Node(4);
        root.left.right = new Node(5);
        root.right.left = new Node(6);
        root.right.right = new Node(7);

        Solution solution = new Solution();

        ArrayList<Integer> result = solution.boudaryTraverse(root);

        System.out.print("Boundary Traversal: ");
        solution.printResult(result);
    }
}
