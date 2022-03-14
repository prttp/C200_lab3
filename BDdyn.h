#pragma once
#include "myString.h"
class MyData {
public:
	enum Sex { UNDEF, MALE, FMALE };
private:
	Sex sex;
	size_t m_age;
	MyString m_job;
	float m_salary;
public://���������, ��� �� ������������� ���� ������ ���� �������������

	MyData();
	MyData(Sex s, size_t age, const char* job, float sal);
	friend std::ostream& operator<<(std::ostream& os, const MyData& d);
	
	//��� �����-���� ������� �� �������
};
class Pair {

	MyString key;//���� -�������
	MyData data;// MyData* pData;//������ � ����������
public:
	Pair();
	Pair(const char* k);
	Pair(const char* k, const MyData& d);
	bool operator== (const char* k) const;
	friend class BD;
	friend std::ostream& operator<<(std::ostream& os, const Pair& pair);
};
class BD {
	Pair* pBase; //Pair**pBase;//��������� �� ���� ������
	size_t count; //���������� ��������� � ����
	size_t capacity; //������� ����
public:
	//���������, ��� �� ������������� ���� ������ ���� �������������
	BD();
	BD(const BD& bd);
	BD& operator=(const BD& bd);//����������������!!!
	BD(BD&& bd);
	BD& operator=(BD&& bd);
	MyData& operator[](const char* key);
	void deletePair(const char* key);
	friend std::ostream& operator<<(std::ostream& os, const BD& bd);

	//��� �����-���� ������� �� �������
};
