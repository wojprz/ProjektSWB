#include <stdbool.h>
bool palindrom(char slowo[])
{
	int flag = 0;
	int length = sizeof(slowo);
    int templength = length;
    for(int j=0;j<length;j++)
    {
        if(slowo[j]==slowo[sizeof(slowo)-1])
            templength--;
    }
	for(int i=0;i < templength ;i++)
	{
        if(slowo[i] != slowo[templength-i-1])
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
    int length = sizeof(slowo);
    int templength = length;
    for(int j=0;j<length;j++)
    {
        if(slowo[j]==slowo[sizeof(slowo)-1])
            templength--;
    }
	for(int i=0;i<templength;i++)
	{
		if(slowo[i] == znak)
			count++;
	}
	return count;
}

