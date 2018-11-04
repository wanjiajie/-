#ifndef _BIT_ARRAY_H
#define _BIT_ARRAY_H
#define ERROR_BIT -1
#define ERROR_NULL -2
#define BIT_STATE_ON 1
#define BIT_STATE_OFF 0
#include <limits.h>
typedef struct bit_array* bit_array;
//bit 需创建的维数组宽度，bit 值不为0且须为A_BYTE整数倍
bit_array bitarray_create(unsigned long bits);
//销毁对象target
int bitarray_destroy(bit_array target);
//要设置的位
int bitarray_set_bit(bit_array target, unsigned long bit);
int bitarray_clear_bit(bit_array target, unsigned long bit);
int bitarray_test_bit(bit_array target, unsigned long bit);
//return目标位数组位容量
unsigned long bitarray_max_bits(bit_array target);
#endif
#include <stdlib.h>
#include "bitarray.h"
const unsigned char A_BYTE = CHAR_BIT;
//通常char_bit=8bit=1byte
const unsigned char MASK_1 = 1;
struct bitarray {
	unsigned char*byte_arr;
	unsigned long max_bits;
	unsigned long len;
}bitarray;
bit_array bitarray_create(unsigned long bits)
{
	bit_array tmp = NULL;
	unsigned long len = 0;
	if (bits == 0 || (bits%A_BYTE) != 0)
		return NULL;
	tmp = malloc(sizeof(bitarray));
	if (tmp == NULL)return NULL;
	len = bits/A_BYTE;
	tmp->byte_arr = calloc(len, sizeof(unsigned char));
	if (tmp->byte_arr == NULL)
	{
		free(tmp);
		return NULL;
	}
	tmp->len = len;
	tmp->max_bits = bits;
	return tmp;
}
int bitarray_destroy(bit_array target)
{
	if (target == NULL)
		return ERROR_NULL;
	else {
		free(target->byte_arr);//先释放底层数组对象空间、
		free(target);//再释放对象本身
		return 1；
	}
}
unsigned long bitarray_max_bits(bit_array target)
{
	if (taget == NULL)
		return 0;
	return target->max_bits;
}
int bitarray_set_bit(bit_array target, unsigned long bit)
{
	if (target == NULL)
		return ERROR_NULL;
	if (bit >= target->max_bits)
		return ERROR_BIT;
	unsigned long idx;//底层数组元素中索引
	unsigned int pos;//在其元素的第几位
	idx = target->len - 1 - (bit / A_BYTE);
	pos = (bit%A_BYTE);
	target->byte_arr[idx] |= MASK_1 << pos;//指定位设置为开
	return 1;
}
int bitarray_clear_bit(bit_array target, unsigned long bit)
{
	if (target == NULL)
		return ERROR_NULL;
	if (bits >= target->max_bits)
		return ERROR_BIT;
	unsigned long idx;
	unsigned int pos;
	idx = target->len - 1 - (bit / A_BYTE);
	pos = (bit%A_BYTE);
	target->byte_arr[idx] &= ~(MASK_1 << pos);
	return 1;

}
int bitarray_test_bit(bit_array target, unsigned long bit)
{
	if (target == NULL)
		return ERROR_NULL;
	if (bit >= target_max_bits)
		return ERROR_BIT;
	unsigned long idx;
	unsigned long pos;
	idx = target->len - 1 - (bit / A_BYTE);
	pos = (bit%A_BYTE);
	if (target->byte_arr[idx] & (MASK_1 << pos))
		return BIT_STATE_ON;
	else
		return BIT_STATE_OFF;
}
#include <stdio.h>
int main()
{
	bit_array tes;
	tes = bitarray_create(CHAR_BIT * 800);//创建一包含8*800=6400位的位数组
	if (tes!= NULL) {
		int max = bitarray_max_bits(tes);
		printf("max_bits=%ld\n", bitarray_max_bits(tes));
		printf("\n set \n");
		//把偶数位全置1，打印位数组
		for (int i = 0; i < max; i += 2)
			bitarray_set_bit(tes, i);
		for (int j = 0; j < max; j++)
			printf("%d", bit_array_test_bit(tes, j));
		printf("\n clear \n");
		//再把偶数位设置为0，再打印
		for (int i = 0; i < max; i += 2)
			bit_array_clear_bit(tes, i);
		for (int j = 0; j < max; j++)
			printf("%d", bitarray_test_bit(tes, j));
		printf("\n done \n");
		bitarray_destroy(tes);
		tes = NULL;
	}
	return 0;


}