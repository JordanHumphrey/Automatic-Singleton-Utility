#include <cassert>

template <typename TAG> class Singleton
{
	static TAG* ms_Singleton;

public:
	Singleton(void)
	{
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