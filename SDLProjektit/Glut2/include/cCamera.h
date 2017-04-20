#ifndef CCAMERA_H
#define CCAMERA_H


class cCamera
{
    public:
        cCamera();
        virtual ~cCamera();
         const float getX() const;
         const float getY() const;
         const float getZ() const;
         void setCord(float aX, float aY, float aZ);
         void setX(float aX);
         void setY(float aY);
         void setZ(float aZ);
        float x;
        float y;
        float z;
        float lastX;
        float lastY;
        float lastZ;
    protected:

    private:
};

#endif // CCAMERA_H
