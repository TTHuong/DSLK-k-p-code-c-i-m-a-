#include<iostream>
using namespace std;
struct sv{
	string ten;int tuoi;
};
struct node{
	sv data;
	node*trai,*phai;
};
typedef struct node* cay;
void khoitaocay(cay &x){
	x=NULL;
}
void chuyendoihoathuong(string &x){
	for(int i=0;i<x.size();i++)
	{
		if(x[i]>='A'&&x[i]<='Z'){
			x[i]+=32;
		}
	}
}
void themnodevaocay(cay &c,sv x){
	
	chuyendoihoathuong(x.ten);
	if(c==NULL){
		node*p=new node;
		p->data=x;
		p->trai=NULL;
		p->phai=NULL;
		c=p;
	}
	else{
		chuyendoihoathuong(c->data.ten);
		if(c->data.ten.compare(x.ten)<0){
			themnodevaocay(c->phai,x);
		}
		if(c->data.ten.compare(x.ten)>0){
			themnodevaocay(c->trai,x);
		}
	}
}
void nhapthongtin1sv(sv &x){
	fflush(stdin);
	cout<<"\nnhap ten sv ";getline(cin,x.ten);
	cout<<"\nnhap tuoi sv ";cin>>x.tuoi;
}
void xuatthongtin1sv(sv x){
	cout<<"\nten : "<<x.ten<<" "<<x.tuoi;
}
void nhap(cay &c,int &n){
	sv x;int m;
	cout<<"\nnhap so luong sv ";cin>>m;
	for(int i=0;i<m;i++){
		nhapthongtin1sv(x);
		
		themnodevaocay(c,x);
	}
	n+=m;
}
void xuat(cay c){
	if(c==NULL)return;
	if(c!=NULL){
		xuat(c->trai);
		xuatthongtin1sv(c->data);
		xuat(c->phai);
	}
}
void timkiemsv(cay c,string &ten){
	if(c==NULL)return ;
	else{
		
		chuyendoihoathuong(ten);
		
		if(ten.compare(c->data	.ten	)==0){
			cout<<c->data.ten<<" "<<c->data.tuoi;
		}
		
		else if(c->data.ten.compare(ten)<0)
			{timkiemsv(c->phai,ten);}
		else if(c->data.ten.compare(ten)>0)
			{timkiemsv(c->trai,ten);}
		
	}
	

}
void capnhaptuoi(cay &c,string &ten,int tuoi){
	if(c==NULL)return;
	else{
	
		chuyendoihoathuong(ten);
		if(c->data.ten.compare(ten)==0){
			c->data.tuoi=tuoi;
		}
		else if(c->data.ten.compare(ten)>0)
			capnhaptuoi(c->trai,ten,tuoi);
		else if(c->data.ten.compare(ten)<0)
			capnhaptuoi(c->phai,ten,tuoi);
	}
}
void timnodethemang(cay &c,cay &y){
	if(y->trai!=NULL){
		timnodethemang(c,y->trai);
	}else{
		c->data=y->data;
		c=y;
		y=y->phai;
	}
}
void xoanode(cay &c,string x){
	if(c!=NULL){
		if(c->data.ten.compare(x)>0){
			xoanode(c->trai,x);
		}
		else if(c->data.ten.compare(x)<0){
			xoanode(c->phai,x);
		}
		else{
			node*x=c;
			if(c->trai==NULL){
				c=c->phai;
			}
			else if(c->phai==NULL){
				c=c->trai;
			}
			else{
				timnodethemang(x,c->phai);
				
			}
			delete x;	
			
		}
	}
}
void giaiphong(cay &c){
	if(c==NULL)return;
	if(c){
				
		giaiphong(c->trai);
		giaiphong(c->phai);
		delete c;
	}
}
void luutuoivaomang(sv a[],int &i,cay &c){
	if(c!=NULL){
		luutuoivaomang(a,i,c->trai);
		a[i++]=c->data;
		luutuoivaomang(a,i,c->phai);
	}
}
void sapxep(sv a[],int n){
	for(int k=0;k<n-1;k++){
					for(int j=k+1;j<n;j++){
						if(a[k].tuoi > a[j].tuoi){
							sv tam=a[k];
							a[k]=a[j];
							a[j]=tam;
						}
					}
				}
}
void menu(cay c,cay l){
	int chon,n=0;
		cout<<"\n0.thoat";
		cout<<"\n1.nhap cay ";
		cout<<"\n2.xuat cay theo ten tang dan ";
		cout<<"\n3.tim kiem sinh vien ";
		cout<<"\n4.cap nhat tuoi cua 1 sv ";
		cout<<"\n5.in ra danh sach sv theo tuoi tang dan ";
		cout<<"\n6.xoa 1 sv ";
		cout<<"\n7.xoa man hinh ";
	do
	{
		
		
		cout<<"\nnhap chon ";cin>>chon;
		switch(chon){
			
			
			case 1:{
				cout<<"\nMOI SINH VIEN CO 1 DU LIEU KHAC NHAU HOAN TOAN,DAY LA BAT BUOC !!!!";
				nhap(c,n);break;
				
			}
			case 2:{
				xuat(c);break;
				
			}
			case 3:{
				string x;
				fflush(stdin);
				cout<<"\nnhap ten sv can tim ";getline(cin,x);
				timkiemsv(c,x);
				break;
			}
			case 4:{
				string ten;int tuoi;
				fflush(stdin);
				cout<<"\nnhap ten sv can cap nhat tuoi ";getline(cin,ten);
				cout<<"\nnhap tuoi  can cap nhat ";cin>>tuoi;
				capnhaptuoi(c,ten,tuoi);
				
				break;
			}
			case 5:{
				int i=0;
				sv a[n];
				luutuoivaomang(a,i,c);
				sapxep(a,i);
				for(int t=0;t<i;t++){
					xuatthongtin1sv(a[t]);
					
				}
				break;
			}
			case 6:{
				string x;
				fflush(stdin);
				cout<<"\nnhap ten sv can xoa ";getline(cin,x);
				chuyendoihoathuong(x);
				xoanode(c,x);
				break;
			}
			case 7:{
				system("cls");
				cout<<"\n0.thoat";
				cout<<"\n1.nhap cay ";
				cout<<"\n2.xuat cay theo ten tang dan ";
				cout<<"\n3.tim kiem sinh vien ";
				cout<<"\n4.cap nhat tuoi cua 1 sv ";
				cout<<"\n5.in ra danh sach sv theo tuoi tang dan ";
				cout<<"\n6.xoa 1 sv ";
				cout<<"\n7.xoa man hinh ";
			}
		}
	}while(chon!=0);
}

int main(){
	cay c;cay l;
	khoitaocay(c);khoitaocay(l);
	menu(c,l);
	giaiphong(c);
	giaiphong(l);
	xuat(c);xuat(l);
	return 0;
}
