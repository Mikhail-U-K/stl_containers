#ifndef UNTITLED_FT_ITERATOR_HPP
#define UNTITLED_FT_ITERATOR_HPP

namespace vector_iterator {
	template<typename T>
	class ft_iterator {
	public:
		typedef	T								value_type;
		typedef	std::ptrdiff_t					difference_type;
		typedef	value_type*						pointer;
		typedef	value_type&						reference;
		typedef	std::random_access_iterator_tag	iterator_category;
	private:
		pointer		m_ptr;
	public:
		explicit ft_iterator(pointer ptr) : m_ptr(ptr) {};
		~ft_iterator() {};
		ft_iterator(const ft_iterator &copy) { *this = copy ;};
		ft_iterator& operator= (const ft_iterator &iter)
		{
			if (this == &iter)
				return (*this);
			m_ptr = iter.m_ptr;
			return (*this);
		}
		ft_iterator& operator++ () {++m_ptr; return *this;};
		ft_iterator operator++ (int ) {
			ft_iterator tmp(m_ptr);
			++m_ptr;
			return (tmp);
		};
		ft_iterator& operator-- () {--m_ptr; return *this;};
		ft_iterator operator-- (int ) {
			ft_iterator	tmp(m_ptr);
			++m_ptr;
			return (tmp);
		};
		ft_iterator& operator+= (difference_type value) { m_ptr += value; return *this;};
		ft_iterator& operator-= (difference_type value) { m_ptr -= value; return *this;};
		reference operator[] (difference_type value) {return *(m_ptr + value);};
		
		bool operator== (const ft_iterator &other) {return (m_ptr = other.m_ptr);};
		bool operator!= (const ft_iterator &other) {return (m_ptr != other.m_ptr);}
		reference operator* () {return *m_ptr;};
		reference operator-> () {return *m_ptr;};
		
//		pointer operator* () {return m_ptr;};
//		pointer operator-> () {return m_ptr;};
	};
}

#endif
