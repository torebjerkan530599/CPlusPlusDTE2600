#include "header.h"

TinyForwardList::MinimalIterator::MinimalIterator() noexcept
{
	//Default constructor : used to make the end iterator.

	//m_current_node = nullptr;

	while(m_current_node)
	{ 
		m_current_node = m_current_node->next;
	}

	//*this = m_current_node;

}

TinyForwardList::MinimalIterator::MinimalIterator(TinyForwardList::Node* node) noexcept
{
	//Constructor specifying a node: used to make the begin iterator.
	m_current_node = node;
	
}

TinyForwardList::MinimalIterator&
TinyForwardList::MinimalIterator::operator++() noexcept
{
	//Pre incremental operator (operator++) : used for the act of iterating one forward.
	this->m_current_node = this->m_current_node->next;
	return *this;
}

bool
TinyForwardList::MinimalIterator::operator!=(const MinimalIterator& other) const noexcept
{
	//The not equals operator: used for comparing objects by most algorithms.
	return other.m_current_node != this->m_current_node;
}

Name
TinyForwardList::MinimalIterator::operator*() const noexcept
{
	//Dereference operator: used for accessing the internal element value.
	return m_current_node->value;
}
