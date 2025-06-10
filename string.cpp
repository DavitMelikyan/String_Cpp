#include <iostream> 

class String {
public:
	String() : m_data(new char[1]), m_size(0) {
		m_data[0] = '\0';	
	}
	String(const char* str) {
        	if (str) {
			int countl = 0;
			for (int i = 0; str[i]; ++i) {
				++countl;
			}
			m_size = countl;
			m_data = new char[m_size + 1];
			for (int i = 0; i < m_size; ++i) {
				m_data[i] = str[i];
			}
			m_data[m_size] = '\0';
		} else {
            		m_size = 0;
            		m_data = new char[1];
            		m_data[0] = '\0';
        	}
	}
	String(String& other) : m_size{other.m_size} {
		m_data = new char[m_size + 1];
		for (int i = 0; i < m_size; ++i) {
			m_data[i] = other.m_data[i];
		}
		m_data[m_size] = '\0';
	}
	String(String&& other) : m_size{other.m_size}, m_data{other.m_data} {
		other.m_data = nullptr;
		other.m_size = 0;
	}
	String& operator=(String& other) {
		if (this == &other) {
			return *this;
		}
		delete [] m_data;
		m_size = other.m_size;
		m_data = new char[m_size + 1];
                for (int i = 0; i < m_size; ++i) {
                        m_data[i] = other.m_data[i];
                }
                m_data[m_size] = '\0';
		return *this;
	}
	String& operator=(String&& other) {
		if (this == &other) {
                        return *this;
                }
		m_size = other.m_size;
		delete [] m_data;
		m_data = other.m_data;
		other.m_data = nullptr;
		other.m_size = 0;
		return *this;
	}	 	
	~String() {
		delete[] m_data;
		m_data = nullptr;
	}
	size_t len() const {
		return m_size;
	}
	const char* str() const {
     		return m_data;
    	}
	void print() const {
        	std::cout << m_data << std::endl;
    	}
private:
	char* m_data;
	size_t m_size;
};


int main() {
	String str1;
	String str2("Hello World!");
	std::cout << str1.len() << std::endl;
	std::cout << str2.len() << std::endl;
	std::cout << str1.str() << std::endl;
	std::cout << str2.str() << std::endl;
	str1 = str2;
	std::cout << str1.len() << std::endl;
        std::cout << str2.len() << std::endl;
	str1.print();
        str2.print();  	
	str2 = std::move(str1);
	std::cout << str1.len() << std::endl;
        std::cout << str2.len() << std::endl;
        str2.print();

   	return 0;
}
