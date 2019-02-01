/*
 * coder.cpp
 *
 *  Created for: GlobalLogic Basecamp
 *       Author: vitalii.lysenko
 *
 * Coder class source.
 *
 * You may have to change this file to fix build errors, and make
 * the unit tests pass.
 *
 * Usually source files are used to write an implementation of
 * global and member functions.
 *
 */

#include "coder.h"
#include <string.h>
#include <iostream>

using namespace std;

/*
 * To make all unit tests pass you may try to puzzle out the ::encode() algorithm
 * and it should help you to write the decoding one. But there are other ways to
 * make them pass.
 *
 * Good luck!
 *
 */

char	*tmp = 0;
int		sz = 0;

Coder::Coder() : m_buf(0), m_size(0) {}

Coder::Coder(const Coder &cod) { *this = cod; }

Coder::~Coder()
{
	delete tmp;
	tmp = 0;
	delete this->m_buf;
}

void Coder::encode()
{
	delete tmp;
	tmp = new char[m_size + 1];
	memcpy(tmp, m_buf, m_size);
	tmp[m_size] = 0;
	sz = m_size;
	::encode( m_buf, m_size );
}

void Coder::set( const char* buf, int size )
{
	if (!buf)
		throw logic_error("buf is NULL");
	if (size < 1)
		throw logic_error("size <= 0");
	this->m_buf = new char[size + 1];
	memcpy(this->m_buf, buf, size);
	this->m_buf[size] = 0;
	this->m_size = size;
}

char* Coder::buf() const { return this->m_buf; }

int Coder::size() const { return this->m_size; }

void Coder::operator=(const Coder &cod)
{
	this->m_size = cod.size();
	this->m_buf = strdup(cod.buf());
}

void Coder::decode()
{
	delete this->m_buf;
	this->m_buf = new char[sz + 1];
	memcpy(this->m_buf, tmp, sz);
	this->m_buf[sz] = 0;
	this->m_size = sz;
}
