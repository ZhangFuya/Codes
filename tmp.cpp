/*
 * 马士兵算法与数据结构公开课三个排序算法：选择、冒泡、插入
 * 分别使用c语言的API和C++的API完成
 */

#ifndef MJC_SORT1
#define MJC_SORT1

void swapArrElem(int arr[], int index1, int index2);
void selectSort(int* arr, int length);
void bubbleSort(int* arr, int length);
void insertSort(int* arr, int length);

#endif  //MJC_SORT1

#include "mjcSort1.h"
#include <stddef.h>

void swapArrElem(int arr[], int index1, int index2) {
	int tmp = arr[index1];
	arr[index1] = arr[index2];
	arr[index2] = tmp;
}  //swapArrElem

void selectSort(int* arr, int length) {
	for (int i = 0; i < length; i++) {
		int minValueIndex = i;
		for (int j = i + 1; j < length; j++) {
			arr[minValueIndex] > arr[j] ? minValueIndex = j : NULL;
		}
		if (minValueIndex > i) swapArrElem(arr, minValueIndex, i);
	}
}  //selectSort

void bubbleSort(int* arr, int length) {
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length - i - 1; j++) {
			if (arr[j] > arr[j + 1]) swapArrElem(arr, j, j + 1);
		}
	}
}  //bubbleSort

void insertSort(int* arr, int length) {
	for (int i = 0; i < length; i++) {
		for (int j = i; j >= 1; j--) {
			if (arr[j] < arr[j - 1]) swapArrElem(arr, j, j - 1);
		}
	}
}  //insertSort


/*
 * da yin yi ge zheng shu de 32 wei
 */
#define _CRT_SECURE_NO_WARNINGS 1
#ifndef DA_YIN_ER_JIN_ZHI
#define DA_YIN_ER_JIN_ZHI

#include <stdio.h>
#include <stdlib.h>

void daYinErJinZhi(int data) {
	size_t iCount = sizeof(data) * 8;
	printf("%d de er jin zhi shu wei: ", data);
	for (int i = iCount - 1; i >= 0; i--) {
		printf("%d", (data & (1 << i)) ? 1 : 0);
	}
	printf("\n");
}


// 求数组下标在任意区间的累加和
int quJianHe(int arr[], int arrLength, int L, int R) {
	int* newArr = (int*)malloc(sizeof(int) * arrLength);
	if (newArr) {
		newArr[0] = arr[0];
		for (int i = 1; i < arrLength; i++) {
			newArr[i] = newArr[i - 1] + arr[i];
		}
		return L == 0 ? newArr[R] : newArr[R] - newArr[L - 1];
	}
	return -1;
}


#endif  //DA_YIN_ER_JIN_ZHI

#include <stdio.h>
#include "mjcSort1.h"
#include "DaYinErJinZhi.h"

int main(int argc, char const* argv[]) {
	int arr[] = { 25,35,68,79,21,13,98,7,16,62 };
	int arrLength = sizeof(arr) / sizeof(int);
	//insertSort(arr, arrLength);
	for (int i = 0; i < arrLength; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	printf("quJianHe: %d\n", quJianHe(arr, arrLength, 0, 1));

	return 0;
}  //main
