# Jenkins Sample Project - C/C++

This project is a skeleton to be used with projects written in C/C++;

# Tips

## Installing subodules

```shell
git submodule update --init --recursive
```

## Make receipts

### clean environment

```shell
make clean-all
```

### clean objects files

```shell
make clean-obj
```

### build test binary

```shell
make test
```

### build binary

```shell
make
```

## Jenkins Ant Tasks

### run default task

```shell
ant -f build.xml
```

### run sonar task

```shell
ant -f build.xml sonar
```

## Tools

- [fff](https://github.com/meekrosoft/fff)
- [Google Test](https://github.com/google/googletest/)
- [RATS](https://code.google.com/archive/p/rough-auditing-tool-for-security/)
- [Vera](https://bitbucket.org/verateam/vera)
