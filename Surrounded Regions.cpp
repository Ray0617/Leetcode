class Solution {
public:
    bool flip(vector<vector<char>> &board, int i, int j, char ch)
    {
        bool touchBound = false;
		vector<pair<int,int> > points;
		points.push_back(make_pair(i, j));
		while (!points.empty())
		{
			auto p = points.back();
			points.pop_back();
			int i = p.first;
			int j = p.second;
			touchBound = touchBound || (i==0 || i==board.size()-1 || j==0 || j==board[0].size()-1);
			board[i][j] = ch;
			if (i > 0 && board[i-1][j] == 'O')
			{
				points.push_back(make_pair(i-1, j));
			}
			if (i < board.size()-1 && board[i+1][j] == 'O')
			{
				points.push_back(make_pair(i+1, j));
			}
			if (j > 0 && board[i][j-1] == 'O')
			{
				points.push_back(make_pair(i, j-1));
			}
			if (j < board[0].size()-1 && board[i][j+1] == 'O')
			{
				points.push_back(make_pair(i, j+1));
			}
		}
        return touchBound;
    }
    
    void solve(vector<vector<char>> &board) {
        if (board.empty() || board[0].empty())
            return;
        
        auto check = board;
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (check[i][j] == 'O')
                {
                    bool touchBound = flip(check, i, j, 'V');
                    if (!touchBound)
                        flip(board, i, j, 'X');
                }
            }
        }
    }
};