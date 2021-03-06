# petite math library

A lightweight and modular C++ math library

# about

`PML` is a math library for C++ designed to be lightweight, modular,
and reasonably fast. It is distributed as header files for ease of use.
Each header can be separated and bundled with it's dependencies into
a nice package, ready to be included in your project. See "Usage" for
more information.

# usage

First, clone the repository. Once you have your local copy, run
`extract.sh` to separate each header into a directory in `module/`
that contains it and any headers it depends on. You can now copy the
modules you need into your project, and be assured that you only have
the files you actually need. Alternatively, you can just copy the entire
`pml/` directory.

`./extract.sh --clean` will remove generated files.

# documentation

Each module has a documentation file in `doc/` that describes it's purpose
and usage. You should be able to learn how to do just about anything by
referring to these files.

# license

Licensed under the MIT License, see LICENSE for more information.
