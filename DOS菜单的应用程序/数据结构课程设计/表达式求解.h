#pragma once
#include <iostream>
#define STACK_INIT_SIZE 10
#define STACKINCREMENT 5
#define BUFFERSIZE 256

//����������ṹջ
typedef struct OPERANDSTACK{
	int *base;
	int *top;
	int stackSize;
}OPERANDSTACK;

//����������ṹջ
typedef struct OPERATORSTACK{
	char *base;
	char *top;
	int stackSize;
}OPERATORSTACK;




//������ջ�������ջ�Ļ�������

//��ʼ��ջ
void initOperandStack(OPERANDSTACK *s)
{
	s->base = (int*)malloc(STACK_INIT_SIZE * sizeof(int));
	if (!(s->base))
		printf("��ʼ��ջʧ��\a\n");
	else{
		s->top = s->base;
		s->stackSize = STACK_INIT_SIZE;
	}
}
void initOperatorStack(OPERATORSTACK *s)
{
	s->base = (char*)malloc(STACK_INIT_SIZE * sizeof(char));
	if (!(s->base))
		printf("��ʼ��ջʧ��\a\n");
	else{
		s->top = s->base;
		s->stackSize = STACK_INIT_SIZE;
	}
}

//ѹջ
void pushOperand(OPERANDSTACK *s, int elem)
{
	//ջ�Ŀռ䲻����ʱ�Զ���չ
	if (s->top - s->base >= s->stackSize)
	{
		s->base = (int*)realloc(s->base, (s->stackSize + STACK_INCREMENT) * sizeof(int));
		if (!(s->base))
			printf("ջ����ʧ�ܣ�\a\n");
		else{
			s->top = s->base + s->stackSize;
			s->stackSize += STACK_INCREMENT;
		}
	}
	*(s->top++) = elem;//ѹջ
}
void pushOperator(OPERATORSTACK *s, char elem)
{
	//ջ�Ŀռ䲻����ʱ�Զ���չ
	if (s->top - s->base >= s->stackSize)
	{
		s->base = (char*)realloc(s->base, (s->stackSize + STACK_INCREMENT) * sizeof(char));
		if (!(s->base))
			printf("ջ����ʧ�ܣ�\a\n");
		else{
			s->top = s->base + s->stackSize;
			s->stackSize += STACK_INCREMENT;
		}
	}
	*(s->top++) = elem;//ѹջ
}

//��ջ
void popOperand(OPERANDSTACK *s, int &elem)
{
	if (s->base == s->top)
		printf("ջΪ�գ���Ԫ�ؿ��Գ�ջ��\a\n");
	elem = *(--s->top);
}
void popOperator(OPERATORSTACK *s, char &elem)
{
	if (s->base == s->top)
		printf("ջΪ�գ���Ԫ�ؿ��Գ�ջ��\a\n");
	elem = *(--s->top);
}

//�õ�ջ��Ԫ��
int getOperandTop(OPERANDSTACK *s)
{
	if (s->top == s->base)
		printf("ջΪ�գ���Ԫ�ؿ��Գ�ջ��\a\n");
	return *(s->top - 1);//���ı�ջ�����ݽṹ
}
char getOperatorTop(OPERATORSTACK *s)
{
	if (s->top == s->base)
		printf("ջΪ�գ���Ԫ�ؿ��Գ�ջ��\a\n");
	return *(s->top - 1);//���ı�ջ�����ݽṹ
}

//�ж�c�Ƿ���һ�����������  
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

//�����*c��ʼ�Ĳ����������غ�cΪ������
const char *getOpnd(const char *c, int *op)
{
	//�����*c��ʼ�Ĳ����������غ�cΪ������  
	int sum = 0, tmp;
	while (false == isOperator(*c)){//��c���ǲ�����  
		tmp = *c - '0';
		sum = sum * 10 + tmp;
		//printf("tmp=%d\n",tmp);  
		c++;
	}
	*op = sum;
	//printf("getOpnd:%d\n",*op);  
	return c;
}

//�ж�op1��op2���ȼ��ĸߵ�
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

////�Բ�����a��b����theta���� 
int operate(int a, char theta, int b)
{
	//�Բ�����a��b����theta���㣬������������  
	//thetaֻ���������������  
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
			printf("errror:����Ϊ0.");
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

//���ַ������ʽ��׼��Ϊ�������ʽ
void standard(char *expression){
	char *p = expression, *q;
	while (*p != '\0'){//�����ַ���  
		if (*p == ' '){//����ǿո�ɾ��  
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

//������ز���
int EvalueateExpression(const char *expression){
	//��ֻ��������������������ʽ expression ��ֵ  
	//OPTR:������ջ��OPND:������ջ  
	const char *c = expression;
	OPERANDSTACK OPND;
	OPERATORSTACK OPTR;
	char x, theta;
	int a, b, num, result;
	initOperatorStack(&OPTR);//��ʼ��������ջ  
	initOperandStack(&OPND);//��ʼ��������ջ  
	pushOperator(&OPTR, '#');//���Ƚ�ƥ�����'#'��ջ  
	while (*c != '#' || getOperatorTop(&OPTR) != '#'){
		//printf("getchar=%c\n",*c);  
		if (*c == '\0')//�����س��˳�  
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
		printf("�ڴ�ռ����");
		exit(0);
	}
	printf("������һ�����ʽ\n");
	gets_s(expression, BUFFERSIZE);
	standard(expression);
	result = EvalueateExpression(expression);
	printf("������ʽ�Ľ��Ϊ��%d", result);
}