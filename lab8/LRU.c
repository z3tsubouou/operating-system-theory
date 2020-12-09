#include <stdio.h>

int main()
{
      int frames[10], temp[10], pages[20] = {7, 2, 3, 1, 2, 5, 3, 4, 6, 7, 7, 1, 0, 5, 4, 6, 2, 3, 0, 1};
      int total_pages = 19, m, n, position, k, l, total_frames = 3;
      int a = 0, b = 0, page_fault = 0;
      for (m = 0; m < total_frames; m++)
      {
            frames[m] = -1;
      }
      for (n = 0; n < total_pages; n++)
      {
            a = 0, b = 0;
            for (m = 0; m < total_frames; m++)
            {
                  if (frames[m] == pages[n])
                  {
                        a = 1;
                        b = 1;
                        break;
                  }
            }
            if (a == 0)
            {
                  for (m = 0; m < total_frames; m++)
                  {
                        if (frames[m] == -1)
                        {
                              frames[m] = pages[n];
                              b = 1;
                              break;
                        }
                  }
            }
            if (b == 0)
            {
                  for (m = 0; m < total_frames; m++)
                  {
                        temp[m] = 0;
                  }
                  for (k = n - 1, l = 1; l <= total_frames - 1; l++, k--)
                  {
                        for (m = 0; m < total_frames; m++)
                        {
                              if (frames[m] == pages[k])
                              {
                                    temp[m] = 1;
                              }
                        }
                  }
                  for (m = 0; m < total_frames; m++)
                  {
                        if (temp[m] == 0)
                              position = m;
                  }
                  frames[position] = pages[n];
                  page_fault++;
            }
            // printf("\n");
            // for (m = 0; m < total_frames; m++)
            // {
            //       printf("%d\t", frames[m]);
            // }
      }
      printf("\nPage Faults-ын тоо:\t%d\n", page_fault);
      return 0;
}