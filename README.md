# MulleLoadTwoUniverses

This is an experiment to see how the global (variable) universe is handled when a shared library is opened with `dlopen` using various mode flags.

The shellscript `run-load-two-universes` runs through sixteen tests with different dlopen settings.

The results:

A RTLD_GLOBAL opened MulleObjC shared library will not coexist with another shared library which is opened  **after** it. Unless that shared library is opened with RTLD_DEEPBIND.

Otherwise RTLD_LOCAL opened shared libraries have no problem.

Memo: A RTLD_GLOBAL shared library is identical to a RTLD_LOCAL, if no dlopen calls follow! 

## Run

This is a [mulle-sde](https://mulle-sde.github.io/) project.

It has it's own virtual environment, that will be automatically setup for you
once you enter it with:

```
mulle-sde MulleLoadTwoUniverses
```

Now you can let **mulle-sde** fetch the required dependencies and build the 
project for you:

```
mulle-sde craft
```
