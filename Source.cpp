//#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//template <class T>
//class Iterator;
//
//template <class T>
//class Fibonacci
//{
//private:
//	T first, second;
//	int size;
//public:
//	friend class Iterator<T>;
//	typedef Iterator<T> Iter;
//	Fibonacci(T const& first, T const& second, int size)
//	{
//		this->first = first;
//		this->second = second;
//		this->size = size;
//	};
//	Fibonacci(int size);
//	Fibonacci();
//	int Size()
//	{
//		return size;
//	};
//	Iter cbegin() const {
//		return Iter(first, second,size);
//	};
//	Iter cend() const {
//		int c = 0;
//		Iter it = cbegin();
//		while (c!=size)
//		{
//			it.plus();
//			c++;
//		}
//		return it;
//	};
//	T at(int index) {
//		if (index<0 || index>size) {
//			cout << "Wrong index!" << endl;
//			exit(1);
//		}
//		else return *(cbegin() + index);
//	};
//	void Resize(int rs)
//	{
//		if (rs <= 0) cout << "Check the entered size!" << endl;
//		else this->size = rs;
//	};
//	~Fibonacci() {};
//};
//template<>
//inline Fibonacci<string>::Fibonacci(int size)
//{
//	this->first = "a";
//	this->second = "b";
//	this->size = size;
//}
//template< typename T>
//Fibonacci<T>::Fibonacci(int size)
//{
//	this->first = 0;
//	this->second = 1;
//	this->size = size;
//}
//template<>
//inline Fibonacci<string>::Fibonacci()
//{
//	this->first = "a";
//	this->second = "b";
//	this->size = 15;
//}
//template< typename T>
//Fibonacci<T>::Fibonacci()
//{
//	this->first = 0;
//	this->second = 1;
//	this->size = 15;
//}
//template <class C, typename T, class It>
//vector<T> Sort(C& fib)
//{
//	vector<T> vec;
//	for (int i = 0; i < fib.Size(); i++) vec.push_back(fib.at(i));
//	for (int i = 0; i < vec.size(); i++)
//	{
//		int min = i;
//		for (int j = i + 1; j < vec.size(); j++)
//		{
//			if (vec[j] < vec[min])
//			{
//				min = j;
//			}
//		}
//		if (min != i)
//		{
//			swap(vec[i], vec[min]);
//		}
//	}
//	return vec;
//};
//
//template <class C, typename T, class It>
//void Sort(C& c)
//{
//	It i1 = It(c);//c.createIterator();
//	for (int i = 0; i < c.Size() - 1; i++)
//	{
//		T& begin = i1.next();
//		It i2 = It(c);
//		int c = 0;
//		while (c != i)
//		{
//			i2.next();
//			c++;
//		}
//		while (i2.hasNext())
//		{
//			T& temp = i2.next();
//			if (begin > temp)
//			{
//				swap(begin, temp);
//			}
//		}
//	}
//};
//
//template <class T>
//class Iterator: public iterator<random_access_iterator_tag, T>
//{
//private:
//	T current, next;
//	int pos = 0, size;
//public:
//	Iterator(T const& first, T const& second, int size) {
//		this->current = first;
//		this->next = second;
//		this->size = size;
//	};
//	Iterator(T const& first, T const& second, int pos, int size) {
//		this->current = first;
//		this->next = second;
//		this->pos = pos;
//		this->size = size;
//	};
//	Iterator(Fibonacci<T> c)
//	{
//		current = c.first;
//		next = c.second;
//		size = c.size;
//	}
//	bool operator==(const Iterator<T>& c) const;
//	bool operator!=(const Iterator<T>& c) const;
//	void plus() 
//	{
//		pos++;
//	};
//	T operator*() {
//		return current;
//	};
//	T* operator->() {
//		return &current;
//	};
//	Iterator<T>& operator++() {
//		if (pos != size)
//		{
//			T temp = current;
//			current = next;
//			next = temp + next;
//			cout << "*";
//			++pos;
//			return *this;
//		}
//		else cout << "Операция невозможна!" << endl;
//	};
//	Iterator<T> operator++(int c){
//		if (pos != size)
//		{
//			cout << "*";
//			T temp = current;
//			current = next;
//			next = temp + next;
//			pos++;
//		}
//		return *this;
//	};
//	Iterator<T>& operator--();
//	Iterator<T> operator--(int c);
//	Iterator<T> operator+(int index) {
//		*this += index;
//		return *this;
//	};
//	friend Iterator<T> operator-(Iterator<T> const& it, int index) {
//		Iterator<T> it2(it);
//		it2 -= index;
//		return it2;
//	};
//	friend int operator-(Iterator<T> const& it, Iterator<T> const& it2) {
//		return it.pos - it2.pos;
//	};
//	bool operator<(const Iterator<T>& c) const {
//		return pos < c.pos;
//	};
//	bool operator<=(const Iterator<T>& c) const {
//		return pos < c.pos || *this == c;
//	};
//	Iterator<T>& operator+=(int index) {
//		if(index > 0) for(int i = 0; i < index; i++) (*this)++;
//		else for(int i = 0; i > index; i--) (*this)--;
//		return *this;
//	};
//	Iterator<T>& operator-=(int index) {
//		if (index > 0) for (int i = 0; i < index; i++) (*this)--;
//		else for (int i = 0; i > index; i--) (*this)++;
//		return *this;
//	};
//	~Iterator() {};
//};
//template <typename T>
//bool Iterator<T>::operator==(const Iterator<T>& c) const
//{
//	if (&& pos == c.pos) return true;
//	else return false;
//}
//template<typename T>
//bool Iterator<T>::operator!=(const Iterator<T>& c) const
//{
//	if (pos == c.pos) return false;
//	else return true;
//}
//template<typename T>
//Iterator<T>& Iterator<T>::operator--()
//{
//	if (pos != 0)
//	{
//		T temp = next;
//		next = current;
//		current = temp - current;
//		--pos;
//		cout << "*";
//		return *this;
//	}
//	else cout << "Операция невозможна!" << endl;
//}
//template<>
//inline Iterator<string>& Iterator<string>::operator--()
//{
//	if (pos != 0)
//	{
//		string temp = next;
//		next = current;
//		current = temp.substr(0, temp.size() - current.size());
//		--pos;
//		cout << "*";
//		return *this;
//	}
//	else cout << "Операция невозможна!" << endl;
//}
//template<typename T>
//Iterator<T> Iterator<T>::operator--(int c)
//{
//	if (pos != 0)
//	{
//		T temp = next;
//		next = current;
//		current = temp - current;
//		pos--;
//		cout << "*";
//	}
//	return *this;
//}
//template<>
//inline Iterator<string> Iterator<string>::operator--(int c)
//{
//	if (pos != 0)
//	{
//		string temp = next;
//		next = current;
//		current = temp.substr(0, temp.size() - current.size());
//		pos--;
//		cout << "*";
//		return *this;
//	}
//	else cout << "Операция невозможна!" << endl;
//}
//
//
//
//int main(int argc, char *argv[])
//{
//	Fibonacci<string> one("a", "b", 10);
//	Fibonacci<int> e(7, -3, 10);
//	Iterator<int> end = e.cend();
//	for (Iterator<int> it = e.cbegin(); it != end; it++) cout << *it << " ";
//	for (int i = 0; i < one.Size(); i++) cout << one.at(i) << " ";
//	vector<int> a = Sort<Fibonacci,int,int>(e);
//	vector<int> a;
//	a.insert(a.begin(), e.cbegin() + 1, e.cend() - 1);
//	sort(a.begin(), a.end());
//	/*vector<string> b = */Sort<Fibonacci<string>, string, Iterator<string>>(one);
//	for (int i = 0; i < a.size(); i++) cout << a[i] << " ";
//	cout << endl;
//	for (int i = 0; i < one.Size(); i++) cout << one.at(i) << " ";
//	setlocale(LC_ALL, "Russian");
//	cout << *(one.cbegin() + 5) << endl;
//	system("pause");
//	return 0;
//
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

