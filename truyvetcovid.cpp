// Hoàng Minh Ngọc 20200440
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct canhan
{
    char diadiem[40];
    int gio;
    int phut;
    struct canhan *next;
    struct canhan *prev;
};
typedef struct canhan list;

list *capphatnutmoi(char diadiem[], int gio, int phut)
{
    list *newnode = (list *)malloc(sizeof(list));
    if (newnode == NULL)
    {
        printf("Cap phat that bai \n");
        // exit(5);
    }
    strcpy(newnode->diadiem, diadiem);
    newnode->gio = gio;
    newnode->phut = phut;
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
}

void giaiphong(list *head)
{
    list *tg = head, *temp1 = NULL;
    while (tg != NULL)
    {
        temp1 = tg->next;
        free(tg);
        tg = temp1;
    }
}
void inds(list *head)
{
    list *tg = head;
    printf("\n");
    printf("\n%-30s%-10s%-10s", "Dia diem", "gio", "phut");
    while (tg != NULL)
    {
        printf("\n%-30s %-10d %-10d ", tg->diadiem, tg->gio, tg->phut);
        tg = tg->next;
    }
}

struct thongtin
{
    char diadiem[40];
    int gio;
    int phut;
};

typedef struct thongtin tt;
tt a[100];
int i = 0;
int chucnang, khoa1 = 0;
void menu()
{

    printf("\nCHUONG TRINH TRUY VET COVID 19\n");
    printf("*************************************************\n");
    printf("******************** MENU ***********************\n");
    printf("** 1) Nhap file log lich su di chuyen          **\n");
    printf("** 2) In ra lich su di chuyen                  **\n");
    printf("** 3) Tim kiem lich su di chuyen theo dia diem **\n");
    printf("** 4) Tim kiem lich su theo thoi gian          **\n");
    printf("** 5) Kiem tra truy vet moi nhat               **\n");
    printf("** 6) Exit                                     **\n");
    printf("*************************************************\n");
    printf("Moi ban chon chuc nang: ");
    scanf("%d", &chucnang);
}

void doc()
{
    FILE *fp = fopen("log.txt", "r");
    if (fp == NULL)
        printf("Doc file that bai\n");
    else
        printf("Doc file thanh cong \n");
    while (!feof(fp))
    {
        fscanf(fp, "%s %d %d", &a[i].diadiem, &a[i].gio, &a[i].phut);
        i++;
    }
    // printf("Nguoi nay di den %d dia diem\n", i);
    // printf("%s", a[8].diadiem);
}

void napdulieu(int soluong, list *head1)
{
    for (int i = 1; i < soluong; i++)
    {
        list *tg;
        tg = capphatnutmoi(a[i].diadiem, a[i].gio, a[i].phut);
        head1->next = tg;
        head1 = head1->next;
    }
}
list *headpro;
int main()
{
    FILE *fp = fopen("log.txt", "r");
    if (fp == NULL)
        printf("Doc file that bai\n");
    else
        printf("Doc file thanh cong \n");

    while (!feof(fp))
    {
        fscanf(fp, "%s %d %d", &a[i].diadiem, &a[i].gio, &a[i].phut);
        i++;
    }

    int soluong = i;
    list *headpro = (list *)malloc(sizeof(list));
    headpro->next = NULL;
    headpro->prev = NULL;
    strcpy(headpro->diadiem, a[0].diadiem);
    headpro->gio = a[0].gio;
    headpro->phut = a[0].phut;
    list *head1 = headpro;
    napdulieu(soluong, head1);
    // duyetds(headpro);
    menu();
    for (;;)
    {
        if (chucnang == 1)
        {
            printf("Chuc nang nap file khoi dong\n");
            khoa1++;
            printf("Nap thanh cong\n");
        }

        if (chucnang == 2)
        {
            if (khoa1 != 0)
            {
                printf("In ra lich su di chuyen: \n");
                if (headpro == NULL)
                    printf("Khong the in");
                else
                    inds(headpro);
            }
            else
                printf("Chua nhap chuc nang 1\n");
        }
        if (chucnang == 3)
        {
            if (khoa1 != 0)
            {
                printf("KHOI DONG CHUONG TRINH TIM KIEM THEO DIA DIEM\n");
                char dd[40];
                printf("Nhap dia diem ban muon truy vet: ");
                scanf("%s", &dd);
                list *tg = headpro;
                int dem = 0;
                while (tg != NULL)
                {
                    if (strcmp(dd, tg->diadiem) == 0)
                    {
                        printf("%d:%d ,", tg->gio, tg->phut);
                        dem++;
                    };
                    tg = tg->next;
                }
                if (dem == 0)
                    printf("Ban chua dem dia diem do\n");
            }
            else
                printf("Chua nhap chuc nang 1\n");
        }
        if (chucnang == 4)
        {
            if (khoa1 != 0)
            {
                printf("KHOI DONG CHUONG TRINH TIM KIEM THEO THOI GIAN\n");
                int h, p;
                do{
                printf("Nhap gio (0 <= gio < 23) : ");
                scanf("%d", &h);
                }while(h<0 || h>23);
                do{
                printf("Nhap phut (0 <= phut <= 59): ");
                scanf("%d", &p);
                }while(p>59|| p<0);
                list *tg = headpro;
                int dem = 0;
                while (tg != NULL)
                {
                    if (tg->gio == h && tg->phut == p)
                    {
                        printf("%s", tg->diadiem);
                        dem++;
                    };
                    tg = tg->next;
                }
                if (dem == 0)
                    printf("Ban chua dem dia diem do\n");
            }
        }
        if (chucnang == 5)
        {
            if (khoa1 != 0)
            {
                int h, p;
                char dd[40];
                printf("Nhap dia diem F0 den: ");
                scanf("%s", &dd);
                do{
                printf("Nhap gio (0 <= gio < 23) : ");
                scanf("%d", &h);
                }while(h<0 || h>23);
                do{
                printf("Nhap phut (0 <= phut <= 59): ");
                scanf("%d", &p);
                }while(p>59|| p<0);
                list *tg = headpro;
                int dem = 0;
                while (tg != NULL)
                {
                    if (strcmp(dd, tg->diadiem) == 0 ) 
                      {
                          if(h < tg->gio || (h==tg->gio && p<tg->phut )) dem++;
                      }

                    tg = tg->next;
                }
                if (dem == 0) printf("Lich su di chuyen cua ban OK\n");
                    else printf("Ban co kha nang bi lay Covid, can phai khai bao y te ngay lap tuc!");

            }
            else
                printf("Chua nhap chuc nang 1");
        }
        if (chucnang == 6)
        {
            printf("Chuong trinh ket thuc, tam biet!!");
            exit(1);
        }
        if (chucnang > 6 || chucnang < 1)
            printf("Nhap lai\n");

        menu();
    }
    // fclose(fp);
    return 0;
}