#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct hanghoa
{
    int kiemtra;
    // kiểm tra = 0 thì là kiện không lỗi, còn 1 là lỗi
    char maloi[5];
    char ID[100];
    int chieudai, chieucao, chieurong;
    double trongluongtinhphi, trongluongtinh, trongluongquydoi;
    long int tinhtienvanchuyen;
    int loaivanchuyen;
    // 1 vận chuyển nhanh, 0 vận chuyển thường
} hanghoa;
int keykiemtra = 0;
// keykiemtra = 0 thì chưa kiểm tra, key bằng 1 thì đã kiểm tra
// hàm chuyển đổi đẻ tính trong luong tinh phi
double hamMax(double a, double b)
{
    if (a > b)
        return a;
    return b;
}
void kiemtra(hanghoa buupham[], int n)
{
    // kiểm tra tất cả các kiện hàng
    for (int i = 0; i < n; i++)
    {
        int tong = buupham[i].chieudai + buupham[i].chieurong + buupham[i].chieucao;
        // kiểm tra = 0 thì là kiện không lỗi, còn 1 là lỗi
        buupham[i].kiemtra = 0;
        // nếu L+W+H < 10 thì lỗi ER1
        if (tong < 10 && buupham[i].kiemtra == 0)
        {
            strcpy(buupham[i].maloi, "ER1");
            buupham[i].kiemtra = 1;
        }
        // nếu L+W+H > 150 thì lỗi ER2
        if (tong > 150 && buupham[i].kiemtra == 0)
        {
            strcpy(buupham[i].maloi, "ER2");
            buupham[i].kiemtra = 1;
        }
        // nếu trong luong tinh > 30 thì lỗi ER3
        if (buupham[i].trongluongtinh > 30 && buupham[i].kiemtra == 0)
        {
            strcpy(buupham[i].maloi, "ER3");
            buupham[i].kiemtra = 1;
        }
    }
}
int dem = 0;

void inloi(hanghoa buupham[], int n)
{

    printf("\nChi tiet kien hang bi tu choi ");
    printf("\n==========================================");
    printf("\n%-15s %-20s", "Ma Kien", " Ly do tu choi");
    dem = 0;
    for (int i = 0; i < n; ++i)
    {
        if (buupham[i].kiemtra == 1)
        {
            printf("\n%-15s %-20s", buupham[i].ID, buupham[i].maloi);
            dem++;
        }
    }
    printf("\n==========================================");
    printf("\nTong So: %d\n", dem);
}

double lamtron(double x)
{
    int check = x; // lúc này check sẽ bằng phần nguyên của x
    if (x == check)
        return x;
    else
    {
        if (x <= check + 0.5)
            return check + 0.5;
        return check + 1;
    }
}

void trongluongtinhphihanghoa(hanghoa buupham[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int tong = buupham[i].chieucao + buupham[i].chieudai + buupham[i].chieurong;
        if (tong < 80)
        {
            buupham[i].trongluongtinhphi = buupham[i].trongluongtinh;
        }
        else
        {
            double tich = buupham[i].chieucao * buupham[i].chieudai * buupham[i].chieurong;
            if (buupham[i].loaivanchuyen == 0)
                buupham[i].trongluongquydoi = tich / 4000;
            else
                buupham[i].trongluongquydoi = tich / 6000;
        }
        buupham[i].trongluongtinh = lamtron(buupham[i].trongluongtinh);
        buupham[i].trongluongquydoi = lamtron(buupham[i].trongluongquydoi);
        buupham[i].trongluongtinhphi = hamMax(buupham[i].trongluongtinh, buupham[i].trongluongquydoi);
    }
}

void tinhtien(hanghoa buupham[], int n)
{
    trongluongtinhphihanghoa(buupham, n);
    for (int i = 0; i < n; i++)
    {
        if (buupham[i].trongluongtinhphi <= 3)
        {
            if (buupham[i].loaivanchuyen == 0)
                buupham[i].tinhtienvanchuyen = 16500;
            else
                buupham[i].tinhtienvanchuyen = 22000;
        }
        else
        {
            int trongluong = buupham[i].trongluongtinhphi - 3;

            if (buupham[i].loaivanchuyen == 0)
                buupham[i].tinhtienvanchuyen = 16500 + ((buupham[i].trongluongtinhphi - 3) * 2) * 2500;
            else
                buupham[i].tinhtienvanchuyen = 22000 + ((buupham[i].trongluongtinhphi - 3) * 2) * 2500;
        }
    }
}
void inkienhanghople(hanghoa buupham[], int n)
{

    tinhtien(buupham, n);
    dem = 0;
    printf("\nChi tiet kien hang hop le ");
    printf("\n==========================================");
    printf("\n%-15s %-20s %-20s %-20s", "Ma Kien", "Can nang tinh phi", "Hinh thuc van chuyen", "Cuoc phi");
    for (int i = 0; i < n; ++i)
    {
        if (buupham[i].kiemtra == 0)
        {
            if (buupham[i].loaivanchuyen == 0)
            {
                printf("\n%-15s %-20.1lf %-20s %-20ld", buupham[i].ID, buupham[i].trongluongtinhphi, "Chuyen thuong", buupham[i].tinhtienvanchuyen);
                dem++;
            }
            else
            {
                printf("\n%-15s %-20.1lf %-20s %-20ld", buupham[i].ID, buupham[i].trongluongtinhphi, "Chuyen nhanh", buupham[i].tinhtienvanchuyen);
                dem++;
            }
        }
    }
    printf("\n==========================================");
    printf("\nTong So: %d\n", dem);
}
long long int S = 0;

