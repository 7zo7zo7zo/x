#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <X11/Xlib.h>

int main(int argc, char *argv[]) {

        Display *dpy;
        int scr;
        Window parent;
        Window win;
        XEvent e;

        dpy = XOpenDisplay(NULL);
        scr = DefaultScreen(dpy);
        parent = XRootWindow(dpy, scr);
        win = XCreateSimpleWindow(dpy, parent, 100, 100, 500, 500, 2, BlackPixel(dpy, scr), WhitePixel(dpy, scr));

        GC gc = DefaultGC(dpy, scr);

        XSelectInput(dpy, win, ExposureMask | KeyPressMask);
        XMapWindow(dpy, win);
        
        while(1) {
                XNextEvent(dpy, &e);
                if(e.type == Expose) {
                        XFillRectangle(dpy, win, gc, 120, 150, 50, 60);
                }
                if(e.type == KeyPress) {
                        break;
                }
        }
        
        XCloseDisplay(dpy);
        return 0;
}
