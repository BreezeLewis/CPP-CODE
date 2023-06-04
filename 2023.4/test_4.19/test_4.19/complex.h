<<<<<<< HEAD
#ifndef COMPLEX_H
#define COMPLEX_H

class COMPLEX
{
public:
	COMPLEX(double r = 0, double i = 0); // ���캯��
	COMPLEX(const COMPLEX& other);		 // �������캯��
	void print();						 // ��ӡ����

	COMPLEX operator+(const COMPLEX& other); // ���ؼӷ����������Ԫ��
	COMPLEX operator-(const COMPLEX& other); // ���ؼ������������Ԫ��
	COMPLEX operator-(); // �������������һԪ��
	COMPLEX operator=(const COMPLEX& other); // ���ظ�ֵ���������Ԫ��

	COMPLEX& operator++();   //����ǰ��++
	COMPLEX operator++(int); //���غ���++
	COMPLEX& operator--();   //����ǰ��--
	COMPLEX operator--(int); //���غ���--
protected:
	double real, image; // ������ʵ�����鲿
};
#endif

=======
#ifndef COMPLEX_H
#define COMPLEX_H

class COMPLEX
{
public:
	COMPLEX(double r = 0, double i = 0); // ���캯��
	COMPLEX(const COMPLEX& other);		 // �������캯��
	void print();						 // ��ӡ����

	COMPLEX operator+(const COMPLEX& other); // ���ؼӷ����������Ԫ��
	COMPLEX operator-(const COMPLEX& other); // ���ؼ������������Ԫ��
	COMPLEX operator-(); // �������������һԪ��
	COMPLEX operator=(const COMPLEX& other); // ���ظ�ֵ���������Ԫ��

	COMPLEX& operator++();   //����ǰ��++
	COMPLEX operator++(int); //���غ���++
	COMPLEX& operator--();   //����ǰ��--
	COMPLEX operator--(int); //���غ���--
protected:
	double real, image; // ������ʵ�����鲿
};
#endif

>>>>>>> cb73fa683f44cfac30efa94f2b3548a5d45d7a6c
