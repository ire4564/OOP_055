//
// Created by 김혁진 on 14/10/2019.
//

#include "shared_mut.h"

namespace ptr {
shared_mut::shared_mut() {
    _mgr = new mgr();
}

shared_mut::shared_mut(Object* _obj) {
    _mgr = new mgr(_obj);
}

shared_mut::~shared_mut() {
    release();
}
shared_mut::shared_mut(const shared_mut& shared){
	        _mgr = shared._mgr;
		        increase();
}

shared_mut shared_mut::operator*(const shared_mut &shared){
	//private여서 한번에 shared를 못 가지고 오므로 가지고 온 주소에 주소를 접근하여
	//ptr을 구하도록 한다
	return shared_mut(new Object(_mgr->ptr->get()*shared.get()->get()));
}	
shared_mut shared_mut::operator+(const shared_mut &shared){
	return shared_mut(new Object(_mgr->ptr->get()+shared.get()->get()));
}
shared_mut shared_mut::operator/(const shared_mut &shared){
	return shared_mut(new Object(_mgr->ptr->get()/shared.get()->get()));
}
shared_mut shared_mut::operator-(const shared_mut &shared){
	return shared_mut(new Object(_mgr->ptr->get()-shared.get()->get()));
}
Object* shared_mut::operator->(){
	return _mgr->ptr;
}

shared_mut& shared_mut::operator=(const shared_mut &r){
	_mgr->~mgr();
	_mgr = r._mgr;
	this -> increase();
	return *this;
}
void shared_mut::release() {
	_mgr->count--;
	if(_mgr->count == 0){
		delete _mgr;
		_mgr = nullptr;
	}
    	 _mgr = new mgr();
  //count를 줄여주고
  //mgr 기본 값이 nullptr에다가 count=0이니까 이것을 가리키게 해준다
			 
}
Object* shared_mut::get() const {
	//값을 가져오는 함수
	if(_mgr == nullptr){
	return nullptr;
	} else {
	return _mgr->ptr;
	}
}
void shared_mut::increase(){
	//_mgr->count++;
	_mgr->count = count()+1;
}
int shared_mut::count() {
	return _mgr->count;
}

} // end of namespace ptr
