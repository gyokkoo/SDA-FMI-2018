/*
https://www.hackerrank.com/challenges/balanced-brackets/problem
*/

#include <bits/stdc++.h>

using namespace std;

string isBalanced(string s) 
{
    std::stack<char> brackets;
    for (int i = 0; i < s.length(); i++) 
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            brackets.push(s[i]);
            continue;
        }
        
        if (brackets.empty()) 
        {
            return "NO";
        }
        
        char lastBracket = brackets.top();
        brackets.pop();
        
        if (s[i] == ')')
        {
            if (lastBracket == '{' || lastBracket == '[')
            {
                return "NO";
            }
        }
        else if (s[i] == '}')
        {
            if (lastBracket == '(' || lastBracket == '[')
            {
                return "NO";
            }
        }
        else if (s[i] == ']')
        {
            if (lastBracket == '(' || lastBracket == '{')
            {
                return "NO";
            }
        }
        
    }
    
    return ((brackets.empty()) ? "YES" : "NO");
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) 
    {
        string s;
        getline(cin, s);

        string result = isBalanced(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
