
namespace soup {
  using namespace std;

#if 1

  template <typename T>
  struct FooOp {
    shared_ptr<T> dev;
    void foo(int param) {
      dev->op1(param * param);
    }
  };

  class ControllerA {
    shared_ptr<DeviceA> dev;
  public:
    ControllerA(shared_ptr<DeviceA> dev) : dev(dev) {}

    void foo(int param) {
      FooOp<DeviceA>({dev}).foo(param);
    }

    int run(int param) {
      return dev->op2(param);
    }
  };


  class ControllerB {
    shared_ptr<DeviceB> dev;
  public:
    ControllerB(shared_ptr<DeviceB> dev) : dev(dev) {}

    void foo(int param) {
      FooOp<DeviceB>({dev}).foo(param);
    }

    int run(int param) {
      return dev->op2(param, param);
    }
  };

#else
  template <typename T>
  class Controller {
  protected:
    shared_ptr<T> dev;
  public:
    Controller(shared_ptr<T> dev) : dev(dev) {}

    void foo(int param) {
      dev->op1(param * param);
    }
  };


  class ControllerA : public Controller<DeviceA> {
  public:
    ControllerA(shared_ptr<DeviceA> dev) : Controller(dev) {}

    int run(int param) {
      return dev->op2(param);
    }
  };


  class ControllerB : public Controller<DeviceB> {
  public:
    ControllerB(shared_ptr<DeviceB> dev) : Controller(dev) {}

    void foo(int param) {
      dev->op1(param * param);
    }

    int run(int param) {
      return dev->op2(param, param);
    }
  };
#endif
}
