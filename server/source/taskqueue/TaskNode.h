#ifndef DEF_CTASKNODE
#define DEF_CTASKNODE

class CTaskNode
{
    typedef unsigned int size_t;
private:
    

protected:
    char *m_data;
    size_t m_size;
public:
   CTaskNode();
   virtual ~CTaskNode();
   char *getData();
   size_t getSize();
   void setData(char *, size_t);
   virtual int toDO();
};
#endif

