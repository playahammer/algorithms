
/**
* Problem souce: 《C 程序设计（第四版）》郑华强
* Problem description: There are n perons sitting round with ordered sequence. Now, we start to count off from one, and someone who reports the number 3 should quit the circle. So who will be the last one left in the cirle, please output his number. 
* Example: n is 10, output is 4
* The following codes give two kinds of solutions, one is based in chain list, the other is array. For chain list method, it recommends to use cycle chain which is vivid and convenient for experssion and operation. 
**/

#include <stdio.h>
#include <stdlib.h>

struct node
    
{
    int number;
    struct node *next;
};



struct node * init_nodes()

{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;
    int i = 1;
    p->number = i;
    p->next = NULL;
    
    while(i < 10)
    {
        //printf("%d\n", i);
        i++;
        struct node *q = (struct node*)malloc(sizeof(struct node));
        q->number = i;
        q->next = NULL;
        p->next = q;
        p = q;
     }
    
    p->next = head;
    return head;

}

int Josephus(struct node *head)
{
	struct node * p = head, *q = head->next;
	int i = 2;
	while (p != q)
	{
		if (i == 3)
		{

			i = 1;
			p->next = q->next;
                        struct node *tmp = q;
			//printf("%d ", tmp->number);
                        free(q);
                        q = p->next;
                        continue;
		}
		i++;
                p = p->next;
		q = q->next;
	}
        return p->number;
}


int numbers[] = {1,2,3,4,5,6,7,8,9,10};
int Josephus_arr(int *arr)
{
	int work = 0, p = 1, n = 10;
        while(n != 0)
        {
		if (p == 3 && *(arr + work) != -1)
		{
			if (n == 1) return *(arr + work);
			//printf("%d ", *(arr + work));
			*(arr + work) = -1;
			p = 1;
			n--;
            	}
		if (*(arr + work) != -1) p++;
		work = (work + 1) % 10;
		
        } 
 	return -1;
}

int main()    
{
	struct node *head = init_nodes();
    	printf("%d\n", Josephus(head));
	printf("%d\n", Josephus_arr(numbers));
    	return 0;

}
