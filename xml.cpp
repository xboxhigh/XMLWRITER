#include "XMLWriterNorm.h"

int main(int argc, char **argv)      {

	XMLWRITER Writer;
	
	string raw = "http://yahoo.com.twORHNGORGPIERNIGONREIKGNMRIGPNRONGRG";
	string modified = "";
	
	modified.append("HTTP/1.0 200 OK\r\n");
	modified.append("Date: Sun, 18 Mar 2012 12:35:33 GMT\r\n");
	modified.append("Server:\r\n");
	modified.append("Last-Modified: Sat, 17 Mar 2012 16:05:03 GMT\r\n");
	modified.append("ETag: \"70357a-1ac3b-4bb727ce7f5ae\"\r\n");
	modified.append("Accept-Ranges: bytes\r\n");
	modified.append("Vary: Accept-Encoding,User-Agent\r\n");
	modified.append("Content-Encoding: gzip\r\n");
	modified.append("Content-Length: 24592\r\n");
	modified.append("Content-Type: text/html\r\n");
	modified.append("Age: 1\r\n");
	modified.append("Connection: close\r\n");
	cout << modified << endl;
	Writer.WriteMetaToFileWithXMLTag("header", modified);
	
	return 0;
}
  
  