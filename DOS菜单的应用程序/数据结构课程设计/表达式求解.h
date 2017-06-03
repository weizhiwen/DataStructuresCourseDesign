#pragma once
#include <iostream>
#define STACK_INIT_SIZE 10
#define STACKINCREMENT 5
#define BUFFERSIZE 256

//定义操作数结构栈
typedef struct OPERANDSTACK{
	int *base;
	int *top;
	int stackSize;
}OPERANDSTACK;

//定义操作符结构栈
typedef struct OPERATORSTACK{
	char *base;
	char *top;
	int stackSize;
}OPERATORSTACK;




//操作数栈和运算符栈的基本操作

//初始化栈
void initOperandStack(OPERANDSTACK *s)
{
	s->base = (int*)malloc(STACK_INIT_SIZE * sizeof(int));
	if (!(s->base))
		printf("初始化栈失败\a\n");
	else{
		s->top = s->base;
		s->stackSize = STACK_INIT_SIZE;
	}
}
void initOperatorStack(OPERATORSTACK *s)
{
	s->base = (char*)malloc(STACK_INIT_SIZE * sizeof(char));
	if (!(s->base))
		printf("初始化栈失败\a\n");
	else{
		s->top = s->base;
		s->stackSize = STACK_INIT_SIZE;
	}
}

//压栈
void pushOperand(OPERANDSTACK *s, int elem)
{
	//栈的空间不够用时自动扩展
	if (s->top - s->base >= s->stackSize)
	{
		s->base = (int*)realloc(s->base, (s->stackSize + STACK_INCREMENT) * sizeof(int));
		if (!(s->base))
			printf("栈扩充失败！\a\n");
		else{
			s->top = s->base + s->stackSize;
			s->stackSize += STACK_INCREMENT;
		}
	}
	*(s->top++) = elem;//压栈
}
void pushOperator(OPERATORSTACK *s, char elem)
{
	//栈的空间不够用时自动扩展
	if (s->top - s->base >= s->stackSize)
	{
		s->base = (char*)realloc(s->base, (s->stackSize + STACK_INCREMENT) * sizeof(char));
		if (!(s->base))
			printf("栈扩充失败！\a\n");
		else{
			s->top = s->base + s->stackSize;
			s->stackSize += STACK_INCREMENT;
		}
	}
	*(s->top++) = elem;//压栈
}

//出栈
void popOperand(OPERANDSTACK *s, int &elem)
{
	if (s->base == s->top)
		printf("栈为空，无元素可以出栈！\a\n");
	elem = *(--s->top);
}
void popOperator(OPERATORSTACK *s, char &elem)
{
	if (s->base == s->top)
		printf("栈为空，无元素可以出栈！\a\n");
	elem = *(--s->top);
}

//得到栈顶元素
int getOperandTop(OPERANDSTACK *s)
{
	if (s->top == s->base)
		printf("栈为空，无元素可以出栈！\a\n");
	return *(s->top - 1);//不改变栈的数据结构
}
char getOperatorTop(OPERATORSTACK *s)
{
	if (s->top == s->base)
		printf("栈为空，无元素可以出栈！\a\n");
	return *(s->top - 1);//不改变栈的数据结构
}

//判断c是否是一个运算操作符  
bool isOperator(char c)
{
	switch (c){
	case '+':
	case '-':
	case '*':
	case '/':
	case '(':
	case ')':
	case '#':
		return true;
		break;
	default:
		return false;
		break;
	}
}

//获得以*c开始的操作数，返回后c为操作符
const char *getOpnd(const char *c, int *op)
{
	//获得以*c开始的操作数，返回后c为操作符  
	int sum = 0, tmp;
	while (false == isOperator(*c)){//当c不是操作符  
		tmp = *c - '0';
		sum = sum * 10 + tmp;
		//printf("tmp=%d\n",tmp);  
		c++;
	}
	*op = sum;
	//printf("getOpnd:%d\n",*op);  
	return c;
}

