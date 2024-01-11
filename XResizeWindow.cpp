/**
 * @file XResizeWindow.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-07-27
 *
 * @copyright Copyright (c) 2022
 * https://github.com/gamedevtech/X11OpenGLWindow
 clang++ XResizeWindow.cpp -o XResizeWindow \
  -I/opt/X11/include \
  -L/opt/X11/lib -lX11
 */
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/keysymdef.h>
#include <iostream>

int main(int argc, char **argv) {
  Display *display;
  Window window;
  Screen *screen;
  int screenId;
  XEvent ev;

  // Open the display
  display = XOpenDisplay(NULL);
  if (display == NULL) {
    printf("%s\n", "Could not open display");
    return 1;
  }
  screen = DefaultScreenOfDisplay(display);
  screenId = DefaultScreen(display);

  // Open the window
  window = XCreateSimpleWindow(display, RootWindowOfScreen(screen), 0, 0, 320,
                               200, 1, BlackPixel(display, screenId),
                               WhitePixel(display, screenId));

  XSelectInput(display, window, ExposureMask);

  // Name the window
  XStoreName(display, window, "Named Window");

  // Show the window
  XClearWindow(display, window);
  XMapRaised(display, window);

  // How large is the window
  XWindowAttributes attribs;
  XGetWindowAttributes(display, window, &attribs);
  std::cout << "Window Width: " << attribs.width
            << ", Height: " << attribs.height << "\n";

  // Resize window
  unsigned int change_values = CWWidth | CWHeight;
  XWindowChanges values;
  values.width = 800;
  values.height = 600;
  XConfigureWindow(display, window, change_values, &values);

  // Variables used in message loop
  bool running = true;
  int x, y;

  // Enter message loop
  while (running) {
    XNextEvent(display, &ev);
    switch (ev.type) {
    case Expose:
      std::cout << "Expose event fired\n";
      XGetWindowAttributes(display, window, &attribs);
      std::cout << "\tWindow Width: " << attribs.width
                << ", Height: " << attribs.height << "\n";
      break;
    }
  }

  // Cleanup
  XDestroyWindow(display, window);
  XCloseDisplay(display);
  return 1;
}