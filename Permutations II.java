public class Solution {
	public void conquer(Stack<Integer> head, LinkedList<Integer> others, ArrayList<List<Integer>> perms)
	{
		if (others.isEmpty())
		{
			perms.add((Stack<Integer>)head.clone());
			return;
		}
		Set<Integer> used = new TreeSet<Integer>();
		Object[] snapshot = others.toArray();
		for (Object obj : snapshot)
		{
		    Integer i = (Integer)obj;
			if (used.contains(i))
				continue;
			used.add(i);
			head.push(i);
			others.remove(i);
			conquer(head, others, perms);
			others.add(i);
			head.pop();
		}
	}
	public List<List<Integer>> permuteUnique(int[] num) {
		ArrayList<List<Integer>> perms = new ArrayList<List<Integer>>();
		Stack<Integer> head = new Stack<Integer>();
		LinkedList<Integer> others = new LinkedList<Integer>();
		for (int i : num)
		{
			others.add(new Integer(i));
		}
		conquer(head, others, perms);
		return perms;
    }
}
