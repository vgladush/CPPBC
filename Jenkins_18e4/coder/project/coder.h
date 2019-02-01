/*
 * coder.h
 *
 *  Created for: GlobalLogic Basecamp
 *       Author: vitalii.lysenko
 *
 * Coder class header.
 *
 * You have to change this file to fix build errors, and make
 * the unit tests passed.
 *
 */

#ifndef CODER_H
#define CODER_H


/*
 * This function was pre-compiled and is provided as a part of the
 * static library.
 *
 */
void encode( char* buf, int size );

// #pragma pack(push, 1)

/*
 * Coder class header.
 *
 */
class Coder
{
public:
	Coder();
	Coder(const Coder &cod);
	~Coder();
	void set( const char* buf, int size );
	char* buf() const;
	int size() const;

	void encode();
	void decode();
	void operator=(const Coder &cod);
	static char* sss;

private:
	char* m_buf;
	int m_size;
};

// #pragma pack(pop)

#endif // CODER_H