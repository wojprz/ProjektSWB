#include <stdbool.h>
bool palindrom(char slowo[])
{
	int flag = 0;
	int length = sizeof(slowo);
	for(int i=0;i < length ;i++)
	{
        if(slowo[i] != slowo[length-i-1])
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
	for(int i=0;i<sizeof(slowo);i++)
	{
		if(slowo[i] == znak)
			count++;
	}
	return count;
}

