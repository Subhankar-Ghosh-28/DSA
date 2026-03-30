import java.util.*;
import java.util.AbstractMap.SimpleEntry;

class Node {
    int data;
    Node left;
    Node right;

    Node(int val) {
        data = val;
        left = null;
        right = null;
    }
}

class Solution {
    public List<List<Integer>> preInPostTraversal(Node root) {
        List<Integer> pre = new ArrayList<>();
        List<Integer> in = new ArrayList<>();
        List<Integer> post = new ArrayList<>();

        if (root == null) {
            return new ArrayList<>();
        }

        Stack<SimpleEntry<Node, Integer>> st = new Stack<>();

        st.push(new SimpleEntry<>(root, 1));

        while (!st.empty()) {
            SimpleEntry<Node, Integer> it = st.pop();

            if (it.getValue() == 1) {
                pre.add(it.getKey().data);

                it.setValue(2);

                st.push(it);

                if (it.getKey().left != null) {
                    st.push(new SimpleEntry<>(it.getKey().left, 1));
                }
            }

            else if (it.getValue() == 2) {
                in.add(it.getKey().data);
                it.setValue(3);

                st.push(it);

                if (it.getKey().right != null) {
                    st.push(new SimpleEntry<>(it.getKey().right, 1));
                }
            }

            else {
                post.add(it.getKey().data);
            }
        }

        List<List<Integer>> result = new ArrayList<>();
        result.add(pre);
        result.add(in);
        result.add(post);
        return result;
    }

    public void printList(List<Integer> list) {
        for (int num : list) {
            System.out.print(num + " ");
        }
        System.out.println();
    }
}

public class oneTraversal {
    public static void main(String[] args) {
        Node root = new Node(1);
        root.left = new Node(2);
        root.right = new Node(3);
        root.left.left = new Node(4);
        root.left.right = new Node(5);

        Solution sol = new Solution();

        List<List<Integer>> traversals = sol.preInPostTraversal(root);

        List<Integer> pre = traversals.get(0);
        List<Integer> in = traversals.get(1);
        List<Integer> post = traversals.get(2);

        System.out.print("Preorder traversal: ");
        sol.printList(pre);

        System.out.print("Inorder traversal: ");
        sol.printList(in);

        System.out.print("Postorder traversal: ");
        sol.printList(post);
    }
}
