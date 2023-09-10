[Dockerfile reference](https://docs.docker.com/engine/reference/builder/)


Docker can build images automatically by reading the instructions from a `Dockerfile`. A `Dockerfile` is a text document that contains all the commands a user could call on the command line to assemble an image.

# Format

``` bash
# Comment
INSTRUCTION arguments
```

The instruction is not case-sensitive. However, convention is for them to be UPPERCASE to distinguish them from arguments more easily.

Docker runs instructions in order.  
A `Dockerfile` **must begin with a** `FROM` **instruction**.
- This maybe after [parser directives](#parser-directives), [comments], and globally scoped [ARGs].
- The `FROM` instruction specifies the [Parent Image] from which you are building.
- `FROM` may only be preceded by one or more `ARG` instructions, which declare arguments that are used in `FROM` lines in the `Dockerfile`.

Docker treats lines that begin with `#` as comment, unless the line is a valid parser directive. A `#` marker anywhere else in a line is treated as an argument. Comment lines are removed before the Dockerfile instructions are executed.  
Line continuation characters are not supported in comments.

    !Note: leading whitespace before comment and instructions are ignored, but discouraged. However whitespace in instruction *arguments*, such as the commands following `RUN` are preserved, for example:
``` bash
RUN echo "\
     hello\
     world"
```


# Parser directives

Parser directives are optional, and affect the way in which subsequent lines in the `Dockerfile` are handled. They do not add layers to the build and will not be shown as a build step.  
Parser directives are written as a special type of comment in the form `# directive=value`. A single directive may only be used once.

Once a comment, empty line or builder instruction has been processed, Docker no longer looks for parser directives. Instead it treats anything formatted as a parser directive as a plain comment ==> all parser directives must be at the very top of a `Dockerfile`.

Rules:
- are not case-sensitive, but convention is for to be lowercase.
- to include a blank line following any parser directives.
- line continuation characters are not supported in them.

Supported parser directives:
- `syntax` **only available** when using the BuildKit backend.
- `escape` used to set the escape character in a `Dockerfile`. If not specified, default is backslash `\`. Set to `` `(backtick)`` is mainly for Windows where `\` is the directory path separator.

The escape character is used both to escape characters in a line, and to escape a newline. This allows a `Dockefile` instruction to span multiple lines.
    !Note: escaping is not performed in a `RUN` command, except at the end of the line.

