
#include <vector>

class IWidget
{
public:
    virtual void storeInteger(int a) = 0;

    virtual int sum() = 0;

};

class WidgetWithArrays : public IWidget
{
public:
    WidgetWithArrays();
    void storeInteger(int a) override;

    int sum() override;
private:

    int m_array[100];
    int m_count;

};

class WidgetWithVector : public IWidget
{
public:
    WidgetWithVector();
    void storeInteger(int a) override;

    int sum() override;
private:

    std::vector<int> m_vector;


};

