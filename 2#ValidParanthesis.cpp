/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.

Examples:

Input: s = "()"   Input: s = "()[]{}"     Input: s = "(]"
Output: true	  Output: true            Output: false

Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.

*/

#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool match(char open,char close)
{
	if(open == '(' && close == ')') return true;
	else if(open == '{' && close == '}') return true;
	else if(open == '[' && close == ']') return true;
	return false;
}
bool correct(string exp)
{
	stack<char>  S;
	for(int i =0;i<exp.length();i++)
	{
		if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
			S.push(exp[i]);
		else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
		{
			if(S.empty() || !match(S.top(),exp[i]))
				return false;
			else
				S.pop();
		}
	}
	return S.empty() ? true:false;
}

int main()
{
	string expression;
	cout<<"Enter input : "; 
	cin>>expression;
	if(correct(expression))
		cout<<"true\n";
	else
		cout<<"false\n";
}