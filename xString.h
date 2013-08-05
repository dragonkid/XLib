#ifndef _XSTRING_H_
#define _XSTRING_H_

#include "xDefine.h"

XSPACE_BEGIN;

class XString
{
public:
	// function:	get whether in_str is start with in_strFlag
	// in:			in_str, in_strFlag
	// out:			nop
	// return:		bool
	//				true:	start with
	//				false:	not start with
	// complete:	2013-7-23
	// examples:	("test", "test")	=>	true
	//				("test123", "test") =>	true
	//				("test123", "st1")	=>	false
	//				("test", "")		=>	true
	//				("", "")			=>	true
	//				("123", "1234")		=>	false
	static bool startWith(const std::string in_str, const std::string in_strFlag);

	// function:	get whether in_str is end with in_strFlag
	// in:			in_str, in_strFlag
	// out:			nop
	// return:		bool
	//				true:	end with
	//				false:	not end with
	// complete:	2013-7-23
	// examples:	("test", "test")	=>	true
	//				("123test", "test")	=>	true
	//				("123test", "st1")	=>	false
	//				("test", "")		=>	true
	//				("", "")			=>	true
	//				("123", "1234")		=>	false
	static bool endWith(const std::string in_str, const std::string in_strFlag);

	// incomplete
	static void spliteStr2Vec(
		const std::string in_str, 
		const std::string in_strFlag, 
		std::vector<std::string>& out_vec
		);
};	// class XString

XSPACE_END

#endif