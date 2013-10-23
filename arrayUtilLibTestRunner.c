#include <stdio.h>

int testCount=0;
int passCount=0;

void setup();
void tearDown();

void fixtureSetup();
void fixtureTearDown();

void testStarted(char* name){
	printf("\t%s\n",name);
}

void resetTestCount(){
	testCount=0;
	passCount=0;
	printf("********* Starting tests\n\n");
}

void summarizeTestCount(){
	printf("\n********* Ran %d tests passed %d failed %d\n",testCount,passCount,testCount-passCount);
}

void incrementTestCount(){
	testCount++;
}

void incrementPassCount(){
	passCount++;
}

void testFailed(const char* fileName, int lineNumber){
	printf("\t\t*** failed at %s:%d\n",fileName,lineNumber);
}

int main(){
	fixtureSetup();
	resetTestCount();

	setup();
		test_1_create_allocates_and_assigns_zero_to_all_bytes_for_INT();
	tearDown();

	setup();
		test_2_create_allocates_and_assigns_zero_to_all_bytes_for_CHAR();
	tearDown();

	setup();
		test_3_create_allocates_and_assigns_zero_to_all_bytes_for_FLOAT();
	tearDown();

	setup();
		test_4_create_allocates_and_assigns_zero_to_all_bytes_for_DOUBLE();
	tearDown();

	setup();
		test_5_resize_should_trim_contents_for_CHAR_TYPE_when_newLength_is_less();
	tearDown();

	setup();
		test_6_resize_should_trim_contents_for_INT_TYPE_when_newLength_is_less();
	tearDown();

	setup();
		test_7_resize_should_trim_contents_for_FLOAT_TYPE_when_newLength_is_less();
	tearDown();

	setup();
		test_8_resize_should_trim_contents_for_DOUBLE_TYPE_when_newLength_is_less();
	tearDown();

	setup();
		test_9_resize_should_assign_zero_for_extra_space_for_INT_TYPE_when_newLength_is_greater();
	tearDown();

	setup();
		test_10_resize_should_assign_zero_for_extra_space_for_FLOAT_TYPE_when_newLength_is_greater();
	tearDown();

	setup();
		test_11_resize_should_assign_zero_for_extra_space_for_CHAR_TYPE_when_newLength_is_greater();
	tearDown();

	setup();
		test_12_resize_should_assign_zero_for_extra_space_for_DOUBLE_TYPE_when_newLength_is_greater();
	tearDown();

	setup();
		test_13_search_should_locate_item_in_INT_VALUES();
	tearDown();

	setup();
		test_14_search_should_locate_item_in_FLOAT_VALUES();
	tearDown();

	setup();
		test_15_findFirst_should_find_first_element_for_INTEGERS();
	tearDown();

	setup();
		test_16_findFirst_should_find_first_element_for_string();
	tearDown();

	setup();
		test_18_findLast_should_find_last_element_for_integers();
	tearDown();

	setup();
		test_19_findLast_should_find_last_element_for_string();
	tearDown();

	setup();
		test_21_count_should_count_matched_element_for_INTIGER();
	tearDown();

	setup();
		test_22_count_should_count_for_matched_element_for_STRING();
	tearDown();

	setup();
		test_23_filter_should_return_no_of_matched_element_for_integer();
	tearDown();

	setup();
		test_24_filter_should_return_no_of_matched_element_for_float();
	tearDown();

	setup();
		test_25_filter_should_return_no_of_matched_element_for_String();
	tearDown();


	summarizeTestCount();
	fixtureTearDown();
	return 0;
}

void setup(){}

void tearDown(){}

void fixtureSetup(){}

void fixtureTearDown(){}
