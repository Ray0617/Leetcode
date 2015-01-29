class Solution {
public:
    int toInt(long long i, bool minus) {
        if (!minus && i >= INT_MAX)
            return INT_MAX;
        if (minus && -i <= INT_MIN)
            return INT_MIN;
        return minus?-i:i;
    }
    int atoi(const char *str) {
        if (str == 0)
            return 0;
        long long ret = 0;
        const char* ptr = str;
        int state = 0;
        bool minus = false;
        while (*ptr != '\0') {
            switch (state) {
                case 0:
                    if (*ptr == ' ' || *ptr == '\t')
                        break;
                    if (*ptr == '-') {
                        minus = true;
                        state = 1;
                        break;
                    }
                    if (*ptr == '+') {
                        state = 1;
                        break;
                    }
                    if (*ptr < '0' || *ptr > '9')
                        return ret;
                    state = 1;
                case 1:
                    if (*ptr >= '0' && *ptr <= '9') {
                        ret *= 10;
                        ret += *ptr - '0';
                        if (!minus && ret >= INT_MAX)
                            return INT_MAX;
                        if (minus && -ret <= INT_MIN)
                            return INT_MIN;
                    }
                    else {
                        return toInt(ret, minus);
                    }
                    break;
            }
            ptr++;
        }
        return toInt(ret, minus);
    }
};