#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void doprocessing (int sock) {
   int answer[8];
   int count1,count2,countA,countB;

   char *message;
   char reply[8],transform[8],message2[50];
   
   if (n < 0) {
      perror("ERROR reading from socket");
      exit(1);
   }
   countA=0; countB=0;
   for(count1=0;count1<4;count1++)
	{
		answer[count1]=rand()%10;
		for(count2=0;count2<count1;count2++)
		{
			if(answer[count1]==answer[count2])
			{
			count1--;
			}
		}
	}
	printf("Answer:%d%d%d%d\n",answer[0],answer[1],answer[2],answer[3]);
	
	while(1)
	{
		bzero(reply,8);
		read(sock,reply,8);
		transform[0]=(reply[0]-'0');
		transform[1]=(reply[1]-'0');
		transform[2]=(reply[2]-'0');
		transform[3]=(reply[3]-'0');
		for(count1=0;count1<4;count1++)
		{
			if(answer[count1]==transform[count1])
			{
				countA+=1;
			}
		}
		for(count2=0;count2<=3;count2++)
		{
			for(count1=0;count1<=3;count1++)
			{
				if(transform[count1]==answer[count2] && count1!=count2)
				{
					countB++;
				}
			}
		}
		if(countA==4)
		{
			message="Game Over";
			write(sock , message, strlen(message)+1);
			return 1;
		}
		else
		{
			sprintf(message2,"%dA%dB",countA,countB);
			write(sock , message2, strlen(message2)+1);
			countA=0;
			countB=0;
		}
	}

   if (n < 0) {
      perror("ERROR writing to socket");
      exit(1);
   }
	
}

