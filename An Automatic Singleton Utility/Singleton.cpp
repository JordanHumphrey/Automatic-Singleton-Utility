#include <cassert>

template <typename TAG> class Singleton
{
	static TAG* ms_Singleton;

public:
	Singleton(void)
	{
		/*
		Constructor figures out the relative address of the dervied instance
		and stores the result in the singleton pointer. Since the derived class
		could be deriving from more than just the singleton, 'this' from SampleClass
		might be different from the singleton 'this'. Solution to this takes a
		non existant object sitting at address 0x1 in memory, cast it to both types,
		seeing the difference. This difference will be the distance between 
		Singleton<TAG> and its derived type SampleClass, which is used to calculate
		the singleton pointer.
		*/
		assert(!ms_Singleton);
		int offset = (int)(TAG*)1 - (int)(Singleton <TAG>*)(TAG*)1;
		ms_Singleton = (TAG*)((int)this + offset);
	}

	~Singleton(void)
	{
		assert(ms_Singleton);
		ms_Singleton = 0;
	}

	static TAG& GetSingleton(void)
	{
		assert(ms_Singleton);
		return (*ms_Singleton);
	}
	static TAG* GetSingletonPtr(void)
	{
		return (ms_Singleton);
	}

	template <typename TAG> TAG* Singleton <TAG> :: ms_Singleton = 0;
};