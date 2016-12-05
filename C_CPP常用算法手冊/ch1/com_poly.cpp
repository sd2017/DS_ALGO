//COM_POLY.CPP
//��ϵ������ʽ����
#include  <iostream.h>
#include  <iomanip.h>
#include  <fstream.h>
#include  <math.h>
#include  <stdlib.h>
//  using namespace std;
class  complex           //����complex��
{
protected:
    double  R;
    double  I;
public:
    complex(double real = 0, double imag = 0) //���캯��
    {
        R = real;
        I = imag;
    }
    friend ostream& operator << (ostream& out, complex& c)
    //���������<<
    {
        out << "(" << c.R << ", " << c.I << ")"; //�����ʽΪ:(ʵ��, �鲿)
        return out;
    }
    friend istream& operator >> (istream& input, complex& c)
    //���������>>
    {
        input >> c.R >> c.I;   //������ʽΪ:ʵ��<�ո�>�鲿
        return input;
    }
    complex operator + (complex& c2)                //�����ӷ�
    {
        complex c;
        c.R = (this->R) + c2.R;
        c.I = (this->I) + c2.I;
        return c;
    }
    complex operator - (complex& c2)                //��������
    {
        complex c;
        c.R = (this->R) - c2.R;
        c.I = (this->I) - c2.I;
        return c;
    }
    complex operator * (complex& c2)                //�����˷�
    {
        complex c;
        double p, q, s;
        p = (this->R) * c2.R;
        q = (this->I) * c2.I;
        s = ((this->R) + (this->I)) * (c2.R + c2.I);
        c.R = p - q;
        c.I = s - p - q;
        return c;
    }
    complex operator / (complex& c2)                //��������
    {
        complex c;
        double p, q, s, w;
        p = (this->R) * c2.R;
        q = - (this->I) * c2.I;
        s = ((this->R) + (this->I)) * (c2.R - c2.I);
        w = (c2.R) * (c2.R) + (c2.I) * (c2.I);
        c.R = (p - q) / w;
        c.I = (s - p - q) / w;
        return c;
    }
    double cfabs(complex& c)                     //����ģ
    {
        double s;
        s = (c.R) * (c.R) + (c.I) * (c.I);
        s = sqrt(s);
        return s;
    }
};

class  com_poly: public complex //����com_poly�ǻ���complex���������
{
private:
    int n;              //����ʽ����
    complex*  p;        //��ϵ������ʽ
public:
    com_poly(int nn)
    {
        n = nn;
        p = new complex[n + 1]; //��̬�����ڴ�
    }
    void  file_input();   //���ļ��������ʽϵ��
    void  input();        //�ɼ����������ʽϵ��
    void  output();       //�������ʽϵ�����ļ�����ʾ
    complex poly_value(complex);  //����ʽ��ֵ
    void poly_mul(com_poly&, com_poly&); //����ʽ���
    void poly_div(com_poly&, com_poly&, com_poly&);
    //����ʽ���
    ~com_poly()
    {
        delete [] p;
    }
};

void com_poly::file_input()  //���ļ��������ʽϵ��
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

    for (i = 0; i < n + 1; i++) { //�������ʽϵ��
        fin >> p[i];
    }

    fin.close();
}

void com_poly::input()  //�ɼ����������ʽϵ��
{
    int  i;
    cout << "����ʽϵ��:" << endl;

    for (i = 0; i < n + 1; i++) {      //�������ʽϵ��
        cout << "p(" << i << ") = ";
        cin >> p[i];
    }
}

void com_poly::output()  //�������ʽϵ�����ļ�����ʾ
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
    }

    for (i = 0; i < n + 1; i++) {
        fout << p[i] << endl;
    }

    fout.close();
}

complex com_poly::poly_value(complex x)   //����ʽ��ֵp(x)
{
    int k;
    complex u;
    u = p[n];

    for (k = n - 1; k >= 0; k--) {
        u = u * x + p[k];
    }

    return u;
}

void com_poly::poly_mul(com_poly& p2, com_poly& p3)
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

void com_poly::poly_div(com_poly& p2, com_poly& p3, com_poly& p4)
//����ʽ��� p3 = p/p2 + p4
{
    int i, j, mm, ll;

    for (i = 0; i <= p3.n; i++) {
        p3.p[i] = 0.0;
    }

    if (cfabs(p2.p[p2.n]) + 1.0 == 1.0) {
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
    com_poly  p(3), p2(5), q2(3), s2(8), p3(4), q3(2), s3(2), r3(1);
    complex x;
    cout << "����x = ";
    cin >> x;
    p.input();             //�Ӽ����������ʽpϵ��
    cout << "����ʽ��ֵ: " << endl;
    cout << "p(" << x << ") = " << p.poly_value(x) << endl;
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

