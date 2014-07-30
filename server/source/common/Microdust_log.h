class CMicrodustLog
{
private:
    static int level;
public:
    static void info();
    static void dbg();
    static void warn();
    static void err();
    static void setDbg(int level);
};

