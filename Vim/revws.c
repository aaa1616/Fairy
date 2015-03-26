#include "revws.h"

static void swap(char *s, int b, int e) {
	while (b < e) {
		s[b] ^= s[e];
		s[e] ^= s[b];
		s[b] ^= s[e];
		b++;
		e--;
	}
}

void reverseWords(char *s) {
	int i = 0;
	int b = -1, e = -1;
	if (s[i] == 0) {
		return;
	}
	while (1) {
		if (s[i] != ' ') {
			e++;
			s[e] = s[i];
		}
		if ((b != e) && (s[i + 1] == ' ' || s[i + 1] == 0)) {
			swap(s, b + 1, e);
			e++;
			s[e] = ' ';
			b = e;
		}
		if (s[i + 1] == 0) {
			break;
		}
		i++;
	}
	if (e == -1) {
		e = 0;
	}
	s[e] = 0;
	if (e > 0) {
		swap(s, 0, e - 1);
	}
}