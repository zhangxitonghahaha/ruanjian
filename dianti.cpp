#include<stdio.h>
#include<windows.h>
typedef struct elevator
{
    int staus;//����״̬����ֹ�����У�����
    int type;//�������ͣ�˫������ȫ
    int floor;//��ʱͣ�ڵ�¥����
    int beixuyao;//��¥���Ƿ񱻵���
    int flag;//�Ƿ������õ���
}B;
B a[4];
int flag, dir, floor, gofloor;
int c[3], k[3], m[3];
int Lookfor(int x, int y, int z)//����¥���ֵ����
{
    int c;
    if (a[x].staus == 0)//��ʱa[x]���ݴ��ھ�ֹ״̬
    {
        if (y < z)
        {
            c = z - y;
        }
        else
        {
            c = y - z;
        }
    }
    if (a[x].staus == 1)//��ʱa[x]���ݴ�������״̬
    {
        if (y > z && dir == 1)
        {
            c = y - z;
        }
        else
        {
            printf("�˵��ݲ�����Ӧ�û�������");
        }
    }
    if (a[x].staus == 2)//��ʱa[x]���ݴ����½�״̬
    {
        if (y < z && dir == 0)
        {
            c = z - y;
        }
        else
        {
            printf("�˵��ݲ�����Ӧ�û�������");
        }
    }
    return c;
}
void main()
{
    //���˲���
    printf("       ----       ----       ----       ---- \n");
    printf("      |    |     |    |     |    |     |    |\n");
    printf("        -1         7          14         20  \n");
    printf("      |    |     |    |     |    |     |    |\n");
    printf("       ----       ----       ----       ---- \n");
    a[0].staus = 0;
    a[1].staus = 0;
    a[2].staus = 0;
    a[3].staus = 0;
    a[0].floor = -1;
    a[1].floor = 7;//��ʾ��ʱ����ͣ�ڵ�¥����Ϊ7¥
    a[2].floor = 14;
    a[3].floor = 20;
    while (1)
    {
        a[0].type = 2;//һ�ŵ�������¥�㶼ͣ��
        a[1].type = 1;//���ŵ��ݵ���¥�㶼ͣ��
        a[2].type = 0;//���ŵ���˫��¥�㶼ͣ��
        a[3].type = 2;//�ĺŵ�������¥�㶼ͣ��
        int i;
        int flag1 = 0, j = 0;
        printf("----------------------------------------------\n");
        printf("��Ҫ�õ����밴��ť 1 ��\n");
        scanf("%d", &flag);//��ʱ�Ƿ����˰�����
        if (flag == 1)
        {
            printf("*****��ʱ���û������ݣ�*****\n");
        }
        printf("�û�����¥��Ϊ: ");
        scanf("%d", &floor);//��ʱ�����ݵ������ڵ�¥����
        printf("��¥�밴 1 ����¥�밴 0: ");
        scanf("%d", &dir);//�û���������¥������¥���
        printf("��ѡ��Ҫȥ��¥��: ");
        scanf("%d", &gofloor);//�û�Ҫȥ��¥��
        if (flag == 1)//�û�������
        {
            if (dir == 1)//�û�Ҫ��¥
            {
                if (floor % 2 == 0)//�û�����Ϊż��¥��
                {
                    if (gofloor % 2 == 1)//�û�Ҫȥ����¥��
                    {
                        for (i = 0; i < 4; i++)
                        {
                            if (a[i].type == 2)
                            {
                                a[i].beixuyao = 1;
                            }
                            else
                            {
                                a[i].beixuyao = 0;
                            }
                            while (a[i].beixuyao == 1)
                            {
                                k[flag1] = Lookfor(i, floor, a[i].floor);
                                m[flag1] = i;
                                flag1++;
                                a[i].beixuyao = 0;
                            }
                        }
                        if (k[0] < k[1])
                        {
                            printf("���û�������ҷ��������ĵ���Ϊ��0\n");
                            a[0].floor = gofloor;
                            a[0].staus = 0;
                        }
                        else
                        {
                            printf("���û�������ҷ��������ĵ���Ϊ��3\n");
                            a[3].floor = gofloor;
                            a[3].staus = 0;
                        }
                    }
                    if (gofloor % 2 == 0)//�û�Ҫȥż��¥��
                    {
                        for (i = 0; i < 4; i++)
                        {
                            if (a[i].type == 2 || a[i].type == 0)
                            {
                                a[i].beixuyao = 1;
                            }
                            else
                            {
                                a[i].beixuyao = 0;
                            }
                            while (a[i].beixuyao == 1)
                            {
                                k[flag1] = Lookfor(i, floor, a[i].floor);
                                m[flag1] = i;
                                flag1++;
                                a[i].beixuyao = 0;
                            }
                        }
                        if (k[0] < k[1])
                        {
                            if (k[0] < k[2])
                            {
                                printf("���û�������ҷ��������ĵ���Ϊ��0\n");
                                a[0].floor = gofloor;
                                a[0].staus = 0;
                            }
                            else
                            {
                                printf("���û�������ҷ��������ĵ���Ϊ��3\n");
                                a[3].floor = gofloor;
                                a[3].staus = 0;
                            }
                        }
                        else
                        {
                            if (k[1] < k[2])
                            {
                                printf("���û�������ҷ��������ĵ���Ϊ��2\n");
                                a[2].floor = gofloor;
                                a[2].staus = 0;
                            }
                            else
                            {
                                printf("���û�������ҷ��������ĵ���Ϊ��3\n");
                                a[3].floor = gofloor;
                                a[3].staus = 0;
                            }
                        }
                    }
                }
                if (floor % 2 == 1)//�û�����Ϊ����¥��
                {
                    if (gofloor % 2 == 0)//�û�Ҫȥż��¥��
                    {
                        for (i = 0; i < 4; i++)
                        {
                            if (a[i].type == 2)
                            {
                                a[i].beixuyao = 1;
                            }
                            else
                            {
                                a[i].beixuyao = 0;
                            }
                            while (a[i].beixuyao == 1)
                            {
                                k[flag1] = Lookfor(i, floor, a[i].floor);
                                m[flag1] = i;
                                flag1++;
                                a[i].beixuyao = 0;
                            }
                        }
                        if (k[0] < k[1])
                        {
                            printf("���û�������ҷ��������ĵ���Ϊ��0\n");
                            a[0].floor = gofloor;
                            a[0].staus = 0;
                        }
                        else
                        {
                            printf("���û�������ҷ��������ĵ���Ϊ��3\n");
                            a[3].floor = gofloor;
                            a[3].staus = 0;
                        }
                    }
                    if (gofloor % 2 == 1)//�û�Ҫȥ����¥��
                    {
                        for (i = 0; i < 4; i++)
                        {
                            if (a[i].type == 2 || a[i].type == 1)
                            {
                                a[i].beixuyao = 1;
                            }
                            else
                            {
                                a[i].beixuyao = 0;
                            }
                            while (a[i].beixuyao == 1)
                            {
                                k[flag1] = Lookfor(i, floor, a[i].floor);
                                m[flag1] = i;
                                flag1++;
                                a[i].beixuyao = 0;
                            }
                        }
                        if (k[0] < k[1])
                        {
                            if (k[0] < k[2])
                            {
                                printf("���û�������ҷ��������ĵ���Ϊ��0\n");
                                a[0].floor = gofloor;
                                a[0].staus = 0;
                            }
                            else
                            {
                                printf("���û�������ҷ��������ĵ���Ϊ��3\n");
                                a[3].floor = gofloor;
                                a[3].staus = 0;
                            }
                        }
                        else
                        {
                            if (k[1] < k[2])
                            {
                                printf("���û�������ҷ��������ĵ���Ϊ��2\n");
                                a[1].floor = gofloor;
                                a[1].staus = 0;
                            }
                            else
                            {
                                printf("���û�������ҷ��������ĵ���Ϊ��3\n");
                                a[3].floor = gofloor;
                                a[3].staus = 0;
                            }
                        }
                    }
                }
            }
            if (dir == 0)//�û�Ҫ��¥
            {
                if (floor % 2 == 0)//�û�����Ϊż��¥��
                {
                    if (gofloor % 2 == 1)//�û�Ҫȥ����¥��
                    {
                        for (i = 0; i < 4; i++)
                        {
                            if (a[i].type == 2)
                            {
                                a[i].beixuyao = 1;
                            }
                            else
                            {
                                a[i].beixuyao = 0;
                            }
                            while (a[i].beixuyao == 1)
                            {
                                k[flag1] = Lookfor(i, floor, a[i].floor);
                                m[flag1] = i;
                                flag1++;
                                a[i].beixuyao = 0;
                            }
                        }
                        if (k[0] < k[1])
                        {
                            printf("���û�������ҷ��������ĵ���Ϊ��0\n");
                            a[0].floor = gofloor;
                            a[0].staus = 0;
                        }
                        else
                        {
                            printf("���û�������ҷ��������ĵ���Ϊ��3\n");
                            a[3].floor = gofloor;
                            a[3].staus = 0;
                        }
                    }
                    if (gofloor % 2 == 0)//�û�Ҫȥż��¥��
                    {
                        for (i = 0; i < 4; i++)
                        {
                            if (a[i].type == 2 || a[i].type == 0)
                            {
                                a[i].beixuyao = 1;
                            }
                            else
                            {
                                a[i].beixuyao = 0;
                            }
                            while (a[i].beixuyao == 1)
                            {
                                k[flag1] = Lookfor(i, floor, a[i].floor);
                                m[flag1] = i;
                                flag1++;
                                a[i].beixuyao = 0;
                            }
                        }
                        if (k[0] < k[1])
                        {
                            if (k[0] < k[2])
                            {
                                printf("���û�������ҷ��������ĵ���Ϊ��0\n");
                                a[0].floor = gofloor;
                                a[0].staus = 0;
                            }
                            else
                            {
                                printf("���û�������ҷ��������ĵ���Ϊ��3\n");
                                a[3].floor = gofloor;
                                a[3].staus = 0;
                            }
                        }
                        else
                        {
                            if (k[1] < k[2])
                            {
                                printf("���û�������ҷ��������ĵ���Ϊ��2\n");
                                a[2].floor = gofloor;
                                a[2].staus = 0;
                            }
                            else
                            {
                                printf("���û�������ҷ��������ĵ���Ϊ��3\n");
                                a[3].floor = gofloor;
                                a[3].staus = 0;
                            }
                        }
                    }
                }
                if (floor % 2 == 1)//�û�����Ϊ����¥��
                {
                    if (gofloor % 2 == 0)//�û�Ҫȥż��¥��
                    {
                        for (i = 0; i < 4; i++)
                        {
                            if (a[i].type == 2)
                            {
                                a[i].beixuyao = 1;
                            }
                            else
                            {
                                a[i].beixuyao = 0;
                            }
                            while (a[i].beixuyao == 1)
                            {
                                k[flag1] = Lookfor(i, floor, a[i].floor);
                                m[flag1] = i;
                                flag1++;
                                a[i].beixuyao = 0;
                            }
                        }
                        if (k[0] < k[1])
                        {
                            printf("���û�������ҷ��������ĵ���Ϊ��0\n");
                            a[0].floor = gofloor;
                            a[0].staus = 0;
                        }
                        else
                        {
                            printf("���û�������ҷ��������ĵ���Ϊ��3\n");
                            a[3].floor = gofloor;
                            a[3].staus = 0;
                        }
                    }
                    if (gofloor % 2 == 1)//�û�Ҫȥ����¥��
                    {
                        for (i = 0; i < 4; i++)
                        {
                            if (a[i].type == 2 || a[i].type == 1)
                            {
                                a[i].beixuyao = 1;
                            }
                            else
                            {
                                a[i].beixuyao = 0;
                            }
                            while (a[i].beixuyao == 1)
                            {
                                k[flag1] = Lookfor(i, floor, a[i].floor);
                                m[flag1] = i;
                                flag1++;
                                a[i].beixuyao = 0;
                            }
                        }
                        if (k[0] < k[1])
                        {
                            if (k[0] < k[2])
                            {
                                printf("���û�������ҷ��������ĵ���Ϊ��0\n");
                                a[0].floor = gofloor;
                                a[0].staus = 0;
                            }
                            else
                            {
                                printf("���û�������ҷ��������ĵ���Ϊ��3\n");
                                a[3].floor = gofloor;
                                a[3].staus = 0;
                            }
                        }
                        else
                        {
                            if (k[1] < k[2])
                            {
                                printf("���û�������ҷ��������ĵ���Ϊ��2\n");
                                a[1].floor = gofloor;
                                a[1].staus = 0;
                            }
                            else
                            {
                                printf("���û�������ҷ��������ĵ���Ϊ��3\n");
                                a[3].floor = gofloor;
                                a[3].staus = 0;
                            }
                        }
                    }
                }
            }
        }
        else if (flag == 0)
        {
            printf("��ʱ�����õ���");
        }
        printf("       ----       ----       ----       ---- \n");
        printf("      |    |     |    |     |    |     |    |\n");
        printf("        %d         %d          %d         %d  \n", a[0].floor, a[1].floor, a[2].floor, a[3].floor);
        printf("      |    |     |    |     |    |     |    |\n");
        printf("       ----       ----       ----       ---- \n");
        printf("\n");
        printf("----------------------------------------------\n");
    }
}