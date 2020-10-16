//Sparse matrix using triplet representation representation
//Delete ith row from matrix
//Swap ith row and jth row of Sparse matrix
//Swap ith row and jth column of Sparse matrix
#include <stdio.h>
#include<stdlib.h>

struct element
{
    int row, column, value;
};


typedef struct element ELEMENT;

void insertion(ELEMENT sparseMat[], int x, int r, int c)
{
    int i=1,j;
    sparseMat=(ELEMENT*)realloc(sparseMat,((sparseMat[0].value)+2)*sizeof(ELEMENT));
   while (sparseMat[i].row<r || (sparseMat[i].row==r && sparseMat[i].column<c))
   {
       i++;
   }
   for (j = sparseMat[0].value+1; j > i; j--)
   {
       sparseMat[j]=sparseMat[j-1];
   }
    sparseMat[j].row=r;
    sparseMat[j].column=c;
    sparseMat[j].value=x;
    sparseMat[0].value++;
}

void deletion(ELEMENT sparseMat[], int r,int c)
{
    int i=1;
   while (sparseMat[i].row<r || (sparseMat[i].row==r && sparseMat[i].column<c))
   {
       i++;
   }
   if (sparseMat[i].row==r && sparseMat[i].column==c)
    {
        printf("From position(%d,%d) element %d deleted successfuly.\n",sparseMat[i].row,sparseMat[i].column,sparseMat[i].value);
        while (i<=sparseMat[0].value)
        {
            sparseMat[i]=sparseMat[i+1];
            i++;
        }
        sparseMat[0].value--;
        sparseMat=(ELEMENT*)realloc(sparseMat,(sparseMat[0].value+1)*sizeof(ELEMENT));
        
    }
    else
    {
        printf("Element at location (%d,%d) does not exist.\n",r,c);
    }
    
}

void display(ELEMENT sparseMat[])
{
    int i=1;
    printf("\nElements in the array are: \n");
    printf("Row(%d)\tColumn(%d)\tValue(%d)\n",sparseMat[0].row,sparseMat[0].column,sparseMat[0].value);
    while (i<sparseMat[0].value+1)
    {
        printf("%d      \t%d        \t%d\n",sparseMat[i].row,sparseMat[i].column,sparseMat[i].value);
        i++;
    }
    
}

void deleteRow(ELEMENT sparseMat[], int r)
{
    int i;
    for (i = 1; sparseMat[i].row<=r ; i++)
    {
        if (sparseMat[i].row==r)
        {
            deletion(sparseMat,r,sparseMat[i].column);
            i--;
        }
        
    }
    
}

ELEMENT* swapRowColumn(ELEMENT sparseMat[], int r, int c)
{
   int i,j=0;
   ELEMENT *tempMat;
   tempMat=(ELEMENT*)malloc(sizeof(ELEMENT));
   tempMat[0].row=sparseMat[0].row;
   tempMat[0].column=sparseMat[0].column;
   tempMat[0].value=0;
   int count=sparseMat[0].value;
   for ( i = 1; i <= count; i++)
   {
       if (sparseMat[i].row==r)
       {
           insertion(tempMat,sparseMat[i].value,sparseMat[i].column,c);
       }
       else if (sparseMat[i].column==c)
       {
           insertion(tempMat,sparseMat[i].value,r,sparseMat[i].row);
       }
       else
       {
           insertion(tempMat,sparseMat[i].value,sparseMat[i].row,sparseMat[i].column);
       }
   }
    display(tempMat);
    free(sparseMat);
    return tempMat;
}

ELEMENT* swapRows(ELEMENT sparseMat[],int ri,int rj)
{
    int i=1;
    for ( i = 1; i <= sparseMat[0].value; i++)
    {
        if (sparseMat[i].row==ri)
        {
            sparseMat[i].row=rj;
        }
        else if(sparseMat[i].row==rj)
        {
            sparseMat[i].row=ri;
        }
    }
    ELEMENT *tempMat;
   tempMat=(ELEMENT*)malloc(sizeof(ELEMENT));
   tempMat[0].row=sparseMat[0].row;
   tempMat[0].column=sparseMat[0].column;
   tempMat[0].value=0;
   for ( i = 1; i <= sparseMat[0].value; i++)
    {
        insertion(tempMat,sparseMat[i].value,sparseMat[i].row,sparseMat[i].column);
    }
   free(sparseMat); 
   return tempMat;
}

int main()
{
    printf("Enter number of rows in sparse matrix: ");
    int r,c;
    scanf("%d",&r);
    printf("Enter number of columns in sparse matrix: ");
    scanf("%d",&c);
    int i=0;   
   ELEMENT *sparseMat=(ELEMENT*)malloc(sizeof(ELEMENT));
   sparseMat[0].row=r;
   sparseMat[0].column=c;
   sparseMat[0].value=0;
   while(1)
    {
        printf("\n\n\nSparse matrix menu: \n");
        printf("1.Enter an element\n");
        printf("2.Delete an element\n");
        printf("3.Display\n");
        printf("4.Delete i-th row\n");
        printf("5.Swap i-th row and j-th row\n");
        printf("6.Swap i-th row and j-th column(for square matrices only)\n");
        printf("7.Exit\n");
        int ch,n,ir,ic;
        printf("Enter your choice : ");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            printf("Enter number to be inserted : ");
            scanf("%d",&n);
            printf("Enter row number of position : ");
            scanf("%d",&ir);
            printf("Enter column number of position : ");
            scanf("%d",&ic);
            if (ir>=r || ic>=c)
            {
                printf("Invalid row or column number.");
                continue;
            }            
            insertion(sparseMat,n,ir,ic);
            break;
        case 2:
            printf("Enter the row number of element to be deleted : ");
            scanf("%d",&ir);
            printf("Enter the column number of element to be deleted : ");
            scanf("%d",&ic);
            if (ir>=r || ic>=c)
            {
                printf("Invalid row or column number.");
                continue;
            }    
            deletion(sparseMat,ir,ic);
            break;

        case 3: 
            display(sparseMat);
            break;

        case 4: 
            printf("Enter the row number of element to be deleted : ");
            scanf("%d",&ir);
            deleteRow(sparseMat,ir);
            if (ir>=r )
            {
                printf("Invalid row number.");
                continue;
            }   
            break;

        case 5:
            printf("Enter the row number for swapping : ");
            scanf("%d",&ir);
            printf("Enter the second row number for swappping : ");
            scanf("%d",&ic);
            if (ir>=r || ic>=r)
            {
                printf("Invalid row number.");
                continue;
            }    
            sparseMat=swapRows(sparseMat,ir,ic);
            break;

         case 6:
            printf("Enter the row number for swapping : ");
            scanf("%d",&ir);
            printf("Enter the column number for swappping : ");
            scanf("%d",&ic);
            if (ir>=r || ic>=c)
            {
                printf("Invalid row or column number.");
                continue;
            }    
            else if (r!=c)
            {
                printf("This is only possible for a square matrix.\n");
                continue;
            }
            sparseMat= swapRowColumn(sparseMat,ir,ic);
            break;

        case 7:
            exit(0);
        
        default:
            printf("Invalid choice.\n");
            break;
        }
    }
    
    return 0;
}
