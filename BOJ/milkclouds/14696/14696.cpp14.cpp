#include <stdio.h>
 
char chk(int Aar[], int Bar[]) {
    if (Aar[4] > Bar[4])
        return 'A';
    else if (Aar[4] < Bar[4])
        return 'B';
    else {
        if (Aar[3] > Bar[3])
            return 'A';
        else if (Aar[3] < Bar[3])
            return 'B';
        else {
            if (Aar[2] > Bar[2])
                return 'A';
            else if (Aar[2] < Bar[2])
                return 'B';
            else {
                if (Aar[1] > Bar[1])
                    return 'A';
                else if (Aar[1] < Bar[1])
                    return 'B';
                else
                    return 'D';
            }
        }
    }
}
 
int main()
{
    int N;
    scanf("%d", &N);
    for (int index = 0, a, b; index < N; ++index) {
        scanf("%d", &a);
        int Ahash[5], Bhash[5];
        for (int k = 0; k < 5; ++k)
            Ahash[k] = 0, Bhash[k] = 0;
        for (int j = 0, get; j < a; ++j) {
            scanf("%d", &get);
            Ahash[get]++;
        }
        scanf("%d", &b);
        for (int j = 0, get; j < b; ++j) {
            scanf("%d", &get);
            Bhash[get]++;
        }
        char ans = chk(Ahash, Bhash);
        printf("%c\n", ans);
        for (int k = 0; k < 5; ++k)
            Ahash[k] = 0, Bhash[k] = 0;
    }
    return 0;
}