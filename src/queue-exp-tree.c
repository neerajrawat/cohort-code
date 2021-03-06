#include<stdio.h>



struct tree {
	int value;
	char ch;
	int lev;
	struct tree *l;
	struct tree *r;
	int 
};

struct tree *queue[100];
int top=-1;

struct tree *new(int i, char c)
{
	struct tree *temp;
	temp = malloc(sizeof(struct tree));
	temp->value = i;
	temp->ch = c;
	temp->lev=-1;
	temp->l=NULL;
	temp->r=NULL;
	
	return temp;
}

int height(struct tree *N)
{
	if(N == NULL)
		return 0;
	
	return 1 + (height(N->l) > height(N->r) ? height(N->l) : height(N->r)); 
}


int make_queue(int R , int l)
{
	int f=0,r=0,f1=0;	
	R->lev = f;
	queue[r++]=R;
	while(f<r)
	{
		if (queue[f]->l->l != NULL && queue[f]->r->r != NULL)
		{
			queue[r] = queue[f]->l;
			queue[r++]->lev = queue[f]->lev + 1;
			
			queue[r] = queue[f]->r;
			queue[r++]->lev = queue[f]->lev + 1;
			
		}
		f=f+1;
	}
	return r;
}


void distri(int l,int qs)
{
	int top;
	int res;
	top = qs;
	int a,b;
	char op;
	while(top >= 0)
	{
		do {
			a = queue[top]->l->value;
			b = queue[top]->r->value;
			op = queue[top]->ch;
			//TODO //send to respective client
			/*
			res = client (a,b,op);
			threads has to be created

			queue->value=res;
			*/
			top=top-1;
		}while(queue[top]->lev==l);

		l=l-1;		
	

			
	}	
	// print res... code end	
}

void main()
{
	struct tree *root;
	int level;
	int queue_size;
	root = new(-1,'-');
	root->l=new(-1,'+');
	root->l->l=new(3,' ');
	root->l->r=new(4,' ');
	root->r=new(-1,'*');
	root->r->l=new(5,' ');
	root->r->r=new(6,' ');

	level = height(root) - 1;

	queue_size = make_queue(root,level)-1;
	
	distri(level,queue_size);
	
}
