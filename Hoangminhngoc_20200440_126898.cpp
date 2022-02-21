// Trường Công Nghệ Thông Tin và Truyền Thông - Đại Học Bách Khoa Hà Nội
// Học phần IT3230 - Lập trình C cơ bản - Giảng Viên Trần Hồng Việt
// Hoàng Minh Ngọc 20200440 Việt Nhật 05 - K65
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct dulieu
{
    char name[4];
    double mocua;
    double dongcua;
};
typedef struct dulieu dl;
dl a[500];
int i = 0, socophieu = 0;

int chucnang, khoa1 = 0;
void menu()
{

    printf("\nTHEO DOI CO PHIEU \n");
    printf("*************************************************\n");
    printf("******************** MENU ***********************\n");
    printf("** 1) Nhap file du lieu                        **\n");
    printf("** 2) Tim kiem theo ma chung khoan             **\n");
    printf("** 3) Tim kiem ma chung khoan su huong tang    **\n");
    printf("** 4) Tim kiem ma co so ngay tang lon nhat     **\n");
    printf("** 5) Exit                                     **\n");
    printf("*************************************************\n");
    printf("Moi ban chon chuc nang: ");
    scanf("%d", &chucnang);
}
int main()
{
    FILE *fp = fopen("data.txt", "r");
    if (fp == NULL)
        printf("Doc file that bai");
    int soluong;
    fscanf(fp, "%d", &soluong);
    while (!(feof(fp)))
    {
        fscanf(fp, "%s\t%lf\t%lf", &a[i].name, &a[i].mocua, &a[i].dongcua);
        i++;
    }
    int socophieu = i;
    menu();
    for (;;)
    {
        if (chucnang == 1)
        {
            system("cls");
            printf("Doc file du lieu thanh cong\n");
            printf("Co tat ca %d ma co phieu ", socophieu);
            khoa1++;
        }
        if (chucnang == 2)
        {
            if (khoa1 == 0)
            {
                printf("Chua nap du lieu, vui long chon chuc nang 1\n");
            }
            else
            {
                system("cls");
                printf("Nhap ma co phieu can tim: ");
                char maco[4];
                double MAX = 0, MIN = 0;
                scanf("%s", &maco);
                for (int i = 0; i < socophieu; i++)
                {
                    if (strcmp(maco, a[i].name) == 0)
                    {
                        MAX = a[i].dongcua;
                        MIN = MAX;
                        break;
                    }
                }
                if (MAX == 0)
                    printf("Khong tim thay ma co phieu do\n");
                else
                {
                    for (int i = 0; i < socophieu; i++)
                    {
                        if (strcmp(maco, a[i].name) == 0)
                        {
                            if (MAX < a[i].dongcua)
                                MAX = a[i].dongcua;
                            if ((MIN - a[i].dongcua) > 0)
                                MIN = a[i].dongcua;
                        }
                    }
                    printf("Ma co phieu %s co gia Max = %.3lf, gia MIN = %.3lf", maco, MAX, MIN);
                }
            }
        }
        if (chucnang == 3)
        {
            if (khoa1 == 0)
                printf("Chua nap du lieu, vui long chon chuc nang 1\n");
            else
            {
                double MAX1 = 0, MAX2 = 0;
                system("cls");
                for (int i = 0; i < 7; i++)
                {
                    MAX1 = a[i].dongcua - a[i].mocua;
                    for (int j = 7; j < 14; j++)
                    {
                        if (strcmp(a[i].name, a[j].name) == 0)
                        {
                            MAX2 = a[j].dongcua - a[j].mocua;
                        }
                        if (MAX1 > 0 && MAX2 > 0)
                            printf("Ngay 1(%s %.3lf %.3lf) va Ngay 2(%s %.3lf %.3lf)", a[i].name, a[i].mocua, a[i].dongcua, a[j].name, a[j].mocua, a[j].dongcua);
                    }
                }
            }
        }
        if (chucnang == 4)
        {
            if (khoa1 == 0)
                printf("Chua nap du lieu, vui long chon chuc nang 1\n");
            else
            {
                double MAX1 = a[0].dongcua - a[0].mocua,
                       MAX2 = a[1].dongcua - a[1].mocua,
                       MAX3 = a[2].dongcua - a[2].mocua,
                       MAX4 = a[4].dongcua - a[3].mocua,
                       MAX5 = a[4].dongcua - a[4].mocua,
                       MAX6 = a[5].dongcua - a[5].mocua,
                       MAX7 = a[6].dongcua - a[6].mocua;
                int vt1 = 0, vt2 = 0, vt3 = 0, vt4 = 0, vt5 = 0, vt6 = 0, vt7 = 0;
                char ma1[4], ma2[4], ma3[4], ma4[4], ma5[4], ma6[4], ma7[4];
                strcpy(ma1, a[0].name);
                strcpy(ma2, a[1].name);
                strcpy(ma3, a[2].name);
                strcpy(ma4, a[3].name);
                strcpy(ma5, a[4].name);
                strcpy(ma6, a[5].name);
                strcpy(ma7, a[6].name);
                for (int i = 7; i < socophieu; i++)
                {
                    if (strcmp(ma1, a[i].name) == 0)
                    {
                        if (MAX1 > 0)
                            vt1++;
                        MAX1 = a[i].dongcua - a[i].mocua;
                    }
                    if (strcmp(ma2, a[i].name) == 0)
                    {
                        if (MAX2 > 0)
                            vt2++;
                        MAX2 = a[i].dongcua - a[i].mocua;
                    }
                    if (strcmp(ma3, a[i].name) == 0)
                    {
                        if (MAX3 > 0)
                            vt3++;
                        MAX3 = a[i].dongcua - a[i].mocua;
                    }
                    if (strcmp(ma4, a[i].name) == 0)
                    {
                        if (MAX4 > 0)
                            vt4++;
                        MAX4 = a[i].dongcua - a[i].mocua;
                    }
                    if (strcmp(ma5, a[i].name) == 0)
                    {
                        if (MAX5 > 0)
                            vt5++;
                        MAX5 = a[i].dongcua - a[i].mocua;
                    }
                    if (strcmp(ma6, a[i].name) == 0)
                    {
                        if (MAX6 > 0)
                            vt6++;
                        MAX6 = a[i].dongcua - a[i].mocua;
                    }
                    if (strcmp(ma7, a[i].name) == 0)
                    {
                        if (MAX7 > 0)
                            vt7++;
                        MAX7 = a[i].dongcua - a[i].mocua;
                    }
                }
                int MAX = vt1, vt = 0;
                if (MAX < vt2)
                {
                    MAX = vt2;
                    vt = 2;
                }
                if (MAX < vt3)
                {
                    MAX = vt3;
                    vt = 3;
                }
                if (MAX < vt4)
                {
                    MAX = vt4;
                    vt = 4;
                }
                if (MAX < vt5)
                {
                    MAX = vt5;
                    vt = 5;
                }
                if (MAX < vt6)
                {
                    MAX = vt6;
                    vt = 6;
                }
                if (MAX < vt7)
                {
                    MAX = vt7;
                    vt = 7;
                }

                if (MAX == vt1)
                {
                    printf("Ma %s co %d ngay cao nhat\n", ma1, MAX);
                }
                if (MAX == vt2)
                {
                    printf("Ma %s co %d ngay cao nhat\n", ma2, MAX);
                }
                if (MAX == vt3)
                {
                    printf("Ma %s co %d ngay cao nhat\n", ma3, MAX);
                }
                if (MAX == vt4)
                {
                    printf("Ma %s co %d ngay cao nhat\n", ma4, MAX);
                }
                if (MAX == vt5)
                {
                    printf("Ma %s co %d ngay cao nhat\n", ma5, MAX);
                }
                if (MAX == vt6)
                {
                    printf("Ma %s co %d ngay cao nhat\n", ma6, MAX);
                }

                if (MAX == vt7)
                {
                    printf("Ma %s co %d ngay cao nhat\n", ma7, MAX);
                }
            }
        }

        if (chucnang == 5)
        {
            system("cls");
            printf("Hoang Minh Ngoc 20200440 \n");
            printf("Than ai, chao tam biet \n");
            exit(1);
        }
        if (chucnang < 1 || chucnang > 5)
        {
            system("cls");
            printf("Nhap loi!, nhap lai");
        }

        menu();
    }
    free(fp);
    return 0;
}