typedef struct 
{
	void *baseAddress;
	int typeSize;
	int length;
} arrayUtil;
typedef char String[256];

typedef struct 
{
	int id;
	int roll;
}simpleStructure;

arrayUtil create(int size,int elements);
arrayUtil resize(arrayUtil util, int newNoOfElements);
int findIndex(arrayUtil util,void* element);
void dispose(arrayUtil util);
typedef int MatchFunc(void* hint, void* item);
void* findFirst(arrayUtil util, MatchFunc* match, void* hint);
void* findLast(arrayUtil util, MatchFunc* match, void* hint);
int count(arrayUtil util, MatchFunc* match, void* hint);
int filter(arrayUtil util, MatchFunc* match, void* hint, void** destination, int maxItems );
