#include<iostream>
using namespace std;
struct sv{
	string ho,ten,lop;float tb;
	int ma;
};
struct node{
	sv data;
	node*truoc;
	node*sau;
};
struct list{
	node*dau,*cuoi;
};
void khoitaolist(list &l){
	l.dau=l.cuoi=NULL;
}
void nhapthongtinsv(sv &x,int &m){
	fflush(stdin);
	cout<<"\nnhap ma sv ";cin>>x.ma;
	fflush(stdin);
	cout<<"\nnhap ho sv ";getline(cin,x.ho);
	cout<<"\nnhap ten sv ";getline(cin,x.ten);
	cout<<"\nnhap ten lop ";getline(cin,x.lop);
	cout<<"\nnhap diem tb ";cin>>x.tb;
	m=x.ma;
}
void xuatthongtinsv(sv x){
	cout<<x.ma<<" "<<x.ho<<x.ten<<" "<<x.lop<<" "<<x.tb<<endl;
}
void themcuoi(list&l,node*p){
	if(l.dau==NULL){
		l.dau=l.cuoi=p;
	}else{
		l.cuoi->truoc=p;
		p->sau=l.cuoi;
		l.cuoi=p;
	}
}

node*khoitaonode(sv x){
	node*p=new node;
	if(p==NULL)return NULL;
	p->data=x;
	p->truoc=NULL;
	return p;
}
void nhap(list&l){
	sv x;int m;
	int n;cout<<"\nnhap so luong sv ";cin>>n;
	for(int i=0;i<n;i++){
		nhapthongtinsv(x,m);
		if(m>0){
			node*p=khoitaonode(x);
			themcuoi(l,p);
		}else return;
		
	}
}
void xuat(list l){
	for(node*k=l.dau;k!=NULL;k=k->truoc){
		xuatthongtinsv(k->data);
	}
}

void themsv(list&l,int vt,node*p){
	int i=1;
		node*g=new node;
		if(vt==i){
			if(l.dau==NULL){
				l.dau=l.cuoi=p;
			}else{
				p->truoc=l.dau;
					l.dau->sau=p;
				}
				return;
		}
		for(node*k=l.dau;k!=NULL;k=k->truoc){
			if(i==vt){
				p->truoc=k;
				k->sau=p;
				g->truoc=p;
				p->sau=g;
				return;
			}g=k;i++;
		}
}
void inragiamdan(list&l){
	sv x;
	for(node*k=l.dau;k!=l.cuoi;k=k->truoc){
		for(node*m=k->truoc;m!=NULL;m=m->truoc){
			if(k->data.tb<m->data.tb){
				x=k->data;
				k->data=m->data;
				m->data=x;
			}
		}
	}
}
void inragioi(list&l){
	sv x;
	for(node*k=l.dau;k!=l.cuoi;k=k->truoc){
		if(k->data.tb>=8.0){
			xuatthongtinsv(k->data);
		}
	}
}
void inrasvcunglop(list l,string lop){
	for(node*k=l.dau;k!=l.cuoi;k=k->truoc){
		if(k->data.lop.compare(lop)==0){
			xuatthongtinsv(k->data);
		}
	}
}
void inrasv_vitri(list l,int ma){
	int i=0;
	for(node*k=l.dau;k!=l.cuoi;k=k->truoc){
		if(ma==k->data.ma){
			cout<<"\nvi tri cua sv nay la "<<i;
			return;
		}
		i++;
	}
	cout<<"\nsv nay k co trong danh sach ";
}
void inrasv_tb(list l,float diem){
	int i=0;
	for(node*k=l.dau;k!=l.cuoi;k=k->truoc){
		if(diem==k->data.tb	){
			xuatthongtinsv(k->data);
			i++;
		}
	}
	if(i==0)
		cout<<"\nsv nay k co trong danh sach ";
}
void inratangdan(list&l){
	sv x;
	for(node*k=l.dau;k!=l.cuoi;k=k->truoc){
		for(node*m=k->truoc;m!=NULL;m=m->truoc){
			if(k->data.tb>m->data.tb){
				x=k->data;
				k->data=m->data;
				m->data=x;
			}
		}
	}
}
void giaiphong(list&l){
	if(l.dau==NULL)return;
	for(node*k=l.dau;k!=NULL;k=k->truoc){
		node*g=l.dau;
		l.dau=l.dau->truoc;
		delete g;
	}
}
void xoasv(list &l){
	if(l.dau->data.tb<5){
		giaiphong(l);return;
	}
	node*g=new node;
	for(node*k=l.dau;k!=NULL;k=k->truoc){
		if(k->data.tb<5){
			//node*tam=k->truoc;
			//k->truoc=NULL;
			g->truoc=k->truoc;
			//tam->sau=g;
			delete k;
			
		}g=k;
	}
}
void menu(list l){
	int chon;
	cout<<"\n1.nhap ";
	cout<<"\n2.xuat ";
	cout<<"\n3.them sv ";
	cout<<"\n4.xuat danh sach sv giam dan theo diem ";
	cout<<"\n5.sv vien gioi";
	cout<<"\n6.xuat tat ca sv cung lop";
	cout<<"\n7.xuat ra vi tri sv ";
	cout<<"\n8.tim kiem sv theo dtb";
	cout<<"\n9.sap xep sv theo thu tu tang dan";
	cout<<"\n10.xoa toan bo sv co diem <5";
	cout<<"\n11.xoa man hinh nhin cho dep :)))))-";
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
				int vt,m;sv x;
				node*g=new node;
				cout<<"\nnhap vi tri ma ban muon them ";cin>>vt;
				nhapthongtinsv(x,m);
				if(m>0){
					node*p=khoitaonode(x);
					themsv(l,vt,p);
				}
				break;
			}
			case 4:{
				inragiamdan(l);
				xuat(l);
				break;
			}
			case 5:{
				inragioi(l);break;
			}
			case 6:{
				string lop;
				fflush(stdin);
				cout<<"\nnhap vao ten lop can tim ";getline(cin,lop);
				inrasvcunglop(l,lop);break;
			}
			case 7:{
				int ma;
				cout<<"\nnhap ma sv ma ban can tim vi tri ";cin>>ma;
				inrasv_vitri(l,ma);break;
			}
			case 8:{
				float diem;
				cout<<"\nnhap diem trung binh ma ban muon tim ";cin>>diem;
				inrasv_tb(l,diem);break;
			}
			case 9:{
				inratangdan(l);
				xuat(l);
				break;
			}
			case 10:{
				inragiamdan(l);
				xoasv(l);
				xuat(l);
				break;
			}
			case 11:{
				system("cls");
				cout<<"\n1.nhap ";
				cout<<"\n2.xuat ";
				cout<<"\n3.them sv ";
				cout<<"\n4.xuat danh sach sv giam dan theo diem ";
				cout<<"\n5.sv vien gioi";
				cout<<"\n6.xuat tat ca sv cung lop";
				cout<<"\n7.xuat ra vi tri sv ";
				cout<<"\n8.tim kiem sv theo dtb";
				cout<<"\n9.sap xep sv theo thu tu tang dan";
				cout<<"\n10.xoa toan bo sv co diem <5";
				cout<<"\n11.xoa man hinh nhin cho dep :)))))-";
				break;
			}
		}
	}while(chon!=0);
}
int main(){
	list l;
	khoitaolist(l);
	menu(l);
	giaiphong(l);
	xuat(l);
	return 0;
}