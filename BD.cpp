#include "BD.h"

MyData::MyData(Sex s, size_t age, const char* job, float sal) {
	sex = s;
	m_age = age;
	m_job = job;
	m_salary = sal;
}
MyData::MyData() {
	sex = MALE;
	m_age = 0;
	m_job = "unemployed";
	m_salary = 0;
}
std::ostream& operator<<(std::ostream& os, const MyData& d) {
	os << "Sex: " << d.sex << ", " << "Age: " << d.m_age << ", " << "Job: " << d.m_job << ", " << "Salary: " << d.m_salary << ";";
	return os;
}

Pair::Pair(const char* k, const MyData& d) {
	key = k;
	data = d;
}
Pair::Pair() {
	key = "default";
	//data = MyData();
}
Pair::Pair(const char* k) {
	key = k;
	//data = MyData();
}
std::ostream& operator<<(std::ostream& os, const Pair& d) {
	os << "Name: " << d.key << ", " << d.data << std::endl;
	return os;
}
bool Pair::operator== (const char* k) const {
	if (strcmp(key.GetString(), k) == 0) {
		return 1;
	};
	return 0;
}
BD::BD() {
	pBase = new Pair();
	count = 0;
	capacity = 0;
}
BD::BD(const BD& bd) {
	for (int i = 0; i < bd.capacity; i++) {
		pBase[i] = bd.pBase[i];
	}
	count = bd.count;
	capacity = bd.capacity;
}
BD& BD::operator=(const BD& bd) {
	for (int i = 0; i < bd.capacity; i++) {
		pBase[i] = bd.pBase[i];
	}
	count = bd.count;
	capacity = bd.capacity;
	return *this;
}
BD::BD(BD&& bd) {
	pBase = bd.pBase;
	bd.pBase = nullptr;
	count = bd.count;
	capacity = bd.capacity;
}
BD& BD::operator=(BD&& bd) {
	pBase = bd.pBase;
	bd.pBase = nullptr;
	count = bd.count;
	capacity = bd.capacity;
	return *this;
}
MyData& BD::operator[](const char *key) {
	for (int i = 0; i < count; i++) {
		if (pBase[i] == key) { return pBase[i].data; };
	}
	pBase[count] = new Pair();
	count++;
	if (count > capacity) { capacity++; }
	return pBase[count - 1].data;
}
void BD::deletePair(const char* key) {
	for (int i = 0; i < count; i++) {
		if (pBase[i] == key) {
			delete &pBase[i];
		};
	}
	
}
std::ostream& operator<<(std::ostream& os, const BD& d) {
	os << *(d.pBase) << "capacity: " << d.capacity << " count: " << d.count << std::endl;
	return os;
}