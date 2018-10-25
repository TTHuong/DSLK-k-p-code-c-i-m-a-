#include<iostream>
using namespace std;
struct node{
	int data;
	node*tip;
};
struct stack{
	node*dau;
};
struct queue{
	node*dau,*cuoi;
};
void khoitaostack(stack &s){
	s.dau=NULL;
}
void khoitaoqueue(queue&q){
	q.dau=q.cuoi=NULL;
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
void themcuoi(queue&q,node*p){
	if(q.dau==NULL){
		q.dau=q.cuoi=p;
	}else{
		q.cuoi->tip=p;
		q.cuoi=p;
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
int tim_so_min_stack(stack &s,int &i){
	int min=s.dau->data,kt=1;
	for(node*k=s.dau;k!=NULL;k=k->tip){
		if(min>=k->data){
			min=k->data;
			i=kt;
		}
		kt++;
	}
	return min;
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
void chuyenstack_sangqueue(stack &s,queue&q){
	int min,i=0;
	while(s.dau!=NULL){
		min=tim_so_min_stack(s,i);
		node*p=khoitaonode(min);
		themcuoi(q,p);
		xoanodestack(s,i);	
	}
}
void xuatqueue(queue q){
	cout<<endl;
	for(node*k=q.dau;k!=NULL;k=k->tip){
		cout<<k->data<<" ";
	}
}
void chuyenqueue_sangqueue(queue&q1,queue&q2){
	for(node*k=q1.dau;k!=NULL;k=k->tip){
		node*p=khoitaonode(k->data);
		themcuoi(q2,p);
	}
}
int tim_so_max_queue(queue&q,int &vt){
	int max=q.dau->data,kt=1;
	for(node*k=q.dau;k!=NULL;k=k->tip){
		if(max<=k->data){
			max=k->data;
			vt=kt;
		}
		kt++;
	}
	return max;
}
void xoanodequeue(queue&q,int vt){
	int i=1;
	if(q.dau==NULL)return;
	else{
		node*g=new node;
		if(vt==i){
			g=q.dau;
			q.dau=q.dau->tip;
			delete g;
			return;
		}
		for(node*k=q.dau;k!=NULL;k=k->tip){
			if(vt==i){
				g->tip=k->tip;
				k->tip=NULL;
				delete k;
				return;
			}
			i++;
			g=k;
		}
	}
}
void chuyenqueue_sangstack(queue&q,stack&s){
	int max,i=0;
	if(q.dau==NULL)return;
	while(q.dau!=NULL){
		max=tim_so_max_queue(q,i);
		node*p=khoitaonode(max);
		themdau(s,p);
		xoanodequeue(q,i);
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
void giaiphongqueue(queue&s){
	if(s.dau==NULL)return;
	while(s.dau!=NULL){
		node*g=s.dau;
		s.dau=s.dau->tip;
		delete g;
	}
}
void menu(stack&s,queue&q,queue&l){
	nhapstack(s);
	cout<<"\nday so cua stack ban dau la ";
	xuatstack(s);
	chuyenstack_sangqueue(s,q);
	cout<<"\nday so cua queue so 1 la ";
	xuatqueue(q);
	chuyenqueue_sangqueue(q,l);
	cout<<"\nday so cua queue so 2 la ";
	xuatqueue(l);
	chuyenqueue_sangstack(l,s);
	cout<<"\nday so cua stack sau khi chuyen la ";
	xuatstack(s);
	
}
int main(){
	stack s;queue q,l;
	khoitaostack(s);khoitaoqueue(q);khoitaoqueue(l);
	menu(s,q,l);
	giaiphongqueue(q);
	giaiphongqueue(l);
	giaiphongstack(s);
	xuatqueue(q);
	xuatstack(s);
	xuatqueue(l);
	return 0;
}