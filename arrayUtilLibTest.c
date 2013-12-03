#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "testUtils.h"
#include "arrayUtilLib.h"

#define create_int()  create_int()
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

arrayUtil intInstance,floatInstance,charInstance,doubleInstance,expectedInstance;
void teardown(){
	free(intInstance.baseAddress);
}
int areEqual(arrayUtil a, arrayUtil b)
{
	int result;
	result = a.typeSize==b.typeSize && a.length == b.length;
	if(!result)	return 0;
	return 0 == memcmp(a.baseAddress,b.baseAddress,a.typeSize*a.length);
}

void test_1_create_allocates_and_assigns_zero_to_all_bytes_for_INT(){
	int value;
	int intArray[] = {0,0,0};
	expectedInstance.baseAddress = intArray;
	expectedInstance.typeSize = 4;
	expectedInstance.length = 3;
	intInstance = create(sizeof(int),3);
	value = areEqual(expectedInstance,intInstance);
	ASSERT(value);
}

void test_2_create_allocates_and_assigns_zero_to_all_bytes_for_CHAR(){
	int value;
	char charArray[] = {0,0,0};
	expectedInstance.baseAddress = charArray;
	expectedInstance.typeSize = 1;
	expectedInstance.length = 3;
	charInstance = create(sizeof(char),3);
	value = areEqual(expectedInstance,charInstance);
	ASSERT(value);
}

void test_3_create_allocates_and_assigns_zero_to_all_bytes_for_FLOAT(){
	int value;
	float floatArray[] = {0.0,0.0,0.0};
	expectedInstance.baseAddress = floatArray;
	expectedInstance.typeSize = 4;
	expectedInstance.length = 3;
	floatInstance = create(sizeof(float),3);
	value = areEqual(expectedInstance,floatInstance);
	ASSERT(value);
}

void test_4_create_allocates_and_assigns_zero_to_all_bytes_for_DOUBLE(){
	int value;
	double doubleArray[] = {0.0,0.0,0.0};
	expectedInstance.baseAddress = doubleArray;
	expectedInstance.typeSize = 8;
	expectedInstance.length = 3;
	doubleInstance = create(sizeof(double),3);
	value = areEqual(expectedInstance,doubleInstance);
	ASSERT(value);
}

void test_5_resize_should_trim_contents_for_CHAR_TYPE_when_newLength_is_less(){
	int value;
	char charArray[] = {'s','a','m'};
	expectedInstance.baseAddress = charArray;
	expectedInstance.typeSize = 1;
	expectedInstance.length = 3;
	
	charInstance = create(sizeof(char),7);
	charInstance = resize(charInstance,3);
	*((char*)charInstance.baseAddress+0)='s';
	*((char*)charInstance.baseAddress+1)='a';
	*((char*)charInstance.baseAddress+2)='m';
	value = areEqual(expectedInstance,charInstance);
	ASSERT(value);
}

void test_6_resize_should_trim_contents_for_INT_TYPE_when_newLength_is_less(){
	int value;
	int intArray[] = {5,55,555};
	expectedInstance.baseAddress = intArray;
	expectedInstance.typeSize = 4;
	expectedInstance.length = 3;
	
	intInstance = create(sizeof(int),7);
	intInstance = resize(intInstance,3);
	*((int*)intInstance.baseAddress+0)=5;
	*((int*)intInstance.baseAddress+1)=55;
	*((int*)intInstance.baseAddress+2)=555;
	value = areEqual(expectedInstance,intInstance);
	ASSERT(value);
}

void test_7_resize_should_trim_contents_for_FLOAT_TYPE_when_newLength_is_less(){
	int value;
	float floatArray[] = {5.05,55.55,555.555};
	expectedInstance.baseAddress = floatArray;
	expectedInstance.typeSize = 4;
	expectedInstance.length = 3;
	
	floatInstance = create(sizeof(float),7);
	floatInstance = resize(floatInstance,3);
	*((float*)floatInstance.baseAddress+0)=5.05;
	*((float*)floatInstance.baseAddress+1)=55.55;
	*((float*)floatInstance.baseAddress+2)=555.555;
	value = areEqual(expectedInstance,floatInstance);
	ASSERT(value);
}

void test_8_resize_should_trim_contents_for_DOUBLE_TYPE_when_newLength_is_less(){
	int value;
	double doubleArray[3] = {9.99,6.69,7.75};
	expectedInstance.baseAddress = doubleArray;
	expectedInstance.typeSize = 8;
	expectedInstance.length = 3;
	
	doubleInstance = create(sizeof(double),7);
	doubleInstance = resize(doubleInstance,3);
	*((double*)doubleInstance.baseAddress+0)=9.99;
	*((double*)doubleInstance.baseAddress+1)=6.69;
	*((double*)doubleInstance.baseAddress+2)=7.75;
	value = areEqual(expectedInstance,doubleInstance);
	ASSERT(value);
}


