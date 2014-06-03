#include <iostream>
#include <string.h>
#include <fstream>
#include <curl/curl.h>

using namespace std;

class XMLWRITER {
private:
	void Init();
	string AddTags(string _rawInfo, string _tagName);
	int URLWithXMLTag(string _rawURL, string& _modifiedURL, char _type);
	int MetaDataWithXMLTag(string _rawData, string& _modifiedData, char _type);
	
	string metaData;
	string urlData;	
public:
	XMLWRITER();
	~XMLWRITER() {};
	
	
	int WriteURLToFileWithXMLTag(string _path, string _content);
	int WriteMetaToFileWithXMLTag(string _path, string _hInfo);
	
	void SetMetaData(string _data);
	void SetURLData(string _data);
};
