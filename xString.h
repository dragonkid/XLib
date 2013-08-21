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
	// return:		DBool
	//				true:	start with
	//				false:	not start with
	// complete:	2013-7-23
	// examples:	("test", "test")	=>	true
	//				("test123", "test") =>	true
	//				("test123", "st1")	=>	false
	//				("test", "")		=>	true
	//				("", "")			=>	true
	//				("123", "1234")		=>	false
	static DBool startWith(const DString in_str, const DString in_strFlag);

	// function:	get whether in_str is end with in_strFlag
	// in:			in_str, in_strFlag
	// out:			nop
	// return:		DBool
	//				true:	end with
	//				false:	not end with
	// complete:	2013-7-23
	// examples:	("test", "test")	=>	true
	//				("123test", "test")	=>	true
	//				("123test", "st1")	=>	false
	//				("test", "")		=>	true
	//				("", "")			=>	true
	//				("123", "1234")		=>	false
	static DBool endWith(const DString in_str, const DString in_strFlag);

	// function:	split the string into vector which is divided by the flag.
	//				"" will not be ignored.
	//				if string is empty or equal to "" an empty vector will be returned.
	// in:			in_str, in_strFlag(only one character supported)
	// out:			out_vec(The vector will be cleared first)
	// return:		DBool
	//				true:	split success
	//				false:	input parameter invalid
	// example:		";a;bc;def"			=> "" a bc def
	//				"a;bc;def"			=> a bc def
	//				"a;bc;def;"			=> a bc def
	//				"a;;def"			=> a "" def
	//				"a;bd;def;;"		=> a bc def ""
	//				"a"					=> a
	static DBool splitStr2Vec(
		const DString in_str, 
		const DString in_strFlag, 
		std::vector<DString> & out_vec
		);

	// function:	merge strings in vector into one string separated by flag
	// in:			in_vec, in_strFlag
	// out:			out_str(will be cleared first; end with in_strFlag)
	// return:		void
	static void mergeVec2Str(
		const std::vector<DString> in_vec,
		const DString in_strFlag,
		DString & out_str
		);

	// function:	replace A with B
	// in:			inout_str, in_strA, in_strB
	// out:			inout_str(the string will be modified; 
	//						  return prime string if there is no in_strA)
	// return:		void
	static void replaceAWithB(DString & inout_str, 
		const DString in_strA,  
		const DString in_strB
		);

	// function:	get substr in in_str between in_strStartFlag and in_strEndFlag
	//				search string from start to end
	// in:			in_str, in_strStartFlag, in_strEndFlag
	// out:			out_str(will be cleared first)
	// return:		DBool
	//				true:	get substr success
	//				false:	get substr failed
	// example:		"<a>asdfasdf</a>"		=>	true	asdfasdf
	//				"adf;asdfas;fa"			=>	true	asdfas
	//				"adf;asdf"				=>	false	""
	//				"<a>asdf</a>wqe</a>"	=>	true	asdf
	static DBool subStrS2E(const DString & in_str,
		const DString & in_strStartFlag,
		const DString & in_strEndFlag,
		DString & out_str
		);

	// function:	get substr in in_str between in_strStartFlag and in_strEndFlag
	//				search string from end to start
	//				reference function subStrS2ENarrow
	static DBool subStrE2S(const DString & in_str,
		const DString & in_strStartFlag,
		const DString & in_strEndFlag,
		DString & out_str
		);

	// function:	get substr in in_str between in_strStartFlag and in_strEndFlag
	//				in_strStartFlag first occurence in in_str
	//				in_strEndFlag last occurence in in_str
	//				reference function subStrS2ENarrow
	static DBool subStrWide(const DString & in_str,
		const DString & in_strStartFlag,
		const DString & in_strEndFlag,
		DString & out_str
		);
};	// class XString

XSPACE_END

#endif