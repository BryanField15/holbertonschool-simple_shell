# Holberton School Simple Shell

<img src="https://images.immediate.co.uk/production/volatile/sites/4/2022/06/Shells-chambered-nautilus-a081684.jpg?quality=90&webp=true&resize=940,400" alt="Gates of Shell" width="800">

This is a simple Unix shell created as part of the curriculum at Holberton School.
<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li><a href="#compliation">Compliation</a></li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#file-description">File description</a></li>
    <li> <a href="#flow-chart">About The Project</a></li>
    <li><a href="#authors">Authors</a></li>
  </ol>
</details>  

## Getting Started

To install the shell clone the following repository:<br>
```bash
git clone https://github.com/BryanField15/holbertonschool-simple_shell.git
```
<p align="right">(<a href="#readme-top">back to top</a>)</p>
<br>

<!-- COMPLIATION -->      
## Compliation

A Make file is provided.
```bash
make all
```
And compiles with the following flags
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -g *.c -o hsh
```
<p align="right">(<a href="#readme-top">back to top</a>)</p>
<br>

<!-- USAGE -->
## Usage

To use the shell execute the ***hsh*** file

```bash
./hsh
```

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- FILE DESCRIPTION -->
## File description

**tbc.c** -- placeholder text.
**tbc.c** -- placeholder text.
**tbc.c** -- placeholder text.
**tbc.c** -- placeholder text.
**tbc.c** -- placeholder text.

<br>
<!-- FLOW CHART -->
## Flow chart

The shell reads the given input from the stdin and trims any leading and trailing whitespaces. It then splits command into tokens if the given input is more than one word and stores it as an array.  The first given word is recognised as the command and following words are considered as arguments to the command.

If a user command matches a builtin command then the coprresponding function is executed.

If an executable is found, the shell forks and the command is executed in the child process while the parent process waits for the child process to be terminated. Once the output is returned it terminates the child process and the shell returns a new line waiting for the next user input.
<br>

![Screen Shot 2023-04-27 at 8 41 23 pm](https://user-images.githubusercontent.com/124537848/234839116-5b67446e-0e88-4889-bb63-9bfd33133489.png)

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- AUTHORS -->
## Authors
***Yu Ji and Bryan Field***

<br>

</i>Github Profiles:

[Yu](https://github.com/YuJi-2023)

[Bryan](https://github.com/BryanField15)

<p align="right">(<a href="#readme-top">back to top</a>)</p>
