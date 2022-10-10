/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public boolean isValidBST(TreeNode root) {
      
        return checkBst(root,Long.MIN_VALUE,Long.MAX_VALUE);
    }
    public boolean checkBst(TreeNode root,Long min,Long max){
        if(root==null)
            return true;
        if(root.val>=max || root.val<=min)
            return false;
        return checkBst(root.left,min,(long)root.val) && checkBst(root.right,(long)root.val,max);
    }
}
