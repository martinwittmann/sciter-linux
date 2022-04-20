#include "sciter-x-window.hpp"
#include "sciter-x-graphics.hpp"

class uSciter: public sciter::window {
public:
  uSciter() : window(
                  SW_TITLEBAR |
                  SW_RESIZEABLE |
                  SW_CONTROLS |
                  SW_MAIN |
                  SW_GLASSY |
                  SW_ENABLE_DEBUG) {}

  int foo(int p) { return p + 42; }

  int get_windowHandle() {
    return (int)(intptr_t)get_hwnd();
  }

  SOM_PASSPORT_BEGIN(uSciter)
    SOM_FUNCS(
      SOM_FUNC(foo),
    )
    SOM_PROPS(SOM_RO_VIRTUAL_PROP(windowHandle,get_windowHandle))
  SOM_PASSPORT_END
};

#include "resources.cpp"

int uimain(std::function<int()> run ) {
  // Enabled features to be used from script.
  SciterSetOption(NULL, SCITER_SET_SCRIPT_RUNTIME_FEATURES,
                  ALLOW_FILE_IO |
                  ALLOW_SOCKET_IO |
                  ALLOW_EVAL |
                  ALLOW_SYSINFO );

  SciterSetOption(nullptr, SCITER_SET_DEBUG_MODE, true);
  sciter::debug_output_console _;
  sciter::archive::instance().open(aux::elements_of(resources));
  sciter::om::hasset<uSciter> pwin = new uSciter();
  // Example, setting "usciter" media variable, check https://sciter.com/forums/topic/debugging-issues/
  SciterSetMediaType(pwin->get_hwnd(), WSTR("desktop,usciter"));

  pwin->load(WSTR("this://app/main.htm"));
  pwin->expand();

  return run();

}
