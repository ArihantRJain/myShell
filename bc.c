#include <string.h>
#include <ctype.h>

#define SIZE 50

int top=-1;
char s[SIZE],sufix[SIZE];

int prior(char ch) //This function returns the priority of the operator.
{
	if(ch=='('||ch=='#') 
		return 1;
	if(ch=='+'||ch=='-') 
		return 2;
	if(ch=='*'||ch=='/') 
		return 3;
	if(ch=='$'||ch=='^') 
		return 4;
}

char pop() //Pops an element from the stack pointed to by top.
{
	char element;

	if(top==-1)
	{
		printf("\nInvalid\n");
	}
	element=s[top];
	top--;
	return element;
}

void push(char element) //Pushes an element onto the stack.
{
	if(top==(SIZE-1))
	{
		printf("\nInvalid\n");
		return;
	}
	top++;
	s[top]=element;
}

void postfixEvaluation() //Evaluates the postfix expression.
{
	int i=0,result,op1,op2;
	while(sufix[i]!='\0') //Loop over the expression until the NULL Character(\0) is found.
	{
		if(isdigit(sufix[i])) //Check if the current symbol is a digit.
			push(sufix[i]-'0'); //Push the digit(after conversion from character to integer) onto the stack.
		else //If the current symbol is an operator.
		{
			op1=pop(); //Pop two elements from the stack.
			op2=pop();
			if(op2 != 35)
			{
				switch(sufix[i]) //Check which operation is to be performed.
				{
				case '*' : result=op2*op1; //If the current symbol is *, then multiply op1 and op2.
					   push(result);
					   break;
				case '+' : result=op2+op1; //If the current symbol is +, then add op1 and op2.
					   push(result);
					   break;
				case '/' : result=op2/op1; //If the current symbol is /, then divide op2 by op1.
					   push(result);
					   break;
				case '-' : result=op2-op1; //If the current symbol is -, then subtract op1 from op2.
					   push(result);
					   break;
				case '%' : result=op2%op1; //If the current symbol is %, then find the remainder of op2/op1.
					   push(result);
					   break;
				default : printf("Invalid Operator\n");
				}
			}
			else 
			{
				printf("Invalid Expression\n");
				return ;
			}
		}
		i++;
	}
		printf("%d\n",result);
}

int mybc()
{
	char infix[SIZE];
	int i,j=0;
	push('#');
	gets(infix); //Scan the infix expression
	
	while(strcmp(infix,"quit")) //Scan for infix expressions and convert them to postfix expressions until the user wants to quit.
	{
		//Convert the infix expression to postfix.
		for(i=0;infix[i]!='\0';i++)
		{
			if(isalnum(infix[i])) //If the current symbol is a digit or an alphabet, then add it to the postfix expression.
				sufix[j++]=infix[i];
			else if(infix[i]=='(') //If the current symbol is a (, then push it onto the stack.
				push(infix[i]);
			else if(infix[i]==')') //If the current symbol os a ), then pop all the elements from the stack and add them to the postfix until ( is found.
			{
				while(s[top]!='(')
					sufix[j++]=pop();
				pop();
			}
			else //If the current symbol is an operator, then pop all the elements from the stack which have a priority greater than the the current symbol.
			{
				while(prior(s[top])>=prior(infix[i])) 
					sufix[j++]=pop();
				push(infix[i]);
			}
		}
		while(s[top]!='#') //Pop all the elements from the stack.
			sufix[j++]=pop();
		sufix[j]='\0';

		postfixEvaluation(); //Evaluate the postfix expression.
		j=0;
		top=-1;
		push('#');
		gets(infix);
	}
	
	return 0;
}

