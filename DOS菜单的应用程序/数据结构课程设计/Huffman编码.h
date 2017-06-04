#pragma once
#include <iostream>
#include <string.h>  
#define title "------------------------------Life is a fight!------------------------------------"  
#define queueSize_Max 256 //���е���󳤶�  
#define code_Max 256 //�������󳤶�  

/**************************************/
/*����Huffman Tree�ڵ�                */
/*����symbol��¼�ڵ�洢���ַ�        */
/*left, rightָ�������ӽڵ�           */
/**************************************/
typedef struct hfmTreeNode{
	int symbol;
	struct hfmTreeNode *left;
	struct hfmTreeNode *right;
} hfmTreeNode, *phTreeNode;

/**************************************/
/*����һ��ָ��Huffman Tree�ĸ��ڵ�    */
/**************************************/
typedef struct hHfmTreeNode{
	hfmTreeNode* rootNode;
} hHfmTreeNode;

/**************************************/
/*������еĽڵ�                      */
/*ptr��һ��ָ��phTreeNode��ָ�룬     */
/*��Ҫ�Ƿ����������Huffman Treee     */
/*Count��¼�ַ����ֵ�Ƶ�Σ�           */
/*nextָ����һ���ڵ�                  */
/**************************************/
typedef struct queueNode{
	phTreeNode ptr;
	int count;
	struct queueNode *next;
} queueNode, *ptrQueue;

/**************************************/
/*����ָ��queueNode��ͷ�ڵ�           */
/*����size��¼�ڵ������              */
/*firstָ��queueNode�ĵ�һ���ڵ�      */
/**************************************/
typedef struct hQueueNode{
	int size;
	ptrQueue first;
} hQueueNode;

/**************************************/
/*����ָ���¼�����table�ڵ�         */
/*symbleΪ�ַ���codeָ���Ӧ�ı���    */
/*next����ָ����һ���ڵ�              */
/**************************************/
typedef struct tableNode{
	char symbol;
	char* code;
	struct tableNode *next;
} tableNode;

/**************************************/
/*����ָ��tableNode��ͷ�ڵ�           */
/*first��ǵ�һ���ڵ�                 */
/*lastָ�����һ���ڵ�                */
/**************************************/
typedef struct hdTableNode{
	tableNode *first;
	tableNode *last;
} hdTableNode;

/**************************************/
/*�Զ��н��г�ʼ�����һ��ͷ�ڵ�      */
/*����size��¼�ڵ������              */
/*firstָ��queue�ڵ�                  */
/**************************************/
void initQueue(hQueueNode** hQueue)
{
	*hQueue = (hQueueNode*)malloc(sizeof(hQueueNode));
	(*hQueue)->size = 0;
	(*hQueue)->first = NULL;
}

void addQueueNode(hQueueNode **hQueue, hfmTreeNode *hNode, int count)//�½�һ�����нڵ㲢��ͳ�ƵĽ����С�����˳��������  
{
	queueNode *qNode = NULL;

	if ((*hQueue)->size == queueSize_Max)//���й�ģ��飬��������²������  
	{
		printf("\nERR: The queue is full!!!");
	}
	else    //������������մ�С�����˳��Ѱ����ȷ��λ�ò���ڵ�  
	{
		if (0 == (*hQueue)->size)//�������ӵĵ�һ���ڵ㣬ֱ����Ӽ���  
		{
			qNode = (queueNode*)malloc(sizeof(queueNode));
			(*hQueue)->first = qNode;
			qNode->count = count;
			qNode->ptr = hNode;
			qNode->next = NULL;
			(*hQueue)->size++;
		}
		else if (count<(*hQueue)->first->count)//���Ҫ��ӵ��ַ���ͳ������С��������С�ģ���ֱ�ӷ��ڵ�һ���ڵ㴦  
		{
			qNode = (queueNode*)malloc(sizeof(queueNode));
			qNode->next = (*hQueue)->first;
			(*hQueue)->first = qNode;
			qNode->count = count;
			qNode->ptr = hNode;
			(*hQueue)->size++;
		}
		else    //���ڵ��������������Ҫ�������У�ֱ��Ѱ�ҵ����ʵ�λ��  
		{
			queueNode* p = (*hQueue)->first;
			qNode = (queueNode*)malloc(sizeof(queueNode));
			qNode->count = count;
			qNode->ptr = hNode;
			(*hQueue)->size++;

			while (p->next != NULL && count >= p->next->count)
				p = p->next;
			qNode->next = p->next;
			p->next = qNode;
		}
	}
}

hfmTreeNode* getHfmTreeNode(hQueueNode* hQueue)
{
	hfmTreeNode* getNode;
	if (hQueue->size>0)
	{
		getNode = hQueue->first->ptr;
		hQueue->first = hQueue->first->next;
		hQueue->size--;
	}
	else
	{
		printf("\nERR: Can't get a node\n");
	}
	return getNode;
}


