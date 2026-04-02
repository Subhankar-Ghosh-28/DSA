class Node {
    int data;
    Node left, right;

    Node(int key) {
        data = key;
    }
}

class Solution {
    private int dfs(Node root) {
        if (root == null)
            return 0;

        int left = Math.max(0, dfs(root.left));
        int right = Math.max(0, dfs(root.right));

        maxSum = Math.max(
                maxSum,
                left + right + root.data);

        return Math.max(left, right) + root.data;
    }

    public int maxSum = Integer.MIN_VALUE;

    int maxPathSum(Node root) {
        dfs(root);
        return maxSum;
    }   //TC -> O(N)  SC-> O(H)
}

public class maxPathSum {
    public static void main(String[] args) {
        Node root = new Node(-10);
        root.left = new Node(9);
        root.right = new Node(20);
        root.right.left = new Node(15);
        root.right.right = new Node(7);

        Solution obj = new Solution();
        System.out.print("Maximum Path Sum: " + obj.maxPathSum(root));
    }
}
