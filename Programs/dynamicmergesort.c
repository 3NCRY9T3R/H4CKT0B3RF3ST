#include <stdio.h>
#include <stdlib.h>

void merging(int arr[], int l, int m, int r)
{
	int s1=m-l+1;
	int s2=r-m;
	int left[s1], right[s2];
	int i=0, j=0, k;
	for (i=0; i<s1; i++)
        left[i]=arr[l+i];
	for (j=0; j<s2; j++)
		right[j]=arr[m+1+j];
	i=0;
	j=0;
	k=l;
	while (i<s1 && j<s2)
    {
        if (left[i]<=right[j])
        {
            arr[k]=left[i];
            i++;
        }
        else
        {
            arr[k]=right[j];
            j++;
        }
        k++;
	}
	while (i<s1) 
    {
		arr[k]=left[i];
		i++;
		k++;
	}
	while (j<s2) 
    {
		arr[k]=right[j];
		j++;
		k++;
	}
}

void mergesort(int arr[], int l, int r)
{
	if (l<r)
    {
		int mid=l+(r-l)/2;
		mergesort(arr, l, mid);
		mergesort(arr, mid + 1, r);
		merging(arr, l, mid, r);
	}
}

void print_array(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n\n");
}

int main()
{
    printf("------------------------------------------------------------------\n");
    printf("Performing Merge Sort on randomly generated numbers in a text file\n");
    printf("------------------------------------------------------------------\n");
    printf("This program randomly generates 300 numbers between 1 and 1000,   \n");
    printf("and writes them to a source file. Then, it will perform mergesort \n");
    printf("taking 50 elements at a time, sorting them and writing them to a  \n");
    printf("destination file, which will have all the elements in sorted order\n");
    printf("-----------------------Press Enter to start-----------------------\n");
    getchar();
    FILE *sf=fopen("source.txt", "w");
    FILE *df=fopen("destination.txt", "w");
    int n=0, i=0;
    for(i=0; i<300; i++)
    {
        //writing 300 random numbers between 1 and 1000 to source.txt
        char st[5];
        int ele=rand()%1000;
        itoa(ele, st, 10);
        fputs(st, sf);
        fputc(' ', sf);
    }
    fclose(sf);
    FILE *sfr = fopen("source.txt", "r");
    int arr[300];
    printf("Start : \n");
    while(n<300)
    {
        int cnt = 0;
        while(cnt < 50)
        {
            char c;
            char ct[5];
            int l = 1;
            c = fgetc(sfr);
            while(c != ' ')
            {
                ct[l-1] = c;
                c = fgetc(sfr);
                l++;
            }
            arr[n+cnt] = atoi(ct);
            cnt++;
        }
        printf("Before Sort Pass %d: \n", n/50+1);
        print_array(arr, n+50);
        mergesort(arr,n,n+49);
        merging(arr,0,n-1,n+49);
        printf("Sorted %d numbers : \n", n+50);
        print_array(arr, n+50);
        n += 50;
        if(n!=300)
            printf("\nPress enter for next 50 elements.\n");
        else
            continue;
        getchar();
    }
    for(int i = 0; i < n; ++i)
    {
        char st[2];
        itoa(arr[i],st,10);
        fputs(st,df);
        fputc(' ',df);
    }
    fclose(sfr);
    fclose(df);
}