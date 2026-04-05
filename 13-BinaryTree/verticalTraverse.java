import java.util.*;

class Pair {
    Node node;
    int vertical;
    int level;

    Pair(Node n, int v, int l) {
        node = n;
        vertical = v;
        level = l;
    }
}

class Node {
    int data;
    Node left, right;

    Node(int key) {
        data = key;
    }
}

class Solution {
    public List<List<Integer>> verticalTraverse(Node root) {
        List<List<Integer>> ans = new ArrayList<>();

        if (root == null)
            return ans;

        // push vertical position level position with every level node
        // multi set for store same value node
        TreeMap<Integer, TreeMap<Integer, PriorityQueue<Integer>>> nodes = new TreeMap<>();

        // push to q node and its x and y position
        Queue<Pair> todo = new LinkedList<>();

        todo.offer(new Pair(root, 0, 0));

        while (!todo.isEmpty()) {
            Pair p = todo.poll();
            Node node = p.node;
            int x = p.vertical;
            int y = p.level;

            nodes.putIfAbsent(x, new TreeMap<>());
            nodes.get(x).putIfAbsent(y, new PriorityQueue<>());
            nodes.get(x).get(y).offer(node.data);

            if (node.left != null) {
                todo.offer(new Pair(node.left, x - 1, y + 1));
            }

            if (node.right != null) {
                todo.offer(new Pair(node.right, x + 1, y + 1));
            }
        }

        for (TreeMap<Integer, PriorityQueue<Integer>> ys : nodes.values()) {
            List<Integer> col = new ArrayList<>();
            for (PriorityQueue<Integer> pq : ys.values()) {
                while (!pq.isEmpty()) {
                    col.add(pq.poll());
                }
            }
            ans.add(col);
        }
        return ans;
        // TC. O(N log²N log²N log²N)
        // SC. O(N + N/2)
    }
};

public class verticalTraverse {

    public static void printResult(List<List<Integer>> result) {
        for (List<Integer> col : result) {
            System.out.println(col);
        }
    }

    public static void main(String[] args) {
        Node root = new Node(1);
        root.left = new Node(2);
        root.left.left = new Node(4);
        root.left.right = new Node(10);
        root.left.left.right = new Node(5);
        root.left.left.right.right = new Node(6);
        root.right = new Node(3);
        root.right.right = new Node(10);
        root.right.left = new Node(9);

        // Create solution object
        Solution solution = new Solution();

        // Call function
        List<List<Integer>> verticaltraversal = solution.verticalTraverse(root);

        // Print result
        System.out.println("Vertical Traversal:");
        printResult(verticaltraversal);
    }

}