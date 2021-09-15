My minishell

The implementation is based on the use of read and termcap, as well as a nice bonus in the form of a "goose" - a small bash script.

Full implementation of commands (pwd, echo, cd, net, export, env, exit), return codes for the command completion status ( $ ?), and so on.
Other commands work through execve.

It is possible to use any number and combinations of pipes, redirects, quotes.

As beautiful as a shell