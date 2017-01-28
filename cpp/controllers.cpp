
namespace soup {
  using namespace std;

#if 1

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

    int run(int param) {
      return dev->op2(param, param);
    }
  };

#else
  template <typename T>
  struct ControllerOps {
    shared_ptr<T> dev;

    void foo(int param) {
      dev->op1(param * param);
    }
  };

  class ControllerA {
    shared_ptr<DeviceA> dev;
    ControllerOps<DeviceA> ops;
  public:
    ControllerA(shared_ptr<DeviceA> dev) : dev(dev), ops({dev}) {}

    void foo(int param) {
      ops.foo(param);
    }

    int run(int param) {
      return dev->op2(param);
    }
  };


  class ControllerB {
    shared_ptr<DeviceB> dev;
    ControllerOps<DeviceB> ops;
  public:
    ControllerB(shared_ptr<DeviceB> dev) : dev(dev), ops({dev}) {}

    void foo(int param) {
      ops.foo(param);
    }

    int run(int param) {
      return dev->op2(param, param);
    }
  };
#endif
}
