#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
class cCandidate{
    private:
        string id;
        string name;
        int ngay, thang, nam;
        double toan, van, anh;
        static int dem;
    public:
        ~cCandidate();
        cCandidate();
        cCandidate(string);
        cCandidate(string, string);
        cCandidate(string, string, int, int, int, double, double, double);
        cCandidate(int, int, int);
        cCandidate(double, double, double);
        cCandidate(const cCandidate&);
        cCandidate& operator=(const cCandidate&);
        string GetID() const;
        string GetName() const;
        int GetNgay() const;
        int GetThang() const;
        int GetNam() const;
        double GetToan() const;
        double GetVan() const;
        double GetAnh() const;
        static int GetDem();
        void SetID(string);
        void SetName(string);
        void SetNgay(int);
        void SetThang(int);
        void SetNam(int);
        void SetNgayThangNam(int, int, int);
        void SetToan(double);
        void SetVan(double);
        void SetAnh(double);
        void SetToanVanAnh(double, double, double);
        void Nhap();
        void Xuat() const;
        friend istream& operator>>(istream& in, cCandidate& ts);
        friend ostream& operator<<(ostream& out, const cCandidate& ts);
        bool KiemTraHopLe() const;
};
int cCandidate::dem=0;
bool NamNhuan(int nam){
    return (nam%4==0&&nam%100!=0)||(nam%400==0);
}
int SoNgayTrongThang(int thang, int nam){
    int nThang[]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(thang==2&&NamNhuan(nam)) return 29;
    return nThang[thang];
}
bool cCandidate::KiemTraHopLe() const{
    return thang>=1&&thang<=12&&nam>=1&&ngay>=1&&ngay<=SoNgayTrongThang(thang, nam);
}
bool isName(char x){
    return (x>='a'&&x<='z')||(x>='A'&&x<='Z')||(x==' ');
}
bool KiemTraHoTen(const string& name){
    if(name.empty()) return false;
    for(const auto& x:name){
        if(!isName(x)) return false;
    }
    return true;
}
cCandidate::~cCandidate(){
    --dem;
}
cCandidate::cCandidate():id(""), name(""), ngay(12), thang(4), nam(2025), toan(0), van(0), anh(0){
    //id=name="";
    //ngay=thang=nam=0;
    //toan=van=anh=0;
    ++dem;
}
cCandidate::cCandidate(string id):id(id){
    name="";
    ngay=thang=nam=0;
    toan=van=anh=0;
    ++dem;
}
cCandidate::cCandidate(string id, string name):id(id), name(name){
    this->id=id;
    toan=van=anh=0;
    if(!KiemTraHoTen(name)) this->name="";
    ++dem;
}
cCandidate::cCandidate(string id, string name, int ngay, int thang, int nam, double toan, double van, double anh){
    this->id=id; this->name=name;
    if(!KiemTraHoTen(name)) this->name="";
    this->toan=toan; this->van=van; this->anh=anh;
    if(toan>10||toan<0) this->toan=0;
    if(van>10||van<0) this->van=0;
    if(anh>10||anh<0) this->anh=0;
    this->ngay=ngay; this->thang=thang; this->nam=nam;
    if(!KiemTraHopLe()){
        this->ngay=12; this->thang=4; this->nam=2025;
    }
    ++dem;
}
cCandidate::cCandidate(int ngay, int thang, int nam):ngay(ngay), thang(thang), nam(nam){
    id=name="";
    toan=van=anh=0;
    if(!KiemTraHopLe()){
        this->ngay=12; this->thang=4; this->nam=2025;
    }
    ++dem;
}
cCandidate::cCandidate(double toan, double van, double anh):toan(toan), van(van), anh(anh){
    id=name="";
    ngay=12; thang=4; nam=2025;
    if(toan>10||toan<0) this->toan=0;
    if(van>10||van<0) this->van=0;
    if(anh>10||anh<0) this->anh=0;
    ++dem;
}
cCandidate::cCandidate(const cCandidate& ps){
    this->id=ps.id; this->name=ps.name;
    this->ngay=ps.ngay; this->thang=ps.thang; this->nam=ps.nam;
    this->toan=ps.toan; this->van=ps.van; this->anh=ps.anh;
    ++dem;
}
cCandidate& cCandidate::operator=(const cCandidate& ps){
    this->id=ps.id; this->name=ps.name;
    this->ngay=ps.ngay; this->thang=ps.thang; this->nam=ps.nam;
    this->toan=ps.toan; this->van=ps.van; this->anh=ps.anh;
    return *this;
}
string cCandidate::GetID() const{
    return this->id;
}
string cCandidate::GetName() const{
    return this->name;
}
int cCandidate::GetNgay() const{
    return this->ngay;
}
int cCandidate::GetThang() const{
    return this->thang;
}
int cCandidate::GetNam() const{
    return this->nam;
}
double cCandidate::GetToan() const{
    return this->toan;
}
double cCandidate::GetVan() const{
    return this->van;
}
double cCandidate::GetAnh() const{
    return this->anh;
}
int cCandidate::GetDem(){
    return dem;
}
void cCandidate::SetID(string id){
    this->id=id;
}
void cCandidate::SetName(string name){
    while(!KiemTraHoTen(name)){
        cout<<"Ho ten vua nhap khong hop le!";
        cout<<"Moi ban nhap lai: "; 
        getline(cin, name);
    }
    this->name=name;
}
void cCandidate::SetNgay(int ngay){
    int ngay_tam=this->ngay;
    this->ngay=ngay;
    if(!KiemTraHopLe()) this->ngay=ngay_tam;
}
void cCandidate::SetThang(int thang){
    int thang_tam=this->thang;
    this->thang=thang;
    if(!KiemTraHopLe()) this->thang=thang_tam;
}
void cCandidate::SetNam(int nam){
    int nam_tam=this->nam;
    this->nam=nam;
    if(!KiemTraHopLe()) this->nam=nam_tam;
}
void cCandidate::SetNgayThangNam(int ngay, int thang, int nam){
    SetNgay(ngay);
    SetThang(thang);
    SetNam(nam);
}
void cCandidate::SetToan(double toan){
    double toan_tam=this->toan;
    this->toan=toan;
    if(toan>10||toan<0) this->toan=toan_tam;
}
void cCandidate::SetVan(double van){
    double van_tam=this->van;
    this->van=van;
    if(van>10||van<0) this->van=van_tam;
}
void cCandidate::SetAnh(double anh){
    double anh_tam=this->anh;
    this->anh=anh;
    if(anh>10||anh<0) this->anh=anh_tam;
}
void cCandidate::SetToanVanAnh(double toan, double van, double anh){
    SetToan(toan);
    SetVan(van);
    SetAnh(anh);
}
istream& operator>>(istream& in, cCandidate& ts){
    ts.Nhap();
    return in;
}
ostream& operator<<(ostream& out, const cCandidate& ts){
    ts.Xuat();
    return out;
}
void cCandidate::Nhap(){
    cin.ignore();
    cout<<"Nhap ma thi sinh: "; getline(cin, id);
    cout<<"Nhap ho ten thi sinh: "; getline(cin, name);
    while(!KiemTraHoTen(name)){
        cout<<"Ho ten vua nhap khong hop le!";
        cout<<"Moi ban nhap lai: "; 
        getline(cin, this->name);
    }
    cout<<"Nhap ngay: "; cin>>ngay;
    cout<<"Nhap thang: "; cin>>thang;
    cout<<"Nhap nam: "; cin>>nam;
    while(!KiemTraHopLe()){
        cout<<"Ngay sinh ban nhap khong hop le!";
        cout<<"Moi ban nhap lai: "; 
        cout<<"Nhap ngay: "; cin>>ngay;
        cout<<"Nhap thang: "; cin>>thang;
        cout<<"Nhap nam: "; cin>>nam;
    }
    cout<<"Nhap diem toan: "; cin>>toan;
    while(toan>10||toan<0){
        cout<<"Diem toan khong hop le!";
        cout<<"Moi ban nhap lai: "; cin>>toan;
    }
    cout<<"Nhap diem van: "; cin>>van;
    while(van>10||van<0){
        cout<<"Diem van khong hop le!";
        cout<<"Moi ban nhap lai: "; cin>>van;
    }
    cout<<"Nhap diem anh: "; cin>>anh;
    while(anh>10||anh<0){
        cout<<"Diem anh khong hop le!";
        cout<<"Moi ban nhap lai: "; cin>>anh;
    }
}
void cCandidate::Xuat() const{
    cout<<"Ma thi sinh: "<<id<<endl;;
    cout<<"Ho va ten thi sinh: "<<name<<endl;
    cout<<"Ngay thang nam sinh: ";
    if(ngay<10) cout<<"0"<<ngay;
    else cout<<ngay;
    cout<<"/";
    if(thang<10) cout<<"0"<<thang;
    else cout<<thang;
    cout<<"/"<<nam<<endl;
    cout<<"Diem toan: "<<fixed<<setprecision(2)<<toan<<endl;
    cout<<"Diem van: "<<fixed<<setprecision(2)<<van<<endl;
    cout<<"Diem anh: "<<fixed<<setprecision(2)<<anh<<endl;
}
class cListCandidate{
    private:
        int n; 
        cCandidate* a;
        static int dem;
    public:
        ~cListCandidate();
        cListCandidate();
        cListCandidate(int);
        cListCandidate(int, cCandidate);
        cListCandidate(const cCandidate*, int);
        cListCandidate(const cListCandidate&);
        int GetN() const;
        cCandidate* GetA() const;
        static int GetDem();
        void SetN(int);
        void SetA(const cListCandidate&);
        void Nhap();
        void Xuat() const;
        friend istream& operator>>(istream& in, cListCandidate& nums);
        friend ostream& operator<<(ostream& out, const cListCandidate& nums);
        cCandidate ThuKhoa() const;
        void SapXepGiamDan();
};
int cListCandidate::dem=0;
cListCandidate::~cListCandidate(){
    --dem;
    if(a!=nullptr){
        delete[] a;
        a=nullptr;
        n=0;
    }
}
cListCandidate::cListCandidate(){
    a=nullptr; n=0;
    ++dem;
}
cListCandidate::cListCandidate(int n){
    while(n<=0){
        cout<<"So luong thi sinh phai > 0!";
        cout<<"Moi ban nhap lai: " ;
        cin>>n;
    }
    this->n=n;
    a=new cCandidate[this->n];
    ++dem;
}
cListCandidate::cListCandidate(int n, cCandidate ts){
    while(n<=0){
        cout<<"So luong thi sinh phai > 0!";
        cout<<"Moi ban nhap lai: " ;
        cin>>n;
    }
    this->n=n;
    a=new cCandidate[this->n];
    for(int i=0; i<this->n; i++) a[i]=ts;
    ++dem;
}
cListCandidate::cListCandidate(const cCandidate* arr, int n){
    a=new cCandidate[n];
    this->n=n;
    for(int i=0; i<n; i++) a[i]=arr[i];
    ++dem;
}
cListCandidate::cListCandidate(const cListCandidate& nums){
    if(!nums.n){
        a=nullptr;
        this->n=0;
    }
    else{
        n=nums.n;
        a=new cCandidate[n];
        for(int i=0; i<n; i++) a[i]=nums.a[i];
    }
    ++dem;
}
int cListCandidate::GetN() const{
    return this->n;
}
cCandidate* cListCandidate::GetA() const{
    return this->a;
}
int cListCandidate::GetDem(){
    return dem;
}
void cListCandidate::SetN(int n){
    if(!n) this->~cListCandidate();
    else{
        while(n<=0){
            cout<<"So luong thi sinh phai > 0!";
            cout<<"Moi ban nhap lai: " ;
            cin>>n;
        }
        cListCandidate nums(n);
        for(int i=0; i<this->n; i++) nums.a[i]=a[i];
        this->~cListCandidate();
        *this=nums;
    }
}
void cListCandidate::SetA(const cListCandidate& nums){
    *this=nums;
}
istream& operator>>(istream& in, cListCandidate& nums){
    nums.Nhap();
    return in;
}
ostream& operator<<(ostream& out, const cListCandidate& nums){
    nums.Xuat();
    return out;
}
void cListCandidate::Nhap(){
    if(a!=nullptr) this->~cListCandidate();
    cout<<"Nhap so luong thi sinh: "; cin>>n;
    while(n<=0){
        cout<<"So luong thi sinh phai > 0!";
        cout<<"Moi ban nhap lai: " ;
        cin>>n;
    }
    a=new cCandidate[n];
    for(int i=0; i<n; i++) a[i].Nhap();
}
void cListCandidate::Xuat() const{
    if(a==nullptr) cout<<"Khong co thi sinh nao"<<endl;
    else{
        for(int i=0; i<n; i++){
            double sum=a[i].GetToan()+a[i].GetVan()+a[i].GetAnh();
            if(sum>15) a[i].Xuat();
        }
        cout<<endl;
    }
}
int partition(cCandidate* &a, int l, int r){
    cCandidate pivot=a[r];
    double pivot_sum=a[r].GetToan()+a[r].GetVan()+a[r].GetAnh();
    int i=l-1;
    for(int j=l; j<r; j++){
        double sum=a[j].GetToan()+a[j].GetVan()+a[j].GetAnh();
        if(sum>=pivot_sum){
            ++i; cCandidate temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    ++i;
    swap(a[i], a[r]);
    return i;
}
void QuickSort(cCandidate* &a, int l, int r){
    if(l>=r) return;
    int p=partition(a, l, r);
    QuickSort(a, l, p-1);
    QuickSort(a, p+1, r);
}
cCandidate cListCandidate::ThuKhoa() const{
    cCandidate thukhoa=a[0];
    double nmax=a[0].GetToan()+a[0].GetVan()+a[0].GetAnh();
    for(int i=1; i<n; i++){
        double sum=a[i].GetToan()+a[i].GetVan()+a[i].GetAnh();
        if(sum>nmax){
            nmax=sum;
            thukhoa=a[i];
        }
    }
    return thukhoa;
}
void cListCandidate::SapXepGiamDan(){
    QuickSort(a, 0, n-1);
}
int main() {
    cout<<"\n=====CHUONG TRINH QUAN LY THI SINH=====\n";
    cout<<"1. Khoi tao thi sinh bang cac constructor khac nhau:\n";
    cCandidate ts1; 
    cCandidate ts2("TS002", "Nguyen Van B", 15, 5, 2000, 8.5, 7.0, 9.0); 
    cCandidate ts3("TS003", "Tran Thi C"); 
    cCandidate ts4(9.5, 8.0, 7.5); 
    cout<<"Thi sinh 1 (Constructor mac dinh):\n"; ts1.Xuat();
    cout<<"\nThi sinh 2 (Constructor day du tham so):\n"; ts2.Xuat();
    cout<<"\nThi sinh 3 (Constructor voi ID va ten):\n"; ts3.Xuat();
    cout<<"\nThi sinh 4 (Constructor voi diem):\n"; ts4.Xuat();
    cout<<"\n2. Thay doi thong tin thi sinh bang cac setter:\n";
    ts1.SetID("TS001");
    ts1.SetName("Le Van A");
    ts1.SetNgayThangNam(10, 8, 2001);
    ts1.SetToanVanAnh(7.5, 8.0, 6.5);
    cout<<"Thi sinh 1 sau khi thay doi thong tin:\n"; ts1.Xuat();
    cout<<"\n3. Tao danh sach thi sinh:\n";
    int n=3;
    cCandidate* arrTS=new cCandidate[n];
    arrTS[0]=ts1;
    arrTS[1]=ts2;
    arrTS[2]=ts3;
    cListCandidate danhSach(arrTS, n);
    cout<<"Danh sach thi sinh co diem tong > 15:\n";
    danhSach.Xuat();
    cout<<"\n4. Tim thi sinh thu khoa:\n";
    cCandidate thuKhoa=danhSach.ThuKhoa();
    cout<<"Thong tin thi sinh thu khoa:\n"; thuKhoa.Xuat();
    cout<<"\n5. Sap xep danh sach thi sinh theo diem giam dan:\n";
    danhSach.SapXepGiamDan();
    cout<<"Danh sach sau khi sap xep (chi hien thi nhung thi sinh co tong diem > 15):\n"; danhSach.Xuat();
    cout<<"\n6. Tao danh sach thi sinh moi tu ban phim:\n";
    cListCandidate danhSachMoi;
    danhSachMoi.Nhap();
    cout<<"\nDanh sach thi sinh vua nhap (chi hien thi nhung thi sinh co tong diem > 15):\n";
    danhSachMoi.Xuat();
    cout<<"\nSap xep danh sach theo diem giam dan:\n";
    danhSachMoi.SapXepGiamDan();
    danhSachMoi.Xuat();
    cout<<"\nThi sinh thu khoa cua danh sach:\n";
    danhSachMoi.ThuKhoa().Xuat();
    cout<<"\n7. Thong ke:\n";
    cout<<"So luong doi tuong thi sinh da tao: "<<cCandidate::GetDem()<<endl;
    cout<<"So luong danh sach thi sinh da tao: "<<cListCandidate::GetDem()<<endl;
    delete[] arrTS;
    return 0;
}