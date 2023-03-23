#include "json/json.h"
#include <iostream>
#include <fstream>

/*本Json实例来自JSON中国
{
	"glossary": {
		"title": "example glossary",
		"GlossDiv": {
			"title": "S",
			"GlossList": {
				"GlossEntry": {
					"ID": "SGML",
					"SortAs": "SGML",
					"GlossTerm": "Standard Generalized Markup Language",
					"Acronym": "SGML",
					"Abbrev": "ISO 8879:1986",
					"GlossDef": {
						"para": "A meta-markup language, used to create markup languages such as DocBook.",
						"GlossSeeAlso": [
							"GML",
							"XML"
						]
					},
					"GlossSee": "markup"
				}
			}
		}
	}
}
*/

void JsonCppRFile() {
	using namespace Json;
	using namespace std;
	Value jsonRoot;
	Reader reader;

	ifstream ifs("test.json");

	if (reader.parse(ifs, jsonRoot)) {
		cout << "{\n\t\"" << jsonRoot.getMemberNames()[0] << "\": {" << endl;
		cout << "\t\t\"" << jsonRoot["glossary"].getMemberNames()[1] << "\": "
			<< jsonRoot["glossary"]["title"] << "," << endl;
		cout << "\t\t\"" << jsonRoot["glossary"].getMemberNames()[0] << "\": {" << endl;
		Value GlossDiv = jsonRoot["glossary"]["GlossDiv"];
		cout << "\t\t\t\"" << GlossDiv.getMemberNames()[1] << "\": "
			<< GlossDiv["title"] << "," << endl;
		cout << "\t\t\t\"" << GlossDiv.getMemberNames()[0] << "\" {" << endl;
		cout << "\t\t\t\t\"" << GlossDiv["GlossList"].getMemberNames()[0] << "\": {" << endl;
		Value GlossEntry = GlossDiv["GlossList"]["GlossEntry"];
		cout << "\t\t\t\t\t\"" << GlossEntry.getMemberNames()[5] << "\": "
			<< GlossEntry["ID"] << "," << endl;
		cout << "\t\t\t\t\t\"" << GlossEntry.getMemberNames()[6] << "\": "
			<< GlossEntry["SortAs"] << "," << endl;
		cout << "\t\t\t\t\t\"" << GlossEntry.getMemberNames()[4] << "\": "
			<< GlossEntry["GlossTerm"] << "," << endl;
		cout << "\t\t\t\t\t\"" << GlossEntry.getMemberNames()[1] << "\": "
			<< GlossEntry["Acronym"] << "," << endl;
		cout << "\t\t\t\t\t\"" << GlossEntry.getMemberNames()[0] << "\": "
			<< GlossEntry["Abbrev"] << "," << endl;
		cout << "\t\t\t\t\t\"" << GlossEntry.getMemberNames()[2] << "\": {" << endl;
		cout << "\t\t\t\t\t\t\"" << GlossEntry["GlossDef"].getMemberNames()[1] << "\": "
			<< GlossEntry["GlossDef"]["para"] << "," << endl;
		cout << "\t\t\t\t\t\t\"" << GlossEntry["GlossDef"].getMemberNames()[0] << "\": [\n"
			<< "\t\t\t\t\t\t\t" << GlossEntry["GlossDef"]["GlossSeeAlso"][0] << ",\n"
			<< "\t\t\t\t\t\t\t" << GlossEntry["GlossDef"]["GlossSeeAlso"][1] 
			<< "\n\t\t\t\t\t\t]\n\t\t\t\t\t}," << endl;
		cout << "\t\t\t\t\t\"" << GlossEntry.getMemberNames()[3] << "\": "
			<< GlossEntry["GlossSee"] << endl;
		cout << "\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t}\n}\n";
	}
}  //JsonCppRFile

void JsonCppWFile() {
	using namespace std;
	using namespace Json;
	Value JsonRoot;
	Value GlossDiv;
	Value GlossEntry;
	GlossEntry = objectValue;
	GlossEntry["ID"] = "SGML";
	GlossEntry["SortAs"] = "SGML";
	GlossEntry["GlossTerm"] = "Standard Generalized Markup Language";
	GlossEntry["Acronym"] = "SGML";
	GlossEntry["Abbrev"] = "ISO 8879:1986";
	GlossEntry["GlossDef"]["para"] = "A meta-markup language,"
		"used to create markup languages such as DocBook.";
	GlossEntry["GlossDef"]["GlossSeeAlso"] = arrayValue;
	GlossEntry["GlossDef"]["GlossSeeAlso"].append("GML");
	GlossEntry["GlossDef"]["GlossSeeAlso"][1] = "XML";
	GlossEntry["GlossSee"] = "markup";
	
	GlossDiv = objectValue;
	GlossDiv["title"] = "S";
	GlossDiv["GlossList"]["GlossEntry"] = GlossEntry;

	JsonRoot = objectValue;
	JsonRoot["glossary"]["title"] = "example glossary";
	JsonRoot["glossary"]["GlossDiv"] = GlossDiv;

#if 0
	FastWriter write;
	string jsonStr = write.write(JsonRoot);
#else
	string jsonStr = JsonRoot.toStyledString();
#endif

	ofstream ofs("test.json");
	ofs << jsonStr;
	ofs.close();
}  //JsonCppWFile

int main(int argc, char const* argv[]) {
	//请勿更改两个函数的顺序，因为JsonCpp在写Json时会对元素进行排序
	JsonCppWFile();
	JsonCppRFile();
	return 0;
}  //main
