//this is the snake game.the snake shifted by the a,s,z,w keys and press x to exit.
//for left shift press a( <-- )
//for right shift press s( --> )
//for upper shift press w( ^ )
//for lower shift press z( \/ )

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int height=20, width=20,score=0;
int x,y,fruitx,fruity,gameover,flag,count;
int tailx[100],taily[100];

void border()
{
	int i,j,k;
	system("cls");
	for( i=0 ; i<height ; i++ )
	{
		for( j=0 ; j<width ; j++)
		{
			if( i==0 || i==height-1 || j==0 || j==width-1 )
			{
				printf("#");
				printf(" ");
			}
			else
			{
				if( i==x && j==y)
				printf("@ ");
				else if( i==fruitx && j==fruity )
				printf("F ");
				else
				{
					int g=0;
					for( k=0 ; k<count ; k++)
					{
						if( i==tailx[k] && j==taily[k] )
						{
							printf("o ");
							g++;
						}
					}
					if(g==0)
					printf("  ");
				}
			}
			
		}
		printf("\n");
	}
}

void setup()
{
	gameover=0;
	x=height/2;
	y=width/2;
	  
	lable_1 : 
	fruitx=rand()%20;
	if( fruitx==0 )
	goto lable_1;
	
	lable_2 : 
	fruity=rand()%20;
	if( fruity==0 )
	goto lable_2;
}

void input()
{
	if(kbhit())
	{
		switch(getch())
		{
			case 'a' :
				flag=1;
				break;
			case 's' :
				flag=2;
				break;
			case 'w' :
				flag=3;
				break;
			case 'z' :
				flag=4;
				break;
			case 'x' :
				gameover=1;
				break; 
		}
	}
}

void logic()
{
	int l;
	int prevx=tailx[0];
	int prevy=taily[0];
	int prev2x,prev2y;
	tailx[0]=x;
	taily[0]=y;
	for( l=1 ; l<count ; l++)
	{
		prev2x=tailx[l];
		prev2y=taily[l];
		tailx[l]=prevx;
		taily[l]=prevy;
		prevx=prev2x;
		prevy=prev2y;
			
	}
	switch(flag)	
	{
		case 1 : 
			y--;
			break;
		case 2 : 
			y++;
			break;
		case 3 : 
			x--;
			break;
		case 4 : 
			x++;
			break;
		default : 
			break;
	}
	if( x<0 || x>height || y<0 || y>width )
	{
		gameover=1;
		printf("\ngameover!!");
		printf("\nYou grab the %d fruit.",count);
		printf("\nYour score is %d.",score);
		printf("\n");
		printf("\nCreated and Designed by saikat.");
	}
	for( l=0 ; l<count ; l++)
	{
		if( x==tailx[l] && y==taily[l] )
		{
			gameover=1;
			printf("\ngameover!!");
			printf("\nYou grab the %d fruit.",count);
			printf("\nYour score is %d.",score);
			printf("\n");
			printf("\nCreated and Designed by saikat.\n");
		}
	}
	if( x==fruitx && y==fruity )
	{
		lable_3 : 
			fruitx=rand()%20;
			if( fruitx==0 )
			goto lable_3;
	
		lable_4 : 
			fruity=rand()%20;
			if( fruity==0 )
			goto lable_4;
	
		score=score+10;
		count++;
	}
}

int main()
{
	int m,n;
	char c,ans='y';
	do{
	
		setup();
		while(!gameover)
		{
			border();
			input();
			logic();
			for( m=0 ; m<1000 ; m++ )
			{
				for( n=0 ; n<10000 ; n++ )
				{	
				}
			}
		}printf("\npress y for continue : ");
		ans = getch();
	}while(ans=='y');
		
	printf("\nHope you enjoy the game.\nThank you for playing.");
	return 0;

}
