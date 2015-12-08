#include "../headers/Map.h"

int main(int argc, char * argv[])
{
  if(argc != 2)
  {
    cout << "Usage: " << argv[0] << " <input file>" << endl;
    return(-1);
  }

  Map newMap(argv[1]);

  cout << newMap;

  return(0);
}
