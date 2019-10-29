//
// Created by 김혁진 on 14/10/2019.
//

#include "unique_immut.h"

namespace ptr {
unique_immut::unique_immut() {
    _mgr = new mgr();
}

unique_immut::unique_immut(Object *obj) {
    _mgr = new mgr(obj);
}

unique_immut::unique_immut(const unique_immut &immut) {
    if (immut._mgr) {
        int val = immut._mgr->ptr->get();
        _mgr = new mgr(val);
    }
}

unique_immut::~unique_immut() {
    release();
}
unique_immut unique_immut::operator+(unique_immut &unique){
	unique_immut temp(new Object(_mgr->ptr->get() + unique.get()->get()));
	release();
	unique.release();
	return temp;
}	
unique_immut unique_immut::operator-(unique_immut &unique){
	unique_immut temp(new Object(_mgr->ptr->get() - unique.get()->get()));
	release();
	unique.release();
	return temp;
}
unique_immut unique_immut::operator*(unique_immut &unique){
	unique_immut temp(new Object(_mgr->ptr->get() * unique.get()->get()));
	release();
	unique.release();
	return temp;

}
unique_immut unique_immut::operator/(unique_immut &unique){
	unique_immut temp(new Object(_mgr->ptr->get() / unique.get()->get()));
	release();
	unique.release();
	return temp;

}
Object* unique_immut::operator->(){
	return _mgr->ptr;	
}
void unique_immut::release() {
	//값을 삭제하기
	_mgr->count--;
	if(_mgr->count == 0){
		delete _mgr;
		_mgr->ptr = nullptr;
	}
}
Object* unique_immut::get() const{
	//포인터 값을 가져오기 위해서
	if(_mgr == nullptr){
		return nullptr;
	} else {
		return _mgr->ptr;
	}
}
} // end of namespace ptr
