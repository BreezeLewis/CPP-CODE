#ifndef VECTOR_MATRIX_H
#define VECTOR_MATRIX_H
class Vector {
public:
    Vector();
    Vector(int dim, const int* elements_);
    ~Vector();

    int getDimension() const;
    int* getElements() const;
    double getModule() const;                             //��������ģ��

private:
    int dimension;                                  //������ά��
    int* elements;                                  //�洢����Ԫ�ص�����
};
class Matrix : public Vector {
public:
    Matrix();
    Matrix(int row, int col, const int* elements_);      //����������Լ�����Ԫ�أ������ȷ�ʽ�洢��һά�����У�
    bool Symmetric() const;                              //�ж��Ƿ�Ϊ�Գƾ���
private:
    int row;                                       //�������
};
#endif