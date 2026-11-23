
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

struct NGAY {
    int Ngay, Thang, Nam;
};
struct SINHVIEN {
    string MASV;
    string HoTen;
    NGAY NgaySinh;
    char GioiTinh;
    float DiemToan, DiemLy, DiemHoa, DTB;
};
struct NODE {
    SINHVIEN key;
    NODE* pNext;
};
struct LIST {
    NODE* pHead, * pTail;
};

void NhapNgay(NGAY&);
void XuatNgay(NGAY);
void NhapSinhVien(SINHVIEN&);
void XuatSinhVien(SINHVIEN);
NODE* CreateNode(SINHVIEN);
void CreateEmptyList(LIST&);
void AddTail(LIST&, NODE*);
void XuatDS(LIST);
void NhapDS(LIST&, int n);
bool RemoveHead(LIST&);
bool RemoveAfterQ(LIST&, NODE*, string);
bool Xoa_TheoHoTen(LIST&, string);

int main() {
    LIST L;
    int n;
    string hoten;

    getline(cin, hoten);
    cin >> n;

    NhapDS(L, n);

    Xoa_TheoHoTen(L, hoten);

    XuatDS(L);

    return 0;
}
void NhapNgay(NGAY& a) {
    cin >> a.Ngay >> a.Thang >> a.Nam;
}
void XuatNgay(NGAY a) {
    cout << a.Ngay << "/" << a.Thang << "/" << a.Nam;
}
void NhapSinhVien(SINHVIEN& a) {
    cin >> ws;
    getline(cin, a.MASV);
    getline(cin, a.HoTen);
    NhapNgay(a.NgaySinh);
    cin >> a.GioiTinh;
    cin >> a.DiemToan >> a.DiemLy >> a.DiemHoa;
    a.DTB = (a.DiemToan + a.DiemLy + a.DiemHoa) / 3;
}
void XuatSinhVien(SINHVIEN a) {
    cout << a.MASV;         cout << "\t";
    cout << a.HoTen;        cout << "\t";
    XuatNgay(a.NgaySinh);   cout << "\t";
    cout << a.GioiTinh;     cout << "\t";
    cout << a.DiemToan;     cout << "\t";
    cout << a.DiemLy;       cout << "\t";
    cout << a.DiemHoa;      cout << "\t";
    cout << setprecision(3);
    cout << a.DTB;
}
NODE* CreateNode(SINHVIEN x) {
    NODE* p = new NODE;
    p->key = x;
    p->pNext = NULL;
    return p;
}
void CreateEmptyList(LIST& L) {
    L.pHead = L.pTail = NULL;
}
void AddTail(LIST& l, NODE* p) {
    if (l.pHead == NULL) {
        l.pHead = l.pTail = p;
        return;
    }
    l.pTail->pNext = p;
    l.pTail = p;
}
void NhapDS(LIST& L, int n) {
    SINHVIEN sv;
    CreateEmptyList(L);
    for (int i = 0; i < n; i++) {
        NhapSinhVien(sv);
        AddTail(L, CreateNode(sv));
    }
}
void XuatDS(LIST L) {
    if (L.pHead == NULL) { cout << "Empty List."; return; }
    NODE* p = L.pHead;
    while (p) {
        XuatSinhVien(p->key);
        cout << endl;
        p = p->pNext;
    }
}

bool RemoveHead(LIST& L)
{
    if (L.pHead == NULL) return false;
    NODE* t = L.pHead;
    L.pHead = L.pHead->pNext;
    if (L.pHead == NULL) L.pTail = NULL;
    delete t;
    return true;
}

bool RemoveAfterQ(LIST& L, NODE* q, string ten)
{
    if (q == NULL || q->pNext == NULL) return false;
    NODE* t = q->pNext;
    if (t->key.HoTen != ten) return false;
    q->pNext = t->pNext;
    if (t == L.pTail) L.pTail = q;
    delete t;
    return true;
}

bool Xoa_TheoHoTen(LIST& L, string ten)
{
    bool daXoa = false;                  
    while (L.pHead != NULL && L.pHead->key.HoTen == ten)
    {
        RemoveHead(L);
        daXoa = true;
    }
    if (L.pHead == NULL) return daXoa;      
    NODE* q = L.pHead;
    while (q->pNext != NULL)
    {
        if (q->pNext->key.HoTen == ten)
        {
            RemoveAfterQ(L, q, ten);          
            daXoa = true;
        }
        else
            q = q->pNext;                    
    }
    return daXoa;
}