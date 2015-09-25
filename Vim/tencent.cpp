//#include <stdio.h>
//#include <stdint.h>
//#include <iostream>
//#include <string>
//#include <vector>
//
//using namespace std;
//void compute_grayCode(int n, vector<int> &temp)
//{
//	unsigned int highest = 1 << n - 1;
//	if (n == 0){
//		temp.push_back(0);
//		return;
//	}
//	if (n == 1){
//		temp.push_back(0);
//		temp.push_back(1);
//		return;
//	}
//	compute_grayCode(n - 1, temp);
//	vector<int> r_temp(temp);
//	reverse(r_temp.begin(), r_temp.end());
//	for (int i = 0; i<r_temp.size(); ++i)
//		temp.push_back(highest | r_temp[i]);
//}
//vector<int> grayCode(int n){
//	vector<int> result;
//	string s;
//	s.e
//	compute_grayCode(n, result);
//	return result;
//
//}
//
//
//
//
//int main()
//{
//	grayCode(3);
//	return 0;
//}