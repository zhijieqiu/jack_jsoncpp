#include <string>
#include "json/json.h"

void readJson();
void writeJson();

int main(int argc, char** argv) {
    readJson();
    writeJson();
    return 0;
}

void readJson() {
    using namespace std;
    std::string strValue = "{\"intValue\":4,\"name\":\"json\",\"array\":[{\"cpp\":\"jsoncpp\"},{\"java\":\"jsoninjava\"},{\"php\":\"support\"}]}";
    
    Json::Reader reader;
    Json::Value value;
    
    if (reader.parse(strValue, value))
    {
        cout<<ULONG_LONG_MAX<<endl;
        unsigned long long intValue = value["intValue"].asULong();
        cout<<intValue<<endl;
        std::string out = value["name"].asString();
        std::cout << out << std::endl;
        const Json::Value arrayObj = value["array"];
        for (unsigned int i = 0; i < arrayObj.size(); i++)
        {
            if (!arrayObj[i].isMember("cpp"))
                continue;
            out = arrayObj[i]["cpp"].asString();
            std::cout << out;
            if (i != (arrayObj.size() - 1))
                std::cout << std::endl;
        }
    }
    else{
        cout<<reader.getFormatedErrorMessages()<<endl;;
        
    }
}

void writeJson() {
    using namespace std;
    
    Json::Value root;
    Json::Value arrayObj;
    Json::Value item;
    
    item["cpp"] = "jsoncpp";
    item["java"] = "jsoninjava";
    item["php"] = "support";
    
    arrayObj.append(item);
    Json::Value item2;
    item2["longValue"] = LONG_LONG_MAX-10;
    item2["neg_longValue"] = LONG_LONG_MIN+20;
    item2["ulongValue"] = ULONG_LONG_MAX -10;
    arrayObj.append(item2);
    root["name"] = "json";
    root["array"] = arrayObj;
    
    root.toStyledString();
    std::string out = root.toStyledString();
    std::cout << out << std::endl;
}
