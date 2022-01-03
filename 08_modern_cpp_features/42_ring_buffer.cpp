#include <iostream>
#include <string>
#include <vector>


template <class T>
class ring{
private:
	int m_pos;
	int m_size;
	T *m_values;
	class iterator;
public:
	ring(int size): m_pos(0), m_size(size), m_values(NULL)
	{
		m_values = new T[size];
	}

	~ring(){
		delete [] m_values;
	}

	int size()
	{
		return m_size;
	}

	void add(T value)
	{
		m_values[ m_pos++ ] = value;
		m_pos = (m_pos == m_size) ? 0 : m_pos;
	}

	void print(){
		std::cout<<"[";
		for (int i = 0; i<m_size; i++){
			std::cout<<m_values[i]<<" , ";
		}
		std::cout<<"]\n";
	}

	iterator begin(){ return iterator( 0      , *this ); }
	iterator   end(){ return iterator( m_size , *this ); }
	T & get(int pos) { return m_values[pos];}
};

template<class T>
class ring<T>::iterator{
private:
	int m_pos_i;
	ring & m_ring;
public:
	iterator(int pos, ring & aRing): m_pos_i(pos), m_ring(aRing){}

	iterator &operator++(){
		m_pos_i++;
		return *this;
	}

	T &operator*()
    {
        return m_ring.get(m_pos_i);
    }
    
    bool operator!=(const iterator &other) const{
        return m_pos_i != other.m_pos_i;
    }
};

int main(){

	ring<std::string> buf(3);
	std::cout<<"Helo World\n";
	std::vector<std::string> lyrics = {
			 "I thought the king"
			,"had more affected "
			,"the Duke of Albany "
			,"than Cornwall"
			,"It did always seem so to us"
			,"but now, in the"
			,"division of the kingdom"
			,"it appears not "
			,"which of the dukes he values most;"
		};

	for (int i=0; i<3; i++){
		buf.add(lyrics[i]);
	}
	std::cout<<"Auto Range Test: \n";
	int k=0;
	for (auto s: buf){
		std::cout << k++ << ":" << s <<"\n";
	}
	std::cout<<"============\n";
	


	for (auto l:lyrics){
		buf.add(l);
		buf.print();
	}
}