# Test for 42sh

## table of content
- [env](#env)
- [echo](#echo)
- [exit](#exit)


### env
```shell
$> env -i
```
```
$> env --ignore-environment
```
```shell
$> env -
```
```shell
$> env -i -
```
```shell
$> env -i - ls
Makefile	auteur		bin		include		libft		obj		src
```
```shell
$> env "- "
env: illegal option --
usage: env [-iv] [-P utilpath] [-S string] [-u name]
           [name=value ...] [utility [argument ...]]
$> echo $?
1
```
```shell
$> env -z
env: illegal option -- z
usage: env [-iv] [-P utilpath] [-S string] [-u name]
           [name=value ...] [utility [argument ...]]
$> echo $?
1
```
```shell
$> env -i "coucou===tata"
coucou==tata
```
```shell
$> env -i env
```
```shell
$> env -i "toto=tata" "titi=toto"
toto=tata
titi=toto
```
```shell
$> env MAIL=123
...
MAIL=123
...
```
```shell
$> env caca
env: caca: No such file or directory
```
```shell
$> env caca
env: caca: No such file or directory
```
```shell
$> env -i caca
env: caca: No such file or directory
```
```shell
$> env -i coucou=caca caca
env: caca: No such file or directory
```
```shell
$> env caca popo
env: caca: No such file or directory
```
```shell
$> env ls
Makefile	auteur		bin		include		libft		obj		src
```
```shell
$> env ls -a
.		.cache_exists	.gitignore	auteur		include		obj
..		.git		Makefile	bin		libft		src
```

```shell
$> env -i ls
Makefile	auteur		bin		include		libft		obj		src
```
```shell
$> env -i PATH=caca ls
env: ls: No such file or directory
```
```shell
$> env -u MAIL=
unsetenv env: MAIL=: Invalid argument
```
```shell
$> env -u
env: option requires an argument -- u
```

### echo
```shell
$> echo

```
```shell
$> echo -n
```
```shell
$> echo -nnnnnn
```
```shell
$> echo -n -n -n -n -n
```
```shell
$> echo -n -n -n -n -n -y -n
-y -n%
```
```shell
$> echo -nnyneEu
-nnyneEu
```
```shell
$> echo Le petit chat boit son lait
Le petit chat boit son lait
```
```shell
$> echo Le         petit         chat        boit       son      lait
Le petit chat boit son lait
```
```shell
$> echo Le petit \t chat boit \\t son lait
Le petit t chat boit \t son lait
```
```shell
$> echo -E Le petit \t chat boit \\t son lait
Le petit t chat boit \t son lait
```
```shell
$> echo -e Le petit \t chat boit \\t son lait
Le petit t chat boit    son lait
```
```shell
$> echo -eE Le petit \t chat boit \\t son lait
Le petit t chat boit \t son lait
```
```shell
$> echo -eEe Le petit \t chat boit \\t son lait
Le petit t chat boit    son lait
```
```shell
$> echo -e \\x38 petits\\x20chats boivent son lait\\x21
8 petits chats boivent son lait!
```
```shell
$> echo -e \\063 chats et \\08 chiens boivent son lait\\077
3 chats et 8 chiens boivent son lait?
$> echo -e \\063 chats et \\08 chiens boivent son lait\\077 | cat -e
3 chats et ^@8 chiens boivent son lait?
```
```shell
$> echo -e \\38 petits\\20chats boivent son lait\\21
\38 petits\20chats boivent son lait\21
```

### exit
```shell
$> exit toto titi
42sh: exit: too many arguments.
```
```shell
$> exit toto
42sh: exit: toto: Expression syntax.
```
```shell
$> exit
$> echo $?
0
```
```shell
$> exit 20
$> echo $?
20
```
```shell
$> exit 256
$> echo $?
0
```
