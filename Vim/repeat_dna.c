#include "repeat_dna.h"

#define HASH_JEN_MIX(a,b,c)                                                      \
	do {                                                                             \
	a -= b; a -= c; a ^= ( c >> 13 );                                              \
	b -= c; b -= a; b ^= ( a << 8 );                                               \
	c -= a; c -= b; c ^= ( b >> 13 );                                              \
	a -= b; a -= c; a ^= ( c >> 12 );                                              \
	b -= c; b -= a; b ^= ( a << 16 );                                              \
	c -= a; c -= b; c ^= ( b >> 5 );                                               \
	a -= b; a -= c; a ^= ( c >> 3 );                                               \
	b -= c; b -= a; b ^= ( a << 10 );                                              \
	c -= a; c -= b; c ^= ( b >> 15 );                                              \
	} while (0)
int hashFun(int *key, int keylen, int num_bkts) {
	unsigned _hj_i, _hj_j, _hj_k;                                                    \
		unsigned char *_hj_key = (unsigned char*)(key);                                  \
		int hashv = 0xfeedbeef;                                                            \
		_hj_i = _hj_j = 0x9e3779b9;                                                    \
		_hj_k = (unsigned)(keylen);                                                    \
	while (_hj_k >= 12) {
		\
			_hj_i += (_hj_key[0] + ((unsigned)_hj_key[1] << 8)                      \
			+ ((unsigned)_hj_key[2] << 16)                                         \
			+ ((unsigned)_hj_key[3] << 24));                                      \
			_hj_j += (_hj_key[4] + ((unsigned)_hj_key[5] << 8)                      \
			+ ((unsigned)_hj_key[6] << 16)                                         \
			+ ((unsigned)_hj_key[7] << 24));                                      \
			hashv += (_hj_key[8] + ((unsigned)_hj_key[9] << 8)                         \
			+ ((unsigned)_hj_key[10] << 16)                                        \
			+ ((unsigned)_hj_key[11] << 24));                                     \
			\
			HASH_JEN_MIX(_hj_i, _hj_j, hashv);                                          \
			\
			_hj_key += 12;                                                              \
			_hj_k -= 12;                                                                \
	}                                                                              \
	hashv += keylen;                                                               \
	switch (_hj_k) {
			\
	case 11: hashv += ((unsigned)_hj_key[10] << 24);                          \
	case 10: hashv += ((unsigned)_hj_key[9] << 16);                           \
	case 9:  hashv += ((unsigned)_hj_key[8] << 8);                            \
	case 8:  _hj_j += ((unsigned)_hj_key[7] << 24);                           \
	case 7:  _hj_j += ((unsigned)_hj_key[6] << 16);                           \
	case 6:  _hj_j += ((unsigned)_hj_key[5] << 8);                            \
	case 5:  _hj_j += _hj_key[4];                                               \
	case 4:  _hj_i += ((unsigned)_hj_key[3] << 24);                           \
	case 3:  _hj_i += ((unsigned)_hj_key[2] << 16);                           \
	case 2:  _hj_i += ((unsigned)_hj_key[1] << 8);                            \
	case 1:  _hj_i += _hj_key[0];                                               \
		}                                                                              \
		HASH_JEN_MIX(_hj_i, _hj_j, hashv);                                             \
		return hashv & (num_bkts - 1);
}
char **findRepeatedDnaSequences(char *input, int *outputSize) {
	int bit[1024] = { 0 };
	char code[128] = { 0 };
	char *str;
	char **ret;
	code['A'] = 0x00;
	code['C'] = 0x01;
	code['T'] = 0x02;
	code['G'] = 0x03;
	int i = 1;
	unsigned int val = 0;
	*outputSize = 0;
	while (input[i] != 0) {
		val = (val << 2 | code[input[i]]) & 0x0fffff;
		i++;
		if (i < 10) {
			continue;
		}
		int hashv = hashFun(&val, sizeof(int), 1024);
		if (bit[hashv] == 0) {
			bit[hashv] = 1;
		}
		else if (bit[hashv] == 1){
			bit[hashv] = 2;
			//strncpy(temp, input + i - 10, 10);
			//temp[10] = 0;
			//printf("First : %s\n", temp);
			(*outputSize)++;
		}
	}
	if (*outputSize <= 0) {
		return NULL;
	}
	ret = malloc(*outputSize * sizeof(char *));
	str = malloc(*outputSize * 10 * sizeof(char));
	i = 1;
	int count = 0;
	memset(bit, 0, 1024 * sizeof(int));
	while (input[i] != 0) {
		val = (val - (code[input[i - 1]] << (2 * 9))) << 2 | code[input[i]];
		i++;
		if (i < 10) {
			continue;
		}
		int hashv = hashFun(&val, sizeof(int), 1024);
		if (bit[hashv] == 0) {
			bit[hashv] = 1;
		}
		else if (bit[hashv] == 1){
			bit[hashv] = 2;
			memcpy(str + 10 * count, input + i - 10, 10);
			ret[count] = str + 10 * count;
			//strncp/*y(temp, input + i - 10, 10);
			//temp[10] = 0;
			//printf(*/"Second : %s\n", temp);
			count++;
		}
	}
	return ret;
}

char bit[1024 * 1024] = { 0 };

char **findRepeatedDnaSequencesTT(char *input, int *outputSize) {
	char temp[11];
	char code[128] = { 0 };
	char *str;
	char **ret;
	code['A'] = 0x00;
	code['C'] = 0x01;
	code['T'] = 0x02;
	code['G'] = 0x03;
	int i = 1;
	unsigned int val = 0;
	*outputSize = 0;
	while (input[i] != 0) {
		val = (val << 2 | code[input[i]]) & 0x0fffff;
		i++;
		if (i < 10) {
			continue;
		}
		if (bit[val] == 0) {
			bit[val] = 1;
		}
		else if (bit[val] == 1){
			bit[val] = 2;
			(*outputSize)++;
		}
	}
	if (*outputSize <= 0) {
		return NULL;
	}
	ret = malloc(*outputSize * sizeof(char *));
	str = malloc(*outputSize * 10 * sizeof(char));
	i = 1;
	int count = 0;
	memset(bit, 0, 1024 * 1024 * sizeof(char));
	while (input[i] != 0) {
		val = (val - (code[input[i - 1]] << (2 * 9))) << 2 | code[input[i]];
		i++;
		if (i < 10) {
			continue;
		}
		//int hashv = hashFun(&val, sizeof(int), 1024);
		if (bit[val] == 0) {
			bit[val] = 1;
		}
		else if (bit[val] == 1){
			bit[val] = 2;
			memcpy(str + 10 * count, input + i - 10, 10);
			ret[count] = str + 10 * count;
			count++;
		}
	}
	return ret;
}
