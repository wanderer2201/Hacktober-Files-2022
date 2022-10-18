class Tree
{
    
    public static void inorder(Node root,List<Integer> list){
        if(root==null) return;
        inorder(root.left,list);
        list.add(root.data);
        inorder(root.right,list);
    }
    public static float findMedian(Node root)
    {
        // code here.
        ArrayList<Integer> list=new ArrayList<>();
        inorder(root,list);
        int n=list.size();
        if(n%2==0){
           return (float)(list.get((n-1)/2)+list.get((n-1)/2+1))/2;
        }
        else{
            return (float)(list.get((n-1)/2));
        }
    }
}
