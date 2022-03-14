#include "BDdyn.h"

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
	os << "Sex: ";
	switch (d.sex) {
	case 0: os << "undefined"; break;
	case 1: os << "male"; break;
	case 2: os << "female"; break;
	}
	os <<  ", " << "Age: " << d.m_age << ", " << "Job: " << d.m_job << ", " << "Salary: " << d.m_salary << ";";
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
//Pair::Pair(const char* k) {
//	key = k;
//	//data = MyData();
//}
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
	pBase = nullptr;
	count = 0;
	capacity = 0;
}
BD::BD(const BD& bd) {
	pBase = new Pair[bd.count+1];
	for (int i = 0; i < bd.count; i++) {
		pBase[i] = bd.pBase[i];
	}
	count = bd.count;
	capacity = bd.count + 1;
}
BD& BD::operator=(BD&& bd) {
	if (pBase != nullptr) { delete pBase; };
	pBase = bd.pBase;
	bd.pBase = nullptr;
	count = bd.count;
	capacity = bd.capacity;
	bd.count = 0;
	bd.capacity = 0;
	return *this;
}
MyData& BD::operator[](const char* key) {
	for (int i = 0; i < count; i++) {
		if (pBase[i] == key) { return pBase[i].data; };
	}
	if (count == capacity) {
		capacity++;
		//if (pBase != nullptr) {
			Pair* tmp = pBase;
			//pBase = nullptr;
			pBase = new Pair[capacity];
			for (int i = 0; i < count; i++) {
				pBase[i] =std::move(tmp[i]);
			}
			//delete[] tmp;
		//} else {pBase = new Pair[capacity];};
	};
	pBase[count].key = key;
	count++;
	return pBase[count - 1].data;
}
BD& BD::operator=(const BD& bd) {
	if (pBase != nullptr) { delete pBase; };
	pBase = new Pair[bd.capacity];
	for (int i = 0; i < bd.count; i++) {
		pBase[i] = bd.pBase[i];
	}
	count = bd.count;
	capacity = bd.capacity;
	return *this;
}
void BD::deletePair(const char* key) {
	for (int i = 0; i < count; i++) {
		if (pBase[i] == key) {
			for (int j = i; j < (count-1); j++) {
				pBase[j] = pBase[j + 1];
			}
			pBase[count-1] = Pair();
			count--;
			break;
		};
	}
}
std::ostream& operator<<(std::ostream& os, const BD& d) {
	for (int i = 0; i < d.count; i++) { os << d.pBase[i]; };
	os << "capacity: " << d.capacity << " count: " << d.count << std::endl;
	return os;
}