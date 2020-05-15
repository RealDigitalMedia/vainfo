# vainfo file descriptor leak

Running this version of `vainfo` on Ubuntu 20.04 on a machine with the
i965 will show a leak of file descriptors for `/dev/dri/card0`. The
accompanying patch to `libva` will resolve this issue.

