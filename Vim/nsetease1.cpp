#include <stdio.h>
#include <vector>
#include <sstream>

using namespace std;

string dig[19] = { "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fiveteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
string dig2[8] = { "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };
string word3[3] = { "Thousand", "Million", "Billion" };

class Solution {
public:
	string numberToWords(int num) {
		string ret;
		int i = 0;
		if (num == 0) {
			return "Zero";
		}
		while (num) {
			if (num % 1000 != 0) {
				ret = word3[i] + " " + cal3dig(num % 1000) + ret;
			}
			num /= 1000;
			i++;
		}
	}
private:
	string cal3dig(int num) {
		int modn;
		string ret;
		modn = num % 100;
		num /= 100;

		if (num) {
			ret += dig[num - 1] + " Hundred ";
		}

		num = modn;
		if (num < 20 && num > 0) {
			ret += dig[num - 1] + " ";
		}
		else if (num >= 20) {
			modn = num % 10;
			num /= 10;

			ret += dig2[num - 2] + " ";

			if (modn != 0) {
				ret += dig[modn - 1] + " ";
			}
		}
		return ret;
	}
};

int main()
{
	Solution sl;
	sl.numberToWords(1234567891);
	return 0;
}