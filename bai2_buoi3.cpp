#include<iostream>
using namespace std;
struct node{
	int data;
	node*tip;
};
struct list{
	node*dau,*cuoi;
};
void khoitaolist(list&l)
{
	l.dau=l.cuoi=NULL;
}
node*khoitaonode(int x)
{
	node*p=new node;
	if(p==NULL)return NULL;
	p->data=x;
	p->tip=NULL;
	return p;
}
void themdau(list&l,node*p)
{
	if(l.dau==NULL)
	{
		l.dau=l.cuoi=p;
	}
	else{
		p->tip=l.dau;
		l.dau=p;
	}
}
void themcuoi(list&l,node*p)
{
	if(l.dau==NULL)
	{
		l.dau=l.cuoi=p;
	}
	else{
		
		l.cuoi->tip=p;
		l.cuoi=p;
	}
}
void  nhap(list&l)
{
	int n,x;cout<<"\nnhap so phan tu ";cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		node*p=khoitaonode(x);
		themcuoi(l,p);
	}
}
void xuat(list l)
{
	for(node*k=l.dau;k!=NULL;k=k->tip)
	{
		cout<<k->data<<" ";
	}
}
void chuyen(list &l,int hem)
{
	int tam;
	while(hem!=0)
	{
		tam=hem%2;
		node*p=khoitaonode(tam);
		themdau(l,p);
		hem/=2;
	}	
}
void laydauraxoa(list &l,int &x)
{
	if(l.dau!=NULL)
	{
		node*g=l.dau;
		x=l.dau->data;
		l.dau=l.dau->tip;
		delete  g;
	}
}
void inbangiphan(list &l)
{
	int x,a[8],i=0;
	while(l.dau)
	{
		laydauraxoa(l,x);
		a[i]=x;
		i++;
	}
	while(i<8)
	{
		for(int j=i+1;j>0;j--)
		{
			a[j]=a[j-1];
		}
		a[0]=0;
		i++;
	}
	for(int j=0;j<i;j++)
	{
		cout<<a[j];
	}
	
}
void giaiphong(list&l)
{
	while(l.dau)
	{
		node*g=l.dau;
		l.dau=l.dau->tip;
		delete g;
	}
}
void tinhnp(list &l,list &np)
{
	for(node*k=l.dau;k!=NULL;k=k->tip)
	{
		chuyen(np,k->data);
		inbangiphan(np);
		cout<<endl;
	}
}
int main()
{
	list l,np;
	khoitaolist(l);
	khoitaolist(np);
	nhap(l);
	xuat(l);
	cout<<endl;
	tinhnp(l,np);
	giaiphong(l);
	return 0;
}