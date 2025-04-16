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
        bool KiemTraTGHopLe(const DIEM&, const DIEM&) const;
        double TinhChuVi(const DIEM&, const DIEM&) const;
        double TinhDienTich(const DIEM&, const DIEM&) const;
        string PhanLoaiTG(const DIEM&, const DIEM&) const;
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
bool DIEM::KiemTraTGHopLe(const DIEM& d1, const DIEM& d2) const{
    double a=this->TinhKhoangCach(d1);
    double b=d1.TinhKhoangCach(d2);
    double c=d2.TinhKhoangCach(*this);
    return a>0&&b>0&&c>0&&a+b>c&&b+c>a&&a+c>b;
}
double DIEM::TinhChuVi(const DIEM& d1, const DIEM& d2) const{
    double a=this->TinhKhoangCach(d1);
    double b=d1.TinhKhoangCach(d2);
    double c=d2.TinhKhoangCach(*this);
    return KiemTraTGHopLe(d1, d2)?a+b+c:0;
}
double DIEM::TinhDienTich(const DIEM& d1, const DIEM& d2) const{
    double a=this->TinhKhoangCach(d1);
    double b=d1.TinhKhoangCach(d2);
    double c=d2.TinhKhoangCach(*this);
    double p=TinhChuVi(d1, d2)/2;
    return KiemTraTGHopLe(d1, d2)?sqrt(p*(p-a)*(p-b)*(p-c)):0;
}
string DIEM::PhanLoaiTG(const DIEM& d1, const DIEM& d2) const{
    double a=this->TinhKhoangCach(d1);
    double b=d1.TinhKhoangCach(d2);
    double c=d2.TinhKhoangCach(*this);
    if(!KiemTraTGHopLe(d1, d2)) return "TG khong hop le";
    else if(a==b&&b==c) return "TG deu";
    else if(a==b||b==c||c==a){
        if(abs(a*a+b*b-c*c)<=epsilon||abs(a*a+c*c-b*b)<=epsilon||abs(b*b+c*c-a*a)<=epsilon) return "TG vuong can";
        else return "TG can";
    }
    else if(abs(a*a+b*b-c*c)<=epsilon||abs(a*a+c*c-b*b)<=epsilon||abs(b*b+c*c-a*a)<=epsilon) return "TG vuong";
    else return "TG thuong";
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
class TAMGIAC{
    private:
        DIEM A, B, C;
        static int dem;
    public:
        ~TAMGIAC();
        TAMGIAC();
        TAMGIAC(const DIEM&, const DIEM&, const DIEM&);
        TAMGIAC(double, double, double, double, double, double);
        TAMGIAC(const TAMGIAC&);
        TAMGIAC& operator=(const TAMGIAC&);
        DIEM GetA() const;
        DIEM GetB() const;
        DIEM GetC() const;
        static int GetDem();
        void SetA(DIEM);
        void SetB(DIEM);
        void SetC(DIEM);
        void Nhap();
        void Xuat() const;
        friend istream& operator>>(istream& in, TAMGIAC& tg);
        friend ostream& operator<<(ostream& out, const TAMGIAC& tg);
        void TinhTien(double, double);
        bool KiemTraTGHopLe() const;
        double TinhChuVi() const;
        double TinhDienTich() const;
        string PhanLoai() const;
};
int TAMGIAC::dem=0;
TAMGIAC::~TAMGIAC(){
    --dem;
}
TAMGIAC::TAMGIAC():A(0, 1), B(1, 0), C(1, 1){
    ++dem;
}
TAMGIAC::TAMGIAC(const DIEM& A, const DIEM& B, const DIEM& C):A(A), B(B), C(C){
    //this->A=A;
    //this->B=B;
    //this->C=C;
    ++dem;
}
TAMGIAC::TAMGIAC(double xA, double yA, double xB, double yB, double xC, double yC):A(xA, yA), B(xB, yB), C(xC, yC){
    ++dem;
}
TAMGIAC::TAMGIAC(const TAMGIAC& tg):A(tg.A), B(tg.B), C(tg.C){
    //this->A=tg.A;
    //this->B=tg.B;
    //this->C=tg.C;
    ++dem;
}
TAMGIAC& TAMGIAC::operator=(const TAMGIAC& tg){
    this->A=tg.A;
    this->B=tg.B;
    this->C=tg.C;
    return *this;
}
DIEM TAMGIAC::GetA() const{
    return this->A;
}
DIEM TAMGIAC::GetB() const{
    return this->B;
}
DIEM TAMGIAC::GetC() const{
    return this->C;
}
int TAMGIAC::GetDem(){
    return dem;
}
void TAMGIAC::SetA(DIEM A){
    this->A=A;
}
void TAMGIAC::SetB(DIEM B){
    this->B=B;
}
void TAMGIAC::SetC(DIEM C){
    this->C=C;
}
void TAMGIAC::Nhap(){
    cout<<"Nhap lan luot toa do 3 diem cua tam giac: "<<endl;;
    A.Nhap(); B.Nhap(); C.Nhap();
}
void TAMGIAC::Xuat() const{
    cout<<"Tam giac qua 3 dinh A("<<A<<"), B("<<B<<"), C("<<C<<")";
}
istream& operator>>(istream& in, TAMGIAC& tg){
    tg.Nhap();
    return in;
}
ostream& operator<<(ostream& out, const TAMGIAC& tg){
    tg.Xuat();
    return out;
}
void TAMGIAC::TinhTien(double dx, double dy){
    A.TinhTien(dx, dy);
    B.TinhTien(dx, dy);
    C.TinhTien(dx, dy);
}
bool TAMGIAC::KiemTraTGHopLe() const{
    return A.KiemTraTGHopLe(B, C);
}
double TAMGIAC::TinhChuVi() const{
    return A.TinhChuVi(B, C);
}
double TAMGIAC::TinhDienTich() const{
    return A.TinhDienTich(B, C);
}
string TAMGIAC::PhanLoai() const{
    return A.PhanLoaiTG(B, C);
}
int main(){
    cout<<"Co"<<DIEM::GetDem()<<" diem\n";
    cout<<"Co"<<TAMGIAC::GetDem()<<" tam giac\n";
    DIEM A, B(3), C(0, 4);
    TAMGIAC tg1, tg2(A, B, C), tg3(0, 4, -3, 0, 3, 0), tg4;
    cout<<"Co"<<DIEM::GetDem()<<" diem\n";
    cout<<"Co"<<TAMGIAC::GetDem()<<" tam giac\n";
    cout<<"Toa do 3 dinh cua cac tam giac:\n";
    cout<<tg1<<endl<<tg2<<endl<<tg3<<endl<<tg4<<endl;
    cout<<tg1<<" =>"<<tg1.PhanLoai()<<" Chu vi: "<<tg1.TinhChuVi()<<" Dien tich: "<<tg1.TinhDienTich()<<endl;
    cout<<tg2<<" =>"<<tg2.PhanLoai()<<" Chu vi: "<<tg2.TinhChuVi()<<" Dien tich: "<<tg2.TinhDienTich()<<endl;
    cout<<tg3<<" =>"<<tg3.PhanLoai()<<" Chu vi: "<<tg3.TinhChuVi()<<" Dien tich: "<<tg3.TinhDienTich()<<endl;
    cout<<tg4<<" =>"<<tg4.PhanLoai()<<" Chu vi: "<<tg4.TinhChuVi()<<" Dien tich: "<<tg4.TinhDienTich()<<endl;
    TAMGIAC tg;
    cout<<"Nhap mot tam giac moi tu ban phim"<<endl;
    tg.Nhap();
    cout<<"\n=====TAM GIAC VUA NHAP=====\n";
    cout<<tg<<endl;
    cout<<"Phan Loai: "<<tg.PhanLoai()<<endl;
    cout<<"Chu vi: "<<tg.TinhChuVi()<<endl;
    cout<<"Dien tich: "<<tg.TinhDienTich()<<endl;
    DIEM d;
    cout<<"Nhap mot diem tu ban phim"<<endl;
    cin>>d;
    cout<<"\n=====DIEM VUA NHAP=====\n";
    cout<<d<<endl;
    int luaChon;
    double dx, dy, scale;
    int goc;
    cout<<"\n=====CAC PHEP BIEN DOI VOI DIEM=====\n";
    cout<<"1. Tinh tine\n";
    cout<<"2. Phong to\n";
    cout<<"3. Thu nho\n";
    cout<<"4. Xoay\n";
    cout<<"5. Doi xung qua Ox\n";
    cout<<"6. Doi xung qua Oy\n";
    cout<<"7. Doi xung qua goc toa do\n";
    cout<<"Chon phep bien doi (1-7): ";
    cin>>luaChon;
    switch(luaChon){
        case 1:
            cout<<"Nhap do doi theo truc Ox va Oy: ";
            cin>>dx>>dy;
            d.TinhTien(dx, dy);
            cout<<"Sau khi tinh tien: (" <<d<< ")"<<endl;
            break;
        case 2:
            cout<<"Nhap he so phong to: ";
            cin>>scale;
            d.PhongTo(scale);
            cout<<"Sau khi phong to: (" <<d<< ")"<<endl;
            break;
        case 3:
            cout<<"Nhap he so thu nho: ";
            cin>>scale;
            d.ThuNho(scale);
            cout<<"Sau khi thu nho: (" <<d<< ")"<<endl;
            break;
        case 4:
            cout<<"Nhap goc xoay (do): ";
            cin>>goc;
            d.Quay(goc);
            cout<<"Sau khi xoay "<<goc<<" đo: (" <<d<< ")"<<endl;
            break;
        case 5:
            d.DoiXungOx();
            cout<<"Sau khi doi xung qua Ox: (" <<d<< ")"<<endl;
            break;
        case 6:
            d.DoiXungOy();
            cout<<"Sau khi doi xung qua Oy: (" <<d<< ")"<<endl;
            break;
        case 7:
            d.DoiXungGoc();
            cout<<"Sau khi doi xung qua goc toa do: (" <<d<< ")"<<endl;
            break;
        default:
            cout<<"Lua chon khong hop le"<<endl;
    }
    DIEM d1, d2, d3;
    cout<<"\nNhap toa do 3 diem de kiem tra tam giac:\n";
    cout<<"Nhap diem thu nhat:\n";
    d1.Nhap();
    cout<<"Nhap diem thu hai:\n";
    d2.Nhap();
    cout<<"Nhap diem thu ba:\n";
    d3.Nhap();
    TAMGIAC tgKiemTra(d1, d2, d3);
    cout<<"\nTam giac qua 3 diem vua nhap:\n";
    cout<<tgKiemTra<<endl;
    if(tgKiemTra.KiemTraTGHopLe()){
        cout<<"Day la tam giac hop le.\n";
        cout<<"Phan loai: "<<tgKiemTra.PhanLoai()<<endl;
        cout<<"Chu vi: " <<tgKiemTra.TinhChuVi()<<endl;
        cout<<"Dien tich: "<<tgKiemTra.TinhDienTich()<<endl;
    } 
    else{
        cout<<"Ba diem vua nhap khong tao thanh tam giac hop le.\n";
    }
    tg4=tg3=tg2=tg1;
    cout<<"\nToa do 3 dinh cua tam giac sau phep gan: \n";
    cout<<tg1<<endl<<tg2<<endl<<tg3<<endl<<tg4<<endl;
    cout<<tg1<<" => "<<tg1.PhanLoai()<<" Chu vi: "<<tg1.TinhChuVi()<<" Dien tich: "<<tg1.TinhDienTich()<<endl;
    cout<<tg2<<" => "<<tg2.PhanLoai()<<" Chu vi: "<<tg2.TinhChuVi()<<" Dien tich: "<<tg2.TinhDienTich()<<endl;
    cout<<tg3<<" => "<<tg3.PhanLoai()<<" Chu vi: "<<tg3.TinhChuVi()<<" Dien tich: "<<tg3.TinhDienTich()<<endl;
    cout<<tg4<<" => "<<tg4.PhanLoai()<<" Chu vi: "<<tg4.TinhChuVi()<<" Dien tich: "<<tg4.TinhDienTich()<<endl;
    cout<<"\nSo luong cuoi cung:\n";
    cout<<"So diem: "<<DIEM::GetDem()<<endl;
    cout<<"So tam giac: "<<TAMGIAC::GetDem()<<endl;
    return 0;
}