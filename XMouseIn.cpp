/**
 * @file XMouseIn.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-07-27
 *
 * @copyright Copyright (c) 2022
 * https://github.com/gamedevtech/X11OpenGLWindow
  clang++ XMouseIn.cpp -o XMouseIn \
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

  XSelectInput(display, window,
               PointerMotionMask | ButtonPressMask | ButtonReleaseMask |
                   EnterWindowMask | LeaveWindowMask);

  // Show the window
  XClearWindow(display, window);
  XMapRaised(display, window);

  // Variables used in message loop
  bool running = true;
  int x, y;

  // Enter message loop
  while (running) {
    XNextEvent(display, &ev);
    switch (ev.type) {
    case ButtonPress:
      if (ev.xbutton.button == 1) {
        std::cout << "Left mouse down\n";
      } else if (ev.xbutton.button == 2) {
        std::cout << "Middle mouse down\n";
      } else if (ev.xbutton.button == 3) {
        std::cout << "Right mouse down\n";
      } else if (ev.xbutton.button == 4) {
        std::cout << "Mouse scroll up\n";
      } else if (ev.xbutton.button == 5) {
        std::cout << "Mouse scroll down\n";
      }
      break;
    case ButtonRelease:
      if (ev.xbutton.button == 1) {
        std::cout << "Left mouse up\n";
      } else if (ev.xbutton.button == 2) {
        std::cout << "Middle mouse up\n";
      } else if (ev.xbutton.button == 3) {
        std::cout << "Right mouse up\n";
        running = false;
      }
      break;
    case MotionNotify:
      x = ev.xmotion.x;
      y = ev.xmotion.y;
      std::cout << "Mouse X:" << x << ", Y: " << y << "\n";
      break;
    case EnterNotify:
      std::cout << "Mouse enter\n";
      break;
    case LeaveNotify:
      std::cout << "Mouse leave\n";
      break;
    }
  }

  // Cleanup
  XDestroyWindow(display, window);
  XCloseDisplay(display);
  return 1;
}