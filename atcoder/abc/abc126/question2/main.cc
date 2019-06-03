#include <stdio.h>

char str[5];
char MM[12][3] = {"01", "02", "03", "04", "05", "06",
                  "07", "08", "09", "10", "11", "12"};

int main(void)
{
  scanf("%s", str);
  bool MMYY = false;
  bool YYMM = false;
  // MMYY
  for (int i = 0; i < 12; ++i) {
    if (str[0] == MM[i][0] && str[1] == MM[i][1]) MMYY = true;
  }
  // YYMM
  for (int i = 0; i < 12; ++i) {
    if (str[2] == MM[i][0] && str[3] == MM[i][1]) YYMM = true;
  }
  if (MMYY && YYMM)
    printf("AMBIGUOUS\n");
  else if (MMYY && !YYMM)
    printf("MMYY\n");
  else if (!MMYY && YYMM)
    printf("YYMM\n");
  else
    printf("NA\n");
  return 0;
}
