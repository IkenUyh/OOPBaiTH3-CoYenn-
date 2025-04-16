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
class HTRON {
private:
    DIEM O; 
    double R; 
    static int dem;
public:
    ~HTRON();
    HTRON();
    HTRON(const DIEM&, double);
    HTRON(double, double, double);
    HTRON(const HTRON&);
    HTRON& operator=(const HTRON&);
    DIEM GetO() const;
    double GetR() const;
    static int GetDem();
    void SetO(DIEM);
    void SetR(double);
    void Nhap();
    void Xuat() const;
    friend istream& operator>>(istream& in, HTRON& ht);
    friend ostream& operator<<(ostream& out, const HTRON& ht);
    void TinhTien(double, double);
    bool KiemTraHopLe() const;
    double TinhChuVi() const;
    double TinhDienTich() const;
};
int HTRON::dem=0;
HTRON::~HTRON(){
    --dem;
}
HTRON::HTRON():O(0, 0), R(1){
    //this->O = O; this->R = R;
    ++dem;
}
HTRON::HTRON(const DIEM& O, double R):O(O), R(R){
    //this->O = O; this->R = R;
    ++dem;
}
HTRON::HTRON(double xO, double yO, double R):O(xO, yO), R(R){
    //this->O = DIEM(xO, yO); this->R = R;
    ++dem;
}
HTRON::HTRON(const HTRON& ht):O(ht.O), R(ht.R){
    //this->O = ht.O; this->R = ht.R;
    ++dem;
}
HTRON& HTRON::operator=(const HTRON& ht){
    this->O=ht.O;
    this->R=ht.R;
    return *this;
}
DIEM HTRON::GetO() const{
    return this->O;
}
double HTRON::GetR() const{
    return this->R;
}
int HTRON::GetDem(){
    return dem;
}
void HTRON::SetO(DIEM O){
    this->O=O;
}
void HTRON::SetR(double R){
    this->R=R;
}
void HTRON::Nhap(){
    cout<<"Nhap toa do tam O va ban kinh R cua hinh tron:"<<endl;
    O.Nhap();
    cout<<"Nhap ban kinh: ";
    cin>>R;
}
void HTRON::Xuat() const{
    cout<<"Hinh tron tam O("<<O<<"), ban kinh R = "<<fixed<<setprecision(2)<<R;
}
istream& operator>>(istream& in, HTRON& ht){
    ht.Nhap();
    return in;
}
ostream& operator<<(ostream& out, const HTRON& ht){
    ht.Xuat();
    return out;
}
void HTRON::TinhTien(double dx, double dy){
    O.TinhTien(dx, dy);
}
bool HTRON::KiemTraHopLe() const{
    return R>0;
}
double HTRON::TinhChuVi() const{
    if(!KiemTraHopLe()) return 0;
    return 2*pi*R;
}
double HTRON::TinhDienTich() const{
    if(!KiemTraHopLe()) return 0;
    return pi*R*R;
}
int main() {
    cout << "Co " << DIEM::GetDem() << " diem\n";
    cout << "Co " << HTRON::GetDem() << " hinh tron\n";
    DIEM O(1, 1);
    HTRON ht1, ht2(O, 2), ht3(0, 0, 3), ht4;
    cout << "Co " << DIEM::GetDem() << " diem\n";
    cout << "Co " << HTRON::GetDem() << " hinh tron\n";
    cout << "Thong tin cac hinh tron:\n";
    cout << ht1 << endl << ht2 << endl << ht3 << endl << ht4 << endl;
    cout << ht1 << " => Hop le: " << (ht1.KiemTraHopLe() ? "Co" : "Khong") << " Chu vi: " << ht1.TinhChuVi() << " Dien tich: " << ht1.TinhDienTich() << endl;
    cout << ht2 << " => Hop le: " << (ht2.KiemTraHopLe() ? "Co" : "Khong") << " Chu vi: " << ht2.TinhChuVi() << " Dien tich: " << ht2.TinhDienTich() << endl;
    cout << ht3 << " => Hop le: " << (ht3.KiemTraHopLe() ? "Co" : "Khong") << " Chu vi: " << ht3.TinhChuVi() << " Dien tich: " << ht3.TinhDienTich() << endl;
    cout << ht4 << " => Hop le: " << (ht4.KiemTraHopLe() ? "Co" : "Khong") << " Chu vi: " << ht4.TinhChuVi() << " Dien tich: " << ht4.TinhDienTich() << endl;
    HTRON ht;
    cout << "Nhap mot hinh tron moi tu ban phim" << endl;
    ht.Nhap();
    cout << "\n=====HINH TRON VUA NHAP=====\n";
    cout << ht << endl;
    cout << "Hop le: " << (ht.KiemTraHopLe() ? "Co" : "Khong") << endl;
    cout << "Chu vi: " << ht.TinhChuVi() << endl;
    cout << "Dien tich: " << ht.TinhDienTich() << endl;
    double dx, dy;
    cout << "Nhap do doi theo truc Ox va Oy: ";
    cin >> dx >> dy;
    ht.TinhTien(dx, dy);
    cout << "Sau khi tinh tien: (" << ht << ")" << endl;
    cout << "Hop le: " << (ht.KiemTraHopLe() ? "Co" : "Khong") << endl;
    cout << "Chu vi: " << ht.TinhChuVi() << endl;
    cout << "Dien tich: " << ht.TinhDienTich() << endl;
    ht4 = ht3 = ht2 = ht1;
    cout << "\nThong tin cac hinh tron sau phep gan: \n";
    cout << ht1 << endl << ht2 << endl << ht3 << endl << ht4 << endl;
    cout << ht1 << " => Hop le: " << (ht1.KiemTraHopLe() ? "Co" : "Khong") << " Chu vi: " << ht1.TinhChuVi() << " Dien tich: " << ht1.TinhDienTich() << endl;
    cout << ht2 << " => Hop le: " << (ht2.KiemTraHopLe() ? "Co" : "Khong") << " Chu vi: " << ht2.TinhChuVi() << " Dien tich: " << ht2.TinhDienTich() << endl;
    cout << ht3 << " => Hop le: " << (ht3.KiemTraHopLe() ? "Co" : "Khong") << " Chu vi: " << ht3.TinhChuVi() << " Dien tich: " << ht3.TinhDienTich() << endl;
    cout << ht4 << " => Hop le: " << (ht4.KiemTraHopLe() ? "Co" : "Khong") << " Chu vi: " << ht4.TinhChuVi() << " Dien tich: " << ht4.TinhDienTich() << endl;
    cout << "\nSo luong cuoi cung:\n";
    cout << "So diem: " << DIEM::GetDem() << endl;
    cout << "So hinh tron: " << HTRON::GetDem() << endl;
    return 0;
}