template <class C>
void Sort(C& c)
{
	typename C::iterator i1(c);//c.createIterator();
	for (int i = 0; i < c.Size() - 1; i++)
	{
		typename C:: value_type& begin = i1.next();
		typename C::iterator i2(c);
		int c = 0;
		while (c != i)
		{
			i2.next();
			c++;
		}
		while (i2.hasNext())
		{
			typename C::value_type& temp = i2.next();
			if (begin > temp)
			{
				swap(begin, temp);
			}
		}
	}
};


template<class T>
class JavaIterator {
public:
	virtual T next() = 0;
	virtual bool hasNext() const = 0;
	virtual ~JavaIterator() {};
};
template<typename T>
class StI;
template<typename T>
class StIC;
template<typename T>
class SDI;
template<typename T>
class SDIC;
template<typename T>
class SI;
template<typename T>
class SIC;
template<typename T>
class QI;
template<typename T>
class QIC;
template<typename T>
class LLI;
template<typename T>
class LLIC;

template <class T>
class ContainerInterface {
public:
	virtual int Size() const = 0; // возвращает размер контейнера
	virtual bool isEmpty() const
	{
		if (Size() == 0) { return true; }
		else return false;
	};
	virtual string toString() const
	{
		string s;
		ostringstream ostr;
		JavaIterator<const T&> *iterator = createIteratorC();
		while (iterator->hasNext()) {
			ostr << iterator->next() << ", ";
			s = ostr.str();
		}
		delete iterator;
		return s;
	};
	//friend class JavaIterator<T>;
	virtual JavaIterator<T&> *createIterator() = 0;
	virtual JavaIterator<const T&> *createIteratorC() const = 0;
	virtual ~ContainerInterface() {};
	friend ostream& operator<<(ostream &os, ContainerInterface<T> const & c)
	{
		os << c.toString();
		return os;
	};
	friend bool operator==(ContainerInterface<T> const& one, ContainerInterface<T> const& two)
	{
		JavaIterator<const T&>* i1 = one.createIteratorC();
		JavaIterator<const T&>* i2 = two.createIteratorC();
		if (one.Size() == two.Size())
		{
			while (i1->hasNext() && i2->hasNext())
			{
				if (i1->next() == i2->next()) { continue; }
				else
				{
					delete i1;
					delete i2;
					return false;
				}
			}
			delete i1;
			delete i2;
			return true;
		}
		else {
			delete i1;
			delete i2;
			return false;
		}
	};
};
template <class T>
class PushPopContainerInterface : virtual public ContainerInterface<T> {
public:
	virtual bool push(T const& value) = 0; // добавить элемент
	virtual T pop() = 0; // забрать элемент
	virtual T peek() const = 0; // узнать элемент
	virtual T& peek() = 0;
	virtual ~PushPopContainerInterface() {};
};
template <class T>
class Deque : virtual public ContainerInterface<T> {
public:
	virtual bool pushFront(T const& value) = 0; // добавить в начало
	virtual bool pushBack(T const& value) = 0; // добавить в конец
	virtual T popFront() = 0; // забрать из начала
	virtual T popBack() = 0; // забрать с конца
	virtual T peekFront() const = 0; // узнать элемент в начале
	virtual T peekBack() const = 0; // узнать элемент с конца
	virtual T& peekFront() = 0; // узнать элемент в начале
	virtual T& peekBack() = 0; // узнать элемент с конца
	virtual ~Deque() {};
};
template <class T>
class IndexedContainer : virtual public ContainerInterface<T> {
public:
	virtual T get(int index) const = 0; // узнать элемент по индексу index
	virtual T& get(int index) = 0; // узнать элемент по индексу index
	virtual void set(int index, T const& value) = 0; // задать значение элементу
	virtual ~IndexedContainer() {};
	T& operator[](int index) {
		return get(index);
	}
};
template <class T>
class InsertableContainer : virtual public IndexedContainer<T> {
public:
	virtual bool insertAt(int index, T const& value) = 0; // вставить элемент со сдвигом
	virtual T removeAt(int index) = 0; // убрать элемент со сдвигом
	virtual ~InsertableContainer() {};
};

