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

	// function:	split the string into vector which is divided by the flag.
	//				"" will not be ignored.
	//				if string is empty or equal to "" a empty vector will be returned.
	// in:			in_str, in_strFlag(only one character supported)
	// out:			out_vec(The vector will be cleared first)
	// example:		";a;bc;def"			=> "" a bc def
	//				"a;bc;def"			=> a bc def
	//				"a;bc;def;"			=> a bc def
	//				"a;;def"			=> a "" def
	//				"a;bd;def;;"		=> a bc def ""
	//				"a"					=> a
	static bool splitStr2Vec(
		const std::string in_str, 
		const std::string in_strFlag, 
		std::vector<std::string> & out_vec
		);

	// function:	merge strings in vector into one string separated by flag
	// in:			in_vec, in_strFlag
	// out:			out_str(will be cleared first; end with in_strFlag)
	static void mergeVec2Str(
		const std::vector<std::string> in_vec,
		const std::string in_strFlag,
		std::string & out_str
		);

	// incomplete
	static bool replaceAWithB(std::string & inout_str, 
		const std::string in_strA,  
		const std::string in_strB
		);
};	// class XString

XSPACE_END

#endif