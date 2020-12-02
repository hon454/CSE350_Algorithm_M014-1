#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <time.h>

#include "Fighter.h"

using namespace std;

class Comparator
{
public:
	virtual bool operator()(Fighter& a, Fighter& b) = 0;
};

class FighterCompareByYear : virtual public Comparator
{
public:
	virtual bool operator()(Fighter& a, Fighter& b)
	{
		if (a.getYearByInteger() > b.getYearByInteger()) {
			return true;
		}
		return false;
	}
};

class FighterCompareByNumber : virtual public Comparator
{
public:
	virtual bool operator()(Fighter& a, Fighter& b)
	{
		if (a.getNumberByInteger() > b.getNumberByInteger()) {
			return true;
		}
		return false;
	}
};

void swap(Fighter* xp, Fighter* yp)
{
	Fighter temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void show(vector<Fighter>& fighters)
{
	for (Fighter fighter : fighters)
	{
		cout << fighter.getName() << ", "
		<< fighter.getCountry() << ", "
		<<  fighter.getYear() << ", "
		<< fighter.getStatus() << ", "
		<< fighter.getNumber() << endl;
	}
}

vector<Fighter> BubbleSort(vector<Fighter> v, Comparator& cmp);
vector<Fighter> SelectionSort(vector<Fighter> v, Comparator& cmp);
vector<Fighter> ShellSort(vector<Fighter> v, Comparator& cmp);
vector<Fighter> MergeSort(vector<Fighter> v, Comparator& cmp);
void MergeSortRecursive(vector<Fighter>& v, Comparator& cmp, int l, int r);
void merge(vector<Fighter>& v, Comparator& cmp, int l, int m, int r);

int main()
{
	ifstream in("Fighters.csv");
	vector<Fighter> fighters;
	
	if (!in.is_open())
	{
		cout << "해당 경로에 위치하는 파일이 존재하지 않습니다." << endl;
		return 0;
	}

	while(in.good())
	{
		string line;
		getline(in, line);
		
		stringstream ss(line);
		string token;
		vector<string> split;
		while (getline(ss, token, ','))
		{
			split.push_back(token);
		}

		if (split.size() == 5)
		{
			fighters.emplace_back(split[0], split[1], split[2], split[3], split[4]);
		}
	}
	
	in.close();

	FighterCompareByYear compareByYear;
	FighterCompareByNumber compareByNumber;

	clock_t start, end;
	double elapsedTime;
	vector<Fighter> sorted;

	{
		cout << "###생산년도 기준 오름차순###" << endl;
		// Bubble Sort(생산년도 기준 오름차순)
		start = clock();
		sorted = BubbleSort(fighters, compareByYear);
		end = clock();
		elapsedTime = static_cast<double>(end - start);
		cout << "Bubble Sort 경과시간: " << elapsedTime << "ms" << endl;

		// Selection(생산년도 기준 오름차순)
		start = clock();
		sorted = SelectionSort(fighters, compareByYear);
		end = clock();
		elapsedTime = static_cast<double>(end - start);
		cout << "Selection 경과시간: " << elapsedTime << "ms" << endl;

		// Shell sort Sort(생산년도 기준 오름차순)
		start = clock();
		sorted = ShellSort(fighters, compareByYear);
		end = clock();
		elapsedTime = static_cast<double>(end - start);
		cout << "Shell sort Sort 경과시간: " << elapsedTime << "ms" << endl;

		// Merge Sort(생산년도 기준 오름차순)
		start = clock();
		sorted = MergeSort(fighters, compareByYear);
		end = clock();
		elapsedTime = static_cast<double>(end - start);
		cout << "Merge Sort 경과시간: " << elapsedTime << "ms" << endl;

		// Quick Sort(생산년도 기준 오름차순)
		start = clock();		
		sorted = fighters;
		sort(sorted.begin(), sorted.end(), compareByYear);
		end = clock();
		elapsedTime = static_cast<double>(end - start);
		cout << "Quick Sort 경과시간: " << elapsedTime << "ms" << endl;
		
		cout << endl << endl;
	}

	{
		cout << "###생산대수 기준 오름차순###" << endl;
		
		// Bubble Sort(생산대수 기준 오름차순)
		start = clock();
		sorted = BubbleSort(fighters, compareByNumber);
		end = clock();
		elapsedTime = static_cast<double>(end - start);
		cout << "Bubble Sort 경과시간: " << elapsedTime << "ms" << endl;

		// Selection(생산대수 기준 오름차순)
		start = clock();
		sorted = SelectionSort(fighters, compareByNumber);
		end = clock();
		elapsedTime = static_cast<double>(end - start);
		cout << "Selection 경과시간: " << elapsedTime << "ms" << endl;

		// Shell sort Sort(생산대수 기준 오름차순)
		start = clock();
		sorted = ShellSort(fighters, compareByNumber);
		end = clock();
		elapsedTime = static_cast<double>(end - start);
		cout << "Shell sort Sort 경과시간: " << elapsedTime << "ms" << endl;

		// Merge Sort(생산대수 기준 오름차순)
		start = clock();
		sorted = MergeSort(fighters, compareByNumber);
		end = clock();
		elapsedTime = static_cast<double>(end - start);
		cout << "Merge Sort 경과시간: " << elapsedTime << "ms" << endl;

		// Quick Sort(생산대수 기준 오름차순)
		start = clock();
		sorted = fighters;
		sort(sorted.begin(), sorted.end(), compareByNumber);
		end = clock();
		elapsedTime = static_cast<double>(end - start);
		cout << "Quick Sort 경과시간: " << elapsedTime << "ms" << endl;
		
		cout << endl << endl;
	}

	{
		cout << "###생산년도 기준 오름차순후 생산 대수 기준 오름차순###" << endl;
		
		// Bubble Sort(생산년도 기준 오름차순후 생산 대수 기준 오름차순)
		start = clock();
		sorted = BubbleSort(fighters, compareByYear);
		sorted = BubbleSort(sorted, compareByNumber);
		end = clock();
		elapsedTime = static_cast<double>(end - start);
		cout << "Bubble Sort 경과시간: " << elapsedTime << "ms" << endl;

		// Selection(생산년도 기준 오름차순후 생산 대수 기준 오름차순)
		start = clock();
		sorted = SelectionSort(fighters, compareByYear);
		sorted = SelectionSort(sorted, compareByNumber);
		end = clock();
		elapsedTime = static_cast<double>(end - start);
		cout << "Selection 경과시간: " << elapsedTime << "ms" << endl;

		// Shell sort Sort(생산년도 기준 오름차순후 생산 대수 기준 오름차순)
		start = clock();
		sorted = ShellSort(fighters, compareByYear);
		sorted = ShellSort(sorted, compareByNumber);
		end = clock();
		elapsedTime = static_cast<double>(end - start);
		cout << "Shell sort Sort 경과시간: " << elapsedTime << "ms" << endl;

		// Merge Sort(생산년도 기준 오름차순후 생산 대수 기준 오름차순)
		start = clock();
		sorted = MergeSort(fighters, compareByYear);
		sorted = MergeSort(sorted, compareByNumber);
		end = clock();
		elapsedTime = static_cast<double>(end - start);
		cout << "Merge Sort 경과시간: " << elapsedTime << "ms" << endl;

		// Quick Sort(생산년도 기준 오름차순후 생산 대수 기준 오름차순)
		start = clock();
		sorted = fighters;
		sort(sorted.begin(), sorted.end(), compareByYear);
		sort(sorted.begin(), sorted.end(), compareByNumber);
		end = clock();
		elapsedTime = static_cast<double>(end - start);
		cout << "Quick Sort 경과시간: " << elapsedTime << "ms" << endl;
		
		cout << endl << endl;
	}
	
	return 0;
}


vector<Fighter> BubbleSort(vector<Fighter>v, Comparator& cmp)
{
	int n = v.size();
	
	for (int i = 0; i < n - 1; ++i)
	{
		bool isSwapped = false;
		for (int j = 0; j < n - i - 1; ++j)
		{
			if (cmp(v[j], v[j + 1]))
			{
				isSwapped = true;
				swap(&v[j], &v[j + 1]);
			}
		}
	
		if (isSwapped == false)
		{
			break;
		}
	}
	
	return v;
}

vector<Fighter> SelectionSort(vector<Fighter> v, Comparator& cmp)
{
	int n = v.size();
	for (int i = 0; i < n - 1; ++i)
	{
		int minIndex = i;
		for (int j = i + 1; j < n; ++j)
		{
			if (cmp(v[minIndex], v[j]))
			{
				minIndex = j;
			}
		}
		swap(&v[minIndex], &v[i]);
	}
	return v;
}

vector<Fighter> ShellSort(vector<Fighter> v, Comparator& cmp)
{
	int n = v.size();

	for (int gap = n/2; gap > 0; gap /= 2)
	{
		for (int i = gap; i < n; i += 1)
		{
			Fighter temp = v[i];

			int j;
			for (j = i; j >= gap && cmp(v[j - gap] , v[i]); j -= gap)
			{
				v[j] = v[j - gap];
			}
			v[j] = temp;
		}
	}
	
	return v;
}

void Merge(vector<Fighter>& v, Comparator& cmp, int l, int m, int r)
{
	const int leftSize = m - l + 1;
	const int rightSize = r - m;

	vector<Fighter> left;;
	vector<Fighter> right;

	for (int i = 0; i < leftSize; ++i)
	{
		left.push_back(v[l + i]);
	}

	for (int i = 0; i < rightSize; ++i)
	{
		right.push_back(v[m + 1 + i]);
	}

	int i = 0;
	int j = 0;
	int k = l;

	while (i < leftSize && j < rightSize) 
	{
		if (cmp(right[j], left[i])) 
		{
			v[k] = left[i];
			i++;
		}
		else 
		{
			v[k] = right[j];
			j++;
		}
		k++;
	}

	while (i < leftSize) 
	{
		v[k] = left[i];
		i++;
		k++;
	}

	while (j < rightSize) 
	{
		v[k] = right[j];
		j++;
		k++;
	}
}

void MergeSortRecursive(vector<Fighter>& v, Comparator& cmp, int l, int r)
{
	if (l >= r)
	{
		return;
	}
	int m = (l + r - 1) / 2;
	MergeSortRecursive(v, cmp, l, m);
	MergeSortRecursive(v, cmp, m + 1, r);
	Merge(v, cmp, l, m, r);
}

vector<Fighter> MergeSort(vector<Fighter> v, Comparator& cmp)
{
	MergeSortRecursive(v, cmp, 0, v.size() - 1);
	return v;
}