template <typename T>
class Stack : public PushPopContainerInterface<T>
{
private:
	template <typename T>
	struct Node {
		T value;
		Node* next;
	};
	Node<T> *first;
	Node<T> *current;
	int s;
public:
	typedef T value_type;
	typedef SI<T> iterator;

	friend class SI<T>;
	friend class SIC<T>;
	Stack(T const& value)
	{
		Node<T> *i = new Node<T>();
		i->value = value;
		i->next = NULL;
		first = i;
		s = 1;
	};
	Stack(const Stack<T> &s) {
		Node<T> *temp = s.first;
		vector<T> a;
		int count = s.Size() - 1;
		while (temp != NULL)
		{
			a.push_back(temp->value);
			temp = temp->next;
		}
		while (count != -1)
		{
			push(a[count]);
			count--;
		}
	};
	Stack& operator=(const Stack &s) {
		Node<T> *temp = s.first;
		vector<T> a;
		int count = s.Size() - 1;
		while (temp != NULL)
		{
			a.push_back(temp->value);
			temp = temp->next;
		}
		while (count != -1)
		{
			push(a[count]);
			count--;
		}
		return *this;
	};
	virtual bool push(T const& value) {
		Node<T> *i = new Node<T>();
		i->value = value;
		i->next = first;
		first = i;
		s++;
		return true;
	};
	virtual T pop() {
		current = first;
		first = first->next;
		--s;
		return current->value;
	};
	virtual T peek() const
	{
		if (first == NULL) throw "Stack is empty";
		return first->value;
	};
	virtual T& peek()
	{
		if (first == NULL) throw "Stack is empty";
		return first->value;
	}
	virtual int Size() const
	{
		return s;
	};
	virtual JavaIterator<T&>* createIterator()
	{
		return new SI<T>(*this);
	};
	virtual JavaIterator<const T&>* createIteratorC() const
	{
		return new SIC<T>(*this);
	};
	~Stack()
	{
		current = first;
		while (first != NULL)
		{
			current = first->next;
			delete first;
			first = current;
		}
		delete[] first;
		delete[] current;
	};
};
template <typename T>
class SIC : public virtual JavaIterator<T const&>
{
private:
	typename Stack<T>::template Node<T>const *iterator;
public:
	SIC(Stack<T>const & s) :iterator(s.first) {}
	T const& next()
	{
		T const& c = iterator->value;
		iterator = iterator->next;
		return c;
	}
	virtual bool hasNext() const {
		return iterator != nullptr;
	};
	virtual ~SIC() {};
};
template<typename T>
class SI : public virtual JavaIterator<T&> {
private:
	typename Stack<T>::template Node<T> *iterator;
public:
	SI(Stack<T> &s) :iterator(s.first) {}
	virtual T& next()
	{
		T& c = iterator->value;
		iterator = iterator->next;
		return c;
	}
	virtual bool hasNext() const {
		return iterator != nullptr;
	};
	virtual ~SI() {};
};

