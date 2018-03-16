class A
{
public:
  A() {};

private:
  A(const A&) = delete;
  void operator=(const A&) = delete;
};