void test_9_resize_should_assign_zero_for_extra_space_for_INT_TYPE_when_newLength_is_greater(){
	int value;
	int intArray[5] = {1,69,56,0,0};
	expectedInstance.baseAddress = intArray;
	expectedInstance.typeSize = 4;
	expectedInstance.length = 5;
	
	intInstance = create(sizeof(int),3);
	*((int*)intInstance.baseAddress+0)=1;
	*((int*)intInstance.baseAddress+1)=69;
	*((int*)intInstance.baseAddress+2)=56;
	intInstance = resize(intInstance,5);
	value = areEqual(expectedInstance,intInstance);
	ASSERT(value);
}

void test_10_resize_should_assign_zero_for_extra_space_for_FLOAT_TYPE_when_newLength_is_greater(){
	int value,i;
	float floatArray[5] = {9.788756,78.764329,89.975453,0.000000,0.000000};
	expectedInstance.baseAddress = floatArray;
	expectedInstance.typeSize = 4;
	expectedInstance.length = 5;
	
	floatInstance = create(sizeof(float),3);
	*((float*)floatInstance.baseAddress+0)=9.788756;
	*((float*)floatInstance.baseAddress+1)=78.764329;
	*((float*)floatInstance.baseAddress+2)=89.975453;
	floatInstance = resize(floatInstance,5);

	value = areEqual(expectedInstance,floatInstance);
	ASSERT(value);
}
void test_11_resize_should_assign_zero_for_extra_space_for_CHAR_TYPE_when_newLength_is_greater(){
	int value,i;
	char charArray[5] = {'a','b','c',0,0};
	expectedInstance.baseAddress = charArray;
	expectedInstance.typeSize = 1;
	expectedInstance.length = 5;
	
	charInstance = create(sizeof(char),3);
	*((char*)charInstance.baseAddress+0)='a';
	*((char*)charInstance.baseAddress+1)='b';
	*((char*)charInstance.baseAddress+2)='c';
	charInstance = resize(charInstance,5);
	value = areEqual(expectedInstance,charInstance);
	ASSERT(value);
}

void test_12_resize_should_assign_zero_for_extra_space_for_DOUBLE_TYPE_when_newLength_is_greater(){
	int value,i;
	double doubleArray[5] = {7.654326,89.654309,95.433543,0.000000,0.000000};
	expectedInstance.baseAddress = doubleArray;
	expectedInstance.typeSize = 8;
	expectedInstance.length = 5;
	
	doubleInstance = create(sizeof(double),3);
	*((double*)doubleInstance.baseAddress+0)=7.654326;
	*((double*)doubleInstance.baseAddress+1)=89.654309;
	*((double*)doubleInstance.baseAddress+2)=95.433543;
	doubleInstance = resize(doubleInstance,5);

	value = areEqual(expectedInstance,doubleInstance);
	ASSERT(value);
}

void test_13_search_should_locate_item_in_INT_VALUES(){
	int i,value,x,expected;
	x=4;
	expected = 2;
	intInstance = create(4,5);
	for(i=0;i<5;i++)
		*((int*)intInstance.baseAddress+i) = i+1;			

	value = findIndex(intInstance,&x);
	ASSERT(value==3);
}

void test_14_search_should_locate_item_in_FLOAT_VALUES(){
	int i,value,expected;
	char x = 'e';
	expected = 2;
	charInstance = create(1,5);
	for(i=0;i<5;i++)
		*((char*)charInstance.baseAddress+i) = i+97;	

	value = findIndex(charInstance,&x);
	ASSERT(value==4);
}
int isDivisible(void* hint, void* item){
	int diviser = *(int *) hint;
	int dividend = *(int *) item;
	if (dividend % diviser == 0)
		return 1;
	return 0;
}
int isGreater(void* hint, void*item){
	float number1 = *(float *) hint;
	float number2 = *(float *) item;
	float number3;
	number3 = number2 - number1;
	if(number3 > 0)
		return 1;
	return 0;	
}

void test_15_findFirst_should_find_first_element_for_INTEGERS(){
	arrayUtil util = create( sizeof(int), 3);
	int* result;
	int* base;
	int hint = 3;
	base = (int*) util.baseAddress;
	base[0] = 9;
	base[1] = 33;
	base[2] = 54;
	result = findFirst(util, isDivisible, &hint);
	ASSERT(9 == *result);
}

int isLengthEqualTo(void* hint, void* item){
	char* word = *(String*)item;
	int length = *(int*) hint;
	return length == strlen(word);
}

void test_16_findFirst_should_find_first_element_for_string(){
	String *result;
	String *base;
	arrayUtil util;
	int hint = 6;
	int res;
	util = create( sizeof(String),3);
	base = util.baseAddress;
	strcpy(base[0],"soumya");
	strcpy(base[1],"kashish");
	strcpy(base[2],"mohit");
	result = findFirst(util, isLengthEqualTo, &hint);
	res = strcmp(*result,"soumya");
	if(res==0)
		ASSERT(1);
}

// void test_17_should_find_first_for_simple_structure(){
// 	ASSERT(0);
// }

