#ifndef CALCULATOR_H
#define CALCULATOR_H

class AbstractCalculator {
public:
    double m_num1;
    double m_num2;
    virtual double getResult() {
        return 0;
    }
};

class Add : public AbstractCalculator {
public:
    double getResult() {
        return m_num1 + m_num2;
    }
};

class Sub : public AbstractCalculator {
public:
    double getResult() {
        return m_num1 - m_num2;
    }
};

class Mul : public AbstractCalculator {
public:
    double getResult() {
        return m_num1 * m_num2;
    }
};

#endif //CALCULATOR_H
