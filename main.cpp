#include <iostream>
#include "ArrayList.hpp"

void testAdd() {
	std::cout << "~~~~~~~~~~~~~~~~~~~~~\n";
	std::cout << "Test add\n\n";

	ArrayList<std::string> list;
	list.add("hello");
	list.add("world");
	list.add("apple");
	list.add("banana");
	list.add("summer");
	list.add("winter");
	std::cout << list;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~\n";
}

void testAddRemove() {
	std::cout << "~~~~~~~~~~~~~~~~~~~~~\n";
	std::cout << "Test add remove\n\n";
	ArrayList<std::string> list;
	list.add("hello");
	list.add("world");
	list.add("apple");
	list.add("banana");
	list.add("summer");
	list.add("winter");
	std::cout << list;
	std::cout << "\n";

	list.remove(1);
	std::cout << list;
	std::cout << "\n";

	list.add("autumn");
	std::cout << list;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~\n";
}

void testAddIndex() {
	std::cout << "~~~~~~~~~~~~~~~~~~~~~\n";
	std::cout << "Test add index\n\n";

	ArrayList<std::string> list;
	list.add("hello");
	list.add("world");
	list.add("apple");
	list.add("banana");
	list.add("summer");
	list.add("winter");
	std::cout << list;
	std::cout << "\n";

	list.add("spring", 3);
	std::cout << list;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~\n";
}

void testReplace() {
	std::cout << "~~~~~~~~~~~~~~~~~~~~~\n";
	std::cout << "Test replace\n\n";

	ArrayList<std::string> list;
	list.add("hello");
	list.add("world");
	list.add("apple");
	list.add("banana");
	list.add("summer");
	list.add("winter");
	std::cout << list;
	std::cout << "\n";

	list.replace("spring", 3);
	list.replace("autumn", 5);
	std::cout << list;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~\n";
}

void testClear() {
	std::cout << "~~~~~~~~~~~~~~~~~~~~~\n";
	std::cout << "Test clear\n\n";

	ArrayList<std::string> list;
	list.add("hello");
	list.add("world");
	list.add("apple");
	list.add("banana");
	list.add("summer");
	list.add("winter");
	std::cout << list;
	std::cout << "\n";

	list.clear();
	std::cout << list;
	std::cout << "\n";

	list.add("spring");
	list.add("autumn");
	std::cout << list;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~\n";
}

void testCopyConstructor() {
	std::cout << "~~~~~~~~~~~~~~~~~~~~~\n";
	std::cout << "Test copy constructor\n\n";

	ArrayList<std::string> list1;
	list1.add("java");
	list1.add("python");
	list1.add("c++");
	list1.add("kotlin");
	std::cout << list1;
	std::cout << "\n";

	ArrayList list2(list1);
	std::cout << list2;
	std::cout << "\n";

	list1.add("rust");
	list1.remove(0);
	list1.add("ruby");

	std::cout << list1;
	std::cout << "\n";
	std::cout << list2;
	std::cout << "\n";

	std::cout << "~~~~~~~~~~~~~~~~~~~~~\n";
}

void testCopyOperator() {
	std::cout << "~~~~~~~~~~~~~~~~~~~~~\n";
	std::cout << "Test copy operator\n\n";

	ArrayList<std::string> list1;
	list1.add("java");
	list1.add("python");
	list1.add("c++");
	list1.add("kotlin");
	std::cout << list1;
	std::cout << "\n";

	ArrayList<std::string> list2;
	list2.add("dog");
	list2.add("cow");
	list2.add("cat");
	list2.add("horse");
	list2.add("duck");
	list2.add("tiger");
	std::cout << list2;
	std::cout << "\n";

	list1 = list2;
	std::cout << list1;
	std::cout << "\n";
	std::cout << list2;
	std::cout << "\n";


	list1.remove(0);
	list1.add("bear");

	list2.replace("cow was replaced", 1);
	list2.add("wolf");

	std::cout << list1;
	std::cout << "\n";
	std::cout << list2;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~\n";
}

void testCapacityConstructor() {
	std::cout << "~~~~~~~~~~~~~~~~~~~~~\n";
	std::cout << "Test capacity constructor\n\n";

	ArrayList<std::string> list1(30);
	list1.add("java");
	list1.add("python");
	list1.add("c++");
	list1.add("kotlin");
	std::cout << list1;
	std::cout << "\n";
	std::cout << list1.capacity() << "\n";
	std::cout << "\n";

	list1.clear();
	std::cout << list1.capacity() << "\n";
	std::cout << "~~~~~~~~~~~~~~~~~~~~~\n";
}

ArrayList<int> getIntArrayList() {
	ArrayList<int> list;
	list.add(10);
	list.add(5);
	list.add(15);
	list.add(3);
	list.add(30);
	return list;
}

void testMoveConstructor() {
	std::cout << "~~~~~~~~~~~~~~~~~~~~~\n";
	std::cout << "Test move constructor\n\n";

	ArrayList<int> list1(std::move(getIntArrayList()));
	std::cout << list1;
	std::cout << "\n";

	list1.add(100);
	list1.add(200);
	list1.add(300);

	list1.remove(1);

	std::cout << list1;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~\n";
}

void testMoveOperator() {
	std::cout << "~~~~~~~~~~~~~~~~~~~~~\n";
	std::cout << "Test move operator\n\n";

	ArrayList<int> list1;
	list1.add(1);
	list1.add(1000);
	list1.add(2000);
	std::cout << list1;
	std::cout << "\n";

	list1 = std::move(getIntArrayList());
	std::cout << list1;
	std::cout << "\n";

	list1.add(-100);
	std::cout << list1;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~\n";
}


int comparatorFun(const double& lhs, const double& rhs) {
	if (lhs < rhs) {
		return -1;
	}
	if (lhs == rhs) {
		return 0;
	}
	return 1;
}

void testSort() {
	std::cout << "~~~~~~~~~~~~~~~~~~~~~\n";
	std::cout << "Test sort\n\n";

	ArrayList<double> list1(100);
	list1.add(4.0);
	list1.add(3.0);
	list1.add(5.0);
	list1.add(7.0);
	list1.add(1.0);
	list1.add(17.0);

	std::cout << list1;
	std::cout << "\n";

	auto comparator = [](const double& lhs, const double& rhs) {
		if (lhs < rhs) {
			return -1;
		}
		if (lhs == rhs) {
			return 0;
		}
		return 1;
	};

	list1.sort(comparatorFun);

	std::cout << list1;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~\n";
}


int main() {
	testAdd();
	testAddRemove();
	testAddIndex();
	testReplace();
	testClear();
	testCopyConstructor();
	testCopyOperator();
	testCapacityConstructor();
	testMoveConstructor();
	testMoveOperator(); //leak
	testSort();
	return 0;
}