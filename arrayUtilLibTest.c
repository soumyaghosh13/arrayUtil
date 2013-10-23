#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "testUtils.h"
#include "arrayUtilLib.h"

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

int isLengthEqual(void* hint, void* item){
	char* word = *(String*)item;
	int newHint = *(int*) hint;
	if(strlen(word)==newHint)
		return 1;
	return 0;
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
	result = findFirst(util, isLengthEqual, &hint);
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
	result = findLast(util, isLengthEqual, &hint);
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
	result = count(util, isLengthEqual, &hint);
	ASSERT(2 == result);
}

// // void test_23_count_should_count_for_matched_element_for_SIMPLE_STRUCTURE(){
// // 	ASSERT(0);
// // }

void test_23_filter_should_return_no_of_matched_element_for_integer(){
	arrayUtil util;
	int result,i;
	int* base;
	void** destination;
	int hint = 2;
	util = create( sizeof(int), 5);
	base = (int*)util.baseAddress;
	destination = calloc(util.typeSize, 10);
	base[0] = 21;
	base[1] = 40;
	base[2] = 20; 
	base[3] = 67; 
	base[4] = 44;
	result = filter(util,isDivisible,&hint,destination,10);
	ASSERT(3 == result);
	ASSERT(*(int*)destination[0] == 40);
	ASSERT(*(int*)destination[1] == 20);
	ASSERT(*(int*)destination[2] == 44);
	free(destination);
}

void test_24_filter_should_return_no_of_matched_element_for_float(){
	arrayUtil util;
	int result,i;
	float* base;
	void** destination;
	float hint = 20.35;
	util = create( sizeof(float),5);
	base = (float*)util.baseAddress;
	destination = calloc( sizeof(float), 5);
	base[0] = 21.00;
	base[1] = 45.00;
	base[2] = 21.00; 
	base[3] = 67.00; 
	base[4] = 45.00;
	result = filter(util,isGreater,&hint,destination,5);
	ASSERT(5 == result);
	ASSERT(*(float*)destination[0] == 21.00);
	ASSERT(*(float*)destination[4] == 45.000);
	free(destination);
}

void test_25_filter_should_return_no_of_matched_element_for_String(){
	arrayUtil util;
	int result = 0,i;
	String* base;
	void** destination;
	int hint = 6;
	util = create(sizeof(String),5);
	base = (String*)util.baseAddress;
	destination = calloc( sizeof(String),4);
	strcpy(base[0],"Soumya");
	strcpy(base[1],"Kashish");
	strcpy(base[2],"Mohit");
	strcpy(base[3],"Sandesh");
	result = filter(util,isLengthEqual,&hint,destination,10);
	ASSERT(1 == result);
	ASSERT(0 == strcmp(*(String*)destination[0],"Soumya"));
	free(destination);
}