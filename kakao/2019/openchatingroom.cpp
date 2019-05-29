#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

string* StringSplit(string strTarget, string strTok)
{
    int     nCutPos;
    int     nIndex     = 0;
    string* strResult = new string[4];

    while ((nCutPos = strTarget.find_first_of(strTok)) != strTarget.npos)
    {
        if (nCutPos > 0)
        {
            strResult[nIndex++] = strTarget.substr(0, nCutPos);
        }
        strTarget = strTarget.substr(nCutPos+1);
    }

    if(strTarget.length() > 0)
    {
        strResult[nIndex++] = strTarget.substr(0, nCutPos);
    }

    return strResult;
}

void ReplaceStringInPlace(std::string& subject, const std::string& search, const std::string& replace) { size_t pos = 0; while ((pos = subject.find(search, pos)) != std::string::npos) { subject.replace(pos, search.length(), replace); pos += replace.length(); } }


vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> user_nickname;

    for ( int i = 0; i < record.size(); i++ ){
      char toki[1] = {' '};
      string *commands = StringSplit(record[i], toki);
      string result;

      if ( commands[0].compare("Change") == 0){
        user_nickname[commands[1]] = commands[2];
        continue;
      } else {
        result.append(commands[1]);

        if ( commands[0].compare("Enter") == 0 ){
          user_nickname[commands[1]] = commands[2];
          result.append("님이 들어왔습니다.");
        } else if ( commands[0].compare("Leave") == 0 ){
          result.append("님이 나갔습니다.");
        }

        answer.push_back(result);
      }
    }
    for ( int i = 0; i < answer.size(); i++ ){
      string *commands = StringSplit(answer[i], "님");
      ReplaceStringInPlace(answer[i], commands[0], user_nickname[commands[0]]);
    }

    return answer;
}

int main(){
  char *str[10] = { "Enter uid1234 Muzi", "Enter uid4567 Prodo", "Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan", "Enter uid1234 Muzi", "Enter uid4567 Prodo", "Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"};
  vector<string> record;

  for ( int i = 0; i < 10; i++ ) {
    record.push_back(std::string(str[i]));
  }

  vector<string> answer = solution(record);

  for ( int i = 0; i < answer.size(); i++ ) {
    cout << answer[i] << endl;
  }
  return 0;
}
