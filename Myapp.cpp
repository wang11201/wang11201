#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
char getSignal()//运算符 
{
    char signal[4]={'+','-','x','/'};
    return signal[rand()%4];
}
int random(int a)//随机数 
{
	int b;
    b=rand()%a+1;
	return b;
}
int gcd(int x,int y)//辗转相除法 
{
    if(y==0) return x;
    return gcd(y,x%y);
}
int answers(int y,int num,int num1,int num2,int num3,char signal1,char signal2,int r)//生成答案 
{
	int ans,a,t,c=0;
	FILE *fp;
	FILE *fb;
	fp=fopen("Answers.txt","a");
	fb=fopen("Exercises.txt","a");
	if(num==1)
	{
		int ans1,ans2;
		switch(signal1)
		{
			case '+':
				ans=num1+num2;
			    fprintf(fp,"答案%d:%d\n",y,ans);
			    fclose(fp);
			    fprintf(fb,"题目%d:%d + %d = \n",y,num1,num2);
			    fclose(fb);
				break;
			case '-':
				if(num1<num2)
				{
					t=num1;
					num1=num2;
					num2=t;
				}
				ans=num1-num2;
				 fprintf(fp,"答案%d:%d\n",y,ans);
			     fclose(fp);
			     fprintf(fb,"题目%d:%d - %d = \n",y,num1,num2);
			     fclose(fb);
				break;
			case 'x':
				ans=num1*num2;
			    fprintf(fp,"答案%d:%d\n",y,ans);
			    fclose(fp);
			    fprintf(fb,"题目%d:%d x %d = \n",y,num1,num2);
			    fclose(fb);
				break;
			case '/':
				a=gcd(num1,num2);
				ans1=num1/a;
				ans2=num2/a;
				c=0;
				while(ans1>ans2)
				{
					ans1=ans1-ans2;
					c++;
				}
				if(c>0)
				{
				fprintf(fp,"答案%d:%d'%d/%d\n",y,c,ans1,ans2);
				fprintf(fb,"题目%d:%d / %d = \n",y,num1,num2);
				}
				
				if(c==0)
				{
				fprintf(fp,"答案%d: %d/%d\n",y,ans1,ans2);
				fprintf(fb,"题目%d:%d / %d = \n",y,num1,num2);
				}
			     fclose(fb);
			     fclose(fp);
				 break;
		}
	}
	if(num==2)
	{
		if(signal2=='x'&&signal1!='/')
		{
			int ans1;
			ans1=num2*num3;
			switch(signal1)
		    {
		    	case '+':
		    		ans=num1+ans1;
		    	    fprintf(fp,"答案%d:%d\n",y,ans);
		    	    fclose(fp);
					fprintf(fb,"题目%d:%d + %d x %d = \n",y,num1,num2,num3);
					fclose(fb);
					break;
		    	case '-':
		    		do{
		    		num1=random(r);
                    num2=random(r);
                    num3=random(r);
					}while(num1-num2*num3<0);
					ans=num1-num2*num3;
					fprintf(fp,"答案%d:%d\n",y,ans);
		    	    fclose(fp);
		    	    fprintf(fb,"题目%d:%d - %d x %d = \n",y,num1,num2,num3);
		    	    fclose(fb);
		    		break;
		    	case 'x':
		    		ans=num1*ans1;
		    	    fprintf(fp,"答案%d:%d\n",y,ans);
		    	    fclose(fp);
		    	    fprintf(fb,"题目%d:%d x %d x %d = \n",y,num1,num2,num3);
		    	    fclose(fb);
					break;
		    }
		}
		else
		if(signal2=='/'&&signal1!='/')
		{
			int ans1,ans2;
			c=0;
			a=gcd(num2,num3);
			ans1=num2/a;
			ans2=num3/a;
			while(ans1>ans2)
			{
				ans1=ans1-ans2;
				c++;
			}
			switch(signal1)
		    {
		    	case '+':
		    		c=num1+c;
		    	    fprintf(fp,"答案%d:%d'%d/%d\n",y,c,ans1,ans2);
		    	    fprintf(fb,"题目%d:%d + %d / %d = \n",y,num1,num2,num3);
		    	    fclose(fb);
		    	    fclose(fp);
					break;
		    	case '-':
		    		do{
		    		num1=random(r);
                    num2=random(r);
                    num3=random(r);
					}while((num1-num2/num3)<0||num3==0);
		    	    	c=num1-c;
		    	    	fprintf(fp,"答案%d:%d'%d/%d\n",y,c,ans1,ans2);
		    	        fclose(fp);
		    	        fprintf(fb,"题目%d:%d - %d / %d = \n",y,num1,num2,num3);
		    	        fclose(fb);
		    	    break;
		    	case 'x':
		    		int ans1;
		    		c=0;
					ans1=num1*num2;
		    		a=gcd(ans1,num3);
		    		ans1=ans1/a;
		    		ans2=num3/a;
		    		while(ans1>ans2)
		    		{
		    			ans1=ans1-ans2;
		    			c++;
					}
		    	    fprintf(fp,"答案%d:%d'%d/%d\n",y,c,ans1,ans2);
		    	    fclose(fp);
					fprintf(fb,"题目%d:%d x %d / %d = \n",y,num1,num2,num3);
		    	    fclose(fb);
					break;
		    }
		}
	    if(signal1=='/')
	    {
	    	int ans1,ans2;
	    	c=0;
	    	switch(signal2)
	    	{
	    		case '+':
	    			a=gcd(num1,num2);
	    			ans1=num1/a;
	    			ans2=num2/a;
	    			c=0;
	    			while(ans1>ans2)
	    			{
	    				ans1=ans1-ans2;
	    				c++;
					}
					c=c+num3;
					fprintf(fp,"答案%d:%d'%d/%d\n",y,c,ans1,ans2);
					fclose(fp);
					fprintf(fb,"题目%d:%d %c %d %c %d = \n",y,num1,signal1,num2,signal2,num3);
		    	    fclose(fb);
					break;
				case '-':
					a=gcd(num1,num2);
	    			ans1=num1/a;
	    			ans2=num2/a;
	    			c=0;
	    			while(ans1>ans2)
	    			{
	    				ans1=ans1-ans2;
	    				c++;
					}
					do{
						num3=random(r);
					}while(c>=num3);
		              if(c==num3)
					{
						fprintf(fp,"答案%d:%d/%d\n",y,ans1,ans2);
						fclose(fp);
						fprintf(fb,"题目%d:%d %c %d %c %d = \n",y,num1,signal1,num2,signal2,num3);
		    	        fclose(fb);
					}
					else if(c>num3)
					{
						c=c-num3;
						fprintf(fp,"答案%d:%d'%d/%d\n",y,c,ans1,ans2);
						fclose(fp);
						fprintf(fb,"题目%d:%d %c %d %c %d = \n",y,num1,signal1,num2,signal2,num3);
		    	        fclose(fb);
					}break;
				case 'x':
					ans1=num1*num3;
					a=gcd(ans1,num2);
					ans1=ans1/a;
					ans2=num2/a;
					c=0;
					while(ans1>ans2)
	    			{
	    				ans1=ans1-ans2;
	    				c++;
					}
					fprintf(fp,"答案%d:%d'%d/%d\n",y,c,ans1,ans2);
					fclose(fp);
					fprintf(fb,"题目%d:%d %c %d %c %d = \n",y,num1,signal1,num2,signal2,num3);
		    	    fclose(fb);
					break;
				case '/':
					ans2=num2*num3;
					a=gcd(num1,ans2);
					ans1=num1/a;
					ans2=ans2/a;
					c=0;
					while(ans1>ans2)
	    			{
	    				ans1=ans1-ans2;
	    				c++;
					}
					fprintf(fp,"答案%d:%d'%d/%d\n",y,c,ans1,ans2);
					fclose(fp);
					fprintf(fb,"题目%d:%d %c %d %c %d = \n",y,num1,signal1,num2,signal2,num3);
		    	    fclose(fb);
					break;
			}
		}
		else
		if(signal1=='+')
	    {
	    	int ans1,ans2;
	    	c=0;
	    	switch(signal2)
    		{
	    		case '+':
	    			ans=num1+num2+num3;
	    		    fprintf(fp,"答案%d:%d\n",y,ans);
	    		    fclose(fp);
	    		    fprintf(fb,"题目%d:%d %c %d %c %d = \n",y,num1,signal1,num2,signal2,num3);
		    	    fclose(fb);
					break;
    			case '-':
    				do
    				{
    					num1=random(r);
    					num2=random(r);
    					num3=random(r);
					}while(num1+num2<num3);
    				ans=num1+num2-num3;
						fprintf(fp,"答案%d:%d\n",y,ans);
	    		        fclose(fp);
	    		        fprintf(fb,"题目%d:%d %c %d %c %d = \n",y,num1,signal1,num2,signal2,num3);
		    	        fclose(fb);
					break;
	    	}
	    }
	    else
	    if(signal1=='-')
	    {
	    	switch(signal2)
    		{
	    		case '+':
	    			if(num1<num2)
	    			{
	    				t=num1;
	    				num1=num2;
	    				num2=t;
					}
	    				ans=num1-num2+num3;
	    		        fprintf(fp,"答案%d:%d\n",y,ans);
	    		        fclose(fp);
	    		        fprintf(fb,"题目%d:%d %c %d %c %d = \n",y,num1,signal1,num2,signal2,num3);
		    	        fclose(fb);
					break;	
    			case '-':
    				do
    				{
    					num1=random(r);
    					num2=random(r);
    					num3=random(r);
					}while(num1<num2+num3);
    					ans=num1-num2-num3;
	    		        fprintf(fp,"答案%d:%d\n",y,ans);
	    		        fclose(fp);
	    		        fprintf(fb,"题目%d:%d - %d - %d = \n",y,num1,num2,num3);
		    	        fclose(fb);
					break;
	    	}
		}
		else
		if(signal1=='x')
		{
			switch(signal2)
    		{
	    		case '+':
	    			ans=num1*num2+num3;
	    		    fprintf(fp,"答案%d:%d\n",y,ans);
	    		    fclose(fp);
	    		    fprintf(fb,"题目%d:%d x %d + %d = \n",y,num1,num2,num3);
		    	    fclose(fb);
					break;
    			case '-':
    				do
    				{
    					num1=random(r);
    					num2=random(r);
    					num3=random(r);
					}while(num1*num2<num3);
    					ans=num1*num2-num3;
	    		        fprintf(fp,"答案%d:%d\n",y,ans);
	    		        fclose(fp);
	    		        fprintf(fb,"题目%d:%d x %d - %d = \n",y,num1,num2,num3);
		    	        fclose(fb);
					break;
	    	}
		}
	}
	return 0;
}
int main()
{
	srand((unsigned)time(0));
	FILE *fp;
	fp=fopen("Exercises.txt","w");
	fp=fopen("Answers.txt","w");
	fclose(fp);
	int n,r;
	int y=1;
    //n=10,r=10;
    int num,num1,num2,num3; 
    char signal1,signal2;
    signal1=getSignal();
    signal2=getSignal();
	scanf("%d",&n);;
	scanf("%d",&r);
		while(n>0)
		{
         num1=random(r);
         num2=random(r);
         num3=random(r);
         num=rand()%2+1; 
         answers(y,num,num1,num2,num3,signal1,signal2,r);
	    	y++;
			n--;
		}
	return 0;
}
