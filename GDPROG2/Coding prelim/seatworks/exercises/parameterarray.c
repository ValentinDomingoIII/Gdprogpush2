#include <stdio.h>
#include <stdlib.h>


void findfunction(int **arr)
{
int key,i,j,foundi,foundj;
printf("\n\nFind function:\n");
printf("Enter key:");
scanf("%d",&key);

    for (i = 0; i < 3; i++)
    {
        // Reset j before the inner loop
        for (j = 0; j < 3; j++) 
        {
                if(arr[i][j]==key)
                {
                    foundi=i;
                    foundj=j;
                }
        }
    }

    printf("Your key is arr[%d][%d]: %d",foundi,foundj,arr[foundi][foundj]);
}



void passedfunction2(int **arr)
{
    int i, j;
    printf("\n\nPassedfunction2\n\n");
    for (i = 0; i < 3; i++)
    {
        // Reset j before the inner loop
        for (j = 0; j < 3; j++) 
        {
            arr[i][j] += 1; // Assigning values to all elements
            printf("Element at [%d][%d]: %d\n", i, j, arr[i][j]);
        }
    }
}

void passedfunction1(int **arr) {
    int i, j;
    for (i = 0; i < 3; i++)
    {
        // Reset j before the inner loop
        for (j = 0; j < 3; j++) 
        {
            arr[i][j] = i * 3 + j; // Assigning values to all elements
            printf("Element at [%d][%d]: %d\n", i, j, arr[i][j]);
        }
    }
    passedfunction2(arr);
}

int main() {
    int rows = 3;
    int cols = 3;
    int **arr = malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        arr[i] = malloc(cols * sizeof(int));
    }

    passedfunction1(arr);
    findfunction(arr);

    // Free the allocated memory
    for (int i = 0; i < rows; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}


