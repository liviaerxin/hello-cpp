/**
 * @file XSampleWindow.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-07-27
 *
 * @copyright Copyright (c) 2022
 * https://github.com/gamedevtech/X11OpenGLWindow
 clang++ XSampleWindow.cpp -o XSampleWindow \
  -I/opt/X11/include \
  -L/opt/X11/lib -lX11
 */
#include <X11/Xlib.h>
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
    std::cout << "Could not open display\n";
    return 1;
  }
  screen = DefaultScreenOfDisplay(display);
  screenId = DefaultScreen(display);

  // Open the window
  window = XCreateSimpleWindow(display, RootWindowOfScreen(screen), 0, 0, 320,
                               200, 1, BlackPixel(display, screenId),
                               WhitePixel(display, screenId));

  // Show the window
  XClearWindow(display, window);
  XMapRaised(display, window);

  // Enter message loop
  while (true) {
    XNextEvent(display, &ev);
    // Do something
  }

  // Cleanup
  XDestroyWindow(display, window);
  XFree(screen);
  XCloseDisplay(display);
  return 1;
}