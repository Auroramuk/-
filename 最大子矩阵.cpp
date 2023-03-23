#include<iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;
class Solution {
public:
	int MaxMatrix(vector<vector<int>> a, int m, int n, int x, int y) {
		//int sum=0;
		int Maxsum = 0;
		for (int i = 0; i <= m - x; i++) {
			for (int j = 0; j <= n - y; j++) {
				int sum = 0;
				for (int p = i; p <= i + x - 1; p++) {
					for (int q = j; q <= j + y - 1; q++) {
						sum += a[p][q];
					}
				}
				if (sum > Maxsum)     Maxsum = sum;
			}
		}
		cout << Maxsum << endl;
		return 0;
	}
};

int main()
{
	freopen("in.txt", "r", stdin);
	int m, n, x, y;
	scanf("%d%d%d%d", &m, &n, &x, &y);
	vector<vector<int>> matrix;
	vector<int> line;
	string k;
	getline(cin, k);
	string s, temp;
	for (int i = 0; i < m; i++) {
		getline(cin, s);
		stringstream ss(s);
		while (ss >> temp) {
			line.push_back(atoi(temp.c_str()));
		}
		matrix.push_back(line);
		s.clear();
		temp.clear();
		line.clear();
		Solution sol;
		sol.MaxMatrix(matrix, m, n, x, y);
	}
}