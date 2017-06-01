#pragma once
#include <iostream>
#define MAXSIZE 100

//三元组储存结构
typedef struct TRIPLE
{
	int x, y;//元素的横纵坐标
	int value;//元素的值
}TRIPLE;

//稀疏矩阵结构
typedef struct TSMATRIX
{
	TRIPLE data[MAXSIZE + 1];//稀疏矩阵中非零元素
	int rows, cols, nonZeroNumber;//稀疏矩阵的行数，列数，非零元素个数
}TSMATRIX;

//创建稀疏矩阵
void createTSMATRIX(TSMATRIX &matrix)
{
	printf("输入稀疏矩阵的行数=");
	scanf_s("%d", &matrix.rows);
	printf("输入稀疏矩阵的列数=");
	scanf_s("%d", &matrix.cols);
	printf("输入稀疏矩阵中非零元素的个数=");
	scanf_s("%d", &matrix.nonZeroNumber);

	if (matrix.nonZeroNumber > MAXSIZE)
		printf("非零元素的个数超过了原来的设置\n");
	else{
		printf("行	列	元素值\n");
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

//打印稀疏矩阵
void printTSMatrix(TSMATRIX matrix)
{
	for (int i = 1; i <= matrix.nonZeroNumber; i++)
	{
		printf("%d\t%d\t%d\n", matrix.data[i].x, matrix.data[i].y, matrix.data[i].value);
	}
}

//判断具体位置的元素是否为0，如果不为0，返回其数据值
bool isNonZeroElem(TSMATRIX matrix, int row, int col, int &data)
{
	int nonZeroNumber = matrix.nonZeroNumber;
	for (int i = 1; i <= nonZeroNumber; i++)
	{
		if (matrix.data[i].x == row && matrix.data[i].y == col)
		{
			data = matrix.data[i].value;

			return true;
		}
	}
	return false;
}

//稀疏矩阵的乘法运算
void multiplyTSMatrix(TSMATRIX matrixA, TSMATRIX matrixB, TSMATRIX &matrixC)
{
	//判断矩阵A的列数是否等于B的行数
	if (matrixA.cols != matrixB.rows)
		printf("两个矩阵不能进行相乘运算");
	else{
		//矩阵C的初始化
		matrixC.rows = matrixA.rows;
		matrixC.cols = matrixB.cols;
		matrixC.nonZeroNumber = 0;
		//需要的循环判断变量和计算变量
		int rowsC = matrixC.rows;
		int colsC = matrixC.cols;
		int colsA = matrixA.cols;
		int a, b;
		a = b = 0;
		int c = 0; //用来记录矩阵C的非零元素个数
		//判断是否为非零矩阵
		if (matrixA.nonZeroNumber * matrixB.nonZeroNumber != 0)
		{
			for (int i = 1; i <= rowsC; i++)
			{
				for (int j = 1; j <= colsC; j++)
				{
					int temp = 0; //储存乘积的值每次都清零
					for (int k = 1; k <= colsA; k++)
					{
						//核心计算，暂时有问题
						if (isNonZeroElem(matrixA, i, k, a) && isNonZeroElem(matrixB, k, j, b))
							temp += a * b;
					}
					//判断计算的结果是否为零，不为零则压缩到矩阵C中
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
