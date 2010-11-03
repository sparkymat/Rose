#include "video.h"

void cls()
{
	unsigned char x = 0,y = 0;
	for(x=0;x<V_MAXX;x++)
	{
		for(y=0;y<V_MAXY;y++)
		{
			vid_clear(x,y);
		}
	}
}

void put_string(char* string, int x, int y)
{
	int i = x,j = y,idx = 0;
	while(string[idx] != '\0')
	{
		while(i>=V_MAXX)
		{
			j++;
			i-=V_MAXX;
		}
		vid_putch(string[idx],i,j);
		i++; idx++;
	}
}

void kmain(void* mbd, unsigned int magic)
{
	char welcome_msg[20] = "Welcome to ROSE\0";
	mbd = mbd;

	if(magic != 0x2BADB002)
	{
	}

	cls();
	put_string(welcome_msg,10,0);

	// Rest of kernel
}

