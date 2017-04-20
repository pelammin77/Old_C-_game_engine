#include <iostream>
#include<fstream>
using namespace std;

int main()
{


    int byte;

    ifstream bmp;
    ofstream log;
    bmp.open("hmap.bmp");
    log.open("hmap.txt");
  if(bmp.good()&&log.good())
  {
      while(bmp.good())
      {
          byte = bmp.get();
          log<<byte<<endl;
      }


  }
  else cout<<"tiedosto ei aukea"<<endl;
bmp.close();
log.close();

    return 0;
}
