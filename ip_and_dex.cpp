#include <iostream>
#include <string>
using namespace std;
#include <stdlib.h>

int main(int argc, const char** argv) 
{
 if(argc < 2) {
  cout << "Usage: " << argv[0] << " <ip/dec>" << endl; 
  return -1;
 } 

 string input(argv[1]);
 if(input.find(".") != string::npos) {
  // treat as ip
  uint32_t ret = 0, count = 0;
  size_t pos = 0;
  do {
    size_t idx = input.find(".", pos);
    if(idx == string::npos) {
      if(count < 3) {
        cout << "Wrong ip: " << input << endl;
        return -1;
      } else {
        ret = ret * (1 << 8) + atoi(input.substr(pos, idx - pos).c_str());
        break; // done
      } 
    } else if (idx == pos) {
      cout << "Wrong ip: " << input << endl;
      return -1;
    } else if(count > 3) {
      cout << "Wrong ip: " << input << endl;
      return -1;
    }
    ret = ret * (1 << 8) + atoi(input.substr(pos, idx - pos).c_str());
    ++count;
//    cout << "debug: " << idx << ", " << ret << ", " << count << ", " << pos << endl;
    pos = idx + 1;
  } while(pos < input.size());
  
  cout << ret << ": " << hex << ret << endl;
 } else {
  // treat as number
  uint32_t num = atoi(input.c_str());
  cout << (num >> 24) << "." << ((num >> 16) & 0xff) << "."<< ((num >> 8) & 0xff) << "." << (num & 0xff) << endl ; 
 }
 return 0;
}
