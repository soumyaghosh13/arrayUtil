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
int filter(arrayUtil util, MatchFunc* match, void* hint, void** dst, int maxItems );
typedef void ConvertFunc(void* hint, void* sourceItem, void* destinationItem);
void map(arrayUtil source, arrayUtil destination, ConvertFunc* convert, void* hint);
typedef void OperationFunc(void* hint, void* item);
void forEach(arrayUtil util, OperationFunc* operation, void* hint);
typedef void* ReducerFunc(void* hint, void* previousItem, void* item);
void reduce(arrayUtil util, ReducerFunc* reducer, void* hint, void* result);


