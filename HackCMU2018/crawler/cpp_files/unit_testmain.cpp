#include <iostream>
#include <sys/time.h>

#include "../tsl/util/ArrayAccessor.hpp"
#include "../tsl/util/VerifySort.hpp"
#include "../tsl/util/Benchmark.hpp"
#include "../tsl/Sort.hpp"

#define countof(x) (sizeof(x) / sizeof(x[0]))

char message[] = "WDCEFAJILOPVRGHQSBUKNXZMTY";
char message_sorted[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main(void)
{
	using namespace tsl;
	using namespace tsl::util;

	unsigned long count = 100000;

	ArrayAccessor<char> arrayAccessor(message, countof(message) - 1);
	ArrayAccessor<char> sortedArray(message_sorted, countof(message_sorted) - 1);
	struct timeval delta;

	if (VerifySort<ArrayAccessor<char> >::verify(BubbleSort<ArrayAccessor<char> >::sort, arrayAccessor, sortedArray, arrayAccessor.size()))
	{
		Benchmark<ArrayAccessor<char> >::benchmark(BubbleSort<ArrayAccessor<char> >::sort, &delta, count, arrayAccessor, arrayAccessor.size());
		printf("%ld iterations of BubbleSort took %f seconds\n", count, delta.tv_sec + (delta.tv_usec) / 1000000.0);
	} else {
		printf("BubbleSort fails\n");
	}

	if (VerifySort<ArrayAccessor<char> >::verify(CocktailSort<ArrayAccessor<char> >::sort, arrayAccessor, sortedArray, arrayAccessor.size()))
	{
		Benchmark<ArrayAccessor<char> >::benchmark(CocktailSort<ArrayAccessor<char> >::sort, &delta, count, arrayAccessor, arrayAccessor.size());
		printf("%ld iterations of CocktailSort took %f seconds\n", count, delta.tv_sec + (delta.tv_usec) / 1000000.0);
	} else {
		printf("CocktailSort fails\n");
	}

	if (VerifySort<ArrayAccessor<char> >::verify(CombSort<ArrayAccessor<char> >::sort, arrayAccessor, sortedArray, arrayAccessor.size()))
	{
		Benchmark<ArrayAccessor<char> >::benchmark(CombSort<ArrayAccessor<char> >::sort, &delta, count, arrayAccessor, arrayAccessor.size());
		printf("%ld iterations of CombSort took %f seconds\n", count, delta.tv_sec + (delta.tv_usec) / 1000000.0);
	} else {
		printf("CombSort fails\n");
	}

	if (VerifySort<ArrayAccessor<char> >::verify(GnomeSort<ArrayAccessor<char> >::sort, arrayAccessor, sortedArray, arrayAccessor.size()))
	{
		Benchmark<ArrayAccessor<char> >::benchmark(GnomeSort<ArrayAccessor<char> >::sort, &delta, count, arrayAccessor, arrayAccessor.size());
		printf("%ld iterations of GnomeSort took %f seconds\n", count, delta.tv_sec + (delta.tv_usec) / 1000000.0);
	} else {
		printf("GnomeSort fails\n");
	}

	if (VerifySort<ArrayAccessor<char> >::verify(InsertionSort<ArrayAccessor<char> >::sort, arrayAccessor, sortedArray, arrayAccessor.size()))
	{
		Benchmark<ArrayAccessor<char> >::benchmark(InsertionSort<ArrayAccessor<char> >::sort, &delta, count, arrayAccessor, arrayAccessor.size());
		printf("%ld iterations of InsertionSort took %f seconds\n", count, delta.tv_sec + (delta.tv_usec) / 1000000.0);
	} else {
		printf("InsertionSort fails\n");
	}

	if (VerifySort<ArrayAccessor<char> >::verify(MergeSort<ArrayAccessor<char> >::sort, arrayAccessor, sortedArray, arrayAccessor.size()))
	{
		Benchmark<ArrayAccessor<char> >::benchmark(MergeSort<ArrayAccessor<char> >::sort, &delta, count, arrayAccessor, arrayAccessor.size());
		printf("%ld iterations of MergeSort took %f seconds\n", count, delta.tv_sec + (delta.tv_usec) / 1000000.0);
	} else {
		printf("MergeSort fails\n");
	}

	if (VerifySort<ArrayAccessor<char> >::verify(QuickSort<ArrayAccessor<char> >::sort, arrayAccessor, sortedArray, arrayAccessor.size()))
	{
		Benchmark<ArrayAccessor<char> >::benchmark(QuickSort<ArrayAccessor<char> >::sort, &delta, count, arrayAccessor, arrayAccessor.size());
		printf("%ld iterations of QuickSort took %f seconds\n", count, delta.tv_sec + (delta.tv_usec) / 1000000.0);
	} else {
		printf("QuickSort fails\n");
	}

	if (VerifySort<ArrayAccessor<char> >::verify(SelectionSort<ArrayAccessor<char> >::sort, arrayAccessor, sortedArray, arrayAccessor.size()))
	{
		Benchmark<ArrayAccessor<char> >::benchmark(SelectionSort<ArrayAccessor<char> >::sort, &delta, count, arrayAccessor, arrayAccessor.size());
		printf("%ld iterations of SelectionSort took %f seconds\n", count, delta.tv_sec + (delta.tv_usec) / 1000000.0);
	} else {
		printf("SelectionSort fails\n");
	}

	if (VerifySort<ArrayAccessor<char> >::verify(ShellSort<ArrayAccessor<char> >::sort, arrayAccessor, sortedArray, arrayAccessor.size()))
	{
		Benchmark<ArrayAccessor<char> >::benchmark(ShellSort<ArrayAccessor<char> >::sort, &delta, count, arrayAccessor, arrayAccessor.size());
		printf("%ld iterations of ShellSort took %f seconds\n", count, delta.tv_sec + (delta.tv_usec) / 1000000.0);
	} else {
		printf("ShellSort fails\n");
	}

	return 0;
}
