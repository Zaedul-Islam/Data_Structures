// Evaluate Prefix Expression.cpp

#include<iostream>
#include<string>
#include<stack>
#include<vector>
using namespace std;




bool IsOperator(string str)
{
    return (str == "+" || str == "-" || str == "*" || str == "/") ? true : false;
}



int StringToInt(string str)
{
    int I, pos = 0, n, len = str.length();

    bool minus = false;

    if(str[0] == '-')
    {
        pos = 1;
        minus = true;
    }

    n = 0;
    for(I = pos; I < len; I++)
    {
        n *= 10;
        n += (str[I] - '0');
    }

    if(minus)
        n *= (-1);

    return n;

}



void EvalPrefix(vector<string> tokens)
{
    stack<int> S;

    int res = 0;
    for(int I = tokens.size() - 1; I >= 0; I--)
    {
        string str = tokens[I];

        if(IsOperator(str))
        {
            if(S.empty())
            {
                cout << "The given prefix expression is not valid.\n";
                return;
            }

            int operand1 = S.top();
            S.pop();

            if(S.empty())
            {
                cout << "The given prefix expression is not valid.\n";
                return;
            }

            int operand2 = S.top();
            S.pop();

            if(str == "+")
                res = (operand1 + operand2);
            else if(str == "-")
                res = (operand1 - operand2);
            else if(str == "*")
                res = (operand1 * operand2);
            else
                res = (operand1 / operand2);

            S.push(res);
        }
        else
        {
            int n = StringToInt(str);
            S.push(n);
        }
    }


    if(S.size() > 1)
    {
        cout << "The given prefix expression is not valid.\n";
        return;
    }

    if(!S.empty())
    {
        res = S.top();
        S.pop();
    }

    cout << "Output: " << res << '\n';

}



int main()
{
    string str;
    vector<string> tokens;

    while(cin >> str)
        tokens.push_back(str);

    EvalPrefix(tokens);

    return 0;
}

/*
Input:
- + * 2 3 * 5 4 9

Output:
17
*/