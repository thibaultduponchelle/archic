#include <sys/inotify.h>
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define bufsize 1024 

int main(int argc, char *argv[])
{
    int ifd;
    char buf[bufsize];
    int n;
    char *p;
    struct inotify_event *event;

    if (argc < 2) {
        printf("%s /dir/to/watch1 /dir/to/watch2 ...\n", argv[0]);
        exit(-1);
    }

    ifd = inotify_init();
    if (ifd == -1) {
        printf("Init failed");
        exit(-1);
    }

    int watcher;
    int i;
    for (i = 1; i < argc; i++) {
        watcher = inotify_add_watch(ifd, argv[i], IN_CLOSE_WRITE);
        if (watcher == -1) {
            printf("Watcher creation failed");
            exit(-1);
        }
        printf("Watching %s\n", argv[i]);
    }

    while(1) {
        n = read(ifd, buf, bufsize);
        if (n <= 0) {
            printf("Problem reading inotify file descriptor");
            exit(-1);
        }

        for (p = buf; p < buf + n; ) {
            event = (struct inotify_event *) p;
            printf("New file [%s] written\n", event->name);
            p += sizeof(struct inotify_event) + event->len;
        }
    }

    exit(0);
}
