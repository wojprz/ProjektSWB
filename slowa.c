#include <stdbool.h>
bool palindrom(char slowo[])
{
	int flag = 0;
	int length = strlen(slowo);

	int l = 0;
    int h = length - 1;

    while(h > l)
    {
        if(slowo[l++] != slowo[h--])
        {
            flag = 1;
            break;
        }
    }

   	if(flag == 1) return false;
	   else return true; 
}
int wystapienia(char slowo[], char znak)
{
	int count = 0;
    int length = strlen(slowo);

	for(int i=0;i<length;i++)
	{
		if(slowo[i] == znak)
			count++;
	}
	return count;
}

