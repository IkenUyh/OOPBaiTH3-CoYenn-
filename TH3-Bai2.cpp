#include<iostream>
#include<cmath>
#include<iomanip>
#define epsilon 0.0000000001
#define pi 3.14159265358979323846
using namespace std;
class DIEM{
    private:
        double x, y;
        static int dem;
    public:
        ~DIEM();
        DIEM();
        DIEM(double);
        DIEM(double, double);
        DIEM(const DIEM&);
        DIEM& operator=(const DIEM&);
        double GetX() const;
        double GetY() const;
        static int GetDem();
        void SetX(double);
        void SetY(double);
        void SetXY(double, double);
        void Nhap();
        void Xuat() const;
        friend istream& operator>>(istream& in, DIEM& d);
        friend ostream& operator<<(ostream& out, const DIEM& d);
        void TinhTien(double, double);
        bool KiemTraTrung(DIEM) const;
        double TinhKhoangCach(const DIEM&) const;
        DIEM TimDiemDoiXung() const;
        void PhongTo(double);
        void ThuNho(double);
        void Quay(int);
        void DoiXungOx();
        void DoiXungOy();
        void DoiXungGoc();
};
int DIEM::dem=0;
DIEM::~DIEM(){
    --dem;
}
DIEM::DIEM():x(0), y(0){
    //x=y=0;
    ++dem;
}
DIEM::DIEM(double x):x(x), y(0){
    //this->x=x; y=0;
    ++dem;
}
DIEM::DIEM(double x, double y):x(x), y(y){
    //this->x=x; this->y=y;
    ++dem;
}
DIEM::DIEM(const DIEM& d):x(d.x), y(d.y){
    //this->x=d.x;
    //this->y=d.y;
    ++dem;
}
DIEM& DIEM::operator=(const DIEM& d){
    this->x=d.x;
    this->y=d.y;
    return *this;
}
double DIEM::GetX() const{
    return this->x;
}
double DIEM::GetY() const{
    return this->y;
}
int DIEM::GetDem(){
    return dem;
}
void DIEM::SetX(double x){
    this->x=x;
}
void DIEM::SetY(double y){
    this->y=y;
}
void DIEM::SetXY(double x, double y){
    SetX(x); SetY(y);
}
istream& operator>>(istream& in, DIEM& d){
    d.Nhap();
    return in;
}
ostream& operator<<(ostream& out, const DIEM& d){
    d.Xuat();
    return out;
}
void DIEM::Nhap(){
    cout<<"Nhap hoanh do va tung do: ";
    cin>>x>>y;
}
void DIEM::Xuat() const{
    cout<<fixed<<setprecision(2)<<"("<<x<<", "<<fixed<<setprecision(2)<<y<<")";
}
bool DIEM::KiemTraTrung(DIEM d) const{
    return x==d.x && y==d.y;
}
double DIEM::TinhKhoangCach(const DIEM&d) const{
    return sqrt(pow(x-d.x, 2)+pow(y-d.y, 2));
}
DIEM DIEM::TimDiemDoiXung() const{
    return DIEM(-x, -y);
}
void DIEM::DoiXungOx(){
    x=-x;
}
void DIEM::DoiXungOy(){
    y=-y;
}
void DIEM::DoiXungGoc(){
    x=-x; y=-y;
}
void DIEM::TinhTien(double dx, double dy){
    x+=dx;
    y+=dy;
}
void DIEM::PhongTo(double scale){
    if(scale>0){
        x*=scale; y*=scale;
    }
}
void DIEM::ThuNho(double scale){
    if(scale>0){
        x/=scale; y/=scale;
    }
}
void DIEM::Quay(int alpha){
    double rad=alpha*pi/180.0;
    double xMoi=x*cos(rad)-y*sin(rad);
    double yMoi=x*sin(rad)+y*cos(rad);
    x=xMoi;
    y=yMoi;
}
class cDaGiac{
    private:
        DIEM* dsDiem;
        int soDinh;
        static int dem;
    public: 
        ~cDaGiac();
        cDaGiac();
        cDaGiac(int);
        cDaGiac(const DIEM*, int);
        cDaGiac(const cDaGiac&);
        int GetSoDinh() const;
        DIEM GetDinh(int) const;
        static int GetDem();
        void SetDinh(int, const DIEM&);
        void SetDiem(const DIEM*, int);
        void Nhap();
        void Xuat() const;
        friend istream& operator>>(istream& in, cDaGiac& dg);
        friend ostream& operator<<(ostream& out, const cDaGiac& dg);
        double TinhChuVi() const;
        double TinhDienTich() const;
        string KiemTraDaGiacLoi() const;
        bool KiemTraDiemNamTrong(const DIEM&) const;
        void TinhTien(double, double);
        void Quay(int);
        void PhongTo(double);
        void ThuNho(double);
        void DoiXungOx();
        void DoiXungOy();
        void DoiXungGoc();
};
int cDaGiac::dem=0;
cDaGiac::~cDaGiac(){
    --dem;
    delete[] dsDiem;
}
cDaGiac::cDaGiac() : soDinh(3){
    dsDiem=new DIEM[soDinh];
    ++dem;
}
cDaGiac::cDaGiac(int soDinh) : soDinh(soDinh>2?soDinh:3){
    dsDiem=new DIEM[this->soDinh];
    ++dem;
}
cDaGiac::cDaGiac(const DIEM* arr, int soDinh) : soDinh(soDinh>2?soDinh:3){
    dsDiem=new DIEM[this->soDinh];
    for(int i=0; i<this->soDinh; i++){
        dsDiem[i]=arr[i];
    }
    ++dem;
}
cDaGiac::cDaGiac(const cDaGiac& dg) : soDinh(dg.soDinh){
    dsDiem=new DIEM[soDinh];
    for(int i=0; i<soDinh; i++){
        dsDiem[i]=dg.dsDiem[i];
    }
    ++dem;
}
int cDaGiac::GetSoDinh() const{
    return this->soDinh;
}
DIEM cDaGiac::GetDinh(int index) const{
    if(index>=0&&index<soDinh) return dsDiem[index];
    cout<<"Chi so khong hop le!"<<endl;
    return DIEM();
}
int cDaGiac::GetDem(){
    return dem;
}
void cDaGiac::SetDinh(int index, const DIEM& diem){
    if(index>=0&&index<soDinh) dsDiem[index]=diem;
    else cout<<"Chi so khong hop le!"<<endl;
}
void cDaGiac::SetDiem(const DIEM* arr, int n){
    if(n<3){
        cout<<"So dinh phai lon hon 3!"<<endl;
        return;
    }
    delete[] dsDiem;
    soDinh=n;
    dsDiem=new DIEM[soDinh];
    for(int i=0; i<soDinh; i++){
        dsDiem[i]=arr[i];
    }
}
istream& operator>>(istream& in, cDaGiac& dg){
    dg.Nhap();
    return in;
}
ostream& operator<<(ostream& out, const cDaGiac& dg){
    dg.Xuat();
    return out;
}
void cDaGiac::Nhap(){
    cout<<"Nhap so dinh: "; cin>>soDinh;
    while(soDinh<3){
        cout<<"So dinh phai lon hon 3! Moi ban nhap lai: "<<endl;
        cout<<"Nhap so dinh: "; cin>>soDinh;
    }
    delete[] dsDiem;
    dsDiem=new DIEM[soDinh];
    for(int i=0; i<soDinh; i++){
        cout<<"Nhap dinh thu "<<i+1<<": "<<endl;
        dsDiem[i].Nhap();
    }
}
void cDaGiac::Xuat() const{
    cout<<"Da giac co "<<soDinh<<" dinh: "<<endl;
    for(int i=0; i<soDinh; i++){
        cout<<"Dinh "<<i+1<<": ";
        dsDiem[i].Xuat();
        cout<<endl;
    }
    cout<<endl;
}
double cDaGiac::TinhChuVi() const{
    double chuvi=0;
    for(int i=0; i<soDinh; i++){
        chuvi+=dsDiem[i].TinhKhoangCach(dsDiem[(i+1)%soDinh]);
    }
    return chuvi;
}
double cDaGiac::TinhDienTich() const{
    // Sử dụng công thức Shoelace để tính diện tích đa giác
    double dientich=0;
    for(int i=0; i<soDinh-1; i++){
        dientich+=dsDiem[i].GetX()*dsDiem[i+1].GetY()-dsDiem[i+1].GetX()*dsDiem[i].GetY();
    }
    dientich+=dsDiem[soDinh-1].GetX()*dsDiem[0].GetY()-dsDiem[0].GetX()*dsDiem[soDinh-1].GetY();
    return fabs(dientich)/2.0;
}
string cDaGiac::KiemTraDaGiacLoi() const{
    if(soDinh<3) return "Khong phai da giac";
    bool huongDuong=true;
    bool daXacDinhHuong=false;
    for (int i=0;i<soDinh; i++) {
        DIEM p1=dsDiem[i];
        DIEM p2=dsDiem[(i + 1)%soDinh]; 
        DIEM p3=dsDiem[(i + 2)%soDinh];
        double v1_x=p2.GetX()-p1.GetX();
        double v1_y=p2.GetY()-p1.GetY();
        double v2_x=p3.GetX()-p2.GetX();
        double v2_y=p3.GetY()-p2.GetY();
        double TichCheo=v1_x*v2_y-v1_y*v2_x;
        if(!daXacDinhHuong){
            huongDuong=(TichCheo>0);
            daXacDinhHuong=true;
        }
        else if((TichCheo>0)!=huongDuong) return "Da giac khong loi";
    }
    return "Da giac loi";
}
bool cDaGiac::KiemTraDiemNamTrong(const DIEM& diem) const{
    // Sử dụng thuật toán ray casting
    int cnt=0;
    for(int i=0; i<soDinh; i++){
        DIEM p1=dsDiem[i];
        DIEM p2=dsDiem[(i+1)%soDinh];
        if (p1.GetY()==diem.GetY()&&p2.GetY()==diem.GetY() &&
            ((p1.GetX()<=diem.GetX()&&diem.GetX()<=p2.GetX()) ||
             (p2.GetX()<=diem.GetX()&&diem.GetX()<=p1.GetX()))){ 
            return true;
        }
        if((diem.GetY()>p1.GetY())!=(diem.GetY()>p2.GetY())){
            double intersectX=p1.GetX()+(diem.GetY()-p1.GetY())*(p2.GetX()-p1.GetX())/(p2.GetY()-p1.GetY());
            if(diem.GetX()<intersectX) {
                cnt++;
            }
        }
    }
    return cnt%2==1;
}
void cDaGiac::TinhTien(double dx, double dy){
    for(int i=0; i<soDinh; i++) dsDiem[i].TinhTien(dx, dy);
}
void cDaGiac::Quay(int alpha){
    for(int i=0; i<soDinh; i++) dsDiem[i].Quay(alpha);
}
void cDaGiac::PhongTo(double scale){
    if(scale<=0){
        cout<<"He so phong to phai duong!"<<endl;
        return;
    }
    for(int i=0; i<soDinh; i++) dsDiem[i].PhongTo(scale);
}
void cDaGiac::ThuNho(double scale){
    if(scale<=0){
        cout<<"He so thu nho phai duong!"<<endl;
        return;
    }
    for(int i=0; i<soDinh; i++) dsDiem[i].ThuNho(scale);
}
void cDaGiac::DoiXungOx(){
    for(int i=0; i<soDinh; i++) dsDiem[i].DoiXungOx();
}
void cDaGiac::DoiXungOy(){
    for(int i=0; i<soDinh; i++) dsDiem[i].DoiXungOy();
}
void cDaGiac::DoiXungGoc(){
    for(int i=0; i<soDinh; i++) dsDiem[i].DoiXungGoc();
}
int main(){
    cout<<"=====CHUONG TRINH MINH HOA DA GIAC====="<<endl<<endl;
    cout<<"1. Tao da giac bang cach nhap tu ban phim:"<<endl;
    cDaGiac daGiac1;
    daGiac1.Nhap();
    cout<<"Da giac vua nhap:"<<endl;
    daGiac1.Xuat();
    cout<<"\n2. Tinh toan thuoc tinh co ban:"<<endl;
    cout<<"- Chu vi: "<<daGiac1.TinhChuVi()<<endl;
    cout<<"- Dien tich: "<<daGiac1.TinhDienTich()<<endl;
    cout<<"- "<<daGiac1.KiemTraDaGiacLoi()<<endl;
    cout<<"\n3. Kiem tra diem nam trong da giac: "<<endl<<endl;
    cout<<"Nhap vao diem muon test: "; 
    double fi, se; cin>>fi>>se;
    DIEM diemTest(fi, se);
    cout<<"Diem test "; diemTest.Xuat(); cout<<endl;
    if (daGiac1.KiemTraDiemNamTrong(diemTest)) cout<<"=> Diem nam trong da giac"<<endl;
    else cout<<"=> Diem khong nam trong da giac"<<endl;
    cDaGiac daGiac2(daGiac1);
    cout<<"\n4. Cac phep bien doi da giac:"<<endl<<endl;
    cout<<"Nhap vao toa do x y vector muon tinh tien: "; cin>>fi>>se;
    cout<<"a) Tinh tien theo vector ("<<fi<<", "<<se<<"):" << endl;
    daGiac2.TinhTien(fi, se);
    cout<<"Da giac sau khi tinh tien:"<<endl;
    daGiac2.Xuat();
    cout<<"Nhap vao goc muon quay (0<=goc<=360): ";
    int alpha; cin>>alpha;
    cout<<"b) Quay "<<alpha<<" do quanh goc toa do:"<<endl;
    daGiac2=daGiac1; 
    daGiac2.Quay(alpha);
    cout<<"Da giac sau khi quay:"<<endl;
    daGiac2.Xuat();
    cout<<"Nhap vao ti le muon phong to: ";
    double scale; cin>>scale;
    cout<<"c) Phong to gap "<<scale<<" lan:"<<endl;
    daGiac2=daGiac1; 
    daGiac2.PhongTo(scale);
    cout<<"Da giac sau khi phong to:"<<endl;
    daGiac2.Xuat();
    cout<<"Nhap vao ti le muon thu nho: ";
    cin>>scale;
    cout<<"d) Thu nho xuong "<<scale<<" lan:"<<endl;
    daGiac2=daGiac1; 
    daGiac2.ThuNho(scale);
    cout<<"Da giac sau khi thu nho:"<<endl;
    daGiac2.Xuat();
    cout<<"e) Doi xung qua truc Ox:"<<endl;
    daGiac2=daGiac1; 
    daGiac2.DoiXungOx();
    cout<<"Da giac sau khi doi xung qua Ox:"<<endl;
    daGiac2.Xuat();
    cout<<"f) Doi xung qua truc Oy:"<<endl;
    daGiac2=daGiac1; 
    daGiac2.DoiXungOy();
    cout<<"Da giac sau khi doi xung qua Oy:"<<endl;
    daGiac2.Xuat();
    cout<<"g) Doi xung qua goc toa do:"<<endl;
    daGiac2=daGiac1; 
    daGiac2.DoiXungGoc();
    cout<<"Da giac sau khi doi xung qua goc toa do:"<<endl;
    daGiac2.Xuat();
    cout<<"\n5. Tao da giac tu mang cac diem:"<<endl;
    DIEM dsDiem[4]={DIEM(0, 0), DIEM(4, 0), DIEM(4, 3), DIEM(0, 3)};
    cDaGiac daGiac3(dsDiem, 4);
    cout<<"Da giac hinh chu nhat:"<<endl;
    daGiac3.Xuat();
    cout<<"- Chu vi: "<<daGiac3.TinhChuVi()<<endl;
    cout<<"- Dien tich: "<<daGiac3.TinhDienTich()<<endl;
    cout<<"- "<<daGiac3.KiemTraDaGiacLoi()<<endl;
    cout<<"\n6. Thong ke:"<<endl;
    cout<<"- So luong diem da tao: " << DIEM::GetDem()<<endl;
    cout<<"- So luong da giac da tao: " << cDaGiac::GetDem()<<endl;
    cout<<"\n=== KET THUC CHUONG TRINH ==="<<endl;
    return 0;
}