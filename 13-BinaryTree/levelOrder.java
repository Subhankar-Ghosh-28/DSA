import java.util.*;

class TreeNode {
    public int data;
    TreeNode left;
    TreeNode right;

    public TreeNode(int key) {
        data = key;
    }
}

class LevelOrderTravarse {
    public List<List<Integer>> LevelOrder(TreeNode root) {
        List<List<Integer>> ans = new ArrayList<>();

        if (root == null)
            return ans;

        Queue<TreeNode> q = new LinkedList<>();

        q.add(root);

        while (!q.isEmpty()) {
            int size = q.size();

            List<Integer> level = new ArrayList<>();

            for (int i = 0; i < size; i++) {
                TreeNode node = q.poll();

                level.add(node.data);

                if (node.left != null) {
                    q.add(node.left);
                }
                if (node.right != null) {
                    q.add(node.right);
                }
            }

            ans.add(level);
        }
        return ans;
    }
}

public class levelOrder {
    public static void main(String[] args) {
        TreeNode root = new TreeNode(1);

        root.left = new TreeNode(2);
        root.right = new TreeNode(3);

        root.left.left = new TreeNode(4);
        root.left.right = new TreeNode(5);

        root.right.left = new TreeNode(8);

        LevelOrderTravarse sol = new LevelOrderTravarse();

        List<List<Integer>> result = sol.LevelOrder(root);

        System.out.println("Level Order Traversal of Tree: ");

        for (List<Integer> x : result) {
            for (Integer y : x) {
                System.out.print(y + " ");
            }
            System.out.println();
        }

    }
}
