#include <bits/stdc++.h>
using namespace std;

vector<vector<double>> trimMat(vector<vector<double>> matrix, int x, int y) {
	int sz, p=-1, q=-1;
	sz = matrix.size() -1;
	vector<vector<double>> ans (sz, vector<double>(sz));
	for (int i=0;i<=sz;i++){
		if (i == x) continue;
		p++;q=-1;
		for (int j=0;j<=sz;j++){
			if (j == y) continue;
			q++;
			ans.at(p).at(q) = matrix.at(i).at(j);
		}
	}
	return ans;
}

double det(vector<vector<double>> matrix) {
	int sz = matrix.size();
	if (sz == 1) return matrix.at(0).at(0);
	double ans=0;
	for (int i=0;i<sz;i++){
		ans += pow(-1,i) * matrix.at(i).at(0) * det(trimMat(matrix, i, 0)) ;
	}
	return ans;
}
	

int main() {
	int n;
	cin >> n;
	vector<vector<double>> matrix (n, vector<double>(n));
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++){
			cin >> matrix.at(i).at(j);
		}
	cout << det(matrix) <<endl;
	
}
