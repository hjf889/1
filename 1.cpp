#include <iostream>
#include <vector>
#include <numeric>
#include <utility>

using namespace std;

pair<unsigned, unsigned> bsort(vector<int>& a) {
	unsigned cmp = 0, swp = 0, sz = a.size(), i, j;
	do {
		j = 0;
		for (i = 1; i < sz; ++i) {
			if (a[i - 1] > a[i]) {
				swap(a[i - 1], a[i]);
				j = i;
				++swp;
			}
			++cmp;
		}
		sz = j;
	} while (sz > 1);
	return make_pair(cmp, swp);
}

pair<unsigned, unsigned> isort(vector<int>& a) {
	unsigned cmp = 0, swp = 0, sz = a.size(), i, j;
	for (i = 1; i < sz; ++i) {
		for (j = i; j > 0 && a[j - 1] > a[j]; --j) {
			swap(a[j], a[j - 1]);
			++cmp;
			++swp;
		}
		++cmp;
	}
	return make_pair(cmp, swp);
}

void print(unsigned a[]) {
	for (int i = 0; i < 7; ++i)
		cout << '\t' << a[i];
}

int main() {
	size_t sz[] = { 53,103,203,405,809,1631,3299 },
		cmp_b[7], swp_b[7], cmp_i[7], swp_i[7];
	for (int i = 0; i < 7; ++i) {
		vector<int> arr1(sz[i]), arr2(sz[i]);
		iota(arr1.rbegin(), arr1.rend(), 0);
		arr2 = arr1;
		pair<unsigned, unsigned> tmp = bsort(arr1);
		cmp_b[i] = tmp.first;
		swp_b[i] = tmp.second;
		tmp = isort(arr2);
		cmp_i[i] = tmp.first;
		swp_i[i] = tmp.second;
	}
	cout << "\t sz:";
	print(sz);
	cout << "\nbsort:\n\tcmp:";
	print(cmp_b);
	cout << "\n\tswp:";
	print(swp_b);
	cout << "\nisort:\n\tcmp:";
	print(cmp_i);
	cout << "\n\tswp:";
	print(swp_i);
	cout << endl;
	system("pause");
	return 0;
}