

// problem code

void mymemcpy(void *dst, const void *src, size_t num)
{
	assert( (dst != NULL) && (src != NULL));

	const char* psrc = (const char*)src;
	char *pdst = (char*)dst;
	while(num-- > 0)
	{
		*pdst++ = *psrc++;
	}
}



//correct code
// considering the situation of overlapping in memory
void mymemcpy(void *dst, const void *src, size_t num)
{
	assert( (dst != NULL) && (src != NULL));

	const char* psrc = (const char*)src;
	char *pdst = (char*)dst;


	if(pdst > psrc && pdst < psrc + num)
	{
		for(size_t i = num - 1; i != -1; --i)
		{
			pdst[i] = psrc[i];
		}
	}
	else
	{
		for (size_t i = 0; i < num; ++i)
		{
			pdst[i] = psrc[i];
		}
	}

	while(num-- > 0)
	{
		*pdst++ = *psrc++;
	}
}

// optimize this code 

//可以每次复制int也就是4个字节，而不是char，1个字节