//判断op1和op2优先级的高低
char Precede(char op1, char op2)
{
	switch (op1){
	case '+':
		switch (op2){
		case '*':
		case '/':
		case '(':
			return '<';
			break;
		default:
			return '>';
			break;
		}
		break;
	case '-':
		switch (op2){
		case '*':
		case '/':
		case '(':
			return '<';
			break;
		default:
			return '>';
			break;
		}
		break;
	case '*':
		switch (op2){
		case '(':
			return '<';
			break;
		default:
			return '>';
			break;
		}
		break;
	case '/':
		switch (op2){
		case '(':
			return '<';
			break;
		default:
			return '>';
			break;
		}
		break;
	case '(':
		switch (op2){
		case ')':
			return '=';
			break;
		default:
			return '<';
			break;
		}
		break;
	case ')':
		switch (op2){
		default:
			return '>';
			break;
		}
		break;
	case '#':
		switch (op2){
		case '#':
			return '=';
			break;
		default:
			return '<';
			break;
		}
		break;
	default:
		return '<';
		break;
	}
}

////对操作数a，b进行theta运算 
int operate(int a, char theta, int b)
{
	//对操作数a，b进行theta运算，并返回运算结果  
	//theta只能是四则运算符号  
	int rs_i;
	switch (theta){
	case '+':
		rs_i = a + b;
		break;
	case '-':
		rs_i = a - b;
		break;
	case '*':
		rs_i = a*b;
		break;
	case '/':
		if (b == 0){
			printf("errror:除数为0.");
			exit(0);
		}
		rs_i = a / b;
		break;
	default:
		printf("Is not a operator.\n");
		break;
	}
	printf("%d %c %d = %d\n", a, theta, b, rs_i);
	return rs_i;
}

//将字符串表达式标准化为算术表达式
void standard(char *expression){
	char *p = expression, *q;
	while (*p != '\0'){//遍历字符串  
		if (*p == ' '){//如果是空格，删除  
			q = p;
			do{
				*q = *(q + 1);
				q++;
			} while (*q != '\0');
		}
		p++;
	}
	*p++ = '#';
	*p = '\0';
}

//运算相关操作
int EvalueateExpression(const char *expression){
	//对只有四则运算符的算数表达式 expression 求值  
	//OPTR:操作符栈，OPND:操作数栈  
	const char *c = expression;
	OPERANDSTACK OPND;
	OPERATORSTACK OPTR;
	char x, theta;
	int a, b, num, result;
	initOperatorStack(&OPTR);//初始化操作符栈  
	initOperandStack(&OPND);//初始化操作数栈  
	pushOperator(&OPTR, '#');//首先将匹配符号'#'入栈  
	while (*c != '#' || getOperatorTop(&OPTR) != '#'){
		//printf("getchar=%c\n",*c);  
		if (*c == '\0')//遇到回车退出  
			break;
		if (false == isOperator(*c)){
			c = getOpnd(c, &num);
			pushOperand(&OPND, num);
		}
		else
			switch (Precede(getOperatorTop(&OPTR), *c)){
			case '<':
				pushOperator(&OPTR, *c);
				c++;
				break;
			case '=':
				popOperator(&OPTR, x);
				c++;
				break;
			case '>':
				popOperator(&OPTR, theta);
				popOperand(&OPND, b);
				popOperand(&OPND, a);
				result = operate(a, theta, b);
				//printf("temp result is:%d\n",result);  
				pushOperand(&OPND, result);
				break;
			default:
				//printf("Precede:%c",Precede(GetTop_OPTR(OPTR),*c));  
				break;
		}//switch  
	}//while  
	result = getOperandTop(&OPND);
	return result;
}

void solution()
{
	fflush(stdin);
	int result = 0;
	char *expression = (char*)malloc(sizeof(char)*BUFFERSIZE);
	if (expression == NULL)
	{
		printf("内存空间错误");
		exit(0);
	}
	printf("请输入一个表达式\n");
	gets_s(expression, BUFFERSIZE);
	standard(expression);
	result = EvalueateExpression(expression);
	printf("这个表达式的结果为：%d", result);
}