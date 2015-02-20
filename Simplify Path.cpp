class Solution {
public:
    string simplifyPath(string path) {
        //remove . in the middle
        path.push_back('/');
        while (true)
        {
            size_t index = path.find("/./");
            if (index == string::npos)
                break;
            path.replace(index, 3, "/");
        }
        //remove . in the start
        if (path.find("./") == 0)
        {
            path.replace(0, 2, "");
        }
        
        //remove //
        while (true)
        {
            size_t index = path.find("//");
            if (index == string::npos)
                break;
            path.replace(index, 2, "/");
        }

        //remove .. in the middle
        while (true)
        {
            size_t index = path.find("/../");
            if (index == string::npos)
                break;
            if (index == 0)
            {
                path.replace(index, 4, "/");
                continue;
            }
            size_t start = path.find_last_of("/", index - 1);
			if (start == string::npos)
				path.replace(0, index + 4, "/");
			else
				path.replace(start, index - start + 4, "/");
        }
        //remove ../ in the front
        if (path.find("../") == 0)
            path.replace(0, 3, "/");

        //remove //
        while (true)
        {
            size_t index = path.find("//");
            if (index == string::npos)
                break;
            path.replace(index, 2, "/");
        }
        
        //remove last /
        while (!path.empty())
        {
            if (path.back() == '/')
                path.pop_back();
            else 
                break;
        }
        if (path.empty())
            return "/";
        return path;
    }
};