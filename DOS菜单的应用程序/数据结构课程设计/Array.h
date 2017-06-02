#pragma once
#include <iostream>
#define MAXSIZE 100

//��Ԫ�鴢��ṹ
typedef struct TRIPLE
{
	int x, y;//Ԫ�صĺ�������
	int value;//Ԫ�ص�ֵ
}TRIPLE;

//ϡ�����ṹ
typedef struct TSMATRIX
{
	TRIPLE data[MAXSIZE + 1];//ϡ������з���Ԫ��
	int rows, cols, nonZeroNumber;//ϡ����������������������Ԫ�ظ���
}TSMATRIX;

//����ϡ�����
void createTSMATRIX(TSMATRIX &matrix)
{
	printf("����ϡ����������=");
	scanf_s("%d", &matrix.rows);
	printf("����ϡ����������=");
	scanf_s("%d", &matrix.cols);
	printf("����ϡ������з���Ԫ�صĸ���=");
	scanf_s("%d", &matrix.nonZeroNumber);

	if (matrix.nonZeroNumber > MAXSIZE)
		printf("����Ԫ�صĸ���������ԭ��������\n");
	else{
		printf("��	��	Ԫ��ֵ\n");
		int row, col, data;
		for (int i = 1; i <= matrix.nonZeroNumber; i++)
		{
			scanf_s("%d%d%d", &row, &col, &data);
			matrix.data[i].x = row;
			matrix.data[i].y = col;
			matrix.data[i].value = data;
		}
	}
}

//��ӡϡ�����
void printTSMatrix(TSMATRIX matrix)
{
	printf("�к� �к� ֵ\n");
	for (int i = 1; i <= matrix.nonZeroNumber; i++)
	{
		printf("%d\t%d\t%d\n", matrix.data[i].x, matrix.data[i].y, matrix.data[i].value);
	}
}

//�жϾ���λ�õ�Ԫ���Ƿ�Ϊ0�������Ϊ0������������ֵ
int isNonZeroElem(TSMATRIX matrix, int row, int col)
{
	int nonZeroNumber = matrix.nonZeroNumber;
	for (int i = 1; i <= nonZeroNumber && matrix.data[i].x <= i; i++)
	{
		if (matrix.data[i].x == row && matrix.data[i].y == col)
		{
			return matrix.data[i].value;
		}
	}
	return 0;
}

//ϡ�����ĵ�Ч�˷�����
void multiplyTSMatrix(TSMATRIX matrixA, TSMATRIX matrixB, TSMATRIX &matrixC) 
{
	//�жϾ���A�������Ƿ����B������
	if (matrixA.cols != matrixB.rows)
		printf("���������ܽ����������");
	else{
		//����C�ĳ�ʼ��
		matrixC.rows = matrixA.rows;
		matrixC.cols = matrixB.cols;
		matrixC.nonZeroNumber = 0;
		//��Ҫ��ѭ���жϱ����ͼ������
		int rowsC = matrixC.rows;
		int colsC = matrixC.cols;
		int colsA = matrixA.cols;
		int a, b;
		a = b = 0;
		int c = 0; //������¼����C�ķ���Ԫ�ظ���
		//�ж��Ƿ�Ϊ�������
		if (matrixA.nonZeroNumber * matrixB.nonZeroNumber != 0)
		{
			for (int i = 1; i <= rowsC; i++)
			{
				for (int j = 1; j <= colsC; j++)
				{
					int temp = 0; //����˻���ֵÿ�ζ�����
					for (int k = 1; k <= colsA; k++)
					{
						//���ļ���,�����ѽ��
						temp += isNonZeroElem(matrixA, i, k) * isNonZeroElem(matrixB, k, j);
					}
					//�жϼ���Ľ���Ƿ�Ϊ�㣬��Ϊ����ѹ��������C��
					if (temp != 0)
					{
						c++;
						matrixC.nonZeroNumber++;
						matrixC.data[c].x = i;
						matrixC.data[c].y = j;
						matrixC.data[c].value = temp;
					}
				}
			}
		}
	}
}
