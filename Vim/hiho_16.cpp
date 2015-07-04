//#include <cstdio>
//#include <map>
//#include <string>
//#include <cmath>
//
//using namespace std;
//
//#define L 5
//#define S 100
//#define Q 4
//
//#define MIN(a, b) nodes[(a)].h < nodes[(b)].h ? (a) : (b)
//
//typedef struct TreeNode {
//    int first, next;
//    int h, arraypos;
//    string name;
//}TREENODE;
//
//int gIndex = 0;
//
//TREENODE nodes[L];
//int m[Q];
//int pre[Q][2 * L];
//map<string, int> names;
//
//void process(int n, int q)
//{
//    int i, j, l;
//    m[0] = 1;
//    for (i = 1 ; i < Q ; i++) {
//        m[i] = m[i - 1] << 1;
//    }
//    for (i = 1 ; i <= q ; i++) {
//        l = n - m[i];
//        for(j = 0 ; j <= l ; j++) {
//            pre[i][j] = MIN(pre[i - 1][j], pre[i - 1][j + m[i - 1]]);
//
//        }
//    }
//}
//
//void build(int ai, string n1, int bi, string n2)
//{
//    int i;
//    nodes[bi].name = n2;
//    if (nodes[ai].first == 0) {
//        nodes[ai].first = bi;
//        nodes[ai].name = n1;
//    }else {
//        nodes[bi].next = nodes[nodes[ai].first].next;
//        nodes[nodes[ai].first].next = bi;
//        nodes[bi].h = nodes[ai].h + 1;
//    }
//}
//void dfs(int u)
//{
//    int i;
//    pre[0][gIndex] = u;
//    nodes[u].arraypos = gIndex++;
//    for (i = nodes[u].first; i != 0; i = nodes[i].next) {
//        dfs(i);
//        pre[0][gIndex] = u;
//        nodes[u].arraypos = gIndex++;
//	}
//}
//
//
//int main()
//{
//	FILE *file = fopen("input.txt", "r");
//    int i, q, n, l, r, t, ai, bi, ret;
//    char name1[S], name2[S];
//    fscanf(file, "%d", &n);
//    while (n--) {
//        fscanf(file, "%s %s", name1, name2);
//        string n1(name1), n2(name2);
//        map<string, int>::iterator it1, it2;
//        it1 = names.find(n1);
//        it2 = names.find(n2);
//        if (it1 != names.end()) {
//            ai = it1->second;
//        }else {
//            ai = gIndex;
//            names[n1] = gIndex++;
//        }
//        if (it2 != names.end()) {
//            bi = it2->second;
//        }else {
//            bi = gIndex;            
//            names[n2] = gIndex++;
//        }
//        build(ai, n1, bi, n2);
//    }
//    
//    gIndex = 0;
//    dfs(0);
//    n = gIndex;
//    q = log(n) / log(2);
//    process(n, q);
//    
//    fscanf(file, "%d", &n);
//    while (n--) {
//        fscanf(file, "%s %s", name1, name2);
//        string n1(name1), n2(name2);
//        l = nodes[names[n1]].arraypos + 1;
//        r = nodes[names[n2]].arraypos + 1;
//        if (l > r) {
//            l ^= r;
//            r ^= l;
//            l ^= r;
//        }
//
//        t = log(r - l + 1) / log(2);
//        ret = MIN(pre[t][l - 1], pre[t][r - m[t]]);
//        printf("%s\n", nodes[ret].name.c_str());
//    }
//    return 0;
//}