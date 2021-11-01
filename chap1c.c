#include <stdio.h> // Needed for printf

int swap_entries(int s[], int n, int i, int j)
{
    if ( (i<n) && (j<n) )
    {
        int x = s[i];
        int y = s[j];
        s[i] = y;
        s[j] = x ;
        return 0;
    }
    else return -1;
}

void print_array(int s[], int n)
{
    printf("[");
    for (int i=0; i+1<n; ++i) {printf("%d, ", s[i]);}
    if (n>0) {printf("%d", s[n-1]);}
    printf("]\n");
}

void insertion_sort(int s[], int n, int out[]) 
{
    int i, j, c=0;
    for (i=0; i<n; ++i) {out[i] = s[i];}
    for (i=1; i<n; ++i) 
    {
        j = i;
            while ((j > 0) && (out[j] < out[j-1]))
                {
                    swap_entries(out, n, j, j-1);
                    c++;
                    j--;
                }
    }
    printf("Number of operations: %d\n", c);
}

int main()
{
    int n=10;
    int ex[] = {17, 4, 0, -5, 22, -8, 13, 13, -7, -5};
    print_array(ex, n);

    int out[n];
    insertion_sort(ex, n, out);
    print_array(out, n); 


    return 0;
}