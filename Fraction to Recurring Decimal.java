public class Solution {
    public String fractionToDecimal(int _numerator, int _denominator) {
        if (_numerator == 0)
            return "0";
            
        StringBuilder decimal = new StringBuilder();
        boolean plus = (_numerator >= 0 && _denominator >= 0) || (_numerator <= 0 && _denominator <= 0);
        if (!plus)
            decimal.append('-');
        long numerator = Math.abs((long)_numerator);
        long denominator = Math.abs((long)_denominator);
        long quotient = numerator / denominator;
        decimal.append(Long.toString(quotient));
        long reminder = numerator % denominator;
        if (reminder == 0)
            return decimal.toString();
        decimal.append('.');
        Map<Long, Integer> cache = new HashMap<Long, Integer>();
        List<Long> digits = new ArrayList<Long>();
        int index = -1;
        while (reminder > 0) {
            numerator = reminder;
            if (cache.containsKey(numerator)) {
                index = cache.get(numerator);
                break;
            }
            cache.put(numerator, digits.size());
            numerator *= 10;
            quotient = numerator / denominator;
            digits.add(quotient);
            reminder = numerator % denominator;
        } 
        for (int i = 0; i < digits.size(); i++) {
            if (i == index)
                decimal.append('(');
            decimal.append((char)('0' + digits.get(i)));
        }
        if (index != -1)
            decimal.append(')');
        return decimal.toString();
    }
}