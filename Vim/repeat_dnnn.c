#include "repeat_dnnn.h"

//char bit[1024 * 1024] = { 0 };
#define BIT_SIZE 100
void jenMix(int *i, int *j, int *k)
{
	\
		int a = *i, b = *j, c = *k;
	a -= b; a -= c; a ^= (c >> 13);                                              \
		b -= c; b -= a; b ^= (a << 8);                                               \
		c -= a; c -= b; c ^= (b >> 13);                                              \
		a -= b; a -= c; a ^= (c >> 12);                                              \
		b -= c; b -= a; b ^= (a << 16);                                              \
		c -= a; c -= b; c ^= (b >> 5);                                               \
		a -= b; a -= c; a ^= (c >> 3);                                               \
		b -= c; b -= a; b ^= (a << 10);                                              \
		c -= a; c -= b; c ^= (b >> 15);                                              \
		*i = a;
	*j = b;
	*k = c;
}

int hashFuns(int *key,int keylen,int num_bkts)                                  \
{
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
			jenMix(&_hj_i, &_hj_j, &hashv);                                          \
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
		jenMix(&_hj_i, &_hj_j, &hashv);                                             \
		return hashv & (num_bkts - 1);                                                    \
}
int hashFun(int *key,int keylen,int num_bkts)                                  \
{                                                                             \
  unsigned _hb_keylen=keylen;                                                    \
  char *_hb_key=(char*)(key);                                                    \
  int hashv = 0;                                                                   \
    while (_hb_keylen--)  { (hashv) = (((hashv) << 5) + (hashv)) + *_hb_key++; }   \
  return (hashv) & (num_bkts-1);                                                  \
}

char **findRepeatedDnaSequences(char *input, int *outputSize) {
	char bit[BIT_SIZE] = { 0 };
	char code[128] = { 0 };
	char *str;
	char **ret;
	code['A'] = 0x00;
	code['C'] = 0x01;
	code['T'] = 0x02;
	code['G'] = 0x03;
	int i = 0;
	unsigned int val = 0;
	*outputSize = 0;
	while (input[i] != 0) {
		val = (val << 2 | code[input[i]]) & 0x0fffff;
		i++;
		if (i < 10) {
			continue;
		}
		int hashv = hashFun(&val, sizeof(unsigned int), BIT_SIZE);
		if (bit[hashv] == 0) {
			bit[hashv] = 1;
		}
		else if (bit[hashv] == 1){
			bit[hashv] = 2;
			(*outputSize)++;
		}
	}
	if (*outputSize <= 0) {
		return NULL;
	}
	ret = malloc(*outputSize * sizeof(char *));
	str = malloc(*outputSize * 11 * sizeof(char));
	i = 0;
	int count = 0;
	memset(bit, 0, BIT_SIZE * sizeof(char));
	while (input[i] != 0) {
		val = (val << 2 | code[input[i]]) & 0x0fffff;
		i++;
		if (i < 10) {
			continue;
		}
		int hashv = hashFun(&val, sizeof(unsigned int), BIT_SIZE);
		if (bit[hashv] == 0) {
			bit[hashv] = 1;
		}
		else if (bit[hashv] == 1){
			bit[hashv] = 2;
			memcpy(str + 11 * count, input + i - 10, 10);
			*(str + 10 * count + 10) = 0;
			ret[count] = str + 11 * count;
			count++;
		}
	}
	return ret;
}