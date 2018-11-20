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
void giaiphong(list&l)
{
	while(l.dau)
	{
		node*g=l.dau;
		l.dau=l.dau->tip;
		delete g;
	}
}
int demdodailist(list &l)
{
	int d=0;
	for(node*k=l.dau;k!=NULL;k=k->tip)
	{
		d++;
	}
	return d;
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
void timcapso(list&l,int a[],int &n)
{
	int s=0,gt,i=0,j=0;
	cout<<"\nnhap gia tri tong can im cap so la ";cin>>gt;
	a[n]=0;
	for(node*k=l.dau;k!=NULL;k=k->tip)
	{
		if(kiemtratrung(a,n,k->data,i)==0)
		{
			for( node*m=k->tip;m!=NULL;m=m->tip)
			{
				s=k->data+m->data;
				if(kiemtratrung(a,n,m->data,j)==0)
				{
					if(s==gt)
					{
						if(k->data > m->data)
						{
							cout<<"\ncap gia tri tong la "<<gt<<" la "<<k->data<<m->data;
							a[n++]=m->data;
						}
						else {
							cout<<"\ncap gia tri tong la "<<gt<<" la "<<m->data<<k->data;
							a[n++]=m->data;
						}
					}
					
				}
				s=0;
				j++;
			}
		}
		i++;
		j=0;
		a[n++]=k->data;
	}
}
int main()
{
	list l;
	khoitaolist(l);
	nhap(l);
	xuat(l);
	int dodai=demdodailist(l),n=0,*a;
	a=new int[dodai];
	timcapso(l,a,n);
	cout<<endl;
	delete[] a;
	giaiphong(l);
	xuat(l);
	return 0;
}