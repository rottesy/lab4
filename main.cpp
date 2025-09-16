#include <cstring>
#include <iostream>

using namespace std;

int myStrlen(const char *str)
{
    if (str == nullptr)
    {
        return 0;
    }
    int len = 0;

    for (int ind = 0; str[ind] != '\0'; ind++)
    {
        len++;
    }

    return len;
}

class Ancestor
{
  private:
    char *humanName = nullptr;

  public:
    explicit Ancestor(const char *name)
    {
        humanName = new char[myStrlen(name) + 1];
        strcpy_s(humanName, myStrlen(name) + 1, name);
    }
    virtual ~Ancestor() { delete[] humanName; }
    virtual void print() const = 0;
    [[nodiscard]] char *getName() const { return humanName; }
};

class Kid : public Ancestor
{
  public:
    explicit Kid(const char *name) : Ancestor(name) {}
    void print() const override { cout << "Name : " << getName() << "\n"; }
};

class GrandSon : public Kid
{
  private:
    char *patronymic = nullptr;

  public:
    GrandSon(const char *name, const char *pat) : Kid(name)
    {
        patronymic = new char[myStrlen(pat) + 1];
        strcpy_s(patronymic, myStrlen(pat) + 1, pat);
    }
    ~GrandSon() override { delete[] patronymic; }
    void print() const override { cout << "GrandSon : " << getName() << " " << patronymic << "\n"; }
};
