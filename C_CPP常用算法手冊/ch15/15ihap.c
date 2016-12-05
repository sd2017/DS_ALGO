
void ihap(p, n)
int n, p[];
{
    int i, mm, t;
    void isift();
    mm = n / 2;

    for (i = mm - 1; i >= 0; i--) {
        isift(p, i, n - 1);
    }

    for (i = n - 1; i >= 1; i--) {
        t = p[0];
        p[0] = p[i];
        p[i] = t;
        isift(p, 0, i - 1);
    }

    return;
}

static void isift(p, i, n)
int i, n, p[];
{
    int j, t;
    t = p[i];
    j = 2 * (i + 1) - 1;

    while (j <= n) {
        if ((j < n) && (p[j] < p[j + 1])) {
            j = j + 1;
        }

        if (t < p[j]) {
            p[i] = p[j];
            i = j;
            j = 2 * (i + 1) - 1;
        } else {
            j = n + 1;
        }
    }

    p[i] = t;
    return;
}

