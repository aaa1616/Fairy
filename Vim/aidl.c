#include "aidl.h"

int parseAidl(FILE *file)
{
	char c;
	char token[100] = { 0 };
	char comment[10];
	char descriptor[100];
	int isComment = 0, isLineComment = 0;
	int ispackage = 0, isInterface = 0, isRetType = 0, isFunc = 0, isType = 1, isParam = 0;
	int total = 0;
	while ((c = getc(file)) != EOF) {
		if ((c == ' ' || c == '\t') && !isRetType && !isParam) {
			continue;
		}
		if (c == '\n' && isInterface != 1) {
			token[0] = 0;
		}
		//comment
		if (c == '/') {
			c = getc(file);
			if (c == '*') {
				while ((c = getc(file)) != EOF) {
					if (c == '*') {
						c = getc(file);
						if (c == '/') {
							break;
						}
						else {
							file->_cnt++;
							file->_ptr--;
						}
					}
				}
			}
			else if (c == '/') {
				while ((c = getc(file)) != '\n');
			}
			else {
				file->_cnt++;
				file->_ptr--;
			}
			continue;
		}
		//if (isComment && c != '*' && c != '/') {
		//	continue;
		//}
		//if (isLineComment){
		//	if (c != '\n') {
		//		continue;
		//	}
		//	else {
		//		isLineComment = 0;
		//	}
		//}
		if (c != ' ' && c != '\t' && c != '\n' && c != ';' && c != '{' && c != '(' && c != ',' && c != ')') {
			strncat(token, &c, 1);
		}
		//if (strcmp(token, "/*")) {
		//	isComment = 1;
		//	strcpy(token, "");
		//	continue;
		//}
		//if (strcmp(token, "//")) {
		//	isLineComment = 1;
		//	strcpy(token, "");
		//}
		//if (strcmp(token, "*/")) {
		//	isComment = 0;
		//	strcpy(token, "");
		//	continue;
		//}

		//descriptor
		if (ispackage != 2 && strcmp(token, "package") == 0) {
			ispackage = 1;
			token[0] = 0;
			continue;
		}
		if (ispackage == 1) {
			if (c != ';') {
				continue;
			}
			else {
				ispackage = 2;
				strcpy(descriptor, token);
				char *temp = ".";
				strcat(descriptor, temp);
				token[0] = 0;
				continue;
			}
		}
		//interface
		if (isInterface != 2 && strcmp(token, "interface") == 0) {
			isInterface = 1;
			token[0] = 0;
			continue;
		}
		if (isInterface == 1) {
			if (c != '{') {
				continue;
			}
			else {
				isInterface = 2;
				strcat(descriptor, token);
				//printf("descriptor:%s\n", descriptor);
				token[0] = 0;
				continue;
			}
		}
		if (isInterface == 2 && c == '}') {
			break;
		}
		//retType
		if (isInterface == 2 && isalpha(c) && isFunc == 0) {
			isRetType = 1;	//read blank
			continue;
		}
		if (isRetType) {
			if (c == ' ' || c == '\t') {
				isRetType = 0;
				isFunc = 1;
				token[0] = 0;
				continue;
			}
		}
		if (isFunc == 1) {
			if (c == '(') {
				isFunc = 2;
				//printf("Func:%s(",token);
				token[0] = 0;
				continue;
			}
		}
		if (isFunc == 2) {
			if (c != ')') {
				if (isalpha(c)) {
					isParam = 1;	//read blank
					continue;
				}
				if ((c == ' ' || c == '\t' || c == ',') && isParam == 1) {
					if (strcmp(token, "in") == 0 || strcmp(token, "out") == 0 || strcmp(token, "inout") == 0) {
						token[0] = 0;
						continue;
					}
					if (isType) {
						isType = 0;
						isParam = 0;
						//printf("%s ", token);
					}
					else {
						isType = 1;
						isParam = 0;
						//printf("%s,", token);
					}
					token[0] = 0;
				}
			}
			else {
				//printf("%s", token);
				//printf(");\n");
				isFunc = 0;
				isType = 1;
				isParam = 0;
				total++;
			}
		}
	}
	return total;
//	printf("Total : %d\n", total);
}
