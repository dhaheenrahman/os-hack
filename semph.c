//Semaphore implementation
#include<stdio.h>
#include<stdlib.h>
int mutex=1,full=0,empty=5,x=0;
void producer()
{
    mutex--;
    full++;
    empty--;
    x++;
    printf("\nProducer produces item %d",x);
    mutex++;
}
void consumer()
{
    mutex--;
    full--;
    empty++;
    printf("\nConsumer consumes item %d",x);
    x--;
    mutex++;
}
void main()
{
    int cho,i;
    printf("1:Producer\n2:Consumer\n3:Exit");
    for(i=1;i>0;i++)
    {
        printf("\nEnter your choice:");
        scanf("%d",&cho);
        switch(cho)
        {
            case 1:
                    if(mutex==1 && empty!=0)
                        producer();
                    else
                        printf("Buffer is full so can't produce...!");
                    break;
            case 2:
                    if(mutex==1 && full!=0)
                        consumer();
                    else
                        printf("Buffer is empty so can't consume..!");
                    break;
            case 3:
                    exit(0);
        }
    }
}