template <class T>
class Queue : public PushPopContainerInterface<T>
{
private:
	template <typename T>
	struct Node {
		T value;
		Node* next;
	};
	Node<T> *first;
	Node<T> *current;
	Node<T> *pretail;
	int s;
public:
	friend class QI<T>;
	friend class QIC<T>;
	Queue(T const& value)
	{
		Node<T> *i = new Node<T>();
		i->value = value;
		i->next = NULL;
		first = i;
		s = 1;
	};
	Queue(const Queue<T> &q) {
		Node<T> *temp = q.first;
		while (temp != NULL) {
			push(temp->value);
			temp = temp->next;
		}
	};
	Queue<T>& operator=(const Queue<T> &q)
	{
		QUEUE<T> *temp = q.first;
		while (temp != NULL) {
			push(temp->value);
			temp = temp->next;
		}
		return *this;
	};
	virtual bool push(T const& value) {
		Node<T> *i = new Node<T>();
		i->value = value;
		i->next = NULL;
		if (pretail == NULL)
		{
			first->next = i;
			pretail = first;
		}
		else
		{
			current = pretail->next;
			current->next = i;
			pretail = current;
		}
		s++;
		return true;
	};
	virtual T pop() {
		current = first;
		first = first->next;
		--s;
		return current->value;
	};
	virtual T peek() const
	{
		T c;
		if (first == NULL) { c = NULL; }
		else { c = first->value; }
		return c;
	};
	virtual T& peek()
	{
		T c;
		if (first == NULL) { c = NULL; }
		else { c = first->value; }
		return c;
	}
	virtual int Size() const {
		return s;
	};
	virtual JavaIterator<T&>* createIterator()
	{
		return new QI<T>(*this);
	};
	virtual JavaIterator<const T&>* createIteratorC() const
	{
		return new QIC<T>(*this);
	};
	~Queue()
	{
		current = first;
		while (first != NULL)
		{
			current = first->next;
			delete first;
			first = current;
		}
		delete[] first;
		delete[] current;
		delete[] pretail;
	};
};
template <typename T>
class QIC : public virtual JavaIterator<T const&>
{
private:
	typename Queue<T>::template Node<T>const *iterator;
public:
	QIC(Queue<T>const & q) :iterator(q.first) {}
	T const& next()
	{
		T const& c = iterator->value;
		iterator = iterator->next;
		return c;
	}
	virtual bool hasNext() const {
		return iterator != nullptr;
	};
	virtual ~QIC() {};
};
template<typename T>
class QI : public virtual JavaIterator<T&> {
private:
	typename Queue<T>::template Node<T> *iterator;
public:
	QI(Queue<T> &q) :iterator(q.first) {}
	virtual T& next()
	{
		T& c = iterator->value;
		iterator = iterator->next;
		return c;
	}
	virtual bool hasNext() const {
		return iterator != nullptr;
	};
	virtual ~QI() {};
};

