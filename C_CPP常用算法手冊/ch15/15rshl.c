
void rshl(p, n)
int n;
double p[];
{
    int k, j, i;
    double t;
    k = n / 2;

    while (k > 0) {
        for (j = k; j <= n - 1; j++) {
            t = p[j];
            i = j - k;

            while ((i >= 0) && (p[i] > t)) {
                p[i + k] = p[i];
                i = i - k;
            }

            p[i + k] = t;
        }

        k = k / 2;
    }

    return;
}

