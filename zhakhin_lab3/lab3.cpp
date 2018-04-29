#include <assert.h>
#include <algorithm> // std::copy, std::rotate
#include <cstddef> // size_t
#include <initializer_list>
#include <stdexcept>
#include <iostream>
using namespace std;

  template <typename Type>
  class vectorm
  {
  public:
    typedef Type* iterator;
    typedef const Type* const_iterator;

    typedef Type value_type;

    typedef value_type& reference;
    typedef const value_type& const_reference;

    typedef std::ptrdiff_t difference_type;

    explicit vectorm(size_t count = 0)
        :m_first(count ? new Type[count]() : nullptr)
        ,m_last(count ? (m_first + count) : nullptr)
    {
 		   cout << "Конструктор вектора по умолчанию" << endl;
 	  }

    template <typename InputIterator>
    vectorm(InputIterator first, InputIterator last)
        :m_first((last - first) ? new Type[last - first]() : nullptr)
 		,m_last((last - first) ? (m_first + (last - first)) : nullptr)
 	{
    cout << "Конструктор вектора с содержимым диапазона" << endl;
 		std::copy(first, last, m_first);
 	}

    vectorm(std::initializer_list<Type> init)
      	:m_first(init.size() ? new Type[init.size()]() : nullptr)
 		,m_last(init.size() ? (m_first + init.size()) : nullptr)
 	{
    cout << "Конструктор инициализация списком" << endl;
 		std::copy(init.begin(), init.end(), m_first);
	}

    vectorm(const vectorm& other)
      	: m_first(other.size() ? new Type[other.size()]() : nullptr)
 		, m_last(other.size() ? (m_first + other.size()) : nullptr)
 	{
    cout << "Конструктор копирования" << endl;
 		std::copy(other.begin(), other.end(), m_first);
 	}

    vectorm(vectorm&& other): m_first(other.m_first), m_last(other.m_last)
     {
       cout << "Конструктор перемещения" << endl;
        other.m_first = nullptr;
        other.m_last = nullptr;
     }

    ~vectorm()
    {
        cout << "деструктор" << endl;
        if(!empty())
            delete [] m_first;
    }

    //assignment operators
    vectorm& operator=(const vectorm& other)
    {
      cout << "присваивание копированием" << endl;
        if (this != &other)
        {
            if(!empty())
                delete [] m_first;
            m_first = nullptr;
            m_last = nullptr;
            if(other.size() > 0)
            {
                m_first = new Type[other.size()];
                m_last = m_first + other.size();
                std::copy(other.begin(), other.end(), m_first);
            }
        }
        return *this;
    }

    vectorm& operator=(vectorm&& other)
    {
      cout << "присваивание перемещением" << endl;
        if(this != &other)
        {
            if(!empty())
                delete [] m_first;
            m_first = other.m_first;
            m_last = other.m_last;
            other.m_first = nullptr;
            other.m_last = nullptr;
        }
        return *this;
    }

    // assign method
    template <typename InputIterator>
    void assign(InputIterator first, InputIterator last)
    {
      cout << "замена содержимым промежутка" << endl;
        if(!empty())
        {
            delete []m_first;
            m_first = nullptr;
            m_last = nullptr;
        }
        if(last-first > 0)
        {
            m_first = new Type[last-first];
            m_last = m_first+(last-first);
            std::copy(first, last, m_first);
        }
    }

    // resize methods
    void resize(size_t count)
    {
      cout << "Изменение количества элементов" << endl;
        if(count != 0)
        {
            int diffsize = count - (m_last - m_first);
            if(diffsize > 0)
            {
                iterator tmp = new Type[count];
                std::copy(m_first, m_last, tmp);
                if(!empty())
                    delete [] m_first;
                m_first = tmp;
                m_last = m_first + count;
            }
            else
            {
                m_last = m_last + diffsize;
            }
        }
        else
        {
            m_last = m_first;
            delete [] m_first;
        }
    }

    template <typename InputIterator>
    void erase1(size_t pos)
    {
      cout << "удаление элмента в позиции pos" << endl;
      size_t lenght = m_last - m_first;
      vectorm<InputIterator> other(lenght);
      for(int i=0; i<pos; i++)
      {
        other.push_back(m_first[i]);
      }
      for(int i=pos+1; i<lenght; i++)
      {
        other.push_back(m_first[i]);
      }
      m_first = other.m_first;
      m_last = other.m_last;
      other.m_first = nullptr;
      other.m_last = nullptr;
    }

    //erase methods
    iterator erase(const_iterator pos)
    {
      cout << "удаление элмента" << endl;
        if ((pos < m_first) || pos >= m_last)
            throw std::out_of_range("Error: out of range");
        size_t offset = pos - m_first;
        std::rotate(m_first + offset, m_first + offset + 1, m_last);
        resize(m_last - m_first - 1);
        return m_first + offset;
    }

    iterator erase(const_iterator first, const_iterator last)
    {
      cout << "удаление промежутка" << endl;
        if ((first < m_first) || (first > m_last) || (last < m_first) || (last > m_last))
            throw std::out_of_range("Error: out of range");
        size_t offset = first - m_first;
        size_t length = last - first;
        std::rotate(m_first + offset, m_first + offset + length, m_last);
        resize(m_last - m_first - length);
        return m_first + offset;
    }

    iterator insert(const_iterator pos, const Type& value)
    {
      cout << "вставка элемента" << endl;
        size_t offset = pos - m_first;
        push_back(value);
        std::rotate(m_first + offset, m_last-1, m_last);
        return m_first + offset;
    }

    template <typename InputIterator>
    iterator insert(const_iterator pos, InputIterator first, InputIterator last)
    {
      cout << "вставка нескольких элементов" << endl;
        size_t offset = pos - m_first;
        size_t length = last - first;
        size_t _size = size();
        iterator tmp = new Type[_size+length];
        std::copy(m_first, m_last, tmp);
        std::copy(first, last, tmp + _size);
        std::rotate(tmp + offset, tmp + _size, tmp + _size + length);
        if(!empty())
            delete [] m_first;
        m_first = tmp;
        m_last = tmp + _size + length;
        return m_first + offset;
    }

    //push_back methods
    void push_back(const value_type& value)
    {
      cout << "добавление элемента в конец" << endl;
        size_t _size = size();
        iterator tmp = new Type[_size+1];
        std::copy(m_first, m_last, tmp);
        if (!empty())
            delete [] m_first;
        m_first = tmp;
        m_last = m_first + _size + 1;
        *(m_last-1) = value;
    }

    //at methods
    reference at(size_t pos)
    {
      return checkIndexAndGet(pos);
    }

    const_reference at(size_t pos) const
    {
      return checkIndexAndGet(pos);
    }

    //[] operators
    reference operator[](size_t pos)
    {
      return m_first[pos];
    }

    const_reference operator[](size_t pos) const
    {
      return m_first[pos];
    }

    //*begin methods
    iterator begin()
    {
      return m_first;
    }

    const_iterator begin() const
    {
      return m_first;
    }

    //*end methods
    iterator end()
    {
      return m_last;
    }

    const_iterator end() const
    {
      return m_last;
    }

    //size method
    size_t size() const
    {
      return m_last - m_first;
    }

    //empty method
    bool empty() const
    {
      return m_first == m_last;
    }

  private:
    reference checkIndexAndGet(size_t pos) const
    {
      if (pos >= size())
      {
        throw std::out_of_range("out of range");
      }

      return m_first[pos];
    }

    //your private functions

  private:
    iterator m_first;
    iterator m_last;
  };
