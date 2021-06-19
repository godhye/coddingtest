//거스름돈 ntotal은 10의배수 
#include <stdio.h>

int main()
{

	int nresult = 0;
	int ntotal = 0;
	int remainarray[4] = { 500 , 100 ,50 ,10 };

	scanf("%d", &ntotal);

	for (int i = 0; i < sizeof(remainarray)/sizeof(remainarray[0]) ; i++)
	{
		int divibe = ntotal / remainarray[i];
		printf("ntotal %d remainarray %d divibe %d nresult %d\n", ntotal, remainarray[i], divibe, nresult);
		nresult = nresult + divibe;
		ntotal = ntotal - remainarray[i] * divibe;
	 
		if (!ntotal)
			break;

	}

	printf("result %d ", nresult);
	return 0;
}
