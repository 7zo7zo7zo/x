#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <X11/Xlib.h>

int main(int argc, char *argv[]) {

        Display *dpy;
        Window win;

        dpy = XOpenDisplay(NULL);

        return 0;
}
