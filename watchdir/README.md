# watchdir

Simple directory watcher program based on inotify and looking only for incoming files.

## Synopsys

Compile then use :

`watchdir /tmp/dir` 

It will watch files in */tmp/dir* like `touch /tmp/dir/foo` or `cp foo /tmp/dir` or `echo "bar" > /tmp/dir/baz`.

But it won't report directory creation (e.g. `mkdir /tmp/dir/subdir`) or nested file creation (e.g. `touch /tmp/dir/subdir/nested`).

## Example

```bash
./watchdir /tmp/dir
Watching /tmp/dir
New file [foo] written
New file [bar] written
New file [baz] written
^C
```
