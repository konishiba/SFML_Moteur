#pragma once

template <typename T>
class Singleton
{
public:
	inline static T& GetInstance()
	{
		static T _instance;
		return _instance;
	}
};

