#include "Singleton.cpp"

// Easy typedef for example purposes, you would include 
// some type of data object that you would use instead
typedef void* DataType;

class DataTypeMgr : public Singleton <DataTypeMgr>
{
public:
	DataType* GetDataType(const char* name);
};

// Quick and easy, albeit a bit lazy, treat the singleton
// like a global for notational convenience
#define g_DataTypeMgr DataTypeMgr::GetSingleton()

void RandomFunction(void)
{
	DataType* data1 = DataTypeMgr::GetSingleton().GetDataType("your structure's name");
	DataType* data2 = g_DataTypeMgr.GetDataType("your structure's name");
}