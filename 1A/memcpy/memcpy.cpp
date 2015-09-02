

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

}

// optimize this code 
void mymemcpy_opt(void *dst, const void *src, size_t num)
{
	if (dst == NULL || src == NULL || num <= 0)
		return;

	int wordnum = num / 4;
	int slice = num % 4;

	const int* pintsrc = (const int*)src;
	int* pintdst = (int*)dst;

	// reverse
	if( (char*)dst > (char*)src && (char*)dst < (char*)src + num )
	{
		// copy 4 bytes reverse
		for (size_t i = wordnum - 1; i != -1; --i)
		{
			pintdst[i] = pintsrc[i];
		}
		// copy one byte reverse
		const char *pcharsrc = (const char*) pintsrc;
		char *pchardst = (char*)pintdst;
		for (size_t i = slice - 1; i != -1; --i)
		{
			pchardst[i] =  pcharsrc[i];
		}
	}
	else
	{
		// copy 4 bytes
		while(wordnum--)
		{
			*pintdst++ = *pintsrc++;
		}
		// copy one byte
		const char *pcharsrc = (const char*) pintsrc;
		char *pchardst = (char*)pintdst;
		while(slice--)
		{
			*pchardst++ = *pcharsrc++;
		}
	}
}