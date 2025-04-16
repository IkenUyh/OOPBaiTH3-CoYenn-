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
    cout<<fixed<<setprecision(2)<<x<<", "<<fixed<<setprecision(2)<<y;
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
class HCN{
private:
    DIEM A, B;
    static int dem;
public:
    ~HCN();
    HCN();
    HCN(const DIEM&, const DIEM&);
    HCN(double, double, double, double);
    HCN(const HCN&);
    HCN& operator=(const HCN&);
    DIEM GetA() const;
    DIEM GetB() const;
    static int GetDem();
    void SetA(DIEM);
    void SetB(DIEM);
    void Nhap();
    void Xuat() const;
    friend istream& operator>>(istream& in, HCN& hcn);
    friend ostream& operator<<(ostream& out, const HCN& hcn);
    void TinhTien(double, double);
    bool KiemTraHopLe() const;
    double TinhChuVi() const;
    double TinhDienTich() const;
};
int HCN::dem = 0;
HCN::~HCN(){
    --dem;
}
HCN::HCN():A(0, 1), B(1, 0){
    //this->A=A; this->B=B;
    ++dem;
}
HCN::HCN(const DIEM& A, const DIEM& B):A(A), B(B){
    //this->A=A; this->B=B;
    ++dem;
}
HCN::HCN(double xA, double yA, double xB, double yB):A(xA, yA), B(xB, yB){
    //this->A=DIEM(xA, yA); this->B=DIEM(xB, yB);
    ++dem;
}
HCN::HCN(const HCN& hcn) : A(hcn.A), B(hcn.B){
    //this->A=hcn.A; this->B=hcn.B;
    ++dem;
}
HCN& HCN::operator=(const HCN& hcn){
    this->A=hcn.A;
    this->B=hcn.B;
    return *this;
}
DIEM HCN::GetA() const{
    return this->A;
}
DIEM HCN::GetB() const{
    return this->B;
}
int HCN::GetDem(){
    return dem;
}
void HCN::SetA(DIEM A){
    this->A=A;
}
void HCN::SetB(DIEM B){
    this->B=B;
}
void HCN::Nhap(){
    cout<<"Nhap toa do dinh A (goc trai tren) va B (goc phai duoi) cua hinh chu nhat:"<<endl;
    A.Nhap();
    B.Nhap();
}
void HCN::Xuat() const{
    cout<<"Hinh chu nhat qua 2 dinh A("<<A<<"), B("<<B<<")";
}
istream& operator>>(istream& in, HCN& hcn){
    hcn.Nhap();
    return in;
}
ostream& operator<<(ostream& out, const HCN& hcn){
    hcn.Xuat();
    return out;
}
void HCN::TinhTien(double dx, double dy){
    A.TinhTien(dx, dy);
    B.TinhTien(dx, dy);
}
bool HCN::KiemTraHopLe() const{
    return A.GetX()<B.GetX()&&A.GetY()>B.GetY();
}
double HCN::TinhChuVi() const{
    if(!KiemTraHopLe()) return 0;
    double chieuDai=B.GetX()-A.GetX();
    double chieuRong=A.GetY()-B.GetY();
    return 2*(chieuDai + chieuRong);
}
double HCN::TinhDienTich() const{
    if(!KiemTraHopLe()) return 0;
    double chieuDai=B.GetX()-A.GetX();
    double chieuRong=A.GetY()-B.GetY();
    return chieuDai*chieuRong;
}
int main(){
    cout<<"Co "<<DIEM::GetDem()<<" diem\n";
    cout<<"Co "<<HCN::GetDem()<<" hinh chu nhat\n";
    DIEM A(0, 2), B(4, 0);
    HCN hcn1, hcn2(A, B), hcn3(1, 3, 5, 1), hcn4;
    cout<<"Co "<<DIEM::GetDem()<<" diem\n";
    cout<<"Co "<<HCN::GetDem()<<" hinh chu nhat\n";
    cout<<"Toa do 2 dinh cua cac hinh chu nhat:\n";
    cout<<hcn1<<endl<<hcn2<<endl<<hcn3<<endl<<hcn4<<endl;
    cout<<hcn1<<" => Hop le: "<<(hcn1.KiemTraHopLe()?"Co":"Khong")<<" Chu vi: "<<hcn1.TinhChuVi()<<" Dien tich: "<<hcn1.TinhDienTich()<<endl;
    cout<<hcn2<<" => Hop le: "<<(hcn2.KiemTraHopLe()?"Co":"Khong")<<" Chu vi: "<<hcn2.TinhChuVi()<<" Dien tich: "<<hcn2.TinhDienTich()<<endl;
    cout<<hcn3<<" => Hop le: "<<(hcn3.KiemTraHopLe()?"Co":"Khong")<<" Chu vi: "<<hcn3.TinhChuVi()<<" Dien tich: "<<hcn3.TinhDienTich()<<endl;
    cout<<hcn4<<" => Hop le: "<<(hcn4.KiemTraHopLe()?"Co":"Khong")<<" Chu vi: "<<hcn4.TinhChuVi()<<" Dien tich: "<<hcn4.TinhDienTich()<<endl;
    HCN hcn;
    cout<<"Nhap mot hinh chu nhat moi tu ban phim"<<endl;
    hcn.Nhap();
    cout<<"\n=====HINH CHU NHAT VUA NHAP=====\n";
    cout<<hcn<<endl;
    cout<<"Hop le: "<<(hcn.KiemTraHopLe() ? "Co" : "Khong")<<endl;
    cout<<"Chu vi: "<<hcn.TinhChuVi()<<endl;
    cout<<"Dien tich: "<<hcn.TinhDienTich()<<endl;
    double dx, dy;
    cout<<"Nhap do doi theo truc Ox va Oy: ";
    cin>>dx>>dy;
    hcn.TinhTien(dx, dy);
    cout<<"Sau khi tinh tien: ("<<hcn<<")"<<endl;
    cout<<"Hop le: "<<(hcn.KiemTraHopLe() ? "Co" : "Khong")<<endl;
    cout<<"Chu vi: "<<hcn.TinhChuVi()<<endl;
    cout<<"Dien tich: "<<hcn.TinhDienTich()<<endl;
    hcn4=hcn3=hcn2=hcn1;
    cout<<"\nToa do 2 dinh cua hinh chu nhat sau phep gan: \n";
    cout<<hcn1<<endl<<hcn2<<endl<<hcn3<<endl<<hcn4<<endl;
    cout<<hcn1<<" => Hop le: "<<(hcn1.KiemTraHopLe()?"Co":"Khong")<<" Chu vi: "<<hcn1.TinhChuVi()<<" Dien tich: "<<hcn1.TinhDienTich()<<endl;
    cout<<hcn2<<" => Hop le: "<<(hcn2.KiemTraHopLe()?"Co":"Khong")<<" Chu vi: "<<hcn2.TinhChuVi()<<" Dien tich: "<<hcn2.TinhDienTich()<<endl;
    cout<<hcn3<<" => Hop le: "<<(hcn3.KiemTraHopLe()?"Co":"Khong")<<" Chu vi: "<<hcn3.TinhChuVi()<<" Dien tich: "<<hcn3.TinhDienTich()<<endl;
    cout<<hcn4<<" => Hop le: "<<(hcn4.KiemTraHopLe()?"Co":"Khong")<<" Chu vi: "<<hcn4.TinhChuVi()<<" Dien tich: "<<hcn4.TinhDienTich()<<endl;
    cout<<"\nSo luong cuoi cung:\n";
    cout<<"So diem: " <<DIEM::GetDem()<<endl;
    cout<<"So hinh chu nhat: "<<HCN::GetDem()<<endl;
    return 0;
}