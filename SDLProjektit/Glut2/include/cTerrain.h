#ifndef CTERRAIN_H
#define CTERRAIN_H

#include"cVector3f.h"


class cTerrain{

  public:

        cTerrain(unsigned int w2, unsigned int l2);
        virtual ~cTerrain();
        const int get_w() const;
         const int get_l() const;
         const float get_H(int x, int z) const ;
          cVector3f get_normal(int x, int z);
         void set_H(int x, int z, float y);
         void compute_normals();

    protected:
    private:
    int w;
    int l;
    float **h;// terrainin korkeus tietyssä pisteessä
    cVector3f **normals;
    bool computed_normals;

};



#endif // CTERRAIN_H
