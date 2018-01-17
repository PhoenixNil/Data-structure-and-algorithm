#include<stdio.h>
int main()
{
    int a[1000000]={0};
    int maxSum=0,seqence=0;
    int i,N,realsum=0,temp_sum=0;
    scanf("%d",&N);
    for(i=0;i<N;i++)
        scanf("%d",&a[i]);       
    for(i=0;i<N;i++)
    {
        temp_sum +=a[i]; 
            if (temp_sum<0)
            {
                temp_sum = 0;
                continue;
            }
            else
            {   
                seqence = (temp_sum>realsum? temp_sum:realsum);
                maxSum = temp_sum + a[i+1];
                if(seqence>maxSum)/*a1和a1+a2比*/
                    realsum = seqence;
                else 
                    realsum = maxSum; 
            }
            
                
    }
    printf(" %d",realsum);
/*     for(i=0;i<N;i++)
        printf(" %d",a[i]); */
    return 0;
}