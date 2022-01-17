
//#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
typedef struct thisinh
{
	int ID;
	char Nation[4];
	char Name[31];
	double kq[3];
	double FR;

} thisinh;
struct thisinh vdv[20], tg;
int chuongtrinh, n;
void Menu()
{
	printf("\n");
	printf("******************************************************\n");
	printf("*                 MENU DIEU HUONG                    *\n");
	printf("* 1) DANG KI VAN DONG VIEN                           *\n");
	printf("* 2) IN BANG THI DAU                                 *\n");
	printf("* 3) NHAP DU LIEU THI                                *\n");
	printf("* 4) TIM KIEM THEO QUOC GIA / TEN VDV                *\n");
	printf("* 5) IN KET QUA THEO FR                              *\n");
	printf("* 6) EXIT                                            *\n");
	printf("******************************************************\n");
	printf("Nhap chuong trinh ban chon: ");
	scanf("%d", &chuongtrinh);
}
void Menu1()
{
	printf("Nhap so luong thi sinh: ");
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		printf("ID: %d\n", i + 1);
		vdv[i].ID = i + 1;
		printf("Nhap Quoc Gia: ");
		scanf("%s", &vdv[i].Nation);
		printf("Nhap ten van dong vien: ");
		fflush(stdin);
		gets(vdv[i].Name);
	}
}
void Menu2()
{
	printf("\nDanh sach truoc thi dau la : \n");
	printf("\n %-5s %-8s %-20s %-5s %-5s %-5s %-5s\n", "ID", "Nation", "Name", "R1", "R2", "R3", "PR");
	for (int i = 0; i < n; i++)
		printf("\n%-5d %-8s %-20s ", vdv[i].ID, vdv[i].Nation, vdv[i].Name);
}
void Menu3()
{
	printf("Luot thi dau thu nhat:  \n");
	for (int i = 0; i < n; i++)
	{
		printf("ID %d ket qua = ", i + 1);
		scanf("%lf", &vdv[i].kq[0]);
		while (vdv[i].kq[0] < 0 || vdv[i].kq[0] > 20)
		{
			printf("Nhap lai ket qua 0<kq<20: ");
			scanf("%lf", &vdv[i].kq[0]);
		}
		vdv[i].FR = vdv[i].kq[0];
	}
	printf("\nKet qua thi dau hiep thu nhat : \n");
	printf("\n %-5s %-8s %-20s %-5s %-5s %-5s %-5s\n", "ID", "Nation", "Name", "R1", "R2", "R3", "PR");
	for (int i = 0; i < n; i++)
		printf("\n%-5d %-8s %-20s %-5.2lf ", vdv[i].ID, vdv[i].Nation, vdv[i].Name, vdv[i].kq[0]);
	printf("\n Luot thi dau thu hai: \n");
	for (int i = 0; i < n; i++)
	{
		printf("ID %d ket qua = ", i + 1);
		scanf("%lf", &vdv[i].kq[1]);
		while (vdv[i].kq[1] < 0 || vdv[i].kq[1] > 20)
		{
			printf("Nhap lai ket qua 0<kq<20: ");
			scanf("%lf", &vdv[i].kq[1]);
		}
		if (vdv[i].kq[1] > vdv[i].FR)
			vdv[i].FR = vdv[i].kq[1];
	}
	printf("\nKet qua thi dau hiep thu hai : \n");
	printf("\n %-5s %-8s %-20s %-5s %-5s %-5s %-5s\n", "ID", "Nation", "Name", "R1", "R2", "R3", "PR");
	for (int i = 0; i < n; i++)
		printf("\n%-5d %-8s %-20s %-5.2lf %-5.2lf ", vdv[i].ID, vdv[i].Nation, vdv[i].Name, vdv[i].kq[0], vdv[i].kq[1]);

	printf("\nLuot thi dau thu ba \n");
	for (int i = 0; i < n; i++)
	{
		printf("ID %d ket qua = ", i + 1);
		scanf("%lf", &vdv[i].kq[2]);
		while (vdv[i].kq[2] < 0 || vdv[i].kq[2] > 20)
		{
			printf("Nhap lai ket qua 0 < kq < 20: ");
			scanf("%lf", &vdv[i].kq[2]);
		}
		if (vdv[i].kq[2] > vdv[i].FR)
			vdv[i].FR = vdv[i].kq[2];
	}

	printf("\nKet qua thi dau : \n");
	printf("\n %-5s %-8s %-20s %-5s %-5s %-5s %-5s\n", "ID", "Nation", "Name", "R1", "R2", "R3", "PR");
	for (int i = 0; i < n; i++)
		printf("\n%-5d %-8s %-20s %-5.2lf %-5.2lf %-5.2lf %-5.2lf ",
			   vdv[i].ID, vdv[i].Nation, vdv[i].Name, vdv[i].kq[0], vdv[i].kq[1], vdv[i].kq[2], vdv[i].FR);
}
void Menu4()
{
	int chuongtrinhcon;
	printf("Menu tim kiem \n");
	printf("1) Tim theo ten \n");
	printf("2) Tim theo quoc gia \n");
	do
	{
		printf("Chuc nang ban chon: ");
		scanf("%d", &chuongtrinhcon);
	} while (chuongtrinhcon < 1 || chuongtrinhcon > 2);

	if (chuongtrinhcon == 1)
	{
		char timten[31];
		printf("\n Tim kiem theo Ten duoc khoi dong \n");
		printf("Nhap ten ban can tim: \n");
		fflush(stdin);
		gets(timten);
		int max, d = 0;
		for (int i = 0; i < n; i++)
		{
			max = strcmp(timten, vdv[i].Name);
			if (max = 0)
			{
				printf("%s\n", vdv[i].Name);
				d++;
			}
		}
		if (d == 0)
			printf("Khong tim thay ten\n");
	}
	if (chuongtrinhcon == 2)
	{
		char timQG[4];
		printf("\n Tim kiem theo Quoc Gia duoc khoi dong \n");
		printf("Nhap QG ban can tim: \n");
		fflush(stdin);
		gets(timQG);
		int max, d = 0;
		for (int i = 0; i < n; i++)
		{
			max = strcmp(timQG, vdv[i].Nation);
			if (max = 0)
			{
				printf("%s\n", vdv[i].Nation);
				d++;
			}
		}
		if (d == 0)
			printf("Khong tim thay ten Quoc Gia\n");
	}
}
void Menu5()
{
	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++)
			if (vdv[i].FR < vdv[j].FR)
			{
				tg = vdv[i];
				vdv[i] = vdv[j];
				vdv[j] = tg;
			}
	printf("Ket qua duoc sap xep \n");
	printf("\n %-5s %-8s %-20s %-5s %-5s %-5s %-5s\n", "ID", "Nation", "Name", "R1", "R2", "R3", "PR");
	for (int i = 0; i < n; i++)
		printf("\n%-5d %-8s %-20s %-5.2lf %-5.2lf %-5.2lf %-5.2lf ",
			   vdv[i].ID, vdv[i].Nation, vdv[i].Name, vdv[i].kq[0], vdv[i].kq[1], vdv[i].kq[2], vdv[i].FR);
}
int main()
{
	Menu();
	while (chuongtrinh != 1)
	{
		printf("\nNhap lai Menu, ban chua khai bao van dong vien\n");
		Menu();
	}
	Menu1();
	int khoa1 = 0, khoa3 = 0;
	Menu();
	do
	{
		if (chuongtrinh == 1)
		{
			printf("\nBan da nhap chuc nang nay\n");
		}
		if (chuongtrinh == 2)
		{
			Menu2();
		}
		if (chuongtrinh == 3 && khoa3 == 0)
		{
			khoa3++;
			Menu3();
		}
		if (chuongtrinh == 4)
		{
			if (khoa3 != 0)
				Menu4();
			else
				printf("Ban chua nhap chuc nang so 3\n");
		}
		if (chuongtrinh == 5)
		{
			if (khoa3 != 0)
				Menu5();
			else
				printf("Ban chua nhap chuc nang so 3\n");
		}
		Menu();
	} while (chuongtrinh != 6);

	printf("Chuong trinh ket thuc, tam biet !\n");
	return 0;
}
