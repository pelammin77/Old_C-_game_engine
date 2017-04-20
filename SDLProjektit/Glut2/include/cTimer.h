#ifndef CTIMER_H
#define CTIMER_H


class cTimer
{
    public:
        cTimer();
        virtual ~cTimer();
        void Update();
        void SetTime(const double aTime);
        const double GetCurrentTime() const;
       const double GetLastTime() const;
    protected:
    private:
        double CurrentTime;
        double LastTime;

};

#endif // CTIMER_H
