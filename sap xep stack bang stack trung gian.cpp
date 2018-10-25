#include<iostream>
using namespace std;
struct node{
	int data;
	node*tip;
};
struct stack{
	node*dau;
};

void khoitaostack(stack &s){
	s.dau=NULL;
}
node*khoitaonode(int x){
	node*p=new node;
	if(p==NULL)return NULL;
	p->data=x;
	p->tip=NULL;
	return p;
}
void themdau(stack&s,node*p){
	if(s.dau==NULL){
		s.dau=p;
	}else{
		p->tip=s.dau;
		s.dau=p;
	}
}

void nhapstack(stack&s){
	int n,x;cout<<"\nnhap so phan tu trong stack ";cin>>n;
	for(int i=0;i<n;i++){
		cin>>x;
		node*p=khoitaonode(x);
		themdau(s,p);
	}
}

void xuatstack(stack s){
	cout<<endl;
	for(node*k=s.dau;k!=NULL;k=k->tip){
		cout<<k->data<<" ";
	}
}
int tim_so_max_stack(stack &s,int &i){
	int max=s.dau->data,kt=1;
	for(node*k=s.dau;k!=NULL;k=k->tip){
		if(max<=k->data){
			max=k->data;
			i=kt;
		}
		kt++;
	}
	return max;
}
void xoadaustack(stack&s){
	if(s.dau==NULL)return;
	else{
		node*g=s.dau;
		s.dau=s.dau->tip;
		delete g;
		return;
	}
}
void xoanodestack(stack&s,int vt){
	int kt=1;
	if(s.dau==NULL)return;
	else{
		if(vt==kt){
			xoadaustack(s);
			return;
		}
		node*g=new node;
		for(node*k=s.dau;k!=NULL;k=k->tip){
			if(vt==kt){
				g->tip=k->tip;
				k->tip=NULL;
				delete k;
				return;
			}
			kt++;g=k;
		}
		return;
	}
}
void chuyenstack_sangstack(stack &s,stack&l){
	int max,i=0;
	while(s.dau!=NULL){
		max=tim_so_max_stack(s,i);
		node*p=khoitaonode(max);
		themdau(l,p);
		xoanodestack(s,i);	
	}
}

void giaiphongstack(stack&s){
	if(s.dau==NULL)return;
	while(s.dau!=NULL){
		node*g=s.dau;
		s.dau=s.dau->tip;
		delete g;
	}
}

void menu(stack&s,stack&l){
	nhapstack(s);
	cout<<"\nday so cua stack ban dau la ";
	xuatstack(s);
	chuyenstack_sangstack(s,l);
	cout<<"\nday so cua stack trung gian la ";
	xuatstack(l);
	chuyenstack_sangstack(l,s);
	cout<<"\nday so cua stack ban dau sau khi chuyen la ";
	xuatstack(s);
	
}
int main(){
	stack s,l;
	khoitaostack(s);khoitaostack(l);
	menu(s,l);
	giaiphongstack(l);
	giaiphongstack(s);
	xuatstack(l);
	xuatstack(s);
	return 0;
}