hHfmTreeNode* crtHfmTree(hQueueNode** hQueue)
{
	int count = 0;
	hfmTreeNode *left, *right;

	while ((*hQueue)->size>1)
	{
		count = (*hQueue)->first->count + (*hQueue)->first->next->count;
		left = getHfmTreeNode(*hQueue);
		right = getHfmTreeNode(*hQueue);

		hfmTreeNode *newNode = (hfmTreeNode*)malloc(sizeof(hfmTreeNode));

		newNode->left = left;
		newNode->right = right;

		addQueueNode(hQueue, newNode, count);
	}

	hHfmTreeNode* tree = (hHfmTreeNode*)malloc(sizeof(hHfmTreeNode));
	tree->rootNode = getHfmTreeNode(*hQueue);
	return tree;
}

hHfmTreeNode* creatTree(void)
{
	FILEFILE *ifile;
	intint *countArray;
	char c;
	int i;

	countArray = (int*)malloc(sizeof(int)* 256);//����ռ����ڴ洢���ַ����ֵĴ���,����ʼ��Ϊ��  
	for (i = 0; i<256; i++)
	{
		countArray[i] = 0;
	}

	ifile = fopen("D://1.txt", "r");
	if (!ifile)  //����ļ��Ƿ�򿪳ɹ�  
		printf("Can't open the file\n");
	else
	{
		while ((c = getc(ifile)) != EOF)
		{
			countArray[(unsigned int)c]++;
			printf("%c", c);
		}
		fclose(ifile);
	}
	hQueueNode *hQueue;
	initQueue(&hQueue);
	for (i = 0; i<256; i++)
	{
		if (countArray[i])
		{
			//printf("%c %d\n",i, countArray[i] );  
			hfmTreeNode *hNode = (hfmTreeNode*)malloc(sizeof(hfmTreeNode));//����һ�����ڵ㣬����ʼ����������Ӧ����queueNode�е�ptr��  

			hNode->symbol = (char)i;
			hNode->left = NULL;
			hNode->right = NULL;

			addQueueNode(&hQueue, hNode, countArray[i]);//���ýڵ��������е��ʵ�λ�ã���ͳ�ƵĽ������С�������У�  
		}
	}
	free(countArray);//�ͷŲ��õ��ڴ�  

	queueNode* q = hQueue->first;
	printf("\n");
	do
	{
		printf("\n%c %d", q->ptr->symbol, q->count);
		q = q->next;
	} while (q != NULL);
	//printf("%d",hQueue->size);  

	hHfmTreeNode *tree = crtHfmTree(&hQueue);
	return tree;
}

void traverseTree(hdTableNode** table, hfmTreeNode* tree, char* code, int k)
{
	if (tree->left == NULL && tree->right == NULL)   //�ݹ������飬���ҵ�Ҷ�ӽڵ�  
	{
		code[k] = '\0';   //����ַ����������  
		tableNode *tNode = (tableNode*)malloc(sizeof(tableNode)); //����һ���ڵ㣬��������ӵ�table������  
		tNode->code = (char*)malloc(sizeof(char)* 256 + 1);
		strcpy(tNode->code, code);
		tNode->symbol = tree->symbol;
		tNode->next = NULL;

		if ((*table)->first == NULL)   //����ǵ�һ���ڵ㣬ֱ����Ӽ��ɣ� ������ӵ�β������  
		{
			(*table)->first = tNode;
			(*table)->last = tNode;
		}
		else
		{
			(*table)->last->next = tNode;
			(*table)->last = tNode;
		}
	}

	if (tree->left != NULL)    //����ߵݹ飬����¼����Ϊ0  
	{
		code[k] = '0';
		traverseTree(table, tree->left, code, k + 1);
	}

	if (tree->right != NULL)   //���ұߵݹ飬����¼����Ϊ1  
	{
		code[k] = '1';
		traverseTree(table, tree->right, code, k + 1);
	}
}

hdTableNode* crtTable(hHfmTreeNode* hfmTree)
{
	hdTableNode* hdTable = (hdTableNode*)malloc(sizeof(hdTableNode));
	hdTable->first = NULL;
	hdTable->last = NULL;

	char code[code_Max];
	int k = 0; //��¼���Ĳ㼶  

	traverseTree(&hdTable, hfmTree->rootNode, code, k);
	return hdTable;
}



int main(void)
{
	hHfmTreeNode* tree;
	hdTableNode* table;

	printf("%s\n\n\n", title);
	tree = creatTree();
	table = crtTable(tree);
	int i = 0, j = 0;
	tableNode* t = table->first;
	char* s = t->code;
	printf("\n\n*************************************************************************************\n");
	printf("The Huffman code is:\n");
	while (t != NULL)
	{

		for (i = 0; i<257; i++)
		{
			if ((*s) != '\0')
			{
				printf("%c", *s);
				s++;
			}
		}
		printf("%8c\n", t->symbol);
		t = t->next;
		if (t)
			s = t->code;

	}
}