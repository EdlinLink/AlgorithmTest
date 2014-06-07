/**************************************************************************                                                            
 *  Title   : Reverse Polish of Expression
 *  Author  : Edlin
 *  Date    : May 31, 2014
 **************************************************************************/

#ifndef REVERSEPOLISTH_H
#define REVERSEPOLISTH_H
#include <iostream>
#include <cstring>
#include <string>
#include <stack>
using namespace std;

#define CHARACTER 0
#define BRACKET_LEFT 102
#define BRACKET_RIGHT 101

class ReversePolish{
private:
	int Level(const char op);
public:
	string RP(const string infix);
};

int ReversePolish::Level(const char op){
	if(op=='+')
		return 1;
	else if(op=='*')
		return 2;
	else if(op=='(')
		return BRACKET_LEFT;
	else if(op==')')
		return BRACKET_RIGHT;
	else
		return CHARACTER;					// normal charater has level 0.
}

string ReversePolish::RP(const string infix){
	string postfix = "";

	int StackLevel = 0;
	stack<char> Stack;
	
	int len = infix.length();

	for(int i=0; i<len; i++){
		char ch = infix[i];
		int level = Level(infix[i]);

		if(level == CHARACTER)
			postfix += ch;
		else{
			if(level==BRACKET_LEFT){
				Stack.push('(');
				StackLevel = level;
			}
			else if(level==BRACKET_RIGHT){
				while(StackLevel!=BRACKET_LEFT){
					postfix += Stack.top();
					Stack.pop();
					StackLevel = Stack.empty()? 0 : Level(Stack.top());
				}	
				Stack.pop();
			}
			else{
				while(level<=StackLevel && StackLevel!=BRACKET_LEFT){
					postfix += Stack.top();
					Stack.pop();
					StackLevel = Stack.empty()? 0 : Level(Stack.top());
				}
				Stack.push(ch);
				StackLevel = level;
			}
		}
	}

	while(!Stack.empty()){
		postfix += Stack.top();
		Stack.pop();
	}

	return postfix;
}


#endif
