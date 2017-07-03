#include <cstdio>
#include <iostream>
#include <map>
#include <stack>
#include <string>

using namespace std;

void solve()
{
    map <char, int> priority;
    priority['+'] = 0, priority['-'] = 1, priority['*'] = 2, priority['/'] = 3, priority['^'] = 4;
    priority['X'] = -1; //Dummy token

    string expression, postfix_expression;
    cin >> expression;

    stack <char> operators;
    operators.push('X');

    for(int i = 0; expression[i] != '\0'; i++)
    {
        switch(expression[i])
        {
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
                      while(priority[operators.top()] >= expression[i])
                      {
                          postfix_expression += operators.top();
                          operators.pop();
                      }

            case '(':

                      operators.push(expression[i]);
                      break;

            case ')':
                      while(operators.top() != '(')
                      {
                          postfix_expression += operators.top();
                          operators.pop();
                      }
                      operators.pop(); //RPN notation has no brackets of either kind
                      break;

            default :
                      postfix_expression  += expression[i]; //Operands

        }
    }

    while(operators.top() != 'X') //While it isn't empty
    {
        postfix_expression += operators.top();
        operators.pop();
    }

    cout << postfix_expression << "\n";
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}

