public class Solution {
    public String simplifyPath(String path) {
        String[] dirs = path.split("/");
        Deque<String> deq = new ArrayDeque<String>();
        for (int i = 0; i < dirs.length; i++) {
            if (dirs[i].equals("")) {
                continue;
            }
            else if (dirs[i].equals(".")) {
                continue;
            }
            else if (dirs[i].equals("..")) {
                if (!deq.isEmpty())
                    deq.removeLast();
            }
            else 
            deq.addLast(dirs[i]);
        }
        
        StringBuilder result = new StringBuilder();
        while (!deq.isEmpty()) {
            result.append("/");
            String dir = deq.removeFirst();
            result.append(dir);
        }
        if (result.toString().equals(""))
            result.append("/");
        return result.toString();
    }
}