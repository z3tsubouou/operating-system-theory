#include <stdio.h>

int main()
{
      int reference_string[20] = {7, 2, 3, 1, 2, 5, 3, 4, 6, 7, 7, 1, 0, 5, 4, 6, 2, 3, 0, 1}, page_faults = 0, m, n, s, pages = 19, frames = 3;

      int temp[frames];
      for (m = 0; m < frames; m++)
      {
            temp[m] = -1;
      }
      for (m = 0; m < pages; m++)
      {
            s = 0;
            for (n = 0; n < frames; n++)
            {
                  if (reference_string[m] == temp[n])
                  {
                        s++;
                        page_faults--;
                  }
            }
            page_faults++;
            if ((page_faults <= frames) && (s == 0))
            {
                  temp[m] = reference_string[m];
            }
            else if (s == 0)
            {
                  temp[(page_faults - 1) % frames] = reference_string[m];
            }
      }
      printf("\nPage Faults-ын тоо:\t%d\n", page_faults);
      return 0;
}