template <class T>
class LinkedList : public PushPopContainerInterface<T>, public InsertableContainer<T>
{
private:
	template <typename T>
	struct N
	{
		T value;
		int index;
		N* next;
	};
	N<T> *first;
	N<T> *current;
	N<T> *tail;
	int s = 0, count = 0;
public:
	friend class LLI<T>;
	friend class LLIC<T>;
	LinkedList(T const& value)
	{
		N<T> *i = new N<T>();
		i->next = NULL;
		i->index = count;
		count++;
		i->value = value;
		tail = i;
		s = 1;
	}
	LinkedList<T>& operator=(const LinkedList &l)
	{
		N<T> *temp = l.tail;
		while (temp != NULL) {
			push(temp->value);
			temp = temp->next;
		}
		return *this;
	};
	LinkedList(const LinkedList &l)
	{
		N<T> *temp = l.tail;
		while (temp != NULL) {
			push(temp->value);
			temp = temp->next;
		}
	};
	virtual bool push(T const& value) {
		N<T> *i = new N<T>();
		i->index = count;
		i->value = value;
		count++;
		i->next = NULL;
		if (first == NULL)
		{
			tail->next = i;
			first = i;
		}
		else
		{
			first->next = i;
			first = i;
		}
		s++;
		return true;
	};
	virtual T pop() {
		T c;
		current = tail;
		while (current->next != first)
		{
			current = current->next;
		}
		c = first->value;
		first = current;
		--s;
		return c;
	};
	virtual T peek() const
	{
		T c;
		if (tail == NULL) { c = NULL; }
		else { c = tail->value; }
		return c;
	};
	virtual T& peek()
	{
		T c;
		if (tail == NULL) { c = NULL; }
		else { c = tail->value; }
		return c;
	}
	virtual T& get(int index)
	{
		T c = NULL;
		current = tail;
		while (current != NULL)
		{
			if (current->index == index)
			{
				c = current->value;
				break;
			}
			current = current->next;
		}
		return c;
	};
	virtual bool insertAt(int index, T const& value)
	{
		N<T> *v = new N<T>();
		v->index = index;
		v->value = value;
		if (first == NULL)
		{
			if (tail->index >= index)
			{
				v->next = tail;
				first = tail;
				tail = v;
			}
			else
			{
				tail->next = v;
				first = v;
			}
		}
		else
		{
			N<T> *i = new N<T>();
			current = tail;
			i = NULL;
			while (true)
			{
				if (current->index >= index)
				{
					if (i == NULL)
					{
						v->next = tail;
						if (first == NULL) { first = tail; }
						tail = v;
						break;
					}
					else
					{
						i->next = v;
						v->next = current;
						break;
					}
				}
				if (current->next = NULL)
				{
					current->next = v;
					v->next = NULL;
					first = v;
					break;
				}
				i = current;
				current = current->next;
			}
		}
		s++;
		return true;
	};
	virtual T removeAt(int index)
	{
		N<T> *i = new N<T>();
		T c;
		current = tail;
		i = NULL;
		while (true)
		{
			if (current->index == index)
			{
				if (i == NULL)
				{
					c = tail->value;
					tail = tail->next;
					break;
				}
				else
				{
					i->next = current->next;
					c = current->value;
					--s;
					break;
				}
			}
			if (current->next == NULL)
			{
				c = NULL;
			}
			i = current;
			current = current->next;
		}
		return c;
	};
	virtual T get(int index) const
	{
		N<T> *i = new N<T>();
		T c;
		i = tail;
		while (true)
		{
			if (i->index == index)
			{
				c = i->value;
				break;
			}
			if (i->next == NULL)
			{
				c = NULL;
				break;
			}
			i = i->next;
		}
		return c;
	}
	virtual void set(int index, T const& value)
	{
		current = tail;
		while (current != NULL)
		{
			if (current->index == index)
			{
				current->value = value;
				break;
			}
			current = current->next;
		}
	}
	virtual int Size() const {
		return s;
	};
	virtual JavaIterator<T&>* createIterator()
	{
		return new LLI<T>(*this);
	};
	virtual JavaIterator<const T&>* createIteratorC() const
	{
		return new LLIC<T>(*this);
	};
	~LinkedList()
	{
		current = tail;
		while (tail != NULL)
		{
			current = tail->next;
			delete tail;
			tail = current;
		}
		delete[] first;
		delete[] current;
		delete[] tail;
	};
};
template <typename T>
class LLIC : public virtual JavaIterator<T const&>
{
private:
	typename LinkedList<T>::template N<T>const *iterator;
public:
	LLIC(LinkedList<T>const & l) :iterator(l.tail) {}
	T const& next()
	{
		T const& c = iterator->value;
		iterator = iterator->next;
		return c;
	}
	virtual bool hasNext() const {
		return iterator != nullptr;
	};
	virtual ~LLIC() {};
};
template<typename T>
class LLI : public virtual JavaIterator<T&> {
private:
	typename LinkedList<T>::template N<T> *iterator;
public:
	LLI(LinkedList<T> &l) :iterator(l.tail) {}
	virtual T& next()
	{
		T& c = iterator->value;
		iterator = iterator->next;
		return c;
	}
	virtual bool hasNext() const {
		return iterator != nullptr;
	};
	virtual ~LLI() {};
};

