#include <iostream>
#include <cstring>
using namespace std;

class SinhVien{
	protected:
		char HoTen[30];
		int NamSinh,GT;
		float Diem;
	public:
		 void Nhap();
		 void Xuat();
		 int Tim_Diem_SV(){
		 	if(Diem<4.0){
		 		Xuat();
			 }
		 }
		 void Tim_Ten(int diem){
		 	//char ht[]="Nguyen Van";
		 	if(strstr(HoTen,"Nguyen Van")!=NULL && Diem>diem){
		 		Xuat();
			 }
		 }
	
};

void SinhVien:: Nhap(){
	fflush(stdin);
	cout<<"\nHo ten: ";
	cin.getline(HoTen,30);
	fflush(stdin);
	
	cout<<"Nam sinh: ";
	cin>>NamSinh;
	fflush(stdin);
	
		do{
		cout<<"Gioi tinh ";
		cout<<"[1.Nam/";
		cout<<" 2.Nu]: ";
		cin>>GT;
		string Nam,Nu;
		switch(GT){
			case 1: 
				break;
			case 2:
				break;
		}
			
	}while(GT>2);
	
	cout<<"Diem: ";
	cin>>Diem;
}

void SinhVien::Xuat(){
	cout<<"\t - Ho ten: "<<HoTen<<endl<<"\t\t + Nam sinh:"<<NamSinh<<endl<<"\t\t + Gioi tinh: ";
	if(GT==1){
		cout<<"Nam";
	}else if(GT==2){
		cout<<"Nu";
	}
	cout<<"\n\t\t + Tuoi:"<<2020-NamSinh<<"\n\t\t + Diem: "<<Diem<<endl;
}
class QuanLy{
	private :
		SinhVien sv[100];
		int n;
	public: 
		void Nhap(){
			cout<<"Nhap so luong sinh vien:";
			cin>>n;
			cout<<"\nNhap danh sach sinh vien\n";
			for(int i=0;i<n;i++){
				sv[i].Nhap();
			}
		}
		void Xuat(){
			for(int i=0;i<n;i++){
				sv[i].Xuat();
			}
		}
		int Tim_Diem_SV(){
			for(int i=0;i<n;i++){
				sv[i].Tim_Diem_SV();
			}
		}
		void Tim_Ten(int diem){
			
			for(int i=0;i<n;i++){
				sv[i].Tim_Ten(diem);
			}
		}
};
int main(){
	QuanLy ql;
	int diem;
	ql.Nhap();
	cout<<"Danh sach sinh vien vua nhap la: \n";
	ql.Xuat();
	cout<<"Cac sinh vien co diem < 4.0 la\n";
	ql.Tim_Diem_SV();
	cout<< "Nhap so diem:";
	cin>>diem;
	cout<<"Sinh vien co diem lon hon so nhap tu ban phim va co ten bat dau ban 'Nguyen Van' la:\n";
	ql.Tim_Ten(diem);
}	
