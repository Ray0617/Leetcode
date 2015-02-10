public class Solution {
public List<String> fullJustify(String[] words, int L) {
        List<String> result = new ArrayList<String>();
        int start = 0;
        int end = 0;
        int totalLength = 0;
        int index = 0;
        while (index < words.length) {
            if (totalLength == 0) {
                totalLength += words[index++].length();
                end++;
                continue;
            }
            if (totalLength + words[index].length() + end - start - 1 < L) {
                totalLength += words[index++].length();
                end++;
                continue;
            }
            String line = words[start];
            if (end - start > 1) {
                int space = (L - totalLength) / (end - start - 1);
                int more = (L - totalLength) % (end - start - 1);
                for (int w = start + 1; w < end; w++) {
                    for (int zeropadding = 0; zeropadding < space; zeropadding++) {
                        line += ' ';
                    }
                    if (w - start - 1 < more) {
                        line += ' ';
                    }
                    line += words[w];
                }
            }
            while (line.length() < L) {
                line += ' ';
            }
            result.add(line);
            totalLength = 0;
            start = end;
        }
        // last line
        String line = words[start];
        for (int w = start + 1; w < end; w++) {
            line += ' ';
            line += words[w];
        }
        while (line.length() < L) {
            line += ' ';
        }
        result.add(line);
        return result;
    }
}