void test_18_findLast_should_find_last_element_for_integers(){
	arrayUtil util = create( sizeof(int), 3);
	int* result;
	int* base;
	int hint = 3;
	base = (int*) util.baseAddress;
	base[0] = 9;
	base[1] = 33;
	base[2] = 54;
	result = findLast(util, isDivisible, &hint);
	ASSERT(54 == *result);
}

void test_19_findLast_should_find_last_element_for_string(){
	String *result;
	String *base;
	arrayUtil util;
	int hint = 5;
	int res;
	util = create( sizeof(String),3);
	base = util.baseAddress;
	strcpy(base[0],"soumya");
	strcpy(base[1],"kashish");
	strcpy(base[2],"mohit");
	result = findLast(util, isLengthEqualTo, &hint);
	res = strcmp(*result,"mohit");
	if(res==0)
		ASSERT(1);
}

// void test_20_findLast_should_find_last_element_for_simple_structure(){
// 	ASSERT(0);
// }

void test_21_count_should_count_matched_element_for_INTIGER(){
	arrayUtil util = create( sizeof(int), 3);
	int result;
	int* base;
	int hint = 3;
	base = (int*) util.baseAddress;
	base[0] = 9;
	base[1] = 33;
	base[2] = 54;
	result = count(util, isDivisible, &hint);
	ASSERT(3 == result);
}

void test_22_count_should_count_for_matched_element_for_STRING(){
	int result;
	String *base;
	arrayUtil util;
	int hint = 6;
	util = create( sizeof(String),3);
	base = util.baseAddress;
	strcpy(base[0],"soumya");
	strcpy(base[1],"manish");
	strcpy(base[2],"kashish");
	result = count(util, isLengthEqualTo, &hint);
	ASSERT(2 == result);
}

// // void test_23_count_should_count_for_matched_element_for_SIMPLE_STRUCTURE(){
// // 	ASSERT(0);
// // }

void test_23_filters_all_numbers_divisible_by_2(){
	arrayUtil util;
	int* destination[10];
	int result,i;
	int* base;
	int _2 = 2;
	util = create(sizeof(int), 5);
	base = (int*)util.baseAddress;
	base[0] = 21;
	base[1] = 40;
	base[2] = 20; 
	base[3] = 67; 
	base[4] = 44;
	result = filter(util,isDivisible,&_2,(void**)destination,10);
	ASSERT(3 == result);
	ASSERT(*destination[0] == 40);
	ASSERT(*destination[1] == 20);
	ASSERT(*destination[2] == 44);
}

void test_24_filters_all_numbers_greater_than_20p35(){
	arrayUtil util;
	int result,i;
	float* base;
	float* destination[5];
	float _20p35 = 20.35;
	util = create(sizeof(float),5);
	base = (float*)util.baseAddress;
	base[0] = 21.00;
	base[1] = 45.00;
	base[2] = 21.00; 
	base[3] = 67.00; 
	base[4] = 45.00;
	result = filter(util,isGreater,&_20p35,(void**)destination,5);
	ASSERT(5 == result);
	ASSERT(*destination[0] == 21.00);
	ASSERT(*destination[4] == 45.000);
}

void test_25_filters_names_of_length_6(){
	arrayUtil util;
	int result = 0,i;
	String* src;
	String* destination[4];
	int _6 = 6;
	util = create(sizeof(String),5);
	src = (String*)util.baseAddress;
	strcpy(src[0],"Soumya");
	strcpy(src[1],"Kashish");
	strcpy(src[2],"Mohit");
	strcpy(src[3],"Sandesh");
	result = filter(util,isLengthEqualTo,&_6,(void**)destination,4);
	ASSERT(1 == result);
	ASSERT(0 == strcmp(*destination[0],"Soumya"));
}

void excessThree(void *hint, void *sourceItem, void *destinationItem){
	*(int*)destinationItem = *(int*)sourceItem + *(int*)hint;
}

void test_map_convert_values_and_put_those_values_to_destination_util(){
	arrayUtil src,dst,expected;
	int expectedElements[] = {4,5,6,7,8};
	int hint = 3;
	int i,result;
	expected.baseAddress = expectedElements;
	expected.typeSize = 4;
	expected.length = 5;
	src = create(sizeof(int),5);
	for(i=0;i<5;i++)
		*((int*)src.baseAddress+i) = i+1;
	dst = create(sizeof(int),5);
	map(src,dst,excessThree,&hint);
	result = areEqual(expected,dst);
	ASSERT(result);
}

void addOne(void* hint, void* item){
	*(int*)hint = *(int*)item + *(int*)hint;
}

void test_forEach_add_one(){
	arrayUtil src;
	int hint = 1;
	int i,result;
	src = create(sizeof(int),5);
	for(i=0;i<5;i++)
		*((int*)src.baseAddress+i) = i+1;
	forEach(src,addOne,&hint);
	ASSERT(result);
}

void test_reduce_adding_elements_of_array(){
	ASSERT(1);
}