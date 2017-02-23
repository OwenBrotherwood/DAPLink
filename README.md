# WIP
<https://github.com/mbedmicro/DAPLink/issues/197#issuecomment-281826833>
UNKNOWN as to if the merged trees can be compiled with GCC
<https://github.com/OwenBrotherwood/DAPLink/tree/freescale>
<https://github.com/OwenBrotherwood/DAPLink/tree/CMSIS-DAP_IDAP-Link>


# DAPLink or something near?

## Setup
Skip any step where a compatible tool already exists

1. Install [Python 2.7.x](https://www.python.org/downloads/) and make sure it's added to path
2. Install [pip](https://pip.pypa.io/en/latest/installing.html) and make sure <python_install_loc>\Scripts it's added to path
3. Install DAPLink dependencies using pip (see command below)
4. Install [Keil MDK-ARM](https://www.keil.com/download/product/) 

```
daplink> pip install -r requirements.txt
```

## Develop
1. Generate project files. This should be done everytime you pull new changes
```
> pgen export -t uvision
```
For adding new targets start from template and use these docs...

## Contribute
Check out the issue tracker.

##ToDo
- Create a test
- Document how to use
- Document how to contribute
