#include<iostream>
using namespace std;
void nhap(int a[],int n){
	for(int i=0;i<n;i++){
		cout<<"\nnhap gia tri vao ";cin>>a[i];
	}
}
void xuat(int a[],int n){
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
}
void thempt(int a[],int &n,int vt,int gt){
	for(int i=n;i>vt;i--){
		a[i]=a[i-1];
	}
	a[vt]=gt;
	n++;
}
int ktshh(int x){
	int s=0;
	for(int i=1;i<x;i++){
		if(x%i==0){
			s+=i;
		}
	}
	return s;
}
void demsohh(int a[],int n){
	int dem=0;
	for(int i=0;i<n;i++){
		if(ktshh(a[i])==a[i]){
			dem++;
		}
	}
	if(dem%2==0)cout<<"\nso luong so hoan hao la chan "<<dem;
	else if(dem%2!=0)cout<<"\nso luong so hoan hao la le "<<dem;
	else cout<<"\nso luong so hoan hao la "<<dem;
}
void capsocong(int a[],int n){
	for(int i=0;i<n-2;i++){
		if(abs(a[i]-a[i+1])==abs(a[i+1]-a[i+2])){
			cout<<"\n3 so lap thanh cap so cong la "<<i<<" "<<i+1<<" "<<i+2;
		}
	}
}
void tb_cong_le_duong(int a[],int n){
	float s=0;
	for(int i=0;i<n;i++){
		if(a[i]>0){
			if(a[i]%2!=0)
			{
				if(a[i]%3!=0){
					s+=a[i];
				}
			}	
		}
	}
	cout<<"\ntrung binh cong so le duong va khong chia het cho 3 la "<<s/n;
}
int ktsnt(int n){
	if(n==2)return 1;
	if(n<2)return 0;
	for(int i=2;i<n;i++){
		if(n%i==0){
			return 0;
		}
	}
	return 1;
}
void vitrisnt(int a[],int n){
	cout<<"\nvi tri cac so nguyen to la ";
	for(int i=0;i<n;i++){
		if(ktsnt(a[i])==1){
			cout<<i<<" ";
		}
	}
}
void lietkesnt(int a[],int n){
	cout<<"\ncac so nguyen to la ";
	for(int i=0;i<n;i++){
		if(ktsnt(a[i])==1){
			cout<<a[i]<<" ";
		}
	}
}
void xoapt(int a[],int &n,int pt){
	for(int i=pt;i<n;i++){
		a[i]=a[i+1];
	}
	n--;
}
void xoaso0(int a[],int &n){
	for(int i=0;i<n;i++){
		if(a[i]==0){
			xoapt(a,n,i);
		}
	}
}
void sapxep(int a[],int n){
	for(int i=0;i<n;i++){
		for(int j=n-1;j>0;j--){
			if(a[j]<=a[j-1]){
				int tam=a[j];
				a[j]=a[j-1];
				a[j-1]=tam;
			}
		}
	}
}
void menu(int a[],int n){
	int chon;
	cout<<"\n1.nhap ";
	cout<<"\n2.xuat ";
	cout<<"\n3.them pt ";
	cout<<"\n4.dem co bao nhieu so hoan hao va so dem duoc la chan hay le ";
	cout<<"\n5.vi tri 3 so dung lien nhau tao thanh cap so cong ";
	cout<<"\n6.tinh trung binh cong so le duong khong chia het cho 3 ";
	cout<<"\n7.kiem tra ds co so nguyen to khong ,co thi o vi tri nao ";
	cout<<"\n8.cac so nguyen to ";
	cout<<"\n9.xoa cac so 0 trong danh sach ";
	cout<<"\n10.sap xep danh sach theo thuc tu tang dan ";
	do{
		cout<<"\nnhap chon ";cin>>chon;
		switch(chon){
			case 1:{
				nhap(a,n);break;
			}
			case 2:{
				xuat(a,n);break;
				
			}
			case 3:{
				int vt,gt;
				do{
					cout<<"\nnhap vi tri can them pt ";cin>>vt;
					if(vt>n || vt<0)
						cout<<"\nvi tri ban nhap vuot qua n ";
				}while(vt>n || vt<0);
				cout<<"\nnhap gia tri ";cin>>gt;
				thempt(a,n,vt,gt);break;
			}
			case 4:{
				demsohh(a,n);break;
			}
			case 5:{
				capsocong(a,n);break;
			}
			case 6:{
				tb_cong_le_duong(a,n);break;
			}
			case 7:{
				vitrisnt(a,n);break;
			}
			case 8:{
				lietkesnt(a,n);break;
			}
			case 9:{
				xoaso0(a,n);break;
			}
			case 10:{
				sapxep(a,n);break;
			}
		}
	}while(chon!=0);
}
int main(){
	int n,*a;
	cout<<"\nnhap so luong pt ";cin>>n;
	a=(int*)malloc(n*sizeof(int));
	menu(a,n);
	return 0;
}