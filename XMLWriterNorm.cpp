#include "XMLWriterNorm.h"

XMLWRITER::XMLWRITER()	{
	Init();
}

void XMLWRITER::Init()	{
	urlData = "";
	metaData = "";
}

void XMLWRITER::SetMetaData(string _data)	{
	metaData.append(_data.c_str(), _data.length());
}

void XMLWRITER::SetURLData(string _data)	{
	urlData.append(_data.c_str(), _data.length());
}

int XMLWRITER::WriteURLToFileWithXMLTag(string _path, string _content)	{

	
	return 0;
}

///	Parameters:
///		_path : the storing path which you want to store the metadata file
///		_hInfo : http header information
///	Return value :
///		0 means write file successfully, otherwise return 1
int XMLWRITER::WriteMetaToFileWithXMLTag(string _path, string _hInfo)	{
	
	CURL *curl_handle;
	string buff = "";
	char *buf;
	/* init the curl session */ 
	//curl_handle = curl_easy_init();
	
	curl_easy_getinfo(curl_handle, CURLINFO_RESPONSE_CODE, buf);
	
	cout << buff << endl;
	/*
	fstream oFile;
	oFile.open(_path.c_str(), ios::out);
	oFile.close();
	*/
	return 0;
}

string XMLWRITER::AddTags(string _rawInfo, string _tagName)	{
	
	string resultURL = "";

	resultURL.append("<", 1);
	resultURL.append(_tagName.c_str(), _tagName.length());
	resultURL.append(">", 1);
	resultURL.append(_rawInfo.c_str(), _rawInfo.length());
	resultURL.append("</", 2);
	resultURL.append(_tagName.c_str(), _tagName.length());
	resultURL.append(">", 1);
	
	return resultURL;
}

/// return 0 means the rawURL is recognizable, otherwise return 1
///	value of parameter "_type" means	:	
///		a : <a href> tag
///		b : <base href> tag
///		i : <img src> tag
///		l : <link href> tag
///		f : <iframe src> tag
///		A : <audio> tag
///		V : <video> tag
int XMLWRITER::URLWithXMLTag(string _rawURL, string& _modifiedURL, char _type)	{

	switch(_type)	{
	case 'a':
		_modifiedURL = AddTags(_rawURL, "href");
	break;
	case 'b':
		_modifiedURL = AddTags(_rawURL, "href");
	break;
	case 'i':
		_modifiedURL = AddTags(_rawURL, "src");
	break;
	case 'l':
		_modifiedURL = AddTags(_rawURL, "href");
	break;
	case 'f':
		_modifiedURL = AddTags(_rawURL, "src");
	break;
	case 'A':
		_modifiedURL = AddTags(_rawURL, "audio");
	break;
	case 'V':
		_modifiedURL = AddTags(_rawURL, "video");
	break;
	default:
		cout << "The type can't be recognized !" << endl;
		return 1;
	break;	
	}
	
	return 0;
}

/// return 0 means the header information is recognizable, otherwise return 1
///	value of parameter "_type" means	:
///		u : current fetch URL
///		c : status code information
///		v : date information, means the time we visit the web page
///		l : last modified information, means the last time which the web page been modified
///		t : transfer encoding information
///		s : server information, means the web server information
///		d : location information, means if the status code is 3XX, then the redirect url information
///		T : content type information
///		L : content length information
///		F : body information, the storing file path
///		B : body information, the begin offset in storing file
///		E : body information, the end offset in storing file
int XMLWRITER::MetaDataWithXMLTag(string _rawData, string& _modifiedData, char _type)	{
	
	switch(_type)	{
	case 'u':
		_modifiedData = AddTags(_rawData, "rawURL");
	break;
	case 'c':
		_modifiedData = AddTags(_rawData, "status");
	break;
	case 'v':
		_modifiedData = AddTags(_rawData, "visit");
	break;
	case 'l':
		_modifiedData = AddTags(_rawData, "modified");
	break;
	case 't':
		_modifiedData = AddTags(_rawData, "encoding");
	break;
	case 's':
		_modifiedData = AddTags(_rawData, "server");
	break;
	case 'd':
		_modifiedData = AddTags(_rawData, "location");
	break;
	case 'T':
		_modifiedData = AddTags(_rawData, "type");
	break;
	case 'L':
		_modifiedData = AddTags(_rawData, "length");
	break;
	case 'F':
		_modifiedData = AddTags(_rawData, "path");
	break;
	case 'B':
		_modifiedData = AddTags(_rawData, "beg");
	break;
	case 'E':
		_modifiedData = AddTags(_rawData, "end");
	break;
	default:
		cout << "The tpye is unrecogonizing !" << endl;
		return 1;
	break;	
	}
	
	return 0;
}