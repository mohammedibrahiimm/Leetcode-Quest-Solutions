class Solution {
public:
	string getPermutation(int n, int k) {
		string permutation;
		for (int i = 1; i <= n; i++)
			permutation += (i + '0');
		do {
		} while (--k >= 1 && next_permutation(all(permutation)) );
		return permutation;
	}
};