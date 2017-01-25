#include "Pair.h"

Pair::Pair(char * a_key, char * a_value)
{
	m_key	= a_key;
	m_value	= a_value;
}

const char * Pair::GetKey() const
{
	return m_key;
}

const char * Pair::GetValue() const
{
	return m_value;
}
