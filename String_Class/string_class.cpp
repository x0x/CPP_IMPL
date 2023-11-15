#include <cstring>
#include <iostream>

class String {
public:
  String() = default;

  // parametrised constructor
  String(const char *string) {
    std::cout << "Created\n";
    m_size = strlen(string);
    m_data = new char[m_size];
    memcpy(m_data, string, m_size);
  }

  // copy constructor
  String(const String &other) {
    std::cout << "Copied\n";
    m_size = other.m_size;
    m_data = new char[m_size];
    memcpy(m_data, other.m_data, m_size);
  }

  //   copy assignment operator
  String &operator=(const String &other) {

    std::cout << "Copy Assignment Operator\n";

    if (this == &other) {
      return *this;
    }

    m_size = other.m_size;
    m_data = new char[m_size];
    memcpy(m_data, other.m_data, m_size);

    return *this;
  }

  // move constructor
  String(String &&name) {
    std::cout << "Moved\n";
    m_size = name.m_size;
    m_data = name.m_data;

    name.m_size = 0;
    name.m_data = nullptr;
  }

  // move assignment operator
  String &operator=(String &&other) noexcept {
    std::cout << "Move assignment operator\n";

    if (this != &other) {
      m_size = other.m_size;
      m_data = other.m_data;
      other.m_size = 0;
      other.m_data = nullptr;
    }
    return *this;
  }

  ~String() {
    std::cout << "Destroyed\n";
    delete m_data;
  }

  void Print() {
    for (int i = 0; i < m_size; i++) {
      std::cout << m_data[i];
    }
    std::cout << "\n";
  }

private:
  char *m_data;
  int m_size;
};

class Entity {
public:
  Entity(const String &name) : m_name(name) {}

  Entity(String &&name) : m_name(std::move(name)) {}

  void PrintName() { m_name.Print(); }

private:
  String m_name;
};

int main() {

  String string = "hello";
  String dest;

  string.Print();
  dest.Print();

  dest = std::move(string);

  dest.Print();
  string.Print();
}