void inphivanchuyen(hanghoa buupham[], int n)
{
    tinhtien(buupham, n);
    for (int i = 0; i < n; i++)
    {
        S = S + buupham[i].tinhtienvanchuyen;
    }
    printf("\n Chi phi van chuyen ");
    printf("\n========================================\n");
    printf("\nSo luong kien da nhan: %d", dem);
    printf("\nTong so tien cuoc %d : ", S);
    long long int VAT = S * 0.08;
    printf("\nVAT: %lld", VAT);
    VAT = VAT + S;
    printf("\nTong chi phi %lld", VAT);
}
void menu()
{
    printf("\n================================");
    printf("\n1) Nhap thong tin kien hang");
    printf("\n2) Chi tiet cac kien hang bi tu choi");
    printf("\n3) Chi tiet cac kien hang bi hop le");
    printf("\n4) Tinh phi van chuyen ");
    printf("\n5) Thoat chuong trinh");
    printf("\n nhap chuc nang ban chon: ");
}

int main()
{
    struct hanghoa buuphamBox[100];
    int n, chucnang;
    int key = 0;
    do
    {
        printf("\nNhap so luong kien hang (1 <= n <= 100) :  ");
        scanf("%d", &n);
    } while (n < 1 || n > 100);
    menu();
    scanf("%d", &chucnang);
    do
    {
        if (chucnang == 1)
        {
            if (key == 0)
            {
                key = 1;
                for (int i = 0; i < n; i++)
                {

                    printf("\n =====================================\n");
                    printf("\nBuu pham so %d : ", i + 1);
                    printf("\nNhap ma buu pham: ");
                    scanf("%s", buuphamBox[i].ID);

                    do
                    {
                        printf("nhap chieu dai: ");
                        scanf("%d", &buuphamBox[i].chieudai);
                        printf("nhap chieu rong: ");
                        scanf("%d", &buuphamBox[i].chieurong);
                        printf("nhap chieu cao: ");
                        scanf("%d", &buuphamBox[i].chieucao);
                    } while (buuphamBox[i].chieudai <= 0 || buuphamBox[i].chieurong <= 0 || buuphamBox[i].chieucao <= 0);

                    do
                    {
                        printf("\nNhap loai van chuyen: ");
                        printf("\n0) chuyen phat thuong \n1) chuyen phat nhanh \n nhap loai van chuyen : ");
                        scanf("%d", &buuphamBox[i].loaivanchuyen);
                    } while (buuphamBox[i].loaivanchuyen > 1 || buuphamBox[i].loaivanchuyen < 0);

                    do
                    {
                        printf("\n Nhap trong luong cua buu pham: ");
                        scanf("%lf", &buuphamBox[i].trongluongtinh);
                    } while (buuphamBox[i].trongluongtinh <= 0);

                    printf("\nbuu pham ban gui so %d \n  Thong tin nhu sau : \n", i + 1);
                    printf("    kich thuoc %d(cm) x %d(cm) x %d(cm) ", buuphamBox[i].chieudai, buuphamBox[i].chieurong, buuphamBox[i].chieucao);
                    if (buuphamBox[i].loaivanchuyen == 0)
                        printf("\n    Chuyen phat thuong ");
                    else
                        printf("\n    Chuyen phat nhanh ");

                    printf("\n    Trong luong goi hang %.2lf kg\n", buuphamBox[i].trongluongtinh);
                }
            }
            else
            {
                system("cls");
                printf("\nBan da nhap so lieu roi, chon chuc nang khac...\n");
            }
        }

        if (chucnang == 2)
        {
            if (key == 0)
            {
                system("cls");
                printf("Chua nhap chuc nang so 1\n");
            }
            else
            {
                if (keykiemtra == 0)
                    kiemtra(buuphamBox, n);
                inloi(buuphamBox, n);
            }
        }
        if (chucnang == 3)
        {
            if (key == 0)
            {
                system("cls");
                printf("Chua nhap chuc nang so 1\n");
            }
            else
            {
                if (keykiemtra == 0)
                    kiemtra(buuphamBox, n);
                inkienhanghople(buuphamBox, n);
            }
        }

        if (chucnang == 4)
        {
            if (key == 0)
            {
                system("cls");
                printf("Chua nhap chuc nang so 1\n");
            }
            else
            {
                inphivanchuyen(buuphamBox, n);
            }
        }
        menu();
        scanf("%d", &chucnang);
    } while (chucnang != 5);

    printf("Chao tam biet!\n");
    return 0;
}