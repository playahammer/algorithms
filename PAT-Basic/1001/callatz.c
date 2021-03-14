#include <stdio.h>

int main()
{
      int n, s = 0;
      scanf("%d", &n);

      while(n != 1)
      {
            if (n % 2 == 0)
                  n /= 2;
            else
                  n = (3 * n + 1) / 2;
            s++;
      }
      printf("%d\n", s);
      return 0;
}