template <typename T>
class StaticArray : public IndexedContainer<T>, public PushPopContainerInterface<T>
{
private:
	template <typename T>
	struct N
	{
		T value;
		int index;
		N* next;
	};
	N<T> *first;
	N<T> *current;
	N<T> *tail;
	int size, s, count = 0;
	T* arr;
public:
	friend class StI<T>;
	friend class StIC<T>;
	StaticArray<T>(int sz, T const& value)
	{
		N<T> *i = new N<T>();
		arr = new T[sz];
		i->next = NULL;
		i->index = count;
		arr[count] = value;
		count++;
		i->value = value;
		first = i;
		tail = i;
		size = sz - 1;
		s = 1;
	}
	StaticArray(const StaticArray &c)
	{
		T array = new T[c.size];
		for (int i = 0; i < c.size; i++) {
			array[i] = c.arr[i];
		}
	};
	StaticArray<T>& operator =(const StaticArray &c)
	{
		T array = new T[c.size];
		for (int i = 0; i < c.size; i++) {
			array[i] = c.arr[i];
		}
		return (*this);
	};
	virtual T get(int index) const
	{
		N<T> *i = new N<T>();
		T c = NULL;
		i = first;
		while (i != NULL)
		{
			if (i->index == index)
			{
				c = i->value;
				break;
			}
			i = i->next;
		}
		return c;
	};
	virtual void set(int index, T const& value)
	{
		current = first;
		while (current != NULL)
		{
			if (current->index == index)
			{
				current->value = value;
				break;
			}
			current = current->next;
		}
	};
	virtual bool push(T const& value) {
		if (size == 0) { return false; }
		else {
			N<T> *i = new N<T>();
			i->value = value;
			i->index = count;
			arr[count] = value;
			count++;
			i->next = NULL;
			tail->next = i;
			tail = i;
			size = size - 1;
			s++;
		}
		return true;
	};
	virtual T pop()
	{
		current = first;
		first = first->next;
		size = size - 1;
		s--;
		return current->value;
	};
	virtual T peek() const {
		T c;
		if (first == NULL) { c = NULL; }
		else { c = first->value; }
		return c;
	};
	virtual T& peek()
	{
		T c;
		if (first == NULL) { c = NULL; }
		else { c = first->value; }
		return c;
	}
	virtual T& get(int index)
	{
		return arr[index];
	};
	virtual int Size() const
	{
		return s;
	};
	virtual JavaIterator<T&>* createIterator()
	{
		return new StI<T>(*this);
	};
	virtual JavaIterator<const T&>* createIteratorC() const
	{
		return new StIC<T>(*this);
	};
	~StaticArray()
	{
		current = first;
		while (first != NULL)
		{
			current = first->next;
			delete first;
			first = current;
		}
		delete[] first;
		delete[] current;
		delete[] tail;
	}
};
template <typename T>
class StIC : public virtual JavaIterator<T const&>
{
private:
	typename StaticArray<T>::template N<T>const *iterator;
public:
	StIC(StaticArray<T>const & st) :iterator(st.first) {}
	T const& next()
	{
		T const& c = iterator->value;
		iterator = iterator->next;
		return c;
	}
	virtual bool hasNext() const {
		return iterator != nullptr;
	};
	virtual ~StIC() {};
};
template<typename T>
class StI : public virtual JavaIterator<T&> {
private:
	typename StaticArray<T>::template N<T> *iterator;
public:
	StI(StaticArray<T> &st) :iterator(st.first) {}
	virtual T& next()
	{
		T& c = iterator->value;
		iterator = iterator->next;
		return c;
	}
	virtual bool hasNext() const {
		return iterator != nullptr;
	};
	virtual ~StI() {};
};

