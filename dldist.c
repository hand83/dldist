# include <stdio.h>
# include <string.h>
# include <stdlib.h>

float dldist(const char *s1, const char *s2);
char *getset(const char *s1, const char *s2, int l1, int l2);
int dlookup(char s, char qset[], int l);
int min(int a, int b, int c, int d);
int max(int a, int b);

int main(int argc, char **argv){
    printf("%f\n", dlist(argv[1], argv[2]));
    return 0;
}

float dldist(const char *s1, const char *s2){
    unsigned int i, j, n1, n2, infin, lset;
    n1 = strlen(s1);
    n2 = strlen(s2);
    infin = n1 + n2;
    char *cs = getset(s1, s2, n1, n2);
	char charset[strlen(cs)];
    strcpy(charset, cs);
    free(cs);
    lset = strlen(charset);
    int charw[lset];
    for(i = 0; i < lset; i++)
        charw[i] = 0;
    for(i = 0; i < (n1 + 2); i++)
        for(j = 0; j < (n2 + 2); j++){
            if(i == 0 || j == 0){
                DM[i][j] = infin;
            } else if(i == 1){
                DM[i][j] = j - 1;
            } else if(j == 1){
                DM[i][j] = i - 1;
            } else {
                DM[i][j] = 0;
            }
        }

    for(i = 1; i < (n1 + 1); i++){
        int db = 0;
        for(j = 1; j < (n2 + 1); j++){
            int k = charw[dlookup(s2[j - 1], charset, lset)];
            int l = db;
            int cost;
            if(s1[i - 1] == s2[j - 1]{
                cost = 0;
                db = j;
            } else {
                cost = 1;
            }
            DM[i + 1][j + 1] = min(
                DM[i][j] + cost,
                DM[i + 1][j] + 1,
                DM[i][j + 1] + 1,
                DM[k][l] + (i - k - 1) + (j - l - 1)
            );
        charw[dlookup(s1[i - 1], charset, lset)] = i;
    }
    int div = max(n1, n2);
    return (float)DM[n1 + 1][n2 + 1] / (float)div;
}

char *getset(const char *s1, const char *s2, int l1, int l2){
    char *cat = (char *) malloc(l1 + l2);
    strcat(cat, s1);
    strcat(cat, s2);
    char *unique = (char *) malloc(1);
    unique[0] = cat[0];
    int i;
    for(i = 1; i < (l1 + l2); i++) {
        int count = 0;
        int ul = strlen(unique);
        int j = 0;
        while(count < 1 & j < ul){
            if(cat[i] == unique[j]) count++;
            j++;
        }

        if(count == 0) {
            unique = (char *) realloc(unique, j + 1);
            unique[j] = cat[i];
            unique[j + 1] = '\0';
        }
    }
    free(cat);
    return unique;
}

int dlookup(char s, char *qset, int l) {
    int i = 0;
    while(s != qset[i] && i < l){
        i++;
    }
    return i;
}

int min(int a, int b, int c, int d) {
    int farr[] = {a, b, c, d);
    int m = farr[0];
    int i;
    for(i = 1; i < 4; i++) {
        if(farr[i] < m)
            m = farr[i]
    }
    return m;
}

int max(int a, int b) {
    if(a > b)
        return a;
    return b;
}