#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;

int findMajority(vector<int>vec, int n)
{
	int i, candidate = -1, votes = 0;

	for (i = 0; i < n; i++) {
		if (votes == 0) {
			candidate = vec[i];
			votes = 1;
		}
		else {
			if (vec[i] == candidate)
				votes++;
			else
				votes--;
		}
	}
	int count = 0;
	for (i = 0; i < n; i++) {
		if (vec[i] == candidate)
			count++;
	}

	if (count > n / 2)
		return candidate;
	return -1;
}
int main()
{
    vector<int>vec{1, 1, 1, 1, 2, 3, 4};
    int vec_size = vec.size();

	cout << "The majority element is : " << findMajority(vec, vec_size);

	return 0;
}