template <typename T>
class StaticDeque : public Deque<T>
{
private:
	template <typename T>
	struct Node {
		T value;
		Node* next;
	};
	Node<T> *first;
	Node<T> *tail;
	Node<T> *current;
	int s, size;
public:
	friend class SDI<T>;
	friend class SDIC<T>;
	StaticDeque(int sz, T const& value)
	{
		Node<T> *i = new Node<T>();
		i->next = NULL;
		i->value = value;
		first = i;
		tail = i;
		s = sz - 1;
		size = 1;
	};
	StaticDeque(const StaticDeque &d)
	{
		current = d.first;
		s = d.Size();
		while (current != NULL)
		{
			pushBack(current->value);
			current = current->next;
		}
	};
	StaticDeque<T>& operator =(const StaticDeque &d)
	{
		current = d.first;
		s = d.Size();
		while (current != NULL)
		{
			pushBack(current->value);
			current = current->next;
		}
		return *this;
	};
	virtual int Size() const
	{
		return size;
	};
	virtual bool pushFront(T const& value)
	{
		if (s == 0) { return false; }
		else
		{
			Node<T> *i = new Node<T>();
			i->value = value;
			i->next = first;
			first = i;
			--s;
			size++;
		}
		return true;
	};
	virtual bool pushBack(T const& value)
	{
		if (s == 0) { return false; }
		else
		{
			Node<T> *i = new Node<T>();
			i->value = value;
			i->next = NULL;
			if (tail == NULL)
			{
				first = i;
			}
			else tail->next = i;
			tail = i;
			--s;
			size++;
		}
		return true;
	};
	virtual T popFront()
	{
		T c = NULL;
		if (first != NULL)
		{
			c = first->value;
			first = first->next;
			s++;
			size = size - 1;
		}
		return c;
	};
	virtual T popBack()
	{
		T c;
		if (tail == NULL) { c = NULL; }
		else
		{
			c = tail->value;
			if (first == tail)
			{
				first = NULL;
				tail = NULL;
			}
			else
			{
				current = first;
				while (true)
				{
					if (current->next == tail)
					{
						c = tail->value;
						tail = current;
						tail->next = NULL;
						break;
					}
					current = current->next;
				}
			}
			s++;
			size = size - 1;
		}
		return c;
	};
	virtual T peekFront() const
	{
		T c;
		if (first == NULL) { c = NULL; }
		else { c = first->value; }
		return c;
	};
	virtual T& peekFront()
	{
		T c;
		if (first == NULL) { c = NULL; }
		else { c = first->value; }
		return c;
	}
	virtual T peekBack() const
	{
		T c;
		if (tail == NULL) { c = NULL; }
		else { c = tail->value; }
		return c;
	};
	virtual T& peekBack()
	{
		T c;
		if (tail == NULL) { c = NULL; }
		else { c = tail->value; }
		return c;
	}
	virtual JavaIterator<T&>* createIterator()
	{
		return new SDI<T>(*this);
	};
	virtual JavaIterator<const T&>* createIteratorC() const
	{
		return new SDIC<T>(*this);
	};
	~StaticDeque()
	{
		current = first;
		while (first != NULL)
		{
			current = first->next;
			delete first;
			first = current;
		}
		delete[] first;
		delete[] current;
		delete[] tail;
	};
};
template <typename T>
class SDIC : public virtual JavaIterator<T const&>
{
private:
	typename StaticDeque<T>::template Node<T>const *iterator;
public:
	SDIC(StaticDeque<T>const& sd) :iterator(sd.first) {}
	T const& next()
	{
		T const& c = iterator->value;
		iterator = iterator->next;
		return c;
	}
	virtual bool hasNext() const {
		return iterator != nullptr;
	};
	virtual ~SDIC() {};
};
template<typename T>
class SDI : public virtual JavaIterator<T&> {
private:
	typename StaticDeque<T>::template Node<T> *iterator;
public:
	SDI(StaticDeque<T> &sd) :iterator(sd.first) {}
	virtual T& next()
	{
		T& c = iterator->value;
		iterator = iterator->next;
		return c;
	}
	virtual bool hasNext() const {
		return iterator != nullptr;
	};
	virtual ~SDI() {};
};

