#pragma once
#include <ctime>
#include <Windows.h>

class Math
{
public:

	template <typename T>
	static T Abs(T value)
	{
		return value < 0 ? -value : value;
	}

	template <typename T>
	static T Min(T a, T b)
	{
		return a < b ? a : b;
	}

	template <typename T>
	static T Max(T a, T b)
	{
		return a > b ? a : b;
	}

	template <typename T>
	static T Clamp(T value, T min, T max)
	{
		if (value < min) value = min;
		if (value > max) value = max;
		return value;
	}

	static int Random(int min, int max)
	{
		static int count = 1;
		srand(time(NULL) * count++);
		return rand() % (max - min) + min;
	}

	template <typename T>
	static void Swap(T* a, T* b)
	{
		T temp = *a;
		*a = *b;
		*b = temp;
	}

	template <typename T>
	static void Shuffle(T array[], int size, int count)
	{
		for (int i = 0; i < count; i++)
		{
			int a = Random(0, size);
			int b = Random(0, size);

			Swap(&array[a], &array[b]);
		}
	}
};