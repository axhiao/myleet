

### 1. Given a set S and an integer x, decide whether there are two elements in S whose sum equals x. Time limit: theta(n*logn).
   
+ sort S
+ S'={x-si | si in S}.
+ sort S'
+ if the same value appears in both S and S', then yes.



### 2. stability in sort algo

+ stable: bubble, insert, radix, merge, bucket, counting
+ instable: select, quick, heap, shell



### 3. Inversions

```
COUNT-INVERSIONS(A, p, r)

inversions = 0
if p<r
   then q = (p+r)/2
        inversions = inversions + COUNT-INVERSIONS(A, p, q)
	inversions = inversions + COUNT-INVERSIONS(A, q+1, r)
        inversions = inversions + Merge-Inversions(A, p, q, r)
   return inversions
```



```c++
int merge_inversions(int arr[], int p, int q, int r)
{
	int nl = q - p + 1;
	int nr = r - q;
	int *L = new int[nl+1];
	int *R = new int[nr+1];
	// left side of array
	for (int i = 0; i < nl; i++)
	{
		L[i] = arr[p+i];
	}
	L[nl] = (numeric_limits<int>::max)();//sentinel
	// right side of array 
	for (int i = 0; i < nr; i++)
	{
		R[i] = arr[q+1+i];
	}
	R[nr] = (numeric_limits<int>::max)();//sentinel

	int inv_cnt = 0;
	bool counted = false;
	int i = 0;
	int j = 0;
	for (int k = p; k <= r; k++)
	{
		if (!counted && R[j] < L[i])
		{
			//inv_cnt += nl - i + 1;
			inv_cnt += nl - i;

			counted = true;
		}
		if (L[i] <= R[j])
		{
			arr[k] = L[i++];
		}
		else
		{
			arr[k] = R[j++];
			counted = false;
		}
	}
	delete[] L;
	delete[] R;
	return inv_cnt;
}
```


