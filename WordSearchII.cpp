#include "leetcode.h"

struct Trie {
    Trie* next[26];
    string word;
    Trie() {
        for (int i = 0; i < 26; i++)
            next[i] = 0;
    }
    Trie* add(char ch) {
        if (!next[ch - 'a'])
            next[ch - 'a'] = new Trie();
        return next[ch - 'a'];
    }
    Trie* get(char ch) {
        return next[ch - 'a'];
    }
};
enum DIRECTION {
    INIT,
    RIGHT,
    DOWN,
    LEFT,
    UP,
    INVALID
};
DIRECTION next_dir(DIRECTION dir) {
    switch (dir) {
        case INIT: return RIGHT;
        case RIGHT: return DOWN;
        case DOWN: return LEFT;
        case LEFT: return UP;
        default: return INVALID;
    }
}
struct Step {
    int row;
    int col;
    char val;
    DIRECTION dir;
    Trie* trie;
    Step(int r, int c, char v, Trie* t, DIRECTION d) : row(r), col(c), val(v), trie(t), dir(d) {}
};
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        unordered_set<string> result;
        for (auto word : words) {
            Trie* node = &root;
            for (auto ch : word) {
                node = node->add(ch);
            }
            node->word = word;
        }
        if (board.empty()) return vector<string>();
        int M = (int)board.size();
        int N = (int)board[0].size();
        for (size_t r = 0; r < M; r++) {
            for (size_t c = 0; c < N; c++) {
                Trie* node = root.get(board[r][c]);
                if (!node)
                    continue;
                vector<Step> path;
                path.push_back(Step(r, c, board[r][c], node, INIT));
                board[r][c] = '.';
                if (!node->word.empty())
                    result.insert(node->word);
                while (!path.empty()) {
                    auto step = path.back();
                    bool found = false;
                    auto dir = next_dir(step.dir);
                    while (dir != INVALID) {
                        int row = step.row;
                        int col = step.col;
                        switch (dir) {
                            case LEFT: col--; break;
                            case RIGHT: col++; break;
                            case UP: row--; break;
                            case DOWN: row++; break;
                            default: break;
                        }
                        if (row >= 0 && row < M && col >= 0 && col < N) {
                             Trie* node = step.trie->get(board[row][col]);
                             if (node) {
                                 path.back().dir = dir;
                                 path.push_back(Step(row, col, board[row][col], node, INIT));
                                 board[row][col] = '.';
                                 if (!node->word.empty())
                                    result.insert(node->word);
                                 found = true;
                                 break;
                             }
                        }
                        dir = next_dir(dir);
                    }
                    if (!found) {
                        board[step.row][step.col] = step.val;
                        path.pop_back();
                    }
                }
            }
        }
        return vector<string>(result.begin(), result.end());
    }
private:
    Trie root;
};

int main() {
    auto inputs = load("WordSearchII.txt");
    auto board = str2chmatrix(inputs[0]);
    auto words = str2strvec(inputs[1]);
    Solution sol;
    auto result = sol.findWords(board, words);
    for (auto str : result)
        cout << str << endl;
    return 0;
}