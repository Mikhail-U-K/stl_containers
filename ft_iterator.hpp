#ifndef UNTITLED_FT_ITERATOR_HPP
#define UNTITLED_FT_ITERATOR_HPP

namespace vector_iterator {

	template<typename T>
	class	ft_const_iterator;

	template<typename T>
	class ft_iterator {
	public:
		typedef	T								value_type;
		typedef	std::ptrdiff_t					difference_type;
		typedef	value_type*						pointer;
		typedef	value_type&						reference;
		typedef	std::random_access_iterator_tag	iterator_category;
		typedef	ft_const_iterator<value_type>	const_iterator;
	private:
		pointer		m_ptr;
	public:
		explicit ft_iterator(pointer ptr) : m_ptr(ptr) {}
		ft_iterator() : m_ptr(nullptr) {}
		~ft_iterator() {}
		ft_iterator(const ft_iterator &copy) {*this = copy;}
		ft_iterator(const const_iterator &copy) {*this = copy;}

		ft_iterator& operator= (const ft_iterator &iter)
		{
			if (this == &iter)
				return (*this);
			m_ptr = iter.m_ptr;
			return (*this);
		}
		ft_iterator& operator= (const const_iterator &iter)
		{
			if (this == &iter)
				return (*this);
			m_ptr = &(*iter);
			return (*this);
		}
		ft_iterator& operator++ () {++m_ptr; return *this;};
		ft_iterator operator++ (int ) {
			ft_iterator tmp(m_ptr);
			++m_ptr;
			return (tmp);
		}
		ft_iterator& operator-- () {--m_ptr; return *this;}
		ft_iterator operator-- (int ) {
			ft_iterator	tmp(m_ptr);
			++m_ptr;
			return (tmp);
		}
		ft_iterator& operator+= (difference_type value) {m_ptr += value; return *this;}
		ft_iterator& operator-= (difference_type value) {m_ptr -= value; return *this;}
		ft_iterator operator- (difference_type n) const {return ft_iterator(m_ptr - n);}
		ft_iterator operator+ (difference_type n) const {return ft_iterator(m_ptr + n);}

		reference operator[] (difference_type value) {return *(m_ptr + value);}
		reference operator* () {return *m_ptr;}
		pointer operator-> () {return m_ptr;}

		bool operator== (const ft_iterator &other) {return (m_ptr = other.m_ptr);}
		bool operator!= (const ft_iterator &other) {return (m_ptr != other.m_ptr);}
		bool operator> (const ft_iterator &ref) const {return m_ptr > ref.m_ptr;}
		bool operator>= (const ft_iterator &ref) const {return m_ptr >= ref.m_ptr;}
		bool operator< (const ft_iterator &ref) const {return m_ptr < ref.m_ptr;}
		bool operator<= (const ft_iterator &ref) const {return m_ptr <= ref.m_ptr;}

		bool operator== (const const_iterator &other) {return (m_ptr = &(*other));}
		bool operator!= (const const_iterator &other) {return (m_ptr != &(*other));}
		bool operator> (const const_iterator &ref) const {return m_ptr > &(*ref);}
		bool operator>= (const const_iterator &ref) const {return m_ptr >= &(*ref);}
		bool operator< (const const_iterator &ref) const {return m_ptr < &(*ref);}
		bool operator<= (const const_iterator &ref) const {return m_ptr <= &(*ref);}
	};


	template<typename T>
	class ft_const_iterator {
	public:
		typedef	T									value_type;
		typedef	std::ptrdiff_t						difference_type;
		typedef	value_type							*pointer;
		typedef	value_type							&reference;
		typedef	std::random_access_iterator_tag		iterator_category;
		typedef	ft_iterator<value_type>				iterator;
	private:
		pointer const_ptr;
	public:
		explicit ft_const_iterator(pointer ptr) : const_ptr(ptr) {}
		ft_const_iterator() : const_ptr(nullptr) {}
		~ft_const_iterator() {};

		ft_const_iterator(const ft_const_iterator &copy) {*this = copy;}
		ft_const_iterator(const iterator &copy) {*this = copy;}

		ft_const_iterator& operator= (const ft_const_iterator &iter)
		{
			if (this == &iter)
				return (*this);
			const_ptr = iter.const_ptr;
			return (*this);
		}
		ft_const_iterator& operator= (const iterator &iter)
		{
			if (this == &iter)
				return (*this);
			const_ptr = &(*iter);
			return (*this);
		}

		ft_const_iterator& operator+= (difference_type value) const {const_ptr += value; return *this;}
		ft_const_iterator& operator-= (difference_type value) const {const_ptr -= value; return *this;}
		ft_const_iterator operator- (difference_type n) const {return ft_const_iterator(const_ptr - n);}
		ft_const_iterator operator+ (difference_type n) const {return ft_const_iterator(const_ptr + n);}

		reference operator[] (difference_type value) {return *(const_ptr + value);}
		const reference operator* () {return *const_ptr;}
		const pointer operator-> () {return const_ptr;}

		bool operator== (const ft_const_iterator &other) const {return (const_ptr = other.const_ptr);}
		bool operator!= (const ft_const_iterator &other) const {return (const_ptr != other.const_ptr);}
		bool operator> (const ft_const_iterator &ref) const {return const_ptr > ref.const_ptr;}
		bool operator>= (const ft_const_iterator &ref) const {return const_ptr >= ref.const_ptr;}
		bool operator< (const ft_const_iterator &ref) const {return const_ptr < ref.const_ptr;}
		bool operator<= (const ft_const_iterator &ref) const {return const_ptr <= ref.const_ptr;}

		bool operator== (const iterator &other) const {return (const_ptr = &(*other));}
		bool operator!= (const iterator &other) const {return (const_ptr != &(*other));}
		bool operator> (const iterator &ref) const {return const_ptr > &(*ref);}
		bool operator>= (const iterator &ref) const {return const_ptr >= &(*ref);}
		bool operator< (const iterator &ref) const {return const_ptr < &(*ref);}
		bool operator<= (const iterator &ref) const {return const_ptr <= &(*ref);}
	};
}

#endif
