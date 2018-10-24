#include<iostream>
using namespace std;
struct cb{
	string ho,ten,pb,cv;int ma;
	float hesoluong;
};
struct node{
	cb data;
	node*tip;
};
struct list{
	node*dau,*cuoi;
};
void khoitaolist(list&l){
	l.dau=l.cuoi=NULL;
}
node*khoitaonode(cb x){
	node*p=new node;
	if(p==NULL)return  NULL;
	p->data=x;
	p->tip=NULL;
	return p;
}
void themcuoi(list&l,node*p){
	if(l.dau==NULL){
		l.dau=l.cuoi=p;
	}else{
		l.cuoi->tip=p;
		l.cuoi=p;
	}
}
void themdau(list&l,node*p){
	if(l.dau==NULL){
		l.dau=l.cuoi=p;
	}else{
		p->tip=l.dau;
		l.dau=p;
	}
}
void nhapthongtincanbo(cb &x,int &macb){
	fflush(stdin);
	cout<<"\nnhap ma cb ";cin>>x.ma;
	fflush(stdin);
	cout<<"\nnhap ho va ten lot ";getline(cin,x.ho);
	cout<<"\nnhap ten can bo ";getline(cin,x.ten);
	cout<<"\nnhap phong ban ";getline(cin,x.pb);
	cout<<"\nnhap chuc vu can bo ";getline(cin,x.cv);
	cout<<"\nnhap he so luong ";cin>>x.hesoluong;
	macb=x.ma;
}
void xuatthongtincanbo(cb x){
	cout<<"\n"<<x.ma<<" "<<x.ho<<" "<<x.ten<<" "<<x.pb<<" "<<x.cv<<" "<<x.hesoluong;
}
void nhap(list&l)
{
	cb x;int macb,n;
	cout<<"\nnhap so can bo ";cin>>n;
	for(int i=0;i<n;i++){
		nhapthongtincanbo(x,macb);
		if(macb>0){
			node*p=khoitaonode(x);
			themcuoi(l,p);
		}else return;
		
	}
}
void xuat(list l){
	for(node*k=l.dau;k!=NULL;k=k->tip){
		xuatthongtincanbo(k->data);
	}
}

void themvitri(list&l,node*p,int vitri){
	int i=0;
	node*g=new node;
	if(vitri==1){
		themdau(l,p);
		return;
	}
	for(node*k=l.dau;k!=NULL;k=k->tip){
		if(i==vitri){
			p->tip=k;
			g->tip=p;
			return;
		}g=k;i++;
	}
}
void luongnhanvienX(list&l,int x){
	long luong,ma;
	for(node*k=l.dau;k!=NULL;k=k->tip){
		if(x==k->data.ma){
			ma=k->data.hesoluong;
			luong=1150000*ma;
			cout<<"\nluong cua can bo nay la "<<luong;
		}
	}
}
void soluongcanbocungphongban(list&l,string phongban,int &dem){
	for(node*k=l.dau;k!=NULL;k=k->tip){
		if(phongban.compare(k->data.pb)==0){
			xuatthongtincanbo(k->data);
			dem++;
		}
	}
}
void inramanhinhluong(list l){
	for(node*k=l.dau;k!=NULL;k=k->tip){
		if(k->data.hesoluong>=4.9){
			xuatthongtincanbo(k->data);
		}
	}
}
void inradscungchuc(list l,string chuc){
	for(node*k=l.dau;k!=NULL;k=k->tip){
		if(chuc.compare(k->data.cv	)==0){
			xuatthongtincanbo(k->data);
		}
	}
}
void inradsluong_pb(list l,string phongb,int heso){
	for(node*k=l.dau;k!=NULL;k=k->tip){
		if((phongb.compare(k->data.pb)==0)&&(heso==k->data.hesoluong)){
			xuatthongtincanbo(k->data);
		}
	}
}
void sapxep(list&l){
	cb x;
	for(node*k=l.dau;k!=NULL;k=k->tip){
		for(node*m=k->tip;m!=NULL;m=m->tip){
			if(k->data.ten.compare(m->data.ten)>0){
				x=k->data;
				k->data=m->data;
				m->data=x;
			}
		}
	}
}
void giaiphhong(list&l){
	if(l.dau==NULL)return;
	else{
		for(node*k=l.dau;k!=NULL;k=k->tip){
			node*g=l.dau;
			l.dau=l.dau->tip;
			delete g;
			
		}
	}	
}

void menu(list l){
	int chon;
	cout<<"\n1.nhap so luong can bo ";
	cout<<"\n2.xuat danh sach ";
	cout<<"\n3.them can bo vao vi tri bat ky ";
	cout<<"\n4.xuat luong nhan vien X";
	cout<<"\n5.so luong can bo cung phong ban";
	cout<<"\n6.in ra man hinh so can bo co he so >=4.9";
	cout<<"\n7.in ra danh sach can bo cung chuc ";
	cout<<"\n8.in ra danh sach can bo cung chuc va cung he so luong ";
	cout<<"\n9.sap xep danh sach theo ten ";
	do{
		cout<<"\nnhap chon ";cin>>chon;
		switch(chon){
			case 1:{
				nhap(l);break;
			}
			case 2:{
				xuat(l);break;
			}
			case 3:{
				cb y;
				int x,rong;
				cout<<"\nnhap vi tri ma ban muon them ";cin>>x;
				nhapthongtincanbo(y,rong);
				if(rong>0){
					node*p=khoitaonode(y);
					themvitri(l,p,x);
				}
				break;
			}
			case 4:{
				int x;
				cout<<"\nnhap ma can bo muon xem luong ";cin>>x;
				luongnhanvienX(l,x);break;
			}
			case 5:{
				int dem=0;string pb;
				fflush(stdin);
				cout<<"\nnhap ten phong ban ma ban muon dem so luong can bo ";getline(cin,pb);
				soluongcanbocungphongban(l,pb,dem);
				cout<<"\nso luong can bo cung phong ban la "<<dem;
				break;
				
			}
			case 6:{
				inramanhinhluong(l);break;
			}
			case 7:{
				string chuc;
				fflush(stdin);
				cout<<"\nnhap chuc vu ma ban muon tim can bo ";getline(cin,chuc);
				inradscungchuc(l,chuc);break;
			}
			case 8:{
				string pb;float heso;
				cout<<"\nnhap he so luong va phong ban ban can tim can bo ";
				cin>>heso;
				fflush(stdin);
				getline(cin,pb);
				inradsluong_pb(l,pb,heso);
				break;
			}
			case 9:{
				sapxep(l);break;
			}
		}
	}while(chon!=0);
}
int main(){
	list l;
	khoitaolist(l);
	menu(l);
	giaiphhong(l);
	xuat(l);
	return 0;
}