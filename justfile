build:
    meson compile -C builddir

install: build
    meson install -C builddir
