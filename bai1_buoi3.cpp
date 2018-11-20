#include<iostream>
using namespace std;
struct node{
	int data;
	node*trai,*phai;
};
typedef struct node* tree;
node*khoitaonode(int x)
{
	node*p=new node;
	if(p==NULL)return NULL;
	p->data=x;
	p->trai=NULL;
	p->phai=NULL;
	return p;
}
void khoitaocay(tree &t)
{
	t=NULL;
}
void themnodevaocay(tree &t,node*p)
{
	if(t==NULL){
		t=p;	
	}
	else if(t->data<p->data)
	{
		themnodevaocay(t->phai,p);
		
	}
	else if(t->data > p->data)
	{
		themnodevaocay(t->trai,p);
	}
}
void duyetLNR(tree &t)
{
	if(t!=NULL)
	{
		duyetLNR(t->trai);
		cout<<t->data<<" ";
		duyetLNR(t->phai);
	}
}
void nhap(tree &t)
{
	int n,x;cout<<"\nnhap so phan tu ";cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		node*p=khoitaonode(x);
		themnodevaocay(t,p);
	}
}
void giaiphong(tree &t)
{
	if(t)
	{
		
		giaiphong(t->trai);
		giaiphong(t->phai);
		delete t;
	}
}
void timphantuthemang(tree &t,tree &p)
{
	if(t->trai!=NULL)
		timphantuthemang(t->trai,p);
	else{
		p->data=t->data;
		p=t;
		t=t->phai;
	}
}
void xoanode(tree &t,int x)
{
	node*p=t;
	if(t==NULL)return;
	if(t->data >x)xoanode(t->trai,x);
	if(t->data <x)xoanode(t->phai,x);
	if(t->data==x)
	{
		if(t->trai==NULL)
		{
			t=t->phai;
		}
		else if(t->phai==NULL)
		{
			t=t->trai;
		}
		else {
			timphantuthemang(t->phai,p);
		}
		delete p;
	}
	
}
int main()
{
	tree t;
	khoitaocay(t);
	nhap(t);
	xoanode(t,6);
	duyetLNR(t);
	giaiphong(t);
	return 0;
}