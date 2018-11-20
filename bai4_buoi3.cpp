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
void demdodaicay(tree t,int &d)
{
	if(t!=NULL)
	{
		demdodaicay(t->trai,d);
		++d;
		demdodaicay(t->phai,d);
	}
}
int kiemtratrung(int a[],int n,int gt,int vt)
{
	for(int i=0;i<vt;i++)
	{
		if(a[i]==gt)
		{
			return 1;
		}
	}
	return 0;
}
void nhapmang(tree&t,int a[],int &n,int gt)
{
	if(t!=NULL)
	{
		if(t->data <gt)
		{
			a[n++]=t->data;
			nhapmang(t->trai,a,n,gt);
		}
	}

}
void timcapso(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<a[i];
	}
}
int main()
{
	tree t;
	int n=0,*a,gt,dodai;
	khoitaocay(t);
	nhap(t);
	duyetLNR(t);
	demdodaicay(t,dodai);
	cout<<dodai;
	//a=new int[dodai];
//	cout<<"\nnhap gia tri can tim tong ";cin>>gt;
//	nhapmang(t,a,n,gt);
//	timcapso(a,n);
	giaiphong(t);
	return 0;
}