#include<iostream>
#include<unordered_map>
#include<list>

using namespace std;
typedef void (*fp)();

unordered_map<const char*, std::list<fp> > hashmap;

void addEvent(const char* eventName, fp cb) {
	/*if (hashmap.find(eventName) == hashmap.end()) {
		list<fp> *cbList = new list<fp>;
		cbList->push_back(cb);
		hashmap[eventName] = *cbList;
		return;
	}*/
	
	hashmap[eventName].push_back(cb);
}
void removeEvent(const char* eventName, fp cb) {
	if (hashmap.find(eventName) == hashmap.end())
		return;
	std::list<fp> *pList = &hashmap[eventName];
	std::list<fp>::iterator it;
	for (it = pList->begin(); it != pList->end(); it++) {
		if ((*it) == cb) {
			cout<< eventName << "remove func name *it" << *it << "and cb" << cb << endl;
			pList->erase(it);
			break;
		}
	}
	//cbList.remove(cb);
}
void postEvent(const char* eventName) {
	if (hashmap.find(eventName) == hashmap.end()) {
		return;
	}
	std::list<fp> cbList = hashmap[eventName];
	for (std::list<fp>::iterator it = cbList.begin(); it != cbList.end(); it++) {
		(*(*it))();
	}
}

void wifi_up_1(){
	cout<< "Wifi is up 1" <<endl;
}
void wifi_up_2(){
	cout<< "Wifi is up 2" <<endl;
}
void wifi_up_3(){
	cout<< "Wifi is up 3" <<endl;
}
void wifi_up_4(){
	cout<< "Wifi is up 4" <<endl;
}
void wifi_down_1(){
	cout<< "Wifi is down 1" <<endl;
}
void wifi_down_2(){
	cout<< "Wifi is down 2" <<endl;
}
void wifi_down_3(){
	cout<< "Wifi is down 3" <<endl;
}
void wifi_down_4(){
	cout<< "Wifi is down 4" <<endl;
}
int main()
{
	addEvent("Wifi UP", &wifi_up_1);
	addEvent("Wifi UP", &wifi_up_2);
	addEvent("Wifi UP", &wifi_up_3);
	addEvent("Wifi UP", &wifi_up_4);
	addEvent("Wifi DOWN", &wifi_down_1);
	addEvent("Wifi DOWN", &wifi_down_2);
	addEvent("Wifi DOWN", &wifi_down_3);
	addEvent("Wifi DOWN", &wifi_down_4);

	postEvent("Wifi UP");
	postEvent("Wifi DOWN");

	removeEvent("Wifi UP", &wifi_up_3);
	removeEvent("Wifi UP", &wifi_up_4);
	removeEvent("Wifi DOWN", &wifi_down_3);
	removeEvent("Wifi DOWN", &wifi_down_4);

	postEvent("Wifi UP");
	postEvent("Wifi DOWN");

	return 0;
}
