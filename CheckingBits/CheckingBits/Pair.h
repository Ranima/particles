#pragma once

class Pair
{
public:
	Pair(char* a_key, char* a_value);

	const char* GetKey() const;

	const char* GetValue() const;

private:
	Pair(const Pair &obj);

	char* m_key;
	char* m_value;
};