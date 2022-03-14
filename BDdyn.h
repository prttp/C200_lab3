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
public://ѕодумайте, все ли перечисленные ниже методы надо реализовывать

	MyData();
	MyData(Sex s, size_t age, const char* job, float sal);
	friend std::ostream& operator<<(std::ostream& os, const MyData& d);
	
	//или каких-либо методов не хватает
};
class Pair {

	MyString key;//ключ -фамили€
	MyData data;// MyData* pData;//данные о сотруднике
public:
	Pair();
	Pair(const char* k);
	Pair(const char* k, const MyData& d);
	bool operator== (const char* k) const;
	friend class BD;
	friend std::ostream& operator<<(std::ostream& os, const Pair& pair);
};
class BD {
	Pair* pBase; //Pair**pBase;//указатель на базу данных
	size_t count; //количество элементов в базе
	size_t capacity; //емкость базы
public:
	//ѕодумайте, все ли перечисленные ниже методы надо реализовывать
	BD();
	BD(const BD& bd);
	BD& operator=(const BD& bd);//оптимизированный!!!
	BD(BD&& bd);
	BD& operator=(BD&& bd);
	MyData& operator[](const char* key);
	void deletePair(const char* key);
	friend std::ostream& operator<<(std::ostream& os, const BD& bd);

	//или каких-либо методов не хватает
};
