#include "cTerrain.h"

cTerrain::cTerrain(unsigned int w2, unsigned int l2)
{
     w = w2;
    l = l2;

    h = new float*[l];
    for(int i = 0; i<l; i++ )
     h[i] = new float[w];

     normals = new  cVector3f*[l];
     for( int j=0; j<l; j++)
      normals[j] = new cVector3f[w];


    computed_normals = false;

}

cTerrain::~cTerrain()
{
    //dtor

 for(int i = 0; i<l; i++)
        {delete[] h[i];
        }

  delete [] h;

for(int j= 0; j<l; j++)
{  delete [] normals[j];}
   delete [] normals;
}


const int cTerrain::get_w() const
{
    return w;
}


const int cTerrain::get_l() const
{
    return l;
}



const float cTerrain::get_H(int x, int z) const
{
  return h[z][x];
}


void cTerrain::set_H(int x, int z, float y)
{
  h[z][x] = y;
}

cVector3f cTerrain::get_normal(int x, int z)
{
   if(!computed_normals) compute_normals();
	return normals[z][x];

}



void cTerrain::compute_normals()
{

}
