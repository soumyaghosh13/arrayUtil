#include <stdio.h>

int testCount=-1;
int passCount=0;
void setup();
void tearDown();

void fixtureSetup();
void fixtureTearDown();
void incrementTestCount();
void incrementPassCount();
int currentTestFailed=0;

void testStarted(char* name){
	incrementTestCount();
	currentTestFailed=0;
	printf("\t%s\n",name);
}

void testEnded(){
	if(!currentTestFailed)
		incrementPassCount();
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

void testFailed(const char* fileName, int lineNumber, char* expression){
	currentTestFailed = 1;
	printf("\t\t %s : failed at %s:%d\n",expression, fileName,lineNumber);
}

int main(){
	fixtureSetup();
	resetTestCount();

	testStarted("test_1_create_allocates_and_assigns_zero_to_all_bytes_for_INT");
	setup();
		test_1_create_allocates_and_assigns_zero_to_all_bytes_for_INT();
	tearDown();
	testEnded();
	testStarted("test_2_create_allocates_and_assigns_zero_to_all_bytes_for_CHAR");
	setup();
		test_2_create_allocates_and_assigns_zero_to_all_bytes_for_CHAR();
	tearDown();
	testEnded();
	testStarted("test_3_create_allocates_and_assigns_zero_to_all_bytes_for_FLOAT");
	setup();
		test_3_create_allocates_and_assigns_zero_to_all_bytes_for_FLOAT();
	tearDown();
	testEnded();
	testStarted("test_4_create_allocates_and_assigns_zero_to_all_bytes_for_DOUBLE");
	setup();
		test_4_create_allocates_and_assigns_zero_to_all_bytes_for_DOUBLE();
	tearDown();
	testEnded();
	testStarted("test_5_resize_should_trim_contents_for_CHAR_TYPE_when_newLength_is_less");
	setup();
		test_5_resize_should_trim_contents_for_CHAR_TYPE_when_newLength_is_less();
	tearDown();
	testEnded();
	testStarted("test_6_resize_should_trim_contents_for_INT_TYPE_when_newLength_is_less");
	setup();
		test_6_resize_should_trim_contents_for_INT_TYPE_when_newLength_is_less();
	tearDown();
	testEnded();
	testStarted("test_7_resize_should_trim_contents_for_FLOAT_TYPE_when_newLength_is_less");
	setup();
		test_7_resize_should_trim_contents_for_FLOAT_TYPE_when_newLength_is_less();
	tearDown();
	testEnded();
	testStarted("test_8_resize_should_trim_contents_for_DOUBLE_TYPE_when_newLength_is_less");
	setup();
		test_8_resize_should_trim_contents_for_DOUBLE_TYPE_when_newLength_is_less();
	tearDown();
	testEnded();
	testStarted("test_9_resize_should_assign_zero_for_extra_space_for_INT_TYPE_when_newLength_is_greater");
	setup();
		test_9_resize_should_assign_zero_for_extra_space_for_INT_TYPE_when_newLength_is_greater();
	tearDown();
	testEnded();
	testStarted("test_10_resize_should_assign_zero_for_extra_space_for_FLOAT_TYPE_when_newLength_is_greater");
	setup();
		test_10_resize_should_assign_zero_for_extra_space_for_FLOAT_TYPE_when_newLength_is_greater();
	tearDown();
	testEnded();
	testStarted("test_11_resize_should_assign_zero_for_extra_space_for_CHAR_TYPE_when_newLength_is_greater");
	setup();
		test_11_resize_should_assign_zero_for_extra_space_for_CHAR_TYPE_when_newLength_is_greater();
	tearDown();
	testEnded();
	testStarted("test_12_resize_should_assign_zero_for_extra_space_for_DOUBLE_TYPE_when_newLength_is_greater");
	setup();
		test_12_resize_should_assign_zero_for_extra_space_for_DOUBLE_TYPE_when_newLength_is_greater();
	tearDown();
	testEnded();
	testStarted("test_13_search_should_locate_item_in_INT_VALUES");
	setup();
		test_13_search_should_locate_item_in_INT_VALUES();
	tearDown();
	testEnded();
	testStarted("test_14_search_should_locate_item_in_FLOAT_VALUES");
	setup();
		test_14_search_should_locate_item_in_FLOAT_VALUES();
	tearDown();
	testEnded();
	testStarted("test_15_findFirst_should_find_first_element_for_INTEGERS");
	setup();
		test_15_findFirst_should_find_first_element_for_INTEGERS();
	tearDown();
	testEnded();
	testStarted("test_16_findFirst_should_find_first_element_for_string");
	setup();
		test_16_findFirst_should_find_first_element_for_string();
	tearDown();
	testEnded();
	testStarted("test_18_findLast_should_find_last_element_for_integers");
	setup();
		test_18_findLast_should_find_last_element_for_integers();
	tearDown();
	testEnded();
	testStarted("test_19_findLast_should_find_last_element_for_string");
	setup();
		test_19_findLast_should_find_last_element_for_string();
	tearDown();
	testEnded();
	testStarted("test_21_count_should_count_matched_element_for_INTIGER");
	setup();
		test_21_count_should_count_matched_element_for_INTIGER();
	tearDown();
	testEnded();
	testStarted("test_22_count_should_count_for_matched_element_for_STRING");
	setup();
		test_22_count_should_count_for_matched_element_for_STRING();
	tearDown();
	testEnded();
	testStarted("test_23_filters_all_numbers_divisible_by_2");
	setup();
		test_23_filters_all_numbers_divisible_by_2();
	tearDown();
	testEnded();
	testStarted("test_24_filters_all_numbers_greater_than_20p35");
	setup();
		test_24_filters_all_numbers_greater_than_20p35();
	tearDown();
	testEnded();
	testStarted("test_25_filters_names_of_length_6");
	setup();
		test_25_filters_names_of_length_6();
	tearDown();
	testEnded();
	testStarted("test_map_convert_values_and_put_those_values_to_destination_util");
	setup();
		test_map_convert_values_and_put_those_values_to_destination_util();
	tearDown();
	testEnded();
	testStarted("test_forEach_add_one");
	setup();
		test_forEach_add_one();
	tearDown();
	testEnded();
	testStarted("test_reduce_adding_elements_of_array");
	setup();
		test_reduce_adding_elements_of_array();
	tearDown();
	testEnded();

	summarizeTestCount();
	fixtureTearDown();
	return 0;
}

void setup(){}

void tearDown(){}

void fixtureSetup(){}

void fixtureTearDown(){}
