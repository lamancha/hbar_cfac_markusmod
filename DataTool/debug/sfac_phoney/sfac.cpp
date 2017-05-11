/**Simple program that reads from stdin and writes to a file.
   Used to mimic sfac to read the data which the sfac process will actually receive.
   compile with: g++ sfac.cpp -o sfac -O3 -Wall
   then place it in the PATH, and before the real sfac program. 
 */


#include <stdio.h>
int main()
{
  char buff[10000];

  FILE *fout = fopen ("debug.sf", "w");
  setbuf(fout, NULL);

  if (fout != NULL) 
    {
      while (gets(buff)) 
	{
	  fprintf(fout,"%s\n", buff);
	}
      fclose (fout);
    }
  return 0;
}
