#include <stdio.h>
#include <string.h>

char s[5001];

void get_lex_min(char *best, char *current, int k) {
    int len = strlen(current);
    char temp[10002]; 
    strcpy(temp, current);
    while (strlen(temp) < k) {
        strcat(temp, current);
    }
    temp[k] = '\0';
    if (strlen(best) == 0 || strcmp(temp, best) < 0) {
        strcpy(best, temp);
    }
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    scanf("%s", s);
    char best[5001] = "";
    get_lex_min(best, s, k);
    for (int i = 1; i < n; i++) {
        char current[5001];
        strncpy(current, s, i); 
        current[i] = '\0';
        get_lex_min(best, current, k);
    }
    printf("%s\n", best);
    return 0;
}
