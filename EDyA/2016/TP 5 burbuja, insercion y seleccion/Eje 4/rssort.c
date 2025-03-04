void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
// Una forma es esta:
// void rssort(int arr[], int sz){
//    if(!sz) return;
//    int max = sz - 1;
//    for (int i = 0; i < sz - 1; i++) {
//       if(arr[i] > arr[max])
//          max = i;
//    }
//    swap(&arr[max],&arr[sz - 1]);
//    rssort(arr,sz-1);
// }

// Otra fora es esta
// void findMax(int arr[], int sz, int *max)
// {
// 	if (sz > -1)
// 	{
// 		if (arr[sz] < arr[*max])
// 			*max = sz;
// 		findMax(arr, sz - 1, max);
// 	}
// }

// void rssort(int arr[], int sz)
// {
// 	if (!sz)
// 		return;
// 	int max = sz - 1;
// 	findMax(arr,sz-1,&max);
// 	swap(&arr[max], &arr[sz - 1]);
// 	rssort(arr, sz - 1);
// }

static void findMin(int arr[], int sz, int idx, int *min)
{
	if (idx < sz)
	{
		if (arr[idx] < arr[*min])
			*min = idx;
		findMin(arr, sz, idx + 1, min);
	}
}

void rssort(int arr[], int sz, int init)
{
	if (init < sz)
	{
		int min = init;
		findMin(arr, sz, init + 1, &min);
		swap(&arr[init], &arr[min]);
		rssort(arr, sz, init + 1);
	}
}
