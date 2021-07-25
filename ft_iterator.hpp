#ifndef UNTITLED_FT_ITERATOR_HPP
#define UNTITLED_FT_ITERATOR_HPP

namespace vector_iterator {
	template<typename T>
	class ft_iterator {
	public:
		typedef	T							value_type;
		typedef	std::ptrdiff_t				difference_type;
		typedef	value_type*					pointer;
		typedef	value_type&					reference;
		typedef	std::random_access_iterator	iterator_category;
	private:
		pointer		m_ptr;
	public:
		explicit ft_iterator(pointer ptr) : m_ptr(ptr) {};
		~ft_iterator() {};
		ft_iterator(const ft_iterator &copy) { *this = copy };
		ft_iterator& operator= (const ft_iterator &iter)
		{
			if (this == &iter)
				return (*this);
			m_ptr = iter.m_ptr;
			return (*this);
		}
	};
}

#endif
