#include "header.h"
#include <stdexcept>

// The <signature> definition(s)
namespace dte2600 {
	char string::getCharAtEx(int index) const
	{
		if (index <= 0 || index >= static_cast<int>(m_data.size()))
		{ 
			throw std::out_of_range{"index out of range"};
		}

		char ch = m_data.at(index);
		return ch;
	}
	
	
	std::optional<char> string::getCharAtOpt(int index) const 
	{ 
		if (index <= 0 || index >= static_cast<int>(m_data.size()))
		{
			return std::nullopt;
		}

		char ch = m_data.at(index);
		return ch;
	
	
	}
	
	
	char string::getCharAtErrBit(int index) const 
	{
		if (index <= 0 || index >= static_cast<int>(m_data.size()))
		{
			m_access_error = true;
			return{};
		}
		return m_data.at(index);
	}
	
	
	char string::getCharAtContracts(int index) const 
	{
		if(DTE2600_STRING_CHECK_RANGE)
		{ 
			if (index <= 0 || index >= int(m_data.size()))
			{
				throw std::out_of_range{ "index out of range" };
			}
		}
		return m_data.at(index);
	}

	
	bool string::accessError() const 
	{
		return m_access_error;
	}
	void string::resetAccessErrorState() 
	{
		m_access_error = false;
	}
}