int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "Russian");

	/*ContainerInterface *cont[5];
	cont[0] = new Stack(1);
	cont[1] = new Queue(2);
	cont[2] = new LinkedList(3);
	cont[3] = new StaticArray(10, 4);
	cont[4] = new StaticDeque(20, 5);
	for (int i = 0; i < 5; i++)
	{
	cout << cont[i]->toString() << endl;
	}
	for (int i = 0; i < 5; i++)
	{
	PushPopContainerInterface *p = dynamic_cast<PushPopContainerInterface*>(cont[i]);
	if (p != NULL) {
	p->push(10);
	p->push(20);
	p->push(30);
	}
	}
	for (int i = 0; i < 5; i++)
	{
	cout << cont[i]->toString() << endl;
	}
	for (int i = 0; i < 5; i++)
	{
	PushPopContainerInterface *p = dynamic_cast<PushPopContainerInterface*>(cont[i]);
	if (p != NULL) {
	p->pop();
	}
	}
	for (int i = 0; i < 5; i++)
	{
	cout << cont[i]->toString() << endl;
	}
	for (int i = 0; i < 5; i++)
	{
	Deque *d = dynamic_cast<Deque*>(cont[i]);
	if (d != NULL)
	{
	d->pushFront(1);
	d->pushFront(2);
	d->pushFront(3);
	d->pushFront(4);
	d->pushFront(84);
	d->pushFront(86);
	d->pushFront(18);
	d->pushBack(154);
	d->pushBack(105);
	d->pushBack(115);
	d->pushBack(1005);
	d->pushBack(159);
	while (d->isEmpty() == false)
	{
	cout <<d->popFront() << " ";
	}
	}
	}*/
	Stack<double> st(15.4);
	Stack<string> s("pool");
	s.push("dhi");
	s.push("ahello");
	s.push("background");
	s.push("cskfkshfskfhsfk");
	Sort<Stack<string>>(s);
	st.push(15.15);
	st.push(15.7);
	st.push(15.3);
	st.push(15.9);
	st.push(15.14);
	cout << s << endl;
	Stack<double> a = (st);
	cout << (a == st) << endl;
	Sort<Stack<double>>(a);
	cout << a << endl;
	StaticDeque<double> sa(10, 1.5);
	sa.pushFront(1.7);
	sa.pushBack(1.4);
	sa.pushFront(1.3);
	sa.pushBack(1.8);
	sa.pushFront(1.1);
	StaticDeque<double> s1(sa);
	cout << sa << endl;
	cout << s1 << endl;
	/*while (a->push(count++));
	cout << "Содержимое StaticArray:" << a->toString() << endl;
	cout << "Введите индекс искомого элемента: ";
	cin >> k;
	cout << "Значение элемента с искомым индексом: " << a->get(k) << endl;
	cout << "Введите индекс элемента, значение которого хотите изменить: ";
	cin >> k;
	cout << "Введите новое значение: ";
	cin >> l;
	a->set(k, l);
	cout << "Содержимое StaticArray:" << a->toString() << endl;
	cout << "Введите количество элементов, которые хотите изъять: ";
	cin >> k;
	while (k != 0)
	{
	a->pop();
	--k;
	}
	cout << "Проверим, пуст ли StaticArray: " << a->isEmpty() << endl;
	cout << "Первый элемент StaticArray: " << a->peek() << endl;
	cout << "Содержимое StaticArray:" << a->toString() << endl;
	cout << "Размер StaticArray: " << a->Size() << endl;
	cout << endl << "Введите размер для StaticDeque: ";
	cin >> n2;*/
	/*StaticDeque<int> *d = new StaticDeque<int>(n2, count);
	count++;
	cout << "Сколько элементов добавить в начало для StaticDeque: ";
	cin >> k;
	while (true)
	{
	if (k != 0)
	{
	ind = d->pushFront(count);
	--k;
	if (ind == false) { break; }
	else { count++; }
	}
	else
	{
	ind = d->pushBack(count);
	if (ind == false) { break; }
	else { count++; }
	}
	}
	cout << "Содержимое StaticDeque:" << d->toString() << endl;
	cout << "Введите количество элементов, которые хотите изъять из начала: ";
	cin >> k;
	while (k != 0)
	{
	d->popFront();
	--k;
	}
	cout << "Введите количество элементов, которые хотите изъять с конца: ";
	cin >> k;
	while (k != 0)
	{
	d->popBack();
	--k;
	}
	cout << "Проверим, пуст ли StaticDeque:: " << d->isEmpty() << endl;
	cout << "Первый элемент: " << d->peekFront() << endl;
	cout << "Последний элемент: " << d->peekBack() << endl;
	cout << endl << "Содержимое StaticDeque:" << d->toString() << endl;
	cout << "Размер StaticDeque: " << d->Size() << endl;*/

	system("pause");
	return 0;
}
