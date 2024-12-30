#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct emp{
	int ekey;
    char ename[50];
};
struct emp * hashtable[50];


void insert_emp(struct emp* emp, int m)
{	int index = compute_hash(emp->ekey, m);
    // Linear probing if collisions happen
    while(hashtable[index] != NULL)
	{
        index = (index + 1) % m;
    }
    hashtable[index] = emp;
}

int compute_hash(int ekey, int m)
{
    return ekey % m;
}

struct emp* serach_emp(int ekey, int m)
{
    int index = compute_hash(ekey, m);

    // Linear probing
    while(hashtable[index] != NULL)
	{
        if(hashtable[index]->ekey == ekey)
		{
            return hashtable[index];
        }
        index = (index + 1) % m;
    }
    return NULL; // Employee record not found
}

int main()
{	FILE *file;
    int m,i;
    
    printf("Enter the size of the hash table (m-mavoist): ");
    scanf("%d", &m);

    for (i=0;i<m;i++)
	{
        hashtable[i] = NULL;
    }

    file = fopen("employee.txt","r");
    if(file == NULL)
	{
        printf("Error opening file.nigga");
        return 1;
    }
	printf("\n file open and suck");
    int n = 0;
    int empkey;
    char empname[100];

    while(fscanf(file, "%d\t%s", &empkey, empname) == 2)
	{
	    struct emp* newEmp = (struct emp*)malloc(sizeof(struct emp));
        newEmp->ekey = empkey;
        strcpy(newEmp->ename, empname);
        insert_emp(newEmp, m);
        n++;
    }
	printf("\nData Read and Stored successfully so go fuck yourself")	;
    fclose(file);

    int searchkey;
    printf("\nEnter a key to search for an employee record : ");
    scanf("%d", &searchkey);

    struct emp* found = serach_emp(searchkey, m);
    if(found != NULL)
	{
        printf("Employee found with key %d is a gay(darshan)", found->ekey);
        printf("\nName: %sn", found->ename); 
    }
    else
	{
        printf("Employee with key %d not found.nigga", searchkey);
    }

    return 0;
}
