//POLYNOMIAL.CPP
//ʵ����ʽ����
#include  <iostream>
#include  <iomanip>
#include  <fstream>
#include  <cmath>
using namespace std;
class  polynomial
{
private:
    int n;         //����ʽ����
    double*  p;
public:
    polynomial(int nn)
    {
        n = nn;
        p = new double[n + 1]; //��̬�����ڴ�
    }
    void  file_input();   //���ļ��������ʽϵ��
    void  input();        //�ɼ����������ʽϵ��
    void  output();       //�������ʽϵ�����ļ�����ʾ
    double poly_value(double);  //����ʽ��ֵ
    void poly_mul(polynomial&, polynomial&); //����ʽ���
    void poly_div(polynomial&, polynomial&, polynomial&);
    //����ʽ���
    ~polynomial()
    {
        delete [] p;
    }
};

void polynomial::file_input()  //���ļ��������ʽϵ��
{
    int  i;
    char str1[20];
    cout << "\n�����ļ���:  ";
    cin >> str1;
    ifstream  fin(str1);

    if (!fin) {
        cout << "\n���ܴ�����ļ� " << str1 << endl;
        exit(1);
    }

    for (i = 0; i < n + 1; i++) {
        fin >> p[i];    //�������ʽϵ��
    }

    fin.close();
}

void polynomial::input()  //�ɼ����������ʽϵ��
{
    int  i;
    cout << "����ʽϵ��:" << endl;

    for (i = 0; i < n + 1; i++) {      //�������ʽϵ��
        cout << "p(" << i << ") = ";
        cin >> p[i];
    }
}

void polynomial::output()  //�������ʽϵ�����ļ�����ʾ
{
    int i;
    char str2[20];
    cout << "\n����ļ���:  ";
    cin >> str2;
    ofstream fout(str2);

    if (!fout) {
        cout << "\n���ܴ�����ļ� " << str2 << endl;
        exit(1);
    }

    for (i = 0; i < n + 1; i++) {
        cout << "p(" << i << ")=" << p[i] << endl;
        fout << p[i] << endl;
    }

    fout.close();
}

double polynomial::poly_value(double x)           //����ʽ��ֵp(x)
{
    int k;
    double u;
    u = p[n];

    for (k = n - 1; k >= 0; k--) {
        u = u * x + p[k];
    }

    return u;
}

void polynomial::poly_mul(polynomial& p2, polynomial& p3)
//����ʽ��� p3 = p*p2
{
    int i, j;

    for (i = 0; i <= p3.n; i++) {
        p3.p[i] = 0.0;
    }

    for (i = 0; i <= n; i++)
        for (j = 0; j <= p2.n; j++) {
            p3.p[i + j] = p3.p[i + j] + (this->p[i]) * p2.p[j];
        }

    return ;
}

void polynomial::poly_div(polynomial& p2, polynomial& p3, polynomial& p4)
//����ʽ��� p3 = p/p2 + p4
{
    int i, j, mm, ll;

    for (i = 0; i <= p3.n; i++) {
        p3.p[i] = 0.0;
    }

    if (p2.p[p2.n] + 1.0 == 1.0) {
        return;
    }

    ll = n;

    for (i = (p3.n) + 1; i >= 1; i--) {
        p3.p[i - 1] = p[ll] / (p2.p[p2.n]);
        mm = ll;

        for (j = 1; j <= p2.n; j++) {
            p[mm - 1] = p[mm - 1] - p3.p[i - 1] * (p2.p[(p2.n) - j]);
            mm = mm - 1;
        }

        ll = ll - 1;
    }

    for (i = 0; i <= p4.n; i++) {
        p4.p[i] = p[i];
    }

    return;
}

void main()       //������
{
    int k;
    double x[6] = { 0.9, 1.1, 1.3, -0.9, -1.1, -1.3};
    polynomial  p(6), p2(5), q2(3), s2(8), p3(4), q3(2), s3(2), r3(1);
    p.file_input();        //���ļ��������ʽpϵ��
    cout << "����ʽ��ֵ: " << endl;

    for (k = 0; k < 6; k++) {
        cout << "p(" << x[k] << ") = " << p.poly_value(x[k]) << endl;
    }

    p2.file_input();         //���ļ��������ʽp2ϵ��
    q2.file_input();         //���ļ��������ʽq2ϵ��
    p2.poly_mul(q2, s2);     //����ʽ��� s2 = p2*q2
    cout << "�˻�����ʽs2:" << endl;
    s2.output();             //����˻�����ʽs2��ϵ�����ļ�����ʾ

    p3.file_input();        //���ļ��������ʽp3ϵ��
    q3.file_input();        //���ļ��������ʽq3ϵ��
    p3.poly_div(q3, s3, r3);   //����ʽ��� s3 = p3/q3 + r3
    cout << "�̶���ʽs3:" << endl;
    s3.output();               //����̶���ʽs3��ϵ�����ļ�����ʾ
    cout << "�����ʽr3:" << endl;
    r3.output();               //��������ʽr3��ϵ�����ļ�����ʾ
}

