#include <stdlib.h>
#include <string.h>
#include "arrayUtilLib.h"

typedef int (*predicate)(int , int);

typedef struct{
	int start;
	predicate test;
	int length;
	int step;
} Loop;

arrayUtil create(int size,int elements)
{
	arrayUtil util;
	util.baseAddress = calloc(elements,size);
	util.typeSize = size;
	util.length = elements;
	return util;
}

arrayUtil resize(arrayUtil util, int newlength)
{
	char *ch;
	int oldSize,newSize,difference;
	ch = (char*)util.baseAddress;
	util.baseAddress = realloc(util.baseAddress,util.typeSize*newlength);	
	oldSize = util.length * util.typeSize;
	newSize = newlength * util.typeSize;
	difference = newSize - oldSize;
	if(difference > 0)
		memset(ch+oldSize,0,difference);
	util.length = newlength;
	return util;
}

int findIndex(arrayUtil util,void* element)
{
	int index,exists;
	for(index=0;index<util.length;index++)
	{
		exists = memcmp(util.baseAddress+(util.typeSize*index),element,util.typeSize);
		if(exists==0) return index;
	}
	return -1;
}

void dispose(arrayUtil util)
{
	free(util.baseAddress);
}

int lessThan(int item,int hint){
	return item<hint;
}
int greaterThan(int item,int hint){
	return item>hint;
}
void* find(Loop loop,arrayUtil util,MatchFunc* MatchFunc,void *hint){
	int i;
	void *item;
	for(i=loop.start; loop.test(i,loop.length);i+=loop.step)
	{
		item = util.baseAddress+util.typeSize*i;
		if(MatchFunc(hint,item))
			return item;
	}
	return NULL;
}

void* findFirst(arrayUtil util,MatchFunc* MatchFunc,void* hint){
	Loop loop  = {0,lessThan,util.length,1};
	return find(loop,util,MatchFunc,hint);
}

void* findLast(arrayUtil util, MatchFunc* match, void* hint){
	Loop loop = {util.length,greaterThan,-1,-1};
	return find(loop,util,match,hint);
}

int count(arrayUtil util, MatchFunc* match, void* hint){
	int i,count=0;
	int typeSize = util.typeSize;
	for(i=0; i<util.length; i++){
		if(match(hint, util.baseAddress + (i * typeSize)))
			count++;
	}
		return count;
}
int filter(arrayUtil util, MatchFunc* match, void* hint, void** destination, int maxItems ){
	int i,count = 0;
    void* base = util.baseAddress;
  for(i = 0;i < util.length; i++){
    if(match(hint, base + i * util.typeSize)){
        if(count<maxItems){
          destination[count] = base + i * util.typeSize;
          count++;
        }
    }
  }
 return count;
}