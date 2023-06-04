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

